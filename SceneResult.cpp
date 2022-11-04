#include "SceneResult.h"
#include "SceneTitle.h"
#include "DxLib.h"

SceneResult::SceneResult() :
	m_isEnd(false)
{
}

void SceneResult::init()
{
	m_isEnd = false;
}

SceneBase* SceneResult::update()
{
	inputKey(key);
	if (key[KEY_INPUT_SPACE] == 1)
	{
		return (new SceneTitle);
	}
	return this;
}

void SceneResult::draw()
{
	DrawString(0, 0, "ƒŠƒUƒ‹ƒg‰æ–Ê", GetColor(255, 255, 255));
}