#include "SceneBase.h"
#include "DxLib.h"

// キーの入力状態
// 0:入力されていない　1:入力された瞬間　2:入力されている
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