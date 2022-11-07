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
	m_fontHandle(-1)
{

}

void SceneTitle::init()
{
	m_fontHandle = CreateFontToHandle(NULL, 40, 3);
}

void SceneTitle::end()
{
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneTitle::update()
{
	inputKey(m_key);
	if (m_key[KEY_INPUT_SPACE] == 1)
	{
		return(new SceneExplanation);
	}
	return this;
}

void SceneTitle::draw()
{

	DrawString(0, 0, "�^�C�g�����", GetColor(255, 255, 255), m_fontHandle);
}