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
	int EmpNum;//��Ա������
	Employee**EmpArray;//Ա������
	bool Empty;//�ж��ļ��Ƿ�Ϊ��
	EmployeeSystem();//���캯��
	void ShowMenu();//��ʾ�˵�
	void ExitSystem();//�˳�ϵͳ
	void AddEmp();//���Ա��
	void SearchEmp();//����Ա��
	void ListEmp();//�г�Ա��
	void Save();//�����ļ�
	void InitEmp();//��ʼ������
	int GetNum();//��ȡԱ������
	long Exist(long id);//�ж�Ա�������Ժ���
	~EmployeeSystem();//��������
};//����ϵͳ��