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

void DrawText(int y)
{
     txSetColor(TX_BLACK);
     txSetFillColor(TX_BLACK);
     txRectangle(800,600,0,0);
     txSetColor(TX_WHITE);
     txSetFillColor(TX_WHITE);
     txSelectFont ("Areal", 40);
     txDrawText (100, 100, 665, 190, "КОНЦОВКА ПЕРВАЯ");
     txDrawText (100, 200, 665, 290, "THE GOD ");



}

struct Bullet
{
    int x;
    int y;
    int w;
    int h;
    int s;
    HDC image;
    HDC image_normal;
    HDC image_angel;



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

int GOD = 0;
string PAGE = "menu";
int random = 0;
int hp = 1000;
int hard = 0;
int SCARY = 0;
int yText = 500;
int Score = 0;
int dam = 8;


Button btn0 = {125, 100, 200, 45, "Start", "Start", "_____", true};
Button btn1 = {125, 165, 200, 45, "Rules", "Rules", "ОНО", true};
Button btn2 = {125, 230, 200, 45, "Settings", "Settings", "УЖЕ", true};
Button btn3 = {125, 295, 200, 45, "About program", "About program", "БЛИЗКО", true};
Button btn4 = {125, 370, 200, 45, "Exit", "Exit", "БЕГИ!", true};
Button btn5 = {700, 25, 100, 26, "THE GOD", "THE GOD", "THE GOD", true};
Button btn6 = {700, 65, 100, 26, "МАГАЗИН", "МАГАЗИН", "????", true};

Stalker stalker = {90,  310, 120, 200, txLoadImage ("Сталкер.bmp"),  txLoadImage ("Сталкер.bmp"),  txLoadImage ("ГЛАЗ.bmp")};
Stalker zast =    {470, 160, 225, 225, txLoadImage("Заставка1.bmp"), txLoadImage("Заставка1.bmp"), txLoadImage("ГЛАЗ1.bmp")};
Stalker fon =     {0,     0, 800, 600, txLoadImage("ЛЕС.bmp"),       txLoadImage("ЛЕС.bmp"),       txLoadImage("ЛЕС0.bmp")};
Stalker god =     {420, -50, 400, 373, txLoadImage("У.bmp"),         txLoadImage("У.bmp"),         txLoadImage("У.bmp")};

Bullet bul0 = {760, 143, 80, 20, 25, txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL_2.bmp")};
Bullet bul1 = {760, 183, 80, 20, 25, txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL2.bmp")};
Bullet bul2 = {30, 0, 20, 80, 25, txLoadImage ("SHELL_v.bmp"), txLoadImage ("SHELL_v.bmp"), txLoadImage ("SHELL_v.bmp")};
Bullet bul3 = {760, 263, 80, 20, 25, txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL2.bmp")};
Bullet bul4 = {760, 303, 80, 20, 25, txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL2.bmp")};
Bullet bul5 = {760, 343, 80, 20, 25, txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL.bmp"), txLoadImage ("SHELL2.bmp")};
Bullet las0 = {400, 100, 800, 65, 25, txLoadImage ("Laser-1.bmp"), txLoadImage ("Laser-1.bmp"), txLoadImage ("Laser0.bmp")};


bul0.image = bul0.image_normal;
bul1.image = bul1.image_normal;
bul2.image = bul2.image_normal;
bul3.image = bul3.image_normal;
bul4.image = bul4.image_normal;
bul5.image = bul5.image_normal;
btn0.text = btn0.text_normal;
btn1.text = btn1.text_normal;
btn2.text = btn2.text_normal;
btn3.text = btn3.text_normal;
btn4.text = btn4.text_normal;
btn6.text = btn6.text_normal;
stalker.image = stalker.image_normal;
fon.image = fon.image_normal;

char str[20];
char stu[20];



while(!btn4.click())
{

txSetFillColor(TX_BLACK);
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
        btn5.draw();
        btn6.draw();
        btn6.visible = true;
        btn0.visible = true;
        btn1.visible = true;
        btn2.visible = true;
        btn3.visible = true;
        btn4.visible = true;
        btn5.visible = true;


        if(btn0.click())
        {
        PAGE="game";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        btn5.visible = false;
        }
        if(btn1.click() and SCARY < 666)
        {
        PAGE="rules";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        btn5.visible = false;
        }
        if(btn2.click() and SCARY < 666)
        {
        PAGE="nastr";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        btn5.visible = false;
        }
        if(btn3.click() and SCARY < 666)
        {
        PAGE="about";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        btn5.visible = false;
        }
        if(btn5.click() and SCARY == 666)
        {
        PAGE="INFORMATION";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        btn5.visible = false;
        }
        if(btn6.click() and SCARY < 666)
        {
        PAGE = "SHOP";
        btn0.visible = false;
        btn1.visible = false;
        btn2.visible = false;
        btn3.visible = false;
        btn4.visible = false;
        btn5.visible = false;
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
        txDrawText (20, 0, 340, 80, "ОНО УЖЕ ЗДЕСЬ");

        }

        if(SCARY == 666)
        {

            btn4.text = btn4.text_scary;
            btn1.text = btn1.text_scary;
            btn2.text = btn2.text_scary;
            btn3.text = btn3.text_scary;
            btn0.text = btn0.text_scary;
            btn6.text = btn6.text_scary;


        }



    }

    if(PAGE == "rules")
    {

     txSetColor(TX_RED);
     txSetFillColor(TX_YELLOW);
     txRectangle(800,600,0,0);
     txDrawText (500, 0, 820, 80, "стрелка вверх - ........");
     txSelectFont ("Areal", 40);
     txDrawText (0, 0, 260, 80, "(еsc для выхода)  ");
     txDrawText (100, 100, 665, 190, "Правила игры:");
     txDrawText (100, 150, 665, 230, "1. Оскорбление = БАН");
     txDrawText (100, 200, 665, 270, "2. Читы = БАН");
     txDrawText (20, 250, 780, 310, "3. Оскорбление АДМИНИСТРАЦИИ = РАССТРЕЛ+БАН");
     txDrawText (20, 300, 780, 350, "Управление :");
     txDrawText (20, 350, 780, 390, "боковые стрелки - движение в стороны");
     txDrawText (20, 400, 780, 430, "пробел - прыжок");
     txDrawText (20, 450, 780, 470, "стрелка вниз - рывок вниз");
     if(GetAsyncKeyState(VK_ESCAPE))
     {
        PAGE = "menu";
     }

     if(hard > 200)
     {
     txSetColor(TX_BLACK);
     txSetFillColor(TX_BLACK);
     txDrawText (500, 0, 820, 80, "стрелка вверх - ........");
     }



     }

    if(PAGE == "INFORMATION")
    {
        txSetColor(TX_RED);
        txSetFillColor(TX_WHITE);
        txRectangle(800,600,0,0);
        txSelectFont ("Areal", 40);
        txSetFillColor(TX_BLACK);
        txDrawText (10, 0, 260, 80, "THE GOD - БОГ");
        txDrawText (5, 100, 665, 190, "ИСТОРИЯ ПОЯВЛЕНИЯ :");
        txDrawText (5, 150, 665, 230, "__+_=--=12+-443*////++э][;p[;.?");
        txDrawText (5, 200, 665, 270, "СЛАБОСТИ :");
        txDrawText (5, 250, 665, 310, "))9*72№=--=12*398++**/+212+=2___-Б,");
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
    txDrawText (100, 150, 665, 230, "Это игра - супер трипл эй проект");
    txDrawText (100, 200, 665, 270, ".....");
    txDrawText (20, 250, 70, 310, "...Ладно, не прям уж супер.");
    if(GetAsyncKeyState(VK_ESCAPE))
     {
    PAGE = "menu";
     }

    }

    if(PAGE == "game")
    {

//------------------------------------------------------------------------------------------------------------------- |

// БАЗА :                                                                                                             |
{



        txSetColor(TX_BLACK);
        txSetFillColor(TX_WHITE);
        txRectangle(0,115,325,0);
        random += 1;
        hard += 10;
        Score += 3;
        fon.draw();
        txSetFillColor(TX_GRAY);
        txRectangle(0,600,280,510);
        txDrawText (0, 0, 260, 80, "(еsc для выхода)");
        stalker.draw();

        if(GOD < 1)
        {
        sprintf(stu, "Очки- %d", Score);
        txTextOut(170, 0, stu);
        }

        if(hard > 1000 and GOD < 1)
        {
            hard = 1000;

        }

        if(Score > 1999 && SCARY < 666)
        {
            Score = 2000;
            PAGE = "ENDING #2";
        }

        if(GetAsyncKeyState(VK_ESCAPE) and GOD < 1)
         {
            PAGE = "menu";
         }

        if(random > 179 and GOD < 1)
         {
            random = 0;
         }


        if(random > 90 and GOD > 1)
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

        if(hard == 6666)
        {
            bul0.s = 120;
            bul1.s = 120;
            bul2.s = 120;
            bul3.s = 120;
            bul4.s = 120;
            bul5.s = 120;
        }


        if(SCARY == 666)
        {
        fon.image = fon.image_scary;
        }

        if(Score > 1501 && Score < 1545)
        {
         hp = 150;
        }


        if(SCARY == 666 and Score > 2999)
         {
        GOD = 2;
        txSetColor(TX_RED);
        txSetFillColor(TX_RED);
        txDrawText (226, 110, 555, 150, "GOD IS HERE");
        god.draw();
         }

        if(GetAsyncKeyState(VK_UP))
        {

        stalker.image = stalker.image_scary;
        zast.image = zast.image_scary;
        SCARY = 666;

        }

        if(Score > 3999 && GOD > 1)
        {

        PAGE = "ENDING #3";

        }


// <JCQ#+
{
    if (GOD > 1 and god.y < 199)
    {
        god.y += 10;
    }

    if (god.y > 198)
    {
      //  PAGE = "ENDING #1";
    }

    if (GOD > 1)
    {
        hard = 6666;
        bul0.image = bul0.image_angel;
        bul1.image = bul1.image_angel;
        bul2.image = bul2.image_angel;
        bul3.image = bul3.image_angel;
        bul4.image = bul4.image_angel;
        bul5.image = bul5.image_angel;



    }

    if(Score > 2999 && Score < 3035)
    {

    hp = 666;

    }
}




}

//------------------------------------------------------------------------------------------------------------------- |

// генерация снарядов :                                                                                               |
{
if(GOD < 1)
{
dam = 8;

    if(random > 1 and random < 30)
    {

     bul0.draw();
     bul0.x -= bul0.s;
    }

        if(random == 1)
        {
             bul0.x = 760;
             bul0.y = 135;

        }


    if(random > 30 and random < 60)
    {
     bul0.draw();
     bul0.x -= bul1.s;

    }
        if(random == 30)
        {
             bul0.x = 760;
             bul0.y = 350;

        }


     if(random > 60 and random < 90)
    {
     bul0.draw();
     bul0.x -= bul0.s;

    }

        if(random == 60)
        {
            bul0.x = 760;
            bul0.y = 160;
        }

     if(random > 90 and random < 120)
    {

     bul0.draw();
     bul0.x -= bul0.s;

    }


        if(random == 90)
        {
            bul0.x = 760;
            bul0.y = 300;
        }


     if(random > 120 and random < 150)
    {

     bul0.draw();
     bul0.x -= bul0.s;

    }

        if(random == 120)
        {
            bul0.x = 760;
            bul0.y = 250;
        }




     if(random > 150 and random < 180)
    {

     bul0.draw();
     bul0.x -= bul0.s;

    }

        if(random == 150)
        {
            bul0.x = 760;
            bul0.y = 200;
        }
}

//-------------------------------------------------------------------------------------------------------------------------- |

if(GOD > 1)
{
bul0.s = 105;
dam = 30;

    if(random > 10 && random < 35)
    {
     bul0.draw();
     bul0.x -= bul0.s;
    }

    if(random > 50 && random < 89)
    {
     bul0.draw();
     bul0.x -= bul0.s;
    }

        if(random == 10)
        {
             bul0.x = 760;
             bul0.y = stalker.y + 125;

        }

    if (random > 15)
    {
        bul2.draw();
        bul2.y += 20;
    }

    if(random == 10)
        {
             bul2.y = 0;
             bul2.x = stalker.x + 60;

        }


    if (random > 15)
    {
        las0.draw();

    }

        if(random == 10)
        {

             bul2.y = stalker.y + 100;

        }


}

}

//------------------------------------------------------------------------------------------------------------------- |

// управлние Сталкером :                                                                                              |
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
            stalker.x += 21;

         }

            if (stalker.x > 205)
         {
            stalker.x -=21;

         }

        if (GetAsyncKeyState(VK_LEFT))
         {
            stalker.x -= 21;

         }

            if (stalker.x < 0)
                {
            stalker.x += 21;

         }
}

//------------------------------------------------------------------------------------------------------------------- |

// касание снаряда (работает:)) :                                                                                     |
{
    if (bul0.x<stalker.x+stalker.w && bul0.x+bul0.w>stalker.x && bul0.y>stalker.y && bul0.y+bul0.h<stalker.y+stalker.h)
    {
          hp -= dam;
    }

    if (bul1.x<stalker.x+stalker.w && bul1.x+bul0.w>stalker.x && bul1.y>stalker.y && bul1.y+bul1.h<stalker.y+stalker.h)
    {
          hp -= 6;
    }

    if (bul2.x<stalker.x+stalker.w && bul2.x+bul0.w>stalker.x && bul2.y>stalker.y && bul2.y+bul2.h<stalker.y+stalker.h)
    {
          hp -= dam;
    }

    if (bul3.x<stalker.x+stalker.w && bul3.x+bul0.w>stalker.x && bul3.y>stalker.y && bul3.y+bul3.h<stalker.y+stalker.h)
    {
          hp -= 6;
    }
    if (bul4.x<stalker.x+stalker.w && bul4.x+bul0.w>stalker.x && bul4.y>stalker.y && bul4.y+bul4.h<stalker.y+stalker.h)
    {
          hp -= 6;
    }
    if (bul5.x<stalker.x+stalker.w && bul5.x+bul0.w>stalker.x && bul5.y>stalker.y && bul5.y+bul5.h<stalker.y+stalker.h)
    {
          hp -= 6;
    }


    if (las0.x<stalker.x+stalker.w && las0.x+las0.w>stalker.x && las0.y>stalker.y && las0.y+las0.h<stalker.y+stalker.h)
    {
          hp -= dam + 10;
    }


    sprintf(str, "Здоровье- %d", hp);
    txTextOut(0, 0, str);


}

//------------------------------------------------------------------------------------------------------------------- |

    }

    if(PAGE == "LOSE")
    {
     txSetColor(TX_RED);
     txSetFillColor(TX_WHITE);
     txRectangle(800,600,0,0);
     txSelectFont ("Areal", 40);
     txSetColor(TX_BLACK);
     txSetFillColor(TX_BLACK);
     txDrawText (100, 100, 665, 190, "Поражение");
     txDrawText (100, 170, 665, 260, "Пал смертью храбрых.....f");

    }

    if(PAGE == "SHOP")
    {
        txSetColor(TX_RED);
        txSetFillColor(TX_YELLOW);
        txRectangle(800,600,0,0);
        txSetFillColor(TX_BLACK);
        txDrawText (10, 0, 260, 80, "МАГАЗИН");
        txDrawText (20, 100, 665, 190, "Пока что тут пусто...");
        if(GetAsyncKeyState(VK_ESCAPE))
     {
        PAGE = "menu";
     }



    }

    if(PAGE == "ENDING #1")
    {
         if (yText < 600)
         {
             DrawText(yText + 50);
             yText -= 5;
         }


    }

    if(PAGE == "ENDING #2")
    {
     txSetColor(TX_RED);
     txSetFillColor(TX_WHITE);
     txRectangle(800,600,0,0);
     txSelectFont ("Areal", 40);
     txSetColor(TX_BLACK);
     txSetFillColor(TX_BLACK);
     txDrawText (100, 100, 665, 190, "Победа!");
     txDrawText (100, 170, 665, 260, "Игра пройдена!!!");
     txDrawText (100, 400, 665, 490, "Или нет?.....");

    }

    if(PAGE == "ENDING #3")
    {
     txSetColor(TX_RED);
     txSetFillColor(TX_WHITE);
     txRectangle(800,600,0,0);
     txSelectFont ("Areal", 40);
     txSetColor(TX_BLACK);
     txSetFillColor(TX_BLACK);
     txDrawText (100, 100, 665, 190, "Победа!");
     txDrawText (100, 400, 665, 490, "Истинная концовка");

    }


    txEnd();
    txSleep(50);

}
// Блок освобождения HDC :
{
txDeleteDC(stalker.image_normal);
txDeleteDC(stalker.image_scary);
txDeleteDC(zast.image_normal);
txDeleteDC(zast.image_scary);
txDeleteDC(bul5.image_normal);
txDeleteDC(bul4.image_normal);
txDeleteDC(bul3.image_normal);
txDeleteDC(bul2.image_normal);
txDeleteDC(bul1.image_normal);
txDeleteDC(bul0.image_normal);
txDeleteDC(stalker.image_normal);
txDeleteDC(zast.image_normal);
txDeleteDC(bul5.image_angel);
txDeleteDC(bul4.image_angel);
txDeleteDC(bul3.image_angel);
txDeleteDC(bul2.image_angel);
txDeleteDC(bul1.image_angel);
txDeleteDC(bul0.image_angel);
txDeleteDC(stalker.image_scary);
txDeleteDC(zast.image_scary);
}


txDisableAutoPause();
return 0;
}
