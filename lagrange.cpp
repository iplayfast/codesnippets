// lagrange interpolation allows you to interpolate through a series of points.
// it works by making functions that has 0 for all points but 1 along the known points.
// with all these functions it simply adds the funtions together for a nice interpolation through all points.

// this code generates code to do N points
// n is number of variables, vi is current variable
//
//Sample test code is created if the number of points to be used is 4. 
//
#include <stdio.h>
void Setup()
{
printf("#include <stdio.h>\n\n");	
printf("struct point {\n\
	double x;\n\
	double y;\n\
};\n\n");
}

void F1(int n,int vi)
{
	printf("double F_%dNum(double X,point *array)\n{\n",vi);
	printf("  return 1.0");
	for(int i=0;i<n;i++) {
		if (i!=vi) 
			printf("* (X - array[%d].x)",i);
	}
	printf(";\n}\n");
}
void F2(int n,int vi)
{
	F1(n,vi);
	printf("double F_%d(double X,point *array)\n{\n",vi);
	printf("double num = F_%dNum(X,array)*array[%d].y;\n",vi,vi);
	printf("double den = F_%dNum(array[%d].x,array);\n",vi,vi);
	printf("if (den==0.0) den = .1;// just in case\n");
	printf("return num / den;\n}\n\n");
}

void Build(int n)
{	
	for(int vi=0;vi<n;vi++)
		F2(n,vi);
	printf("double lagrange%d(double X,point *array)\n{\n",n);
	printf("  return 0.0");
	for(int vi=0;vi<n;vi++)
		printf("+ F_%d(X,array)",vi);
	printf(";\n}\n\n");

	if (n==4) {			
	printf(
"int main()\n{\n\
point array[4];\n\
	array[0].x = 0.0; array[0].y = 1.88;\n\
	array[1].x = 1.38; array[1].y = 1.13;\n\
	array[2].x = 3.01; array[2].y = 1.38;\n\
	array[3].x = 4.1; array[3].y = 0.0;\n\
	double test = lagrange%d(1,array);\n\
	printf(\"X=1,Y should be about 1.1, is %%f\\n\",test);\n\
	test = lagrange%d(2,array);\n\
	printf(\"X=2,Y should be about 1.3, is %%f\\n\",test);\n\
	test = lagrange%d(5,array);\n\
	printf(\"X=2,Y should be about -3.2, is %%f\\n\",test);\n\
}\n\n",n,n,n);
	}


}

int main() {
	Setup();
	Build(4);
	return 0;
}
