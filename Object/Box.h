#pragma once

#include "Vec2.h"
#include "Mouse.h"

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

	//bool CheckHit(Vec2* pos, Vec2* size, int mousePosX, int mousePosY, int mouseSizeX, int mouseSizeY);

	// ���擾
	Vec2* getPos() const { return m_pos; }		// ���W
	Vec2* getSize() const { return m_size; }	// �T�C�Y

protected:
	// �{�b�N�X�̍��W
	Vec2* m_pos;
	// �{�b�N�X�̃T�C�Y
	Vec2* m_size;
	// �N���b�N�����Ƃ��̔���
	Mouse* m_mouse;
};