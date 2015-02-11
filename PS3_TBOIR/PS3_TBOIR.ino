int LED = 13;

void setup()
{

	Serial1.begin(115200);


	pinMode(LED, OUTPUT);
	while (!Serial1)
	{
		digitalWrite(LED, HIGH);
		delay(1000);
		digitalWrite(LED, LOW);
		delay(1000);
	}
	Mouse.begin();
	Keyboard.begin();
}

String cmd;

void loop()
{
	while (Serial1.available())
	{
		char c = Serial1.peek();
		if (c == '\n')
		{

			parseCmd(cmd);
			cmd = "";
		}
		else
		{
			cmd += c;
		}
	}
}


void parseCmd(String i)
{
	String com;
	String arg;

	int spaceIndex = com.indexOf(" ");
	com = i.substring(0, spaceIndex);
	arg = i.substring(spaceIndex + 1);

	if (com.equals("LHX"))
	{
		int val;
		int mval;
		val = arg.toInt();
		if (val < 117)
		{
			map(mval, 0, 116, -10, 1);
		}
		if (val > 137)
		{
			map(mval, 138, 255, 1, 10);
		}

		Mouse.move(mval, 0, 0);

	}

	if (com.equals("LHY"))
	{
		int val;
		int mval;
		val = arg.toInt();
		if (val < 117)
		{
			map(mval, 0, 116, -10, 1);
		}
		if (val > 137)
		{
			map(mval, 138, 255, 1, 10);
		}

		Mouse.move(0, mval, 0);
	}

	if (com.equals( "SQUARE"))
	{
		Keyboard.press(KEY_LEFT_ARROW);
		Keyboard.release(KEY_LEFT_ARROW);
	}

	if (com.equals("TRIANGLE"))
	{
		Keyboard.press(KEY_UP_ARROW);
		Keyboard.release(KEY_UP_ARROW);
	}

	if (com.equals("CIRCLE"))
	{
		Keyboard.press(KEY_RIGHT_ARROW);
		Keyboard.release(KEY_RIGHT_ARROW);
	}

	if (com.equals("CROSS"))
	{
		Keyboard.press(KEY_DOWN_ARROW);
		Keyboard.release(KEY_DOWN_ARROW);
	}

	if (com.equals("START"))
	{
		Keyboard.press(KEY_ESC);
		Keyboard.release(KEY_ESC);
		delay(1000);
	}

	if (com.equals( "L1"))
	{
		Keyboard.press('Q');
		Keyboard.release('Q');
	}

	if (com.equals("L2"))
	{
		Keyboard.press('E');
		Keyboard.release('E');
	}

	if (com.equals("UP"))
	{
		Keyboard.press(' ');
		Keyboard.release(' ');
	}

}
