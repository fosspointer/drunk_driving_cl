#pragma once
#include <iostream>
#include <demo/ArgumentHandler.hpp>

namespace demo
{
	class DrunkDriving
	{
	public:
		static void Start(int argc, char** argv);
		static void ShowUsage();
	private:
		static float CalculateReactionOffsetMeters(float driver_reaction_s, float car_terminal_speed_mps);
	};
}