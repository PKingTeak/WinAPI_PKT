#pragma once
#include <EngineBase/EngineMath.h>
#include <EngineCore/EngineCore.h>



class GloBal
{


public:
	static GloBal& GetInst()
	{
		static GloBal global = GloBal();
		return global;
	}


private:
	
	GloBal();
	~GloBal();

	// delete Function
	GloBal(const GloBal& _Other) = delete;
	GloBal(GloBal&& _Other) noexcept = delete;
	GloBal& operator=(const GloBal& _Other) = delete;
	GloBal& operator=(GloBal&& _Other) noexcept = delete;

};

