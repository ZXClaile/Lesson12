#include<string>
#include<sstream>
#include "Enemy.h"
using std::string;
Enemy::Enemy()
{
}

Enemy::Enemy(int inputHealth)
{
	health = inputHealth;
}

Enemy::Enemy(Enemy && moveSource)
{
	if (moveSource.Boss != nullptr)
	{
		Boss = moveSource.Boss;
		moveSource.Boss = nullptr;
	}
}


Enemy::~Enemy()
{
	if (Boss != nullptr)  
	{
		//静态成员 static  == ??   delete
		Boss = nullptr; 
	}
}

Enemy & Enemy::operator++()
{
	health = ++health;
	return *this;
}

Enemy & Enemy::operator--()
{
	health = --health;
	return *this;
}

Enemy Enemy::operator++(int)
{
	//Enemy++
	Enemy copyEnemy(health); //用原有生命值创建了一个副本  
	health = ++health;
	return copyEnemy;
}

Enemy Enemy::operator--(int)
{
	//Enemy--
	Enemy copyEnemy(health);
	health = --health;
	return copyEnemy;
}

int Enemy::getHealth()
{
	return health; 
}

Enemy& Enemy::operator+(int inputHealth)
{
	health = health + inputHealth;
	return  *this;
}

Enemy& Enemy::operator - (int inputHealth)
{
	health = health - inputHealth;
	return *this;
}

void Enemy::operator+=(int inputData)
{
	health = health + inputData;
}

void Enemy::operator-=(int inputData)
{
	health = health - inputData;
}

Enemy & Enemy::operator[](int inputHealth)
{
	health = inputHealth;
	return *this;
}

Enemy & Enemy::operator()(int inputHealth)
{
	health = inputHealth;
	return *this;
}

//Enemy::operator const char*()
//{
//	std::stringstream formattedEnemy;
//	formattedEnemy << "敌军生命值： " << health;    //用于输出的一个类对象   缓存一段字符串
//	formattedEnemy >>enemyInString;
//	enemyInString = formattedEnemy.str(); //将这段缓存的字符串 保存到类的变量里  会在函数运行完清除
//	return  enemyInString.c_str();  //返回const char* 
//}

bool Enemy::operator==(const Enemy & compareTo)
{
	return  (health == compareTo.health);
}

bool Enemy::operator!=(const Enemy & compareTo)
{
	return (health != compareTo.health);
}

Enemy & Enemy::operator=(const Enemy & copySource)
{
	if ( ( this != &copySource ) && ( copySource .Boss  != nullptr) )
	{
		if (Boss != nullptr)
		{
			delete Boss;
		}
		Boss = new Enemy(copySource.Boss->health);
	}
	health = copySource.health;
	return *this;

}

Enemy & Enemy::operator = (Enemy && moveSource)
{
	if (moveSource.Boss != nullptr)
	{
		Boss = moveSource.Boss;
	}
	return *this;
}
