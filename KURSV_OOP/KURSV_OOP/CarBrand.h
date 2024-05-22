#pragma once
#include "Connect.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CarBrand
{
private:
    vector<string> names;
    vector<int> id_country;
public:
    void Insert(string name, int id_country);
    void Update(int id, string name, int id_country);
    void Delete(int id);
    void Print();
};

