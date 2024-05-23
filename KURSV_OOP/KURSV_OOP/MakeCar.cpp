#include "MakeCar.h"

void MakeCar::Print(int id_car)
{
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement(" SELECT MakeCars.id, MakeCars.id_car, Assemblies.name, MakeCars.quantity \
                                        FROM MakeCars \
                                        INNER JOIN Assemblies ON MakeCars.id_assembly = Assemblies.id \
                                        WHERE id_car = ?;");
        pstmt->setInt(1, id_car);
        result = pstmt->executeQuery();
        cout << "ID\tName\tQunatity" << endl;
        cout << "-----------------" << endl;

        while (result->next())
        {
            cout << result->getInt("id") << "\t" << result->getString("name")<<"\t"<< result->getString("quantity") << endl;
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

void MakeCar::Print(float id_assem)
{
    sql::PreparedStatement* pstmt;
    sql::ResultSet* result;
    sql::Connection* con;
    try
    {
        con = ConectDB();
        pstmt = con->prepareStatement(" SELECT MakeCars.id, Cars.name, MakeCars.quantity \
            FROM MakeCars \
            INNER JOIN Cars ON MakeCars.id_car = Cars.id \
            WHERE id_assembly = ?;");
        pstmt->setInt(1, id_assem);
        result = pstmt->executeQuery();
        cout << "ID\tName\tQunatity" << endl;
        cout << "-----------------" << endl;

        while (result->next())
        {
            cout << result->getInt("id") << "\t" << result->getString("name") << "\t" << result->getString("quantity") << endl;
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

void MakeCar::Insert(int id_car, int id_assem, int quantity)
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con;

    con = ConectDB();
    pstmt = con->prepareStatement("INSERT INTO MakeCars(id_car, id_assembly, quantity) VALUES (?,?,?)");
    pstmt->setInt(1, id_car);
    pstmt->setInt(2, id_assem);
    pstmt->setInt(3, quantity);
    pstmt->execute();
    cout << "Saved" << endl;
    delete pstmt;
    delete con;
}

void MakeCar::Update(int id, int id_assem, int quantity)
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con;
    sql::ResultSet* result;
    con = ConectDB();
    int old_id_assem;
    int id_car;

    pstmt = con->prepareStatement("Select id_assembly ,id_car from MakeCars where id=?");
    pstmt->setInt(1, id);
    result = pstmt->executeQuery();
    if (result->next())
    {
        old_id_assem = result->getInt("id_assembly"); 
        id_car = result->getInt("id_car"); 
        cout << old_id_assem << "    " << id_assem;
    }



    pstmt = con->prepareStatement("UPDATE MakeCars SET id_assembly=?,quantity=? WHERE id = ?");
    pstmt->setInt(1, id_assem);
    pstmt->setInt(2, quantity);
    pstmt->setInt(3, id);
    pstmt->execute();
    cout << "Updated" << endl;

    if (old_id_assem != id_assem) {
        
        pstmt = con->prepareStatement("INSERT INTO Histories(date, id_assembly_new, id_assembly_old, id_car) VALUES (NOW(), ?, ?, ?)");
        pstmt->setInt(1, id_assem);
        pstmt->setInt(2, old_id_assem);
        pstmt->setInt(3, id_car);
        pstmt->execute();

      
    }

    delete pstmt;
    delete con;
    delete result;

}

void MakeCar::Delete(int id)
{
    sql::PreparedStatement* pstmt;
    sql::Connection* con;

    con = ConectDB();
    pstmt = con->prepareStatement("delete from MakeCars where id=?");
    pstmt->setInt(1, id);
   
    pstmt->execute();
    cout << "Deleted" << endl;
    delete pstmt;
    delete con;
}


