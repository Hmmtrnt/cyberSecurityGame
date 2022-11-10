#include "SceneFail.h"
#include "SceneTitle.h"
#include "DxLib.h"

namespace
{
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
}

SceneFail::SceneFail() :
	m_fadeBright(0),
	m_fadeSpeed(0)
{
}

void SceneFail::init()
{
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
}

SceneBase* SceneFail::update()
{
	// フェードアウト処理
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		m_fadeSpeed = 0;
	}
	if ((m_fadeBright <= 0) && (m_fadeSpeed < 0))
	{
		m_fadeBright = 0;
		return (new SceneTitle);
	}
	if (m_fadeSpeed == 0)
	{
		// フェードアウト開始
		inputKey(m_key);
		if (m_key[KEY_INPUT_SPACE] == 1)
		{
			m_fadeSpeed = -kFadeSpeed;
		}
	}
	/*inputKey(key);
	if (key[KEY_INPUT_SPACE] == 1)
	{
		return (new SceneTitle);
	}*/
	return this;
}

void SceneFail::draw()
{
	// 描画の輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	DrawString(0, 0, "失敗画面", GetColor(255, 255, 255));
}