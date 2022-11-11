#include "Mouse.h"
#include "DxLib.h"

//namespace
//{
//	constexpr int kLogNum = 16;
//	// ���̓��O	0���ŐV�̏��
//	int mouseLog[kLogNum];
//}
//
//namespace Mouse
//{
//	// �}�E�X�̓��͏�Ԏ擾
//	void update()
//	{
//		// ���O�̍X�V
//		for (int i = kLogNum - 1; i >= 1; i--)
//		{
//			mouseLog[i] = mouseLog[i - 1];
//		}
//		// �ŐV�̏��
//		if (GetMouseInput() & MOUSE_INPUT_LEFT)
//		{
//			mouseLog[0] = 1;
//		}
//		else
//		{
//			mouseLog[0] = 0;
//		}
//	}
//
//	// ���݂̃}�E�X�ʒu�擾
//	Vec2 getPos()
//	{
//		Vec2 mousePos{ 0,0 };
//		int mouseX = 0;
//		int mouseY = 0;
//		if (GetMousePoint(&mouseX, &mouseY) == -1)
//		{
//			// �G���[����
//			return mousePos;
//		}
//		mousePos.x = static_cast<float>(mouseX);
//		mousePos.y = static_cast<float>(mouseY);
//		return mousePos;
//	}
//
//	// ������������
//	bool isPressLeft()
//	{
//		return (mouseLog[0]);
//	}
//	// �g���K�[����
//	bool isTriggerLeft()
//	{
//		bool isNow = (mouseLog[0]);	// ���݂̏��
//		bool isLast = (mouseLog[1]);	// �P�t���[���O�̏��
//		return (isNow && !isLast);
//	}
//	// ����������
//	bool isRelaseLeft()
//	{
//		bool isNow = (mouseLog[0]);	// ���݂̏��
//		bool isLast = (mouseLog[1]);	// �P�t���[���O�̏��
//		return (!isNow && isLast);
//	}
//}

Mouse::Mouse() :
	m_button(0),
	m_clickX(0),
	m_clickY(0),
	m_logType(0),
	m_drawFlag(false),
	m_drawX(0),
	m_drawY(0),
	m_drawColor(0)
{

}

Mouse::~Mouse()
{

}

void Mouse::init()
{
	m_button = 0;
	m_clickX = 0;
	m_clickY = 0;
	m_logType = 0;
	m_drawFlag = false;
	m_drawX = 0;
	m_drawY = 0;
	m_drawColor = 0;
}

void Mouse::end()
{

}

void Mouse::update()
{
	// �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
	if (GetMouseInputLog2(&m_button, &m_clickX, &m_clickY, &m_logType, TRUE) == 0)
	{
		// ���{�^���������ꂽ�藣���ꂽ�肵�Ă�����`�悷�邩�ǂ����̃t���O�𗧂ĂāA���W���ۑ�����
		if ((m_button & MOUSE_INPUT_LEFT) != 0)
		{
			m_drawFlag = TRUE;
			m_drawX = m_clickX;
			m_drawY = m_clickY;

			// �l�p�`�̐F�������ꂽ�ꍇ�͔��ɁA�����ꂽ�ꍇ�͎��ɂ���
			m_drawColor = m_logType == MOUSE_INPUT_LOG_DOWN ? GetColor(255, 255, 255) : GetColor(255, 0, 255);
		}
	}
}

void Mouse::draw()
{
	// �`�悷�邩�ǂ����̃t���O�������Ă�����A�}�E�X�̍��{�^���������ꂽ�藣���ꂽ�肵�����W�ɏ������l�p�`��`�悷��
	if (m_drawFlag == TRUE)
	{
		DrawBox(m_drawX - 2, m_drawY - 2, m_drawX + 2, m_drawY + 2, m_drawColor, TRUE);
	}
}