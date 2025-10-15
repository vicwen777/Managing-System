#include<iostream>
#include"EmployeeSystem.h"
#include"Employee.h"
int main() 
{
	EmployeeSystem es;//建立新系统
	int choice=0;//记录管理员的选择
	while (true)
	{
		es.ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			es.ExitSystem();
			break;
		case 1://添加员工
			es.AddEmp();
			break;
		case 2://列出所有员工
			es.ListEmp();
			break;
		case 3://查找员工
			es.SearchEmp();
			break;
		case 4:
			cout << "File Has Been Saved " << endl;
			es.Save();
			
			break;//保存当前信息
		default:
			system("cls");//输入无效数字后清屏，输入字母或其他键自动关闭
			break;
		}
	}
	system("pause");
}
