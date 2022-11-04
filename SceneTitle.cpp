#include "SceneTitle.h"
#include "DxLib.h"
#include "Mouse.h"
//#include "Keyboard.h"
#include "SceneMain.h"
#include "SceneExplanation.h"

namespace
{
	// サイズ
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
	inputKey(key);
	if (key[KEY_INPUT_SPACE] == 1)
	{
		return(new SceneExplanation);
	}
	return this;
}

void SceneTitle::draw()
{

	DrawString(0, 0, "タイトル画面", GetColor(255, 255, 255));
}