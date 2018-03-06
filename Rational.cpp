#include <iostream>
using namespace std; 
#include "common.h"
#include "Rational.h"
 
int gys (int a,int b)
{	//�����Լ�� 
	int t,r;
	if(a<b) {t=a;a=b;b=t;}
	r=a%b;
	while(r!=0) {a=b;b=r;r=a%b;}
	return b;
}

Status InitRational(Rational &T, ElemType v1, ElemType v2) 
{	//����������T �����ӡ���ĸ�ֱ��Բ���v1,v2��ֵ 
	T = new ElemType [2];  //T = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T) exit(OVERFLOW);  //����洢�ռ�ʧ��
	T[0] = v1;
	T[1] = v2;
	return OK;
}

Status DestoryRational(Rational &T)
{	//����������T 
	delete T;  //free(T);
	T = NULL;
	return OK;
}

Status GetRational(Rational &T, int i, ElemType &e) 
{	//i=1��2����e�����������ķ��ӻ��ĸ
	if(i<1||i>2)
		return ERROR;
	e = T[i-1];
	return OK;
}

Status PutRational(Rational &T, int i, ElemType &e)
{	//i=1��2����e�ı��������ķ��ӻ��ĸ
	if(i<1||i>2)
		return ERROR;
	T[i-1] = e;
	return OK;
}

Status AddRational(Rational T1, Rational T2, Rational &T3) 
{	//������T1,T2���,�������������T3
	T3 = new ElemType [2];	  //T3 = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T3) exit(OVERFLOW);  //����洢�ռ�ʧ��
	
	T3[0] = T1[0]*T2[1]+T1[1]*T2[0];
	T3[1] = T1[1]*T2[1];
	if(T3[0]==0) T3[0]=T3[1]=0;  //����������� 
	else{
		int m=gys(T3[0],T3[1]);
		T3[0]/=m;
		T3[1]/=m;
		if(T3[1]<0) {
			T3[0]=-1*T3[0];   //��ĸΪ����
			T3[1]=-1*T3[1];
		}
	}
}

Status SubRational(Rational T1, Rational T2, Rational &T3) 
{	//������T1,T2���,�������������T3
    T3 = new ElemType [2];	  //T3 = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T3) exit(OVERFLOW);  //����洢�ռ�ʧ��
	
	T3[0] = T1[0]*T2[1]-T1[1]*T2[0];   
	T3[1] = T1[1]*T2[1];
	if(T3[0]==0) T3[0]=T3[1]=0;  //����������� 
	else{
		int m=gys(T3[0],T3[1]);
		T3[0]/=m;
		T3[1]/=m;
		if(T3[1]<0) {
			T3[0]=-1*T3[0];  //��ĸΪ����
			T3[1]=-1*T3[1];
		}
	}
}
	
Status MulRational(Rational T1, Rational T2, Rational &T3) 
{	//������T1,T2���,�������������T3
	T3 = new ElemType [2];	  //T3 = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T3) exit(OVERFLOW);  //����洢�ռ�ʧ��
	
	T3[0] = T1[0]*T2[0];
	T3[1] = T1[1]*T2[1];
	if(T3[0]==0) T3[0]=T3[1]=0;  //����������� 
	else{
		int m=gys(T3[0],T3[1]);
		T3[0]/=m;
		T3[1]/=m;
		if(T3[1]<0) {
			T3[0]=-1*T3[0];   //��ĸΪ����
			T3[1]=-1*T3[1];
		}
	}
}

Status DivRational(Rational T1, Rational T2, Rational &T3) 
{	//������T1,T2���,�������������T3
	 T3 = new ElemType [2];	  //T3 = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T3) exit(OVERFLOW);  //����洢�ռ�ʧ��

	T3[0] = T1[0]*T2[1];
	T3[1] = T1[1]*T2[0];
	if(T3[0]==0) T3[0]=T3[1]=0;  //����������� 
	else{
		int m=gys(T3[0],T3[1]);
		T3[0]/=m;
		T3[1]/=m;
		if(T3[1]<0) {
			T3[0]=-1*T3[0];   //��ĸΪ���� 
			T3[1]=-1*T3[1];
		}
	}
}

