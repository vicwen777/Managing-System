#include"Employee.h"
Employee::Employee(long id,string name,char gender,long phone)
{
	this->Id = id;
	this->Name = name;
	this->Gender = gender;
	this->Phone = phone;
}//��ʼ��Ա����Ϣ
void Employee::ShowInfo() 
{
	cout << "Id:         " << this->Id << "\t";
	cout << "Name:   " << this->Name << "\t";
	cout << "Gender: " << this->Gender << "\t";
	cout << "Phone:   " << this->Phone << "\t" << endl;
};//��ʾԱ����Ϣ����
