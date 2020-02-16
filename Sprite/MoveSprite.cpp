#include "MoveSprite.h"



MoveSprite::MoveSprite()
{
}


MoveSprite::~MoveSprite()
{
}

void MoveSprite::Update(std::vector<Sprite>* spriteList)
{
	float speed = 0.0001f;
	int spriteNum = spriteList->size();
	for (int i = 0; i < spriteNum; i++)
	{
		(*spriteList).at(i).m_DrawX += (*spriteList).at(i).m_MoveX * speed;
		(*spriteList).at(i).m_DrawY += (*spriteList).at(i).m_MoveY * speed;

		if ((*spriteList).at(i).m_DrawX < 0.0f || (*spriteList).at(i).m_DrawX > 1.0f)
		{
			(*spriteList).at(i).m_MoveX *= -1.0f;
		}
		if ((*spriteList).at(i).m_DrawY < 0.0f || (*spriteList).at(i).m_DrawY > 1.0f)
		{
			(*spriteList).at(i).m_MoveY *= -1.0f;
		}
	}
}
