#include "TXLib.h"

int main()
{
    txCreateWindow(1300,730);

    int nQue = 52;

    string question = "����� �������� ������������� ������� ����?";
    string v1 ="1050";
    string v2 ="988";
    string v3 ="999";

    HDC pict1 = txLoadImage("1050.bmp");
    HDC pict2 = txLoadImage("988.bmp");
    HDC pict3 = txLoadImage("999.bmp");

    if(nQue == 1)
    {
        question = "����� �������� ������������� ������� ����?";
        v1 ="1050";
        v2 ="988";
        v3 ="999";
    }
    else
    {
        question = "����� �������� ������������� ������� ����?";
        v2 ="1050";
        v3 ="988";
        v1 ="999";
    }


    //������
    txSelectFont("Comic Sans",40);
    txSetColor(TX_WHITE);
    txSetFillColor(TX_TRANSPARENT);
    //����� �������
    txDrawText(1129,30,1300,78,"������ �_");
    //������ ������� ������
    txRectangle(103,273,410,562);
    txBitBlt(txDC(),103,273,307,289,pict1);
    //������ ������� ������
    txRectangle(504,273,810,562);
    txBitBlt(txDC(),504,273,307,289,pict2);
    //������ ������� ������
    txRectangle(893,273,1199,562);
    txBitBlt(txDC(),893,273,307,289,pict3);

    //������
    txRectangle(269,67,1011,167);
    txDrawText(269,67,1011,167,question.c_str());
    //����������� � 1 �������
    txRectangle(103+39,562+24,410-39,562+24+33);
    txDrawText(103+39,562+24,410-39,562+24+33,v1.c_str());
    //����������� �� 2 �������
    txRectangle(504+39,562+24,810-39,562+24+33);
    txDrawText(504+39,562+24,810-39,562+24+33,v2.c_str());
    //����������� � 3 �������
    txRectangle(893+39,562+24,1199-39,562+24+33);
    txDrawText(893+39,562+24,1199-39,562+24+33,v3.c_str());

    txDeleteDC(pict1);
    txDeleteDC(pict2);
    txDeleteDC(pict3);


    txTextCursor(false);
    return 0;
}
