#pragma once
#include "stdafx.h"

class Error
{
public:
	Error() {};

	static void Display(std::string aMsg)
	{
		system("color 04");
		std::cout << aMsg << std::endl;
		exit(1);
	}
};