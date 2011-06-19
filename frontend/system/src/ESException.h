#ifndef SYSTEM__EXCEPTION_H
#define SYSTEM__EXCEPTION_H

class					ESException : public std::exception
{
	public:
						ESException				(const char* aMessage, ...)
		{
			char buffer[2048];

			va_list args;
			va_start (args, aMessage);
			vsnprintf(buffer, 2048, aMessage, args);
			va_end(args);

			Error = buffer;
		}

						ESException				(const std::string& aError)		{Error = aError;}
		virtual			~ESException			()								throw(){};
						
		const char*		what					()								{return Error.c_str();}
	
	protected:
		std::string		Error;
};

#endif

