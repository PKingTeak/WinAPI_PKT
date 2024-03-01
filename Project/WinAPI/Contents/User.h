#pragma once
#include <EngineCore/Actor.h>
#include"Stage1BackGround.h"


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

	void PlayerDie();
	
	int GetLife()
	{
		return Life;
	}


	static FVector CurPos;
	static FVector UserScale;
	static User* GetMainUser(); //�ٸ������� �Ӽ��� �������� get
	static UCollision* GetUserCollider();
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	

private:
	
	UImageRenderer* PlayerRenderer;
	float time = 0.0f;
	int Life = 2;


	//��� �ѽ�� ����� �ʿ� ����. 
	// float QSkillColl = 0.0f; 
};

