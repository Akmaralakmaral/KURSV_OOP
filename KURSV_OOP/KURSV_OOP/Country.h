#pragma once
#include "Connect.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Country
{
private:
	vector<string> name;
public:
	void Insert(string name);
	void Update(int id, string name);	
	void Delete(int id);	
	void Print();	
};
