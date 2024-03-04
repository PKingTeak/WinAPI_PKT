#include "User.h"
#include <EngineBase/EngineTime.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineMath.h>
#include "ArkanoidCore.h"


#include <vector>
#include <list>
#include "Bullet.h"
#include "Ball.h"
FVector User::CurPos = {};
FVector User::UserScale = {};
User* User::MainUser = nullptr;
UCollision* User::PlayerCollider = nullptr;


User::User()
{
}

User::~User()
{
}

void User::BeginPlay()
{
	MainUser = this;
	AActor::BeginPlay(); //Actor에서 상속받아와 BeginePlay()를 실행시켜준다 하지만 지금은 비어있다.
	UserScale = { 60,14 };

	//랜더러를 가져오기
	SetActorLocation({ 300,480 }); //원래 위치 480
	CurPos = GetActorLocation();
	PlayerRenderer = CreateImageRenderer(0);

	PlayerRenderer->SetImage("Player_Idle.png");
	PlayerRenderer->SetTransform({ { 0,0 },{ 68,16} });
	PlayerRenderer->CreateAnimation("PlayerIdleAnimation", "Player_Idle.png", 0, 5, 0.1f, true);
	PlayerRenderer->CreateAnimation("PlayerStart", "Player_Start.png", 0, 4, 0.1f, false);
	PlayerRenderer->CreateAnimation("PlayerDead", "Player_Dead.png", 0, 3, 0.1f, false);
	//변수 보는방법 

	CheckPlayerState(this);

}
UCollision* User::GetUserCollider()
{
	return PlayerCollider;
}
User* User::GetMainUser()
{

	return MainUser;
}


void User::Tick(float _DeltaTime) //델타타임은 현재 시간이다 프레임마다 시간을 다르게 하면 성능에 따라 시간이 달라지기 때문에 안된다.
{

	CurPos = GetActorLocation();
	FVector MovePos = FVector::Zero;
	FVector NextPos = GetActorLocation();
	CurPos = NextPos;
	if (true == UEngineInput::IsPress('A'))
	{
		MovePos = FVector::Left * 500.0f * _DeltaTime;
		NextPos += MovePos;

	}

	if (true == UEngineInput::IsPress('D'))
	{
		MovePos = FVector::Right * 500.0f * _DeltaTime;
		NextPos += MovePos;
	}



	if (NextPos.X <= 50 || NextPos.X >= 500)
	{
		return;
	}
	AddActorLocation(MovePos);

	if (UEngineInput::IsDown('U'))
	{
		SetActorLocation({ 300,100 });
	}
	if (UEngineInput::IsDown('I'))
	{
		SetActorLocation({ 300,480 });
	}


	CheckPlayerState(this);



}

void User::PlayerDie(User* _Player)
{
	Life -= 1;
	_Player->SetPlayerState(PlayerState::Dead, _Player);
	//_Player->SetPlayerState(PlayerState::Dead, _Player);
	PlayerState nowState = GetPlayerState(_Player);
	CheckPlayerState(_Player);
	if (isDead == true)
	{
		NowState = PlayerState::Start;
	}
	if (Life < 0)
	{
		//GameOver() UI 작업;
		//Player 다시 재생성 안할것
	}
}

void User::PlayerStart(User* _Player)
{
	//_Player->CreateAnimation("PStartAnimation", "Player_Start.png", 0, false);

}


PlayerState User::GetPlayerState(User* _Player)
{
	return _Player->NowState;
}


void User::CheckPlayerState(User* _Player)
{
	bool isEnd;

	switch (NowState)
	{
	case Start:

		if (true == isStartAniEnd)
		{
			SetPlayerState(PlayerState::Idle, _Player);
		}
		PlayerRenderer->ChangeAnimation("PlayerStart");
		isEnd = PlayerRenderer->IsCurAnimationEnd(); // true라도 나옴 그럼 애니메이션은 끝이 난것인데
		isStartAniEnd = isEnd;
		if (true == isDead)
		{
			isDead = false;
		}
		break;
	case Idle:
		PlayerRenderer->ChangeAnimation("PlayerIdleAnimation");
		break;
	case PEnlarge:
		break;
	case Dead:
		if (true == isDead)
		{
			NowState = Start;
			PlayerAnimationReset(_Player);
		}
		// PlayerAnimationReset(_Player); 만약에 랜더러안에 애니메이션이 존재할 경우 지워줘야 한다.
   //	PlayerAnimationReset(_Player);
		PlayerRenderer->ChangeAnimation("PlayerDead");
		isEnd = PlayerRenderer->IsCurAnimationEnd();
		isDead = isEnd;
		break;
	default:
		break;
	}


}

void User::SetPlayerState(PlayerState _PlayerState, User* _Player)
{
	_Player->NowState = _PlayerState;
	
}






//int User::SetPlayerState(int _PlayerState, User* _Player)
//{
//
//	return _PlayerState;
//	// 임시 리턴값 변신 했을때 상태를 채크할때 사용할 것입니다.
//
//}
//

void User::PlayerAnimationReset(User* _Player)
{
	_Player->PlayerRenderer->AnimationReset();
}


/*
void 레이저()



if(Input(' ');

void User::AutoShot(float _DeltaTime)
 {
	if (true == Isballlive)
	{
		return;
	}
	time += _DeltaTime;
	if (time >= 2)
	{

		Ball* NewBall = GetWorld()->SpawnActor<Ball>(); //여기서 공이 생성됨
		NewBall->Move(CurPos);
		NewBall->SetActorLocation({ CurPos.X,CurPos.Y - 10 });//플레이어의 판위에서 생성

		NewBall->DirCheck();
		Isballlive = true;
		time = 0;
		//공이 사라지면 다시 생기게 할것이다.

	}

//
// 레이저 아이템 먹었을때 스페이스바를 누르면 만들 함수
// 	if (time >= 2)
// 	{
// 		//총알이 계속 나간다 .
// 	}
 }



{

 ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
 NewBullet->SetActorLocation(GetActorLocation());
 NewBullet->SetDir(FVector::Up);
 time = 0;
}
*/
