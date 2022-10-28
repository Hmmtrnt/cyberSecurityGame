#include "SceneMain.h"
#include "DxLib.h"

SceneMain::SceneMain() :
	m_isEnd(false)
{
}

void SceneMain::init()
{
	m_isEnd = false;
}

void SceneMain::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isEnd = true;
	}
}

void SceneMain::draw()
{
	DrawString(0, 0, "ƒƒCƒ“‰æ–Ê", GetColor(255, 255, 255));
}