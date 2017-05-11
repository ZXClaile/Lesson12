#include<iostream>
#include "Enemy.h"
#include <memory>  //智能指针  要包含此头文件
#include "smartPtr.h"
using namespace std;
//递增运算符

int main() {
	//目标： 实现Enemy++ Enemy--   ++Enemy , --Enemy
	//目标：转换运算符 当做所需类型的参数
	//双目运算符的重载   enemy +  1   //   1  + enemy ??
	Enemy enemy01;
	++enemy01; 
	cout << enemy01.getHealth() << endl;
	--enemy01;
	cout << enemy01.getHealth() << endl;
	enemy01++;
	cout << enemy01.getHealth() << endl;
	enemy01--;
	cout << enemy01.getHealth() << endl;

	/*cout << enemy01 <<endl;*/
	
	//智能指针 unique_ptr  shared_ptr  weak_ptr
	//unique_ptr<Enemy>  enemyPtr(new Enemy(50));  
	//enemyPtr->Display();
	////无需主动回收内存  
	//smartPtr<Enemy> enemyPtr02(new Enemy(66));
	//enemyPtr02->Display();
	//我的也无需主动回收内存 

	// + 
	enemy01 = enemy01 + 20; 
	// 20 + enemy01 ????   friend 
	cout << enemy01.getHealth() << endl;
	// - 
	enemy01 = enemy01 - 200;  
	cout << enemy01.getHealth() << endl;
	
	// +=   -=  
	enemy01 += 100;
	cout << enemy01.getHealth() << endl;
	enemy01 -= 50;
	cout << enemy01.getHealth() << endl;

	//  bool   enemy01 > enemy 02 ??
	Enemy enemy02;
	cout << "生命值是否相同？？？  ？？？  ？？？  " << (enemy01 == enemy02) << endl;
	cout << "不一样吗？？ 吗 ？？  " << (enemy01 != enemy02) << endl;

	//深复制？ 
	//Enemy(enemy01)  
	//Enemy enemy03;
	//enemy02.Boss = &enemy01;
	//enemy03 = enemy02;
	//cout << (enemy03.Boss->getHealth()) << endl; //改变了Enemy02的BOSS生命值 enemy03 是否会改变？
	//enemy03 = enemy03[200];  // []
	//cout << enemy03.getHealth() << endl;
	//enemy03 = enemy03(500);  // []
	//cout << enemy03.getHealth() << endl;

	//移动复制函数 和移动构造函数  std::move()  
	//  enemy01++;

	system("pause");
	return 9;
}