// KURSV_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <iostream>
#include "ServiceWorker.h"



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


int main()
{
	setlocale(LC_ALL, "ru");

	int a = 1;
	while (a != 0)
	{

		cout << "\tMENU";
		cout << "Выберите действие " << endl;
		cout << " 1 - Действия с ServiceWorker " << endl;
		cout << "Действия с Продуктами введите 2 " << endl;
		cout << "Действия с Меню введите 3 " << endl;
		cout << "exit 0" << endl;
		cin >> a;
		switch (a) {
		case(1):
			for_SW();
			break;
		case(2):
			

			break;
		case(3):
			
			break;

		}

	}
   
}
