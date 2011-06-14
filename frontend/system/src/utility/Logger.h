#ifndef	SYSTEM__LOGGER_H
#define	SYSTEM__LOGGER_H

class				Logger : public TextViewer
{
	public:
									Logger						(const Area& aRegion);
									~Logger						();
									
		void						Log							(const char* aString, ...);
};

#endif

