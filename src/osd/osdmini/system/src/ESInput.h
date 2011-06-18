#pragma once

class				ESInputHelp
{
	public:	//Helpers
		static void							RefreshButton			(uint32_t aState, uint32_t& aHeld, uint32_t& aSingle)
		{
			if(aState && aHeld == 0xFFFFFFFF)
			{
				return;
			}

			aHeld = aState ? 1 : 0;
		
			if(!aState)
			{
				aSingle = 0;
			}
			else if(aState && aSingle == 0)
			{
				aSingle = 1;
			}
		}

		static bool							HandleSingleState		(uint32_t aHeld, uint32_t& aSingle)
		{
			if(aHeld == 0xFFFFFFFF)
			{
				return false;
			}
			else if(aSingle == 1)
			{
				aSingle = 2;
				return aHeld;
			}
			else
			{
				return false;
			}
		}
};

