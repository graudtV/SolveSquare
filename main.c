/*!
 * \file
 * \version 1.1 Теперь ввод реализуется через функцию getNewData
 *
 * \brief Файл с примером работы с функцией SolveSquare()
 * 
 * Программа показывает пример работы с функцией SolveSquare() а также включает возможность
 * юнит-тестирования этой функции
 * 
 * Сначала проводится юнит-тест (если он включен параметром TEST_SOLVESQUARE), далее программа считывает из стандартного ввода 3 числа - коэффициенты a, b, c - и 
 * вычисляет корни соответсвующего квадратного уравнения
 */

#include <stdio.h>
#include "stdlib.h" //for function free()
#include "SolveSquare.h"
#include "Input.h"

#define bool short //!< Введено для удобства, т.к. в C нет типа bool.
#define true 1
#define false 0


/*!
 * \brief Включает/выключает режим юнит-тестирования функции SolveSquare()
 *
 * При значении 0 тест выключен.
 * При значении 1 - включен1
 */
#define TEST_SOLVESQUARE 1

#if (TEST_SOLVESQUARE)
int testSolveSquare();
#endif

/*!
 * \brief Содержит реализацию примера работы.
 */

int main()
{
	double x1 = 0, x2 = 0;
	int nRoots = 0;

	#if(TEST_SOLVESQUARE)
	if(testSolveSquare() == 1) //if test is unsuccessful
		return 1; //main returns 1;
	#endif


	double *koeffs = getNewData("Enter a, b, c:", 3);

	nRoots = SolveSquare(koeffs[0], koeffs[1], koeffs[2], &x1, &x2);
	switch(nRoots)
	{
		case 0:
			printf("No roots:(\n");
			break;
		case 1:
			printf("One root: x1 = x2 = %lg;\n", x1);
			break;
		case 2:
			printf("Two roots: x1 = %lg;  x2 = %lg;\n", x1, x2);
			break;	
		case INF_ROOTS:
			printf("Inf. number of roots;\n");
			break;	
		default:
			printf("Error! nRoots = %d\n", nRoots);
			break;		
	}

	free(koeffs);

	return 0;
}

#if (TEST_SOLVESQUARE)
/*!
 * \brief Функция для тестирования SolveSquare()
 *
 * В случае возникновения ошибки выводит сообщение с пояснениями в стандартный вывод и возвращает 1.
 * \returns 0 Если тест прошёл успешно
 * \returns 1 Если возникла ошибка.
 */
int testSolveSquare() 
{
	const double PRECISION = 0.001; //!< sets precision of checking for the test

	double a = 0, b = 0, c = 0;
	double x1 = 0, x2 = 0;
	int nRoots = 0;

	printf("\nTest of SolveSquare is started.\n");

	const int INTERVAL = 100;
	//test's body	
	for(a = -INTERVAL; a < INTERVAL; ++a)
		for(b = -INTERVAL; b < INTERVAL; ++b)
			for(c = -INTERVAL; c < INTERVAL; ++c)
	{
		bool errorOccured = false;
		nRoots = SolveSquare(a, b,c, &x1, &x2);

		if(nRoots != 1 && nRoots != 2 && nRoots !=0 && nRoots != INF_ROOTS)
		{
			printf("\nERROR: nRoots is incorrect! \n");
			errorOccured=true;				
		}
		if(nRoots == 0)
		{
			double D = b * b - 4 * a * c;
			if( !doublesAreEqual(a, 0.0, PRECISION) && D >= 0 )
			{
			printf("\nERROR: nRoots == 0, but D >= 0 \n");
			errorOccured = true;							
			}
			if( doublesAreEqual(a, 0.0, PRECISION) && doublesAreEqual(b, 0.0, PRECISION) && doublesAreEqual(c, 0.0, PRECISION) )
			{
			printf("\nERROR: nRoots==0, but number of roots is infinitive.\n");
			errorOccured = true;							
			}		
		}
		if( (nRoots == 1 || nRoots == 2 ) && !doublesAreEqual(a * x1 * x1 + b * x1 + c, 0.0, PRECISION) )
		{
			printf("\nERROR: x1 is not a root! \n");
			errorOccured = true;
		}
		if( (nRoots == 2) && !doublesAreEqual(a * x2 * x2 + b * x2 + c, 0.0, PRECISION) )
		{
			printf("\nERROR: x2 is not a root! \n");
			errorOccured = true;				
		}
		if( nRoots == INF_ROOTS &&
		!(doublesAreEqual(a, 0.0, PRECISION) && doublesAreEqual(b, 0.0, PRECISION) && doublesAreEqual(c, 0.0, PRECISION)) )
		{
			printf("\nERROR: nRoots==INF_ROOTS, but nubmer of roots is not infinitive \n");
			errorOccured = true;		
		}

		if(errorOccured)
		{
			printf("SolveSquare works incorrectly!\n");
			printf("Input values:\n a: %lg; \n b: %lg; \n c: %lg; \n", a, b, c);
			printf("Output values:\n nRoots: %d; \n x1: %lg; \n x2: %lg; \n", nRoots, x1, x2);
			return 1; 
		}
	}	


	printf("Tested successfully! \n\n");
	return 0;
}
#endif