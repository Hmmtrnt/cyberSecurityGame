#include "Mouse.h"
#include "DxLib.h"

Mouse::Mouse() :
	m_button(0),
	m_clickX(0),
	m_clickY(0),
	m_logType(0),
	m_drawFlag(false),
	m_drawX(0),
	m_drawY(0),
	m_drawColor(0)
{
}

Mouse::~Mouse()
{
}

void Mouse::init()
{
	m_button = 0;
	m_clickX = 0;
	m_clickY = 0;
	m_logType = 0;
	m_drawFlag = false;
	m_drawX = 0;
	m_drawY = 0;
	m_drawColor = 0;
}

void Mouse::end()
{
	m_button = 0;
	m_logType = 0;
}

void Mouse::update(int& pushNum)
{
	// マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
	if (GetMouseInputLog2(&m_button, &m_clickX, &m_clickY, &m_logType, TRUE) == 0)
	{
		// 左ボタンが押されたり離されたりしていたら処理するかどうかのフラグを立てて、座標も保存する
		if ((m_button & MOUSE_INPUT_LEFT) != 0)
		{
			m_drawFlag = TRUE;
			m_drawX = m_clickX;
			m_drawY = m_clickY;
			// 押した回数
			if (m_logType == MOUSE_INPUT_LOG_DOWN)
			{
				pushNum--;
				if (pushNum <= 0)
				{
					pushNum = 0;
				}
			}
			else if (m_logType == MOUSE_INPUT_LOG_UP)
			{
				return;
			}
		}
	}
}