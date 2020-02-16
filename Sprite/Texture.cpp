#include "Texture.h"
#include <fstream>
#include <iostream>

Texture::Texture()
{
}

Texture::Texture(const std::string& str)
{
	LoadTexture(str);
}

Texture::~Texture()
{
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
	return m_Width * m_Height * m_PixelByte;
}

void Texture::LoadTexture(const std::string& str)
{
	std::ifstream ifs(str, std::ios::binary);
	if (!ifs) {
		std::cout << "in file open error !" << std::endl;
		return;
	}

	//�w�b�_�ǂݍ���
	NewBitMapHeader fileHeader;
	ifs.read((char*)&fileHeader, sizeof(NewBitMapHeader));

	m_Width = fileHeader.width;
	m_Height = fileHeader.height;
	m_PixelByte = 4;

	int imageSizeByte = m_Width * m_Height * m_PixelByte;

	//�摜�ꊇ�ǂݍ���
	//���@������
	//Raii �l�����@�X�}�[�g�|�C���^�@�I�[�i�[�V�b�v,���C�t�^�C�����l����@

	//�摜�ꊇ�ǂݍ��݁@new�����Ƃ��ɉ���̂��Ƃ��l����
	m_Buffer = std::make_unique<char[]>(imageSizeByte);
	ifs.read(m_Buffer.get(), imageSizeByte);
}

const char* Texture::GetTextureBuffer(void) const
{
	return m_Buffer.get();
}
