#include "DxLib.h"
#include "Box.h"
#include "Mouse.h"

namespace
{
	// �F
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
	m_pos->x = 320;		// X���W
	m_pos->y = 40;		// Y���W
	m_size->x = 445;	// X���W�T�C�Y
	m_size->y = 50;		// Y���W�T�C�Y
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