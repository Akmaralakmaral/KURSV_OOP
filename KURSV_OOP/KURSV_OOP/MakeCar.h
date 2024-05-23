#pragma once
#include<iostream>
#include<vector>
#include"Connect.h"
class MakeCar
{
public:
	void Print(int id_car);

	void Print(float id_assem);
	void Insert(int id_car, int id_assem,int quantity);
	void Update(int id, int id_assem,int quantity);
	void Delete(int id);


};

