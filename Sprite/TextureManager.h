#pragma once
#include <vector>
#include <string>

#pragma pack(1)
struct NewBitMapHeader {
	int width;
	int height;
};

struct Color {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};
#pragma pack()

class Texture final
{
private:
	std::vector<unsigned char> m_Buffer;
	int m_Width;
	int m_Height;
	int m_PixelByte;

public:
	Texture(const std::string& str);
	Texture(const Texture& texture) = default;
	Texture& operator=(const Texture& texture) = default;
	/* virtual */ ~Texture();

	int GetWidth(void) const;
	int GetHeight(void) const;
	int GetPixelByte(void) const;
	int GetSize(void) const;
	const unsigned char* GetTextureBuffer(void) const;
};

class TextureManager final
{
private:
	std::vector<Texture> m_TextureList;

public:
	TextureManager();
	TextureManager(const TextureManager& textureManager) = delete;
	TextureManager& operator=(const TextureManager& textureManager) = delete;
	/* virtual */ ~TextureManager();

	int AddTexture(const std::string& str);
	const Texture& GetTexture(int textureIndex) const;
};

