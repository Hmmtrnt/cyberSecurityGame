// シーンマネージャー
#pragma once
#include "SceneBase.h"

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

	// 初期化処理
	void init();
	// 終了処理
	void end();
	// 更新処理
	void update();
	// 描画処理
	void draw();

	// 基底クラスのポインタ
	SceneBase* m_pScene;
};