#pragma once

#include "Vec2.h"

class Box
{
public:
	Box();
	~Box();

	// 初期化処理
	void init();
	// 更新処理
	void update(int& pushNum, int& fadeBright);

	// 答えとなる範囲をクリックしたかどうか
	bool isTouchEnable();

	// 情報取得
	Vec2 getPos() const { return m_pos; }		// 座標
	Vec2 getSize() const { return m_size; }	// サイズ

protected:
	// ボックスの座標
	Vec2 m_pos;
	// ボックスのサイズ
	Vec2 m_size;
	
	// マウスの座標
	int m_mouseX;
	int m_mouseY;
	// 押された瞬間のフレーム
	int m_pushFlame;

	// クリックされたかどうか
	bool m_isTouch;
};