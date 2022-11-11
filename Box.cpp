#include "DxLib.h"
#include "Box.h"

namespace
{
	// �{�b�N�X�̃T�C�Y����
	constexpr int kBoxSizeX = 445;
	constexpr int kBoxSizeY = 50;
	// �F
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
	// �������W
	m_pos.x = 320;	// X���W
	m_pos.y = 40;	// Y���W

}

void Box::update()
{

}

void Box::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + kBoxSizeX, m_pos.y + kBoxSizeY, kColorB, false);
}