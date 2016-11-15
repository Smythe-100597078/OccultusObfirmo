#pragma once
#include "Object.h"

class Item
{

public:
	
	Item(std::string name, std::string desc, std::string idents[]);
	~Item();

	std::string FullDescription()
	{
		return fdesc;
	}
	std::string Name() { return fname; }
	bool AreYou(std::string aId);

protected:
	std::string fname;
	std::string fdesc;
	std::string identifiers[2] = { "","" };
	
};
