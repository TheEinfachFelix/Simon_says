#include "hardware.hpp"

int Auge_Links = 2;
bool State_Auge_Links;
int Button_Links = 12;

int Auge_Rechts = 0;
bool State_Auge_Rechts;
int Button_Rechts = 16;


void Setup(){
    pinMode(2, OUTPUT);
    pinMode(0, OUTPUT);
    pinMode(12, INPUT);
    pinMode(16, INPUT);
    pinMode(A0, INPUT_PULLUP);
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