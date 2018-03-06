#include "common.h"
#define ElemType int

typedef ElemType * Rational;// 由InitRational分配2个元素存储空间  
 // Rational类型是ElemType类型的指针，存放ElemType类型的地址  
 
 
//---------基本操作的函数说明-----------
Status InitRational(Rational &T, ElemType v1, ElemType v2) ;
	//构造有理数T ，分子、分母分别赋以参数v1,v2的值 
	
Status DestoryRational(Rational &T) ;
	//销毁有理数T 
	
Status GetRational(Rational &T, int i, ElemType &e) ;
	//i=1或2，用e返回有理数的分子或分母
	
Status PutRational(Rational &T, int i, ElemType &e) ; 
	//i=1或2，用e改变有理数的分子或分母
	
Status AddRational(Rational T1, Rational T2, Rational &T3) ; 
	//有理数T1,T2相加,结果存入有理数T3
	
Status SubRational(Rational T1, Rational T2, Rational &T3) ; 
	//有理数T1,T2相减,结果存入有理数T3
	
Status MulRational(Rational T1, Rational T2, Rational &T3) ; 
	//有理数T1,T2相乘,结果存入有理数T3
	
Status DivRational(Rational T1, Rational T2, Rational &T3) ; 
	//有理数T1,T2相除,结果存入有理数T3
	
Status gys(int m,int n);//求最大公约数，用于化简 
