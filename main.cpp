//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"

struct Bullet
{
    int x;
    int y;
    int w;
    int h;
    int s;
    HDC image;


    void draw()
    {

        txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_WHITE);

    }

 };

struct Stalker
{
    int x;
    int y;
    int w;
    int h;
    HDC image;
    HDC image_normal;
    HDC image_scary;


    void draw()
    {


    txTransparentBlt(txDC(), x, y, w, h, image, 0, 0, TX_WHITE);



    }

};

struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;
    const char* text_normal;
    const char* text_scary;
    bool visible;

    void draw()
    {

    txSetColor (TX_WHITE, 3);
    txSetFillColor (TX_RED);
    Win32::RoundRect(txDC(), x, y, x+w, y+h, 30, 30);
    txSelectFont("Areal", 30);
    txDrawText(x, y, x+w, y+h, text);

    }

    bool click()
    {
        return  (txMouseX()>x && txMouseX()<x+w &&
                txMouseY()>y && txMouseY()<y+h &&
                txMouseButtons() == 1 && visible);





    }

};

int main()
{
    txCreateWindow (800, 600);
    txTextCursor (false);

string PAGE = "menu";
int random = 0;
int hp = 100;
int hard = 0;
int SCARY = 0;


Button btn0 = {125, 100, 200, 45, "Start", "Start", "_____", true};
Button btn1 = {125, 165, 200, 45, "Rules", "Rules", "������", true};
Button btn2 = {125, 230, 200, 45, "Settings", "Settings", "���", true};
Button btn3 = {125, 295, 200, 45, "About program", "About program", "������", true};
Button btn4 = {125, 370, 200, 45, "Exit", "Exit", "����!", true};
Stalker stalker = {90, 310, 120, 200, txLoadImage ("�������.bmp"), txLoadImage ("�������.bmp"), txLoadImage ("����.bmp")};
Stalker zast = {470, 160, 225, 225, txLoadImage("��������1.bmp"), txLoadImage("��������1.bmp"), txLoadImage("����1.bmp")};
Bullet bul0 = {760, 143, 80, 20, 25, txLoadImage ("SHELL.bmp")};
Bullet bul1 = {760, 183, 80, 20, 25, txLoadImage ("SHELL.bmp")};
Bullet bul2 = {760, 223, 80, 20, 25, txLoadImage ("SHELL.bmp")};
Bullet bul3 = {760, 263, 80, 20, 25, txLoadImage ("SHELL.bmp")};
Bullet bul4 = {760, 303, 80, 20, 25, txLoadImage ("SHELL.bmp")};
Bullet bul5 = {760, 343, 80, 20, 25, txLoadImage ("SHELL.bmp")};

btn0.text = btn0.text_normal;
btn1.text = btn1.text_normal;
btn2.text = btn2.text_normal;
btn3.text = btn3.text_normal;
btn4.text = btn4.text_normal;
stalker.image = stalker.image_normal;

    while(!(btn4.click()))
    {

    txSetFillColor (TX_BLACK);
    txClear();
    txBegin();



    if(PAGE == "menu")
    {

        txSetColor(TX_RED);
        txSetFillColor(TX_GREEN);
        txRectangle(0,0,800,600);
        zast.draw();
        txSetFillColor(TX_GRAY);
        btn0.draw();
        btn1.draw();
        btn2.draw();
        btn3.draw();
        btn4.draw();
        btn0.visible = true;
        btn1.visible = true;
        btn2.visible = true;
        btn3.visible = true;
        btn4.visible = true;


        if(btn0.click() )
        {
        PAGE="game";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;

        }
        if(btn1.click() and SCARY < 666)
        {
        PAGE="rules";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
        if(btn2.click() and SCARY < 666)
        {
        PAGE="nastr";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
        if(btn3.click() and SCARY < 666)
        {
        PAGE="about";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }

        if(SCARY < 666)
        {

        txSetColor(TX_YELLOW);
        txSetFillColor(TX_RED);
        txDrawText (20, 0, 340, 80, "STALKER 3 (100% Original)");

        }

        if(SCARY == 666)
        {
        txSetColor(TX_RED);
        txSetFillColor(TX_RED);
        txDrawText (20, 0, 340, 80, "��� ��� �����");

        }

        if(SCARY == 666)
        {

            btn4.text = btn4.text_scary;
            btn1.text = btn1.text_scary;
            btn2.text = btn2.text_scary;
            btn3.text = btn3.text_scary;
            btn0.text = btn0.text_scary;

        }



    }

    if(PAGE == "rules")
    {

     txSetColor(TX_RED);
     txSetFillColor(TX_YELLOW);
     txRectangle(800,600,0,0);
     txDrawText (500, 0, 820, 80, "������� ����� - ........");
     txSelectFont ("Areal", 40);
     txDrawText (0, 0, 260, 80, "(�sc ��� ������)  ");
     txDrawText (100, 100, 665, 190, "������� ����:");
     txDrawText (100, 150, 665, 230, "1. ����������� = ���");
     txDrawText (100, 200, 665, 270, "2. ���� = ���");
     txDrawText (20, 250, 780, 310, "3. ����������� ������������� = ��������+���");
     txDrawText (20, 300, 780, 350, "���������� :");
     txDrawText (20, 350, 780, 390, "������� ������� - �������� � �������");
     txDrawText (20, 400, 780, 430, "������ - ������");
     txDrawText (20, 450, 780, 470, "������� ���� - ����� ����");
     if(GetAsyncKeyState(VK_ESCAPE))
     {
        PAGE = "menu";
     }

     if(hard > 200)
     {
     txSetColor(TX_BLACK);
     txSetFillColor(TX_BLACK);
     txDrawText (500, 0, 820, 80, "������� ����� - ........");
     }



     }



    if(PAGE == "nastr")
    {
     txSetColor(TX_RED);
     txSetFillColor(TX_YELLOW);
     txRectangle(800,600,0,0);
     txDrawText (0, 0, 260, 80, "(�sc ��� ������)  ");
     txSelectFont ("Areal", 40);
     txDrawText (100, 100, 665, 190, "������, ��� �� ���������");
     txDrawText (100, 150, 665, 230, "������, ���� �������");
     txDrawText (100, 210, 665, 280, "������ � ��������������� �����!");
     txDrawText (100, 400, 665, 460, "�������� ����!!!");
     if(GetAsyncKeyState(VK_ESCAPE))
     {
      PAGE = "menu";
     }

    }

    if(PAGE == "about")
    {
    txSetColor(TX_RED);
    txSetFillColor(TX_YELLOW);
    txRectangle(800,600,0,0);
    txSelectFont ("Areal", 40);
    txDrawText (0, 0, 260, 80, "(�sc ��� ������)  ");
    txDrawText (100, 100, 665, 190, "� ����:");
    txDrawText (100, 150, 665, 230, "��� ���� - ������� ��");
    txDrawText (100, 200, 665, 270, ".....");
    txDrawText (20, 250, 70, 310, " ..............");
    if(GetAsyncKeyState(VK_ESCAPE))
     {
    PAGE = "menu";
     }

    }

    if(PAGE == "game")
    {
// ���� :
{
        txSetColor(TX_BLACK);
        txSetFillColor(TX_WHITE);
        txRectangle(800,600,0,0);
        random += 1;
        hard += 1;
        txSetFillColor(TX_GREEN);
        txRectangle(0,600,280,510);
        txDrawText (0, 0, 260, 80, "(�sc ��� ������)");
        stalker.draw();


        if(GetAsyncKeyState(VK_ESCAPE))
         {
            PAGE = "menu";
         }

        if(random > 250)
         {
            random = 0;
         }

        if(hard > 150)
         {
            bul0.s = 35;
            bul1.s = 35;
            bul2.s = 35;
            bul3.s = 35;
            bul4.s = 35;
            bul5.s = 35;
         }

        if(hard > 350)
         {
            bul0.s = 60;
            bul1.s = 60;
            bul2.s = 60;
            bul3.s = 60;
            bul4.s = 60;
            bul5.s = 60;
         }

        if(hard > 600)
         {
            bul0.s = 90;
            bul1.s = 90;
            bul2.s = 90;
            bul3.s = 90;
            bul4.s = 90;
            bul5.s = 90;
         }


        if(GetAsyncKeyState(VK_UP))
        {

        stalker.image = stalker.image_scary;
        zast.image = zast.image_scary;
        SCARY = 666;

        }

}
// ��������� �������� :
{
    if(random > 200)
    {
     bul0.draw();
     bul0.x -= bul0.s;
    }

        if(random == 200)
        {
         bul0.x = 760;
         bul0.y = 143;
        }

    if(random > 100)
    {
     bul1.draw();
     bul1.x -= bul1.s;

    }

        if(random == 100)
        {
         bul1.x = 760;
         bul1.y = 183;
        }


     if(random > 50)
    {
     bul2.draw();
     bul2.x -= bul2.s;

    }

        if(random == 500)
        {
         bul2.x = 760;
         bul2.y = 223;
        }

     if(random > 10)
    {
     bul3.draw();
     bul3.x -= bul3.s;

    }

        if(random == 10)
        {
         bul3.x = 760;
         bul3.y = 263;
        }

     if(random > 160)
    {
     bul4.draw();
     bul4.x -= bul4.s;

    }

        if(random == 160)
        {
         bul4.x = 760;
         bul4.y = 303;
        }

     if(random > 125)
    {
     bul5.draw();
     bul5.x -= bul5.s;

    }

        if(random == 125)
        {
         bul5.x = 760;
         bul5.y = 343;
        }

}
// ��������� ��������� :
{





        if(hp < 0)
        {
        PAGE = "LOSE";
        }



        if (GetAsyncKeyState(VK_SPACE))
         {
            stalker.y -= 55;

         }

         stalker.y += 20;

            if (stalker.y > 310)
                {

          stalker.y = 310;
        }
            if (stalker.y < 60)
                {
          stalker.y = 60;
        }

        if (GetAsyncKeyState(VK_DOWN) and stalker.y < 180)
         {
            stalker.y += 70;
         }

        if (GetAsyncKeyState(VK_RIGHT))
         {
            stalker.x += 8;

         }

            if (stalker.x > 205)
         {
            stalker.x -=8;

         }

        if (GetAsyncKeyState(VK_LEFT))
         {
            stalker.x -= 8;

         }

            if (stalker.x < 0)
                {
            stalker.x += 8;

         }
}
// ������� ������� (�� ��������) :
{
    if (stalker.x+stalker.y == bul0.x+bul0.y)

    hp -= 3;
    txDrawText (100, 100, 665, 190, "-3");



    if (stalker.x+stalker.y == bul1.x+bul1.y)
    {
    hp -= 3;
    txDrawText (100, 100, 665, 190, "-3");
    }

    if (stalker.x+stalker.y == bul2.x+bul2.y)
    {
    hp -= 3;
    txDrawText (100, 100, 665, 190, "-3");
    }

    if (stalker.x+stalker.y == bul3.x+bul3.y)
    {
    hp -= 3;
    txDrawText (100, 100, 665, 190, "-3");
    }

    if (stalker.x+stalker.y == bul4.x+bul4.y)
    {
    hp -= 3;
    txDrawText (100, 100, 665, 190, "-3");
    }

    if (stalker.x+stalker.y == bul5.x+bul5.y)
    {
    hp -= 3;
    txDrawText (100, 100, 665, 190, "-3");
    }

}

    }

    if(PAGE == "LOSE")
    {
     txSetColor(TX_RED);
     txSetFillColor(TX_CYAN);
     txRectangle(800,600,0,0);
     txSelectFont ("Areal", 40);
     txSetColor(TX_GREEN);
     txSetFillColor(TX_RED);
     txDrawText (100, 100, 665, 190, "CUDA!!!!!");
    }

    txEnd();
    txSleep(50);

  }



// ���� ������������ HDC :
{
txDeleteDC(stalker.image_normal);
txDeleteDC(stalker.image_scary);
txDeleteDC(zast.image_normal);
txDeleteDC(zast.image_scary);
txDeleteDC(bul5.image);
txDeleteDC(bul5.image);
txDeleteDC(bul4.image);
txDeleteDC(bul3.image);
txDeleteDC(bul2.image);
txDeleteDC(bul1.image);
txDeleteDC(bul0.image);
txDeleteDC(stalker.image);
txDeleteDC(zast.image);
}


txDisableAutoPause();
return 0;
}
