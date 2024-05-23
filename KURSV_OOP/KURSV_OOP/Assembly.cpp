#include "Assembly.h"

void Assembly::Insert(string name, string date, int id_SW)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO Assemblies (name, date, id_SW) VALUES(?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setString(2, date);
        pstmt->setInt(3, id_SW);
        pstmt->execute();
        cout << "Saved" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Cannot Insert. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Assembly::Update(int id, string name, string date, int id_SW)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "UPDATE Assemblies SET name = ?, date = ?, id_SW = ? WHERE id = ?");
        pstmt->setString(1, name);
        pstmt->setString(2, date);
        pstmt->setInt(3, id_SW);
        pstmt->setInt(4, id);
        pstmt->execute();
        cout << "Updated" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Cannot Update. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Assembly::Delete(int id)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Assemblies WHERE id = ?");
        pstmt->setInt(1, id);
        pstmt->execute();
        cout << "Deleted" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Cannot Delete. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Assembly::Print()
{
    try {
        sql::Connection* con = ConectDB();
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery(
            "SELECT Assemblies.id, Assemblies.name, Assemblies.date, "
            "ServiceWorkers.name AS sw_name "
            "FROM Assemblies "
            "INNER JOIN ServiceWorkers ON Assemblies.id_SW = ServiceWorkers.id ");

        cout << "ID\tName\tDate\tServiceWorker\tCar" << endl;
        cout << "--------------------------------------------------------" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t";
            cout << res->getString("name") << "\t";
            cout << res->getString("date") << "\t";
            cout << res->getString("sw_name") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Cannot retrieve data. Error message: " << e.what() << endl;
        system("pause");
    }
}
