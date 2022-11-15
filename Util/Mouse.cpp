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

}

void Mouse::update(int& pushNum)
{
	// マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
	if (GetMouseInputLog2(&m_button, &m_clickX, &m_clickY, &m_logType, TRUE) == 0)
	{
		// 左ボタンが押されたり離されたりしていたら描画するかどうかのフラグを立てて、座標も保存する
		if ((m_button & MOUSE_INPUT_LEFT) != 0)
		{
			m_drawFlag = TRUE;
			m_drawX = m_clickX;
			m_drawY = m_clickY;
			// 押した回数
			if (m_logType == MOUSE_INPUT_LOG_DOWN)
			{
				pushNum--;
			}
			
			// 四角形の色を押された場合は白に、離された場合は紫にする
			m_drawColor = m_logType == MOUSE_INPUT_LOG_DOWN ? GetColor(255, 255, 255) : GetColor(255, 0, 255);
		}
	}
}

void Mouse::draw()
{
	// 描画するかどうかのフラグが立っていたら、マウスの左ボタンが押されたり離されたりした座標に小さい四角形を描画する
	if (m_drawFlag == TRUE)
	{
		DrawBox(getPosX(), getPosY(), getSizeX(), getSizeY(), m_drawColor, TRUE);
	}
}