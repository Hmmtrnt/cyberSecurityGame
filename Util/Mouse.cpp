#include "Mouse.h"
#include "DxLib.h"

//namespace
//{
//	constexpr int kLogNum = 16;
//	// 入力ログ	0が最新の状態
//	int mouseLog[kLogNum];
//}
//
//namespace Mouse
//{
//	// マウスの入力状態取得
//	void update()
//	{
//		// ログの更新
//		for (int i = kLogNum - 1; i >= 1; i--)
//		{
//			mouseLog[i] = mouseLog[i - 1];
//		}
//		// 最新の状態
//		if (GetMouseInput() & MOUSE_INPUT_LEFT)
//		{
//			mouseLog[0] = 1;
//		}
//		else
//		{
//			mouseLog[0] = 0;
//		}
//	}
//
//	// 現在のマウス位置取得
//	Vec2 getPos()
//	{
//		Vec2 mousePos{ 0,0 };
//		int mouseX = 0;
//		int mouseY = 0;
//		if (GetMousePoint(&mouseX, &mouseY) == -1)
//		{
//			// エラー発生
//			return mousePos;
//		}
//		mousePos.x = static_cast<float>(mouseX);
//		mousePos.y = static_cast<float>(mouseY);
//		return mousePos;
//	}
//
//	// 押し下げ判定
//	bool isPressLeft()
//	{
//		return (mouseLog[0]);
//	}
//	// トリガー判定
//	bool isTriggerLeft()
//	{
//		bool isNow = (mouseLog[0]);	// 現在の状態
//		bool isLast = (mouseLog[1]);	// １フレーム前の状態
//		return (isNow && !isLast);
//	}
//	// 離した判定
//	bool isRelaseLeft()
//	{
//		bool isNow = (mouseLog[0]);	// 現在の状態
//		bool isLast = (mouseLog[1]);	// １フレーム前の状態
//		return (!isNow && isLast);
//	}
//}

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

void Mouse::update()
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
		DrawBox(m_drawX - 2, m_drawY - 2, m_drawX + 2, m_drawY + 2, m_drawColor, TRUE);
	}
}