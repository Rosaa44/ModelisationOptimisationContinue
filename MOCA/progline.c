#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double* resolution(double a1, double b1, double c1, double a2, double b2, double c2){
	//on résoud les équations de la forme ax+bx=c sinon adapter la forme;
	double determinant = a1*b2-a2*b1;
	
	if (determinant == 0) {
		fprintf(stderr, "Salut, je ne peux pas résoudre ton système :( \n");
		exit(1);
	}
	
	double * xy = malloc(sizeof(double)*2);
	double A[2][2];
	A[0][0] = a1;
	A[1][0] = a2;
	A[0][1] = b1;
	A[1][1] = b2;
	
	float AC[2][2]; 
	AC[0][0] = A[1][1]/determinant;
	AC[1][0] = -(A[1][0])/determinant;
	AC[0][1] = -(A[0][1])/determinant;
	AC[1][1] = A[0][0]/determinant;
	
	
	xy[0] = (AC[0][0] * c1) + (AC[0][1] * c2); // x
	xy[1] = (AC[1][0] * c1) + (AC[1][1] * c2); // y
	
	return xy;
}
	
	
/*
int main() {
	
	double* xy = resolution(2, 1, 1, 3, 7, -2);
	printf("résolution 1 \n");
	printf("X = %.2f\n", xy[0]);
	printf("Y = %.2f\n", xy[1]);
	
	printf("résolution 2 \n");
	double* waw = resolution(1, 5, 1, 1, 5, 1);
	printf("X = %.2f\n", waw[0]);
	printf("Y = %.2f\n", waw[1]);

	
	
	return 0;
}
*/ //Ce test est dans Newton2; car nous partageons un même main
