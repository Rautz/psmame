#include <es_system.h>

							Logger::Logger						(const Area& aRegion) : TextViewer(aRegion, "", false)
{
	SetHeader("Global Log");
}

							Logger::~Logger						()
{
}
									
void						Logger::Log							(const char* aMessage, ...)
{
	char array[1024];
	va_list args;
	va_start (args, aMessage);
	vsnprintf(array, 1024, aMessage, args);
	va_end(args);

	Lines.push_back(std::string(array));

	LongestLine = Lines[Lines.size() - 1].length() > LongestLine ? Lines[Lines.size() - 1].length() : LongestLine;
}

