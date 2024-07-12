#pragma once

#include <iostream>
//#include <list>

#include "dll_t.hpp"

typedef struct
{
	int id;
	std::string name, password;
} Entry;

class Vault
{
public:
	Vault(void) : vault_(), entriesNumber_(0) {}

	int GetEntriesNumber(void) const { return entriesNumber_; }
	void IncrementEntriesNumber(int number = 1) { entriesNumber_ += number; }
	void AddEntry(Entry* newEntry) { vault_.PushBack(new dll_node_t<Entry*>(newEntry)); }

private:
	int entriesNumber_;
	dll_t<Entry*> vault_;
};