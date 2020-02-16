#include "DeleteSprite.h"



DeleteSprite::DeleteSprite()
{
}


DeleteSprite::~DeleteSprite()
{
}

void DeleteSprite::Update(std::vector<Sprite>* spriteList)
{
	spriteList->erase(spriteList->begin());
}
