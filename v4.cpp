#include <stdio.h>

struct point {
	double x;
	double y;
};

double F_0Num(double X,point *array)
{
  return 1.0* (X - array[1].x)* (X - array[2].x)* (X - array[3].x);
}
double F_0(double X,point *array)
{
double num = F_0Num(X,array)*array[0].y;
double den = F_0Num(array[0].x,array);
if (den==0.0) den = .1;// just in case
return num / den;
}

double F_1Num(double X,point *array)
{
  return 1.0* (X - array[0].x)* (X - array[2].x)* (X - array[3].x);
}
double F_1(double X,point *array)
{
double num = F_1Num(X,array)*array[1].y;
double den = F_1Num(array[1].x,array);
if (den==0.0) den = .1;// just in case
return num / den;
}

double F_2Num(double X,point *array)
{
  return 1.0* (X - array[0].x)* (X - array[1].x)* (X - array[3].x);
}
double F_2(double X,point *array)
{
double num = F_2Num(X,array)*array[2].y;
double den = F_2Num(array[2].x,array);
if (den==0.0) den = .1;// just in case
return num / den;
}

double F_3Num(double X,point *array)
{
  return 1.0* (X - array[0].x)* (X - array[1].x)* (X - array[2].x);
}
double F_3(double X,point *array)
{
double num = F_3Num(X,array)*array[3].y;
double den = F_3Num(array[3].x,array);
if (den==0.0) den = .1;// just in case
return num / den;
}

double lagrange4(double X,point *array)
{
  return 0.0+ F_0(X,array)+ F_1(X,array)+ F_2(X,array)+ F_3(X,array);
}

int main()
{
point array[4];
	array[0].x = 0.0; array[0].y = 1.88;
	array[1].x = 1.38; array[1].y = 1.13;
	array[2].x = 3.01; array[2].y = 1.38;
	array[3].x = 4.1; array[3].y = 0.0;
	double test = lagrange4(1,array);
	printf("X=1,Y should be about 1.1, is %f\n",test);
	test = lagrange4(2,array);
	printf("X=2,Y should be about 1.3, is %f\n",test);
	test = lagrange4(5,array);
	printf("X=2,Y should be about -3.2, is %f\n",test);
}

