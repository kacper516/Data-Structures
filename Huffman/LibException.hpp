#pragma once

#include <iostream>
#include <exception>

namespace EXCEPTIONS
{
	class InvalidArguments : public std::runtime_error
	{
	public:
		InvalidArguments() : runtime_error("Wrong input values.") {}
		InvalidArguments(std::string msg) : runtime_error(msg.c_str()) {}
	};

	class FileOpenException : public std::runtime_error
	{
	public:
		FileOpenException() : runtime_error("We can't open the file.") {}
		FileOpenException(std::string msg) : runtime_error(msg.c_str()) {}
	};
}
