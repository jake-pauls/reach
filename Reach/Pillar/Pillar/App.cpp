#include "PCH.h"
#include "App.h"

#ifdef WIN32
#include "Win32/Win32Window.h"
#include "DX11/DX11Renderer.h"
#endif

void pillar::App::Init()
{
#ifdef WIN32
	m_Renderer = new DX11Renderer();
#endif
}

void pillar::App::Update()
{
}

void pillar::App::Draw()
{
#ifdef WIN32
	m_Renderer->Draw();
#endif
}

void pillar::App::Teardown()
{
#ifdef WIN32
	delete m_Renderer;
#endif
}
