#include<iostream>
#include"EmployeeSystem.h"
#include"Employee.h"
int main() 
{
	EmployeeSystem es;//������ϵͳ
	int choice=0;//��¼����Ա��ѡ��
	while (true)
	{
		es.ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			es.ExitSystem();
			break;
		case 1://���Ա��
			es.AddEmp();
			break;
		case 2://�г�����Ա��
			es.ListEmp();
			break;
		case 3://����Ա��
			es.SearchEmp();
			break;
		case 4:
			cout << "File Has Been Saved " << endl;
			es.Save();
			
			break;//���浱ǰ��Ϣ
		default:
			system("cls");//������Ч���ֺ�������������ĸ���������Զ��ر�
			break;
		}
	}
	system("pause");
}
