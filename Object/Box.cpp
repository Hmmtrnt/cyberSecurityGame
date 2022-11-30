#include "DxLib.h"
#include "Box.h"

namespace
{
	// �F
	const int kColorB = GetColor(0, 0, 0);	// ��
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

// ����������
void Box::init()
{
	m_pos.x = 320;		// X���W
	m_pos.y = 40;		// Y���W
	m_size.x = 445;	// X���W�T�C�Y
	m_size.y = 50;		// Y���W�T�C�Y
	SetMouseDispFlag(true);
	m_pushFlame = 0;//�������[�v�O�Ő錾
}

// �X�V����
void Box::update(int& pushNum, int& fadeBright)
{
	// �}�E�X�̍��W�擾
	GetMousePoint(&m_mouseX, &m_mouseY);

	if (fadeBright < 255) return;

	// �����͈̔͊O���������Ƃ�
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		// �����ꂽ�u��
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
		// �t���[�����Z�b�g
		m_pushFlame = 0;
	}
}

// �����ƂȂ�͈͂��N���b�N�������ǂ���
bool Box::isTouchEnable()
{
	// �}�E�X�̍��W�擾
	GetMousePoint(&m_mouseX, &m_mouseY);
	// �����͈̔͂��N���b�N
	if (m_mouseX >= m_pos.x && m_mouseX <= m_pos.x + m_size.x &&
		m_mouseY >= m_pos.y && m_mouseY <= m_pos.y + m_size.y &&
		(GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		// �����ꂽ�u��
		if (m_pushFlame == 0)
		{
			m_pushFlame = 1;
			return true;
		}
	}
	
	return false;
}