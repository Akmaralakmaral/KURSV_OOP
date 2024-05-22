#include "PartStoreWorker.h"

void PartStoreWorker::Insert(string name, int experience, string number)
{
	try {
		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		con = ConectDB();
		pstmt = con->prepareStatement("INSERT INTO PartStoreWorkers (name, experience, number) VALUES(?, ?, ?)");
		pstmt->setString(1, name);
		pstmt->setInt(2, experience);
		pstmt->setString(3, number);
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

void PartStoreWorker::Update(int id, string name, int experience, string number)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	try
	{
		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE PartStoreWorkers SET name = ?, experience = ?, number = ? WHERE id = ?");
		pstmt->setString(1, name);
		pstmt->setInt(2, experience);
		pstmt->setString(3, number);
		pstmt->setInt(4, id);
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

void PartStoreWorker::Delete(int id)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	try
	{
		con = ConectDB();
		pstmt = con->prepareStatement("DELETE FROM PartStoreWorkers WHERE id = ?");
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

void PartStoreWorker::Print()
{
	sql::Statement* stmt;
	sql::ResultSet* res;
	sql::Connection* con;
	try
	{
		con = ConectDB();
		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT * FROM PartStoreWorkers");

		cout << "ID\tName\tExperience\tNumber" << endl;
		cout << "---------------------------------" << endl;

		while (res->next())
		{
			cout << res->getInt("id") << "\t";
			cout << res->getString("name") << "\t\t";
			cout << res->getInt("experience") << "\t";
			cout << res->getString("number") << endl;
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

int PartStoreWorker::Check()
{
	return 0;
}

void PartStoreWorker::Print_by_id(int id)
{
}

int PartStoreWorker::Get_id()
{
	return 0;
}
