#include "SceneExplanation.h"
#include "SceneMain.h"
#include "DxLib.h"

SceneExplanation::SceneExplanation() :
	m_isEnd(false)
{
}

void SceneExplanation::init()
{
	m_isEnd = false;
}

SceneBase* SceneExplanation::update()
{
	inputKey(key);
	if (key[KEY_INPUT_SPACE] == 1)
	{
		return (new SceneMain);
	}
	return this;
}

void SceneExplanation::draw()
{
	DrawString(0, 0, "ê‡ñæâÊñ ", GetColor(255, 255, 255));
}