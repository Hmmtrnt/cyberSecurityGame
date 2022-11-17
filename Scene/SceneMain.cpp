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
	// �F
	const int kColorB = GetColor(0, 0, 0);			// ��
	const int kColorR = GetColor(255, 0, 0);		// ��
	// �c��񐔂̍��W
	constexpr int kFontPosX = 15;
	constexpr int kFontPosY = 400;
	// �t�F�[�h�֘A
	constexpr int kFadeBright = 0;	// ����
	constexpr int kFadeSpeed = 7;	// ���x
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
	m_fontHandle = CreateFontToHandle("BIZ UDP�S�V�b�N", 100, 4);
	m_fadeBright = kFadeBright;	// �t�F�[�h����
	m_fadeSpeed = kFadeSpeed;	// �t�F�[�h���x
	m_pushNum = 3;
	m_box->init();
	m_mouse->init();
}

void SceneMain::end()
{
	DeleteGraph(m_hBackGround);
	DeleteFontToHandle(m_fontHandle);
	m_mouse->end();
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
		// �t�F�[�h�A�E�g�J�n
		if (CheckHit(m_box->getPos(), m_box->getSize(), m_mouse->getPosX(), m_mouse->getPosY(), m_mouse->getSizeX(), m_mouse->getSizeY()))
		{
			//DrawString(0, 0, "�����ꂽ", GetColor(0, 0, 0), true);
			m_fadeSpeed = -kFadeSpeed;
		}
		else if (m_pushNum <= 0)
		{
			//DrawString(0, 0, "���s", GetColor(0, 0, 0), true);
			m_fadeSpeed = -kFadeSpeed;
		}
	}
	return this;
}

void SceneMain::draw()
{
	// �`��̋P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
	// �w�i
	DrawGraph(0, 0, m_hBackGround, true);

	if (m_pushNum >= 2)
	{
		DrawFormatStringToHandle(15, 400, kColorB, m_fontHandle, "��%d��", m_pushNum);
	}
	else if (m_pushNum <= 1)
	{
		DrawFormatStringToHandle(15, 400, kColorR, m_fontHandle, "��%d��", m_pushNum);
	}
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