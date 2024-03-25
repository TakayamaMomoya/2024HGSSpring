//*****************************************************
//
// 花管理[flowerManager.h]
// Author:髙山桃也
//
//*****************************************************

#ifndef _FLOWERMANAGER_H_
#define _FLOWERMANAGER_H_

//*****************************************************
// インクルード
//*****************************************************
#include "object.h"
#include <list>

//*****************************************************
// 前方宣言
//*****************************************************
class CFlower;

//*****************************************************
// クラスの定義
//*****************************************************
class CFlowerManager : public CObject
{
public:
	CFlowerManager(int nPriority = 3);	// コンストラクタ
	~CFlowerManager();	// デストラクタ

	static CFlowerManager *Create(void);
	static CFlowerManager *GetInstance(void) { return m_pFlowerManager; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	std::list<CFlower*> GetList(void) { return m_list; }

private:
	float m_fTimerFlower;	// 花設置タイマー

	std::list<CFlower*> m_list;	// 花のリスト
	static CFlowerManager *m_pFlowerManager;	// 自身のポインタ
};

#endif

