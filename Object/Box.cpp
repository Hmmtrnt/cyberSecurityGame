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
	m_mouseX(0),
	m_mouseY(0),
	m_MouseInput(0),
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
	m_MouseInput = GetMouseInput();
}

void end()
{

}

void Box::update()
{
	GetMousePoint(&m_mouseX, &m_mouseY);
}

bool Box::isTouchEnable(Vec2 pos)
{
	if (m_mouseX > m_pos->x && m_mouseX < m_pos->x + m_size->x &&
		m_mouseY > m_pos->y && m_mouseY < m_pos->y + m_size->y &&
		(m_MouseInput & MOUSE_INPUT_LEFT) == 0)
	{
		return true;
	}
}