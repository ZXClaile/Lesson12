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
		//��̬��Ա static  == ??   delete
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
	Enemy copyEnemy(health); //��ԭ������ֵ������һ������  
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
//	formattedEnemy << "�о�����ֵ�� " << health;    //���������һ�������   ����һ���ַ���
//	formattedEnemy >>enemyInString;
//	enemyInString = formattedEnemy.str(); //����λ�����ַ��� ���浽��ı�����  ���ں������������
//	return  enemyInString.c_str();  //����const char* 
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
