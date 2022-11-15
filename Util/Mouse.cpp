#include "Mouse.h"
#include "DxLib.h"

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

void Mouse::update(int& pushNum)
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
			// ��������
			if (m_logType == MOUSE_INPUT_LOG_DOWN)
			{
				pushNum--;
			}
			
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
		DrawBox(getPosX(), getPosY(), getSizeX(), getSizeY(), m_drawColor, TRUE);
	}
}