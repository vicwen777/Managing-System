#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
#include<fstream>
#define  File "EmpFile.txt"
using namespace std;
class EmployeeSystem
{
public:
	int EmpNum;//总员工数量
	Employee**EmpArray;//员工数组
	bool Empty;//判断文件是否为空
	EmployeeSystem();//构造函数
	void ShowMenu();//显示菜单
	void ExitSystem();//退出系统
	void AddEmp();//添加员工
	void SearchEmp();//查找员工
	void ListEmp();//列出员工
	void Save();//保存文件
	void InitEmp();//初始化函数
	int GetNum();//获取员工数量
	long Exist(long id);//判断员工存在性函数
	~EmployeeSystem();//析构函数
};//构建系统类