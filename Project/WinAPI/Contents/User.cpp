#include "User.h"
#include <EngineBase/EngineTime.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineMath.h>
#include "ArkanoidCore.h"
#include "UIManager.h"

#include <vector>
#include <list>
#include "Bullet.h"
#include "Ball.h"
FVector User::CurPos = {};
FVector User::UserScale = {};
User* User::MainUser = nullptr;
UCollision* User::PlayerCollider = nullptr;
bool User::isGameOver = false;
User::User()
{
}

User::~User()
{
}

void User::BeginPlay()
{
	
	MainUser = this;
	AActor::BeginPlay(); //Actor���� ��ӹ޾ƿ� BeginePlay()�� ��������ش� ������ ������ ����ִ�.
	UserScale = { 60,14 };
	//�������� ��������
	SetActorLocation({ 300,530 }); //���� ��ġ 480
	CurPos = GetActorLocation();
	PlayerRenderer = CreateImageRenderer(0);

	PlayerRenderer->SetImage("Player_Start.png");
	PlayerRenderer->SetTransform({ { 0,0 },{ 68,16} });
	PlayerRenderer->CreateAnimation("PlayerIdleAnimation", "Player_Idle.png", 0, 5, 0.1f, true);
	PlayerRenderer->CreateAnimation("PlayerStart", "Player_Start.png", 0, 4, 0.1f, false);
	PlayerRenderer->CreateAnimation("PlayerEnlarge","Player_Enlarge.png",0,5,0.1f,true);
	PlayerRenderer->CreateAnimation("PlayerDead", "Player_Dead.png", 0, 3, 0.1f, false);
	//���� ���¹�� 

	
	this->SetActive(true, 1.0f);
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


void User::Tick(float _DeltaTime) //��ŸŸ���� ���� �ð��̴� �����Ӹ��� �ð��� �ٸ��� �ϸ� ���ɿ� ���� �ð��� �޶����� ������ �ȵȴ�.
{
	time += _DeltaTime;
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
	
	UIManager::GetUIManager()->UIManager::PlayerLifeMinusUI(Life);
	Ball::GetMainBall()->SetSpeed(300.0f);
	User::Life--;
	_Player->SetPlayerState(PlayerState::Dead, _Player);
	PlayerState nowState = GetPlayerState(_Player);
	CheckPlayerState(_Player);
	if (isDead == true)
	{
		NowState = PlayerState::Start;
	}
	if (Life < 0)
	{
		isGameOver = true;
		GetWorld()->SetAllTimeScale(0.0f);
	}
	
}
void User::PlayerLifePlus()
{
	Life++;
	if (Life >= 3)
	{
		Life = 3;
	}
	UIManager::GetUIManager()->UIManager::PlayerLifePlusUI(Life);

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
	PlayerState nowState;
	UIManager* UIContorl = UIManager::GetUIManager();
	
	switch (NowState)
	{
	case Start:
	

		
		if (true == isStartAniEnd)
		{
			SetPlayerState(PlayerState::Idle, _Player);
			
		}

		if (this->IsActive() == true)
		{
			PlayerRenderer->SetTransform({ { 0,0 },{ 68 ,16} });
			PlayerRenderer->ChangeAnimation("PlayerStart");
			isEnd = PlayerRenderer->IsCurAnimationEnd(); // true�� ���� �׷� �ִϸ��̼��� ���� �����ε�
			isStartAniEnd = isEnd;
				
			
			//Dead ���� time 0���� �ʱ�ȭ ���ָ� ������ ����� Start�ִϸ��̼� �ɵ� �ϴ�.
			if (true == isDead)
			{
				
				isDead = false;
			}
		}
		
		nowState = _Player->GetPlayerState(_Player);
		break;
	case Idle:
		PlayerRenderer->SetTransform({ { 0,0 },{ 68 ,16} });
		UIContorl->Ready_Text->SetActive(false);
		PlayerRenderer->ChangeAnimation("PlayerIdleAnimation");
		break;
	case PEnlarge:
		UserScale = UserScale * 2;
		PlayerRenderer->SetTransform({ { 0,0 },{ 68+20,16} });
		PlayerRenderer->ChangeAnimation("PlayerEnlarge");
		break;
	case Dead:
		if (true == isDead)
		{
			UIContorl->Ready_Text->SetActive(true);
			NowState = Start;
			PlayerAnimationReset(_Player);
		}
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






void User::PlayerAnimationReset(User* _Player)
{
	_Player->PlayerRenderer->AnimationReset();
}

bool User::CheckGameOver()
{
	return isGameOver;
}