#pragma once
#include "ControlSprite.h"
class MoveSprite :
	public ControlSprite
{
public:
	MoveSprite();
	~MoveSprite();
	void Update(std::vector<Sprite>* spriteList);
};

