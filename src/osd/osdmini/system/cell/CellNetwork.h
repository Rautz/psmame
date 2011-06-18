#pragma once

class								ESSocket
{
	public:
									ESSocket			(const char* aHost, uint32_t aPort);
									~ESSocket			();

		uint32_t					ReadString			(void* aBuffer, uint32_t aLength);
		uint32_t					Read				(void* aBuffer, uint32_t aLength);
		void						Write				(const void* aBuffer, uint32_t aLength);

	protected:
		int							Socket;
};

class								ESNetwork
{
	public:
		static void					Initialize			();
		static void					Shutdown			();

		static ESSocket*			OpenSocket			(const char* aHost, uint32_t aPort);
};

