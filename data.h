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
#define LEFT 7
#define TOP 3

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

//Menu Control
extern bool key;
extern int _MENU;
extern int _CURRENT_MENU;

//ASCII ARTS
const wstring D2_CAROCHESS_0 = L"  ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄		";
const wstring D2_CAROCHESS_1 = L"▄▄█•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••█▄▄	";
const wstring D2_CAROCHESS_2 = L"█•••██████╗•█████╗•██████╗••██████╗••••••██████╗██╗••██╗███████╗███████╗███████╗••█	";
const wstring D2_CAROCHESS_3 = L"█••██╔════╝██╔══██╗██╔══██╗██╔═══██╗••••██╔════╝██║••██║██╔════╝██╔════╝██╔════╝••█	";
const wstring D2_CAROCHESS_4 = L"█••██║•••••███████║██████╔╝██║•••██║••••██║•••••███████║█████╗••███████╗███████╗••█	";
const wstring D2_CAROCHESS_5 = L"█••██║•••••██╔══██║██╔══██╗██║•••██║••••██║•••••██╔══██║██╔══╝••╚════██║╚════██║••█	";
const wstring D2_CAROCHESS_6 = L"█••╚██████╗██║••██║██║••██║╚██████╔╝••••╚██████╗██║••██║███████╗███████║███████║••█	";
const wstring D2_CAROCHESS_7 = L"█•••╚═════╝╚═╝••╚═╝╚═╝••╚═╝•╚═════╝••••••╚═════╝╚═╝••╚═╝╚══════╝╚══════╝╚══════╝••█	";
const wstring D2_CAROCHESS_8 = L"▀▀█•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••█▀▀	";
const wstring D2_CAROCHESS_9 = L"  ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀		";


const wstring D2_HCMUS_1 = L" ▄ .▄ ▄▄· • ▌ ▄ ·. ▄• ▄▌.▄▄ ·	";
const wstring D2_HCMUS_2 = L"██▪▐█▐█ ▌▪·██ ▐███▪█▪██▌▐█ ▀.	";
const wstring D2_HCMUS_3 = L"██▀▀███ ▄▄▐█ ▌▐▌▐█·█▌▐█▌▄▀▀▀█▄	";
const wstring D2_HCMUS_4 = L"██▌▐▀▐███▌██ ██▌▐█▌▐█▄█▌▐█▄▪▐█	";
const wstring D2_HCMUS_5 = L"▀▀▀ ··▀▀▀ ▀▀  █▪▀▀▀ ▀▀▀  ▀▀▀▀	";

//D2_CHARACTER = 0
const wstring D2_COMPUTER_1 = L"▐▓█▀▀▀▀▀▀▀▀▀█▓▌░▄▄▄▄▄░";
const wstring D2_COMPUTER_2 = L"▐▓█░░▀░░▀▄░░█▓▌░█▄▄▄█░";
const wstring D2_COMPUTER_3 = L"▐▓█░░▄░░▄▀░░█▓▌░█▄▄▄█░";
const wstring D2_COMPUTER_4 = L"▐▓█▄▄▄▄▄▄▄▄▄█▓▌░█████░";
const wstring D2_COMPUTER_5 = L"░░░░▄▄███▄▄░░░░░█████░";

//D2_CHARACTER = 1
const wstring D2_BEAR_1 = L"───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───";
const wstring D2_BEAR_2 = L"───█▒▒░░░░░░░░░▒▒█───";
const wstring D2_BEAR_3 = L"────█░░█░░░░░█░░█────";
const wstring D2_BEAR_4 = L"─▄▄──█░░░▀█▀░░░█──▄▄─";
const wstring D2_BEAR_5 = L"█░░█─▀▄░░░░░░░▄▀─█░░█";

//D2_CHARACTER = 2
const wstring D2_ROBOT_1 = L"▒▒▒▒▒▒▐███████▌		";
const wstring D2_ROBOT_2 = L"▒▒▒▒▒▒▐░▀░▀░▀░▌		";
const wstring D2_ROBOT_3 = L"▒▒▒▒▒▒▐▄▄▄▄▄▄▄▌		";
const wstring D2_ROBOT_4 = L"▄▀▀▀█▒▐░▀▀▄▀▀░▌▒█▀▀▀▄	";
const wstring D2_ROBOT_5 = L"▌▌▌▌▐▒▄▌░▄▄▄░▐▄▒▌▐▐▐▐	";

//D2_CHARACTER = 3
const wstring D2_CAT_1 = L"──────▄▀▄─────▄▀▄	  ";
const wstring D2_CAT_2 = L"─────▄█░░▀▀▀▀▀░░█▄	  ";
const wstring D2_CAT_3 = L"─▄▄──█░░░░░░░░░░░█──▄▄ ";
const wstring D2_CAT_4 = L"█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█";
const wstring D2_CAT_5 = L"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";

//D2_CHARACTER = 4
const wstring D2_ALIEN_1 = L"▒▒▄▀▀▀▀▀▄▒▒▒▒▒▄▄▄▄▄▒▒▒";
const wstring D2_ALIEN_2 = L"▒▐░▄░░░▄░▌▒▒▄█▄█▄█▄█▄▒";
const wstring D2_ALIEN_3 = L"▒▐░▀▀░▀▀░▌▒▒▒▒▒░░░▒▒▒▒";
const wstring D2_ALIEN_4 = L"▒▒▀▄░═░▄▀▒▒▒▒▒▒░░░▒▒▒▒";
const wstring D2_ALIEN_5 = L"▒▒▐░▀▄▀░▌▒▒▒▒▒▒░░░▒▒▒▒";

//D2_CHARACTER = 5
const wstring D2_LION_1 = L"───▄▀▀▀▀▀───▄█▀▀▀█▄	";
const wstring D2_LION_2 = L"──▐▄▄▄▄▄▄▄▄██▌▀▄▀▐██";
const wstring D2_LION_3 = L"──▐▒▒▒▒▒▒▒▒███▌▀▐███";
const wstring D2_LION_4 = L"───▌▒▓▒▒▒▒▓▒██▌▀▐██	";
const wstring D2_LION_5 = L"───▌▓▐▀▀▀▀▌▓─▀▀▀▀▀	";

//D2_CHARACTER = 6
const wstring D2_CROCODILE_1 = L"░░░░░▄▄▄▄▄░▄░▄░▄░▄		";
const wstring D2_CROCODILE_2 = L"▄▄▄▄██▄████▀█▀█▀█▀██▄	";
const wstring D2_CROCODILE_3 = L"▀▄▀▄▀▄████▄█▄█▄█▄█████	";
const wstring D2_CROCODILE_4 = L"▒▀▀▀▀▀▀▀▀██▀▀▀▀██▀▒▄██	";
const wstring D2_CROCODILE_5 = L"▒▒▒▒▒▒▒▒▀▀▒▒▒▒▀▀▄▄██▀▒	";

//D2_CHARACTER = 7
const wstring D2_SNAKE_1 = L"▄▄▀█▄───▄───────▄		";
const wstring D2_SNAKE_2 = L"▀▀▀██──███─────███		";
const wstring D2_SNAKE_3 = L"░▄██▀░█████░░░█████░░	";
const wstring D2_SNAKE_4 = L"███▀▄███░███░███░███░▄	";
const wstring D2_SNAKE_5 = L"▀█████▀░░░▀███▀░░░▀██▀	";

//D2_CHARACTER = 8
const wstring D2_CRAB_1 = L"░░▄█▀▀▀░░░░░░░░▀▀▀█▄	";
const wstring D2_CRAB_2 = L"▄███▄▄░░▀▄██▄▀░░▄▄███▄	";
const wstring D2_CRAB_3 = L"▀██▄▄▄▄████████▄▄▄▄██▀	";
const wstring D2_CRAB_4 = L"░░▄▄▄▄██████████▄▄▄▄	";
const wstring D2_CRAB_5 = L"░▐▐▀▐▀░▀██████▀░▀▌▀▌▌	";

//D2_CHARACTER = 9
const wstring D2_TURTLE_1 = L"─▄▀▀▀▄────▄▀█▀▀█▄		";
const wstring D2_TURTLE_2 = L"▄▀─▀─▀▄▄▀█▄▀─▄▀─▄▀▄	";
const wstring D2_TURTLE_3 = L"█▄▀█───█─█▄▄▀─▄▀─▄▀▄	";
const wstring D2_TURTLE_4 = L"──█▄▄▀▀█▄─▀▀▀▀▀▀▀─▄█	";
const wstring D2_TURTLE_5 = L"─────▄████▀▀▀▀████─▀▄	";

//D2_CHARACTER = 10
const wstring D2_WHALE_1 = L"─────▀▄▀─────▄─────▄	";
const wstring D2_WHALE_2 = L"──▄███████▄──▀██▄██▀	";
const wstring D2_WHALE_3 = L"▄█████▀█████▄──▄█		";
const wstring D2_WHALE_4 = L"███████▀████████▀		";
const wstring D2_WHALE_5 = L"─▄▄▄▄▄▄███████▀		";


const wstring D2_NEWGAME_1 = L"███╗   ██╗███████╗██╗    ██╗     ██████╗  █████╗ ███╗   ███╗███████╗";
const wstring D2_NEWGAME_2 = L"████╗  ██║██╔════╝██║    ██║    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝";
const wstring D2_NEWGAME_3 = L"██╔██╗ ██║█████╗  ██║ █╗ ██║    ██║  ███╗███████║██╔████╔██║█████╗  ";
const wstring D2_NEWGAME_4 = L"██║╚██╗██║██╔══╝  ██║███╗██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ";
const wstring D2_NEWGAME_5 = L"██║ ╚████║███████╗╚███╔███╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗";
const wstring D2_NEWGAME_6 = L"╚═╝  ╚═══╝╚══════╝ ╚══╝╚══╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝";


const wstring D2_SAVEDGAMES_1 = L"███████╗ █████╗ ██╗   ██╗███████╗██████╗      ██████╗  █████╗ ███╗   ███╗███████╗███████╗";
const wstring D2_SAVEDGAMES_2 = L"██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔════╝";
const wstring D2_SAVEDGAMES_3 = L"███████╗███████║██║   ██║█████╗  ██║  ██║    ██║  ███╗███████║██╔████╔██║█████╗  ███████╗";
const wstring D2_SAVEDGAMES_4 = L"╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  ██║  ██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ╚════██║";
const wstring D2_SAVEDGAMES_5 = L"███████║██║  ██║ ╚████╔╝ ███████╗██████╔╝    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗███████║";
const wstring D2_SAVEDGAMES_6 = L"╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═════╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝";


const wstring D2_PLAYER01_1 = L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██████╗  ██╗";
const wstring D2_PLAYER01_2 = L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ██╔═████╗███║";
const wstring D2_PLAYER01_3 = L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ██║██╔██║╚██║";
const wstring D2_PLAYER01_4 = L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ████╔╝██║ ██║";
const wstring D2_PLAYER01_5 = L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ╚██████╔╝ ██║";
const wstring D2_PLAYER01_6 = L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═════╝  ╚═╝";


const wstring D2_PLAYER02_1 = L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██████╗ ██████╗	";
const wstring D2_PLAYER02_2 = L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ██╔═████╗╚════██╗	";
const wstring D2_PLAYER02_3 = L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ██║██╔██║ █████╔╝	";
const wstring D2_PLAYER02_4 = L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ████╔╝██║██╔═══╝	";
const wstring D2_PLAYER02_5 = L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ╚██████╔╝███████╗	";
const wstring D2_PLAYER02_6 = L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═════╝ ╚══════╝	";


const wstring D2_SETTINGS_1 = L"███████╗███████╗████████╗████████╗██╗███╗   ██╗ ██████╗ ███████╗";
const wstring D2_SETTINGS_2 = L"██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗  ██║██╔════╝ ██╔════╝";
const wstring D2_SETTINGS_3 = L"███████╗█████╗     ██║      ██║   ██║██╔██╗ ██║██║  ███╗███████╗";
const wstring D2_SETTINGS_4 = L"╚════██║██╔══╝     ██║      ██║   ██║██║╚██╗██║██║   ██║╚════██║";
const wstring D2_SETTINGS_5 = L"███████║███████╗   ██║      ██║   ██║██║ ╚████║╚██████╔╝███████║";
const wstring D2_SETTINGS_6 = L"╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝";


const wstring D2_ABOUT_1 = L" █████╗ ██████╗  ██████╗ ██╗   ██╗████████╗";
const wstring D2_ABOUT_2 = L"██╔══██╗██╔══██╗██╔═══██╗██║   ██║╚══██╔══╝";
const wstring D2_ABOUT_3 = L"███████║██████╔╝██║   ██║██║   ██║   ██║   ";
const wstring D2_ABOUT_4 = L"██╔══██║██╔══██╗██║   ██║██║   ██║   ██║   ";
const wstring D2_ABOUT_5 = L"██║  ██║██████╔╝╚██████╔╝╚██████╔╝   ██║   ";
const wstring D2_ABOUT_6 = L"╚═╝  ╚═╝╚═════╝  ╚═════╝  ╚═════╝    ╚═╝   ";


const wstring D2_HELP_1 = L"██╗  ██╗███████╗██╗     ██████╗ ";
const wstring D2_HELP_2 = L"██║  ██║██╔════╝██║     ██╔══██╗";
const wstring D2_HELP_3 = L"███████║█████╗  ██║     ██████╔╝";
const wstring D2_HELP_4 = L"██╔══██║██╔══╝  ██║     ██╔═══╝ ";
const wstring D2_HELP_5 = L"██║  ██║███████╗███████╗██║     ";
const wstring D2_HELP_6 = L"╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ";


const wstring D2_WIN_1 = L"██╗    ██╗██╗███╗   ██╗";
const wstring D2_WIN_2 = L"██║    ██║██║████╗  ██║";
const wstring D2_WIN_3 = L"██║ █╗ ██║██║██╔██╗ ██║";
const wstring D2_WIN_4 = L"██║███╗██║██║██║╚██╗██║";
const wstring D2_WIN_5 = L"╚███═███═╝██╝██╝ ╚████╝";


const wstring D2_LOSE_1 = L"██╗      ██████╗ ███████╗███████";
const wstring D2_LOSE_2 = L"██║     ██╔═══██╗██╔════╝██╔═══╝";
const wstring D2_LOSE_3 = L"██║     ██║   ██║███████╗█████╗	";
const wstring D2_LOSE_4 = L"██╚════╗██║   ██║╚════██║██╔══╝	";
const wstring D2_LOSE_5 = L"███████╝╚██████═╝███████╝███████";


const wstring D1_TOPPLAYERS_1 = L"▀▀█▀▀  █▀▀█  █▀▀█    █▀▀█  █    █▀▀▄  █   █  █▀▀▀  █▀▀▄  █▀▀▀█";
const wstring D1_TOPPLAYERS_2 = L"  █    █  █  █▄▄█    █▄▄█  █    █▄▄█  ▀▄▄▄▀  █▀▀▀  █▄▄▀  ▀▀▀▄▄";
const wstring D1_TOPPLAYERS_3 = L"  █    █▄▄█  █       █     █▄▄█ █  █    █    █▄▄▄  █  █  █▄▄▄█";


const wstring D1_MENULOGO_1 = L" ▄▄   ▄▄ ▄▄▄▄▄▄▄ ";
const wstring D1_MENULOGO_2 = L"█  █▄█  █       █";
const wstring D1_MENULOGO_3 = L"█       █    ▄▄▄█";
const wstring D1_MENULOGO_4 = L"█       █   █▄▄▄ ";
const wstring D1_MENULOGO_5 = L"█       █    ▄▄▄█";
const wstring D1_MENULOGO_6 = L"█ ██▄██ █   █▄▄▄ ";
const wstring D1_MENULOGO_7 = L"█▄█   █▄█▄▄▄▄▄▄▄█";
const wstring D1_MENULOGO_8 = L" ▄▄    ▄ ▄▄   ▄▄ ";
const wstring D1_MENULOGO_9 = L"█  █  █ █  █ █  █";
const wstring D1_MENULOGO_10 = L"█   █▄█ █  █ █  █";
const wstring D1_MENULOGO_11 = L"█       █  █▄█  █";
const wstring D1_MENULOGO_12 = L"█  ▄    █       █";
const wstring D1_MENULOGO_13 = L"█ █ █   █       █";
const wstring D1_MENULOGO_14 = L"█▄█  █▄▄█▄▄▄▄▄▄▄█";

const wstring D2_RUNANDGO_LOGO_01 = L"               ▀▀▀▀▀▀▀▀▀▀▀▀▀▀███████████      ";
const wstring D2_RUNANDGO_LOGO_02 = L"                             ███       █████  ";
const wstring D2_RUNANDGO_LOGO_03 = L"                            ██   ██████     █ ";
const wstring D2_RUNANDGO_LOGO_04 = L"           ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄██  ███    ███   ██";
const wstring D2_RUNANDGO_LOGO_05 = L"                           █   █   ██   ███  █";
const wstring D2_RUNANDGO_LOGO_06 = L"                           █   █    █     █  █";
const wstring D2_RUNANDGO_LOGO_07 = L"                           █   ████    ███  ██";
const wstring D2_RUNANDGO_LOGO_08 = L"       ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀██     █████    ██ ";
const wstring D2_RUNANDGO_LOGO_09 = L"                            █████        ███  ";
const wstring D2_RUNANDGO_LOGO_10 = L"             ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄████████████▀    ";

const wstring D2_RUNANDGO_TEXT_01 = L" █████                 ▄█████    ████▄           ";
const wstring D2_RUNANDGO_TEXT_02 = L"██  ███                █   ██   ██   █▄          ";
const wstring D2_RUNANDGO_TEXT_03 = L"███▄█▀                 ██      ██                ";
const wstring D2_RUNANDGO_TEXT_04 = L"██▀██   ▀██  █ ▀████    █████  ██  █████ ▄███    ";
const wstring D2_RUNANDGO_TEXT_05 = L"██  ██    █ ██  █  ██  ██   ██  ██  ██   █  ██   ";
const wstring D2_RUNANDGO_TEXT_06 = L"█    ▀█▄  ███▀  █   █▄  █████    ████▀   ████▀   ";

const wstring D3_BYE_01 = L" _______  __      __ ________      __     __     __";
const wstring D3_BYE_02 = L"|       \\|\\ \\    /\\ \\\\       \\    |\\ \\   |\\ \\   |\\ \\";
const wstring D3_BYE_03 = L"| ▓▓▓▓▓▓▓\\\\▓▓\\  /  ▓▓ ▓▓▓▓▓▓▓▓    | ▓▓   | ▓▓   | ▓▓";
const wstring D3_BYE_04 = L"| ▓▓__/ ▓▓ \\▓▓\\/  ▓▓| ▓▓__        | ▓▓   | ▓▓   | ▓▓";
const wstring D3_BYE_05 = L"| ▓▓    ▓▓  \\▓▓  ▓▓ | ▓▓  \\       | ▓▓   | ▓▓   | ▓▓";
const wstring D3_BYE_06 = L"| ▓▓▓▓▓▓▓\\   \\▓▓▓▓  | ▓▓▓▓▓        \\▓▓    \\▓▓    \\▓▓";
const wstring D3_BYE_07 = L"| ▓▓__/ ▓▓   | ▓▓   | ▓▓_____      __     __     __";
const wstring D3_BYE_08 = L"| ▓▓    ▓▓   | ▓▓   | ▓▓     \\    |\\ \\   |\\ \\   |\\ \\";
const wstring D3_BYE_09 = L" \\▓▓▓▓▓▓▓     \\▓▓    \\▓▓▓▓▓▓▓▓     \\▓▓    \\▓▓    \\▓▓";

const wstring D3_EXIT_01 = L"███████╗███████╗███████╗    ██╗   ██╗ ██████╗ ██╗   ██╗     █████╗  ██████╗  █████╗ ██╗███╗   ██╗";
const wstring D3_EXIT_02 = L"██╔════╝██╔════╝██╔════╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔══██╗██╔════╝ ██╔══██╗██║████╗  ██║";
const wstring D3_EXIT_03 = L"███████╗█████╗  █████╗       ╚████╔╝ ██║   ██║██║   ██║    ███████║██║  ███╗███████║██║██╔██╗ ██║";
const wstring D3_EXIT_04 = L"╚════██║██╔══╝  ██╔══╝        ╚██╔╝  ██║   ██║██║   ██║    ██╔══██║██║   ██║██╔══██║██║██║╚██╗██║";
const wstring D3_EXIT_05 = L"███████║███████╗███████╗       ██║   ╚██████╔╝╚██████╔╝    ██║  ██║╚██████╔╝██║  ██║██║██║ ╚████║";
const wstring D3_EXIT_06 = L"╚══════╝╚══════╝╚══════╝       ╚═╝    ╚═════╝  ╚═════╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝";

const wstring D2_LOGO2_1 = L"  ▄▄█▀▀▀█▄█     ██     ▀███▀▀▀██▄   ▄▄█▀▀██▄     ";
const wstring D2_LOGO2_2 = L"▄██▀     ▀█    ▄██▄      ██   ▀██▄▄██▀    ▀██▄   ";
const wstring D2_LOGO2_3 = L"██▀       ▀   ▄█▀██▄     ██   ▄██ ██▀      ▀██   ";
const wstring D2_LOGO2_4 = L"██           ▄█  ▀██     ███████  ██        ██   ";
const wstring D2_LOGO2_5 = L"██▄          ████████    ██  ██▄  ██▄      ▄██   ";
const wstring D2_LOGO2_6 = L"▀██▄     ▄▀ █▀      ██   ██   ▀██▄▀██▄    ▄██▀   ";
const wstring D2_LOGO2_7 = L"  ▀▀█████▀▄███▄   ▄████▄████▄ ▄███▄ ▀▀████▀▀     ";




#endif
