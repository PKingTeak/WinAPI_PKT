#include "Ball.h"
#include <EngineCore/EngineResourcesManager.h>
#include "User.h"
#include <EnginePlatform/EngineInput.h>
#include <vector>
#include"Block.h"
#include"Item.h"
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
	BallRender->SetScale({ 10,8 });
	GetUserScale();
	SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });



	BallCollison = CreateCollision(ColliderOrder::Ball);
	BallCollison->SetScale({ 5,5 });
	BallCollison->SetColType(ECollisionType::CirCle);




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
	if (false == IsballLive)
	{
		SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });
	}

	AActor::Tick(_DeltaTime);
	GameStartCheck();

	Move(_DeltaTime);
	// �� �̷��� ��ġ�� üũ�ϴ� ��
	// �浹�ϰ� ���� üũ�ϴ¹�


	WallCheck();
	//UserCheck();
	BlockCheck();

	// IsCollide();
}

void Ball::IsCollide()
{
	if (false == IsballLive)
	{
		return;
	}

	std::vector<UCollision*> Result;

	if (true == BallCollison->CollisionCheck(ColliderOrder::Player, Result))
	{

		FVector N = { 0,-1 };
		FVector N2 = { 0,-2 };
		FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
		BDir = BDir + (N2 * T); //R

	}
	else if (true == BallCollison->CollisionCheck(ColliderOrder::Block, Result))
	{
		UCollision* Collider = Result[0/*���°�϶�*/];
		AActor* ColAct = Collider->GetOwner();
		Block* ColBlock = dynamic_cast<Block*>(ColAct);
		BDir = (BDir * -1);
		FVector BlockPos = ColBlock->GetActorLocation();
		Result[0]->Destroy(); //�ӽ÷� ����� CollManager���� �Ѱ��� �����Ұ�
		ColBlock->Destroy();
	}

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
		BDir = FVector(-1.0f, -1.0f);
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

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		IsballLive = true;
	}
}


void Ball::StartPos(FVector _StartPos)
{
	CurBallPos = _StartPos; //���� ��ġ 

}


Ball* Ball::GetMainBall()
{
	return MainBall;
}


void Ball::Move(float _DeltaTime)
{
	BDir.Normalize2D();

	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.
}

void Ball::WallCheck()
{
	// R = P + 2n(-P��n);
	FVector N = FVector::Zero;
	CurBallPos = GetTransform().GetPosition();

	if (CurBallPos.X >= 520)
	{
		N = { -1,0 };
	}
	else if (CurBallPos.X <= 30)
	{
		N = { 1,0 };
	}
	else if (CurBallPos.Y <= 50)
	{
		N = { 0,1 };
	}


else if (CurBallPos.Y >= 480)
{
		int a = 0;
		PlayerPos();
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
		Reflect({ 0.0f, -1.0f });
		FVector Pos = GetTransform().GetPosition() - User::CurPos;
		Pos.X /= User::UserScale.hX(); //���� x���� ������ �������� �ε�ģ ���� ������ 
		BDir.X += Pos.X;
		BDir.Normalize2D();
	}
}
void Ball::UserCheck()
{
	std::vector<UCollision*> Result;
	if (true == BallCollison->CollisionCheck(ColliderOrder::Player, Result))
	{
		Reflect({ 0.0f, -1.0f });
		FVector Pos = GetTransform().GetPosition() - User::CurPos;
		Pos.X /= User::UserScale.hX(); //���� x���� ������ �������� �ε�ģ ���� ������ 
		BDir.X += Pos.X;
		BDir.Normalize2D();

		//���� ũ�⸸ŭ ���� ����� ������
		
		FVector TestPos = User::CurPos;
	


		

	}
}

void Ball::BlockCheck()
{
	std::vector<UCollision*> Result;
	if (true == BallCollison->CollisionCheck(ColliderOrder::Block, Result))
	{
		UCollision* Collider = Result[0/*���°�϶�*/];
		AActor* ColAct = Collider->GetOwner();
		Block* ColBlock = dynamic_cast<Block*>(ColAct);
		BDir = (BDir * -1);
		FVector BlockPos = ColBlock->GetActorLocation();
		Result[0]->Destroy(); //�ӽ÷� ����� CollManager���� �Ѱ��� �����Ұ�
		ColBlock->Destroy();
	}
}

void Ball::Reflect(FVector Normal)
{
	FVector N = Normal;
	FVector N2 = N * 2.0f;
	FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
	BDir = BDir + (N2 * T);
}

