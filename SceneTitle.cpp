#include "SceneTitle.h"
#include "DxLib.h"
#include "Mouse.h"
//#include "Keyboard.h"
#include "SceneMain.h"
#include "SceneExplanation.h"

namespace
{
	// �T�C�Y
	constexpr int kRadius = 64;
}

SceneTitle::SceneTitle() :
	m_isEnd(false)
{
}

void SceneTitle::init()
{
	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{
	/*int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		m_isEnd = true;
	}*/

	inputKey(key);
	if (key[KEY_INPUT_SPACE] == 1)
	{
		return(new SceneExplanation);
	}
	return this;
}

void SceneTitle::draw()
{
	DrawString(0, 0, "�^�C�g�����", GetColor(255, 255, 255));
}