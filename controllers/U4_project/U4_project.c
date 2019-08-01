
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>
#include <webots/position_sensor.h>
#include <webots/keyboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TIME_STEP 64
#define PI 3.1415


double encoder_left_1_1,encoder_left_1_dif;
double encoder_left_2_1, encoder_left_2_dif;
double encoder_right_1_1, encoder_right_1_dif;
double encoder_right_2_1, encoder_right_2_dif;

int c;
int start;
int key;

float encoder_left_1_angv, encoder_left_2_angv;
float encoder_right_1_angv, encoder_right_2_angv;
float encoder_left_1_linv, encoder_left_2_linv;
float encoder_right_1_linv, encoder_right_2_linv;
float encoder_left_1_rpm, encoder_left_2_rpm;
float encoder_right_1_rpm, encoder_right_2_rpm;

 void goRobot(WbDeviceTag *wheels){

   wb_motor_set_position(wheels[0], INFINITY);
   wb_motor_set_velocity(wheels[0], 4);
   wb_motor_set_position(wheels[1], INFINITY);
   wb_motor_set_velocity(wheels[1], 4);
   wb_motor_set_position(wheels[2], INFINITY);
   wb_motor_set_velocity(wheels[2], 4);
   wb_motor_set_position(wheels[3], INFINITY);
   wb_motor_set_velocity(wheels[3], 4);
 }
 void downRobot(WbDeviceTag *wheels){
   wb_motor_set_position(wheels[0], INFINITY);
   wb_motor_set_velocity(wheels[0], -4);
   wb_motor_set_position(wheels[1], INFINITY);
   wb_motor_set_velocity(wheels[1], -4);
   wb_motor_set_position(wheels[2], INFINITY);
   wb_motor_set_velocity(wheels[2], -4);
   wb_motor_set_position(wheels[3], INFINITY);
   wb_motor_set_velocity(wheels[3], -4);
  }
 void leftRobot(WbDeviceTag *wheels){
   wb_motor_set_position(wheels[0], INFINITY);
   wb_motor_set_velocity(wheels[0], -4);
   wb_motor_set_position(wheels[1], INFINITY);
   wb_motor_set_velocity(wheels[1], 4);
   wb_motor_set_position(wheels[2], INFINITY);
   wb_motor_set_velocity(wheels[2], 4);
   wb_motor_set_position(wheels[3], INFINITY);
   wb_motor_set_velocity(wheels[3], -4);
  }
 void rightRobot(WbDeviceTag *wheels){
   wb_motor_set_position(wheels[0], INFINITY);
   wb_motor_set_velocity(wheels[0], 4);
   wb_motor_set_position(wheels[1], INFINITY);
   wb_motor_set_velocity(wheels[1], -4);
   wb_motor_set_position(wheels[2], INFINITY);
   wb_motor_set_velocity(wheels[2], -4);
   wb_motor_set_position(wheels[3], INFINITY);
   wb_motor_set_velocity(wheels[3], 4);
  }
 void stopRobot(WbDeviceTag *wheels){
   wb_motor_set_position(wheels[0], INFINITY);
   wb_motor_set_velocity(wheels[0], 0);
   wb_motor_set_position(wheels[1], INFINITY);
   wb_motor_set_velocity(wheels[1], 0);
   wb_motor_set_position(wheels[2], INFINITY);
   wb_motor_set_velocity(wheels[2], 0);
   wb_motor_set_position(wheels[3], INFINITY);
   wb_motor_set_velocity(wheels[3], 0);
  }
 void turnRight(WbDeviceTag *wheels){
   wb_motor_set_position(wheels[0], INFINITY);
   wb_motor_set_velocity(wheels[0], 4);
   wb_motor_set_position(wheels[1], INFINITY);
   wb_motor_set_velocity(wheels[1], 4);
   wb_motor_set_position(wheels[2], INFINITY);
   wb_motor_set_velocity(wheels[2], -4);
   wb_motor_set_position(wheels[3], INFINITY);
   wb_motor_set_velocity(wheels[3], -4);
  }
 void turnLeft(WbDeviceTag *wheels){
   wb_motor_set_position(wheels[0], INFINITY);
   wb_motor_set_velocity(wheels[0], -4);
   wb_motor_set_position(wheels[1], INFINITY);
   wb_motor_set_velocity(wheels[1], -4);
   wb_motor_set_position(wheels[2], INFINITY);
   wb_motor_set_velocity(wheels[2], 4);
   wb_motor_set_position(wheels[3], INFINITY);
   wb_motor_set_velocity(wheels[3], 4);
  }
 void manual(){
   wb_keyboard_enable(TIME_STEP);
   key = wb_keyboard_get_key();
   WbDeviceTag wheel_left_1  = wb_robot_get_device("motor_wheel_left_1");
   WbDeviceTag wheel_left_2  = wb_robot_get_device("motor_wheel_left_2");
   WbDeviceTag wheel_right_1 = wb_robot_get_device("motor_wheel_right_1");
   WbDeviceTag wheel_right_2 = wb_robot_get_device("motor_wheel_right_2");
   WbDeviceTag wheels[4];
   wheels[0] = wheel_left_1;
   wheels[1] = wheel_right_1;
   wheels[2] = wheel_left_2;
   wheels[3] = wheel_right_2;

   if(key == WB_KEYBOARD_UP){
     goRobot(wheels);
   }
   else if(key == WB_KEYBOARD_DOWN){
     downRobot(wheels);
   }
   else if(key == WB_KEYBOARD_LEFT){
     leftRobot(wheels);
   }
   else if(key == WB_KEYBOARD_RIGHT){
     rightRobot(wheels);
   }
   else if(key == 'A' ){
     turnRight(wheels);
   }
   else if(key == 'S' ){
     turnLeft(wheels);
   }
   else{
     stopRobot(wheels);
   }
 }
int main(int argc, char **argv)
{
  wb_robot_init();
  WbDeviceTag wheel_left_1  = wb_robot_get_device("motor_wheel_left_1");
  WbDeviceTag wheel_left_2  = wb_robot_get_device("motor_wheel_left_2");
  WbDeviceTag wheel_right_1 = wb_robot_get_device("motor_wheel_right_1");
  WbDeviceTag wheel_right_2 = wb_robot_get_device("motor_wheel_right_2");
  WbDeviceTag wheels[4];
  wheels[0] = wheel_left_1;
  wheels[1] = wheel_right_1;
  wheels[2] = wheel_left_2;
  wheels[3] = wheel_right_2;

  while (wb_robot_step(TIME_STEP) != -1) {
  key = wb_keyboard_get_key();
  if(key == 'S'){
    start = 1;
  }
  while (start == 1) {
    manual();
  }


  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
