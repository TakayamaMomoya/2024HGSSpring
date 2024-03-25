//*****************************************************
//
// �v���C���[�Ԃ̏���[flowerPlayer.h]
// Author:���R����
//
//*****************************************************

#ifndef _FLOWERPLAYER_H_
#define _FLOWERPLAYER_H_

#include "ObjectX.h"

//*****************************************************
// �O���錾
//*****************************************************

//*****************************************************
// �N���X�̒�`
//*****************************************************
class CFlowerPlayer : public CObjectX
{
public:
	CFlowerPlayer(int nPriority = 3);	// �R���X�g���N�^
	~CFlowerPlayer();	// �f�X�g���N�^

	static CFlowerPlayer *Create(void);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	static int m_nNumAll;	// ����
};

#endif
