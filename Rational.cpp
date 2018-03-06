#include <iostream>
using namespace std; 
#include "common.h"
#include "Rational.h"
 
int gys (int a,int b)
{	//求最大公约数 
	int t,r;
	if(a<b) {t=a;a=b;b=t;}
	r=a%b;
	while(r!=0) {a=b;b=r;r=a%b;}
	return b;
}

Status InitRational(Rational &T, ElemType v1, ElemType v2) 
{	//构造有理数T ，分子、分母分别赋以参数v1,v2的值 
	T = new ElemType [2];  //T = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T) exit(OVERFLOW);  //分配存储空间失败
	T[0] = v1;
	T[1] = v2;
	return OK;
}

Status DestoryRational(Rational &T)
{	//销毁有理数T 
	delete T;  //free(T);
	T = NULL;
	return OK;
}

Status GetRational(Rational &T, int i, ElemType &e) 
{	//i=1或2，用e返回有理数的分子或分母
	if(i<1||i>2)
		return ERROR;
	e = T[i-1];
	return OK;
}

Status PutRational(Rational &T, int i, ElemType &e)
{	//i=1或2，用e改变有理数的分子或分母
	if(i<1||i>2)
		return ERROR;
	T[i-1] = e;
	return OK;
}

Status AddRational(Rational T1, Rational T2, Rational &T3) 
{	//有理数T1,T2相加,结果存入有理数T3
	T3 = new ElemType [2];	  //T3 = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T3) exit(OVERFLOW);  //分配存储空间失败
	
	T3[0] = T1[0]*T2[1]+T1[1]*T2[0];
	T3[1] = T1[1]*T2[1];
	if(T3[0]==0) T3[0]=T3[1]=0;  //特殊情况考虑 
	else{
		int m=gys(T3[0],T3[1]);
		T3[0]/=m;
		T3[1]/=m;
		if(T3[1]<0) {
			T3[0]=-1*T3[0];   //分母为负数
			T3[1]=-1*T3[1];
		}
	}
}

Status SubRational(Rational T1, Rational T2, Rational &T3) 
{	//有理数T1,T2相减,结果存入有理数T3
    T3 = new ElemType [2];	  //T3 = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T3) exit(OVERFLOW);  //分配存储空间失败
	
	T3[0] = T1[0]*T2[1]-T1[1]*T2[0];   
	T3[1] = T1[1]*T2[1];
	if(T3[0]==0) T3[0]=T3[1]=0;  //特殊情况考虑 
	else{
		int m=gys(T3[0],T3[1]);
		T3[0]/=m;
		T3[1]/=m;
		if(T3[1]<0) {
			T3[0]=-1*T3[0];  //分母为负数
			T3[1]=-1*T3[1];
		}
	}
}
	
Status MulRational(Rational T1, Rational T2, Rational &T3) 
{	//有理数T1,T2相乘,结果存入有理数T3
	T3 = new ElemType [2];	  //T3 = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T3) exit(OVERFLOW);  //分配存储空间失败
	
	T3[0] = T1[0]*T2[0];
	T3[1] = T1[1]*T2[1];
	if(T3[0]==0) T3[0]=T3[1]=0;  //特殊情况考虑 
	else{
		int m=gys(T3[0],T3[1]);
		T3[0]/=m;
		T3[1]/=m;
		if(T3[1]<0) {
			T3[0]=-1*T3[0];   //分母为负数
			T3[1]=-1*T3[1];
		}
	}
}

Status DivRational(Rational T1, Rational T2, Rational &T3) 
{	//有理数T1,T2相除,结果存入有理数T3
	 T3 = new ElemType [2];	  //T3 = (ElemType *)malloc(2 * sizeof(ElemType));
	if(!T3) exit(OVERFLOW);  //分配存储空间失败

	T3[0] = T1[0]*T2[1];
	T3[1] = T1[1]*T2[0];
	if(T3[0]==0) T3[0]=T3[1]=0;  //特殊情况考虑 
	else{
		int m=gys(T3[0],T3[1]);
		T3[0]/=m;
		T3[1]/=m;
		if(T3[1]<0) {
			T3[0]=-1*T3[0];   //分母为负数 
			T3[1]=-1*T3[1];
		}
	}
}

