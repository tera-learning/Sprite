#pragma once
#include "ControlSprite.h"
class AddSprite :
	public ControlSprite
{
public:
	AddSprite();
	virtual ~AddSprite();
	void Update(std::vector<Sprite>* spriteList);
};

