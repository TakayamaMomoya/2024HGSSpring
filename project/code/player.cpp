//*****************************************************
//
// �v���C���[�̏���[player.cpp]
// Author:���R����
//
//*****************************************************

//*****************************************************
// �C���N���[�h
//*****************************************************
#include "main.h"
#include "player.h"
#include "collision.h"
#include "motion.h"
#include "inputManager.h"
#include "inputkeyboard.h"
#include "debugproc.h"
#include "universal.h"
#include "slow.h"
#include "camera.h"
#include "manager.h"
#include "effect3D.h"
#include "meshfield.h"
#include "cameraBehavior.h"
#include "particle.h"
#include "debrisSpawner.h"
#include "game.h"
#include "animEffect3D.h"
#include "anim3D.h"
#include "pause.h"
#include "inpact.h"
#include "sound.h"
#include "flowerPlayer.h"
#include "object3D.h"
#include "texture.h"
#include "flowerManager.h"
#include "flower.h"
#include "fan2D.h"

//*****************************************************
// �萔��`
//*****************************************************
namespace
{
const char* BODY_PATH = "data\\MOTION\\motionBeetle.txt";	// �����ڂ̃p�X
const float GRAVITY = 0.50f;	// �d��
const float SPEED_MOVE = 2.0f;	// �ړ����x
const float FACT_MOVE = 0.1f;	// �ړ��̌����W��
const float TIME_BLOOM = 0.6f;	// �ԍ玞��
const float TIME_ESCAPE = 2.0f;	// ���܂莞��
const float MAXTIME_SEED = 10.0f;	// ��܂��ő厞��
const float RADIUS_GAUGE = 100.0f;	// �Q�[�W���a
}

//*****************************************************
// �ÓI�����o�ϐ��錾
//*****************************************************
CPlayer *CPlayer::m_pPlayer = nullptr;	// ���g�̃|�C���^

//=====================================================
// �D�揇�ʂ����߂�R���X�g���N�^
//=====================================================
CPlayer::CPlayer(int nPriority)
{
	m_pPlayer = this;

	ZeroMemory(&m_info, sizeof(CPlayer::SInfo));
	ZeroMemory(&m_param, sizeof(CPlayer::SParam));
	ZeroMemory(&m_fragMotion, sizeof(CPlayer::SFragMotion));
}

//=====================================================
// �f�X�g���N�^
//=====================================================
CPlayer::~CPlayer()
{

}

//=====================================================
// ��������
//=====================================================
CPlayer *CPlayer::Create(void)
{
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = new CPlayer;

		if (m_pPlayer != nullptr)
		{
			m_pPlayer->Init();
		}
	}

	return m_pPlayer;
}

//=====================================================
// ����������
//=====================================================
HRESULT CPlayer::Init(void)
{
	// ���f���̐ݒ�
	CMotion::Load((char*)BODY_PATH);

	// �p���N���X�̏�����
	CMotion::Init();

	m_info.rotDest = D3DXVECTOR3(0.0f, 1.57f, 0.0f);
	SetRotation(D3DXVECTOR3(0.0f, -1.57f, 0.0f));

	// �����蔻��̐���
	if (m_info.pCollisionSphere == nullptr)
	{
		m_info.pCollisionSphere = CCollisionSphere::Create(CCollision::TAG_PLAYER, CCollision::TYPE_SPHERE, this);

		if (m_info.pCollisionSphere != nullptr)
		{
			m_info.pCollisionSphere->SetRadius(50.0f);
		}
	}

	if (m_info.pClsnAttack == nullptr)
	{// ���̓����蔻�萶��
		m_info.pClsnAttack = CCollisionSphere::Create(CCollision::TAG_NONE, CCollision::TYPE_SPHERE, this);

		if (m_info.pClsnAttack != nullptr)
		{// ���̐ݒ�
			m_info.pClsnAttack->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			m_info.pClsnAttack->SetRadius(0.0f);
		}
	}

	if (m_info.pCollisionCube == nullptr)
	{// �����蔻�萶��
		m_info.pCollisionCube = CCollisionCube::Create(CCollision::TAG_PLAYER, this);

		if (m_info.pCollisionCube != nullptr)
		{
			D3DXVECTOR3 vtxMax = { 20.0f,100.0f,20.0f };
			D3DXVECTOR3 vtxMin = { -20.0f,0.0f,-20.0f };

			m_info.pCollisionCube->SetPosition(GetPosition());

			m_info.pCollisionCube->SetVtx(vtxMax, vtxMin);
		}
	}

	if (m_info.pGauge == nullptr)
	{
		m_info.pGauge = CFan2D::Create(6);

		if (m_info.pGauge != nullptr)
		{
			D3DXVECTOR3 pos = SCRN_MID;
			pos.x -= 100.0f;
			m_info.pGauge->SetPosition(pos);
			m_info.pGauge->SetRadius(RADIUS_GAUGE);

			m_info.pGauge->SetRateAngle(0.0f);
			m_info.pGauge->SetVtx();
		}
	}

	// �p�����[�^�[�ɏ����l������
	m_param.fInitialLife = 300.0f;
	m_info.fLife = m_param.fInitialLife;
	m_param.fSpeedMove = SPEED_MOVE;
	m_info.state = STATE_NORMAL;
	m_info.bLand = true;

	SetMotion(MOTION_WALK_FRONT);

	// �J�����̍s���ݒ�
	Camera::ChangeBehavior(new CFollowPlayer);

	// �Ǎ�
	Load();

	EnableShadow(true);
	SetPosShadow(D3DXVECTOR3(0.0f, 1.0f, 0.0f));

	m_info.fLimitBloom = TIME_BLOOM;

	return S_OK;
}

//=====================================================
// �Ǎ�����
//=====================================================
void CPlayer::Load(void)
{
	char cTemp[256];
	int nThruster = 0;

	FILE *pFile = fopen("data\\TEXT\\playerParam.txt", "r");

	if (pFile != nullptr)
	{
		while (true)
		{
			// �����œǂݍ��񂾕����ɂ���ĉ��L��IF�ɂ�����
			(void)fscanf(pFile, "%s", &cTemp[0]);

			if (strcmp(cTemp, "END_SCRIPT") == 0)
			{
				break;
			}
		}

		fclose(pFile);
	}
}

//=====================================================
// �I������
//=====================================================
void CPlayer::Uninit(void)
{
	m_pPlayer = nullptr;

	Object::DeleteObject((CObject**)&m_info.pCollisionSphere);
	Object::DeleteObject((CObject**)&m_info.pCollisionCube);
	Object::DeleteObject((CObject**)&m_info.pClsnAttack);

	// �p���N���X�̏I��
	CMotion::Uninit();
}

//=====================================================
// �X�V����
//=====================================================
void CPlayer::Update(void)
{
	CSlow *pSlow = CSlow::GetInstance();

	if (m_info.state != CPlayer::STATE::STATE_DEATH)
	{
		// ����
		Input();

		// �v���C���[�̉�]
		Rotation();
	}

	// �ʒu�̔��f
	D3DXVECTOR3 pos = GetPosition();
	D3DXVECTOR3 move = GetMove();
	
	// �O��̈ʒu��ۑ�
	SetPositionOld(pos);

	pos += move;
	SetPosition(pos);

	move.x += (0 - move.x) * FACT_MOVE;
	move.z += (0 - move.z) * FACT_MOVE;

	SetMove(move);

	// �펞�ԊǗ�
	ManageTimeSeed();

	// �����蔻��̊Ǘ�
	ManageCollision();

	// ��ԊǗ�
	ManageState();

	// ���[�V�����Ǘ�
	ManageMotion();

	// �p���N���X�̍X�V
	CMotion::Update();

	if (m_info.pGauge != nullptr)
	{
		// �傫������
		float fRadius = m_info.pGauge->GetRadius();

		fRadius += (RADIUS_GAUGE - fRadius) * 0.1f;

		m_info.pGauge->SetRadius(fRadius);

		// �����v�Z
		float fRate = m_info.fTimerSeed / MAXTIME_SEED;

		m_info.pGauge->SetRateAngle(fRate);
		m_info.pGauge->SetVtx();
	}

// �f�o�b�O����
#if _DEBUG
	Debug();
#endif // _DEBUG
}

//=====================================================
// ���͏���
//=====================================================
void CPlayer::Input(void)
{
	int nMotion = GetMotion();

	if (CGame::GetState() != CGame::STATE_NORMAL || nMotion == MOTION_CATCH)
		return;

	// �ړ�����
	InputMove();

	// �J��������
	InputCamera();

	// �U������
	InputAttack();

	if (CManager::GetMode() == CScene::MODE_GAME)
	{
		CInputManager *pInputManager = CInputManager::GetInstance();

		if (pInputManager != nullptr)
		{
			if (pInputManager->GetTrigger(CInputManager::BUTTON_PAUSE))
			{
				CPause::Create();
			}
		}
	}
}

//=====================================================
// �ړ��̓���
//=====================================================
void CPlayer::InputMove(void)
{
	CSlow *pSlow = CSlow::GetInstance();
	CInputManager *pInputManager = CInputManager::GetInstance();

	if (pInputManager == nullptr)
	{
		return;
	}

	// �J�����擾
	CCamera *pCamera = CManager::GetCamera();

	if (pCamera == nullptr)
	{
		return;
	}

	CCamera::Camera *pInfoCamera = pCamera->GetCamera();

	// �ڕW�����̐ݒ�
	CInputManager::SAxis axis = pInputManager->GetAxis();
	D3DXVECTOR3 axisMove = axis.axisMove;

	float fLengthAxis = D3DXVec3Length(&axisMove);

	int nMotion = GetMotion();

	if (fLengthAxis >= 0.3f)
	{// �ʏ�ړ����̖ڕW�����ݒ�
		m_info.rotDest.y = atan2f(axisMove.x, axisMove.z);

		CDebugProc *pDebugProc = CDebugProc::GetInstance();

		pDebugProc->Print("\n�ʏ�ړ�");
	}

	D3DXVECTOR3 vecMove = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 rot = GetRotation();

	fLengthAxis *= SPEED_MOVE;

	vecMove -= {sinf(rot.y) * fLengthAxis, 0.0f, cosf(rot.y) * fLengthAxis};

	// �ړ����x�̐ݒ�
	D3DXVECTOR3 move = GetMove();

	D3DXVec3Normalize(&vecMove, &vecMove);
	vecMove *= m_param.fSpeedMove;

	if (pSlow != nullptr)
	{
		float fScale = pSlow->GetScale();

		vecMove *= fScale;
	}

	float fAngleInput = atan2f(axisMove.x, axisMove.z);

	move += vecMove;

	SetMove(move);

#ifdef _DEBUG
	CInputKeyboard *pKeyboard = CInputKeyboard::GetInstance();

	if (pKeyboard != nullptr)
	{
		if (pKeyboard->GetTrigger(DIK_RETURN))
		{// �X���[�ɂ���
			if (pSlow != nullptr)
			{
				pSlow->SetScale(0.25f);
			}
		}

		if (pKeyboard->GetRelease(DIK_RETURN))
		{// �X���[����
			CSlow *pSlow = CSlow::GetInstance();

			if (pSlow != nullptr)
			{
				pSlow->SetScale(1.0f);
			}
		}

		if (pKeyboard->GetTrigger(DIK_O))
		{// ���p�[�c���Z�b�g
			ResetEnableMotion();
		}
	}
#endif
}

//=====================================================
// �J��������
//=====================================================
void CPlayer::InputCamera(void)
{
	// ���̓}�l�[�W���[�擾
	CInputManager *pInputManager = CInputManager::GetInstance();

	if (pInputManager == nullptr)
	{
		return;
	}

	// �J�����擾
	CCamera *pCamera = CManager::GetCamera();

	if (pCamera == nullptr)
	{
		return;
	}

	CCamera::Camera *pInfoCamera = pCamera->GetCamera();
}

//=====================================================
// �U���̓���
//=====================================================
void CPlayer::InputAttack(void)
{
	CInputManager *pInputManager = CInputManager::GetInstance();
	int nMotion = GetMotion();

	if (pInputManager == nullptr)
	{
		return;
	}
}

//=====================================================
// �펞�ԊǗ�
//=====================================================
void CPlayer::ManageTimeSeed(void)
{
	if (m_info.fTimerSeed <= 0.0f)
	{// �펞�Ԑ؂�

	}
	else
	{// ��c���Ă�ꍇ
		float fDeltaTime = CManager::GetDeltaTime();

		// �Ԃ��炩����
		m_info.fTimerBloom += fDeltaTime;

		if (m_info.fTimerBloom >= m_info.fLimitBloom)
		{
			CFlowerPlayer *pFlower = CFlowerPlayer::Create();

			if (pFlower != nullptr)
			{
				D3DXVECTOR3 pos = GetPosition();

				pos.z += universal::RandRange(500, -500);
				pos.x += universal::RandRange(500, -500);

				pFlower->SetPosition(pos);
			}

			m_info.fTimerBloom = 0.0f;
		}

		// ���Ԃ̌���
		m_info.fTimerSeed -= fDeltaTime;

		if (m_info.fTimerSeed <= 0.0f)
		{
			m_info.fTimerSeed = 0.0f;
		}
	}
}

//=====================================================
// �v���C���[�̉�]
//=====================================================
void CPlayer::Rotation(void)
{
	// �ړ������̎擾
	D3DXVECTOR3 move = GetMove();

	float fAngleMove = atan2f(-move.x, -move.z);
	float fLenghtMove = sqrtf(move.x * move.x + move.z * move.z);

	int nMotion = GetMotion();

	if (fLenghtMove >= 6.0f)
	{
		// �����̕␳
		D3DXVECTOR3 rot = GetRotation();

		SetRotation(rot);

		if (m_info.bLand)
		{
			m_fragMotion.bMove = true;
		}
	}
	else
	{
		m_fragMotion.bMove = false;
	}

	m_info.rotDest.x = 0.0f;

	// �����̕␳
	D3DXVECTOR3 rot = GetRotation();

	float fFact = 0.1f;

	universal::FactingRot(&rot.y, m_info.rotDest.y + D3DX_PI, fFact);
	universal::FactingRot(&rot.x, m_info.rotDest.x, fFact);

	SetRotation(rot);
}

//=====================================================
// ��ԊǗ�
//=====================================================
void CPlayer::ManageState(void)
{
	switch (m_info.state)
	{
	case STATE_NORMAL:
	{// �ʏ���

	}
		break;
	case STATE_DAMAGE:
	{// �_���[�W���

	}
		break;
	case STATE_DEATH:
	{// ���S���

	}
		break;
	default:
		break;
	}
}

//=====================================================
// �����蔻��Ǘ�
//=====================================================
void CPlayer::ManageCollision(void)
{
	// �����蔻��̒Ǐ]
	if (m_info.pCollisionSphere != nullptr)
	{
		int nMotion = GetMotion();

		D3DXVECTOR3 pos = GetPosition();
		D3DXVECTOR3 posWaist = GetMtxPos(0);
		D3DXVECTOR3 move = GetMove();

		m_info.pCollisionSphere->SetPositionOld(m_info.pCollisionSphere->GetPosition());
		m_info.pCollisionSphere->SetPosition(pos);

		if (m_info.pCollisionSphere->IsTriggerEnter(CCollision::TAG_FLOWER))
		{// �ԂƂ̔���
			CObject *pObj = nullptr;

			pObj = m_info.pCollisionSphere->GetOther();

			if (pObj != nullptr)
			{
				pObj->Hit(1.0f);
			}

			AddLimitBloom(-0.05f);

			if (m_info.pGauge != nullptr)
			{
				m_info.pGauge->SetRadius(RADIUS_GAUGE * 1.3f);
			}

			// �����Ńp�[�e�B�N��
			CParticle::Create(pos, CParticle::TYPE::TYPE_EXPLOSION);
		}

		if (m_info.pCollisionCube != nullptr)
		{
			pos = GetPosition();
			D3DXVECTOR3 posCollision = m_info.pCollisionCube->GetPosition();

			// ����̒Ǐ]
			m_info.pCollisionCube->SetPositionOld(posCollision);
			m_info.pCollisionCube->SetPosition(pos);

			// ���b�V���t�B�[���h�Ƃ̓����蔻��
			pos = GetPosition();
			D3DXVECTOR3 posOld = GetPositionOld();

			CMeshField *pMesh = CMeshField::GetInstance();

			if (pMesh != nullptr)
			{
				float fHeight = pMesh->GetHeight(pos,&move);

				if (pos.y <= fHeight)
				{
					pos.y = fHeight;
					move.y = 0.0f;

					SetPosition(pos);
				}
			}

			SetMove(move);
		}

		SetPosition(pos);
	}
}

//=====================================================
// ���[�V�����Ǘ�
//=====================================================
void CPlayer::ManageMotion(void)
{
	int nMotion = GetMotion();
	bool bFinish = IsFinish();

	if (m_fragMotion.bCatch)
	{
		if (nMotion != MOTION_CATCH)
		{
			SetMotion(MOTION_CATCH);
		}

		m_info.fTimerCatch += CManager::GetDeltaTime();

		if (TIME_ESCAPE < m_info.fTimerCatch)
		{
			m_info.fTimerCatch = 0.0f;

			m_fragMotion.bCatch = false;
		}
	}
	else if (m_fragMotion.bMove)
	{// �������[�V����
		if (nMotion != MOTION_WALK_FRONT)
		{
			SetMotion(MOTION_WALK_FRONT);
		}
	}
	else
	{// �ҋ@���[�V����
		if (nMotion != MOTION_NEUTRAL)
		{
			SetMotion(MOTION_NEUTRAL);
		}
	}
}

//=====================================================
// �O���Ɉړ��ʂ�������
//=====================================================
void CPlayer::AddMoveForward(float fSpeed)
{
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 vecMove = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 rot = GetRotation();

	vecMove =
	{
		sinf(rot.x - D3DX_PI * 0.5f) * sinf(rot.y) * fSpeed,
		cosf(rot.x - D3DX_PI * 0.5f) * fSpeed,
		sinf(rot.x - D3DX_PI * 0.5f) * cosf(rot.y) * fSpeed
	};

	move += vecMove;

	SetMove(move);
}

//=====================================================
// ��Ɉړ��ʂ�������
//=====================================================
void CPlayer::AddMoveUp(float fSpeed)
{
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR3 vecMove = { 0.0f,0.0f,0.0f };

	vecMove.y += fSpeed;

	move += vecMove;

	SetMove(move);
}

//=====================================================
// �C�x���g�̊Ǘ�
//=====================================================
void CPlayer::Event(EVENT_INFO *pEventInfo)
{
	int nMotion = GetMotion();

	D3DXVECTOR3 offset = pEventInfo->offset;
	D3DXMATRIX mtxParent;
	D3DXMATRIX mtxPart = *GetParts(pEventInfo->nIdxParent)->pParts->GetMatrix();

	universal::SetOffSet(&mtxParent, mtxPart, offset);

	D3DXVECTOR3 pos = { mtxParent._41,mtxParent._42 ,mtxParent._43 };

}

//=====================================================
// �`�揈��
//=====================================================
void CPlayer::Draw(void)
{
	// �p���N���X�̕`��
	CMotion::Draw();

	// �f�o�b�O�\��
	Debug();
}

//=====================================================
// �q�b�g����
//=====================================================
void CPlayer::Hit(float fDamage)
{
	m_fragMotion.bCatch = true;
}

//=====================================================
// ���S����
//=====================================================
void CPlayer::Death(void)
{
	CSound *pSound = CSound::GetInstance();

	if (pSound != nullptr)
	{
		pSound->Stop(CSound::LABEL_SE_WARNING00);
	}

	Sound::Play(CSound::LABEL_SE_EXPLOSION01);

	D3DXVECTOR3 pos = GetMtxPos(0);

	// �G�t�F�N�g����
	CAnimEffect3D *pAnimManager = CAnimEffect3D::GetInstance();

	if (pAnimManager != nullptr)
	{
		CAnim3D *pAnim = pAnimManager->CreateEffect(pos, CAnimEffect3D::TYPE_EXPLOSION);

		if (pAnim != nullptr)
		{
			pAnim->SetSize(600.0f, 600.0f);
		}
	}

	// �j�А���
	CDebrisSpawner::Create(pos, CDebrisSpawner::TYPE::TYPE_DEATH);
	
	Uninit();
}

//=====================================================
// �f�o�b�O�\��
//=====================================================
void CPlayer::Debug(void)
{
#ifndef _DEBUG

	return;

#endif

	CDebugProc *pDebugProc = CDebugProc::GetInstance();

	if (pDebugProc == nullptr)
	{
		return;
	}

	pDebugProc->Print("\n�v���C���[�̈ʒu[%f,%f,%f]", GetPosition().x, GetPosition().y, GetPosition().z);
	pDebugProc->Print("\n�v���C���[�̈ړ���[%f,%f,%f]", GetMove().x, GetMove().y, GetMove().z);
	pDebugProc->Print("\n�펞��[%f]", m_info.fTimerSeed);
	for (int i = 0; i < PARAM_MAX; i++)

	int nMotion = GetMotion();

	pDebugProc->Print("\n���n[%d]", m_info.bLand);

	CInputKeyboard *pKey = CInputKeyboard::GetInstance();

	if (pKey != nullptr)
	{
		if (pKey->GetTrigger(DIK_O))
		{
			m_info.fLife = 1.0f;
		}
	}
}