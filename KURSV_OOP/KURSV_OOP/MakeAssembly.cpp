#include "MakeAssembly.h"

void MakeAssembly::Insert(int id_nameAssembly, int id_part, int quantity_part, int id_component, int quantity_component)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO MakeAssemblies (id_nameAssembly, id_part, quantity_part, id_component, quantity_component) VALUES(?, ?, ?, ?, ?)");
        pstmt->setInt(1, id_nameAssembly);
        pstmt->setInt(2, id_part);
        pstmt->setInt(3, quantity_part);
        pstmt->setInt(4, id_component);
        pstmt->setInt(5, quantity_component);
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

void MakeAssembly::Update(int id, int id_nameAssembly, int id_part, int quantity_part, int id_component, int quantity_component)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "UPDATE MakeAssemblies SET id_nameAssembly = ?, id_part = ?, quantity_part = ?, id_component = ?, quantity_component = ? WHERE id = ?");
        pstmt->setInt(1, id_nameAssembly);
        pstmt->setInt(2, id_part);
        pstmt->setInt(3, quantity_part);
        pstmt->setInt(4, id_component);
        pstmt->setInt(5, quantity_component);
        pstmt->setInt(6, id);
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

void MakeAssembly::Delete(int id)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM MakeAssemblies WHERE id = ?");
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

void MakeAssembly::Print()
{
    try {
        sql::Connection* con = ConectDB();
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery(
            "SELECT MakeAssemblies.id, Assemblies.name AS assembly_name, Parts.name AS part_name, MakeAssemblies.quantity_part, "
            "Components.name AS component_name, MakeAssemblies.quantity_component "
            "FROM MakeAssemblies "
            "INNER JOIN Assemblies ON MakeAssemblies.id_nameAssembly = Assemblies.id "
            "INNER JOIN Parts ON MakeAssemblies.id_part = Parts.id "
            "INNER JOIN Components ON MakeAssemblies.id_component = Components.id");

        cout << "ID\tAssembly\tPart\tQuantity Part\tComponent\tQuantity Component" << endl;
        cout << "------------------------------------------------------------------------------" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t";
            cout << res->getString("assembly_name") << "\t";
            cout << res->getString("part_name") << "\t";
            cout << res->getInt("quantity_part") << "\t\t";
            cout << res->getString("component_name") << "\t";
            cout << res->getInt("quantity_component") << endl;
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
