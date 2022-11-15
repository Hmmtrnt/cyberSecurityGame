#pragma once

#include "Vec2.h"

class Mouse
{
public:
	Mouse();
	~Mouse();

	void init();
	void end();
	void update();
	void draw();

	int getPosX() const { return m_drawX - 2; }		// ���W
	int getPosY() const { return m_drawY - 2; }		// ���W
	int getSizeX() const { return m_drawX + 2; }	// �T�C�Y
	int getSizeY() const { return m_drawY + 2; }	// �T�C�Y

protected:
	// �����ꂽ�藣���ꑫ�肷��{�^���̒l
	int m_button;
	// �N���b�N�������W
//	int m_clickX;	// X
//	int m_clickY;	// Y
	// �{�^���������ꂽ�̂��܂��͗����ꂽ�̂��̏��擾
	int m_logType;
	// �`�悷�邩�ǂ���
	int m_drawFlag;
	// �`����W
//	int	m_drawX;	// X
//	int	m_drawY;	// Y
	// �`��F
	int m_drawColor;

	// �N���b�N�������W
	Vec2* m_click;
	// �`����W
	Vec2* m_draw;
};