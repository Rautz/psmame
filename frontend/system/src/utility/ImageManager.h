#pragma once

class													ImageManager
{
	public:
		static void										Purge							();
		static void										SetDirectory					(const std::string& aPath) {Directory = aPath;}

		static Texture*									LoadImage						(const std::string& aName, const std::string& aPath);
		static Texture*									GetImage						(const std::string& aName);
	
	protected:
		static std::string								Directory;

		static std::map<std::string, Texture*>			Images;
};

