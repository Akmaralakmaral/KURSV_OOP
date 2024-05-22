#include "Manufacturer.h"

void Manufacturer::Insert(string name, int id_country, string date)
{
    try {
        sql::PreparedStatement* pstmt;
        sql::Connection* con;
        con = ConectDB();

        // Ensure the country exists in the Countries table
        sql::PreparedStatement* pstmtCheck;
        pstmtCheck = con->prepareStatement("SELECT COUNT(*) FROM Countries WHERE id = ?");
        pstmtCheck->setInt(1, id_country);
        sql::ResultSet* res = pstmtCheck->executeQuery();

        if (res->next() && res->getInt(1) > 0) {
            pstmt = con->prepareStatement("INSERT INTO Manufacturers (name, id_country, date) VALUES(?, ?, ?)");
            pstmt->setString(1, name);
            pstmt->setInt(2, id_country);
            pstmt->setString(3, date);
            pstmt->execute();
            cout << "Saved" << endl;
            delete pstmt;
        }
        else {
            cout << "Cannot Insert. Country does not exist." << endl;
        }

        delete pstmtCheck;
        delete res;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot Insert. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Manufacturer::Update(int id, string name, int id_country, string date)
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con;
    try
    {
        con = ConectDB();

        // Ensure the country exists in the Countries table
        sql::PreparedStatement* pstmtCheck;
        pstmtCheck = con->prepareStatement("SELECT COUNT(*) FROM Countries WHERE id = ?");
        pstmtCheck->setInt(1, id_country);
        sql::ResultSet* res = pstmtCheck->executeQuery();

        if (res->next() && res->getInt(1) > 0) {
            pstmt = con->prepareStatement("UPDATE Manufacturers SET name = ?, id_country = ?, date = ? WHERE id = ?");
            pstmt->setString(1, name);
            pstmt->setInt(2, id_country);
            pstmt->setString(3, date);
            pstmt->setInt(4, id);
            pstmt->execute();
            cout << "Updated" << endl;
            delete pstmt;
        }
        else {
            cout << "Cannot Update. Country does not exist." << endl;
        }

        delete pstmtCheck;
        delete res;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot Update. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Manufacturer::Delete(int id)
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement("DELETE FROM Manufacturers WHERE id = ?");
        pstmt->setInt(1, id);
        pstmt->execute();
        cout << "Deleted" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot Delete. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Manufacturer::Print()
{
    sql::Statement* stmt;
    sql::ResultSet* res;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        stmt = con->createStatement();
        res = stmt->executeQuery(
            "SELECT Manufacturers.id, Manufacturers.name, Countries.name as country_name, Manufacturers.date "
            "FROM Manufacturers "
            "INNER JOIN Countries ON Manufacturers.id_country = Countries.id");

        cout << "ID\tName\tCountry\t\tDate" << endl;
        cout << "-------------------------------------" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t";
            cout << res->getString("name") << "\t";
            cout << res->getString("country_name") << "\t";
            cout << res->getString("date") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot retrieve data. Error message: " << e.what() << endl;
        system("pause");
    }
}
