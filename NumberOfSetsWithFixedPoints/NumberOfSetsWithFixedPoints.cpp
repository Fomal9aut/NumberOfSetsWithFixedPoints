#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Functions.h"


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	// буфер для хранения входных данных из файла, получаемых строкой
	char buff[50] = "";		
	// считываем данные из файла, путь которого указан в параметрах запуска программы
	std::ifstream fin(argv[1]);	
	// создаем выходной файл по пути, указанному в аргументах запуска программы
	std::ofstream fout(argv[2]);

	// если файл с входными данными успешно открыт
	if (fin.is_open())	
	{
		// считываем входные данные из файла в буфер
		fin.getline(buff, 50);		
		char buffCopy[50];
		// копируем строку для ее проверки
		strcpy(buffCopy, buff);		

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
			fout << "Недопустимый формат входных данных: отсутствует аргумент\n";
		}
		else {
			// приводим первый аргумент к числу	
			FirstArgument = atoi(ptr1);			
			// если аргумент успешно приведен к числу, считаем что он прошел проверку, иначе выводим ошибку
			if (FirstArgument != 0)				
			{
				InputFlagFirstArgument = 1;
			}
			else
			{
				fout << "Недопустимые входные данные: операнд должен быть натуральным десятичным числом, отличным от нуля\n";
			}			
		}
			// получаем второй аргумент из строки
			char* ptr2 = strtok(NULL, " ");		
			// если второй аргумент получить не удалось
			//(правая часть условия нужна для предотвращения повторного вывода ошибки при отсутствии обоих аргументов)
			if (ptr2 == NULL && ptr1 != NULL)		
			{
				fout << "Недопустимый формат входных данных: отсутствует аргумент\n";
			}
			// проверка второго аргумента имеет смысл, только если первый прошел проверку
			else if((InputFlagFirstArgument == 1))  
			{
				// приводим второй аргумент к числу
				SecondArgument = atoi(ptr2);		
				// т.к. второй аргумент может быть 0, то atoi вернет тот же результат, как если бы были переданы неправильные данные
				// чтобы корректно обрабатывать 0 для второго аргумента, дополнительно проверяем, является ли переданная строка нулем
				// если второй аргумент успешно преобразован к числу или является нулем, то он прошел проверку
				if ((SecondArgument != 0) || (SecondArgument == 0 && !strcmp(ptr2, "0")))			
				{
					InputFlagSecondArgument = 1;
				}
				else
				{
					fout << "Недопустимые входные данные: операнд должен быть натуральным десятичным числом\n";
				}
				
			}
	
		// если оба аргумента успешно прошли проверку
		 if(InputFlagFirstArgument && InputFlagSecondArgument) 
		 {
			// проверяем, удовлетворяет ли первый аргумент диапазону
			if (FirstArgument < 0 || FirstArgument > 9)						
			{
				fout << "операнд n = " << FirstArgument << " вне диапазона [1..9].\n";
			}
			else {

				// проверяем, удовлетворяет ли второй аргумент диапазону
				if (SecondArgument < 0 || SecondArgument > FirstArgument)					
				{
					fout << "операнд k = " << SecondArgument << " вне диапазона [0.." << FirstArgument << "]\n";
				}
				else {			
					// выводим результат функции в файл
					fout << NumOfSetsFixedPts(FirstArgument, SecondArgument);
					fout.close();
				}
			}
		 }

	}
	else
	{
		fout << "Невозможно открыть файл\n";
	}

	return 0;
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
* \param[in] n - общее количество элементов
* \param[in] m - количество элементов выборки
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