#pragma once
#pragma once
#ifndef HELP_H
#define HELP_H

#include "Data.h"
#include "console.h"


// Help Data
#define D3_Help_Box_Left 38
#define D3_Help_Box_Top 9
#define D3_Help_Max_i 82
#define D3_Help_Max_j 40
#define D3_Help_Double_Vertical_Line char(205)
#define D3_Help_Double_Horizontal_Line char(186)
#define D3_Left_Arrow char(17)
#define D3_Right_Arrow char(16)
#define D3_Up_Arrow char(30)
#define D3_Down_Arrow char(31)

void DrawArrow();
void DrawKey();
void DrawEnter();
int Help();

#endif