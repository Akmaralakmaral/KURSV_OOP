#pragma once
#include "Connect.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class MakeAssembly
{
private:
    vector<int> id_nameAssembly;
    vector<int> id_part;
    vector<int> quantity_part;    
    vector<int> id_component;
    vector<int> quantity_component;

public:
    void Insert(int id_nameAssembly, int id_part, int quantity_part, int id_component, int quantity_component);
    void Update(int id, int id_nameAssembly, int id_part, int quantity_part, int id_component, int quantity_component);
    void Delete(int id);
    void Print();
};


