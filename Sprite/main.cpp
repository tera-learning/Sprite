#include "DrawManager.h"
#include <atltypes.h>
#include <Windows.h>

DrawManager dx11Manager;


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		dx11Manager.UpdateSpriteList(wp);
		break;
	}

	return DefWindowProc(hWnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	WNDCLASSEX winc;

	//�\���̂̃T�C�Y
	winc.cbSize = sizeof(WNDCLASSEX);
	//�E�B���h�E�N���X�̊�{�X�^�C����\���萔
	winc.style = CS_HREDRAW | CS_VREDRAW;
	//�E�B���h�E�v���V�[�W���i�E�B���h�E�Ŕ��������C�x���g����������֐��j�̃|�C���g�^
	winc.lpfnWndProc = WndProc;
	//�N���X�̍\���̂̒ǉ��̈�
	winc.cbClsExtra = 0;
	//�E�B���h�E�\���̂̒ǉ��̈�
	winc.cbWndExtra = 0;
	//�C���X�^���X�n���h��
	winc.hInstance = hInstance;
	//�f�X�N�g�b�v���ɕ`�悳���A�C�R���̏������A�C�R���n���h��
	winc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	//�E�B���h�E�̃N���C�A���g�G���A��̃}�E�X�J�[�\��
	winc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	//�N���C�A���g�G���A�̔w�i�F
	winc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//�N���X���j���[
	winc.lpszMenuName = nullptr;
	//�E�B���h�E�N���X�̖��O
	winc.lpszClassName = TEXT("Polygon");
	//�^�X�N�o�[��^�C�g���o�[�ɕ\������鏬�����A�C�R���̏������A�C�R���n���h��
	winc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

	if (!RegisterClassEx(&winc)) return 0;


	//////////////////////////////////////////////////////////////////////////////////
	//�E�B���h�E����
	//////////////////////////////////////////////////////////////////////////////////
	int width = 600;
	int height = 600;

	HWND hwnd = CreateWindow(
		winc.lpszClassName,
		TEXT("Polygon"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,
		0,
		width,
		height,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	if (hwnd == NULL) return 0;


	//////////////////////////////////////////////////////////////////////////////////
	//�N���C�A���g�̈��ōĐ���
	//////////////////////////////////////////////////////////////////////////////////
	CRect crect, wrect;
	GetWindowRect(hwnd, &wrect);
	GetClientRect(hwnd, &crect);

	int newWidth = width + ((wrect.right - wrect.left) - (crect.right - crect.left));
	int newHeight = height + ((wrect.bottom - wrect.top) - (crect.bottom - crect.top));

	SetWindowPos(hwnd, nullptr, 0, 0, newWidth, newHeight, SWP_SHOWWINDOW);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	

	//////////////////////////////////////////////////////////////////////////////////
	//�`��
	//////////////////////////////////////////////////////////////////////////////////
	dx11Manager.Create(hwnd);


	//////////////////////////////////////////////////////////////////////////////////
	//�`��
	//////////////////////////////////////////////////////////////////////////////////
	MSG msg{};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			dx11Manager.UpdateWindow();
			dx11Manager.Render(hwnd);
		}
	}

	return msg.wParam;
}