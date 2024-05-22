// KURSV_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <iostream>
#include "ServiceWorker.h"
#include "PartStoreWorker.h"
#include "Country.h"
#include "CarBrand.h"


void for_SW()
{
	setlocale(LC_ALL, "ru");
	ServiceWorker SW;
	string name, service;
	int experience;
	int a = 1, id;
	while (a != 0)
	{
		cout << "\tРаботник Автосервиса " << endl;
		cout << " 1 - Добавить сотрудника " << endl;
		cout << " 2 - Обновить информацию о сотруднике" << endl;
		cout << " 3 - Удалить сотрудника" << endl;
		cout << " 4 - Вывести список сотрудников" << endl;
		cin >> a;
		switch (a)
		{
		case(1):
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите имя работника" << endl;
			cout << "Name ";
			getline(cin, name);
			cout << "Experience	";
			cin >> experience;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Service ";
			getline(cin, service);
			SW.Insert(name, experience, service);
			break;
		case 2:  
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите ID работника, которого хотите обновить" << endl;
			cout << "ID: ";
			cin >> id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите новое имя работника" << endl;
			cout << "Name: ";
			getline(cin, name);
			cout << "Experience: ";
			cin >> experience;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Service: ";
			getline(cin, service);
			SW.Update(id, name, experience, service);
			break;
		case 3: 
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите ID работника, которого хотите удалить" << endl;
			cout << "ID: ";
			cin >> id;
			SW.Delete(id);
			break;
		case 4:  
			system("cls");
			SW.Print();
			break;
		default:
			break;
		}
	}

}

void for_PSW()
{
	setlocale(LC_ALL, "ru");
	PartStoreWorker PSW;
	string name, number;
	int experience;
	int a = 1, id;
	while (a != 0)
	{
		cout << "\tРаботник Магазина Запчастей " << endl;
		cout << " 1 - Добавить сотрудника " << endl;
		cout << " 2 - Обновить информацию о сотруднике" << endl;
		cout << " 3 - Удалить сотрудника" << endl;
		cout << " 4 - Вывести список сотрудников" << endl;
		cin >> a;
		switch (a)
		{
		case(1):
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите имя сотрудника: ";
			getline(cin, name);
			cout << "Experience: ";
			cin >> experience;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Number phone: ";
			getline(cin, number);
			PSW.Insert(name, experience, number);
			break;
		case 2:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите ID сотрудника, которого хотите обновить: ";
			cin >> id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите новое имя сотрудника: ";
			getline(cin, name);
			cout << "Experience: ";
			cin >> experience;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Number phone: ";
			getline(cin, number);
			PSW.Update(id, name, experience, number);
			break;
		case 3:
			system("cls");
			cout << "Введите ID сотрудника, которого хотите удалить: ";
			cin >> id;
			PSW.Delete(id);
			break;
		case 4:
			system("cls");
			PSW.Print();
			break;
		default:
			break;
		}
	}
}

void for_Country()
{
	setlocale(LC_ALL, "ru");
	Country country;
	string name;
	int a = 1, id;

	while (a != 0)
	{
		cout << "\tСтраны" << endl;
		cout << " 1 - Добавить страну" << endl;
		cout << " 2 - Обновить информацию о стране" << endl;
		cout << " 3 - Удалить страну" << endl;
		cout << " 4 - Вывести список стран" << endl;
		cin >> a;
		switch (a)
		{
		case(1):
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите имя страны: ";
			getline(cin, name);
			country.Insert(name);
			break;
		case 2:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите ID страны, которую хотите обновить: ";
			cin >> id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите новое имя страны: ";
			getline(cin, name);
			country.Update(id, name);
			break;
		case 3:
			system("cls");
			cout << "Введите ID страны, которую хотите удалить: ";
			cin >> id;
			country.Delete(id);
			break;
		case 4:
			system("cls");
			country.Print();
			break;
		default:
			break;
		}
	}
}

void for_CarBrand()
{
	setlocale(LC_ALL, "ru");
	CarBrand carBrand;
	Country country;
	string name;
	int id_country;
	int a = 1, id;

	while (a != 0)
	{
		cout << "\tМарки автомобилей" << endl;
		cout << " 1 - Добавить марку автомобиля" << endl;
		cout << " 2 - Обновить информацию о марке автомобиля" << endl;
		cout << " 3 - Удалить марку автомобиля" << endl;
		cout << " 4 - Вывести список марок автомобилей" << endl;
		cin >> a;
		switch (a)
		{
		case(1):
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите имя марки автомобиля: ";
			getline(cin, name);
			cout << "Список стран:" << endl;
			country.Print();
			cout << "Введите ID страны: ";
			cin >> id_country;
			carBrand.Insert(name, id_country);
			break;
		case 2:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите ID марки автомобиля, которую хотите обновить: ";
			cin >> id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите новое имя марки автомобиля: ";
			getline(cin, name);
			cout << "Список стран:" << endl;
			country.Print();
			cout << "Введите ID страны: ";
			cin >> id_country;
			carBrand.Update(id, name, id_country);
			break;
		case 3:
			system("cls");
			cout << "Введите ID марки автомобиля, которую хотите удалить: ";
			cin >> id;
			carBrand.Delete(id);
			break;
		case 4:
			system("cls");
			carBrand.Print();
			break;
		default:
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	int a = 1;
	while (a != 0)
	{
		cout << "\tMENU";
		cout << "Выберите действие " << endl;
		cout << " 1 - Действия с ServiceWorker " << endl;
		cout << " 2 - Действия с PartStoreWorker " << endl;
		cout << " 3 - Действия с Country " << endl;
		cout << " 4 - Действия с CarBrand " << endl;
		cout << "exit 0" << endl;
		cin >> a;
		switch (a) {
		case(1):
			for_SW();
			break;
		case(2):
			for_PSW();
			break;
		case(3):
			for_Country();
			break;
		case(4):
			for_CarBrand();
			break;
		default:
			break;
		}

	}
   
}
