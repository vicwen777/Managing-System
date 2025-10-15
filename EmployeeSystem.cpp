#include"EmployeeSystem.h"
#include"Employee.h"
#include<iostream>
#include<string>
EmployeeSystem::EmployeeSystem()
{
	ifstream ifs;
	ifs.open(File, ios::in);
	if (!ifs.is_open() )
	{
		cout << "No Document" << endl;
		this->EmpArray = NULL;
		this->EmpNum = 0;
		this->Empty = true;
		ifs.close();
		return;
	}//文件不存在
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout<< "File is Empty" << endl;
		this->EmpNum = 0;
		this->Empty = true;
		this->EmpArray = NULL;
		ifs.close();
		return;
	}//文件不存在
	int num = this->GetNum();
	this->EmpNum = num;//导入员工数量
	this->EmpArray = new Employee * [this->EmpNum];//开辟空间
	this->InitEmp();
}
void EmployeeSystem::InitEmp() 
{
	ifstream ifs;
	ifs.open(File, ios::in);
	long id;
	string name;
	char gender;
	long phone;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> gender && ifs >> phone)
	{
		Employee* emp = new Employee(id,name,gender,phone);
		this->EmpArray[index] = emp;
		index++;
	}//逐一对员工元素赋值
	ifs.close();
}//初始化员工人数及数组
long EmployeeSystem::Exist(long id) 
{
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++)
	{
		if (this->EmpArray[i]->Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}//判断编号是否存在于系统中，并返回在数组中的位置
void EmployeeSystem::ShowMenu()
{   
	cout <<"Welcome to Employee Administering System!" << endl;
	cout << "    "<<"Please Press Numbers to Continue"<<"        " << endl;
	cout << endl;
	cout << "    " << "0, " << "Exit Employee Administering System       " << endl;
	cout << endl;
	cout << "    " << "1, " << "Add New Empolyee       " << endl;
	cout << endl;
	cout << "    " << "2, " << "Show All Employees        " << endl;
	cout << endl;
	cout << "    " << "3, " << "Search Empolyee       " << endl;
	cout << endl;
	cout << "    " << "4, " << "Save Files       " << endl;
}//显示菜单函数
void EmployeeSystem::ExitSystem()
{
	cout << "Shuting Down..." << endl;
	system("pause");
	exit(0);
}//关闭系统函数
void EmployeeSystem::AddEmp()
{
	cout << "Please Input the Number of Employees You Need to Add" << endl;
	int AddNum = 0;//输入添加员工数量
	cin >> AddNum;
	if (AddNum > 0)
	{
		int NewSize = this->EmpNum + AddNum;//新员工总数
		Employee** NewSpace = new Employee * [NewSize];//开辟对应大小的空间
		if (this->EmpArray != NULL) //判断数组情况
		{
			for (int i = 0; i < EmpNum; i++)
			{
				NewSpace[i] = EmpArray[i];
			}
		}//输入现有员工数组
		for (int i = 0; i < AddNum; i++)
		{
			long id;  string  name; char gender; long phone;
			cout << "Please Input the Num." << i + 1 << "Employee's Id You Want to Add" << endl;
			cin >> id;
			cout << "Please Input the Num." << i + 1 << "Employee's Name You Want to Add" << endl;
			cin >> name;
			cout << "Please Input the Num." << i + 1 << "Employee's Gender You Want to Add" << endl;
			cin >> gender;
			cout << "Please Input the Num." << i + 1 << "Employee's Phone You Want to Add" << endl;
			cin >> phone;
			Employee* ep = new Employee(id, name, gender, phone);
			NewSpace[EmpNum + i] = ep;
		}////添加新员工信息并将新员工添加入员工数组
		this->EmpArray = NewSpace;//更改新空间指向
		this->EmpNum = NewSize;//更新员工总人数
		cout << AddNum << "New Employees Have Been Added" << endl;
		this->Empty = false;
		this->Save();//保存到文件中
	}
	else {
		cout << "ERROR" << endl;
		system("cls");
		}//输入数值不合理时清屏
}//添加员工函数
void EmployeeSystem::Save()
{
	ofstream ofs;
	ofs.open(File, ios::out);//打开并写入文件
	for (int i = 0; i < EmpNum; i++) 
	{
		ofs <<this->EmpArray[i]->Id << " "
			<< this->EmpArray[i]->Name << " "
			<< this->EmpArray[i]->Gender << " "
			<<this->EmpArray[i]->Phone << endl;
	}
	ofs.close();//关闭文件
}//保存函数
void EmployeeSystem::SearchEmp()
{
	if (this->Empty)
	{
		cout << "No Results" << endl;
	}
	else 
	{
		cout << "Please Input the Id of the Employee You Want to Search" << endl;
		long x = 0;
		cin >> x;
		long index = Exist(x);//判断员工是否存在
		if (index != -1) 
		{
			cout << "the Employee You Want to Search is" << endl;
			this->EmpArray[index]->ShowInfo();//显示员工
		}
		else 
		{
			cout << "No Results" << endl;
		}
	}
}//查找员工函数
void EmployeeSystem::ListEmp()
{
	if (this->Empty)
	{
		cout << "No Results" << endl;
	}
	else 
	{
		for (int i = 0; i < this->EmpNum; i++)
		{
			this->EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}//列出员工函数
int EmployeeSystem::GetNum()
{
	ifstream ifs;
	ifs.open(File, ios::in);
	int id;
	string name;
	char gender;
	long phone;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> gender && ifs >> phone)
	{
		num++;
	}
	ifs.close();
	return num;
}//获取员工数量函数
EmployeeSystem::~EmployeeSystem()
{
}//析构函数

