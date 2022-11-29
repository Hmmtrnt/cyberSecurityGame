#include "DxLib.h"
#include "Keyboard.h"

namespace
{
	constexpr int kKeyMax = 256;
}

namespace Key
{
	// �O�F���͂���Ă��Ȃ��A�P�F���͂��ꂽ�u�ԁA�Q�F���͂���Ă���
	int key[kKeyMax];
	void inputKey()
	{
		static char buf[kKeyMax];
		GetHitKeyStateAll(buf);
		for (int i = 0; i < kKeyMax; i++)
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