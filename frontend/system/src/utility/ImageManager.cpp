#include <es_system.h>

#ifndef ES_HAVE_LOADPNG
void										ESSUB_LoadPNG										(const std::string& aPath, Texture** aTexture)
{
	png_structp png_ptr;
	png_infop info_ptr;
	png_bytep* row_pointers;
	uint32_t Width;
	uint32_t Height;

	//Load
	uint8_t header[8];
		
	FILE *fp = fopen(aPath.c_str(), "rb");
	ErrorCheck(fp, "PNG Reader: File could not be opened for reading. [File: %s]", aPath.c_str());

	fread(header, 1, 8, fp);
	ErrorCheck(!png_sig_cmp(header, 0, 8), "PNG Reader: File not recognized as a PNG file. [File: %s]", aPath.c_str());

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	ErrorCheck(png_ptr, "PNG Reader: png_create_read_struct failed. [File: %s]", aPath.c_str());
	
	info_ptr = png_create_info_struct(png_ptr);
	ErrorCheck(info_ptr, "PNG Reader: png_create_info_struct failed. [File: %s]", aPath.c_str());
	
	if(setjmp(png_jmpbuf(png_ptr)))
	{
		ErrorCheck(0, "PNG Reader: Error during init_io. [File: %s]", aPath.c_str());
	}
	
	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, 8);

	if(setjmp(png_jmpbuf(png_ptr)))
	{
		ErrorCheck(0, "PNG Reader: Error during read_png. [File: %s]", aPath.c_str());
	}
	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_EXPAND | PNG_TRANSFORM_SWAP_ALPHA, 0);
	
	fclose(fp);

	row_pointers = png_get_rows(png_ptr, info_ptr);
	Width = png_get_image_width(png_ptr, info_ptr);
	Height = png_get_image_height(png_ptr, info_ptr);

	//Copy to texture
	Texture* output = ESVideo::CreateTexture(Width, Height, true);
	output->Clear(0);

	uint32_t copyWidth = std::min(Width, output->GetWidth());
	uint32_t copyHeight = std::min(Height, output->GetHeight());

	uint32_t* texPixels = output->Map();

	for(int i = 0; i != copyHeight; i ++)
	{
		uint32_t* dest = texPixels + (output->GetPitch() * i);
		uint8_t* source = row_pointers[i];

		for(int j = 0; j != copyWidth; j ++)
		{
			uint32_t a = (info_ptr->color_type == PNG_COLOR_TYPE_RGB_ALPHA) ? *source++ : 0xFF;
			uint32_t r = *source ++;
			uint32_t g = *source ++;
			uint32_t b = *source ++;
			*dest++ = output->ConvertPixel(r, g, b, a);
		}
	}

	output->Unmap();
	*aTexture = output;

	//Close
	png_destroy_info_struct(png_ptr, &info_ptr);
	png_destroy_read_struct(&png_ptr, 0, 0);
}
#endif

void										ImageManager::Purge									()
{
	for(std::map<std::string, Texture*>::iterator i = Images.begin(); i != Images.end(); i ++)
	{
		delete i->second;
	}

	Images.clear();
}
	
Texture*									ImageManager::LoadImage								(const std::string& aName, const std::string& aPath)
{
	if(!Utility::FileExists(aPath))
	{
		return 0;
	}

//HACK: Don't allow more than 33 images, make a less nuclear pruning routine!
	if(Images.size() >= 33)
	{
		Purge();
	}

	if(Images.find(aName) == Images.end())
	{
		Texture* output;

		ESSUB_LoadPNG(aPath, &output);
		output->SetFilter(true);
		
		Images[aName] = output;
	}
	
	return Images[aName];
}

Texture*									ImageManager::GetImage								(const std::string& aName)
{
	if(Images.find(aName) == Images.end())
	{
		std::string filename = Directory + "/" + aName;

		if(Utility::FileExists(filename))
		{
			return LoadImage(aName, filename);
		}
		else if(Utility::FileExists(filename + ".png"))
		{
			return LoadImage(aName, filename + ".png");
		}
		else
		{
			Images[aName] = 0; //Don't check every time for a non-existant image
		}
	}
	
	return Images[aName];
}

std::string									ImageManager::Directory;
std::map<std::string, Texture*>				ImageManager::Images;

