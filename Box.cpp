#include "DxLib.h"
#include "Box.h"

namespace
{
	// �F
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
	// �������W
	m_pos.x = 320;	// X���W
	m_pos.y = 40;	// Y���W
	m_vec.x = 445;	// X���W
	m_vec.y = 50;	// Y���W
}

void Box::update()
{

}

void Box::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_vec.x, m_pos.y + m_vec.y, kColorB, false);
}