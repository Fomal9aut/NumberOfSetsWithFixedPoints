@echo off
chcp 866 >nul
set program=NumberOfSetsWithFixedPoints.exe

echo. > results.txt
echo 01 - ������� ���� >> results.txt
echo.  >> results.txt
%program% input1.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input1.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 02 - ������������ ������ ������������ >> results.txt
echo.  >> results.txt
%program% input2.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input2.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 03 - ������������ ���-�� ����� >> results.txt
echo.  >> results.txt
%program% input3.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input3.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 04 - ��� ����������� ����� >> results.txt
echo.  >> results.txt
%program% input4.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input4.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 05 - ����������� ������ ������������, ���� ����� >> results.txt
echo.  >> results.txt
%program% input5.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input5.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 06 - ����������� ������ ������������, ��� ����� >> results.txt
echo.  >> results.txt
%program% input6.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input6.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 07 - �������� ������� ������: ������ �� ������� �� 2� ���������, ����������� �������� >> results.txt
echo ������� ������: >> results.txt
type input7.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
%program% input7.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 08 - �������� ������� ������: ���� �� ��������� �� �������� �����  ������ >> results.txt
echo ������� ������: >> results.txt
type input8.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
%program% input8.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 09 - �������� ������� ������: ������� ���� ������ >> results.txt
echo ������� ������: >> results.txt
type input09.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
%program% input09.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 10 - �������� ������� ������: ������ n �� ����������� ���������� � ����������� ��������� >> results.txt
echo ������� ������: >> results.txt
type input10.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
%program% input10.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 11 - �������� ������� ������: ���-�� ����������� ����� �� ����������� ���������� � ����������� ��������� >> results.txt
echo ������� ������: >> results.txt
type input11.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
%program% input11.txt output.txt >> results.txt