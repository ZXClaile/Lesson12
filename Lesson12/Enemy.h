#pragma once
#include <iostream>
#include<string>
using std::string;
using namespace std;
class Enemy
{
public:
	Enemy();
	Enemy(int inputHealth);   //  new Enemy(100)
	Enemy(Enemy&& moveSource);  // Move Constructor  
	~Enemy();
	//ǰ׺  ++Enemy
	Enemy& operator ++ ();
	//ǰ׺ --Enemy
	Enemy& operator-- ();
	//��׺   Enemy++
	Enemy operator++(int);  
	//��׺  Enemy--
	Enemy operator -- (int);
	int getHealth();

	//  Boss
	Enemy* Boss = nullptr;

	// ���ؼӷ������
	Enemy& operator + (int inputHealth);  
	//���ؼ��������
	Enemy& operator - (int inputHealth);
	
	// ���� +=  
	void operator += (int inputData);
	// ���� -=
	void operator -= (int inputData);

	// ���� []   enemy01[500];    
	Enemy&  operator [] (int inputHealth);

	// ���� ()   
	Enemy&  operator () (int inputHealth);

	//operator const char* (); //����ת�������
	//string enemyInString; //�ַ��� ����ַ��� �洢ת�������ַ�


	// bool   ==  
	bool operator == (const Enemy& compareTo);

	//bool !=
	bool operator != (const Enemy& compareTo);

	//����һ��ssssss
	void Display() {
		cout << "����ֵ�� ���ٶ� " << health << endl;
	}
	
	//  =  
	Enemy& operator = (const Enemy& copySource);

	Enemy & operator = (Enemy&& moveSource);
private:
	int health = 100;   //������������ʱ�� ������ֵ�����仯
};

