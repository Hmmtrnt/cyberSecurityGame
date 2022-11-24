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
	m_isTouch(false)
{
	m_pos = new Vec2;
	m_size = new Vec2;
}

Box::~Box()
{
	delete m_pos;
	delete m_size;
}

void Box::init()
{
	m_pos->x = 320;		// X座標
	m_pos->y = 40;		// Y座標
	m_size->x = 445;	// X座標サイズ
	m_size->y = 50;		// Y座標サイズ
	Vec2 mousePos = Mouse::getPos();
}

void end()
{

}

void Box::update()
{

}

bool Box::isTouchEnable(Vec2 pos)
{
	if ()
}