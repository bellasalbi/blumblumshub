/*
 * blumblum.cpp
 *
 *  Created on: 16-10-2014
 *      Author: konrad
 */

#include "blumblum.h"

void sleep(unsigned int );

blumblum::blumblum(int first, int second) : p(first), q(second), stanX(0), stanX_1(0), M(0) {}


blumblum::~blumblum() {
	// TODO Auto-generated destructor stub
	cout << "\nKoniec!";
}
int blumblum::init(){
	int X0 = (czas_w_sekundach())%1000; //liczba od 0 do 1000;
	cout << "X0: "<< X0;
	if(p > 1000 && q > 1000 && p % 4 == 3 && q % 4 == 3 && X0 != 1)
	{
		M = p*q;
		cout << "\nM: " << M;
		while( nwd(M,X0) != 1) X0++;
		stanX = (X0*X0)%M;
		cout << "\nstanX: " << stanX << endl;
	}
	else{
		cout << "\nInne liczby! (>1000) p: ";
		cin >> p;
		cout << "q: ";
		cin >> q;
		blumblum::init();
	}
	return stanX;
}
int blumblum::generuj() {
	return stanX_1 = (stanX*stanX)%M;
}
void blumblum::wypisz_n(int ilosc){
	int iterator = 0;
	while(iterator<ilosc){
		cout << "Liczba " << iterator+1 << " = " << generuj() << endl;
		sleep(750000);
		stanX = stanX_1;
		iterator++;
	}
}
int blumblum::czas_w_sekundach(){
	time_t timer;
	timer = time(&timer);
	return timer;
}
void blumblum::swichthem(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int blumblum::nwd(int &first, int &second)
{
	int a = first;
	int b = second;
	while(a!=b){
		if(a < b)
			b-=a;
		else
			a-=b;
	}
	return a;
}
void sleep(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
