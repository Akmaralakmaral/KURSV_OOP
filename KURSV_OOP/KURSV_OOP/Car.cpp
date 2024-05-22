#include "Car.h"

void Car::Insert(string name, int id_carBrand, int id_manufacturer, int id_SW, string date)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Cars (name, id_carBrand, id_manufacturer, id_SW, date) VALUES(?, ?, ?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setInt(2, id_carBrand);
        pstmt->setInt(3, id_manufacturer);
        pstmt->setInt(4, id_SW);
        pstmt->setString(5, date);
        pstmt->execute();
        cout << "Saved" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e) {
        cout << "Cannot Insert. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Car::Update(int id, string name, int id_carBrand, int id_manufacturer, int id_SW, string date)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Cars SET name = ?, id_carBrand = ?, id_manufacturer = ?, id_SW = ?, date = ? WHERE id = ?");
        pstmt->setString(1, name);
        pstmt->setInt(2, id_carBrand);
        pstmt->setInt(3, id_manufacturer);
        pstmt->setInt(4, id_SW);
        pstmt->setString(5, date);
        pstmt->setInt(6, id);
        pstmt->execute();
        cout << "Updated" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e) {
        cout << "Cannot Update. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Car::Delete(int id)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Cars WHERE id = ?");
        pstmt->setInt(1, id);
        pstmt->execute();
        cout << "Deleted" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e) {
        cout << "Cannot Delete. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Car::Print()
{
    try {
        sql::Connection* con = ConectDB();
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery(
            "SELECT Cars.id, Cars.name, CarBrands.name as carBrand_name, Manufacturers.name as manufacturer_name, ServiceWorkers.name as serviceWorker_name, Cars.date "
            "FROM Cars "
            "INNER JOIN CarBrands ON Cars.id_carBrand = CarBrands.id "
            "INNER JOIN Manufacturers ON Cars.id_manufacturer = Manufacturers.id "
            "INNER JOIN ServiceWorkers ON Cars.id_SW = ServiceWorkers.id");

        cout << "ID\tName\tCarBrand\tManufacturer\tServiceWorker\tDate" << endl;
        cout << "---------------------------------------------------------------------" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t";
            cout << res->getString("name") << "\t";
            cout << res->getString("carBrand_name") << "\t\t";
            cout << res->getString("manufacturer_name") << "\t\t";
            cout << res->getString("serviceWorker_name") << "\t\t";
            cout << res->getString("date") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException e) {
        cout << "Cannot retrieve data. Error message: " << e.what() << endl;
        system("pause");
    }
}

template<typename T>
void Car::Search(T value, const string& columnName)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "SELECT Cars.id, Cars.name, CarBrands.name as carBrand_name, Manufacturers.name as manufacturer_name, ServiceWorkers.name as serviceWorker_name, Cars.date "
            "FROM Cars "
            "INNER JOIN CarBrands ON Cars.id_carBrand = CarBrands.id "
            "INNER JOIN Manufacturers ON Cars.id_manufacturer = Manufacturers.id "
            "INNER JOIN ServiceWorkers ON Cars.id_SW = ServiceWorkers.id "
            "WHERE Cars." + columnName + " = ?");

        if constexpr (is_same<T, int>::value) {
            pstmt->setInt(1, value);
        }
        else if constexpr (is_same<T, string>::value) {
            pstmt->setString(1, value);
        }

        sql::ResultSet* res = pstmt->executeQuery();
        bool found = false;

        while (res->next()) {
            found = true;
            cout << "ID: " << res->getInt("id") << endl;
            cout << "Name: " << res->getString("name") << endl;
            cout << "CarBrand: " << res->getString("carBrand_name") << endl;
            cout << "Manufacturer: " << res->getString("manufacturer_name") << endl;
            cout << "ServiceWorker: " << res->getString("serviceWorker_name") << endl;
            cout << "Date: " << res->getString("date") << endl;
            cout << "---------------------------------" << endl;
        }

        if (!found) {
            cout << "No cars found with the " << columnName << " " << value << "." << endl;
        }

        delete res;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e) {
        cout << "Cannot retrieve data. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Car::SearchById(int id)
{
    Search(id, "id");
}

void Car::SearchByName(string name)
{
    Search(name, "name");
}
