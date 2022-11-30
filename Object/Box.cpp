#include "DxLib.h"
#include "Box.h"

namespace
{
	// 色
	const int kColorB = GetColor(0, 0, 0);	// 黒
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

// 初期化処理
void Box::init()
{
	m_pos.x = 320;		// X座標
	m_pos.y = 40;		// Y座標
	m_size.x = 445;	// X座標サイズ
	m_size.y = 50;		// Y座標サイズ
	SetMouseDispFlag(true);
	m_pushFlame = 0;//無限ループ外で宣言
}

// 更新処理
void Box::update(int& pushNum, int& fadeBright)
{
	// マウスの座標取得
	GetMousePoint(&m_mouseX, &m_mouseY);

	if (fadeBright < 255) return;

	// 答えの範囲外を押したとき
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		// 押された瞬間
		if (m_pushFlame == 0)
		{
			m_pushFlame = 1;
			pushNum--;
			if (pushNum <= 0)
			{
				pushNum = 0;
			}
		}
	}
	else
	{
		// フレームリセット
		m_pushFlame = 0;
	}
}

// 答えとなる範囲をクリックしたかどうか
bool Box::isTouchEnable()
{
	// マウスの座標取得
	GetMousePoint(&m_mouseX, &m_mouseY);
	// 答えの範囲をクリック
	if (m_mouseX >= m_pos.x && m_mouseX <= m_pos.x + m_size.x &&
		m_mouseY >= m_pos.y && m_mouseY <= m_pos.y + m_size.y &&
		(GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		// 押された瞬間
		if (m_pushFlame == 0)
		{
			m_pushFlame = 1;
			return true;
		}
	}
	
	return false;
}