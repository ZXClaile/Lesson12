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
	//前缀  ++Enemy
	Enemy& operator ++ ();
	//前缀 --Enemy
	Enemy& operator-- ();
	//后缀   Enemy++
	Enemy operator++(int);  
	//后缀  Enemy--
	Enemy operator -- (int);
	int getHealth();

	//  Boss
	Enemy* Boss = nullptr;

	// 重载加法运算符
	Enemy& operator + (int inputHealth);  
	//重载减法运算符
	Enemy& operator - (int inputHealth);
	
	// 重载 +=  
	void operator += (int inputData);
	// 重载 -=
	void operator -= (int inputData);

	// 重载 []   enemy01[500];    
	Enemy&  operator [] (int inputHealth);

	// 重载 ()   
	Enemy&  operator () (int inputHealth);

	//operator const char* (); //重载转换运算符
	//string enemyInString; //字符串 这个字符串 存储转换出的字符


	// bool   ==  
	bool operator == (const Enemy& compareTo);

	//bool !=
	bool operator != (const Enemy& compareTo);

	//表现一下ssssss
	void Display() {
		cout << "生命值是 多少吨 " << health << endl;
	}
	
	//  =  
	Enemy& operator = (const Enemy& copySource);

	Enemy & operator = (Enemy&& moveSource);
private:
	int health = 100;   //我们在自增的时候 让生命值发生变化
};

