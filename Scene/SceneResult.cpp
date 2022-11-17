#include "SceneResult.h"
#include "SceneTitle.h"
#include "DxLib.h"

namespace
{
	// 表示するテキスト
	const char* const kGuideText = "スペースキーを押してタイトルへ";
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
	// 文字列の点滅
	constexpr int kTextDispFrame = 45;	// 表示
	constexpr int kTextHideFrame = 20;	// 隠れる
	// フォントの色
	const int kColorB = GetColor(0, 0, 0);	// 黒
	// ガイドフォントの位置
	constexpr int kFontGuideWidth = 280;
	constexpr int kFontGuideHeight = 500;
}

SceneResult::SceneResult() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_hBackGround(-1),
	m_fontHandle(-1),
	m_textBlinkFrame(0)
{
}

void SceneResult::init()
{
	m_fadeBright = kFadeBright;								// フェード処理
	m_fadeSpeed = kFadeSpeed;								// フェード速度
	m_hBackGround = LoadGraph("data/SceneResult.png");	// 背景のグラフィックハンドル
	m_fontHandle = CreateFontToHandle("BIZ UDPゴシック", 30, 4);
}

void SceneResult::end()
{
	DeleteGraph(m_hBackGround);
	DeleteFontToHandle(m_fontHandle);
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

	// テキストの点滅
	m_textBlinkFrame++;
	if (m_textBlinkFrame >= kTextDispFrame + kTextHideFrame)
	{
		m_textBlinkFrame = 0;
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
	DrawGraph(0, 0, m_hBackGround, true);
	if (m_textBlinkFrame < kTextDispFrame)
	{
		DrawStringToHandle(kFontGuideWidth, kFontGuideHeight, kGuideText, kColorB, m_fontHandle);
	}
}