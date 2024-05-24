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
	void Delete(int id);	
	void Print();
	
};

