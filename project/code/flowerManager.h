//*****************************************************
//
// �ԊǗ�[flowerManager.h]
// Author:���R����
//
//*****************************************************

#ifndef _FLOWERMANAGER_H_
#define _FLOWERMANAGER_H_

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "object.h"
#include <list>

//*****************************************************
// �O���錾
//*****************************************************
class CFlower;

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CFlowerManager : public CObject
{
public:
	CFlowerManager(int nPriority = 3);	// �R���X�g���N�^
	~CFlowerManager();	// �f�X�g���N�^

	static CFlowerManager *Create(void);
	static CFlowerManager *GetInstance(void) { return m_pFlowerManager; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	std::list<CFlower*> GetList(void) { return m_list; }

private:
	float m_fTimerFlower;	// �Ԑݒu�^�C�}�[

	std::list<CFlower*> m_list;	// �Ԃ̃��X�g
	static CFlowerManager *m_pFlowerManager;	// ���g�̃|�C���^
};

#endif

