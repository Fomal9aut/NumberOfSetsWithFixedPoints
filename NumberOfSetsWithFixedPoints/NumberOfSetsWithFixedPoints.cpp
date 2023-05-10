#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Functions.h"


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	// ����� ��� �������� ������� ������ �� �����, ���������� �������
	char buff[50] = "";		
	// ��������� ������ �� �����, ���� �������� ������ � ���������� ������� ���������
	std::ifstream fin(argv[1]);	
	// ������� �������� ���� �� ����, ���������� � ���������� ������� ���������
	std::ofstream fout(argv[2]);

	// ���� ���� � �������� ������� ������� ������
	if (fin.is_open())	
	{
		// ��������� ������� ������ �� ����� � �����
		fin.getline(buff, 50);		
		char buffCopy[50];
		// �������� ������ ��� �� ��������
		strcpy(buffCopy, buff);		

		// ���������� ��� �������� ������� ���������
		uint FirstArgument = 0,		
		// ���������� ��� �������� ������� ���������
		SecondArgument = 0,		
		// ����������-����, ��������������� � �������� ��������� ������� ���������
		InputFlagFirstArgument = 0,			
		// ����������-����, ��������������� � �������� ��������� ������� ���������
		InputFlagSecondArgument = 0;		

		// �������� ������ �������� �� ������
		char* ptr1 = strtok(buffCopy, " ");		
		// ���� ������ �������� �������� �� �������
		if (ptr1 == NULL)						
		{		
			fout << "������������ ������ ������� ������: ����������� ��������\n";
		}
		else {
			// �������� ������ �������� � �����	
			FirstArgument = atoi(ptr1);			
			// ���� �������� ������� �������� � �����, ������� ��� �� ������ ��������, ����� ������� ������
			if (FirstArgument != 0)				
			{
				InputFlagFirstArgument = 1;
			}
			else
			{
				fout << "������������ ������� ������: ������� ������ ���� ����������� ���������� ������, �������� �� ����\n";
			}			
		}
			// �������� ������ �������� �� ������
			char* ptr2 = strtok(NULL, " ");		
			// ���� ������ �������� �������� �� �������
			//(������ ����� ������� ����� ��� �������������� ���������� ������ ������ ��� ���������� ����� ����������)
			if (ptr2 == NULL && ptr1 != NULL)		
			{
				fout << "������������ ������ ������� ������: ����������� ��������\n";
			}
			// �������� ������� ��������� ����� �����, ������ ���� ������ ������ ��������
			else if((InputFlagFirstArgument == 1))  
			{
				// �������� ������ �������� � �����
				SecondArgument = atoi(ptr2);		
				// �.�. ������ �������� ����� ���� 0, �� atoi ������ ��� �� ���������, ��� ���� �� ���� �������� ������������ ������
				// ����� ��������� ������������ 0 ��� ������� ���������, ������������� ���������, �������� �� ���������� ������ �����
				// ���� ������ �������� ������� ������������ � ����� ��� �������� �����, �� �� ������ ��������
				if ((SecondArgument != 0) || (SecondArgument == 0 && !strcmp(ptr2, "0")))			
				{
					InputFlagSecondArgument = 1;
				}
				else
				{
					fout << "������������ ������� ������: ������� ������ ���� ����������� ���������� ������\n";
				}
				
			}
	
		// ���� ��� ��������� ������� ������ ��������
		 if(InputFlagFirstArgument && InputFlagSecondArgument) 
		 {
			// ���������, ������������� �� ������ �������� ���������
			if (FirstArgument < 0 || FirstArgument > 9)						
			{
				fout << "������� n = " << FirstArgument << " ��� ��������� [1..9].\n";
			}
			else {

				// ���������, ������������� �� ������ �������� ���������
				if (SecondArgument < 0 || SecondArgument > FirstArgument)					
				{
					fout << "������� k = " << SecondArgument << " ��� ��������� [0.." << FirstArgument << "]\n";
				}
				else {			
					// ������� ��������� ������� � ����
					fout << NumOfSetsFixedPts(FirstArgument, SecondArgument);
					fout.close();
				}
			}
		 }

	}
	else
	{
		fout << "���������� ������� ����\n";
	}

	return 0;
}


/*! ��������� ���������� ������������ ������ n ��� ����������� �����
* \param[in] n - ����� ������������
* \param[out] - ���������� ������������
*/
uint numOfSetsNoFixedPts(uint n)
{
	// ��� ���������� ���������� ���������� ����� ��������� ��� ����������� ��������
	uint oddIndex = 0, evenIndex = 1;			   // oddIndex ������ ������������� ����������� �������� � �������� ��������, evenIndex - ��������� � ������ ��������
	for (uint i = 2; i < n; i++)
		if (i % 2)								   // ���� ������ �������� ��������  
			evenIndex = i * (oddIndex + evenIndex);// �������� ����������� � ������������ � evenIndex
		else									   // �����
			oddIndex = i * (oddIndex + evenIndex); // �������� ����������� � ������������ � oddIndex
	return n % 2 ? oddIndex : evenIndex;		   // ����� �������� ������������ ����� �������� ����������
}
/*! ��������� ���������� ������������ ������ n ��� ����������� �����
* \param[in] n - ����� ���������� ���������
* \param[in] m - ���������� ��������� �������
* \param[out] numerator / denominator - �������� ��������� �� n �� m
*/
uint NumOfCombOfmFromN(uint n, uint m)
{
	uint k = n - m;									 // ��������� ��������, �� ������� ����� ��������� ���������� ��� ����� ������������ ����������
	if (m > k)
		m = k;											
	if (!m)											 // ���� ����� ��������� �� ������� 0
		return 1;
	uint numerator = k = n + 1 - m, denominator = 1; // ��������� � ����������� ����� ���������� �����������
	k++;
	for (uint i = 2; i <= m; i++, k++)				 // ���������� ��������� �������� ��������� � �����������
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
	return NumOfCombOfmFromN(n, m) * numOfSetsNoFixedPts(n - m);
}