#pragma once

// �L�[�{�[�h����̓��͏�Ԃ��擾����
namespace Keyboard
{
	// �L�[�{�[�h�̓��͏�Ԏ擾
	void update();
	// ������������
	bool isPress(int button);
	// �g���K�[����
	bool isTrigger(int button);
	// ����������
	bool isRelase(int button);
}