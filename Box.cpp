#include "DxLib.h"
#include "Box.h"

namespace
{
	// ボックスのサイズ↓仮
	constexpr int kBoxSizeX = 445;
	constexpr int kBoxSizeY = 50;
	// 色
	const int kColorB = GetColor(0, 0, 0);
}

Box::Box() :
	m_pos()
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

}

void Box::update()
{

}

void Box::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + kBoxSizeX, m_pos.y + kBoxSizeY, kColorB, false);
}