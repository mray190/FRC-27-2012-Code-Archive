/*
  RobotOpen.h - Library implementation of the RobotOpen Hardware found at www.RobotOpen.biz
  Created by Eric Barch, October 16, 2011.
*/

#ifndef RobotOpen_h
#define RobotOpen_h

#include "Arduino.h"

// Logitech Mapping Windows
#define LOGITECH_RIGHTY 0
#define LOGITECH_RIGHTX 1
#define LOGITECH_LEFTY 2
#define LOGITECH_LEFTX 3
#define LOGITECH_DPAD 4
#define LOGITECH_BTN1 5
#define LOGITECH_BTN2 6
#define LOGITECH_BTN3 7
#define LOGITECH_BTN4 8
#define LOGITECH_BTN5 9
#define LOGITECH_BTN6 10
#define LOGITECH_BTN7 11
#define LOGITECH_BTN8 12
#define LOGITECH_BTN9 13
#define LOGITECH_BTN10 14
#define LOGITECH_LEFTBTN 15
#define LOGITECH_RIGHTBTN 16

// Logitech Mapping OS X
#define LOGITECH_BTN1_MAC 0
#define LOGITECH_BTN2_MAC 1
#define LOGITECH_BTN3_MAC 2
#define LOGITECH_BTN4_MAC 3
#define LOGITECH_BTN5_MAC 4
#define LOGITECH_BTN6_MAC 5
#define LOGITECH_BTN7_MAC 6
#define LOGITECH_BTN8_MAC 7
#define LOGITECH_BTN9_MAC 8
#define LOGITECH_BTN10_MAC 9
#define LOGITECH_LEFTBTN_MAC 10
#define LOGITECH_RIGHTBTN_MAC 11
#define LOGITECH_LEFTX_MAC 12
#define LOGITECH_LEFTY_MAC 13
#define LOGITECH_RIGHTX_MAC 14
#define LOGITECH_RIGHTY_MAC 15
#define LOGITECH_DPAD_MAC 16

// D-PAD Constants
#define UP 0x3F
#define UP_LEFT 0x1F
#define UP_RIGHT 0x5F
#define DOWN 0xBF
#define DOWN_LEFT 0xDF
#define DOWN_RIGHT 0x9F
#define LEFT 0xFF
#define RIGHT 0x7F

// Joystick modifiers
#define INVERT 1
#define NORMAL 0

// Sidecar Mapping
#define ANALOG1 0
#define ANALOG2 1
#define ANALOG3 2
#define ANALOG4 3
#define ANALOG5 4
#define ANALOG6 5
#define SIDECAR_DIGITAL1 7
#define SIDECAR_DIGITAL2 6
#define SIDECAR_DIGITAL3 5
#define SIDECAR_DIGITAL4 4
#define SIDECAR_DIGITAL5 3
#define SIDECAR_DIGITAL6 2
#define SIDECAR_DIGITAL7 9
#define SIDECAR_DIGITAL8 8
#define SIDECAR_PWM1 1
#define SIDECAR_PWM2 2
#define SIDECAR_PWM3 3
#define SIDECAR_PWM4 4
#define SIDECAR_PWM5 5
#define SIDECAR_PWM6 6
#define SIDECAR_PWM7 7
#define SIDECAR_PWM8 8
#define SIDECAR_PWM9 9
#define SIDECAR_PWM10 10


typedef struct {
   unsigned int length;
   unsigned int payloadIndex;
} bundleInfo;

class RobotOpen {
public:
    // Fire up the RobotOpen object and get things running
    static void init();
    
    // Check for fresh data
    static void pollDS();
    
    // There is a feedback packet ready to send
    static void outgoingDS();

	// Sets a PWM output that is fed to the PWM generator chip
	static void setPWM(int pwmChannel, int value);
    
    // Tells us if the robot is enabled
    static boolean enabled();

    // Used to publish data back to the dashboard
    static void publishAnalog(int pin, unsigned char bundleID);
    static void publishDigital(int pin, unsigned char bundleID);
    static void publishByte(unsigned char byteRead, unsigned char bundleID);
    static void publishShort(unsigned int valueRead, unsigned char bundleID);
    static void publishLong(long valueRead, unsigned char bundleID);
    
	// Get the number of components in a particular bundle
    static int getBundleSize(unsigned char bundleID);
	
    // Used to fetch a component from a data packet
    static int getComponent(unsigned char bundleID, int componentIndex);

private:
    // Periodic Task Functions
    static void handleData();
    static void parsePacket();
    static void swapValidPacket();
    
    // Dumps data back to the DS
    static void publishDS();
    
    // Used to fetch needed info of bundle
    static bundleInfo getBundleInfo(unsigned char bundleID);
    
    // CRC16 checksum function
    static unsigned int calc_crc16(unsigned char *buf, unsigned short len);
};

class USBJoystick
{
  public:
    USBJoystick(unsigned char);
    int getIndex(int index);
    unsigned int makePWM(int index, char mode);
    boolean getBtn(int index, char mode);
    boolean getDpad(int index, unsigned char compare, char mode);
    
  private:
    unsigned char _bundleID;
};

#endif