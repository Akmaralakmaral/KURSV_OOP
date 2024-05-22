#pragma once
#include "Connect.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Manufacturer
{
private:
    vector<string> names;
    vector<int> id_country;
    vector<string> date;
public:
    void Insert(string name, int id_country, string date);
    void Update(int id, string name, int id_country, string date);
    void Delete(int id);
    void Print();
};
