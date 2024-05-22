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

	virtual int Get_id() = 0;	
	virtual void Delete(int id) = 0;
	virtual int Check() = 0;
	virtual void Print() = 0;
	virtual void Print_by_id(int id) = 0;


};
