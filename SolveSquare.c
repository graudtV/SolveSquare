/*!
 * \file
 * \version 1.0
 * \brief
 *  Включает реализвции функции SolveSquare() и doublesAreEqual()
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "SolveSquare.h"


int doublesAreEqual(double a, double b, double precision)
{
	return (fabs(a-b) <= precision) ? 1 : 0;
}


int SolveSquare(double a, double b, double c, double *x1, double *x2)
{
	const double PRECISION = 0.001;

	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	//assert()
	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);

	if(a == 0)
	{
		if(b == 0) return (c == 0) ? INF_ROOTS : 0;
		//if b!=0:
		*x1 = -(c / b);
		return 1;
	}
	//if a!=0:
	double D = b * b-4 * a * c;
	if(D < 0) return 0;
	*x1 = (-b - sqrt(D)) / (2 * a);
	*x2 = (-b + sqrt(D)) / (2 * a);
	if(doublesAreEqual(D, 0.0, PRECISION)) return 1;
	return 2;
}