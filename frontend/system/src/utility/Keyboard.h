#ifndef SYSTEM__KEYBOARD_H
#define SYSTEM__KEYBOARD_H

class										Keyboard : public SummerfaceWindow
{
	public:
											Keyboard				(const Area& aRegion, const std::string& aHeader, const std::string& aText);
		virtual								~Keyboard				();

		bool								Draw					();
		bool								Input					();
				
		std::string							GetText					()								{return Text;};
		void								SetText					(const std::string& aText)		{Text = aText;};

		bool								WasCanceled				()								{return Canceled;};
				
		
	protected:
		std::string							Text;
		
		int32_t								Column;
		int32_t								Row;
		uint32_t							Shift;
		
		bool								Canceled;
};

#endif

