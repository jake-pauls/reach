#pragma once

namespace pillar
{
	class App
	{
	public:
		App() = default;
		virtual ~App() = default;

		virtual void Init();
		virtual void Update();
		virtual void Teardown();
	};
}