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
	BallRender->SetScale(BallSize*2 );
	GetUserScale();
	SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });



	BallCollison = CreateCollision(ColliderOrder::Ball);
	BallCollison->SetScale({ 1,1 });
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


	if (UEngineInput::IsDown('R'))
	{
		Reset();
	}
	AActor::Tick(_DeltaTime);
	GameStartCheck();

	Move(_DeltaTime);
	// 내 미래의 위치로 체크하는 법
	// 충돌하고 나서 체크하는법


	WallCheck();
	BlockCheck();


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





Ball* Ball::GetMainBall()
{
	return MainBall;
}


void Ball::Move(float _DeltaTime)
{
	BDir.Normalize2D();

	AddActorLocation(BDir * Speed * _DeltaTime);//공이이동한다.
}

void Ball::WallCheck()
{
	// R = P + 2n(-P·n);
	FVector N = FVector::Zero;
	CurBallPos = GetTransform().GetPosition();

	if (CurBallPos.X >= 524)
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
	
		PlayerPos();
	}

if (false == N.IsZeroVector2D())
{
	Reflect(N);
	int a = 0;
	
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
		Pos.X /= User::UserScale.hX(); //유저 x에서 중점을 기준으로 부딪친 곳을 나눠서 
		BDir.X += Pos.X;
		BDir.Normalize2D();
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
	std::vector<UCollision*> Result;
	if (true == BallCollison->CollisionCheck(ColliderOrder::Block, Result))
	{
		UCollision* Collider = Result[0/*몇번째일때*/];
		AActor* ColAct = Collider->GetOwner();
		Block* ColBlock = dynamic_cast<Block*>(ColAct);
		BlockRatio(ColBlock);
		FVector BlockPos = ColBlock->GetActorLocation();
		//Result[0]->Destroy(); //임시로 사용중 CollManager에서 총괄로 관리할것
		//ColBlock->Destroy();
	}
}

void Ball::Reflect(FVector Normal)
{
	FVector N = Normal;
	FVector N2 = N * 2;
	float X = BDir.X;
	float Y = BDir.Y;
	float T = (-BDir.X) * N.X + (-BDir.Y) * N.Y; //(-P * n) <여기가 이상하다.
	BDir = BDir + (N2 * T); //R = P+2n(-P내적n)
}


void Ball::BlockRatio(Block* _NewBlock)
{
	FVector N = {BDir.X,BDir.Y};

	FTransform Transform = { _NewBlock->GetBlockPos(), _NewBlock->GetBlockScale() };

	bool R = BlockSideCheckLR(_NewBlock);
	bool D = BlockSideCheckUD(_NewBlock);
	
	
	 
	
	if (false == R && false == D)
	{
		if (true == MidTopHeight)
		{
			Reflect({ -1.0f,0.0f });
		}
		else
		{
		Reflect({0.0,-1.0f});
		}
	
		//N

	}
	if (true == R && true == D)
	{
		if (true == MidHeight)
		{
			Reflect({ 1.0f,0.0f });
		}
		else
		{
		Reflect({ 1.0f,-1.0f });
		}
	}
	if (true == R && false == D)
	{
		if (true == MidTopHeight)
		{
			Reflect({ 1.0f,0.0f });
		}
		else
		{
		Reflect({0.0f,-1.0f});
		}
		

	}
	if (false == R && true == D)
	{
		if (true == MidHeight)
		{
			Reflect({ -1.0f,0.0f });
		}
		else
		{
		Reflect({ 0.0f,1.0f });
		}
		 // 여기서 값이 y가 -가 붙어서 나와야 하는데 지금 양수로 나온다. 그래서 꺾여서 나가기 때문에 값이 이상하다
		// X값은 잘나옴
	}

	
	
	
	
	
//	if (RatioX < RatioY) // : /
//	{
//		R = false; // 이게 맞음
//		D = true;
	//}
	/*
	
	if (false == R && false == D)
	{
		float ColX = GetActorLocation().X - Transform.Left();
		float ColY = GetActorLocation().Y - Transform.Top();

		// 지금 공 위치 = 공의 현재 위치 - 블록의 왼쪽 좌표
		// 지금 공 위치 = 공의 현재 y위치 - 블록의 위쪽 좌표;

		float RatioX = ColX / _NewBlock->GetBlockScale().X;
		float RatioY = ColY / _NewBlock->GetBlockScale().Y;
		 // [\] 일때
		FVector N = { RatioX ,RatioY };
		N.Normalize2D();
		Reflect(N);
	
		//N

	}
	*/


}
bool Ball::BlockSideCheckLR(Block* _ColBlock )
{
	
	bool isRight = false;
	
	Block* thisBlock = _ColBlock;
	float BlockLeft =  thisBlock->BlockLeft() + thisBlock->GetActorLocation().X -1;
	float BlockRight =  thisBlock->BlockRight() + thisBlock->GetActorLocation().X+1;
	
	//각각 1씩 더해준 이유는 float 의 오차를 없애기 위해서 더해줬습니다. 
	
	float XMid = thisBlock->GetActorLocation().X;
	
	

	if (BlockLeft <= CurBallPos.X && CurBallPos.X < XMid)
	{

		isRight = false;
		
		//왼쪽 
		//왼쪽 오른쪽인지 일단 먼저 확인하고 위아래 에서 구현할때 bool타입으로 확인하고 그다음 계산을 시작
	}

	if (XMid <= CurBallPos.X && CurBallPos.X <= BlockRight)
	{
		isRight = true;
	
		//오른쪽
	}

	return isRight;
	


}

bool Ball::BlockSideCheckUD(Block* _ColBlock)
{
	bool isDown = false;
	bool isMD = false;
	Block* thisBlock = _ColBlock;
	float BlockTop = thisBlock->BlockUP() + thisBlock->GetActorLocation().Y - 1;
	float BlockBottom = thisBlock->BlockBottom() + thisBlock->GetActorLocation().Y ;

	float YMid = thisBlock->GetActorLocation().Y;


	if (BlockTop < CurBallPos.Y && CurBallPos.Y < YMid)
	{
		
		isDown = false;
		MidTopHeight = true;
		//위
	}
	if (BlockTop >= CurBallPos.Y)
	{
		isDown = false;
	}

	if (YMid <= CurBallPos.Y && CurBallPos.Y < BlockBottom)
	{

		MidHeight = true;
		isDown = true;
		
		//아래
	}
	if (CurBallPos.Y > BlockBottom)
	{
		isDown = true;
	}
	return isDown;
}

//위아래 반사각공식은 이제 완벽한데 






















/*

		if (RatioX < RatioY) //대각선 방향 [/]
		{
			isRight = false;
			isDown = false;
		}
		if (RatioX > RatioY) //대각선 [\]
		{
			isDown = true;
			isRight = true;
			RatioY *= -1;
			//만약에 왼쪽 위쪽에서 맞았을경우에는 위로 튕겨야된다.
		}

*/