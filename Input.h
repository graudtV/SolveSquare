/*!
 * \file 
 * \brief Заголовочный файл с удобными функциями для ввода-вывода числовых массивов
 */

#ifndef INPUT_FUNCTIONS
#define INPUT_FUNCTIONS

void fillDArray(double arr[], size_t nElements, double value);
void printDArray(const double arr[], size_t from, size_t to);
void input(const char prompt[], double mas[], size_t nElements); //Version 1
double *getNewData(const char prompt[], size_t nElements); //Version 2

#endif
