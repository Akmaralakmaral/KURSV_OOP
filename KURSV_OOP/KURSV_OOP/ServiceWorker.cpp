#include "ServiceWorker.h"

void ServiceWorker::Insert(string name, int experience, string service)
{
	try {
		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		con = ConectDB();
		pstmt = con->prepareStatement("INSERT INTO ServiceWorkers (name,experience,service) VALUES(?,?,?)");
		pstmt->setString(1, name);
		pstmt->setInt(2, experience);
		pstmt->setString(3, service);
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

void ServiceWorker::Update(int id, string name, int experience, string service)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	try
	{
		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE ServiceWorkers SET name = ?, experience = ?, service = ? WHERE id = ?");
		pstmt->setString(1, name);
		pstmt->setInt(2, experience);
		pstmt->setString(3, service);
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

void ServiceWorker::Delete(int id)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	try
	{
		con = ConectDB();
		pstmt = con->prepareStatement("DELETE FROM ServiceWorkers WHERE id = ?");
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

void ServiceWorker::Print()
{
	sql::Statement* stmt;
	sql::ResultSet* res;
	sql::Connection* con;
	try
	{
		con = ConectDB();
		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT * FROM ServiceWorkers");

		cout << "ID\tName\tExperience\tService" << endl;
		cout << "---------------------------------" << endl;

		while (res->next())
		{
			cout << res->getInt("id") << "\t";
			cout << res->getString("name") << "\t\t";
			cout << res->getInt("experience") << "\t";
			cout << res->getString("service") << endl;
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

void ServiceWorker::Print_by_id(int id)
{

}

int ServiceWorker::Get_id()
{
	return 0;
}

int ServiceWorker::Check()
{
	return 0;
}
