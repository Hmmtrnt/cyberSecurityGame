#pragma once

#include "Vec2.h"

class Box
{
public:
	Box();
	~Box();

	// ����������
	void init();
	// �X�V����
	void update(int& pushNum, int& fadeBright);

	// �����ƂȂ�͈͂��N���b�N�������ǂ���
	bool isTouchEnable();

	// ���擾
	Vec2 getPos() const { return m_pos; }		// ���W
	Vec2 getSize() const { return m_size; }	// �T�C�Y

protected:
	// �{�b�N�X�̍��W
	Vec2 m_pos;
	// �{�b�N�X�̃T�C�Y
	Vec2 m_size;
	
	// �}�E�X�̍��W
	int m_mouseX;
	int m_mouseY;
	// �����ꂽ�u�Ԃ̃t���[��
	int m_pushFlame;

	// �N���b�N���ꂽ���ǂ���
	bool m_isTouch;
};