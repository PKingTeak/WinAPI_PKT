#pragma once
#include <EngineCore/Actor.h>
#include"Stage1BackGround.h"


// ���� :
class User : public AActor
{
public:
	// constrcuter destructer
	User();
	~User();

	// delete Function
	User(const User& _Other) = delete;
	User(User&& _Other) noexcept = delete;
	User& operator=(const User& _Other) = delete;
	User& operator=(User&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	

private:
	FVector CurPos;
	//void AutoShot(float _DeltaTime);
	UImageRenderer* PlayerRenderer;
	
	float time = 0.0f;
	


	//��� �ѽ�� ����� �ʿ� ����. 
	// float QSkillColl = 0.0f; 
};

