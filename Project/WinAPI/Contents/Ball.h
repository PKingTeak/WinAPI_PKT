#pragma once
#include<EngineCore/Actor.h>
#include"User.h"
class Ball : public AActor
{
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
		�̰Ŵ� �÷��̾� ���ο� �ִ� CurPos�� ����ؾ� �ϱ� ������ User���� �����ϴ°� ������
	2. ������ ���� Ȥ�� �����̽��ٸ� ������ �ٷ� ������ ����
		�ʻ󿡼� ���� ������ �Ѱ��� ���� �ؾߵ� == boolŸ������ ���� �����ߴ��� Ȯ���غ���
	3. ���� �������� ������� �ٽ� ����� ������ = �÷��̾� ��ġ
	4. ���� �ε������� ��ó
	5. ���ϵ�� �ε������� ��ó ���

	*/
	void SetPos(FVector _CurPos);
	void Move(FVector _StartPos);
	void DirCheck();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	
private:
	void GameStart(float _DeltaTime);
	UImageRenderer* BallRender = nullptr;
	FVector CurBallPos = {};
	FVector BDir = {0,0};
	bool IsballLive = false;
	float Speed = 300.0f;
	float Time = 0.0f;
};