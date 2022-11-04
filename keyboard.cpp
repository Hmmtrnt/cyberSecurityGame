#include "DxLib.h"
#include "Keyboard.h"

namespace
{
	int key[256];
}

namespace Key
{
	void inputKey()
	{
		static char buf[256];
		GetHitKeyStateAll(buf);
		for (int i = 0; i < 256; i++)
		{
			if (buf[i])
			{
				if (key[i] == 0) key[i] = 1;
				else if (key[i] == 1) key[i] = 2;
			}
			else key[i] = 0;
		}
	}
}