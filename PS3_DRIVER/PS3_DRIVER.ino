
#include <usbhub.h>
#include <PS3USB.h>

USB Usb;

PS3USB PS3(&Usb);



void setup()
{
	Serial2.begin(115200);
	Serial.begin(9600);

	while (!Serial2);
	if (!Usb.Init() == -1)
	{
		Serial.println("OSC did not start :(");
		while (1);
	}

	
}

void loop()
{
	Usb.Task();
	if (PS3.PS3Connected) 
	{

		//						Processes Left Joystick
		if (PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117)
		{
			Serial2.print("LHX ");
			Serial2.println(PS3.getAnalogHat(LeftHatX), DEC);
			Serial.print("LHX ");
			Serial.println(PS3.getAnalogHat(LeftHatX), DEC);
		}
		
		if (PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117)
		{
			Serial2.print("LHY ");
			Serial2.println(PS3.getAnalogHat(LeftHatY), DEC);
			Serial.print("LHY ");
			Serial.println(PS3.getAnalogHat(LeftHatY), DEC);
		}
		
		//

		//						Processes Right Joystick

		if (PS3.getAnalogHat(RightHatX) > 137 || PS3.getAnalogHat(RightHatX) < 117)
		{
			Serial2.print("RHX ");
			Serial2.println(PS3.getAnalogHat(RightHatX), DEC);
			Serial.print("RHX ");
			Serial.println(PS3.getAnalogHat(RightHatX), DEC);
		}

		if (PS3.getAnalogHat(RightHatY) > 137 || PS3.getAnalogHat(RightHatY) < 117)
		{
			Serial2.print("RHY ");
			Serial2.println(PS3.getAnalogHat(RightHatY), DEC);
			Serial.print("RHY ");
			Serial.println(PS3.getAnalogHat(RightHatY), DEC);
		}
		
		//

		//							Processes Left D-Pad

		if (PS3.getButtonPress(UP))
		{
			Serial2.println("UP ");
			Serial.println("UP ");
		}

		if (PS3.getButtonPress(DOWN))
		{
			Serial2.println("DOWN ");
			Serial.println("DOWN ");
		}

		if (PS3.getButtonPress(LEFT))
		{
			Serial2.println("LEFT ");
			Serial.println("LEFT ");
		}

		if (PS3.getButtonPress(RIGHT))
		{
			Serial2.println("RIGHT ");
			Serial.println("RIGHT ");
		}

		//	

		//								Processes Right Buttons

		if (PS3.getButtonPress(CROSS))
		{
			Serial2.println("CROSS ");
			Serial.println("CROSS ");
		}

		if (PS3.getButtonPress(SQUARE))
		{
			Serial2.println("SQUARE ");
			Serial.println("SQUARE ");
		}

		if (PS3.getButtonPress(TRIANGLE))
		{
			Serial2.println("TRIANGLE ");
			Serial.println("TRIANGLE ");
		}
		
		if (PS3.getButtonPress(CIRCLE))
		{
			Serial2.println("CIRCLE");
			Serial.println("CIRCLE");
		}
		
		//

		//								Processes Trigger Buttons

		if (PS3.getButtonPress(L1))
		{
			Serial2.println("L1 ");
			Serial.println("L1 ");
		}

		if (PS3.getButtonPress(R1))
		{
			Serial2.println("R1 ");
			Serial.println("R1 ");

		}

		if (PS3.getAnalogButton(L2) > 0)
		{
			Serial2.print("L2 ");
			Serial2.println(PS3.getAnalogButton(L2));
			Serial.print("L2 ");
			Serial.println(PS3.getAnalogButton(L2));
		}

		if (PS3.getAnalogButton(R2) > 0)
		{
			Serial2.print("R2 ");
			Serial2.println(PS3.getAnalogButton(R2));
			Serial.print("R2 ");
			Serial.println(PS3.getAnalogButton(R2));
		}

		//

		//							Processes Start, Select and PS button

		if (PS3.getButtonPress(PS))
		{
			Serial2.println("PS ");
			Serial.println("PS ");
		}

		if (PS3.getButtonPress(START))
		{
			Serial2.println("START ");
			Serial.println("START ");
		}

		if (PS3.getButtonPress(SELECT))
		{
			Serial2.println("SELECT ");
			Serial.println("SELECT ");
		}
	}
    delay(20);
}
