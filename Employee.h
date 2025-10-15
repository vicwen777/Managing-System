#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee {
public:
	long Id; 
	string Name; 
	char Gender ; //用字符型表示以省空间，F或M
	long Phone ;//员工信息
	Employee(long id, string name, char gender, long phone);//构造函数
	void ShowInfo();//显示员工信息
};//定义员工类



