#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"
#include "Mouse.h"
#include "SceneMain.h"
#include "SceneExplanation.h"

namespace
{
	// サイズ
	constexpr int kRadius = 64;
	// フォントの位置
	constexpr int kFontWidth = 100;
	constexpr int kFontHeight = 200;
	// キャラ１の座標
	constexpr int kCharWidth = 50;
	constexpr int kCharHeight = 300;
	// キャラ１の大きさ
	constexpr int kCharSizeWidth = 150;
	constexpr int kCharSizeHeight = 190;
}

SceneTitle::SceneTitle() :
	m_hChar1(-1),
	m_fontHandle(-1)
{
}

void SceneTitle::init()
{
	m_hChar1 = LoadGraph("data/TitleCharWaru_1.png");

	m_fontHandle = CreateFontToHandle(NULL, 56, 4);
}

void SceneTitle::end()
{
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneTitle::update()
{
	inputKey(m_key);
	if (m_key[KEY_INPUT_SPACE] == 1)
	{
		return(new SceneExplanation);
	}
	return this;
}

void SceneTitle::draw()
{
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(200, 200, 200), true);
	DrawExtendGraph(kCharWidth, kCharHeight, kCharWidth + kCharSizeWidth, kCharHeight + kCharSizeHeight, m_hChar1, true);
	DrawStringToHandle(kFontWidth, kFontHeight, "詐欺メールを見抜けッ！", GetColor(0, 0, 0), m_fontHandle);
}