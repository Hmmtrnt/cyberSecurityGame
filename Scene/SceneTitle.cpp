#include "SceneTitle.h"
#include "DxLib.h"
#include "game.h"
#include "Mouse.h"
#include "SceneMain.h"
#include "SceneExplanation.h"

namespace
{
	// 表示するテキスト
	const char* const kTitleText = "詐欺メールを見抜け";
	const char* const kGuideText = "スペースキーを押してください";
	// サイズ
	constexpr int kRadius = 64;
	// フォントの位置
	constexpr int kFontWidth = 100;
	constexpr int kFontHeight = 200;
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
	constexpr int kTextDixpFrame = 45;	// 現れる
	constexpr int kTextHideFrame = 15;	// 隠れる
	// 背景色
	const int kBackgroundColor = GetColor(200, 200, 200);
	// 文字色
	const int kFontColor = GetColor(0, 0, 0);
}

SceneTitle::SceneTitle() :
	m_hChar1(-1),
	m_hChar2(-1),
	m_fontHandle(-1)
{
}

void SceneTitle::init()
{
	m_hChar1 = LoadGraph("data/TitleCharWaru_1.png");
	m_hChar2 = LoadGraph("data/TitleCharOdoroki1.png");
	m_fontHandle = CreateFontToHandle(NULL, 56, 4);
}

void SceneTitle::end()
{
	DeleteGraph(m_hChar1);
	DeleteGraph(m_hChar2);
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
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, kBackgroundColor, true);
	DrawExtendGraph(kCharWidth2, kCharHeight2, kCharWidth2 + kCharSizeWidth2, kCharHeight2 + kCharSizeHeight2, m_hChar2, true);
	DrawExtendGraph(kCharWidth1, kCharHeight1, kCharWidth1 + kCharSizeWidth1, kCharHeight1 + kCharSizeHeight1, m_hChar1, true);
	DrawStringToHandle(kFontWidth, kFontHeight, "詐欺メールを見抜けッ！", GetColor(0, 0, 0), m_fontHandle);
}