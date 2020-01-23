#include "Sprite.h"
#include "TextureManager.h"

SpriteList::SpriteList()
{
}

SpriteList::~SpriteList()
{
	m_SpriteList.clear();
}

int SpriteList::GetSpriteNum(void) const
{
	return m_SpriteList.size();
}

void SpriteList::AddSprite(const CPoint& drawPos, int textureIndex) {
	Sprite sprite{drawPos, textureIndex};
	m_SpriteList.push_back(sprite);

}

const Sprite& SpriteList::GetSprite(int spriteIndex) const {
	return m_SpriteList.at(spriteIndex);
}
