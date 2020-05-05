// Negative logic bump sensors
// P4.7 Bump5, left side of robot
// P4.6 Bump4
// P4.5 Bump3
// P4.3 Bump2
// P4.2 Bump1
// P4.0 Bump0, right side of robot

// Left motor direction connected to P5.4 (J3.29)
// Left motor PWM connected to P2.7/TA0CCP4 (J4.40)
// Left motor enable connected to P3.7 (J4.31)
// Right motor direction connected to P5.5 (J3.30)
// Right motor PWM connected to P2.6/TA0CCP3 (J4.39)
// Right motor enable connected to P3.6 (J2.11)

#include "msp.h"
#include "Bump.h"
#include "Clock.h"
#include "SysTick.h"
#include "CortexM.h"
#include "LaunchPad.h"
#include "Motor.h"
#include "TimerA2.h"

void waitForInput(void) {
  while(LaunchPad_Input()==0);  // wait for touch
  while(LaunchPad_Input());     // wait for release
}

// Driver test
void TimedPause(uint32_t time){
  Clock_Delay1ms(time);          // run for a while and stop
  Motor_Stop();
  waitForInput();
}

void turnRight90(void) {
  Motor_Left(4000, 1000);
  Clock_Delay1ms(750);
}

void turnLeft90(void) {
  Motor_Right(1000, 4000);
  Clock_Delay1ms(750);
}

void checkBump(void) {
  if (Bump_Read()) {
    Motor_Stop();

    Clock_Delay1ms(1500);

    Motor_Backward(4000, 4000);

    Clock_Delay1ms(1500);

    Motor_Stop();

    Clock_Delay1ms(1000);

    turnRight90();
    Motor_Stop();

    Clock_Delay1ms(1000);
  }
}

int main(void){
  Clock_Init48MHz();
  LaunchPad_Init(); // built-in switches and LEDs
  Bump_Init();      // bump switches
  Motor_Init();
  TimerA2_Init(&checkBump, 5000); // 0.01 s period
  EnableInterrupts();
  waitForInput();
  while(1){
    if (LaunchPad_Input()) {
      Motor_Stop();
      Clock_Delay1ms(1000);
      waitForInput();
    }
    Motor_Forward(4000, 4000);
  }
}

