#include "SceneResult.h"
#include "SceneTitle.h"
#include "DxLib.h"

namespace
{
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
	// 文字列の点滅
	constexpr int kTextDispFrame = 45;	// 表示
	constexpr int kTextHideFrame = 20;	// 隠れる
}

SceneResult::SceneResult() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_hBackGround(-1),
	m_textBlinkFrame(0)
{
}

void SceneResult::init()
{
	m_fadeBright = kFadeBright;								// フェード処理
	m_fadeSpeed = kFadeSpeed;								// フェード速度
	m_hBackGround = LoadGraph("data/SceneResult.png");	// 背景のグラフィックハンドル
}

void SceneResult::end()
{
	DeleteGraph(m_hBackGround);
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
	//DrawString(0, 0, "リザルト画面", GetColor(255, 255, 255));
	DrawGraph(0, 0, m_hBackGround, true);
}