#pragma once
#include "Connect.h"
#include "User.h"
#include <iostream>
#include <vector>
class PartStoreWorker : public Users
{
private:
	vector<string> number;
public:
	void Insert(string name, int experience, string number);
	void Update(int id, string name, int experience, string number);	
	void Delete(int id);
	void Print();
};


