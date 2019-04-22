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
	double hibrido_posicao_falsa_e_metodo_newton(double a, double b, double episilon_1, double episilon_2,double x0, double e1, double e2);
	double secant(double x0, double x1, double e1, double e2);
	double trapezio_composta(float b, float a, int n);
	double trapezio_simples(float b, float a, int n);
	double simpson13_simples(float a, float b);
	double derivasaoExpanTaylor2(int a, int h);
	double derivasaoExpanTaylor3(int a, int h)
private:	
	double funcaoPosicao_Falsa(double valor);
	double funcaoSecantNewton(double x);
	double derivada(double x); 
	double funcao_trapezio(double x);
	double funcao_simpson(float valor);
	double funcao_derivasaoExpanTaylor(int valor);
};
#endif