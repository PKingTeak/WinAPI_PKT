#include "User.h"
#include <EngineCore\EngineCore.h>
#include <EngineBase/EngineTime.h>
#include <EnginePlatform/EngineInput.h>
#include <vector>
#include <list>
#include "Bullet.h"
User::User()
{
}

User::~User()
{
}

void User::BeginPlay()
{
	AActor::BeginPlay(); //Actor���� ��ӹ޾ƿ� BeginePlay()�� ��������ش� ������ ������ ����ִ�.

	
	


	{
		PlayerRenderer = CreateImageRenderer(0);				  		//��ǥ �̵� ������ �� ������ 0���� �ؾߵȴ� ������ ������ ���� �ִ� ������ �Ȱ��� ���ľ� �ϱ� ����
		PlayerRenderer->SetPosition({ 0, 500 });				  		//��ǥ �̵� ������ �� ������ 0���� �ؾߵȴ� ������ ������ ���� �ִ� ������ �Ȱ��� ���ľ� �ϱ� ����
		PlayerRenderer->SetScale({ 0,50 });						  		//��ǥ �̵� ������ �� ������ 0���� �ؾߵȴ� ������ ������ ���� �ִ� ������ �Ȱ��� ���ľ� �ϱ� ����
		//�̰� �������� ũ���̰� 								  		//��ǥ �̵� ������ �� ������ 0���� �ؾߵȴ� ������ ������ ���� �ִ� ������ �Ȱ��� ���ľ� �ϱ� ����
	}
	SetActorLocation({ 200, 500 });
	SetActorScale({ 100, 50 });


}

void User::Tick(float _DeltaTime) //��ŸŸ���� ���� �ð��̴� �����Ӹ��� �ð��� �ٸ��� �ϸ� ���ɿ� ���� �ð��� �޶����� ������ �ȵȴ�.
{

	if (true == EngineInput::IsPress('A'))
	{
		AddActorLocation(FVector::Left * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('D'))
	{
		AddActorLocation(FVector::Right * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('W'))
	{
		AddActorLocation(FVector::Up * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('S'))
	{
		AddActorLocation(FVector::Down * 500.0f * _DeltaTime);
	}

}
void User::AutoShot(float _DeltaTime)
{

	
	if (_DeltaTime >= 2)
	{
		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
		NewBullet->SetActorLocation(GetActorLocation());
		NewBullet->SetDir(FVector::Up);
	}
}