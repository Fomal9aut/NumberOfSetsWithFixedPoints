#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Functions.h"


int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		std::cerr << "Неправильно введены параметры запуска"
			<< "Параметры должны соответствовать шаблону: \n"
			<< argv[0] << "<path/to/input_file> <path/to/save_file> \n";
		return 1;
	}

	setlocale(LC_ALL, "rus");
	// буфер для хранения входных данных из файла, получаемых строкой
	char buff[50] = "";		
	// считываем данные из файла, путь которого указан в параметрах запуска программы
	std::ifstream fin(argv[1]);	

	// если файл с входными данными успешно открыт
	if (fin.is_open())	
	{
		// считываем входные данные из файла в буфер
		fin.getline(buff, 50);
	}
	else
	{
		std::cout << "Невозможно открыть файл\n";
		fin.close();
		return 1;
	}

		char buffCopy[50];
		// копируем строку для ее проверки
		strcpy(buffCopy, buff);
		// закрываем поток считывания из файла
		fin.close();
		// переменная для хранения первого аргумента
		uint FirstArgument = 0,		
		// переменная для хранения второго аргумента
		SecondArgument = 0,		
		// переменная-флаг, сигнализирующая о успешной валидации первого аргумента
		InputFlagFirstArgument = 0,			
		// переменная-флаг, сигнализирующая о успешной валидации второго аргумента
		InputFlagSecondArgument = 0;		

		// получаем первый аргумент из строки
		char* ptr1 = strtok(buffCopy, " ");		
		// если первый аргумент получить не удалось
		if (ptr1 == NULL)						
		{		
			std::cout << "Недопустимый формат входных данных: отсутствует аргумент\n";
			return 1;
		}
	
			// приводим первый аргумент к числу	
		FirstArgument = atoi(ptr1);			
			// если аргумент успешно приведен к числу, считаем что он прошел проверку, иначе выводим ошибку
		if (FirstArgument != 0)				
		{
			InputFlagFirstArgument = 1;
		}
		else
		{
			std::cout << "Недопустимые входные данные: операнд должен быть натуральным десятичным числом, отличным от нуля\n";
			return 1;
		}			
		
		// получаем второй аргумент из строки
		char* ptr2 = strtok(NULL, " ");		
		// если второй аргумент получить не удалось
		//(правая часть условия нужна для предотвращения повторного вывода ошибки при отсутствии обоих аргументов)
		if (ptr2 == NULL)		
		{
			std::cout << "Недопустимый формат входных данных: отсутствует аргумент\n";
			return 1;
		}
			
		// проверка второго аргумента имеет смысл, только если первый прошел проверку
		if(InputFlagFirstArgument == 1) 
		{
			// приводим второй аргумент к числу
			SecondArgument = atoi(ptr2);		
			// т.к. второй аргумент может быть 0, то atoi вернет тот же результат, как если бы были переданы неправильные данные
			// чтобы корректно обрабатывать 0 для второго аргумента, дополнительно проверяем, является ли переданная строка нулем
			// если второй аргумент успешно преобразован к числу или является нулем, то он прошел проверку
			if (SecondArgument != 0 || !strcmp(ptr2, "0"))
			{
				InputFlagSecondArgument = 1;
			}
			else
			{
				std::cout << "Недопустимые входные данные: операнд должен быть натуральным десятичным числом\n";
				return 1;
			}			
		}
	
		// если оба аргумента успешно прошли проверку
		 if(InputFlagFirstArgument && InputFlagSecondArgument) 
		 {
			// проверяем, удовлетворяет ли первый аргумент диапазону
			if (FirstArgument < 0 || FirstArgument > 9)						
			{
				std::cout << "операнд n = " << FirstArgument << " вне диапазона [1..9].\n";
				return 1;
			}

			// проверяем, удовлетворяет ли второй аргумент диапазону
			if (SecondArgument < 0 || SecondArgument > FirstArgument)					
			{
				std::cout << "операнд k = " << SecondArgument << " вне диапазона [0.." << FirstArgument << "]\n";
				return 1;
			}
			
			// создаем выходной файл по пути, указанному в параметрах запуска программы
			std::ofstream fout(argv[2]);
			// выводим результат функции в файл
			fout << NumOfSetsFixedPts(FirstArgument, SecondArgument);
			fout.close();
			
		 }
	return 0;
}



uint numOfSetsNoFixedPts(uint n)
{
	// для вычисления результата достаточно знать последние два вычесленных значения
	// oddIndex хранит предпоследнее вычисленное значение с нечетным индексом, evenIndex - последнее с четным индексом
	uint oddIndex = 0, evenIndex = 1;			   
	for (uint i = 2; i < n; i++)
		// если данная итерация нечетная, то значение вычисляется и записывается в evenIndex, иначе - в  oddIndex
		if (i & 1)								  
		{
			evenIndex = i * (oddIndex + evenIndex);
		}
		else									   
		{
			oddIndex = i * (oddIndex + evenIndex);
		}
	// через четность входного параметра определяется какое значение возвращать
	return n % 2 ? oddIndex : evenIndex;		   
}

uint NumOfCombOfmFromN(uint n, uint m)
{
	// вычисляем значение, на которое нужно сократить факториалы для более эффективного вычисления
	uint k = n - m;									 
	if (m > k)
		m = k;										
	// если число элементов из выборки 0
	if (!m)											 
		return 1;
	// числитель и знаменатель после сокращения факториалов
	uint numerator = k = n + 1 - m, denominator = 1; 
	k++;
	// циклически вычисляем значения числителя и знаменателя
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