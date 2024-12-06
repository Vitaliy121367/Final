#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

public:
	//--------- ������������ �� ����������� ---------
	Date(); // �� ������������� - ������� ����
	Date(int year, int month, int day); // � ����������� - ������ ����	 

	bool isLeapYear()const; //�������� �� ���������� ��
	int monthDays()const; //ʳ������ ��� �� ������
	void nextDate(); // �������� ����
	void prevDate(); // ��������� ����        
	bool valid()const; // �������� ���� �� ����������

	//--------- �������� ---------
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;


	//--------- ��������� ��������� �� ��������
	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);


	//--------- ��������� ���������� �� ���������� ---------
	Date& operator --(); // ��������� ����� ����������
	Date operator --(int); // ���������� ����� ����������
	Date& operator ++ (); // ��������� ����� ����������
	Date operator ++ (int); // ���������� ����� ����������

	//--------- ��������� ��в������ ---------
	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;


	//--------- ��������� �����Ϊ��� ---------	
	Date& operator += (int days); // ������ days ��� �� ����
	Date& operator -= (int days); // ������ days �� �� ����
	Date& operator += (double years); // ������ years ���� �� ����
	Date& operator -= (double years); // ������ years ���� �� ����


	//--------- ���������Ͳ ��������� ---------
	Date operator + (int days)const&;
	Date operator - (int days)const&;
	friend Date operator + (int days, const Date& a);
	friend Date operator - (int days, const Date& a);

	Date operator + (double years)const&;
	Date operator - (double years)const&;
	friend Date operator + (double years, const Date& a);
	friend Date operator - (double years, const Date& a);

};