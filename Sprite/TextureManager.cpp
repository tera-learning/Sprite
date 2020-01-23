#include "TextureManager.h"
#include <fstream>
#include <iostream>

Texture::Texture(const std::string& str)
{
	std::ifstream ifs(str, std::ios::binary);
	if (!ifs) {
		std::cout << "in file open error !" << std::endl;
		return;
	}

	//ヘッダ読み込み
	NewBitMapHeader fileHeader;
	ifs.read((char*)&fileHeader, sizeof(NewBitMapHeader));

	m_Width = fileHeader.width;
	m_Height = fileHeader.height;
	m_PixelByte = 4;

	int imageSize = m_Width * m_Height;
	int imageSizeByte = imageSize * 3;

	//画像一括読み込み
	char* col = new char[imageSizeByte];
	ifs.read(col, imageSizeByte);

	//画像サイズ分バッファー確保
	m_Buffer.resize(imageSize * m_PixelByte);

	//画像データコピー
	for (int i = 0; i < imageSize * m_PixelByte; i++) {
		if (((i + 1) % m_PixelByte) != 0 ) {
			m_Buffer[i] = *col;
			col++;
		}
		else {
			m_Buffer[i] = 255;
		}
	}
}

Texture::~Texture()
{
	m_Buffer.clear();
	m_Width = 0;
	m_Height = 0;
}

int Texture::GetWidth(void) const
{
	return m_Width;
}

int Texture::GetHeight(void) const
{
	return m_Height;
}

int Texture::GetPixelByte(void) const
{
	return m_PixelByte;
}

int Texture::GetSize(void) const
{
	return m_Buffer.size();
}

const unsigned char* Texture::GetTextureBuffer(void) const
{
	return &m_Buffer[0];
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	m_TextureList.clear();
}

int TextureManager::AddTexture(const std::string& str)
{
	m_TextureList.push_back(Texture(str));
	return m_TextureList.size() - 1;
}

const Texture& TextureManager::GetTexture(int textureIndex) const
{
	return m_TextureList.at(textureIndex);
}

