#include "stdafx.h"
#include "Item.h"


Item::Item(std::string name, std::string desc, std::string idents[])
{
	fname = name;
	fdesc = desc;
	identifiers[0] = idents[0];
	identifiers[1] = idents[1];
}

Item::~Item()
{
}


bool Item::AreYou(std::string aId)
{
	bool result = false;
	std::string* temp = identifiers;

	for (int i = 0; i < 2; i++)
	{
		transform(temp[i].begin(), temp[i].end(), temp[i].begin(), tolower);
	}
	transform(aId.begin(), aId.end(), aId.begin(), tolower);

	for (int i = 0; i < 2; i++)
	{
		if (aId == temp[i])
		{
			result = true;
			break;
		}
	}

	return result;
}
