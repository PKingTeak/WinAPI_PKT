#pragma once
#include <EngineCore/Actor.h>
#include"Stage1BackGround.h"
#include"UIManager.h"

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

	
	
	inline int GetLife()
	{
		return Life;
	}


	static FVector CurPos;
	static FVector UserScale;
	static User* GetMainUser(); //다른곳에서 속성을 가져오기 get
	static UCollision* GetUserCollider();

	void PlayerStart(User* _Player);


	void SetPlayerState(PlayerState _PlayerState, User* _Player);

	
	PlayerState GetPlayerState(User* _Player);
	void CheckPlayerState(User* _Player);
	void PlayerDie(User* _Player);
	void PlayerLifePlus()
	{
		Life++;
		if (Life > 5)
		{
			Life = 5;
		}

	}
	bool GetisDead()
	{
		return isDead;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	

private:
	void PlayerAnimationReset(User* _Player);
	UImageRenderer* PlayerRenderer = nullptr;
	UIManager* UIControl = UIManager::GetUIManager();
	PlayerState NowState = PlayerState::Start;
	float time = 0.0f;
	int Life = 2;
	bool isStartAniEnd = false;
	bool isDead = false;

	//사실 총쏘는 기능은 필요 없다. 
	// float QSkillColl = 0.0f; 
};

