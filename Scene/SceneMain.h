// ���C�����
#pragma once
#include "SceneBase.h"

class Box;
class Vec2;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ����������
	virtual void init();
	// �I������
	virtual void end();
	// �X�V����
	virtual SceneBase* update();
	// �`�揈��
	virtual void draw();

protected:
	// �n���h��
	int m_hBackGround;		// �w�i
	int m_fontHandle;		// �t�H���g
	// �t�F�[�h
	int m_fadeBright;		// ����
	int m_fadeSpeed;		// ���x
	// �c��̃v�b�V���o�����
	int m_pushNum;
	// �}�E�X�̍��W
	int m_mouseX;
	int m_mouseY;

	// �����ꂽ�u�Ԃ̃t���[��
	int m_pushFlame;

	// �����蔻��̃|�C���^
	Box* m_box;
};