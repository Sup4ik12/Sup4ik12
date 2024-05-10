#include "TXLib.h"

int main()
{
    txCreateWindow(1300,730);

    int nQue = 52;

    string question = "Когда Владамир Святославович крестил Русь?";
    string v1 ="1050";
    string v2 ="988";
    string v3 ="999";

    HDC pict1 = txLoadImage("1050.bmp");
    HDC pict2 = txLoadImage("988.bmp");
    HDC pict3 = txLoadImage("999.bmp");

    if(nQue == 1)
    {
        question = "Когда Владамир Святославович крестил Русь?";
        v1 ="1050";
        v2 ="988";
        v3 ="999";
    }
    else
    {
        question = "Когда Владамир Святославович крестил Русь?";
        v2 ="1050";
        v3 ="988";
        v1 ="999";
    }


    //шаблон
    txSelectFont("Comic Sans",40);
    txSetColor(TX_WHITE);
    txSetFillColor(TX_TRANSPARENT);
    //номер вопроса
    txDrawText(1129,30,1300,78,"Вопрос №_");
    //первый вариант ответа
    txRectangle(103,273,410,562);
    txBitBlt(txDC(),103,273,307,289,pict1);
    //второй вариант ответа
    txRectangle(504,273,810,562);
    txBitBlt(txDC(),504,273,307,289,pict2);
    //третий вариант ответа
    txRectangle(893,273,1199,562);
    txBitBlt(txDC(),893,273,307,289,pict3);

    //вопрос
    txRectangle(269,67,1011,167);
    txDrawText(269,67,1011,167,question.c_str());
    //комментарий к 1 вопросу
    txRectangle(103+39,562+24,410-39,562+24+33);
    txDrawText(103+39,562+24,410-39,562+24+33,v1.c_str());
    //комментарий ко 2 вопросу
    txRectangle(504+39,562+24,810-39,562+24+33);
    txDrawText(504+39,562+24,810-39,562+24+33,v2.c_str());
    //комментарий к 3 вопросу
    txRectangle(893+39,562+24,1199-39,562+24+33);
    txDrawText(893+39,562+24,1199-39,562+24+33,v3.c_str());

    txDeleteDC(pict1);
    txDeleteDC(pict2);
    txDeleteDC(pict3);


    txTextCursor(false);
    return 0;
}
