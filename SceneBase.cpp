#include "SceneBase.h"
#include "DxLib.h"

SceneBase::SceneBase() :
    m_key()
{
}

void SceneBase::inputKey()
{
    static char buf[256];
    GetHitKeyStateAll(buf);
    for (int i = 0; i < 256; i++) {
        if (buf[i]) {
            if (m_key[i] == 0) m_key[i] = 1;
            else if (m_key[i] == 1) m_key[i] = 2;
        }
        else m_key[i] = 0;
    }
}