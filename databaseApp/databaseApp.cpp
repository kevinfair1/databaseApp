#using <mscorlib.dll>
#using <System.Data.dll>
#using <System.dll>



using namespace System;
using namespace System::Data::OleDb;

int main(void)
{
	String^ sqlstr = "SELECT * FROM [memberTable]";
	

	OleDbConnection^ conn = nullptr;
	OleDbCommand^ cmd = nullptr;

	try
	{
		conn = gcnew OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0; Data Source=member.accdb; Jet OLEDB:Database Password=123;");
		conn->Open();
		cmd = gcnew OleDbCommand(sqlstr, conn);

		OleDbDataReader^ reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
		String^ Sep = gcnew String('*', 60);

		while (reader->Read())
		{
			Console::WriteLine("ID: " + reader->GetValue(0));
			Console::WriteLine("Last Name: " + reader->GetValue(1) + "\t");
			Console::WriteLine("First Name: " + reader->GetValue(2));
			Console::WriteLine(Sep);
		}
	}
	catch (Exception^ ex)
	{
		Console::WriteLine(ex->ToString());
	}
	Console::ReadLine();
	return 0;
}