// 
// 
// 



#include "DuckyParser.h"
#include "SdFat.h"
#include "USBHID.h"

SdFat sd;
bool DuckyParser::init(int sdPin)
{
	return sd.begin(sdPin);
}
/*
 * Excecutes a ducky script.
 * The int is for special use
 */
void DuckyParser::ExecDucky(int file)
{
	String FileName = file+".txt";
}
void DuckyParser::ExecDucky(String file){
	File myFile = sd.open(file); // Opening a file
	if (myFile) {
		String line = "";
		while (myFile.available()) {
			char m = myFile.read();
			if (m == '\n') { // If char is new-line then excecute that line
				ParseLine(line);
				line = "";
			}
			else if ((int)m != 13)
			{
				line += m; // Adds the char to the line var for excecuting
			}
		}
		ParseLine(line);
	}
	else {
	}
	myFile.close();
}
void DuckyParser::ParseLine(String l)
{
	int space_1 = l.indexOf(" ");
	if (space_1 == -1) // If no space then directly press the SINGLE button
	{
		Press(l);
	}
	else if (l.substring(0, space_1) == "STRING")
	{
		Keyboard.print(l.substring(space_1 + 1)); // Print chars to the PC
	}
	else if (l.substring(0, space_1) == "DELAY") // Speaks for itself
	{
		int delaytime = l.substring(space_1 + 1).toInt();
		delay(delaytime);
	}
	else if (l.substring(0, space_1) == "DEFAULTDELAY") // Speaks for itself
	{
		int delaytime = l.substring(space_1 + 1).toInt();
		delayTime = delaytime;
	}
	else if (l.substring(0, space_1) == "REM") {} // This are commands
	else // Parsing all the special buttons here
	{
		String remain = l;

		while (remain.length() > 0)
		{
			int latest_space = remain.indexOf(" ");
			if (latest_space == -1)
			{
				Press(remain);
				remain = "";
			}
			else
			{
				Press(remain.substring(0, latest_space));
				remain = remain.substring(latest_space + 1);
			}
			delay(5);
		}
	}

	Keyboard.releaseAll();
}

void DuckyParser::Press(String b)
{
	if (b.length() == 1)
	{
		char c = b[0];
		Keyboard.press(c);
	}
	else if (b.equals("ENTER"))
	{
		Keyboard.press(KEY_RETURN);
	}
	else if (b.equals("CTRL"))
	{
		Keyboard.press(KEY_LEFT_CTRL);
	}
	else if (b.equals("SHIFT"))
	{
		Keyboard.press(KEY_LEFT_SHIFT);
	}
	else if (b.equals("ALT"))
	{
		Keyboard.press(KEY_LEFT_ALT);
	}
	else if (b.equals("GUI"))
	{
		Keyboard.press(KEY_LEFT_GUI);
	}
	else if (b.equals("UP") || b.equals("UPARROW"))
	{
		Keyboard.press(KEY_UP_ARROW);
	}
	else if (b.equals("DOWN") || b.equals("DOWNARROW"))
	{
		Keyboard.press(KEY_DOWN_ARROW);
	}
	else if (b.equals("LEFT") || b.equals("LEFTARROW"))
	{
		Keyboard.press(KEY_LEFT_ARROW);
	}
	else if (b.equals("RIGHT") || b.equals("RIGHTARROW"))
	{
		Keyboard.press(KEY_RIGHT_ARROW);
	}
	else if (b.equals("DELETE"))
	{
		Keyboard.press(KEY_DELETE);
	}
	else if (b.equals("PAGEUP"))
	{
		Keyboard.press(KEY_PAGE_UP);
	}
	else if (b.equals("PAGEDOWN"))
	{
		Keyboard.press(KEY_PAGE_DOWN);
	}
	else if (b.equals("HOME"))
	{
		Keyboard.press(KEY_HOME);
	}
	else if (b.equals("ESC"))
	{
		Keyboard.press(KEY_ESC);
	}
	else if (b.equals("INSERT"))
	{
		Keyboard.press(KEY_INSERT);
	}
	else if (b.equals("TAB"))
	{
		Keyboard.press(KEY_TAB);
	}
	else if (b.equals("END"))
	{
		Keyboard.press(KEY_END);
	}
	else if (b.equals("CAPSLOCK"))
	{
		Keyboard.press(KEY_CAPS_LOCK);
	}
	else if (b.equals("F1"))
	{
		Keyboard.press(KEY_F1);
	}
	else if (b.equals("F2"))
	{
		Keyboard.press(KEY_F2);
	}
	else if (b.equals("F3"))
	{
		Keyboard.press(KEY_F3);
	}
	else if (b.equals("F4"))
	{
		Keyboard.press(KEY_F4);
	}
	else if (b.equals("F5"))
	{
		Keyboard.press(KEY_F5);
	}
	else if (b.equals("F6"))
	{
		Keyboard.press(KEY_F6);
	}
	else if (b.equals("F7"))
	{
		Keyboard.press(KEY_F7);
	}
	else if (b.equals("F8"))
	{
		Keyboard.press(KEY_F8);
	}
	else if (b.equals("F9"))
	{
		Keyboard.press(KEY_F9);
	}
	else if (b.equals("F10"))
	{
		Keyboard.press(KEY_F10);
	}
	else if (b.equals("F11"))
	{
		Keyboard.press(KEY_F11);
	}
	else if (b.equals("F12"))
	{
		Keyboard.press(KEY_F12);
	}
}