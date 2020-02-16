#pragma once
#include "ControlSprite.h"
class DeleteSprite :
	public ControlSprite
{
public:
	DeleteSprite();
	virtual ~DeleteSprite();
	void Update(std::vector<Sprite>* spriteList);
};

