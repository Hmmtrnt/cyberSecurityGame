// �}�E�X�̏��
#pragma once

#include "Vec2.h"

// �}�E�X�̓��͏�Ԃ��擾����
namespace Mouse
{
	void update();			// �}�E�X�̏�Ԏ擾

	Vec2 getPos();			// ���݂̃}�E�X�ʒu�擾

	bool isPressLeft();		// ������������
	bool isTriggerLeft();	// �g���K�[����
	bool isRelaseLeft();	// ����������
}