#include <demo/ArgumentHandler.hpp>
#include <iostream>

void demo::ArgumentHandler::Return()
{
	m_ReturnCallback();
	m_HasReturned = true;
}

demo::ArgumentHandler::ArgumentHandler(int argc, char** argv, const ReturnCallbackFunction& return_callback, const ArgumentList& arguments)
	:m_Arguments(), m_ReturnCallback(return_callback), m_HasReturned(false)
{
	for (int i = 1; i < argc; i++) 
	{
		std::string argument = argv[i];

		if(argument == "--help")
		{
			Return();
			return;
		}

		size_t find_index = argument.find_first_of('=');
		if (argument[0] != '-' || find_index == std::string::npos)
		{
			std::cout << "Incorrect formatting!\n";
			Return();
			return;
		}

		std::string key = argument.substr(0, find_index);
		argument.erase(0, find_index + 1);
		m_Arguments[key] = argument;
	}

	for (const auto& argument_test : arguments)
	{
		auto find = Get(argument_test.Name);
		
		if (find != End()) continue;
		else if (argument_test.DefaultValue != "")
		{
			m_Arguments[argument_test.Name] = argument_test.DefaultValue;
			continue;
		}
		else
		{
			std::cout << "Argument " << argument_test.Name << " is required but was not provided!\n";
			Return();
			return;
		}
	}

	for(const auto& argument : m_Arguments)
	{
		std::cout << argument.first << ": " << argument.second << '\n';
	}
}