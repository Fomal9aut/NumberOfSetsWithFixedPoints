#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Functions.h"


int main()
{
    std::cout << "Hello World!\n";
}


/*! ��������� ���������� ������������ ������ n ��� ����������� �����
* \param[in] n - ����� ������������
* \param[out] - ���������� ������������
*/
uint numOfSetsNoFixedPts(uint n)
{
	return n;
}
/*! ��������� ���������� ������������ ������ n ��� ����������� �����
* \param[in] n - ���������� ����� ���������
* \param[in] m - ���������� ���������
* \param[out] numerator / denominator - �������� ��������� �� n �� m
*/
uint NumOfCombOfmFromN(uint n, uint m)
{
	uint k = n - m; // �������� ����������, �� ������� �� �������� �����������
	if (m > k)
		m = k;
	if (!m) // ���� m = 0
		return 1;
	uint numerator = k = n + 1 - m, denominator = 1; // ��������� � ����������� ����� ���������� �����������
	k++;
	for (uint i = 2; i <= m; i++, k++) // ���������� ��������� �������� ��������� � �����������
	{
		numerator *= k;
		denominator *= i;
	}
	return numerator / denominator;
}
/*! ��������� ���������� ������������ ������ n � m ������������ �������
* \param[in] n - ����� ������������
* \param[in] m - ���������� ����������� �����
* \param[out] NumOfSetsFixedPts - ����� ������������ ������ n � m ������������ �������
*/
uint NumOfSetsFixedPts(uint n, uint m)
{
	return m;
}