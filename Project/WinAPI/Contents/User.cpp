#include "User.h"
#include <EngineBase/EngineTime.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineMath.h>
#include "ArkanoidCore.h"

#include"CollisonManger.h"
#include <vector>
#include <list>
#include "Bullet.h"
#include "Ball.h"
FVector User::CurPos = {};
User::User()
{
}

User::~User()
{
}

void User::BeginPlay()
{
	AActor::BeginPlay(); //Actor에서 상속받아와 BeginePlay()를 실행시켜준다 하지만 지금은 비어있다.

	//랜더러를 가져오기
	SetActorLocation({ 300,480 });
	UImageRenderer* PlayerRenderer = CreateImageRenderer(1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Idle.png", 1, 6);
	PlayerRenderer->SetImage("Player_Idle.png");
	PlayerRenderer->SetTransform({ { 0,0 },{ 68,16} });
	PlayerRenderer->CreateAnimation("PlayerIdleAnimation", "Player_Idle.png",0,5,0.1f,true);
	PlayerRenderer->ChangeAnimation("PlayerIdleAnimation");
	

	//SetActorLocation({16,4,32,8});
	//SetActorLocation({ 200, 500 });


}


void User::Tick(float _DeltaTime) //델타타임은 현재 시간이다 프레임마다 시간을 다르게 하면 성능에 따라 시간이 달라지기 때문에 안된다.
{
	
	//Block();
	FVector MovePos = FVector::Zero;
	FVector NextPos = GetActorLocation();
	CurPos = NextPos;
	if (true == UEngineInput::IsPress('A'))
	{
		MovePos = FVector::Left * 500.0f * _DeltaTime;
		NextPos += MovePos;
		//AddActorLocation(MovePos);
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

	
	AutoShot(_DeltaTime);
	
}




void User::AutoShot(float _DeltaTime)
 {
	if (true == Isballlive)
	{
		return;
	}
 	time += _DeltaTime;
	if (time >= 2)
	{
		CurPos;
		Ball* NewBall = GetWorld()->SpawnActor<Ball>(); //여기서 공이 생성됨 
		NewBall->Move(CurPos);
		NewBall->SetActorLocation({CurPos.X,CurPos.Y-10});//플레이어의 판위에서 생성
		
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

/*
void 레이저()



if(Input(' ');

{

 ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
 NewBullet->SetActorLocation(GetActorLocation());
 NewBullet->SetDir(FVector::Up);
 time = 0;
} 
*/