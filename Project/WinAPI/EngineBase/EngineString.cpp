#include "EngineString.h"

EngineString::EngineString()
{
}

EngineString::~EngineString()
{
}

std::string EngineString::ToUpper(std::string_view View)
{
	std::string Name = View.data();//�̰ɷ� ǥ���ϴ� ������?

	for (char& _Ch : Name) //�̰� �� ���۷����� ����Ѱ���? ��������for�� ���� ���ѵ� for(����:��������)
	{
		_Ch = std::toupper(_Ch);
	}
	//�빮�ڷ� �ٲ��� ������ �̸��� ��ȯ���ش�

	return Name;
}