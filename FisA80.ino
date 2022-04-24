#include "Ucglib.h"
#include <SPI.h>


Ucglib_ST7735_18x128x160_SWSPI ucg(/*sclk=*/ 13, /*data=*/ 11, /*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);
int p,i,m,z, k, u, ui, kn, kt, r, g, b, r2, g2, b2, kni, kti, speedo;
void setup(void) 
{
   z=0;
  i=0;
  m=1; //Przełączanie pozycji na ekranie
  p=1; //Ekrany główne
  k=1;
  ui=0;
  u=1;
  kn=1;
  kt=1;
  kni=0;
  kti=0;
  r=255;
  g=0;
  b=0;
  r2=0;
  g2=0;
  b2=0;
  speedo=15;
  
    pinMode(7, INPUT_PULLUP);  //przelaczanie
    pinMode(6, INPUT_PULLUP);  //przelaczanie
    pinMode(5, INPUT_PULLUP);  //zatwierdzanie/powrót
 delay(1000);
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  ucg.setColor(r2,g2,b2);
  ucg.drawBox(0, 0, ucg.getWidth(), ucg.getHeight());
  Serial.begin(9600);
 
}

void mainScreen()
{
  

  while (z==0)
    {
      ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(0, 0, ucg.getWidth(), ucg.getHeight());
     
      ucg.setPrintPos(5,18);
      ucg.setColor(r, g, b);
      ucg.setFont(ucg_font_helvB14_tr);
      ucg.print("10:30");
      ucg.setPrintPos(84,18);
      ucg.print("15");
      ucg.setPrintPos(110,18);
      ucg.print("C");
      ucg.setFont(ucg_font_helvB08_tr);
      ucg.setPrintPos(105,10);
      ucg.print("o");
    
      //ucg.setFont(ucg_font_helvB08_hr);
      ucg.setColor(r,g,b);
      ucg.drawBox(0, 22, 160, 2);
      ucg.drawBox(0, 132, 160, 2);
      //ucg.setFont(ucg_font_helvB24_tr);
      
      ucg.setFont(ucg_font_helvB14_tr);
      ucg.setPrintPos(80,60);
      ucg.print("km/h");
      
      
      
      ucg.setPrintPos(30,92);
      ucg.print("12,5");
      ucg.setFont(ucg_font_helvB08_tr);
      ucg.setPrintPos(88,80);
      ucg.print("l");
      ucg.setColor(r,g,b);
      ucg.drawBox(73, 82, 37, 2);
      ucg.setPrintPos(75,95);
      ucg.print("100km");

      ucg.setFont(ucg_font_helvB14_tr);
      ucg.setPrintPos(20,120);
      ucg.print("28-12-2021");
      
      ucg.setPrintPos(26,155);
      ucg.print("E");
      ucg.setPrintPos(115,155);
      ucg.print("F");
      //Ikona dystrybutora vvv
      ucg.drawBox(5, 145, 10, 10);
      ucg.drawBox(5, 141, 2, 4);
      ucg.drawBox(13, 141, 2, 4);
      ucg.drawBox(7, 139, 6, 2);
      ucg.drawBox(6, 140, 2, 2);
      ucg.drawBox(12, 140, 2, 2);
      ucg.drawBox(15, 146, 3, 2);
      ucg.drawBox(16, 148, 2, 6);
      ucg.drawBox(17, 153, 3, 2);
      ucg.drawBox(19, 142, 2, 12);
      ucg.drawBox(17, 144, 2, 1);
      ucg.drawBox(17, 143, 1, 1);
      ucg.drawBox(17, 141, 3, 2);
      ucg.drawBox(17, 141, 3, 2);
      ucg.drawBox(17, 140, 2, 1);
      ucg.drawBox(16, 139, 2, 2);
      //Ikona dystrybutora ^^^
      ucg.drawBox(40, 141, 74, 14); // Stan LPG Zakres 2- 
      //ucg.setColor(0, 255, 255, 255);   // use white as main color for the font
      //ucg.setColor(1, 255,0,0);     // use blue as background for SOLID mode
      ucg.setPrintPos(20,60);
      ucg.setFont(ucg_font_helvB24_hr);
      z=1;
    }
    if (speedo>99)
    {
      ucg.setPrintPos(20,60);
    }
    else
    {
      if (speedo<10)
    {
      ucg.setPrintPos(56,60);
      ucg.setColor(r2, g2, b2);
      ucg.drawBox(20, 35, 34, 30);
    }
    else
    {
      ucg.setPrintPos(38,60);
      ucg.setColor(r2, g2, b2);
      ucg.drawBox(20, 35, 17, 30);;
    }
      //ucg.setPrintPos(38,60);
     // ucg.setColor(r2, g2, b2);
      //ucg.drawBox(20, 35, 17, 30);
    }
    
    ucg.setFontMode(UCG_FONT_MODE_SOLID);
      //ucg.setColor(r2,g2,b2);
      //ucg.drawBox(20, 35, 60, 30);
      //ucg.setPrintPos(20,60);
      //ucg.setColor(r,g,b);
      ucg.setColor(0, r, g, b);    // use white as main color for the font
      ucg.setColor(1, r2,g2,b2);
      ucg.print(speedo);
    if (digitalRead(5)== LOW)
    {
    p=2;
    z=0;
    i=0;
    }
}

void menu()
{
  
  while (z==0)
    {
      ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(0, 0, ucg.getWidth(), 120);
     
      ucg.setPrintPos(4,20);
      ucg.setColor(r, g,b);
      ucg.setFont(ucg_font_helvB14_tr);
      ucg.print("MENU");
      
      //ucg.setFont(ucg_font_helvB08_hr);
      ucg.setColor(r,g,b);
      ucg.drawBox(0, 22, 160, 2);
      //ucg.setColor(0, 255, 255, 255);   // use white as main color for the font
      //ucg.setColor(1, 255,0,0);     // use blue as background for SOLID mode
      ucg.setFont(ucg_font_helvB10_tr);
      ucg.setPrintPos(20,38);  
      ucg.print("Diagnostyka");  // two extra spaces (not sufficient here)
      ucg.setPrintPos(20,52);  
      ucg.print("Spalanie");
      ucg.setPrintPos(20,66);  
      ucg.print("Ustawienia");
      ucg.setPrintPos(20,80);  
      ucg.print("Ekran glowny");
      z=1;
    }
      switch (m)
  {
    case 1: //Diagnostyka
    {
      while (i==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,42, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawBox(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7,56, 9,9);
      ucg.drawFrame(7, 70, 9,9);
      i=1;
      }
      break;
    }
    case 2: //Spalanie
    {
      while (i==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7, 28, 9,9);
      ucg.drawBox(7,56, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawBox(7,42, 9,9);
      ucg.drawFrame(7,56, 9,9);
      ucg.drawFrame(7, 70, 9,9);
      i=1;
      }
      break;
    }
    case 3: //Ustawienia
    {
      while (i==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,42, 9,9);
      ucg.drawBox(7,70, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7, 70, 9,9);
      ucg.drawBox(7,56, 9,9);
      i=1;
      }
      break;
    }
    case 4: //Ekran główny
    {
      while (i==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,56, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7, 56, 9,9);
      ucg.drawBox(7,70, 9,9);
      i=1;
      }
      break;
    }
  }
  //Przyciski
  if (digitalRead(7)== LOW and m<=3)
  {
    m++;
    i=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  
  if (digitalRead(6)== LOW and m>=2)
  {
    m--;
    i=0;
    delay(200);
    while(digitalRead(6)== LOW);     
  }
 //Zatwierdzanie
  if (digitalRead(5)== LOW)
    {
      if (m==1) 
      {
        p=3;
        z=0;
        i=0;
      }
      if (m==2) 
      {
        p=4;
        z=0;
        i=0;
      }
      if (m==3) 
      {
        p=5;
        z=0;
        i=0;
      }
      if (m==4) 
      {
        p=1;
        z=0;
        i=0;
      }
      delay(200);
      while(digitalRead(5)== LOW);
      z=0;
      i=0;
    }
    
}
void diagnostyka()
{
  while (z==0)
    {
      ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(0, 0, ucg.getWidth(), 90);
     
      ucg.setPrintPos(4,20);
      ucg.setColor(r, g,b);
      ucg.setFont(ucg_font_helvB14_tr);
      ucg.print("Diagnostyka");
     
      //ucg.setFont(ucg_font_helvB08_hr);
      ucg.setColor(r,g,b);
      ucg.drawBox(0, 22, 160, 2);
      z=1;
    }
  if (digitalRead(5)== LOW)
    {
      p=2;
      z=0;
      i=0;
    }
}

void spalanie()
{
  while (z==0)
    {
      ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(0, 0, ucg.getWidth(), 90);
      
      ucg.setPrintPos(4,20);
      ucg.setColor(r, g,b);
      ucg.setFont(ucg_font_helvB14_tr);
      ucg.print("Spalanie");
      
      ucg.setColor(r,g,b);
      ucg.drawBox(0, 22, 160, 2);
      ucg.setPrintPos(30,52);
      ucg.print("12,5");
      ucg.setFont(ucg_font_helvB08_tr);
      ucg.setPrintPos(88,40);
      ucg.print("l");
      ucg.setColor(r,g,b);
      ucg.drawBox(73, 42, 37, 2);
      ucg.setPrintPos(75,55);
      ucg.print("100km");
      z=1;
    }
    if (digitalRead(5)== LOW)
    {
    p=2;
    z=0;
    i=0;
    }
}

void ustawienia()
{
  while (z==0)
    {
      ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(0, 0, ucg.getWidth(), 90);
      
      ucg.setPrintPos(4,20);
      ucg.setColor(r, g,b);
      ucg.setFont(ucg_font_helvB14_tr);
      ucg.print("Ustawienia");
      
      //ucg.setFont(ucg_font_helvB08_hr);
      ucg.setColor(r,g,b);
      ucg.drawBox(0, 22, 160, 2);
      ucg.setFont(ucg_font_helvB10_tr);
      ucg.setPrintPos(20,38);  
      ucg.print("Kolor napisow");  // two extra spaces (not sufficient here)
      ucg.setPrintPos(20,52);  
      ucg.print("Kolor tla");
      ucg.setPrintPos(20,66);  
      ucg.print("Powrot");
      z=1;
    }
  
   switch (u)
  {
    case 1: // Kolor napisów
    {
      while (ui==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,42, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawBox(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7,56, 9,9);
      ui=1;
      }
      break;
    }
    case 2: // Kolor tła
    {
      while (ui==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7, 28, 9,9);
      ucg.drawBox(7,56, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawBox(7,42, 9,9);
      ucg.drawFrame(7,56, 9,9);
      ui=1;
      }
      break;
    }
    case 3: // Powrót
    {
      while (ui==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,42, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawBox(7,56, 9,9);
      ui=1;
      }
      break;
    }
   }
   if (digitalRead(7)== LOW and u<=2)
  {
    u++;
    ui=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  
  if (digitalRead(6)== LOW and m>=2)
  {
    u--;
    ui=0;
    delay(200);
    while(digitalRead(6)== LOW);     
  }
  if (digitalRead(5)== LOW)
    {
      if (u==1) 
      {
        p=6;
        z=0;
        i=0;
      }
      if (u==2) 
      {
        p=7;
        z=0;
        i=0;
      }
      if (u==3) 
      {
        p=2;
        z=0;
        i=0;
      }
      delay(200);
      while(digitalRead(5)== LOW);
      z=0;
      ui=0;
    }
}
void KolorNapisow()
{
  while (z==0)
    {
      ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(0, 0, ucg.getWidth(), 90);
     
      ucg.setPrintPos(4,20);
      ucg.setColor(r, g,b);
      ucg.setFont(ucg_font_helvB14_tr);
      ucg.print("Kolor napisow");
      
      //ucg.setFont(ucg_font_helvB08_hr);
      ucg.setColor(r,g,b);
      ucg.drawBox(0, 22, 160, 2);
      ucg.setFont(ucg_font_helvB10_tr);
      ucg.setPrintPos(20,38);  
      ucg.print("Czerwony");  // two extra spaces (not sufficient here)
      ucg.setPrintPos(20,52);  
      ucg.print("Niebieski");
      ucg.setPrintPos(20,66);  
      ucg.print("Zielony");
      ucg.setPrintPos(20,80);  
      ucg.print("Bialy");
      ucg.setPrintPos(20,94);  
      ucg.print("Kolor niest.");
      z=1;
    }
    switch (kn)
  {
    case 1: //Czerwony
    {
      while (kni==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,42, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawBox(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7,56, 9,9);
      ucg.drawFrame(7, 70, 9,9);
      ucg.drawFrame(7,84,9,9);
      kni=1;
      }
      break;
    }
    case 2: //Niebieski
    {
      while (kni==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7, 28, 9,9);
      ucg.drawBox(7,56, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawBox(7,42, 9,9);
      ucg.drawFrame(7,56, 9,9);
      ucg.drawFrame(7, 70, 9,9);
      kni=1;
      }
      break;
    }
    case 3: //Zielony
    {
      while (kni==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,42, 9,9);
      ucg.drawBox(7,70, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7, 70, 9,9);
      ucg.drawBox(7,56, 9,9);
      kni=1;
      }
      break;
    }
    case 4: //Biały
    {
      while (kni==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,56, 9,9);
      ucg.drawBox(7,84,9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7, 56, 9,9);
      ucg.drawFrame(7,84,9,9);
      ucg.drawBox(7,70, 9,9);
      kni=1;
      }
      break;
    }
    case 5: //Kolor niestandardowy
    {
      while (kni==0)
      {
        ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,70, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7, 56, 9,9);
      ucg.drawFrame(7,70,9,9);
      ucg.drawBox(7,84, 9,9);
      kni=1;
      }
    }
  }
    if (digitalRead(7)== LOW and kn<=4)
  {
    kn++;
    kni=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  
  if (digitalRead(6)== LOW and kn>=2)
  {
    kn--;
    kni=0;
    delay(200);
    while(digitalRead(6)== LOW);     
  }
  if (digitalRead(5)== LOW and kn==1) //Czerwony
    {
      r=255;
      g=0;
      b=0;
      p=1;
      z=0;
      kni=0;
      
    }
  if (digitalRead(5)== LOW and kn==2) //Niebieski
    {
      r=0;
      g=0;
      b=255;
      p=1;
      z=0;
      kni=0;
    }
    if (digitalRead(5)== LOW and kn==3) //Zielony
    {
      r=0;
      g=255;
      b=0;
      p=1;
      z=0;
      kni=0;
    }
    if (digitalRead(5)== LOW and kn==4) //Biały
    {
      r=255;
      g=255;
      b=255;
      p=1;
      z=0;
      kni=0;
      kn=1;
    }
}

void KolorTla()
{
  while (z==0)
    {
      ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(0, 0, ucg.getWidth(), 90);
     
      ucg.setPrintPos(4,20);
      ucg.setColor(r, g,b);
      ucg.setFont(ucg_font_helvB14_tr);
      ucg.print("Kolor tla");
     
      //ucg.setFont(ucg_font_helvB08_hr);
      ucg.setColor(r,g,b);
      ucg.drawBox(0, 22, 160, 2);
      ucg.setFont(ucg_font_helvB10_tr);
      ucg.setPrintPos(20,38);  
      ucg.print("Czerwony");  // two extra spaces (not sufficient here)
      ucg.setPrintPos(20,52);  
      ucg.print("Niebieski");
      ucg.setPrintPos(20,66);  
      ucg.print("Czarny");
      ucg.setPrintPos(20,80);  
      ucg.print("Bialy");
      ucg.setPrintPos(20,94);  
      ucg.print("Kolor niest.");
      z=1;
    }
      switch (kt)
  {
    case 1: //Czerwony
    {
      while (kti==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,42, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawBox(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7,56, 9,9);
      ucg.drawFrame(7, 70, 9,9);
      ucg.drawFrame(7,84, 9,9);
      kti=1;
      }
      break;
    }
    case 2: //Niebieski
    {
      while (kti==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7, 28, 9,9);
      ucg.drawBox(7,56, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawBox(7,42, 9,9);
      ucg.drawFrame(7,56, 9,9);
      ucg.drawFrame(7, 70, 9,9);
     kti=1;
      }
      break;
    }
    case 3: //Czarny
    {
      while (kti==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,42, 9,9);
      ucg.drawBox(7,70, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7, 70, 9,9);
      ucg.drawBox(7,56, 9,9);
      kti=1;
      }
      break;
    }
    case 4: //Biały
    {
      while (kti==0)
      {
      ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,56, 9,9);
      ucg.drawBox(7,84, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7, 56, 9,9);
      ucg.drawFrame(7,84, 9,9);
      ucg.drawBox(7,70, 9,9);
      kti=1;
      }
      break;
    }
    case 5: //Kolor niestandardowy
    {
      while (kti==0)
      {
        ucg.setColor(r2,g2,b2);
      ucg.drawBox(7,70, 9,9);
      ucg.setColor(r,g,b);
      ucg.drawFrame(7, 28, 9,9);
      ucg.drawFrame(7,42, 9,9);
      ucg.drawFrame(7, 56, 9,9);
      ucg.drawFrame(7,70,9,9);
      ucg.drawBox(7,84, 9,9);
      kti=1;
      }
    }
  }
    if (digitalRead(7)== LOW and kt<=4)
  {
    kt++;
    kti=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  
  if (digitalRead(6)== LOW and kt>=2)
  {
    kt--;
    kti=0;
    delay(200);
    while(digitalRead(6)== LOW);     
  }
  if (digitalRead(5)== LOW and kt==1) //Czerwony
    {
      r2=255;
      g2=0;
      b2=0;
      p=1;
      z=0;
      kti=0;
    }
    if (digitalRead(5)== LOW and kt==2) //Niebieski
    {
      r2=0;
      g2=0;
      b2=255;
      p=1;
      z=0;
      kti=0;
    }
    if (digitalRead(5)== LOW and kt==3) //Czarny
    {
      r2=0;
      g2=0;
      b2=0;
      p=1;
      z=0;
      kti=0;
    }
    if (digitalRead(5)== LOW and kt==4) //Biały
    {
      r2=255;
      g2=255;
      b2=255;
      p=1;
      z=0;
      kti=0;
      kt=1;
    }

}
void loop() {

  speedo=analogRead(A0);
speedo = map(speedo, 40, 1020, 0, 300);
Serial.println(speedo);
  switch (p)
  {
    case 1:
    {
      mainScreen();
      break;
    }
    case 2:
    {
     menu();  
     break;
    }
    case 3:
    {
      diagnostyka();
      break;
    }
    case 4:
    {
      spalanie();
      break;
    }
    case 5:
    {
      ustawienia();
      break;
    }
    case 6:
    {
      KolorNapisow();
      break;
    }
    case 7:
    {
      KolorTla();
      break;
    }
   }





/*
 
 //Obsługa przycisków w MENU  
  if (digitalRead(7)== LOW and m<=3 and p==1)
  {
    m++;
    i=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  
  if (digitalRead(6)== LOW and m>=3 and p==2)
  {
    m--;
    i=0;
    delay(200);
    while(digitalRead(6)== LOW);     
  }
  
  if (digitalRead(5)== LOW and m==1 and p==2)
  {
    p=2;
    z=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  
  if (digitalRead(5)== LOW and m==2 and p==2)
  {
    p=3;
    z=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }

  if (digitalRead(5)== LOW and m==3 and p==2)
  {
    p=4;
    z=0;
    ui=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  if (digitalRead(5)== LOW and m==4 and p==2)
  {
    p=1;
    z=0;
    ui=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
//Obsługa przycisku w Ustawieniach
if (digitalRead(5)== LOW and p==5 and u==3) //Powrót do menu
  {
    p=1;
    z=0;
    i=0;
    u=1;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
if (digitalRead(7)== LOW and u<=2 and p==5)
  {
    u++;
    ui=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  
  if (digitalRead(6)== LOW and u>=2 and p==5)
  {
    u--;
    ui=0;
    delay(200);
    while(digitalRead(6)== LOW);     
  }
//Pozostała obsługa
  if (digitalRead(5)== LOW and p>2 and p<5)
  {
    p=2;
    z=0;
    i=0;
    delay(200);
    while(digitalRead(7)== LOW);  
  }
  else
  {
    if (digitalRead(5)== LOW and p==1)
    {
    p=2;
    z=0;
    i=0;
    }
  }*/
}
