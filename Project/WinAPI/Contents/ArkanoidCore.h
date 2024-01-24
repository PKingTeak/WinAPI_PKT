#pragma once
#include <EngineCore\EngineCore.h>

// Ό³Έν :
class ArkanoidCore : public EngineCore
{
public:
	// constrcuter destructer
	ArkanoidCore();
	~ArkanoidCore();

	// delete Function
	ArkanoidCore(const ArkanoidCore& _Other) = delete;
	ArkanoidCore(ArkanoidCore&& _Other) noexcept = delete;
	ArkanoidCore& operator=(const ArkanoidCore& _Other) = delete;
	ArkanoidCore& operator=(ArkanoidCore&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void End() override;

private:

};

