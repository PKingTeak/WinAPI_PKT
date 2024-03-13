#include "Ball.h"
#include <EngineCore/EngineResourcesManager.h>
#include "User.h"
#include <EnginePlatform/EngineInput.h>
#include <vector>
#include"Block.h"
#include <EngineCore/EngineDebug.h>
#include<EnginePlatform/EngineSound.h>
Ball* Ball::MainBall = nullptr;

Ball::Ball()
{

}
Ball::~Ball()
{}




void Ball::BeginPlay()
{

	MainBall = this;
	AActor::BeginPlay();
	BallRender = CreateImageRenderer(0);
	UEngineResourcesManager::GetInst().CuttingImage("Ball.png", 1, 1);
	BallRender->SetImage("Ball.png");
	BallRender->SetScale(BallSize);
	GetUserScale();
	SetActorLocation({ User::CurPos.X,User::CurPos.Y -10});

	BallCollison = CreateCollision(ColliderOrder::Ball);
	BallCollison->SetColType(ECollisionType::CirCle);
	BallCollison->SetScale({ BallSize });
	this->SetActive(true, 1.0f);


}
void Ball::SetPos(FVector _CurPos)
{

	CurBallPos = _CurPos;

}
void Ball::GetUserScale()
{
	FVector UScale = { User::CurPos.hX() , User::CurPos.hY() };

}



void Ball::Tick(float _DeltaTime)
{
	
	if (abs(BDir.Y) <= 0.3f)
	{
		if (0 < BDir.Y)
		{
			BDir.Y = 0.3f;
		}
		else {
			BDir.Y = -0.3f;
		}
		BDir.Normalize2D();
		//�̷����̸� ���ڷ� ƨ��� ���� ��������.
	}

	float time = 1 / _DeltaTime;
	std::string stime = std::to_string(time);
	UEngineDebug::DebugTextPrint(stime, 24);



	if (false == IsballLive)
	{
		SetActorLocation({ User::CurPos.X,User::CurPos.Y -10 });
	}

	if (UEngineInput::IsDown('R'))
	{
		Reset();
	}

	

	AActor::Tick(_DeltaTime);
	GameStartCheck();
	WallCheck();
	BlockCheck();
	Move(_DeltaTime);
	// �� �̷��� ��ġ�� üũ�ϴ� ��
	// �浹�ϰ� ���� üũ�ϴ¹�



}

Ball* Ball::GetMainBall()
{
	return MainBall;
}


void Ball::SetSpeed(float _Speed)
{
	Speed = _Speed;

}


UCollision* Ball::GetCollision()
{
	return BallCollison;

}



void Ball::GameStartCheck()
{
	if (true == IsballLive)
	{
		return;
	}

	if (true == UEngineInput::IsDown('A'))
	{
		BDir = FVector(-1.0f, 0.0f);
		BDir.Normalize2D();
	}
	else if (true == UEngineInput::IsDown('D'))
	{
		BDir = FVector(1.0f, -1.0f);
		BDir.Normalize2D();
	}
	else if (true == UEngineInput::IsDown('W'))
	{
		BDir = FVector(0.0f, -1.0f);
		BDir.Normalize2D();
	}
	else if (true == UEngineInput::IsDown('S'))
	{
		BDir = FVector(0.0f, 1.0f);
		BDir.Normalize2D();
	}

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		IsballLive = true;
	}



}



void Ball::Move(float _DeltaTime)
{
	Item* CurItem = Item::GetMainItem();
	BDir.Normalize2D();
	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.

}

void Ball::WallCheck()
{
	// R = P + 2n(-P��n);
	FVector N = FVector::Zero;
	CurBallPos = GetTransform().GetPosition();
	bool PlayerDead = false;

	if (CurBallPos.X > 524)
	{
		N = { -1,0 };
		BallAdjustwithWall(524.0f, true);
		CurBallPos.X = 524;

	}
	else if (CurBallPos.X <= 30)
	{
		N = { 1,0 };
		BallAdjustwithWall(30.0f, true);
		CurBallPos.X = 30;

	}
	else if (CurBallPos.Y <= 80)
	{
		N = { 0,1 };
		BallAdjustwithWall(80, false);
		CurBallPos.Y = 80;

	}


	else if (CurBallPos.Y >= 530 && CurBallPos.Y < 540)
	{

		PlayerPos();
		//	CurBallPos.Y += 530-CurBallPos.Y;
	}
	else if (CurBallPos.Y >= 650 && CurBallPos.Y <= 750)
	{


		User* user = User::GetMainUser();
		user->User::PlayerDie(user);
		IsballLive = false;
		//GameStartCheck();



	}


	if (false == N.IsZeroVector2D())
	{
		Reflect(N);

	}
}
void Ball::PlayerPos()
{
	float ULeft = User::CurPos.X - 30;
	float URight = User::CurPos.X + 30;
	

	if (CurBallPos.X >= ULeft && CurBallPos.X <= URight)
	{
		if (User::CurPos.Y + 2 > CurBallPos.Y) // �÷��̾� �ϴ� ����
		{
			Reflect({ 0.0f, -1.0f });
			FVector Pos = GetTransform().GetPosition() - User::CurPos;
			Pos.X /= User::UserScale.hX(); //���� x���� ������ �������� �ε�ģ ���� ������ 
			BDir.X += Pos.X;
			BDir.Normalize2D();
			UEngineSound::SoundPlay("BallCrashPlayer.wav");
			CurBallPos.Y = User::CurPos.Y;
		}



	}


}
void Ball::Reset()
{

	IsballLive = false;
	CurBallPos = User::CurPos;
	GameStartCheck();
}

void Ball::BlockCheck()
{
	int Blocklife = 0;
	float checkY = CurBallPos.Y;
	std::vector<UCollision*> Result;

	if (true == BallCollison->CollisionCheck(ColliderOrder::Block, Result))
	{

		
		UCollision* Collider = Result[0/*���°�϶�*/];
		AActor* ColAct = Collider->GetOwner();
		Block* ColBlock = dynamic_cast<Block*>(ColAct);
		BlockRatio(ColBlock);
		Blocklife = ColBlock->GetLife();
		BlockType Type = ColBlock->GetBlockType(ColBlock);

		if (Blocklife > 0)
		{
			ColBlock->LifeDecrease();
			if (Type == BlockType::Hard)
			{
				UEngineSound::SoundPlay("Blockprotected.wav");
				ColBlock->BlockAniReset(ColBlock);
				ColBlock->HardBlockAnimation(ColBlock);
				return;

			}
		}

		else
		{
			ColBlock->Destroy();
		}
		UEngineSound::SoundPlay("BlockCrashBall.wav");


	}

}

void Ball::Reflect(FVector Normal)
{
	FVector N = Normal;
	FVector N2 = N * 2;

	float X = BDir.X * -1;
	float Y = BDir.Y * -1;//0.7
	float T = X * N.X + Y * N.Y; //(-P * n) <���Ⱑ �̻��ϴ�.
	BDir.Normalize2D();
	BDir = BDir + (N2 * T); //R = P+2n(-P����n)

}


void Ball::BlockRatio(Block* _NewBlock)
{
	FVector N = { BDir.X,BDir.Y };

	FTransform Transform = { _NewBlock->GetBlockPos(), _NewBlock->GetBlockScale() };

	bool R = BlockSideCheckLR(_NewBlock);
	bool D = BlockSideCheckUD(_NewBlock);


	if (false == R && false == D)
	{
		if (true == MidTopHeight)
		{
			MidTopHeight = false;

			Reflect({ -1.0f, 0.0f });



		}
		else if (false == MidTopHeight)
		{
			float CheckX = CurBallPos.X;
			float CheckXB = BDir.X;
			Reflect({ 0.0f, -1.0f });



		}
		else if (true == MidHeight)
		{

			Reflect({ -1.0f,0.0f });

		}
		else if (false == MidHeight)
		{
			Reflect({ 0.0f,1.0f });
		}




	}
	if (true == R && true == D)
	{
		float CheckX = BDir.X;
		float CheckY = BDir.Y;
		if (true == MidHeight)
		{
			MidHeight = false;
			//Reflect({ 0.0f,1.0f });
			Reflect({ 1.0f,0.0f });
			return;

		}

		else if (false == MidHeight && false == isBottom)
		{

			Reflect({ 0.0f,1.0f });
			//���� ���ǹ� �߰�
		}
		if (false == MidHeight && true == isBottom)
		{
			Reflect({ 0.0f,1.0f });
			return;
		}
		//������ �Ʒ�
	}

	if (true == R && false == D)
	{
		if (true == MidTopHeight)
		{
			MidHeight = false;
			Reflect({ 1.0f,0.0f });
			//���⵵ �̻���

		}
		else
		{
			Reflect({ 0.0f,-1.0f });
		}
		//������ ��


	}
	if (false == R && true == D)
	{
		float CheckX = BDir.X;
		float CheckY = BDir.Y;

		if (true == MidHeight)
		{
			MidHeight = false;
			Reflect({ -1.0f,0.0f });

		}
		else if (false == MidHeight)
		{
			Reflect({ 0.0f,1.0f });
			//Reflect({ -1.0f,0.0f });
		}
		else
		{

			//����
		}
		// ���⼭ ���� y�� -�� �پ ���;� �ϴµ� ���� ����� ���´�. �׷��� ������ ������ ������ ���� �̻��ϴ�
	   // X���� �߳���
	   //���� �Ʒ�
	}


}
bool Ball::BlockSideCheckLR(Block* _ColBlock)
{

	bool isRight = false;

	Block* thisBlock = _ColBlock;
	float BlockLeft = thisBlock->GetActorLocation().X - 44;
	float BlockRight = thisBlock->GetActorLocation().X + 44;

	//���� 1�� ������ ������ float �� ������ ���ֱ� ���ؼ� ��������ϴ�. 

	float XMid = thisBlock->GetActorLocation().X;



	if (BlockLeft <= CurBallPos.X && CurBallPos.X < XMid)
	{

		isRight = false;

		//���� 
		//���� ���������� �ϴ� ���� Ȯ���ϰ� ���Ʒ� ���� �����Ҷ� boolŸ������ Ȯ���ϰ� �״��� ����� ����
	}

	if (XMid <= CurBallPos.X && CurBallPos.X <= BlockRight)
	{
		isRight = true;

		//������
	}

	return isRight;



}

bool Ball::BlockSideCheckUD(Block* _ColBlock)
{
	bool isDown = false;
	bool isMD = false;
	Block* thisBlock = _ColBlock;
	float BlockTop = thisBlock->GetActorLocation().Y - thisBlock->GetBlockScale().Y / 2;
	float BlockBottom = thisBlock->GetActorLocation().Y + thisBlock->GetBlockScale().Y / 2;

	float YMid = thisBlock->GetActorLocation().Y;
	float BallYCheck = CurBallPos.Y;

	if (BlockTop < CurBallPos.Y && CurBallPos.Y < YMid)
	{

		isDown = false;
		MidTopHeight = true; //������ ��� ����
		//�� ����
	}
	if (BlockTop > CurBallPos.Y)
	{
		isDown = false;
		MidTopHeight = false;
		// ��¥ ����

	}

	if (YMid <= CurBallPos.Y && CurBallPos.Y < BlockBottom)
	{

		MidHeight = true; //������� �Ʒ�����
		isDown = true;

		//�Ʒ� ������
	}
	if (CurBallPos.Y > BlockBottom)
	{
		isDown = true;
		isBottom = true;
	}
	return isDown;
}


void Ball::BallAdjustwithWall(float _Pos, bool isX)
{
	float MovePos = 0;
	if (isX == true)
	{
		if (CurBallPos.X - 1 < 30)
		{
			CurBallPos.X = 30;
		}

		if (CurBallPos.X + 1 > 520)
		{
			CurBallPos.X = 520;
		}


	}

	if (CurBallPos.Y - 1 < 80)
	{
		CurBallPos.Y = 80;
	}

}

void Ball::BallAdjustwithPlayer(float _Pos)
{
	if (User::CurPos.Y == CurBallPos.Y)
	{
		SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });
	}

}