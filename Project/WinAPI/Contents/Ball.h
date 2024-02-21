#pragma once
#include<EngineCore/Actor.h>
#include"User.h"
#include"ColliderManager.h"
class Ball : public AActor
{
private: 
	static Ball* MainBall;;
public:
	// constrcuter destructer
	Ball();
	~Ball();

	// delete Function
	Ball(const Ball& _Other) = delete;
	Ball(Ball&& _Other) noexcept = delete;
	Ball& operator=(const Ball& _Other) = delete;
	Ball& operator=(Ball&& _Other) noexcept = delete;


	//���� ����� ������ ������ 
	/*
	1. ������ ����  -> �÷��̾� ��ġ�� ���� 
		���� �÷��̾� ��ġ�� �����ͼ� ����ٴϰ� �� isballLive�� ���� �ʿ� �����ϴ��� äũ�ϴ°��̴�. 
	2. ������ ���� Ȥ�� �����̽��ٸ� ������ �ٷ� ������ ����
		�ʻ󿡼� ���� ������ �Ѱ��� ���� �ؾߵ� == boolŸ������ ���� �����ߴ��� Ȯ���غ���
	3. ���� �������� ������� �ٽ� ����� ������ = �÷��̾� ��ġ
	4. ���� �ε������� ��ó
	5. ��ϵ�� �ε������� ��ó ���

	*/
	void SetPos(FVector _CurPos);
	void StartPos(FVector _StartPos);
	void DirCheck();
	void Reflect(FVector _CurBallPos);
	void GetUserScale();
	static Ball* GetMainBall();
	UCollision* GetCollision();
//static UCollision* GetBallCollision();

	
	//void YLReflect();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	
private:
	
	void Move(float _DeltaTime);
	void IsCollide();
	void GameStart(float _DeltaTime);
	UImageRenderer* BallRender = nullptr;
	FVector CurBallPos = {};
	FVector BDir = {0.5f,-0.5f};
	UCollision* BallCollison = nullptr;
	bool IsballLive = false;
	float Speed = 300.0f;
	float Time = 0.0f;
	bool isCol = false;
	
	

};