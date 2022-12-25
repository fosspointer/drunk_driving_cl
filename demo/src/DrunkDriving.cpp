#include <demo/DrunkDriving.hpp>

void demo::DrunkDriving::Start(int argc, char** argv)
{
    demo::ArgumentHandler args_handler(argc, argv, DrunkDriving::ShowUsage, {
        demo::ArgumentInitializer{ARG0, ""},
        demo::ArgumentInitializer{ARG1, "0.6"},
        demo::ArgumentInitializer{ARG2, "2.5"}
        });

    if (args_handler.HasReturned()) return;

    auto car_speed_str = args_handler.Get(ARG0);
    auto first_reaction_str = args_handler.Get(ARG1);
    auto second_reaction_str = args_handler.Get(ARG2);

    float car_speed, first_reaction, second_reaction;

    try
    {
        car_speed = std::stof(car_speed_str->second);
        first_reaction = std::stof(first_reaction_str->second);
        second_reaction = std::stof(second_reaction_str->second);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "One or more of the provided arguments is not formatted correctly!\n";
        std::cout << "This resulted in an exception of type '" << e.what() << "'\n";
        return;
    }

    std::cout << "Displacement of driver #1: " << DrunkDriving::CalculateReactionOffsetMeters(first_reaction, car_speed) << '\n';
    std::cout << "Displacement of driver #2: " << DrunkDriving::CalculateReactionOffsetMeters(second_reaction, car_speed) << '\n';
}

void demo::DrunkDriving::ShowUsage()
{
	std::cout << "Usage [0]: " << PROG_NAME << " (--help): Displays this menu\n"
		<< "Usage [1]: " << PROG_NAME << " [" << ARG0 ": float(m/s)] (" << ARG1 << ": float(s), default: 0.6) (" << ARG2 << ": float(s), default: 2.5)\n"
		<< "Example: " << PROG_NAME << ' ' << ARG0 << "=3.14 " << ARG1 << "=2.71 " << ARG2 "=1.618\n";
}

float demo::DrunkDriving::CalculateReactionOffsetMeters(float driver_reaction_s, float car_terminal_speed_mps)
{
	float displacement = car_terminal_speed_mps * driver_reaction_s;
	return displacement;
}