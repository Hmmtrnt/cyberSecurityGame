#include "Mouse.h"
#include "DxLib.h"
#include "SceneBase.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneExplanation.h"
#include "SceneResult.h"
#include "SceneFail.h"

Mouse::Mouse() :
	m_button(0),
	m_clickX(0),
	m_clickY(0),
	m_logType(0),
	m_drawFlag(false),
	m_drawX(0),
	m_drawY(0),
	m_drawColor(0),
	sceneManager(nullptr)
{
	sceneManager = new SceneManager;
}

Mouse::~Mouse()
{
	delete sceneManager;
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
	m_button = 0;
	m_logType = 0;
}

void Mouse::update(int& pushNum)
{
	//if (sceneManager->m_pScene != new SceneMain) return;

	// �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
	if (GetMouseInputLog2(&m_button, &m_clickX, &m_clickY, &m_logType, TRUE) == 0)
	{
		// ���{�^���������ꂽ�藣���ꂽ�肵�Ă����珈�����邩�ǂ����̃t���O�𗧂ĂāA���W���ۑ�����
		if ((m_button & MOUSE_INPUT_LEFT) != 0)
		{
			
			
			// ��������
			if (m_logType == MOUSE_INPUT_LOG_DOWN)
			{
				pushNum--;
				if (pushNum <= 0)
				{
					pushNum = 0;
				}
				m_drawX = m_clickX;
				m_drawY = m_clickY;
			}
			else if (m_logType == MOUSE_INPUT_LOG_UP)
			{
				return;
			}
		}
	}
}

void Mouse::reset(int pushNum)
{
	if (pushNum <= 3)
	{
		pushNum = 3;
	}
}