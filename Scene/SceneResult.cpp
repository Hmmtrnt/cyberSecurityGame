#include "SceneResult.h"
#include "SceneTitle.h"
#include "DxLib.h"

namespace
{
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
}

SceneResult::SceneResult() :
	m_fadeBright(0),
	m_fadeSpeed(0)
{
}

void SceneResult::init()
{
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
	//ChangeFont("ＭＳ 明朝");
}

SceneBase* SceneResult::update()
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
	return this;
}

void SceneResult::draw()
{
	// 描画の輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	DrawString(0, 0, "リザルト画面", GetColor(255, 255, 255));
}