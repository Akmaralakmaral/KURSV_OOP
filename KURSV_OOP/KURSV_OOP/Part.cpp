#include "Part.h"

void Part::Insert(string name, int id_PSW, string date)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Parts (name, id_PSW, date) VALUES(?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setInt(2, id_PSW);
        pstmt->setString(3, date);
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

void Part::Update(int id, string name, int id_PSW, string date)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Parts SET name = ?, id_PSW = ?, date = ? WHERE id = ?");
        pstmt->setString(1, name);
        pstmt->setInt(2, id_PSW);
        pstmt->setString(3, date);
        pstmt->setInt(4, id);
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

void Part::Delete(int id)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Parts WHERE id = ?");
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

void Part::Print()
{
    try {
        sql::Connection* con = ConectDB();
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery(
            "SELECT Parts.id, Parts.name, PartStoreWorkers.name AS psw_name, Parts.date "
            "FROM Parts "
            "INNER JOIN PartStoreWorkers ON Parts.id_PSW = PartStoreWorkers.id");

        cout << "ID\tName\tPSW Name\tDate" << endl;
        cout << "---------------------------------" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t";
            cout << res->getString("name") << "\t\t";
            cout << res->getString("psw_name") << "\t";
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
