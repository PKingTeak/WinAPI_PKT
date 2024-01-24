#pragma once
#include <EngineCore/Actor.h>


// Ό³Έν :
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

};

