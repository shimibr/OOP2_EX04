#include "Controller.h"
#include <iostream>

int main()
{
	Controller controller;
	try
	{
		controller.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "An unknown error occurred." << std::endl;
		return 1;
	}
	return 0;
}
