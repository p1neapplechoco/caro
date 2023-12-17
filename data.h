#pragma once
#pragma once
#ifndef DATA_H
#define DATA_H
#pragma comment(lib, "winmm.lib")

//Library
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

//Namespace
using namespace std;

//Game Data
#define LEFT 10
#define TOP 7

//Console size
#define HEIGHT 720
#define WIDTH 1280

//ASCII Code For Board (Single Line)
#define VERTICAL_LINE_LIGHT char(179) //│
#define HORIZONTAL_LINE_LIGHT char(196) //─
#define RIGHT_TOP_LIGHT char(191) //┐
#define RIGHT_BOTTOM_LIGHT char(217) //┘
#define LEFT_TOP_LIGHT char(218) //┌
#define LEFT_BOTTOM_LIGHT char(192) //└
#define T_SHAPE_UP_LIGHT char(193) //┴
#define T_SHAPE_DOWN_LIGHT char(194) //┬
#define T_SHAPE_RIGHT_LIGHT char(195) //├
#define T_SHAPE_LEFT_LIGHT char(180) //┤
#define CROSS_LIGHT char(197) //┼

//ASCII Code For Board (Double Line)
#define VERTICAL_LINE char(186)
#define HORIZONTAL_LINE char(205)
#define RIGHT_TOP char(187)
#define RIGHT_BOTTOM char(188)
#define LEFT_TOP char(201)
#define LEFT_BOTTOM char(200)
#define T_SHAPE_UP char(202)
#define T_SHAPE_DOWN char(203)
#define T_SHAPE_RIGHT char(204)
#define T_SHAPE_LEFT char(185)
#define CROSS char(206)

// ASCII Code For Box
#define Horizontal_Line char(219) //█
#define Upper_Vertical char(223) //▀
#define Lower_Vertical char(220) //▄

// Menu's Box Data
#define BMax_i 85
#define BMax_j 35
#define BLeft 43
#define BTop 19

// Help Data
#define HLeft 43
#define HTop 5
#define HMax_i 82
#define HMax_j 36
#define Left_Arrow char(17)
#define Right_Arrow char(16)
#define Up_Arrow char(30)
#define Down_Arrow char(31)

// Info data
#define ILeft 43
#define ITop 5
#define IMax_i 82
#define IMax_j 36

struct _POINT {
	int x, y, c;
};

//ASCII Code For Selected Part Of The Menu
#define SELECTED_LEFT char(175)
#define SELECTED_RIGHT char(174)

struct D1_POINT
{
	int x, y;
	string Name;
	wstring WName;
	int width;

	D1_POINT(int _x = 0, int _y = 0, string _Name = "", int _width = 0)
	{
		x = _x; y = _y;
		Name = _Name;
		width = _width;
	}

	D1_POINT(int _x = 0, int _y = 0, wstring _WName = L"", int _width = 0)
	{
		x = _x; y = _y;
		WName = _WName;
		width = _width;
	}
};