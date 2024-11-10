#pragma once

#include <Pillar/App.h>

namespace autumn
{
	class App : public pillar::App
	{
	public:
		App() = default;
		~App() override = default;

		void Init() override;
		void Update() override;
		void Teardown() override;
	};
}
