#pragma once
#include "Item.h"

class Inventory
{		
public:
	Inventory();
	~Inventory();
	std::vector<Item*> items;

	bool HasItem(std::string aId);			// Returns true if item with ID exists
	void Put(Item* aItm);					// Adds new item to front of invetory
	Item* Take(std::string aId);			// Returns item from invetory, also deletes item.
	Item* Fetch(std::string aId);			// Returns copy of item
	std::string ItemList();					// Returns a string with a lits of all items
};