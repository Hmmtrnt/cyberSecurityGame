#include "SceneMain.h"
#include "SceneResult.h"
#include "SceneFail.h"
#include "DxLib.h"
#include "game.h"
#include "mouse.h"
#include "Box.h"
#include "Mouse.h"

namespace
{
	// 色
	const int kColorG = GetColor(200, 200, 200);	// 灰色
	const int kColorB = GetColor(0, 0, 0);			// 黒
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
	m_box(nullptr),
	m_mouse(nullptr)
{
	m_box = new Box;
	m_mouse = new Mouse;
}

SceneMain::~SceneMain()
{
	delete m_box;
	delete m_mouse;
}

void SceneMain::init()
{
	m_hBackGround = LoadGraph("data/SceneMain.png");
	m_fontHandle = CreateFontToHandle(NULL, 30, 4);
	m_fadeBright = kFadeBright;	// フェード処理
	m_fadeSpeed = kFadeSpeed;	// フェード速度
	m_pushNum = 3;
	m_box->init();
	m_mouse->init();
}

void SceneMain::end()
{
	DeleteGraph(m_hBackGround);
	DeleteFontToHandle(m_fontHandle);
	
}

SceneBase* SceneMain::update()
{
	m_mouse->update(m_pushNum);
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		m_fadeSpeed = 0;
	}
	if ((m_fadeBright <= 0) && (m_fadeSpeed < 0) && 
		(CheckHit(m_box->getPos(), m_box->getSize(), m_mouse->getPosX(), m_mouse->getPosY(), m_mouse->getSizeX(), m_mouse->getSizeY())))
	{
		m_fadeBright = 0;
		return (new SceneResult);
	}
	else if ((m_fadeBright <= 0) && (m_fadeSpeed < 0) && (m_pushNum <= 0))
	{
		m_fadeBright = 0;
		return (new SceneFail);
	}
	if (m_fadeSpeed == 0)
	{
		// フェードアウト開始
		if (CheckHit(m_box->getPos(), m_box->getSize(), m_mouse->getPosX(), m_mouse->getPosY(), m_mouse->getSizeX(), m_mouse->getSizeY()))
		{
			DrawString(0, 0, "押された", GetColor(0, 0, 0), true);
			m_fadeSpeed = -kFadeSpeed;
		}
		else if (m_pushNum <= 0)
		{
			DrawString(0, 0, "失敗", GetColor(0, 0, 0), true);
			m_fadeSpeed = -kFadeSpeed;
		}
	}
	return this;
}

void SceneMain::draw()
{
	// 描画の輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// 背景
	DrawGraph(0, 0, m_hBackGround, true);
	// 答えとなる当たり判定
	m_box->draw();
	m_mouse->draw();

	if (CheckHit(m_box->getPos(), m_box->getSize(), m_mouse->getPosX(), m_mouse->getPosY(), m_mouse->getSizeX(), m_mouse->getSizeY()))
	{
		DrawString(0, 0, "押された", GetColor(0, 0, 0), true);
	}
	else
	{
	DrawString(0, 0, "押されていない", GetColor(0, 0, 0), true);
	}
	DrawFormatString(0, 15, kColorB, "後%d回", m_pushNum);
}

bool SceneMain::CheckHit(Vec2* pos, Vec2* size, int m_mousePosX, int m_mousePosY, int m_mouseSizeX, int m_mouseSizeY)
{
	if ((pos->x + size->x > m_mousePosX) && (pos->x < m_mouseSizeX))
	{
		if ((pos->y + size->y > m_mousePosY) && (pos->y < m_mousePosY))
		{
			return true;
		}
	}
	return false;
}