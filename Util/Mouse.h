// マウスの状態
#pragma once

#include "Vec2.h"

// マウスの入力状態を取得する
namespace Mouse
{
	void update();			// マウスの状態取得

	Vec2 getPos();			// 現在のマウス位置取得

	bool isPressLeft();		// 押し下げ判定
	bool isTriggerLeft();	// トリガー判定
	bool isRelaseLeft();	// 離した判定
}