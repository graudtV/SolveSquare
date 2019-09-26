#include "math.h" //for NAN
#include "stdio.h" //for rewind
#include "stdlib.h" //for calloc
#include "assert.h"
/*!
 * \brief Заполняет массив чисел типа double каким-либо числом
 *
 * \param [out] arr[] Массив, который нужно заполнить
 * \param [in] nElements Количество элементов в массиве. Можно заполнить не все элементы,
 * а только первые nElemets, считая от начала
 * \param [in] value Значение, которое присвоиться каждому элементу массива
 * с индексом от 0 до nElements - 1. В частности, можно присвоить нули или NAN.
 */
void FillDArray(double arr[], size_t nElements, double value)
{
	for(int i = 0; i < nElements; ++i)
		arr[i] = value;
}

/*!
 * \brief Выводит массив в стандартный вывод
 *
 * \param arr[] Массив, который нужно вывести
 * \param from Начиная с какого индекса выводит
 * \param to Заканчивая каким
 *
 * Пример использования:
 * \code
 * double values[] = {1, 2.5, 3};
 * printDArray(values, 0, 2);
 * \endcode
 */
void printDArray(const double arr[], size_t from, size_t to)
{
	for(int k = from; k <= to; ++k)
		printf("  (%4d) ", k);
	printf("\n");
	for(int k = from; k <= to; ++k)
		printf(" %7lg ", arr[k]); 
	printf("\n");
}


void Input(const char prompt[], double mas[], size_t nElements) //Version 1
{
	assert(prompt != NULL);
	assert(mas != NULL);

	printf("%s\n", prompt);
	for(int i = 0; i < nElements; ++i)
	{
		rewind(stdin); //clears stdin
		printf("[%d/%lu]: ", i + 1, nElements);
		if(scanf("%lg", mas + i) != 1 || getchar() != '\n') //incorrect input
		{
			printf("ERROR : Incorrect input! Try again!\n");
			--i;
			continue;
		}
	}
}


double *getNewData(const char prompt[], size_t nElements) //Version 2
{
	assert(prompt != NULL);
	double *data = calloc(nElements, sizeof(data[0]));
	if(data == NULL) //BAD_ALLOC
	{
		printf("ERROR: BAD_ALLOC\n");
		return NULL;
	}

	Input(prompt, data, nElements);
	return data;
}