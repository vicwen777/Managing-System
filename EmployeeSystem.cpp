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
	}//�ļ�������
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
	}//�ļ�������
	int num = this->GetNum();
	this->EmpNum = num;//����Ա������
	this->EmpArray = new Employee * [this->EmpNum];//���ٿռ�
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
	}//��һ��Ա��Ԫ�ظ�ֵ
	ifs.close();
}//��ʼ��Ա������������
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
}//�жϱ���Ƿ������ϵͳ�У��������������е�λ��
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
}//��ʾ�˵�����
void EmployeeSystem::ExitSystem()
{
	cout << "Shuting Down..." << endl;
	system("pause");
	exit(0);
}//�ر�ϵͳ����
void EmployeeSystem::AddEmp()
{
	cout << "Please Input the Number of Employees You Need to Add" << endl;
	int AddNum = 0;//�������Ա������
	cin >> AddNum;
	if (AddNum > 0)
	{
		int NewSize = this->EmpNum + AddNum;//��Ա������
		Employee** NewSpace = new Employee * [NewSize];//���ٶ�Ӧ��С�Ŀռ�
		if (this->EmpArray != NULL) //�ж��������
		{
			for (int i = 0; i < EmpNum; i++)
			{
				NewSpace[i] = EmpArray[i];
			}
		}//��������Ա������
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
		}////�����Ա����Ϣ������Ա�������Ա������
		this->EmpArray = NewSpace;//�����¿ռ�ָ��
		this->EmpNum = NewSize;//����Ա��������
		cout << AddNum << "New Employees Have Been Added" << endl;
		this->Empty = false;
		this->Save();//���浽�ļ���
	}
	else {
		cout << "ERROR" << endl;
		system("cls");
		}//������ֵ������ʱ����
}//���Ա������
void EmployeeSystem::Save()
{
	ofstream ofs;
	ofs.open(File, ios::out);//�򿪲�д���ļ�
	for (int i = 0; i < EmpNum; i++) 
	{
		ofs <<this->EmpArray[i]->Id << " "
			<< this->EmpArray[i]->Name << " "
			<< this->EmpArray[i]->Gender << " "
			<<this->EmpArray[i]->Phone << endl;
	}
	ofs.close();//�ر��ļ�
}//���溯��
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
		long index = Exist(x);//�ж�Ա���Ƿ����
		if (index != -1) 
		{
			cout << "the Employee You Want to Search is" << endl;
			this->EmpArray[index]->ShowInfo();//��ʾԱ��
		}
		else 
		{
			cout << "No Results" << endl;
		}
	}
}//����Ա������
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
}//�г�Ա������
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
}//��ȡԱ����������
EmployeeSystem::~EmployeeSystem()
{
}//��������

