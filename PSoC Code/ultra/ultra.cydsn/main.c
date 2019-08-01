 #include "project.h"
#include "string.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define StringToPrint_SIZE 32
#define PWM 120
char StringToPrint[StringToPrint_SIZE];
 
int value_counter=0; 
int con= 0; 
int stop = 0;
int comp = 0;
int dataIn = 0;
int robot_state;
int state; 
int i=0;

float distancia=0.0;        
               
char data[2];
char string[3];
char dato_lit_car; 

enum{
    AUTONOMOUS,
    CONTROLLER,
    AVOID
};

void goRobot(){
    PWM_WriteCompare1(PWM);  
    PWM_1_WriteCompare1(PWM);
    PWM_2_WriteCompare1(PWM); 
    PWM_3_WriteCompare1(PWM);
        
    PWM_WriteCompare2(0);
    PWM_1_WriteCompare2(0);
    PWM_2_WriteCompare2(0);
    PWM_3_WriteCompare2(0);
}

void backRobot(){
    PWM_WriteCompare1(0);  
    PWM_1_WriteCompare1(0);
    PWM_2_WriteCompare1(0); 
    PWM_3_WriteCompare1(0);
        
    PWM_WriteCompare2(PWM);
    PWM_1_WriteCompare2(PWM);
    PWM_2_WriteCompare2(PWM);
    PWM_3_WriteCompare2(PWM);
}

void robotLeft(){
     PWM_WriteCompare1(PWM);
     PWM_2_WriteCompare1(0);
     PWM_1_WriteCompare1(0);
     PWM_3_WriteCompare1(PWM);
         
     PWM_WriteCompare2(0);
     PWM_2_WriteCompare2(PWM);
     PWM_1_WriteCompare2(PWM);
     PWM_3_WriteCompare2(0);   
}

void robotRight(){
     PWM_WriteCompare1(0);
     PWM_2_WriteCompare1(PWM);
     PWM_1_WriteCompare1(PWM);
     PWM_3_WriteCompare1(0);
         
     PWM_WriteCompare2(PWM);
     PWM_2_WriteCompare2(0);
     PWM_1_WriteCompare2(0);
     PWM_3_WriteCompare2(PWM);   
}
void spinLeft(){
     PWM_WriteCompare1(PWM);
     PWM_2_WriteCompare1(PWM);
     PWM_1_WriteCompare1(0);
     PWM_3_WriteCompare1(0);
         
     PWM_WriteCompare2(0);
     PWM_2_WriteCompare2(0);
     PWM_1_WriteCompare2(PWM);
     PWM_3_WriteCompare2(PWM);   
}

void spinRight(){
     PWM_WriteCompare1(0);
     PWM_2_WriteCompare1(0);
     PWM_1_WriteCompare1(PWM);
     PWM_3_WriteCompare1(PWM);
         
     PWM_WriteCompare2(PWM);
     PWM_2_WriteCompare2(PWM);
     PWM_1_WriteCompare2(0);
     PWM_3_WriteCompare2(0);   
}

void Turn(){
    PWM_WriteCompare1(PWM);
    PWM_1_WriteCompare1(PWM);
    PWM_2_WriteCompare1(0);
    PWM_3_WriteCompare1(0);
         
    PWM_WriteCompare2(0);
    PWM_1_WriteCompare2(0);
    PWM_2_WriteCompare2(PWM);
    PWM_3_WriteCompare2(PWM);
}
 
void Stop(){
    PWM_WriteCompare1(0);
    PWM_1_WriteCompare1(0);
    PWM_2_WriteCompare1(0);
    PWM_3_WriteCompare1(0);

    PWM_WriteCompare2(0);
    PWM_1_WriteCompare2(0); 
    PWM_2_WriteCompare2(0); 
    PWM_3_WriteCompare2(0);  
}

int main(void) {
    
    CyGlobalIntEnable;      //habilitación de interrupciones globales
    
    Timer_Start();          //Inicialización del timer
    QuadDec_Start();
    
    UART_Start();
    UART_Enable(); 
    
    PWM_Start();
    PWM_Enable();
    PWM_1_Start();
    PWM_1_Enable();    
    PWM_2_Start();
    PWM_2_Enable();   
    PWM_3_Start();
    PWM_3_Enable();
 
    for(;;)
    {
        if(dataIn <= 3){
            dato_lit_car = UART_GetChar();
        if(dato_lit_car != ' '){
            string[dataIn] = dato_lit_car;
            dataIn++;}
        }   
        else {
            UART_PutString(string);
            dataIn=0;
        }
        
        if (string[1] == 'w') {
            robot_state=CONTROLLER; 
        }
        if (string[1] == 'g') {
            robot_state=AUTONOMOUS; 
        }
        if (robot_state == CONTROLLER) {
            Stop(); 
        }
        if (string[1] == 'u' && robot_state==CONTROLLER) {
            goRobot();   
        }
        if (string[1] == 'd' && robot_state==CONTROLLER) {
            backRobot();    
        }
        if (string[1] == 'l' && robot_state==CONTROLLER) { 
            robotLeft(); 
        }
        if (string[1] == 'r' && robot_state==CONTROLLER) {
            robotRight(); 
        }
        if (string[1] == 'f' && robot_state==CONTROLLER) {
            spinRight(); 
        } 
        if (string[1] == 'a' && robot_state==CONTROLLER) {
            spinLeft(); 
        } 
        if (string[1] == 's') {
            Stop();  
        }   
        
////////////////////////////////////////////////////////////////////////////////////////////////    

        while(echo_Read()==0)
        {
            Trigger_out_Write(1);
            CyDelay(10u);        
            Trigger_out_Write(0);
            CyDelay(1);          
        }
        while(echo_Read()== 1) {}; 
        
        value_counter = 65535-Timer_ReadCounter();        
        distancia = value_counter / 58.0 ;        
                     
        if (distancia <= 30 && robot_state==AUTONOMOUS) { //Solo si la distancia es menor a 30cm
            robot_state=AUTONOMOUS; 
            goRobot(); 
        }
        else {
            i=1;
        }    
        if (i>=1 && i<40) {
            Turn(); 
            i++;
        } 
        else {
           i=0; 
        }  
    } 
}