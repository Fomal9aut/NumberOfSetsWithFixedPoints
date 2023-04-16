#pragma once
typedef unsigned int uint;
/*! ��������� ���������� ������������ ������ n ��� ����������� �����
* \param[in] n - ����� ������������
* \param[out] - ���������� ������������
*/
uint numOfSetsNoFixedPts(uint n);

/*! ��������� ���������� ������������ ������ n ��� ����������� �����
* \param[in] n - ���������� ����� ���������
* \param[in] m - ���������� ���������
* \param[out] numerator / denominator - �������� ��������� �� n �� m
*/
uint NumOfCombOfmFromN(uint n, uint m);

/*! ��������� ���������� ������������ ������ n � m ������������ �������
* \param[in] n - ����� ������������
* \param[in] m - ���������� ����������� �����
* \param[out] NumOfSetsFixedPts - ����� ������������ ������ n � m ������������ �������
*/
uint NumOfSetsFixedPts(uint n, uint m);
