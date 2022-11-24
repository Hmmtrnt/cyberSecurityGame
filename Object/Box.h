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
	void update();

	// クリックされたかどうか
	bool isTouchEnable(Vec2 pos);
	// 自身がクリックされたかどうか
	bool isTouch() const { return m_isTouch; }

	// 情報取得
	Vec2* getPos() const { return m_pos; }		// 座標
	Vec2* getSize() const { return m_size; }	// サイズ

protected:
	// ボックスの座標
	Vec2* m_pos;
	// ボックスのサイズ
	Vec2* m_size;
	// クリックされたかどうか
	bool m_isTouch;
};