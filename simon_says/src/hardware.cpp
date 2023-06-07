#include "hardware.hpp"

int Auge_Links = 2;
bool State_Auge_Links;
int Button_Links = 12;

int Auge_Rechts = 0;
bool State_Auge_Rechts;
int Button_Rechts = 16;

int Button_Mitte = 13;

int Button_Start = 14;
bool State_Start_Button_LED;
int Button_Start_LED = 15;

int Nase_LED = 4;
bool State_Nase_LED;


void Setup(){
    pinMode(Auge_Links, OUTPUT);
    pinMode(Auge_Rechts, OUTPUT);
    pinMode(Button_Start_LED, OUTPUT);
    pinMode(Nase_LED, OUTPUT);

    pinMode(Button_Links, INPUT);
    pinMode(Button_Rechts, INPUT);
    pinMode(Button_Mitte, INPUT);
    pinMode(Button_Start, INPUT);

    Set_Start_Button_LED(1);

}

/////////////////////////////////////-Auge-/////////////////////////////////////
void Set_Links_Auge(bool set){
    digitalWrite(Auge_Links , set);
    State_Auge_Links = set;
}

bool Get_Links_Auge(){
    return State_Auge_Links;
}

void Set_Rechts_Auge(bool set){
    digitalWrite(Auge_Rechts , set);
    State_Auge_Rechts = set;
}

bool Get_Rechts_Auge(){
    return State_Auge_Rechts;
}

/////////////////////////////////////-Button-/////////////////////////////////////
bool Get_Links_Button(){
    return digitalRead(Button_Links);
}

bool Get_Rechts_Button(){
    return digitalRead(Button_Rechts);
}

bool Get_Mitte_Button(){
    return digitalRead(Button_Mitte);
}

/////////////////////////////////////-Start-Button-/////////////////////////////////////
bool Get_Start_Button(){
    return digitalRead(Button_Start);
}

void Set_Start_Button_LED(bool set){
    digitalWrite(Button_Start_LED , set);
    State_Start_Button_LED = set;
}

bool Get_Start_Button_LED(){
    return State_Start_Button_LED;
}

void Set_Nase_LED(bool set){
    digitalWrite(Nase_LED , set);
    State_Nase_LED = set;
}

bool Get_Nase_LED(){
    return State_Nase_LED;
}