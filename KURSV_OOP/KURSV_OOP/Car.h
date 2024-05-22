#pragma once
#include "Connect.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Car
{
private:
    vector<string> names;
    vector<int> id_carBrand;
    vector<int> id_manufacturer;
    vector<int> id_SW;
    vector<string> date;

    template<typename T>
    void Search(T value, const string& columnName);
public:
    void Insert(string name, int id_carBrand, int id_manufacturer, int id_SW, string date);
    void Update(int id, string name, int id_carBrand, int id_manufacturer, int id_SW, string date);
    void Delete(int id);
    void Print();
    void SearchById(int id);
    void SearchByName(string name);
};

