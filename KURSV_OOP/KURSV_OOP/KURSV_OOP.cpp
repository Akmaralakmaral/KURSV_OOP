// KURSV_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <iostream>
#include "ServiceWorker.h"
#include "PartStoreWorker.h"
#include "Country.h"
#include "CarBrand.h"
#include "Manufacturer.h"
#include "Car.h"
#include "Part.h"
#include "Component.h"


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

void for_Manufacturer()
{
	setlocale(LC_ALL, "ru");
	Manufacturer manufacturer;
	Country country;
	string name, date;
	int id_country;
	int a = 1, id;

	while (a != 0)
	{
		cout << "\tПроизводители" << endl;
		cout << " 1 - Добавить производителя" << endl;
		cout << " 2 - Обновить информацию о производителе" << endl;
		cout << " 3 - Удалить производителя" << endl;
		cout << " 4 - Вывести список производителей" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Список стран:" << endl;
			country.Print(); // Print the list of countries
			cout << "Введите имя производителя: ";
			getline(cin, name);
			cout << "Введите ID страны: ";
			cin >> id_country;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите дату: ";
			getline(cin, date);
			manufacturer.Insert(name, id_country, date);
			break;
		case 2:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите ID производителя, которого хотите обновить: ";
			cin >> id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Список стран:" << endl;
			country.Print(); // Print the list of countries
			cout << "Введите новое имя производителя: ";
			getline(cin, name);
			cout << "Введите ID страны: ";
			cin >> id_country;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите новую дату: ";
			getline(cin, date);
			manufacturer.Update(id, name, id_country, date);
			break;
		case 3:
			system("cls");
			cout << "Введите ID производителя, которого хотите удалить: ";
			cin >> id;
			manufacturer.Delete(id);
			break;
		case 4:
			system("cls");
			manufacturer.Print();
			break;
		default:
			break;
		}
	}
}

void for_Car()
{
	Car car;
	Manufacturer manufacturer;
	CarBrand carBrand;
	ServiceWorker SW;
	int choice;
	string name, date;
	int id, id_carBrand, id_manufacturer, id_SW;

	while (true)
	{
		cout << "\nМеню для работы с машинами:" << endl;
		cout << "1. Добавить машину" << endl;
		cout << "2. Обновить информацию о машине" << endl;
		cout << "3. Удалить машину" << endl;
		cout << "4. Вывести список машин" << endl;
		cout << "5. Поиск машины по ID" << endl;
		cout << "6. Поиск машины по имени" << endl;
		cout << "0. Выйти" << endl;

		cout << "\nВыберите действие: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите имя машины: ";
			getline(cin, name);
			cout << "Список брендов:" << endl;
			carBrand.Print();
			cout << "Введите ID марки автомобиля: ";
			cin >> id_carBrand;
			cout << "Список производителей:" << endl;
			manufacturer.Print();
			cout << "Введите ID производителя: ";
			cin >> id_manufacturer;
			cout << "Список сотрудников:" << endl;
			SW.Print();
			cout << "Введите ID сотрудника, ответственного за обслуживание: ";
			cin >> id_SW;
			cout << "Введите дату: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, date);
			car.Insert(name, id_carBrand, id_manufacturer, id_SW, date);
			break;
		case 2:
			system("cls");
			cout << "Введите ID машины, которую хотите обновить: ";
			cin >> id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите новое имя машины: ";
			getline(cin, name);
			cout << "Список брендов:" << endl;
			carBrand.Print();
			cout << "Введите новый ID марки автомобиля: ";
			cin >> id_carBrand;
			cout << "Список производителей:" << endl;
			manufacturer.Print();
			cout << "Введите новый ID производителя: ";
			cin >> id_manufacturer;
			cout << "Список сотрудников:" << endl;
			SW.Print();
			cout << "Введите новый ID сотрудника, ответственного за обслуживание: ";
			cin >> id_SW;
			cout << "Введите новую дату: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, date);
			car.Update(id, name, id_carBrand, id_manufacturer, id_SW, date);
			break;
		case 3:
			system("cls");
			cout << "Введите ID машины, которую хотите удалить: ";
			cin >> id;
			car.Delete(id);
			break;
		case 4:
			system("cls");
			cout << "Список машин:" << endl;
			car.Print();
			break;
		case 5:
			system("cls");
			cout << "Введите ID машины для поиска: ";
			cin >> id;
			car.SearchById(id);
			break;
		case 6:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите имя машины для поиска: ";
			getline(cin, name);
			car.SearchByName(name);
			break;
		case 0:
			return;
		default:
			cout << "Некорректный выбор. Попробуйте снова." << endl;
			break;
		}
	}
}

void for_Part()
{
	setlocale(LC_ALL, "ru");
	Part part;
	PartStoreWorker partStoreWorker;
	string name, date;
	int id_PSW;
	int a = 1, id;

	while (a != 0)
	{
		cout << "\tДетали" << endl;
		cout << " 1 - Добавить деталь" << endl;
		cout << " 2 - Обновить информацию о детали" << endl;
		cout << " 3 - Удалить деталь" << endl;
		cout << " 4 - Вывести список деталей" << endl;
		cin >> a;
		switch (a)
		{
		case(1):
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите название детали: ";
			getline(cin, name);
			cout << "Список ответственных работников магазина деталей:" << endl;
			partStoreWorker.Print();
			cout << "Введите ID ответственного работника магазина деталей: ";
			cin >> id_PSW;
			cout << "Введите дату: ";
			cin >> date;
			part.Insert(name, id_PSW, date);
			break;
		case 2:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите ID детали, которую хотите обновить: ";
			cin >> id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите новое название детали: ";
			getline(cin, name);
			cout << "Список ответственных работников магазина деталей:" << endl;
			partStoreWorker.Print();
			cout << "Введите ID ответственного работника магазина деталей: ";
			cin >> id_PSW;
			cout << "Введите новую дату: ";
			cin >> date;
			part.Update(id, name, id_PSW, date);
			break;
		case 3:
			system("cls");
			cout << "Введите ID детали, которую хотите удалить: ";
			cin >> id;
			part.Delete(id);
			break;
		case 4:
			system("cls");
			part.Print();
			break;
		default:
			break;
		}
	}
}

void for_Component()
{
	setlocale(LC_ALL, "ru");
	Component component;
	Part part;
	ServiceWorker serviceWorker;
	string name, date;
	int id_part1, id_part2, id_SW;
	int a = 1, id;

	while (a != 0)
	{
		cout << "\tКомпоненты" << endl;
		cout << " 1 - Добавить компонент" << endl;
		cout << " 2 - Обновить информацию о компоненте" << endl;
		cout << " 3 - Удалить компонент" << endl;
		cout << " 4 - Вывести список компонентов" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите имя компонента: ";
			getline(cin, name);
			cout << "Введите дату: ";
			getline(cin, date);
			cout << "Список частей:" << endl;
			part.Print();
			cout << "Введите ID первой части: ";
			cin >> id_part1;
			cout << "Введите ID второй части: ";
			cin >> id_part2;
			cout << "Список работников сервиса:" << endl;
			serviceWorker.Print();
			cout << "Введите ID работника сервиса: ";
			cin >> id_SW;
			component.Insert(name, date, id_part1, id_part2, id_SW);
			break;
		case 2:
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите ID компонента, который хотите обновить: ";
			cin >> id;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите новое имя компонента: ";
			getline(cin, name);
			cout << "Введите новую дату: ";
			getline(cin, date);
			cout << "Список частей:" << endl;
			part.Print();
			cout << "Введите ID первой части: ";
			cin >> id_part1;
			cout << "Введите ID второй части: ";
			cin >> id_part2;
			cout << "Список работников сервиса:" << endl;
			serviceWorker.Print();
			cout << "Введите ID работника сервиса: ";
			cin >> id_SW;
			component.Update(id, name, date, id_part1, id_part2, id_SW);
			break;
		case 3:
			system("cls");
			cout << "Введите ID компонента, который хотите удалить: ";
			cin >> id;
			component.Delete(id);
			break;
		case 4:
			system("cls");
			component.Print();
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
		cout << " 5 - Действия с Manufacturer " << endl;
		cout << " 6 - Действия с Car " << endl;
		cout << " 7 - Действия с Part " << endl;
		cout << " 8 - Действия с Component " << endl;
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
		case(5):
			for_Manufacturer();
			break;
		case(6):
			for_Car();
			break;
		case(7):
			for_Part();
			break;
		case(8):
			for_Component();
			break;
		default:
			break;
		}

	}
   
}
