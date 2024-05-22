#include "CarBrand.h"

void CarBrand::Insert(string name, int id_country)
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
            pstmt = con->prepareStatement("INSERT INTO CarBrands (name, id_country) VALUES(?, ?)");
            pstmt->setString(1, name);
            pstmt->setInt(2, id_country);
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

void CarBrand::Update(int id, string name, int id_country)
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
            pstmt = con->prepareStatement("UPDATE CarBrands SET name = ?, id_country = ? WHERE id = ?");
            pstmt->setString(1, name);
            pstmt->setInt(2, id_country);
            pstmt->setInt(3, id);
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

void CarBrand::Delete(int id)
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement("DELETE FROM CarBrands WHERE id = ?");
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

void CarBrand::Print()
{
    sql::Statement* stmt;
    sql::ResultSet* res;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        stmt = con->createStatement();
        res = stmt->executeQuery(
            "SELECT CarBrands.id, CarBrands.name, Countries.name as country_name "
            "FROM CarBrands "
            "INNER JOIN Countries ON CarBrands.id_country = Countries.id");

        cout << "ID\tName\tCountry" << endl;
        cout << "----------------------" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t";
            cout << res->getString("name") << "\t";
            cout << res->getString("country_name") << endl;
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
