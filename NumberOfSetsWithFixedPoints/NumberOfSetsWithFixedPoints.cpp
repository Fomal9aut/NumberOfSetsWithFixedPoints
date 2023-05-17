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
			return 1;
		}
	
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
				return 1;
			}			
		
			// �������� ������ �������� �� ������
			char* ptr2 = strtok(NULL, " ");		
			// ���� ������ �������� �������� �� �������
			//(������ ����� ������� ����� ��� �������������� ���������� ������ ������ ��� ���������� ����� ����������)
			if (ptr2 == NULL)		
			{
				fout << "������������ ������ ������� ������: ����������� ��������\n";
				return 1;
			}
			
			// �������� ������� ��������� ����� �����, ������ ���� ������ ������ ��������
			if(InputFlagFirstArgument == 1) 
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
					return 1;
				}
				
			}
	
		// ���� ��� ��������� ������� ������ ��������
		 if(InputFlagFirstArgument && InputFlagSecondArgument) 
		 {
			// ���������, ������������� �� ������ �������� ���������
			if (FirstArgument < 0 || FirstArgument > 9)						
			{
				fout << "������� n = " << FirstArgument << " ��� ��������� [1..9].\n";
				return 1;
			}

			// ���������, ������������� �� ������ �������� ���������
			if (SecondArgument < 0 || SecondArgument > FirstArgument)					
			{
				fout << "������� k = " << SecondArgument << " ��� ��������� [0.." << FirstArgument << "]\n";
				return 1;
			}
			
			// ������� ��������� ������� � ����
			fout << NumOfSetsFixedPts(FirstArgument, SecondArgument);
			fout.close();
			
		 }
	}
	else
	{
		fout << "���������� ������� ����\n";
	}

	return 0;
}



uint numOfSetsNoFixedPts(uint n)
{
	// ��� ���������� ���������� ���������� ����� ��������� ��� ����������� ��������
	// oddIndex ������ ������������� ����������� �������� � �������� ��������, evenIndex - ��������� � ������ ��������
	uint oddIndex = 0, evenIndex = 1;			   
	for (uint i = 2; i < n; i++)
		// ���� ������ �������� ��������, �� �������� ����������� � ������������ � evenIndex, ����� - �  oddIndex
		if (i % 2)								  
		{
			evenIndex = i * (oddIndex + evenIndex);
		}
		else									   
		{
			oddIndex = i * (oddIndex + evenIndex);
		}
	// ����� �������� �������� ��������� ������������ ����� �������� ����������
	return n % 2 ? oddIndex : evenIndex;		   
}

uint NumOfCombOfmFromN(uint n, uint m)
{
	// ��������� ��������, �� ������� ����� ��������� ���������� ��� ����� ������������ ����������
	uint k = n - m;									 
	if (m > k)
		m = k;										
	// ���� ����� ��������� �� ������� 0
	if (!m)											 
		return 1;
	// ��������� � ����������� ����� ���������� �����������
	uint numerator = k = n + 1 - m, denominator = 1; 
	k++;
	// ���������� ��������� �������� ��������� � �����������
	for (uint i = 2; i <= m; i++, k++)				 
	{
		numerator *= k;
		denominator *= i;
	}
	return numerator / denominator;
}

uint NumOfSetsFixedPts(uint n, uint m)
{
	return NumOfCombOfmFromN(n, m) * numOfSetsNoFixedPts(n - m);
}