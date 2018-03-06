#include <iostream> 
using namespace std; 
#include "Rational.h" 

int main( )
{
	Rational T1,T2,T3;  //定义三个有理数 
	ElemType e1,e2,e3,e4;  //定义四个分子分母 
	int i;
	
	cout<<"请输入第一个有理数的分子与分母："<<endl;//输入两个有理数的分子与分母 
	cin>>e1>>e2;
	while(e2<=0) //有理数分母不能为负数或者0
	{
		cout<<"分母输入有误，请重新输入"<<endl;
		cin>>e1>>e2;
	}
	cout<<"请输入第二个有理数的分子与分母:"<<endl;
	cin>>e3>>e4;
	while(e4<=0)
	{
		cout<<"分母输入有误，请重新输入"<<endl;
		cin>>e3>>e4;
	}
	InitRational(T1,e1,e2);  //构造两个有理数 
	InitRational(T2,e3,e4);
	//四则运算 
	AddRational( T1, T2, T3);
	cout<<"两有理数之和为:"<<endl<<T3[0]<<" "<<T3[1]<<endl;

    SubRational( T1, T2, T3);
	/*if(T3[0]==0&&T3[1]==0) 
	cout<<"两有理数之差为:"<<endl<<"0 0"<<endl;
	else*/
	cout<<"两有理数之差为:"<<endl<<T3[0]<<" "<<T3[1]<<endl;
	
	MulRational( T1, T2, T3);
	cout<<"两有理数之积为:"<<endl<<T3[0]<<" "<<T3[1]<<endl;
	
	if(T2[0]==0)
		cout<<"所给有理数无法相除"<<endl;
	else
	{
		DivRational( T1, T2, T3);
		cout<<"两有理数之商为:"<<endl<<T3[0]<<" "<<T3[1]<<endl;
	}

	DestoryRational( T1 );  //销毁三个有理数 
	DestoryRational( T2 );
	DestoryRational( T3 );
	
    return 0;
}
