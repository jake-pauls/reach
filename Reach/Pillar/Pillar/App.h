#pragma once

namespace pillar
{
#ifdef WIN32
	class DX11Renderer;
#endif

	class App
	{
	public:
		App() = default;
		virtual ~App() = default;

		virtual void Init();
		virtual void Update();
		void Draw();
		virtual void Teardown();

	private:
#ifdef WIN32
		DX11Renderer* m_Renderer;
#endif
	};
}