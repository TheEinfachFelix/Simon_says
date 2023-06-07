#include "main.hpp"

const int MAX_LEVEL  = 100;
int sequence[MAX_LEVEL];
int your_sequence[MAX_LEVEL];
int level  = 1;

int velocity = 1000;

void setup() {
  Serial.begin(115200);
  Setup();

}

//Set_Links_Auge(Get_Links_Button());
//Set_Rechts_Auge(Get_Rechts_Button());

void loop(){
  if  (level == 1)
  generate_sequence();//generate a sequence;

  if (Get_Start_Button()  == LOW || level != 1){
    Set_Start_Button_LED(0);
    show_sequence();    //show the sequence
    get_sequence();     //wait for your sequence
    
  }
  
  //* Serial.println(digitalRead(14));
}

void  show_sequence(){
  Serial.println("show_sequence()");
  Set_Links_Auge(0);
  Set_Rechts_Auge(0);

  for (int i = 0; i < level; i++){
    if(sequence[i] == 5){
      Set_Links_Auge(1);
      delay(velocity);
      Set_Links_Auge(0);
      delay(200);
    } else if (sequence[i] == 4){
      Set_Rechts_Auge(1);
      delay(velocity);
      Set_Rechts_Auge(0);
      delay(200);
    } else if (sequence[i] == 3){
      Set_Links_Auge(1);
      Set_Rechts_Auge(1);
      delay(velocity);
      Set_Links_Auge(0);
      Set_Rechts_Auge(0);
      delay(200);
    } else {
      Serial.println("Error in show sequence: " + String(sequence[i]));
    }
  }
}

void  get_sequence(){
  Serial.println("get_sequence()");
  int flag = 0; //this flag indicates if the sequence is correct

  for  (int i = 0; i < level; i++)    {
    flag = 0;
    while(flag == 0){
      yield();
      if (Get_Links_Button() == LOW){
        Serial.println("links");
        Set_Links_Auge(1);
        your_sequence[i] = 5;
        flag = 1;
        delay(200);
        if  (your_sequence[i] != sequence[i])        {
          wrong_sequence();
          return;
        }
        Set_Links_Auge(0);
      }

      if (Get_Rechts_Button() == LOW){
        Serial.println("Rechts");
        Set_Rechts_Auge(1);
        your_sequence[i]  = 4;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
          wrong_sequence();
          return;
        }
        Set_Rechts_Auge(0);
      }

// beide
      if (Get_Mitte_Button() == LOW){
        Serial.println("Beide");
        Set_Links_Auge(1);
        Set_Rechts_Auge(1);
        your_sequence[i]  = 3;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]){
          wrong_sequence();
          return;
        }
        Set_Links_Auge(0);
        Set_Rechts_Auge(0);
      }
    }
  }
  right_sequence();
}

void generate_sequence(){
  //Serial.println("generate_sequence()");
  randomSeed(millis());  //in this way is really random!!!

  for (int i = 0; i < MAX_LEVEL; i++){
    sequence[i]  = random(3,6);
  }
}

void wrong_sequence(){
  Serial.println("wrong_sequence()");
  int x = 100;
  Set_Start_Button_LED(1);
  for (int i = 0; i < 13;  i++)
    {
    Set_Links_Auge(1);
    Set_Rechts_Auge(1);
    delay(x);
    Set_Links_Auge(0);
    Set_Rechts_Auge(0);
    delay(x);
    
    }
  level  = 1;
  velocity = 1000;
  
}

void right_sequence(){
  Serial.println("right_sequence()");
  Set_Nase_LED(0);
  delay(250);
  Set_Nase_LED(1);
  delay(500);
  Set_Nase_LED(0);
  delay(500);

  if  (level < MAX_LEVEL);
  level++;

  velocity -= 50; //increase difficulty
}