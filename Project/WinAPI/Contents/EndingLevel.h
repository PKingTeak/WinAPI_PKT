#pragma once
#include<EngineCore/EngineResourcesManager.h>
#include<EngineCore/Level.h>
class EndingLevel : public ULevel
{
public:
	EndingLevel();
	~EndingLevel();

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime)override;
	private:
};

