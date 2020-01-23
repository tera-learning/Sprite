#pragma once
#include "VertexManager.h"
#include "TextureManager.h"
#include <atltypes.h>

struct Sprite
{
	CPoint m_DrawPos;
	int m_TextureIndex;
};

class SpriteList final
{
private:
	std::vector<Sprite> m_SpriteList;

public:
	SpriteList();
	SpriteList(const SpriteList& spriteList) = delete;
	SpriteList& operator=(const SpriteList& spriteList) = delete;
	/* virtual */ ~SpriteList();

	int GetSpriteNum(void) const;
	void AddSprite(const CPoint& drawPos, int textureIndex);
	const Sprite& GetSprite(int spriteIndex) const;
	
};

