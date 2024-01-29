#include "EngineString.h"

UEngineString::UEngineString()
{
}

UEngineString::~UEngineString()
{
}

std::string UEngineString::ToUpper(std::string_view View)
{
	std::string Name = View.data();//이걸로 표현하는 이유는?

	for (char& _Ch : Name) //이거 왜 레퍼런스를 사용한건지? 범위지정for문 이해 못한듯 for(뭐고:범위까지)
	{
		_Ch = std::toupper(_Ch);
	}
	//대문자로 바꿔준 다음에 이름을 반환해준다

	return Name;
}