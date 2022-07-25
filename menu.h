#pragma once
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "clockBig.h"

#define LCD_I2C_ADDRESS 0x27
#define LCD_ROW_COUNT       2    // Number of Rows
#define LCD_COL_COUNT       16
LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, LCD_COL_COUNT, LCD_ROW_COUNT);

//#define BacklightDelay 30000// Длительность подсветки
#define BacklightDelay 10000// Длительность подсветки

unsigned long timerBacklight;

#include <BigNumbers_I2C.h>
BigNumbers_I2C bigNum(&lcd);

uint16_t flagind;
bool flag = 1; //lcdbacklight

uint16_t menuActiveFlag = 1;
bool menuActive;

#ifndef QUANTITY_SCREENS                                               //4 экрана по 5 строк в каждом 
#define QUANTITY_SCREENS 4
#endif
#ifndef QUANTITY_LINES
#define QUANTITY_LINES 5
#endif
bool potHandlerEnable = false;


  
