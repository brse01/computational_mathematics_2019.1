#ifndef BRUNO_H
#define BRUNO_H

#include <cmath>
#include <iostream>
#include <math.h>


using namespace std;
struct ponto { int x, y; }; 

class Bruno
{
public:
	Bruno();
	~Bruno();	
	double interpolacao_lagrange(ponto pontos[], int xi, int n);
	double taylor(double x, double epsilon);
	double posicao_falsa(double a, double b, double episilon_1, double episilon_2);
	double metodoNewton(double x0, double e1, double e2);
	double secant(double x0, double x1, double e1, double e2);
	double trapezio_simples(float b, float a, int n);
private:	
	double funcaoPosicao_Falsa(double valor);
	double funcaoSecantNewton(double x);
	double derivada(double x); 
	double funcao_trapezio(double x);
};
#endif