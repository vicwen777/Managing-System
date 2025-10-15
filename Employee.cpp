#include"Employee.h"
Employee::Employee(long id,string name,char gender,long phone)
{
	this->Id = id;
	this->Name = name;
	this->Gender = gender;
	this->Phone = phone;
}//初始化员工信息
void Employee::ShowInfo() 
{
	cout << "Id:         " << this->Id << "\t";
	cout << "Name:   " << this->Name << "\t";
	cout << "Gender: " << this->Gender << "\t";
	cout << "Phone:   " << this->Phone << "\t" << endl;
};//显示员工信息函数
