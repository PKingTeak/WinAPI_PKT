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


// ���� :
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
	static User* GetMainUser(); //�ٸ������� �Ӽ��� �������� get
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

	//��� �ѽ�� ����� �ʿ� ����. 
	// float QSkillColl = 0.0f; 
};

