#include "TXLib.h"

struct shape
{
    string question;
    string v1;
    string v2;
    string v3;
    HDC pict1;
    HDC pict2;
    HDC pict3;
};

bool clk(int x)
    {
        return (txMouseButtons() == 1 and
            txMouseX()>x and txMouseX()<x+307 and
            txMouseY()>273 and txMouseY()<562);
    }

int main()
{
    txCreateWindow(1300,730);

    int nQue = 1;
    char stroka[50];

    shape sh;

    shape sh_list[10];

    sh_list[0] = {"����� �������� ������������� ������� ����?","1050","988","999",txLoadImage("����/1050.bmp"),txLoadImage("����/988.bmp"),txLoadImage("����/999.bmp")};
    sh_list[1] = {"��� ������ � ������ � 1115 ����","���� �������","�������� �������","�������� ������� ��������",txLoadImage("����/�������.bmp"),txLoadImage("����/�������.bmp"),txLoadImage("����/��������.bmp")};
    sh_list[2] = {};
    sh_list[3] = {};
    sh_list[4] = {};
    sh_list[5] = {};
    sh_list[6] = {};
    sh_list[7] = {};
    sh_list[8] = {};
    sh_list[9] = {};

    while (nQue<11)
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txBegin();

        sh = sh_list[nQue-1];

        //������
        txSelectFont("Comic Sans",40);
        txSetColor(TX_WHITE);
        txSetFillColor(TX_TRANSPARENT);
        //����� �������
        sprintf(stroka,"������ � %d",nQue);
        txDrawText(1100,30,1300,78,stroka);
        //������ ������� ������
        txRectangle(103,273,410,562);
        txBitBlt(txDC(),103,273,307,289,sh.pict1);
        //������ ������� ������
        txRectangle(504,273,810,562);
        txBitBlt(txDC(),504,273,307,289,sh.pict2);
        //������ ������� ������
        txRectangle(893,273,1199,562);
        txBitBlt(txDC(),893,273,307,289,sh.pict3);

        //������
        txRectangle(269,67,1011,167);
        txDrawText(269,67,1011,167,sh.question.c_str());
        //����������� � 1 �������
        txRectangle(103+39,562+24,410-39,562+24+33);
        txDrawText(103+39,562+24,410-39,562+24+33,sh.v1.c_str());
        //����������� �� 2 �������
        txRectangle(504+39,562+24,810-39,562+24+33);
        txDrawText(504+39,562+24,810-39,562+24+33,sh.v2.c_str());
        //����������� � 3 �������
        txRectangle(893+39,562+24,1199-39,562+24+33);
        txDrawText(893+39,562+24,1199-39,562+24+33,sh.v3.c_str());

        if (clk(103))
        {
            while(txMouseButtons() == 1)
            {
                txSleep(10);
            }
            nQue ++;
        }
        if (clk(504))
        {
            while(txMouseButtons() == 1)
            {
                txSleep(10);
            }
            nQue ++;
        }
        if (clk(893))
        {
            while(txMouseButtons() == 1)
            {
                txSleep(10);
            }
            nQue ++;
        }


        txEnd();
    }


    txDeleteDC(sh.pict1);
    txDeleteDC(sh.pict2);
    txDeleteDC(sh.pict3);


    txTextCursor(false);
    return 0;
}
