#include <iostream> 
using namespace std; 
#include "Rational.h" 

int main( )
{
	Rational T1,T2,T3;  //�������������� 
	ElemType e1,e2,e3,e4;  //�����ĸ����ӷ�ĸ 
	int i;
	
	cout<<"�������һ���������ķ������ĸ��"<<endl;//���������������ķ������ĸ 
	cin>>e1>>e2;
	while(e2<=0) //��������ĸ����Ϊ��������0
	{
		cout<<"��ĸ������������������"<<endl;
		cin>>e1>>e2;
	}
	cout<<"������ڶ����������ķ������ĸ:"<<endl;
	cin>>e3>>e4;
	while(e4<=0)
	{
		cout<<"��ĸ������������������"<<endl;
		cin>>e3>>e4;
	}
	InitRational(T1,e1,e2);  //�������������� 
	InitRational(T2,e3,e4);
	//�������� 
	AddRational( T1, T2, T3);
	cout<<"��������֮��Ϊ:"<<endl<<T3[0]<<" "<<T3[1]<<endl;

    SubRational( T1, T2, T3);
	/*if(T3[0]==0&&T3[1]==0) 
	cout<<"��������֮��Ϊ:"<<endl<<"0 0"<<endl;
	else*/
	cout<<"��������֮��Ϊ:"<<endl<<T3[0]<<" "<<T3[1]<<endl;
	
	MulRational( T1, T2, T3);
	cout<<"��������֮��Ϊ:"<<endl<<T3[0]<<" "<<T3[1]<<endl;
	
	if(T2[0]==0)
		cout<<"�����������޷����"<<endl;
	else
	{
		DivRational( T1, T2, T3);
		cout<<"��������֮��Ϊ:"<<endl<<T3[0]<<" "<<T3[1]<<endl;
	}

	DestoryRational( T1 );  //�������������� 
	DestoryRational( T2 );
	DestoryRational( T3 );
	
    return 0;
}
