#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Functions.h"


int main()
{
    std::cout << "Hello World!\n";
}


/*! вычисляет количество перестановок длиной n без неподвижных точек
* \param[in] n - длина перестановки
* \param[out] - количество перестановок
*/
uint numOfSetsNoFixedPts(uint n)
{
	// для вычисления результата достаточно знать последние два вычесленных значения
	uint oddIndex = 0, evenIndex = 1;			   // oddIndex хранит предпоследнее вычисленное значение с нечетным индексом, evenIndex - последнее с четным индексом
	for (uint i = 2; i < n; i++)
		if (i % 2)								   // если данная итерация нечетная  
			evenIndex = i * (oddIndex + evenIndex);// значение вычисляется и записывается в evenIndex
		else									   // иначе
			oddIndex = i * (oddIndex + evenIndex); // значение вычисляется и записывается в oddIndex
	return n % 2 ? oddIndex : evenIndex;		   // через четность определяется какое значение возвращать
}
/*! вычисляет количество перестановок длиной n без неподвижных точек
* \param[in] n - количество всего элементов
* \param[in] m - количество элементов
* \param[out] numerator / denominator - значение сочетаний из n по m
*/
uint NumOfCombOfmFromN(uint n, uint m)
{
	uint k = n - m;									 // вычисляем значение, на которое нужно сократить факториалы для более эффективного вычисления
	if (m > k)
		m = k;
	if (!m)											 // если число элементов из выборки 0
		return 1;
	uint numerator = k = n + 1 - m, denominator = 1; // числитель и знаменатель после сокращения факториалов
	k++;
	for (uint i = 2; i <= m; i++, k++)				 // циклически вычисляем значения числителя и знаменателя
	{
		numerator *= k;
		denominator *= i;
	}
	return numerator / denominator;
}
/*! вычисляет количество перестановок длиной n с m неподвижными точками
* \param[in] n - длина перестановки
* \param[in] m - количество неподвижных точек
* \param[out] NumOfSetsFixedPts - число перестановок длиной n с m неподвижными точками
*/
uint NumOfSetsFixedPts(uint n, uint m)
{
	return NumOfCombOfmFromN(n, m) * numOfSetsNoFixedPts(n - m);
}