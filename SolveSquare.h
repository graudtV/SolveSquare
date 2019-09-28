/*!
 * \file
 * \brief Заголовочный файл с прототипами функции SolveSquare() и doublesAreEqual(). Также определяет константу INF_ROOTS
 */

#ifndef SOLVESQUARE
#define SOLVESQUARE

#define INF_ROOTS -1 //!< SolveSquare() возвращает это значение, если ур-ие имеет бесконечно много корней

int doublesAreEqual(double a, double b, double precision);
int SolveSquare(double a, double b, double c, double *x1, double *x2);

#endif

