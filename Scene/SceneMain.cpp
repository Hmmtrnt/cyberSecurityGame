#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// 背景色
	const int kBackgroundColor = GetColor(200, 200, 200);	// 灰色
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
}

SceneMain::SceneMain() :
	m_fadeBright(0),
	m_fadeSpeed(0)
{
}

void SceneMain::init()
{
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
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
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackgroundColor, true);
}