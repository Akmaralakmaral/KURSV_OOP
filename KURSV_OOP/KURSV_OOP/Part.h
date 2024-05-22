#pragma once
#include "Connect.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Part
{
private:
    vector<string> names;
    vector<int> id_PSW;
    vector<string> date;

public:
    void Insert(string name, int id_PSW, string date);
    void Update(int id, string name, int id_PSW, string date);
    void Delete(int id);
    void Print();
};

