#include "SceneTitle.h"
#include "DxLib.h"
#include "Mouse.h"

SceneTitle::SceneTitle() :
	m_isEnd(false)
{
}

void SceneTitle::init()
{
	m_isEnd = false;
}

void SceneTitle::update()
{
	/*int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}*/

	if (Mouse::isTriggerLeft())
	{
		m_isEnd = true;
	}
}

void SceneTitle::draw()
{
	DrawString(0, 0, "ƒ^ƒCƒgƒ‹‰æ–Ê", GetColor(255, 255, 255));
}