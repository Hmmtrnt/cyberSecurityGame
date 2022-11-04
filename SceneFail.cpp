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
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		return (new SceneTitle);
	}
	return this;
}

void SceneFail::draw()
{
	DrawString(0, 0, "���s���", GetColor(255, 255, 255));
}