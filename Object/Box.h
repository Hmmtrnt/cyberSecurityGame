#pragma once

#include "Vec2.h"

class Box
{
public:
	Box();
	~Box();

	// 初期化
	void init();
	// 修了
	void end();
	// 処理
	void update(int& pushNum);
	// 描画
	void draw();


	// クリックされたかどうか
	bool isTouchEnable();
	// 自身がクリックされたかどうか
	bool isTouch() const { return m_isTouch; }

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

	// クリックされたかどうか
	bool m_isTouch;

	// 押された瞬間のフレーム
	int m_pushFlame;
};