#include "Mouse.h"
#include "DxLib.h"

Mouse::Mouse() :
	m_button(0),
	/*m_clickX(0),
	m_clickY(0),*/
	m_logType(0),
	m_drawFlag(false),
	/*m_drawX(0),
	m_drawY(0),*/
	m_drawColor(0),
	m_click(0),
	m_draw(0)
{
	m_click = new Vec2;
	m_draw = new Vec2;
}

Mouse::~Mouse()
{
	delete m_click;
	delete m_draw;
}

void Mouse::init()
{
	m_button = 0;
	/*m_clickX = 0;
	m_clickY = 0;*/
	m_logType = 0;
	m_drawFlag = false;
	/*m_drawX = 0;
	m_drawY = 0;*/
	m_drawColor = 0;
	m_click = 0;
	m_draw = 0;
}

void Mouse::end()
{

}

void Mouse::update()
{
	// �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
	if (GetMouseInputLog2(&m_button, &m_click.x, &m_click.y, &m_logType, TRUE) == 0)
	{
		// ���{�^���������ꂽ�藣���ꂽ�肵�Ă�����`�悷�邩�ǂ����̃t���O�𗧂ĂāA���W���ۑ�����
		if ((m_button & MOUSE_INPUT_LEFT) != 0)
		{
			m_drawFlag = TRUE;
			m_draw.x = m_click.x;
			m_draw.y = m_click,y;

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