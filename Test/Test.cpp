
// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include <fstream>      // std::ifstream


struct keyReport
{
	uint8_t modifier;
	uint8_t keys[6];
};

keyReport keyMacros[9][9];
void readMacros(char *fname)
{
	unsigned char head[54];
	std::ifstream is(fname, std::ios::binary | std::ios::ate);
	if(is.tellg() != 486)
	{
		std::cout << "Filesize is not good";
	}
	for (int i = 0; i < 9; i++) // Macro
	{
		for (int j = 0; j < 9; j++) // Macro Keys
		{
			keyMacros[i][j].modifier = is.get();
			for (int k = 0; k < 6; k++) // Key
			{
				keyMacros[i][k].keys[k] = is.get();
			}
		}
	}

}

int main()
{
	readMacros(const_cast<char*>("F:\\UserFiles\\Documents\\MEGA\\Projects\\ArduinoProjects\\KeyboardProject\\Misc\\macros"));

	int temp;
	std::cin >> temp;
	return 0;
}