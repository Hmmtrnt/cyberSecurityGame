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
	// �`��
	void draw();

	// ���擾
	Vec2 getPos() const { return m_pos; }	// ���W
	Vec2 getVec() const { return m_vec; }	// �T�C�Y

protected:
	// �{�b�N�X�̍��W
	Vec2 m_pos;
	// �{�b�N�X�̃T�C�Y
	Vec2 m_vec;

};