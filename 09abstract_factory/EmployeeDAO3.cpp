//数据库访问有关的基类
class IDBConnection
{
};

class IDBCommand
{
};

class IDataReader
{
};

class IDBFactory
{
public:
    virtual IDBConnection *CreateDBConnection() = 0;
    virtual IDBCommand *CreateDBCommand() = 0;
    virtual IDataReader *CreateDataReader() = 0;
};

//支持SQL Server
class SqlConnection : public IDBConnection
{
};
class SqlCommand : public IDBCommand
{
};
class SqlDataReader : public IDataReader
{
};

class SqlDBFactory : public IDBFactory
{
public:
    virtual IDBConnection *CreateDBConnection()
    {
        return new SqlConnection();
    };
    virtual IDBCommand *CreateDBCommand();
    virtual IDataReader *CreateDataReader();
};

//支持Oracle
class OracleConnection : public IDBConnection
{
};

class OracleCommand : public IDBCommand
{
};

class OracleDataReader : public IDataReader
{
};

class EmployeeDAO
{
    IDBFactory *dbFactory;

public:
    EmployeeDAO(IDBFactory *dbFactory)
    {
        this->dbFactory = dbFactory;
    }
    vector<EmployeeDAO> GetEmployees()
    {
        IDBConnection *connection =
            dbFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand *command =
            dbFactory->CreateDBCommand();
        command->CommandText("...");
        command->SetConnection(connection); //关联性

        IDBDataReader *reader = command->ExecuteReader(); //关联性
        while (reader->Read())
        {
        }
    }
};