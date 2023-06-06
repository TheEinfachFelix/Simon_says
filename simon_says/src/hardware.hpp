#pragma once

#include <Arduino.h>

void Setup();
void Set_Links_Auge(bool set);
bool Get_Links_Auge();
void Set_Rechts_Auge(bool set);
bool Get_Rechts_Auge();
bool Get_Links_Button();
bool Get_Rechts_Button();
bool Get_Mitte_Button();
bool Get_Start_Button();
void Set_Start_Button_LED(bool set);
bool Get_Start_Button_LED();