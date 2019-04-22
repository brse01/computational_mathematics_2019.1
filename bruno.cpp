#include <bruno.hpp>

double Bruno::interpolacao_lagrange(ponto pontos[], int xi, int n){
 	double resultado =0.0;
 	for (int i = 0; i < n; i++){
 		double termo  = pontos[i].y;
 		for (int j = 0; j< n ; j++){
 			if(j!= i)
 				termo = termo* (xi - f[j].x) / double(f[i].x - f[j].k); 			
 		}
 		    resultado += term; 	
 	}

 	return resultado;
}

double Bruno::taylor(double x, double epsilon){
	int n =0; // Número de iterações;
	double parcela = 1;
	double soma = 0.0;
	while(fabs(parcela) >= epsilon){
		n++;
		soma+=parcela;
		parcela = (parcela * x) /n;
	}
	return soma;
}

double Bruno::funcaoPosicao_Falsa(double valor){
	return return valor - sqrt(7);
}

double Bruno::posicao_falsa(double a, double b, double episilon_1, double episilon_2){
	int k_fala_posi = 0;
	double f_a,f_b,x,f_x;
	while (b - a >= episilon_1) {
		f_a = funcaoPosicao_Falsa(a);
		f_b = funcaoPosicao_Falsa(b);
		if(abs(f_a) < episilon_2)
			return a;
		if(abs(f_b) < episilon_2)
			return b;

		x = (a * f_b - b * f_a) / (f_b - f_a);
		f_x = funcaoPosicao_Falsa(x);

		if((f_a * f_b) > 0) a=x;
		else b =x;

		k_fala_posi++;
	}
	return a - (b-a)/2;	
}

// x^3 - 9x + 3
double Bruno::funcaoSecantNewton(double x) {
	return pow(x, 3) - 9 * x + 3;
}

// 3*x^2 - 9
 double Bruno::derivada(double x) {
		return 3 * pow(x, 2) - 9;
}

double Bruno::metodoNewton(double x0, double e1, double e2){
	double x1=0;
	if(abs(funcaoSecantNewton(x0)) < e1){
		return x0;
	}else{
		int k=0;
		x1 = x0 - (funcaoSecantNewton(x0)/derivada(x0));
		while(abs(funcaoSecantNewton(x1))  >e1 || abs(x1-x0) > e2  ){
			x1 = x0 - (funcaoSecantNewton(x0)/derivada(x0));
			x0= x1;
			k++;
		}		
	}
	return x1;
}

double Bruno::secant(double x0, double x1, double e1, double e2){
	double x2 = 0.0;
	if(abs(funcaoSecantNewton(x0)) < e1)
		return x0;
	else{
		int k=0;		
		do{
			x2 = x1 - (funcaoSecantNewton(x1)/ (funcaoSecantNewton(x1) - funcaoSecantNewton(x0)));
			x0 = x1;
			x1 = x2;
		}while(abs(funcaoSecantNewton(x2)) > e1 || abs(x2 - x1) > e2);		
	}
	return x2;
}

double Bruno::funcao_trapezio(double x) {
	return pow(M_E, x);
}

double Bruno::trapezio_composta(float b, float a, int n){
	double h = (b-a)/n;
	double soma = funcao(a);	
	for (int i = 0; i < n; i++)
		soma+= 2* funcao(h*i);

	soma+= funcao(b);

	return (h*soma)/2;
}

double Bruno::trapezio_simples(float b, float a, int n){
	return (b-a) * ((funcao(a) + funcao(b))/2);
}

double Bruno::hibrido_posicao_falsa_e_metodo_newton(double a, double b, double episilon_1, double episilon_2,double x0, double e1, double e2){
	double a = posicao_falsa(a,b,episilon_1,episilon_2);
	return metodoNewton(a,e1,e2);
}

double Bruno::funcao_simpson(float valor){
	return valor;
}

double Bruno::simpson13_simples(float a, float b){
	double soma = 0.0;
	return (b-a/3) * (funcao_simpson(a) + 4* funcao_simpson(a+b/2) + funcao_simpson(b));	
}
double Bruno::simpson13_composto(float b, float a, int m){
	double h = (b - a) / m;
	double soma = funcao_simpson(a);
	for (i = 0; i < m -2 ; i++)
		soma += 4 * funcao_simpson(h * i) + 2 * funcao_simpson(h * (i + 1));

	soma += 4 * funcao(h * i) + funcao(b);

	return (soma*h)/3;
}

double Bruno::funcao_derivasaoExpanTaylor(int valor){
	return valor;
}
// Com erro O(h^2)
double Bruno::derivasaoExpanTaylor2(int a, int h){
	return (funcao_derivasaoExpanTaylor(a+h) - funcao_derivasaoExpanTaylor(a)/h);
}

double Bruno::derivasaoExpanTaylor3(int a, int h){
	
}

