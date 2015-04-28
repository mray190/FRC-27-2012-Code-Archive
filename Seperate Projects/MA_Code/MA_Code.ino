#include <SPI.h>
#include <Ethernet.h>
#include <RobotOpen.h>


/* I/O Setup */
USBJoystick usb1('0');  // Assign the logitech USBJoystick object to bundle 0


void setup()
{
  /* Initiate comms */
  RobotOpen::init();
}


/* This is your primary robot loop - all of your code
 * should live here that allows the robot to operate
 */
void enabled() {
  // Constantly update PWM values with joystick values
  RobotOpen::setPWM(SIDECAR_PWM1, map(usb1.makePWM(LOGITECH_LEFTY, NORMAL), 0, 255, 104, 150));
  RobotOpen::setPWM(SIDECAR_PWM2, map(usb1.makePWM(LOGITECH_RIGHTY, INVERT), 0, 255, 104, 150));
}


/* This is called while the robot is disabled
 * You must make sure to set all of your outputs
 * to safe/disable values here
 */
void disabled() {
}


/* This loop ALWAYS runs - only place code here that can run during a disabled state
 * This is also a good spot to put driver station publish code
 * You can use either publishAnalog, publishDigital, publishByte, publishShort, or publishLong
 * Specify a bundle ID with a single character (a-z, A-Z, 0-9) - Just make sure not to use the same twice!
 */
void timedtasks() {
  RobotOpen::publishAnalog(ANALOG1, 'A');   // Bundle A
}


/* This is the main program loop that keeps comms operational
 * There's no need to touch anything here!!!
 */
void loop() {
  RobotOpen::pollDS();
  if (RobotOpen::enabled())
    enabled();
  else
    disabled();
  timedtasks();
  RobotOpen::outgoingDS();
}
