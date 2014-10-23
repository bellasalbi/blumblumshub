/*
 * blumblum.h
 *
 *  Created on: 16-10-2014
 *      Author: konrad
 */

#ifndef BLUMBLUM_H_
#define BLUMBLUM_H_

#include <iostream>
#include <ctime>
#include <time.h>
#include <math.h>

using namespace std;

class blumblum {
public:
	blumblum(int, int);
	virtual ~blumblum();
	int init();
	int generuj();
	int nwd(int &,int &);
	int czas_w_sekundach();
	void swichthem(int &, int &);
	void wypisz_n(int );
private:
	unsigned long int stanX; //dla init - pierwszy stan
	unsigned long int stanX_1; //stany kolejne
	int p;
	int q; //p*q = M - dzielnik
	int M;
};

#endif /* BLUMBLUM_H_ */
