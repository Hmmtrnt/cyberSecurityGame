#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// 文字列
	const char* const kURL = "URL →";
	const char* const kText = "本文→";
	// 色
	const int kColorG = GetColor(200, 200, 200);	// 灰色
	const int kColorB = GetColor(0, 0, 0);			// 黒
	// URLの枠の座標
	constexpr int kURLFrameX = 350;
	constexpr int kURLFrameY = 50;
	// URLの枠のサイズ
	constexpr int kSizeURLFrameX = 400;
	constexpr int kSizeURLFrameY = 130;
	// 本文の枠の座標
	constexpr int kTextFrameX = 350;
	constexpr int kTextFrameY = 230;
	// 本文の枠のサイズ
	constexpr int kSizeTextFrameX = 400;
	constexpr int kSizeTextFrameY = 300;
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
}

SceneMain::SceneMain() :
	m_hBackGround(-1),
	m_fontHandle(-1),
	m_fadeBright(0),
	m_fadeSpeed(0)
{
}

void SceneMain::init()
{
	m_hBackGround = LoadGraph("data/SceneMain.png");
	m_fontHandle = CreateFontToHandle(NULL, 30, 4);
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
}

void SceneMain::end()
{
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneMain::update()
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
		return (new SceneResult);
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
	if (key[KEY_INPUT_RETURN] == 1)
	{
		return (new SceneFail);
	}
	else if (key[KEY_INPUT_SPACE] == 1)
	{
		return (new SceneResult);
	}
	else if (key[KEY_INPUT_TAB] == 1)
	{
		return (new SceneExplanation);
	}*/
	return this;
}

void SceneMain::draw()
{
	// 描画の輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// 背景
	DrawGraph(0, 0, m_hBackGround, true);
}