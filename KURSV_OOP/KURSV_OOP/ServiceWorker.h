#pragma once
#include "Connect.h"
#include "User.h"
#include <iostream>
#include <vector>
class ServiceWorker: public Users
{
private:
	vector<string> service;
public:
	void Insert(string name, int experience, string service);
	void Update(int id, string name, int experience, string service);
	int Get_id();
	void Delete(int id);
	int Check();
	void Print();
	void Print_by_id(int id);
};

