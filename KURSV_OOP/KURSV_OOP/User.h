#pragma once
#include  <iostream>
#include <iostream>
#include <vector>
using namespace std;
class Users
{
protected:
	vector<int> id;
	vector<string> name;
	vector<int> experience;
public:	

	virtual void Delete(int id) = 0;	
	virtual void Print() = 0;
};
