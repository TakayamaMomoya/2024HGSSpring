//*****************************************************
//
// �ԊǗ�[netManager.h]
// Author:���R����
//
//*****************************************************

#ifndef _NETMANAGER_H_
#define _NETMANAGER_H_

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "object.h"
#include <list>

//*****************************************************
// �O���錾
//*****************************************************
class CNet;

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CNetManager : public CObject
{
public:
	CNetManager(int nPriority = 3);	// �R���X�g���N�^
	~CNetManager();	// �f�X�g���N�^

	static CNetManager *Create(void);
	static CNetManager *GetInstance(void) { return m_pNetManager; }
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	std::list<CNet*> GetList(void) { return m_list; }
	void PushBack(CNet *pNet) { m_list.push_back(pNet); }
	void Remove(CNet *pNet) { m_list.remove(pNet); }

private:
	float m_fTimerNet;	// �Ԑݒu�^�C�}�[

	std::list<CNet*> m_list;	// �Ԃ̃��X�g
	static CNetManager *m_pNetManager;	// ���g�̃|�C���^
};

#endif

