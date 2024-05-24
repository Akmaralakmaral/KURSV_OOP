#pragma once
#include "Connect.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Assembly
{
private:
    vector<string> names;
    vector<string> date;
    vector<int> id_SW;
public:
    void Insert(string name, string date, int id_SW);
    void Update(int id, string name, string date, int id_SW);
    void Delete(int id);
    void Print();
};

