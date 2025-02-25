//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <Заголовок>\n
//! @brief      <Подзаголовок>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <Автор>, <Год> (<Имя> <Почта>)
//! @date       <Дата>
//!
//! @par        Протестировано
//!           - (TODO: список платформ)
//!
//! @todo     - (TODO: список ближайших планов по этому файлу)
//!
//! @bug      - (TODO: список найденных ошибок в этом файле)
//!
//! @par        История изменений файла
//!           - Версия 0.01 Alpha
//!             - Только что созданный файл
//!
//}=======================================================================

#include "TXLib.h"

struct Stalker
{
    int x;
    int y;
    int w;
    int h;
    HDC image_scary;
    HDC image;



    void draw()
    {


    txTransparentBlt(txDC(), x, y, w, h, image_scary, image)


    }

};


struct Shell
{
    int x;
    int y;
    int w;
    int h;
    HDC image;



    void draw()
    {


    txTransparentBlt(txDC(), x, y, w, h, image);



    }

};


struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;
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
//!GetAsyncKeyState(VK_ESCAPE)
int main()
    {
    txCreateWindow (800, 600);
    txTextCursor (false);

string PAGE = "menu";
int SCARY = 0;


Button btn0 = {280, 100, 200, 45, "Start", true};
Button btn1 = {280, 165, 200, 45, "Rules", true};
Button btn2 = {280, 230, 200, 45, "Settings", true};
Button btn3 = {280, 295, 200, 45, "About program", true};
Button btn4 = {280, 370, 200, 45, "Exit", true};
Stalker stalker = {90, 310, 120, 200, txLoadImage ("Сталкер.bmp"), txLoadImage ("ГЛАЗ.bmp")};
//Shell shl0 = {};



    while(!(btn4.click()))
    {

    txSetFillColor (TX_BLACK);
    txClear();
    txBegin();



    if(PAGE == "menu")
    {
        for(int i=0; i<=4; i++)
        {
            txSetColor(TX_RED);
            txSetFillColor(TX_GREEN);
            txRectangle(800,600,0,0);
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

        }
        if(btn0.click())
        {
        PAGE="game";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;

        }
        if(btn1.click())
        {
        PAGE="rules";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
        if(btn2.click())
        {
        PAGE="nastr";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }
        if(btn3.click())
        {
        PAGE="about";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        }


    }

    if(PAGE == "rules")
    {

     txSetColor(TX_RED);
     txSetFillColor(TX_YELLOW);
     txRectangle(800,600,0,0);
     txSelectFont ("Areal", 40);
     txDrawText (0, 0, 260, 80, "(еsc для выхода)  ");
     txDrawText (100, 100, 665, 190, "Правила игры:");
     txDrawText (100, 150, 665, 230, "1. Оскорбление = БАН");
     txDrawText (100, 200, 665, 270, "2. Читы = БАН");
     txDrawText (20, 250, 780, 310, "3. Оскорбление АДМИНИСТРАЦИИ = РАССТРЕЛ+БАН");
     if(GetAsyncKeyState(VK_ESCAPE))
     {
        PAGE = "menu";
     }

    }

    if(PAGE == "nastr")
    {
     txSetColor(TX_RED);
     txSetFillColor(TX_YELLOW);
     txRectangle(800,600,0,0);
     txDrawText (0, 0, 260, 80, "(еsc для выхода)  ");
     txSelectFont ("Areal", 40);
     txDrawText (100, 100, 665, 190, "Вообще, это не настройки");
     txDrawText (100, 150, 665, 230, "Короче, игра сделана");
     txDrawText (100, 210, 665, 280, "СУГУБО В РАЗВЛЕКАТЕЛЬНЫХ ЦЕЛЯХ!");
     txDrawText (100, 400, 665, 460, "Приятной игры!!!");
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
    txDrawText (0, 0, 260, 80, "(еsc для выхода)  ");
    txDrawText (100, 100, 665, 190, "О игре:");
    txDrawText (100, 150, 665, 230, "Это игра - пародия на");
    txDrawText (100, 200, 665, 270, ".....");
    txDrawText (20, 250, 70, 310, " ..............");
    if(GetAsyncKeyState(VK_ESCAPE))
     {
    PAGE = "menu";
     }

    }

    if(PAGE == "game")
    {
    txSetColor(TX_BLACK);
    txSetFillColor(TX_WHITE);
    txRectangle(800,600,0,0);
    txSetFillColor(TX_GREEN);
    txRectangle(0,600,280,510);
    txDrawText (0, 0, 260, 80, "(еsc для выхода)");
    stalker.draw();
    if(GetAsyncKeyState(VK_ESCAPE))
     {
    PAGE = "menu";
     }

    if (GetAsyncKeyState(VK_RIGHT))
    {
     stalker.x += 20;
    }


        if (stalker.x > 220)
        {
         stalker.x -= 20;
        }




    if (GetAsyncKeyState(VK_LEFT))
    {
     stalker.x -= 20;
    }


        if (stalker.x < 0)
        {
         stalker.x += 20;
        }


     stalker.y += 12;
     if (GetAsyncKeyState(VK_SPACE))
    {
     stalker.y -= 35;
    }

         if (stalker.y > 310)
        {
         stalker.y = 310;
        }


         if (stalker.y < 53)
        {
         stalker.y = 53;
        }


     if (GetAsyncKeyState(VK_DOWN) and stalker.y < 260)
    {
     stalker.y += 45;
    }

    if (GetAsyncKeyState('q') and GetAsyncKeyState('e'))
    {
     SCARY = 666;
    }

    if (SCARY == 666)
    {
     stalker.image = stalker.image_scary;
    }



    }




    txEnd();
    txSleep(50);

    }


    txDisableAutoPause();
    return 0;
    }
