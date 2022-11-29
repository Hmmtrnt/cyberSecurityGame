#include "DxLib.h"
#include "Keyboard.h"

namespace
{
	constexpr int kKeyMax = 256;
}

namespace Key
{
	// ‚OF“ü—Í‚³‚ê‚Ä‚¢‚È‚¢A‚PF“ü—Í‚³‚ê‚½uŠÔA‚QF“ü—Í‚³‚ê‚Ä‚¢‚é
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