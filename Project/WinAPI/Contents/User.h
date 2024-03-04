#pragma once
#include <EngineCore/Actor.h>
#include"Stage1BackGround.h"


enum PlayerState
{
	Start,
	Idle,
	PEnlarge,
	Dead

};


// 설명 :
class User : public AActor
{


private:
	static User* MainUser;
	static UCollision* PlayerCollider;
public:
	// constrcuter destructer
	User();
	~User();

	// delete Function
	User(const User& _Other) = delete;
	User(User&& _Other) noexcept = delete;
	User& operator=(const User& _Other) = delete;
	User& operator=(User&& _Other) noexcept = delete;

	void PlayerDie();
	
	int GetLife()
	{
		return Life;
	}


	static FVector CurPos;
	static FVector UserScale;
	static User* GetMainUser(); //다른곳에서 속성을 가져오기 get
	static UCollision* GetUserCollider();

	void PlayerStart(User* _Player);
	template<typename Playerstate>
	int SetPlayerState(Playerstate _PlayerState, User* _Player)
	{
		_Player->NowState = _PlayerState;
		return SetPlayerStates(static_cast<int>(_PlayerState), _Player);
	}
	PlayerState GetPlayerState(User* _Player);
	
	void CheckPlayerState(User* _Player);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	

private:
	void PlayerAnimationReset(User* _Player);
	UImageRenderer* PlayerRenderer;
	float time = 0.0f;
	int Life = 2;
	PlayerState NowState = PlayerState::Idle;


	//사실 총쏘는 기능은 필요 없다. 
	// float QSkillColl = 0.0f; 
};

