#include "Component.h"

void Component::Insert(string name, string date, int id_part1, int id_part2, int id_SW)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO Components (name, date, id_part1, id_part2, id_SW) VALUES(?, ?, ?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setString(2, date);
        pstmt->setInt(3, id_part1);
        pstmt->setInt(4, id_part2);
        pstmt->setInt(5, id_SW);
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

void Component::Update(int id, string name, string date, int id_part1, int id_part2, int id_SW)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "UPDATE Components SET name = ?, date = ?, id_part1 = ?, id_part2 = ?, id_SW = ? WHERE id = ?");
        pstmt->setString(1, name);
        pstmt->setString(2, date);
        pstmt->setInt(3, id_part1);
        pstmt->setInt(4, id_part2);
        pstmt->setInt(5, id_SW);
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

void Component::Delete(int id)
{
    try {
        sql::Connection* con = ConectDB();
        sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Components WHERE id = ?");
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

void Component::Print()
{
    try {
        sql::Connection* con = ConectDB();
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery(
            "SELECT Components.id, Components.name, Components.date, "
            "Part1.name AS part1_name, Part2.name AS part2_name, "
            "ServiceWorkers.name AS sw_name "
            "FROM Components "
            "INNER JOIN Parts AS Part1 ON Components.id_part1 = Part1.id "
            "INNER JOIN Parts AS Part2 ON Components.id_part2 = Part2.id "
            "INNER JOIN ServiceWorkers ON Components.id_SW = ServiceWorkers.id");

        cout << "ID\tName\tDate\t\tPart1\tPart2\tServiceWorker" << endl;
        cout << "--------------------------------------------------------" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t";
            cout << res->getString("name") << "\t";
            cout << res->getString("date") << "\t";
            cout << res->getString("part1_name") << "\t";
            cout << res->getString("part2_name") << "\t";
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
