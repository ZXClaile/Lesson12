#include<iostream>
#include "Enemy.h"
#include <memory>  //����ָ��  Ҫ������ͷ�ļ�
#include "smartPtr.h"
using namespace std;
//���������

int main() {
	//Ŀ�꣺ ʵ��Enemy++ Enemy--   ++Enemy , --Enemy
	//Ŀ�꣺ת������� �����������͵Ĳ���
	//˫Ŀ�����������   enemy +  1   //   1  + enemy ??
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
	
	//����ָ�� unique_ptr  shared_ptr  weak_ptr
	//unique_ptr<Enemy>  enemyPtr(new Enemy(50));  
	//enemyPtr->Display();
	////�������������ڴ�  
	//smartPtr<Enemy> enemyPtr02(new Enemy(66));
	//enemyPtr02->Display();
	//�ҵ�Ҳ�������������ڴ� 

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
	cout << "����ֵ�Ƿ���ͬ������  ������  ������  " << (enemy01 == enemy02) << endl;
	cout << "��һ���𣿣� �� ����  " << (enemy01 != enemy02) << endl;

	//��ƣ� 
	//Enemy(enemy01)  
	//Enemy enemy03;
	//enemy02.Boss = &enemy01;
	//enemy03 = enemy02;
	//cout << (enemy03.Boss->getHealth()) << endl; //�ı���Enemy02��BOSS����ֵ enemy03 �Ƿ��ı䣿
	//enemy03 = enemy03[200];  // []
	//cout << enemy03.getHealth() << endl;
	//enemy03 = enemy03(500);  // []
	//cout << enemy03.getHealth() << endl;

	//�ƶ����ƺ��� ���ƶ����캯��  std::move()  
	//  enemy01++;

	system("pause");
	return 9;
}