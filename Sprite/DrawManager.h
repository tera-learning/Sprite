#pragma once
#include "Sprite.h"
#include <Windows.h>
#include <d3d11.h>
#include <wrl/client.h>

struct ConstantBuffer {
	int centerWindow[2];
};

class DrawManager final
{
private:
	SpriteList m_Sprite;
	TextureManager m_TextureManager;
	VertexManager m_VertexManager;

public:
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_Context;
	Microsoft::WRL::ComPtr<ID3D11Device> m_Device;
	Microsoft::WRL::ComPtr<IDXGISwapChain> m_Swapchain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_RenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_VertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_InputLayout;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> m_VertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_PixelShader;
	Microsoft::WRL::ComPtr<ID3D11SamplerState> m_SamplerState;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_TextureView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> m_Texture;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_ConstantBuffer;
	D3D11_VIEWPORT m_ViewPort;

	DrawManager() {};
	DrawManager(const DrawManager& drawManager) = delete;
	DrawManager& operator=(const DrawManager& drawManager) = delete;
	/* virtual */ ~DrawManager() { m_Context->ClearState();  };

	HRESULT Create(HWND hwnd);
	void Render(HWND hwnd, CPoint pos);
};

