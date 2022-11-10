#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"
#include "Mouse.h"
#include "SceneMain.h"
#include "SceneExplanation.h"

namespace
{
	// 表示するテキスト
	const char* const kTitleText = "詐欺メールを見抜けッ！";
	const char* const kGuideText = "スペースキーを押してください";
	// タイトルフォントの位置
	constexpr int kFontWidth = 100;
	constexpr int kFontHeight = 200;
	// ガイドフォントの位置
	constexpr int kFontGuideWidth = 170;
	constexpr int kFontGuideHeight = 400;
	// キャラ１の座標
	constexpr int kCharWidth1 = 50;
	constexpr int kCharHeight1 = 300;
	// キャラ１の大きさ
	constexpr int kCharSizeWidth1 = 150;
	constexpr int kCharSizeHeight1 = 190;
	// キャラ２の座標
	constexpr int kCharWidth2 = 600;
	constexpr int kCharHeight2 = 300;
	// キャラ２の大きさ
	constexpr int kCharSizeWidth2 = 170;
	constexpr int kCharSizeHeight2 = 210;
	// 文字列の点滅
	constexpr int kTextDispFrame = 45;	// 表示
	constexpr int kTextHideFrame = 20;	// 隠れる
	// 背景色
	const int kBackgroundColor = GetColor(200, 200, 200);	// 灰色
	// 文字色
	const int kFontColor = GetColor(0, 0, 0);				// 黒
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
}

SceneTitle::SceneTitle() :
	m_hChar1(-1),
	m_hChar2(-1),
	m_fontHandle(-1),
	m_fontHandle2(-1),
	m_textBlinkFrame(0),
	m_fadeBright(0),
	m_fadeSpeed(0)
{
}

void SceneTitle::init()
{
	m_hChar1 = LoadGraph("data/TitleCharWaru_1.png");
	m_hChar2 = LoadGraph("data/TitleCharOdoroki1.png");
	m_fontHandle = CreateFontToHandle(NULL, 56, 4);
	m_fontHandle2 = CreateFontToHandle(NULL, 30, 4);
	m_textBlinkFrame = 0;
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
}

void SceneTitle::end()
{
	DeleteGraph(m_hChar1);
	DeleteGraph(m_hChar2);
	DeleteFontToHandle(m_fontHandle);
	DeleteFontToHandle(m_fontHandle2);
	SetDrawBright(255, 255, 255);
}

SceneBase* SceneTitle::update()
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
		return (new SceneExplanation);
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

void SceneTitle::draw()
{
	// 描画の輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// 背景
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackgroundColor, true);
	// 驚いたキャラ
	DrawExtendGraph(kCharWidth2, kCharHeight2, kCharWidth2 + kCharSizeWidth2, kCharHeight2 + kCharSizeHeight2, m_hChar2, true);
	// 悪そうなキャラ
	DrawExtendGraph(kCharWidth1, kCharHeight1, kCharWidth1 + kCharSizeWidth1, kCharHeight1 + kCharSizeHeight1, m_hChar1, true);
	// 文字列
	DrawStringToHandle(kFontWidth, kFontHeight, kTitleText, kFontColor, m_fontHandle);
	if (m_textBlinkFrame < kTextDispFrame)
	{
		DrawStringToHandle(kFontGuideWidth, kFontGuideHeight, kGuideText, kFontColor, m_fontHandle2);
	}

}