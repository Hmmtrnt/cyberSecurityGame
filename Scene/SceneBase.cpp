#include "SceneBase.h"
#include "DxLib.h"

// �L�[�̓��͏��
// 0:���͂���Ă��Ȃ��@1:���͂��ꂽ�u�ԁ@2:���͂���Ă���
void SceneBase::inputKey(int key[256])
{
    static char buf[256];
    GetHitKeyStateAll(buf);
    for (int i = 0; i < 256; i++) {
        if (buf[i]) {
            if (key[i] == 0) key[i] = 1;
            else if (key[i] == 1) key[i] = 2;
        }
        else key[i] = 0;
    }
}