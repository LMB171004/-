#include "common.h"
#define ElemType int

typedef ElemType * Rational;// ��InitRational����2��Ԫ�ش洢�ռ�  
 // Rational������ElemType���͵�ָ�룬���ElemType���͵ĵ�ַ  
 
 
//---------���������ĺ���˵��-----------
Status InitRational(Rational &T, ElemType v1, ElemType v2) ;
	//����������T �����ӡ���ĸ�ֱ��Բ���v1,v2��ֵ 
	
Status DestoryRational(Rational &T) ;
	//����������T 
	
Status GetRational(Rational &T, int i, ElemType &e) ;
	//i=1��2����e�����������ķ��ӻ��ĸ
	
Status PutRational(Rational &T, int i, ElemType &e) ; 
	//i=1��2����e�ı��������ķ��ӻ��ĸ
	
Status AddRational(Rational T1, Rational T2, Rational &T3) ; 
	//������T1,T2���,�������������T3
	
Status SubRational(Rational T1, Rational T2, Rational &T3) ; 
	//������T1,T2���,�������������T3
	
Status MulRational(Rational T1, Rational T2, Rational &T3) ; 
	//������T1,T2���,�������������T3
	
Status DivRational(Rational T1, Rational T2, Rational &T3) ; 
	//������T1,T2���,�������������T3
	
Status gys(int m,int n);//�����Լ�������ڻ��� 
