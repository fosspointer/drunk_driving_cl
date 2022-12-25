#pragma once
#include <string>
#include <unordered_map>
#include <functional>

namespace demo
{
	struct ArgumentInitializer 
	{
		std::string Name;
		std::string DefaultValue = "";
	};

	using ArgumentMap = std::unordered_map<std::string, std::string>;
	using ArgumentList = std::initializer_list<ArgumentInitializer>;
	using ReturnCallbackFunction = std::function<void()>;

	class ArgumentHandler
	{
	public:
		ArgumentHandler(int argc, char** argv, const ReturnCallbackFunction& return_callback, const ArgumentList& arguments);
		inline const ArgumentMap::const_iterator Get(const std::string& argument_name) const { return m_Arguments.find(argument_name); }
		inline const ArgumentMap::const_iterator End() const { return m_Arguments.end(); }
		inline const bool& HasReturned() const { return m_HasReturned; }
	private:
		void Return();
		bool m_HasReturned;
		ArgumentMap m_Arguments;
		ReturnCallbackFunction m_ReturnCallback;
	};
}