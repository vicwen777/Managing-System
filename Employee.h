#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee {
public:
	long Id; 
	string Name; 
	char Gender ; //���ַ��ͱ�ʾ��ʡ�ռ䣬F��M
	long Phone ;//Ա����Ϣ
	Employee(long id, string name, char gender, long phone);//���캯��
	void ShowInfo();//��ʾԱ����Ϣ
};//����Ա����



