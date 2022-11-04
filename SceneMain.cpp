#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"

SceneMain::SceneMain() :
	m_isEnd(false)
{
}

void SceneMain::init()
{
	m_isEnd = false;
}

SceneBase* SceneMain::update()
{
	inputKey(key);
	if (key[KEY_INPUT_SPACE] == 1)
	{
		return (new SceneResult);
	}
	if (key[KEY_INPUT_RETURN] == 1)
	{
		return (new SceneFail);
	}
	return this;
}

void SceneMain::draw()
{
	DrawString(0, 0, "ƒƒCƒ“‰æ–Ê", GetColor(255, 255, 255));
}