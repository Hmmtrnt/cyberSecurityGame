#include "SceneFail.h"
#include "DxLib.h"

SceneFail::SceneFail() :
	m_isEnd(false)
{
}

void SceneFail::init()
{
	m_isEnd = false;
}

void SceneFail::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}
}

void SceneFail::draw()
{
	DrawString(0, 0, "Ž¸”s‰æ–Ê", GetColor(255, 255, 255));
}