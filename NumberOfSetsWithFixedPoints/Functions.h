#pragma once
typedef unsigned int uint;
/*! вычисляет количество перестановок длиной n без неподвижных точек
* \param[in] n - длина перестановки
* \param[out] - количество перестановок
*/
uint numOfSetsNoFixedPts(uint n);

/*! вычисляет количество перестановок длиной n без неподвижных точек
* \param[in] n - количество всего элементов
* \param[in] m - количество элементов
* \param[out] numerator / denominator - значение сочетаний из n по m
*/
uint NumOfCombOfmFromN(uint n, uint m);

/*! вычисляет количество перестановок длиной n с m неподвижными точками
* \param[in] n - длина перестановки
* \param[in] m - количество неподвижных точек
* \param[out] NumOfSetsFixedPts - число перестановок длиной n с m неподвижными точками
*/
uint NumOfSetsFixedPts(uint n, uint m);
