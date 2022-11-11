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
	// �\���ʒu�̐ݒ�
	void setPos(Vec2 pos) { m_pos = pos; }

	// ���������ǂ���
	bool isPushEnable(Vec2 pos);

protected:
	// �{�b�N�X�̍��W
	Vec2 m_pos;

};