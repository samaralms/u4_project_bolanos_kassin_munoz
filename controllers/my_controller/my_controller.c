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
#define OBSTACLE_DISTANCE .17

 enum {
 AUTOMATIC,
 MANUAL
 };



double encoder_left_1_1,encoder_left_1_dif;
double encoder_left_2_1, encoder_left_2_dif;
double encoder_right_1_1, encoder_right_1_dif;
double encoder_right_2_1, encoder_right_2_dif;
double dis_value_left;
double dis_value_right;
double dis_sen_left;
double encoder_left;
double encoder_right;
double value_cm_left;
double value_cm_right;
double turn_l;
double turn_r;
double breakstop = 1;
double dis_sen;
double radio=0.075;
double initial_angle_wheel1;
short int robot_state;
int action;
float VELOCITY = 4.0;
double velocidad, angVel=0;
float a=0;
float b=0;
float pos_final;
float rpm;
float lin_vel_right;



float encoder_left_1_angv, encoder_left_2_angv;
float encoder_right_1_angv, encoder_right_2_angv;
float encoder_left_1_linv, encoder_left_2_linv;
float encoder_right_1_linv, encoder_right_2_linv;
float encoder_left_1_rpm, encoder_left_2_rpm;
float encoder_right_1_rpm, encoder_right_2_rpm;

void goRobot(WbDeviceTag wheel_left_1,WbDeviceTag wheel_right_1,WbDeviceTag wheel_left_2,WbDeviceTag wheel_right_2) {
  wb_motor_set_position(wheel_left_1, INFINITY);
  wb_motor_set_velocity(wheel_left_1, -VELOCITY);
  wb_motor_set_position(wheel_right_1, INFINITY);
  wb_motor_set_velocity(wheel_right_1, -VELOCITY);
  wb_motor_set_position(wheel_left_2, INFINITY);
  wb_motor_set_velocity(wheel_left_2, -VELOCITY);
  wb_motor_set_position(wheel_right_2, INFINITY);
  wb_motor_set_velocity(wheel_right_2, -VELOCITY);
}
void goRobotBack(WbDeviceTag wheel_left_1,WbDeviceTag wheel_right_1,WbDeviceTag wheel_left_2,WbDeviceTag wheel_right_2) {
  wb_motor_set_position(wheel_left_1, INFINITY);
  wb_motor_set_velocity(wheel_left_1, VELOCITY);
  wb_motor_set_position(wheel_right_1, INFINITY);
  wb_motor_set_velocity(wheel_right_1, VELOCITY);
  wb_motor_set_position(wheel_left_2, INFINITY);
  wb_motor_set_velocity(wheel_left_2, VELOCITY);
  wb_motor_set_position(wheel_right_2, INFINITY);
  wb_motor_set_velocity(wheel_right_2, VELOCITY);
}
void stopRobot(WbDeviceTag wheel_left_1,WbDeviceTag wheel_right_1,WbDeviceTag wheel_left_2,WbDeviceTag wheel_right_2){
  wb_motor_set_position(wheel_left_1, INFINITY);
  wb_motor_set_velocity(wheel_left_1, 0);
  wb_motor_set_position(wheel_right_1, INFINITY);
  wb_motor_set_velocity(wheel_right_1, 0);
  wb_motor_set_position(wheel_left_2, INFINITY);
  wb_motor_set_velocity(wheel_left_2, 0);
  wb_motor_set_position(wheel_right_2, INFINITY);
  wb_motor_set_velocity(wheel_right_2, 0);
}
void turnRight(WbDeviceTag wheel_left_1,WbDeviceTag wheel_right_1,WbDeviceTag wheel_left_2,WbDeviceTag wheel_right_2) {
  wb_motor_set_position(wheel_left_1, INFINITY);
  wb_motor_set_velocity(wheel_left_1,  -VELOCITY);
  wb_motor_set_position(wheel_right_1, INFINITY);
  wb_motor_set_velocity(wheel_right_1,  VELOCITY);
  wb_motor_set_position(wheel_left_2, INFINITY);
  wb_motor_set_velocity(wheel_left_2,  VELOCITY);
  wb_motor_set_position(wheel_right_2, INFINITY);
  wb_motor_set_velocity(wheel_right_2,  -VELOCITY);
  
}
void turnLeft(WbDeviceTag wheel_left_1,WbDeviceTag wheel_right_1,WbDeviceTag wheel_left_2,WbDeviceTag wheel_right_2) {
  wb_motor_set_position(wheel_left_1, INFINITY);
  wb_motor_set_velocity(wheel_left_1,  VELOCITY);
  wb_motor_set_position(wheel_right_1, INFINITY);
  wb_motor_set_velocity(wheel_right_1, -VELOCITY);
  wb_motor_set_position(wheel_left_2, INFINITY);
  wb_motor_set_velocity(wheel_left_2,  -VELOCITY);
  wb_motor_set_position(wheel_right_2, INFINITY);
  wb_motor_set_velocity(wheel_right_2,  VELOCITY);
}

void rotateLeft(WbDeviceTag wheel_left_1,WbDeviceTag wheel_right_1,WbDeviceTag wheel_left_2,WbDeviceTag wheel_right_2) {
  wb_motor_set_position(wheel_left_1, INFINITY);
  wb_motor_set_velocity(wheel_left_1,  VELOCITY);
  wb_motor_set_position(wheel_right_1, INFINITY);
  wb_motor_set_velocity(wheel_right_1, -VELOCITY);
  wb_motor_set_position(wheel_left_2, INFINITY);
  wb_motor_set_velocity(wheel_left_2,   VELOCITY);
  wb_motor_set_position(wheel_right_2, INFINITY);
  wb_motor_set_velocity(wheel_right_2, -VELOCITY);
  
}

void rotateRight(WbDeviceTag wheel_left_1,WbDeviceTag wheel_right_1,WbDeviceTag wheel_left_2,WbDeviceTag wheel_right_2) {
  wb_motor_set_position(wheel_left_1, INFINITY);
  wb_motor_set_velocity(wheel_left_1,  -VELOCITY);
  wb_motor_set_position(wheel_right_1, INFINITY);
  wb_motor_set_velocity(wheel_right_1, VELOCITY);
  wb_motor_set_position(wheel_left_2, INFINITY);
  wb_motor_set_velocity(wheel_left_2,  -VELOCITY);
  wb_motor_set_position(wheel_right_2, INFINITY);
  wb_motor_set_velocity(wheel_right_2, VELOCITY);
  
}


void autonomousMode(WbDeviceTag wheel_left_1,WbDeviceTag wheel_right_1,WbDeviceTag wheel_left_2,WbDeviceTag wheel_right_2, WbDeviceTag distance_sensor_left, WbDeviceTag distance_sensor_right) {

  
  goRobot(wheel_left_1,wheel_right_1,wheel_left_2,wheel_right_2);
  printf("turn %f\n",turn_l);
  
  dis_value_left = wb_distance_sensor_get_value(distance_sensor_left);
  value_cm_left = ((dis_value_left *.2)/1660);
  
  dis_value_right = wb_distance_sensor_get_value(distance_sensor_right);
  value_cm_right = ((dis_value_right *.2)/1660);
  
  if (value_cm_left<0.17 && value_cm_left <  dis_value_right) {
     printf("the distance left val is %f\n",value_cm_left);
     turn_l++;
  }if (turn_l>=1 && turn_l<=20){
    turnLeft(wheel_left_1,wheel_right_1,wheel_left_2,wheel_right_2);
  
    turn_l++;
    
  } else {
      turn_l=0;
  }
  
  if (value_cm_right<0.17 && value_cm_right <  dis_value_left) {
     printf("the distance left val is %f\n",value_cm_right);
     turn_r++;
  }if (turn_r>=1 && turn_r<=20){
    turnRight(wheel_left_1,wheel_right_1,wheel_left_2,wheel_right_2);
  
    turn_r++;
    
  } else {
      turn_r=0;
  }
  
  
  
  
}






int main(int argc, char **argv)
{



wb_robot_init();
WbDeviceTag wheel_left_1  = wb_robot_get_device("motor_wheel_left_1");
WbDeviceTag wheel_left_2  = wb_robot_get_device("motor_wheel_left_2");
WbDeviceTag wheel_right_1 = wb_robot_get_device("motor_wheel_right_1");
WbDeviceTag wheel_right_2 = wb_robot_get_device("motor_wheel_right_2");


WbDeviceTag encoder_left_1  = wb_robot_get_device("encoder_wheel_left_1");
WbDeviceTag encoder_left_2  = wb_robot_get_device("encoder_wheel_left_2");
WbDeviceTag encoder_right_1 = wb_robot_get_device("encoder_wheel_right_1");
WbDeviceTag encoder_right_2 = wb_robot_get_device("encoder_wheel_right_2");

WbDeviceTag distance_sensor_left  = wb_robot_get_device("distance_sensor_left");
WbDeviceTag distance_sensor_right  = wb_robot_get_device("distance_sensor_right");

wb_position_sensor_enable(encoder_left_1, TIME_STEP);
wb_position_sensor_enable(encoder_right_1, TIME_STEP);
wb_position_sensor_enable(encoder_left_2, TIME_STEP);
wb_position_sensor_enable(encoder_right_2, TIME_STEP);
wb_distance_sensor_enable(distance_sensor_left, TIME_STEP);
wb_distance_sensor_enable(distance_sensor_right, TIME_STEP);

wb_keyboard_enable(TIME_STEP);

while (wb_robot_step(TIME_STEP) != -1) {

  int key=wb_keyboard_get_key(); 
  a = wb_position_sensor_get_value(encoder_right_1);
    ///rueda 1///
    
    if(robot_state == AUTOMATIC){
      VELOCITY = 5.33;
      pos_final = -a+b;
      printf( "a is %f\n",a);
      printf( "b is %f\n",b);
      printf( "pos_final is %f\n",pos_final);
      angVel = (pos_final/0.064);
      lin_vel_right= angVel*radio;
      b = a;
      printf("My Angular Velocity is: %f [rad/seg]\n",angVel);     
      printf("My Linear Velocity is: %f [m/s]\n", lin_vel_right);
      }

    if(robot_state == MANUAL){
      VELOCITY = 4.0;
      pos_final = -a+b;
      printf( "a is %f\n",a);
      printf( "b is %f\n",b);
      printf( "pos_final is %f\n",pos_final);
      angVel = (pos_final/0.064);
      lin_vel_right= angVel*radio;
      b = a;
      printf("My Angular Velocity is: %f [rad/seg]\n",angVel);     
      printf("My Linear Velocity is: %f [m/s]\n", lin_vel_right);
      }    
   

   if (key == 'G' || robot_state == AUTOMATIC) {
      autonomousMode(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2, distance_sensor_left, distance_sensor_right);
      robot_state = AUTOMATIC;
    }
    
    if (key == 'W') {
      robot_state=MANUAL;
      stopRobot(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2);
     } 
     
     if (key == 'A') {
      robot_state=MANUAL;
      action=key;
      rotateLeft(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2);
     }
     
     if (key == 'S') {
      robot_state=MANUAL;
      action=key;
      rotateRight(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2);
     }
     
    if(key == WB_KEYBOARD_LEFT && robot_state == MANUAL) {
      action=key;
      turnLeft(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2);
    } 
    
    if(key==WB_KEYBOARD_UP && robot_state == MANUAL) {
      action=key;
      goRobot(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2);
    }

    if(key==WB_KEYBOARD_DOWN && robot_state == MANUAL) {
      action=key;
      goRobotBack(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2);
    }

    if(key==WB_KEYBOARD_RIGHT && robot_state == MANUAL) {
      action=key;
      turnRight(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2);
    }

    if(action!=key && robot_state == MANUAL) {
      stopRobot(wheel_left_1, wheel_right_1, wheel_left_2, wheel_right_2);
    }
    
}

wb_robot_cleanup();

return 0;
}
