#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"
#include "game.h"
#include "Mouse.h"
#include "Box.h"
#include "Mouse.h"

namespace
{
	// 色
	const int kColorB = GetColor(0, 0, 0);			// 黒
	const int kColorR = GetColor(255, 0, 0);		// 赤
	// 残り回数の座標
	constexpr int kFontPosX = 15;
	constexpr int kFontPosY = 400;
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
	m_box = new Box;
}

SceneMain::~SceneMain()
{
	delete m_box;
}

void SceneMain::init()
{
	m_hBackGround = LoadGraph("data/SceneMain.png");
	m_fontHandle = CreateFontToHandle("BIZ UDPゴシック", 100, 4);
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
	m_pushNum = 3;
	m_box->init();
}

void SceneMain::end()
{
	DeleteGraph(m_hBackGround);
	DeleteFontToHandle(m_fontHandle);
}

SceneBase* SceneMain::update()
{
	Vec2 mousePos = Mouse::getPos();
	
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		m_fadeSpeed = 0;
	}
	if ((m_fadeBright <= 0) && (m_fadeSpeed < 0) && (m_pushNum <= 0)/*&& m_box->isTouchEnable()*/)
	{
		m_fadeBright = 0;
		return (new SceneFail);
	}
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
			//DrawString(0, 0, "押された", GetColor(0, 0, 0), true);
			m_fadeSpeed = -kFadeSpeed;
		}
		else if (m_pushNum <= 0)
		{
			//DrawString(0, 0, "失敗", GetColor(0, 0, 0), true);
			m_fadeSpeed = -kFadeSpeed;
		}
	}
	m_box->update(m_pushNum);
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
	else if (m_pushNum <= 1)
	{
		DrawFormatStringToHandle(15, 400, kColorR, m_fontHandle, "後%d回", m_pushNum);
	}
	m_box->draw();
}
//
//bool SceneMain::CheckHit()
//{
//	GetMousePoint(&m_mouseX, &m_mouseY);
//	if (m_mouseX > m_box->getPos() && m_mouseX < m_box->getPos() + m_box->getSize() &&
//		m_mouseY > m_box->getPos() && m_mouseY < m_box->getPos() + m_box->getSize() &&
//		(GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
//	{
//		if (m_pushFlame == 0)
//		{
//			m_pushFlame = 1;
//			if (m_pushFlame == 1)
//			{
//				return true;
//			}
//		}
//	}
//	else
//	{
//		return false;
//	}
//}