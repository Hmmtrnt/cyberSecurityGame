#include "SceneFail.h"
#include "SceneTitle.h"
#include "DxLib.h"

SceneFail::SceneFail() :
	m_isEnd(false)
{
}

void SceneFail::init()
{
	m_isEnd = false;
}

SceneBase* SceneFail::update()
{
	inputKey(key);
	if (key[KEY_INPUT_SPACE] == 1)
	{
		return (new SceneTitle);
	}
	return this;
}

void SceneFail::draw()
{
	DrawString(0, 0, "Ž¸”s‰æ–Ê", GetColor(255, 255, 255));
}