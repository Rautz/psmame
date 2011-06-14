#include <es_system.h>

namespace
{
	bool								AlphaSortDirectory					(SummerfaceItem_Ptr a, SummerfaceItem_Ptr b)
	{
		if(a->IntProperties["DIRECTORY"] == 1 && b->IntProperties["DIRECTORY"] == 0)		return true;
		if(a->IntProperties["DIRECTORY"] == 0 && b->IntProperties["DIRECTORY"] == 1)		return false;
		return a->GetText() < b->GetText();
	}
}

class									FlowListView : public ListView
{
	public:
										FlowListView					(SummerfaceList_WeakPtr aWeakList) : WeakList(aWeakList) {}
		virtual							~FlowListView					() {}
	
		virtual bool					Input							();
		bool							DrawItem						(SummerfaceItem_Ptr aItem, uint32_t aX, uint32_t aY, uint32_t aWidth, uint32_t aHeight, bool aSelected);
		virtual bool					Draw							();

	private:
		SummerfaceList_WeakPtr			WeakList;
		static const int				Columns = 5;
		static const int				Rows = 2;
};

bool									FlowListView::Input				()
{
	if(!WeakList.expired())
	{
		SummerfaceList_Ptr List = WeakList.lock();

		int32_t oldIndex = List->GetSelection();
		if(List->GetItemCount() != 0)
		{
			oldIndex += (ESInput::ButtonPressed(0, ES_BUTTON_DOWN) ? 1 : 0);
			oldIndex -= (ESInput::ButtonPressed(0, ES_BUTTON_UP) ? 1 : 0);
			oldIndex += (ESInput::ButtonPressed(0, ES_BUTTON_RIGHT) ? Rows : 0);
			oldIndex -= (ESInput::ButtonPressed(0, ES_BUTTON_LEFT) ? Rows : 0);
			oldIndex = Utility::Clamp(oldIndex, 0, List->GetItemCount() - 1);
			List->SetSelection(oldIndex);
		}

		if(ESInput::ButtonDown(0, ES_BUTTON_CANCEL))
		{
			List->SetCanceled(true);
			return true;
		}

		if(ESInput::ButtonDown(0, ES_BUTTON_ACCEPT))
		{
			List->SetCanceled(false);
			return true;
		}
		
		return false;
	}
	else
	{
		return true;
	}	
}

bool									FlowListView::DrawItem			(SummerfaceItem_Ptr aItem, uint32_t aX, uint32_t aY, uint32_t aWidth, uint32_t aHeight, bool aSelected)
{
	Texture* image = ImageManager::GetImage(aItem->GetImage());
	if(Utility::FileExists(aItem->Properties["THUMB"]))
	{
		image = ImageManager::LoadImage(aItem->Properties["THUMB"], aItem->Properties["THUMB"]);
	}

	if(image && aWidth && aHeight)
	{
		Area ImageArea(0, 0, image->GetWidth(), image->GetHeight());

		uint32_t x = aX, y = aY, w = aWidth, h = aHeight;
		Utility::CenterAndScale(x, y, w, h, ImageArea.Width, ImageArea.Height);
		ESVideo::PlaceTexture(image, Area(x, y, w, h), ImageArea, 0xFFFFFFFF);
	}
}

bool							FlowListView::Draw						()
{
//	ESVideo::SetClip(Area(0, 0, ESVideo::GetScreenWidth(), ESVideo::GetScreenHeight()));
//	ESVideo::FillRectangle(Area(0, 0, ESVideo::GetScreenWidth(), ESVideo::GetScreenHeight()), 0x000080FF);

	if(!WeakList.expired())
	{
		SummerfaceList_Ptr List = WeakList.lock();

		List->SetHeader("");

		uint32_t iconWidth = ESVideo::GetClip().Width / Columns;
		uint32_t iconHeight = ESVideo::GetClip().Height / Rows;
		uint32_t expandWidth = ESVideo::GetClip().Width / 16;
		uint32_t expandHeight = ESVideo::GetClip().Height / 16;

		int onitem = (List->GetSelection() - (List->GetSelection() % Rows)) - (Rows * (Columns / 2));
		int selection = -1, selectionx = 0, selectiony = 0;

		for(int i = 0; i != Columns; i ++)
		{
			for(int j = 0; j != Rows; j ++)
			{
				if(onitem < 0 || onitem >= List->GetItemCount())
				{
					onitem ++;
					continue;
				}

				DrawItem(List->GetItem(onitem), i * iconWidth, j * iconHeight, iconWidth, iconHeight, List->GetSelection() == onitem);

				if(List->GetSelection() == onitem)
				{
					selection = onitem;
					selectionx = i;
					selectiony = j;
				}
				onitem ++;
			}
		}
		
		if(selection >= 0)
		{
			Area clipp = ESVideo::GetClip();

			uint32_t textY = (clipp.Y + ((selectiony * iconHeight) - expandHeight) < ESVideo::GetScreenHeight() / 3) ? ESVideo::GetClip().Height - FontManager::GetBigFont()->GetHeight() - 16 : 16;
			FontManager::GetBigFont()->PutString(List->GetSelected()->GetText().c_str(), 32, textY, 0x000000FF);

			ESVideo::SetClip(Area(0, 0, ESVideo::GetScreenWidth(), ESVideo::GetScreenHeight()));
			DrawItem(List->GetItem(selection), (clipp.X + selectionx * iconWidth) - expandWidth, (clipp.Y + selectiony * iconHeight) - expandHeight, iconWidth + expandWidth * 2, iconHeight + expandHeight * 2, true);
		}

		return false;
	}
	else
	{
		return true;
	}
}



										FileSelect::FileSelect				(const std::string& aHeader, BookmarkList& aBookMarks, const std::string& aPath, MenuHook* aInputHook) :
	List(boost::make_shared<SummerfaceList>(Area(10, 10, 80, 80))),
	Interface(Summerface::Create("List", List)),
	Valid(true),
	Header(aHeader),
	BookMarks(aBookMarks)
{
	Interface->SetHook(aInputHook);
	List->SetInputConduit(boost::make_shared<SummerfaceTemplateConduit<FileSelect> >(this));

	Paths.push(aPath);
	LoadList(aPath);
}

bool									FileSelect::HandleInput				(Summerface_Ptr aInterface, const std::string& aWindow)
{
	if(ESInput::ButtonDown(0, ES_BUTTON_AUXRIGHT2))
	{
		SummerfaceItem_Ptr item = List->GetSelected();
		BookmarkList::iterator bookmark = std::find(BookMarks.begin(), BookMarks.end(), item->Properties["PATH"]);
		
		if(bookmark != BookMarks.end())
		{
			BookMarks.erase(bookmark);
			item->IntProperties["BOOKMARK"] = 0;
			item->SetColors(Colors::Normal, Colors::HighLight);
		}
		else
		{
			BookMarks.push_back(item->Properties["PATH"]);
			item->IntProperties["BOOKMARK"] = 1;
			item->SetColors(Colors::SpecialNormal, Colors::SpecialHighLight);
		}
	}

	return false;
}

std::string								FileSelect::GetFile					()
{
	if(Valid)
	{
		std::string result;
	
		while(!WantToDie())
		{
			Interface->Do();

			if(List->WasCanceled())
			{
				if(Paths.size() > 1)
				{
					Paths.pop();
					LoadList(Paths.top().c_str());
					continue;
				}
				else
				{
					return "";
				}
			}
			
			if(List->GetSelected()->IntProperties["DIRECTORY"])
			{
				Paths.push(List->GetSelected()->Properties["PATH"]);
				LoadList(Paths.top());
			}
			else
			{
				return List->GetSelected()->Properties["PATH"];
				break;
			}
		}
	
		return "";
	}
	else
	{
		ErrorCheck(0, "FileSelect::GetFile: FileSelect object is invalid.");
	}
}

void								FileSelect::LoadList						(const std::string& aPath)
{
	List->ClearItems();
	List->SetHeader("[%s] %s", Header.c_str(), aPath.c_str());

	if(Utility::DirectoryExists(aPath + "/__images"))
	{
		List->SetView(boost::make_shared<FlowListView>(List));
	}
	else
	{
		List->SetView(boost::make_shared<AnchoredListView>(List, true));
	}

	if(aPath.empty())
	{
		List->AddItem(MakeItem("Local Files", "/", true, false));

		for(BookmarkList::iterator i = BookMarks.begin(); i != BookMarks.end(); i ++)
		{
			if(!i->empty())
			{
				std::string nicename = *i;

				bool directory = false;
				if(nicename[nicename.length() - 1] != '/')
				{
						nicename = nicename.substr(nicename.rfind('/') + 1);
				}
				else
				{
						nicename = nicename.substr(0, nicename.length() - 1);
						nicename = nicename.substr(nicename.rfind('/') + 1);
						nicename.push_back('/');
						directory = true;
				}
				
				List->AddItem(MakeItem(nicename, *i, directory, !directory));
			}
		}
	}
	else
	{
		std::vector<std::string> items;
		Utility::ListDirectory(aPath, items);

		for(int i = 0; i != items.size(); i ++)
		{
			List->AddItem(MakeItem(items[i], aPath + items[i], items[i][items[i].length() - 1] == '/', items[i][items[i].length() - 1] != '/'));
		}

		List->Sort(AlphaSortDirectory);
	}
}

SummerfaceItem_Ptr					FileSelect::MakeItem						(const std::string& aName, const std::string& aPath, bool aDirectory, bool aFile)
{
	std::string extension = Utility::GetExtension(aPath);

	SummerfaceItem_Ptr item = boost::make_shared<SummerfaceItem>(aName, aDirectory ? "FolderICON" : (ImageManager::GetImage(extension + "ICON") ? extension + "ICON" : "FileICON"));
	item->IntProperties["DIRECTORY"] = aDirectory;
	item->IntProperties["FILE"] = aFile;
	item->IntProperties["BOOKMARK"] = std::find(BookMarks.begin(), BookMarks.end(), aPath) != BookMarks.end();
	item->Properties["PATH"] = aPath;
	item->Properties["THUMB"] = Utility::GetDirectory(aPath) + "/__images/" + Utility::GetFileName(aPath) + ".png";

	if(item->IntProperties["BOOKMARK"])
	{
		item->SetColors(Colors::SpecialNormal, Colors::SpecialHighLight);
	}

	return item;
}

