@echo off
chcp 866 >nul
set program=NumberOfSetsWithFixedPoints.exe

echo. > results.txt
echo 01 - Òèïîâîé òåñò >> results.txt
echo.  >> results.txt
%program% input1.txt output.txt >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input1.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 02 - Ìàêñèìàëüíûé ðàçìåð ïåðåñòàíîâêè >> results.txt
echo.  >> results.txt
%program% input2.txt output.txt >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input2.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 03 - Ìàêñèìàëüíîå êîë-âî òî÷åê >> results.txt
echo.  >> results.txt
%program% input3.txt output.txt >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input3.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 04 - Íåò íåïîäâèæíûõ òî÷åê >> results.txt
echo.  >> results.txt
%program% input4.txt output.txt >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input4.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 05 - Ìèíèìàëüíûé ðàçìåð ïåðåñòàíîâêè, îäíà òî÷êà >> results.txt
echo.  >> results.txt
%program% input5.txt output.txt >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input5.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 06 - Ìèíèìàëüíûé ðàçìåð ïåðåñòàíîâêè, íåò òî÷åê >> results.txt
echo.  >> results.txt
%program% input6.txt output.txt >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input6.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 07 - Íåâåðíûå âõîäíûå äàííûå: Ñòðîêà íå ñîñòîèò èç 2õ ýëåìåíòîâ, ðàçäåëåííûõ ïðîáåëîì >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input7.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
%program% input7.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 08 - Íåâåðíûå âõîäíûå äàííûå: Îäèí èç ýëåìåíòîâ íå ÿâëÿåòñÿ öåëûì  ÷èñëîì >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input8.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
%program% input8.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 09 - Íåâåðíûå âõîäíûå äàííûå: Âõîäíîé ôàéë ïóñòîé >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input09.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
%program% input09.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 10 - Íåâåðíûå âõîäíûå äàííûå: Ðàçìåð n íå ïðèíàäëåæèò óêàçàííîìó â òðåáîâàíèÿõ äèàïàçîíó >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input10.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
%program% input10.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 11 - Íåâåðíûå âõîäíûå äàííûå: Êîë-âî íåïîäâèæíûõ òî÷åê íå ïðèíàäëåæèò óêàçàííîìó â òðåáîâàíèÿõ äèàïàçîíó >> results.txt
echo ÂÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
type input11.txt >> results.txt
echo.  >> results.txt
echo ÂÛÕÎÄÍÛÅ ÄÀÍÍÛÅ: >> results.txt
%program% input11.txt output.txt >> results.txt