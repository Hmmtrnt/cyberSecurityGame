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
	m_size()
{
	m_pos = new Vec2;
	m_size = new Vec2;
	m_mouse = new Mouse;
}

Box::~Box()
{
	delete m_pos;
	delete m_size;
	delete m_mouse;
}

void Box::init()
{
	// ↓仮座標
	m_pos->x = 320;	// X座標
	m_pos->y = 40;	// Y座標
	m_size->x = 445;	// X座標
	m_size->y = 50;	// Y座標
}

void end()
{

}

void Box::update()
{
	
}

void Box::draw()
{
	DrawBox(m_pos->x, m_pos->y, m_pos->x + m_size->x, m_pos->y + m_size->y, kColorB, false);
	/*if (CheckHit(m_pos, m_size, m_mouse->getPosX(), m_mouse->getPosY(), m_mouse->getSizeX(), m_mouse->getSizeY()))
	{
		DrawString(0, 0, "押せた", GetColor(0, 0, 0), true);
	}
	else
	{
		DrawString(0, 0, "押せていない", GetColor(0, 0, 0), true);
	}*/
}

//bool Box::CheckHit(Vec2* pos, Vec2* size, int mousePosX, int mousePosY, int mouseSizeX, int mouseSizeY)
//{
//	if ((size->x > mousePosX) && (pos->x < mouseSizeX))
//	{
//		if ((size->y > mousePosY) && (pos->y < mousePosY))
//		{
//			return true;
//		}
//	}
//	return false;
//}