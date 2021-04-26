
#include<math.h>
#include <stdlib.h>
#include <stdio.h> 

#define EPS 0.0001
#define H 0.0001


//Nous avons réécrit ces fonctions pour les tester dans le main

double f0(double x){
	return -2*exp(-(x+1)*(x+1));
}

double f6(double x){
	return log(x)-1;
}


double f1(double x){
	return (1/4)*x*x*x*x-2*x*x+x;
}

double f2(double x){
	return (1/2)*x*x-3*x*(log(x)-1);
}

double Newton(double (*f)(double y), double x, double h){
	double y = x;
	printf("valeur de f: %.5f \n",((*f)(y)));
	int i = 1;
	while (fabs((*f)(y)) > EPS){
		printf("ITERATION: %d \n", i );
		i++;
		printf("val absolue de f(y)= %.5f \n",fabs((*f)(y)));
		double derivee = ((*f)(y+h) - (*f)(y))/h;
		printf("dérivée en %.5f : %.5f \n",y, derivee);
		y = y - ((*f)(y)/derivee);
		printf("y= %.5f \n",y);
	}
	printf("il y a eu %d itérations \n", i-1 );     //Question 3, complétée par des tests dans le main
	return y;
	
}


int main(){

	double i = Newton(&f0,0.9,H);
	printf("il y a convergence en %.5f \n \n",i);
	/*double m = Newton(&f0,1.5,H);
	printf("il y a convergence en %.5f \n \n",m);
	double n = Newton(&f0,-0.9,H);
	printf("il y a convergence en %.5f \n \n",n);

	double j = Newton(&f1,0,H);
	printf("il y a convergence en %.5f \n \n",j);
	double v = Newton(&f1,-1.5,H);
	printf("il y a convergence en %.5f \n \n",v);

	double k = Newton(&f2,4.9,H);
	printf("il y a convergence en %.5f \n \n",k);
	//double L = Newton(&f6,1.8,H);
	//printf("il y a convergence en %.5f \n \n",L);


*/


}
