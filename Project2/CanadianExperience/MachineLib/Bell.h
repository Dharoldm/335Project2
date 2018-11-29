#pragma once
#include "Component.h"
class CBell : public CComponent
{
public:
	CBell();
	virtual ~CBell();
	void CreatePlayer(std::wstring file);
	void PlayChannel();
};

