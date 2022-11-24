#pragma once

#include "Vec2.h"

class Box
{
public:
	Box();
	~Box();

	// ������
	void init();
	// �C��
	void end();
	// ����
	void update();

	// �N���b�N���ꂽ���ǂ���
	bool isTouchEnable(Vec2 pos);
	// ���g���N���b�N���ꂽ���ǂ���
	bool isTouch() const { return m_isTouch; }

	// ���擾
	Vec2* getPos() const { return m_pos; }		// ���W
	Vec2* getSize() const { return m_size; }	// �T�C�Y

protected:
	// �{�b�N�X�̍��W
	Vec2* m_pos;
	// �{�b�N�X�̃T�C�Y
	Vec2* m_size;
	
	// �}�E�X�̍��W
	int m_mouseX;
	int m_mouseY;
	// �}�E�X�̓��͏��
	int m_MouseInput;

	// �N���b�N���ꂽ���ǂ���
	bool m_isTouch;
};