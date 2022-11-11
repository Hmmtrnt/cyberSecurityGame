#include "DxLib.h"
#include "Box.h"

namespace
{
	// 色
	const int kColorB = GetColor(0, 0, 0);
}

Box::Box() :
	m_pos(),
	m_vec()
{

}

Box::~Box()
{

}

void Box::init()
{
	// ↓仮座標
	m_pos.x = 320;	// X座標
	m_pos.y = 40;	// Y座標
	m_vec.x = 445;	// X座標
	m_vec.y = 50;	// Y座標
}

void Box::update()
{

}

void Box::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_vec.x, m_pos.y + m_vec.y, kColorB, false);
}