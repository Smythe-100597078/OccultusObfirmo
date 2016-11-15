#include "stdafx.h"
#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

bool Inventory::HasItem(std::string aId)
{
	bool result = false;

	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->AreYou(aId))
		{
			result = true;
			break;
		}
		else
		{
			result = false;
		}
	}

	return result;
}

void Inventory::Put(Item* aItm)
{
	items.push_back(aItm);
}

Item* Inventory::Take(std::string aId)
{
	Item* result = NULL;

	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->AreYou(aId))
		{
			result = items[i];
			items.erase(items.begin() + i);
			break;
		}
	}
	return result;
}

Item* Inventory::Fetch(std::string aId)
{
	Item* result = NULL;

	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (items[i]->AreYou(aId))
		{
			result = items[i];
			break;
		}
	}
	return result;
}

std::string Inventory::ItemList()
{
	std::string result = "";

	for (unsigned int i = 0; i < items.size(); i++)
	{
		result += items[i]->Name()+ " : " + items[i]->FullDescription() + "\n";
	}
	return result;
}
