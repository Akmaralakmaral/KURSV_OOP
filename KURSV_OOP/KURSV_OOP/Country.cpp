#include "Country.h"

void Country::Insert(string name)
{
    try {
        sql::PreparedStatement* pstmt;
        sql::Connection* con;
        con = ConectDB();
        pstmt = con->prepareStatement("INSERT INTO Countries (name) VALUES(?)");
        pstmt->setString(1, name);
        pstmt->execute();
        cout << "Saved" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot Insert. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Country::Update(int id, string name)
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement("UPDATE Countries SET name = ? WHERE id = ?");
        pstmt->setString(1, name);
        pstmt->setInt(2, id);
        pstmt->execute();
        cout << "Updated" << endl;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot Update. Error message: " << e.what() << endl;
        system("pause");
    }
}

void Country::Delete(int id)
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement("DELETE FROM Countries WHERE id = ?");
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

void Country::Print()
{
    sql::Statement* stmt;
    sql::ResultSet* res;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM Countries");

        cout << "ID\tName" << endl;
        cout << "-----------------" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t" << res->getString("name") << endl;
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
