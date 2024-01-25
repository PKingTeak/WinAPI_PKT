#include "EngineMath.h"

//방향을 정해주기 위한 기능 
const float4 float4::Zero = { 0.0f, 0.0f, 0.0f, 0.0f };
const float4 float4::Left = { -1.0f, 0.0f, 0.0f, 0.0f };
const float4 float4::Right = { 1.0f, 0.0f, 0.0f, 0.0f };
const float4 float4::Up = { 0.0f, -1.0f, 0.0f, 0.0f };
const float4 float4::Down = { 0.0f, 1.0f, 0.0f, 0.0f };
//일단 위로 가는거부터 구현하면 될거 같다. 


EngineMath::EngineMath() 
{
}

EngineMath::~EngineMath() 
{
}

