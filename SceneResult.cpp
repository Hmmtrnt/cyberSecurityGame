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
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		return (new SceneTitle);
	}
	return this;
}

void SceneResult::draw()
{
	DrawString(0, 0, "���U���g���", GetColor(255, 255, 255));
}