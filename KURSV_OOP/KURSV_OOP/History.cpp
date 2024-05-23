#include "History.h"

void History::Print()
{
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement("SELECT Histories.id, Histories.date, Cars.name as Cars , NewAssemblies.name AS New,OldAssemblies.name AS Old \
            FROM Histories \
            INNER JOIN Assemblies AS NewAssemblies ON Histories.id_assembly_new = NewAssemblies.id \
            INNER JOIN Assemblies AS OldAssemblies ON Histories.id_assembly_old = OldAssemblies.id\
			INNER JOIN Cars ON Histories.id_car = Cars.id ;");
        result = pstmt->executeQuery();
        cout << "ID\t Date \t Cars\t New \t Old" << endl;
        cout << "-----------------" << endl;

        while (result->next())
        {
            cout << result->getInt("id") << "\t" << result->getString("date") << "\t" << result->getString("Cars")<< "\t" << result->getString("New") << "\t" << result->getString("Old") << endl;
        }

        delete result;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot retrieve data. Error message: " << e.what() << endl;
        system("pause");
    }
}

void History::Print(int id_car)
{
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement("SELECT Histories.id, Histories.date, NewAssemblies.name AS New,OldAssemblies.name AS Old \
            FROM Histories \
            INNER JOIN Assemblies AS NewAssemblies ON Histories.id_assembly_new = NewAssemblies.id \
            INNER JOIN Assemblies AS OldAssemblies ON Histories.id_assembly_old = OldAssemblies.id \
            WHERE Histories.id_car = ?;");
        pstmt->setInt(1, id_car);
        result = pstmt->executeQuery();
        cout << "ID\t Date \t New \t Old" << endl;
        cout << "-----------------" << endl;

        while (result->next())
        {
            cout << result->getInt("id") << "\t" << result->getString("date") << "\t" << result->getString("New")<< "\t" << result->getString("Old") << endl;
        }

        delete result;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot retrieve data. Error message: " << e.what() << endl;
        system("pause");
    }
}

void History::Print(string date)
{
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement("SELECT Histories.id, Cars.name, NewAssemblies.name AS New, OldAssemblies.name AS Old \
            FROM Histories\
            INNER JOIN Assemblies AS NewAssemblies ON Histories.id_assembly_new = NewAssemblies.id\
            INNER JOIN Assemblies AS OldAssemblies ON Histories.id_assembly_old = OldAssemblies.id\
            INNER JOIN Cars ON Histories.id_assembly_old = Cars.id\
            WHERE  Histories.date = ?;");
        pstmt->setString(1, date);
        result = pstmt->executeQuery();
        cout << "ID\t Car \t New \t Old" << endl;
        cout << "-----------------" << endl;

        while (result->next())
        {
            cout << result->getInt("id") << "\t" << result->getString("name") << "\t" << result->getString("New")<< "\t" << result->getString("Old") << endl;
        }

        delete result;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e)
    {
        cout << "Cannot retrieve data. Error message: " << e.what() << endl;
        system("pause");
    }
}
