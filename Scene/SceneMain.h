// メイン画面
#pragma once
#include "SceneBase.h"

class Box;
class Vec2;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化処理
	virtual void init();
	// 終了処理
	virtual void end();
	// 更新処理
	virtual SceneBase* update();
	// 描画処理
	virtual void draw();

protected:
	// ハンドル
	int m_hBackGround;		// 背景
	int m_fontHandle;		// フォント
	// フェード
	int m_fadeBright;		// 処理
	int m_fadeSpeed;		// 速度
	// 残りのプッシュ出来る回数
	int m_pushNum;
	// マウスの座標
	int m_mouseX;
	int m_mouseY;

	// 押された瞬間のフレーム
	int m_pushFlame;

	// 当たり判定のポインタ
	Box* m_box;
};