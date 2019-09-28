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

/*!
 * \brief Проверяет, равны ли два числа типа double
 *
 * \param [in] a, b Значения, которые нужно проверить на равенство
 * \param [in] precision Точность сравнения (абсолютная). Если числа a и b отличается на меньшее значение, то считается, что числа равны.
 * \returns 1 Если числа равны в пределах заданной точности
 * \returns 0 Числа не равны 
 */
int doublesAreEqual(double a, double b, double precision)
{
	return (fabs(a-b) <= precision) ? 1 : 0;
}

/*!
	\brief Функция для вычисления корней квадратного трёхчлена (уравнения).

	Находит корни уравнения ax^2+bx+c=0.
	Результаты вычисления помещает в x1, x2 (передаются по указателю).

	\param [in] a, b, c  параметры a, b и c уравнения
	\param x1 - указатель на первый корень
	\param x2 - указатель на второй корень

	\returns 1, 2 - Количество корней, если они есть
	\returns 0 Если корней нет
	\returns INF_ROOTS Если у уравнения бесконечно много корней.

	\warning Всегда проверяйте, чему равно возвращенное функцией значение, т.е. количество корней уравнения.
			 Если корней меньше 2, то в переменных x1 и(или) x2 может оказаться мусор!

	Если у уравнения 2 различных корня, то гарантируется, что x1 < x2.
*/
int SolveSquare(double a, double b, double c, double *x1, double *x2)
{
	const double PRECISION = 0.001;

	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

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
	double sqrtD = sqrt(D);
	*x1 = (-b - sqrtD) / (2 * a);
	*x2 = (-b + sqrtD) / (2 * a);
	if(doublesAreEqual(D, 0.0, PRECISION))
	{
		*x2 = *x1;
		return 1;
	}
	return 2;
}