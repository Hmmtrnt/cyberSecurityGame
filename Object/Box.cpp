#include "DxLib.h"
#include "Box.h"
#include "Mouse.h"

namespace
{
	// 色
	const int kColorB = GetColor(0, 0, 0);
}

Box::Box() :
	m_pos(),
	m_size(),
	m_mouseX(0),
	m_mouseY(0),
	m_isTouch(false),
	m_pushFlame(0)
{
	
}

Box::~Box()
{
	
}

void Box::init()
{
	m_pos.x = 320;		// X座標
	m_pos.y = 40;		// Y座標
	m_size.x = 445;	// X座標サイズ
	m_size.y = 50;		// Y座標サイズ
	SetMouseDispFlag(true);
	m_pushFlame = 0;//無限ループ外で宣言
}

void Box::end()
{

}

void Box::update(int& pushNum)
{
	GetMousePoint(&m_mouseX, &m_mouseY);

	if (m_mouseX <= m_pos.x && m_mouseX >= m_pos.x + m_size.x &&
		m_mouseY <= m_pos.y && m_mouseY >= m_pos.y + m_size.y && 
		(GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (m_pushFlame == 0)
		{
			m_pushFlame = 1;
			if (m_pushFlame == 1)
			{
				pushNum--;
				if (pushNum <= 0)
				{
					pushNum = 0;
				}
			}
		}
	}
	else
	{
		m_pushFlame = 0;
	}
}

void Box::draw()
{
	GetMousePoint(&m_mouseX, &m_mouseY);
	DrawFormatString(0, 0, GetColor(0, 0, 0), "%d, %d", m_mouseX, m_mouseY);
	GetMousePoint(&m_mouseX, &m_mouseY);
}

bool Box::isTouchEnable()
{
	GetMousePoint(&m_mouseX, &m_mouseY);
	if (m_mouseX >= m_pos.x && m_mouseX <= m_pos.x + m_size.x &&
		m_mouseY >= m_pos.y && m_mouseY <= m_pos.y + m_size.y &&
		(GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (m_pushFlame == 0)
		{
			m_pushFlame = 1;
			if (m_pushFlame == 1)
			{
				return true;
			}
		}
	}
	
	return false;
}