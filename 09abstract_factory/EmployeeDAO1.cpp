class EmployeeDAO
{
public:
    vector<EmployeeDAO> GetEmployees()
    {
        SqlConnection *connection = new SqlConnection();
        connection->ConnectionString("...");

        SqlCommond *commond = new SqlCommond();
        commond->CommondText("...");
        commond->SetConnection(connection); //关联

        SqlDataReader *reader = command->ExecuteReader();
        while (reader->Read())
        {
        }
    }
};