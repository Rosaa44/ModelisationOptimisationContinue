#include <unistd.h>
#include<math.h>
#include <stdlib.h>
#include <stdio.h> 
#include "progline.c"

#define EPS 0.0001
#define H 0.0001


double ex4(double x, double y){
    return 2*x*y+2*y-x*x-2*y*y;
}

double grad1(double x,double y){
	return 2*y-2*x;
}

double grad2(double x,double y){
	return 2*x+2-4*y;
}

double hessx(double x,double y){
	return -2;
}

double hessy(double x,double y){
	return -4;
}

double hessxy(double x,double y){
	return 2;
}

//COURS10:

double ex10(double x, double y){
    return exp(x+y)+x*x+2*y*y;
}

double grad10(double x,double y){
	return exp(x+y)+2*x;
}

double grad20(double x,double y){
	return exp(x+y)+4*x;
}

double hessx0(double x, double y){
	return exp(x+y)+2;
}

double hessy0(double x,double y){
	return exp(x+y)+4;
}

double hessxy0(double x,double y){
	return exp(x+y);
}


double * Newton2(double (*f)(double z,double v),double (*fp1)(double z,double v), double (*fp2)(double z, double v), double (*fs1)(double x,double y), double (*fs2)(double x,double y), double (*fs3)(double x,double y), double x, double y){

	return resolution((*fs1)(x,y), (*fs3)(x,y), -(*fp1)(x,y), (*fs3)(x,y), (*fs2)(x,y), -(*fp2)(x,y));
		
}




int main(){

	printf(" \n");
	double* x = Newton2(&ex4, &grad1, &grad2, &hessx, &hessy, &hessxy, 1000, 1000);
	printf("résolution 1 \n");
	printf("X = %.2f\n", x[0]);
	printf("Y = %.2f\n", x[1]);

	printf(" \n");
	double* xy = Newton2(&ex4, &grad1, &grad2, &hessx, &hessy, &hessxy, 10, 10);
	printf("résolution 2 \n");
	printf("X = %.2f\n", xy[0]);
	printf("Y = %.2f\n", xy[1]);

	printf(" \n");
	double* xyz = Newton2(&ex4, &grad1, &grad2, &hessx, &hessy, &hessxy, 0, 0);
	printf("résolution 3 \n");
	printf("X = %.2f\n", xyz[0]);
	printf("Y = %.2f\n", xyz[1]);
	printf(" LE RESULTAT EST DONC (1,1)\n");

	printf(" \n");
	
	printf("EXERCICE 10 APPROXIMATION: \n");
	double* xyz1 = Newton2(&ex10, &grad10, &grad20, &hessx0, &hessy0, &hessxy0, 0, 0);
	printf("résolution 1 \n");
	printf("X = %.5f\n", xyz1[0]);
	printf("Y = %.5f\n", xyz1[1]);
	printf("Il s'agit bel et bien du résultat de l'exercice 10 \n");

	printf("Une approximation du résultat : \n");
	double* xyz4;
	double res = xyz1[0];
	double res2 = xyz1[1];
	while( (sqrt( (res*res)+(res2*res2)) ) >=0.2){	
		xyz4 = Newton2(&ex10, &grad10, &grad20, &hessx0, &hessy0, &hessxy0, res, res2);
		res = xyz4[0];
		res2 = xyz4[1];

	}
	printf("X = %.5f\n", res);
	printf("Y = %.5f\n", res2);	


}



















