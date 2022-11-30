#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"
#include "Box.h"

namespace
{
	// 色
	const int kColorB = GetColor(0, 0, 0);			// 黒
	const int kColorR = GetColor(255, 0, 0);		// 赤
	// 残り回数の座標
	constexpr int kFontPosX = 15;	// X座標
	constexpr int kFontPosY = 400;	// Y座標
	// フェード関連
	constexpr int kFadeBright = 0;	// 処理
	constexpr int kFadeSpeed = 7;	// 速度
}

SceneMain::SceneMain() :
	m_hBackGround(-1),
	m_fontHandle(-1),
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_pushNum(0),
	m_mouseX(0),
	m_mouseY(0),
	m_pushFlame(0),
	m_box(nullptr)
{
	// メモリの取得
	m_box = new Box;
}

SceneMain::~SceneMain()
{
	// メモリの開放
	delete m_box;
}

// 初期化処理
void SceneMain::init()
{
	m_hBackGround = LoadGraph("data/SceneMain.png");				// 背景
	m_fontHandle = CreateFontToHandle("BIZ UDPゴシック", 100, 4);	// フォント
	m_fadeBright = kFadeBright;										// フェード処理
	m_fadeSpeed = kFadeSpeed;										// フェード速度
	m_pushNum = 3;													// 押せる回数
	m_box->init();
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hBackGround);
	DeleteFontToHandle(m_fontHandle);
}

// 更新処理
SceneBase* SceneMain::update()
{	
	// フェード処理
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		m_fadeSpeed = 0;
	}
	// ゲームオーバー
	if ((m_fadeBright <= 0) && (m_fadeSpeed < 0) && (m_pushNum <= 0))
	{
		m_fadeBright = 0;
		return (new SceneFail);
	}
	// ゲームクリア
	else if ((m_fadeBright <= 0) && (m_fadeSpeed < 0))
	{
		m_fadeBright = 0;
		return (new SceneResult);
	}
	if (m_fadeSpeed == 0)
	{
		// フェードアウト開始
		if (m_box->isTouchEnable())
		{
			m_fadeSpeed = -kFadeSpeed;
		}
		else if (m_pushNum <= 0)
		{
			m_fadeSpeed = -kFadeSpeed;
		}
	}
	m_box->update(m_pushNum, m_fadeBright);
	return this;
}

void SceneMain::draw()
{
	// 描画の輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// 背景
	DrawGraph(0, 0, m_hBackGround, true);

	if (m_pushNum >= 2)
	{
		DrawFormatStringToHandle(15, 400, kColorB, m_fontHandle, "後%d回", m_pushNum);
	}
	// 残り回数が一回でフォントが赤になる
	else if (m_pushNum <= 1)
	{
		DrawFormatStringToHandle(15, 400, kColorR, m_fontHandle, "後%d回", m_pushNum);
	}
}