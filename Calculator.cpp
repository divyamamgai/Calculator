#define _WIN32_WINNT 0x0500

#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<windows.h>
#include<process.h>
#include<winuser.h>
#include<string>              // Required for file streaming functions such as getline.
#include<sstream>
#include<dos.h>
#include<time.h>
#include<cstring>
#include<ctime>
#include<wininet.h>           // Required for web data fetching.

using namespace std;

// Global Variables definitions.
// To be altered carefully. Please refer to the documentation.

int ErrorFlag = 0;
const char *SettingsFilePath = "resources/settings.bin";
const char *AboutDataFilePath = "resources/aboutdata.bin";
const char *CurrencyDataFilePath = "resources/currencydata.bin";
const char *CurrencyRateDataFilePath = "resources/currencyratedata.bin";
const char *CurrencyRateDataTempFilePath = "resources/currencyratedatatemp.bin";
const char *ConvertDataFilePath = "resources/convertdata.bin";
const char *MinGWFilePath = "resources/minGW.bin";
const char *CurrencyLogDataFilePath = "Failed Currency Updates Log.txt";
const int StringCharLen = 512;                                 // No. of a chars a STRING array element can store.
const int ButtonsColumnLimit = 6;
const int ButtonsRowLimit = 250;
const int DefaultConsoleWidth = 800;
const int DefaultConsoleHeight = 340;
float FPS = 0.1;
long int MusicStackSize = 102400;                            // No. of bytes to be given to Music related processes.
int IntroEndFlag = 0;                                        // This is a Flag with 1 for true and 0 for false. This is for Intro End Que.
int KeypressSoundID = 0;                                     // This is a Flag with 1 for true and 0 for false. This is for Keypress Action.
int IntroMusicID = 0;                                        // This is a Flag with 1 for true and 0 for false. This is for Into Music.
int IntroStyleID = 0;
int BackgroundMusicFlag = 0;
int BackgroundMusicID = 0;
int BackgroundMusicExecutedCount = 0;
int BackgroundMusicEndFlag = 1;
int MusicID = 2;                                             // This is ID for the background music.
int Temp = 1;                                                // Any Value can be assigned to this variable. (In the range of 'int' data type.)
int PreviousMenuID = 1;                                      // This is the ID for Previous Menu that the user visited. (For back function.)
int CurrentMenuID = 1;                                       // This is the ID for Current Menu that the user is viewing.
int PreviousCalculationID = 0;                               // This is the ID for Previous Calculation the user performed.
int CurrentAddressNoOfLines = 0;
struct button                                                // Structure for a Button Elements.
{
    short int Status;
    int x;
    int y;
    char *Text;
    int FunctionCallID;                                     // Note this should be unique so as to make sure that program perfroms as desired.
};
struct scrolllist {
    short int Status;
    char Text[80];
    int AssociatedID;
    char AdditionalText[80];
};
struct settingslist {
    short int Status;
    char Text[80];
    int SettingID;
};
struct unit {
    int UnitID;
    int UnitPowerValue;
    char UnitName[80];
};
struct input {
    int DataVariableType;
    int DataVariableID;
    int MaximumChar;
    int InputInformationTextID;
    int InputInformationSecondaryTextID;
    short InputFrameStartX;
    short InputFrameStartY;
    int InputFrameWidth;
    int InputFrameHeight;
    short UnitID;
    char *UnitName;
};
unit DefaultUnits[21];
double DoubleVariable[20];
short UnitVariable[20];
int IntegerVariable[20];
char CharacterVariable[20];
string StringVariable[20];
short VariableConvertStatus[20];
int MainFrameShiftX = 0;                                    // Default Value.
int MainFrameShiftY = 9;                                    // Default Value.
int MainFrameWidth = 79;                                    // Default Value.
int MainFrameHeight = 15;                                   // Default Value.
int MainFrameColourType = 0;                                // Default Value.
int MainFrameRoundFlag = 2;                                 // Default Value.
short MenuTempFlag = 0;                                     // This flag is used in some cases in Main Menu function.
const int NumberOfCurrencies = 69;
const int WebRecieveDataSize = 4096;                        // In Bytes.
int UpdateCurrencyRatesTerminateFlag = 0;
const int MaxScrollList = 50;
char *AboutCurrentPageTitle;
int AboutCurrentStartYCordinate;
char *AboutCurrentCurrentAddressText;
char *DefaultCalculationUnitName;
string CalcStringGet = "";
double CalcResult = 0;
int CalcCharCount = 0;
int CalcLineCount = 0;
int CalcCurrentSideMenu = 1;
int CalcBracketFlag = 0;
int CalcNumberInputFlag = 0;
double UnitConversionResult = 0;
string UnitConversionStringResult = "";
int StringOutNoOfLines = 0;
int StringOutEndX = 0;
int StringOutEndY = 0;
string UnitConversionFromFileFromSuffix;
string UnitConversionFromFileToSuffix;
int ScrollInputButtonColumnHack = 0;
const int DefaultCreateButtonColumnWidthValue = 70;
int CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
int AboutJumpID = 0;
string MinGWPath = "C:\\MinGW\\bin\\g++.exe";

// Theme Variables

char LoadingSpirit;
char LoadingFrameTopBottomSpirit;
char LoadingFrameLeftRightSpirit;
char LoadingFrameEdgeTopRightSpirit;
char LoadingFrameEdgeTopLeftSpirit;
char LoadingFrameEdgeBottomRightSpirit;
char LoadingFrameEdgeBottomLeftSpirit;
char HeaderSeparatorSpirit;
char FrameHeaderSpiritMain;
char FrameHeaderEdgeLeftSpirit;
char FrameHeaderEdgeRightSpirit;
char FrameHeaderInnerMainSpirit;
char FrameHeaderMainTopBottomSpirit;
char FrameHeaderMainInnerSpirit;
char FrameHeaderMainLeftRightSpirit;
char FrameHeaderMainEdgesSpirit;
char FrameHeaderMainInnerCornerTopLeftSpirit;
char FrameHeaderMainInnerCornerTopRightSpirit;
char FrameHeaderMainInnerCornerBottomLeftSpirit;
char FrameHeaderMainInnerCornerBottomRightSpirit;
char CurrentAddressSeparatorSpirit;
int CurrentAddressSeparatorRepeatCount;
char DialogBoxMainTopBottomSpirit;
char DialogBoxMainLeftRightSpirit;
char DialogBoxMainInnerSpirit;
char DialogBoxMainOutterSpirit;
char DialogBoxMainEdgeTopRightSpirit;
char DialogBoxMainEdgeTopLeftSpirit;
char DialogBoxMainEdgeBottomRightSpirit;
char DialogBoxMainEdgeBottomLeftSpirit;
char DialogBoxContentSeparatorSpirit;
char SettingsBoxTop;
char SettingsBoxBottom;
char SettingsBoxLeft;
char SettingsBoxRight;
char SettingsBoxSeparator;
char SettingsBoxTopRight;
char SettingsBoxTopLeft;
char SettingsBoxBottomLeft;
char SettingsBoxBottomRight;
char CurrencyOneToManyBoxTop;
char CurrencyOneToManyBoxBottom;
char CurrencyOneToManyBoxLeft;
char CurrencyOneToManyBoxRight;
char CurrencyOneToManyBoxSeparator;
char CurrencyOneToManyBoxTopRight;
char CurrencyOneToManyBoxTopLeft;
char CurrencyOneToManyBoxBottomLeft;
char CurrencyOneToManyBoxBottomRight;
char CalcBoxTop;
char CalcBoxBottom;
char CalcBoxLeft;
char CalcBoxRight;
char CalcBoxSeparator;
char CalcBoxTopRight;
char CalcBoxTopLeft;
char CalcBoxBottomLeft;
char CalcBoxBottomRight;
char ScrollUpSpirit;
char ScrollDownSpirit;
char ScrollLeftSpirit;
char ScrollRightSpirit;

// Defining required constants.

#define CALCULATOR_TITLE "Calculator.1.0 - Divya Mamgai"

// Defining Global Menu Function ID's.

#define ERROR_M 99999
#define ErrorDownloadYes 999991
#define Main_Menu_B_F 999992

#define FirstTimeIntroDemoButton 9901
#define FirstTimeIntroDemoButton2 9902
#define FirstTimeIntroDemoButtonRedoYes 9903
#define FirstTimeIntroDemoButtonRedoNo 9904
#define Play_Intro_B_F 9905

#define Geometrical_Calculations_B_F 2001

#define About_Information_B_F 9001
#define About_Properties_B_F 9002
#define About_Formulas_B_F 9003
#define About_More_B_F 9004

#define Triangles_B_F 3101

#define About_Triangles_B_F 31011
#define Area_of_Triangles_B_F 31012

#define For_Scalene_Triangle_B_F 310121
#define For_Equilateral_Triangle_B_F 310122
#define For_Isosceles_Triangle_B_F 310123

#define Re_Calculate_B_F 3211

#define Perimeter_of_Triangles_B_F 31013

#define For_Scalene_Triangle_Perimeter_B_F 310131
#define For_Equilateral_Triangle_Perimeter_B_F 310132
#define For_Isosceles_Triangle_Perimeter_B_F 310133

#define Calculation_of_Formulae_Triangles_B_F 31014

#define Quadrilateral_B_F 3102

#define About_Quadrilateral_B_F 31021
#define Area_of_Quadrilateral_B_F 31022

#define Area_of_Quadrilateral_Formula_1_B_F 310221
#define Area_of_Quadrilateral_Formula_2_B_F 310222
#define Area_of_Quadrilateral_Formula_3_B_F 310223
#define Area_of_Quadrilateral_Formula_4_B_F 310224

#define Perimeter_of_Quadrilateral_B_F 31023

#define Pentagon_B_F 3103

#define About_Pentagon_B_F 31031
#define Area_of_Pentagon_B_F 31032
#define Perimeter_of_Pentagon_B_F 31033

#define Hexagon_B_F 3104

#define About_Hexagon_B_F 31041
#define Area_of_Hexagon_B_F 31042

#define Area_of_Hexagon_Formula_1_B_F 310421
#define Area_of_Hexagon_Formula_2_B_F 310422
#define Area_of_Hexagon_Formula_3_B_F 310423
#define Area_of_Hexagon_Formula_4_B_F 310424

#define Perimeter_of_Hexagon_B_F 31043

#define Equation_Solving_B_F 2002

#define Linear_Equation_B_F 20021

#define About_Linear_Equation_B_F 200211
#define Solve_Linear_Equation_Two_Variable_B_F 200212
#define Solve_System_Of_Linear_Equation_B_F 200213

#define Quadratic_Equation_B_F 20022

#define About_Quadratic_Equation_B_F 200221
#define Solve_Quadratic_Equation_B_F 200222

#define Calc_B_F 2003

#define Conversions_B_F 2004

#define Currency_B_F 6001

#define Currency_One_To_One_Conversion_B_F 6013
#define Currency_One_To_Many_Conversion_B_F 6014

#define Update_Currency_Exchange_Rates_B_F 6003

#define Continue_From_Last_Point_B_F 6031
#define View_Update_History_B_F 6032
#define Restart_The_Updation_B_F 6033

#define Units_B_F 6002

#define Temperature_B_F 6021
#define Length_B_F 6022
#define Mass_B_F 6023
#define Speed_B_F 6024
#define Volume_B_F 6025
#define Area_B_F 6026
#define Time_B_F 6027
#define Data_Storage_B_F 6028
#define Pressure_B_F 6029
#define Power_B_F 60210
#define Angle_B_F 60211
#define Acceleration_B_F 60212
#define Density_B_F 60213
#define Energy_B_F 60214
#define Force_B_F 60215
#define Torque_B_F 60216

#define Settings_B_F 2005

#define Update_Settings_B_F 7001
#define Reset_Settings_B_F 7002
#define Reset_Settings_Yes_B_F 70021

#define Exit_B_F 2006
#define Back_B_F 2007
#define About_Jump_B_F 2008

// Ending Menu Function ID's.

// Defining Global Menu ID's.

#define Main_Menu_M 1
#define Geometrical_Calculations_M 2

#define Triangles_M 2111

#define About_Triangles_M 21111
#define Area_of_Triangles_M 21112

#define For_Scalene_Triangle_M 211121
#define For_Equilateral_Triangle_M 211122
#define For_Isosceles_Triangle_M 211123

#define Perimeter_of_Triangles_M 21113

#define For_Scalene_Triangle_Perimeter_M 211131
#define For_Equilateral_Triangle_Perimeter_M 211132
#define For_Isosceles_Triangle_Perimeter_M 211133

#define Calculation_of_Formulae_Triangles_M 21114

#define Quadrilateral_M 2112

#define About_Quadrilateral_M 21121
#define Area_of_Quadrilateral_M 21122

#define Area_of_Quadrilateral_Formula_1_M 211221
#define Area_of_Quadrilateral_Formula_2_M 211222
#define Area_of_Quadrilateral_Formula_3_M 211223
#define Area_of_Quadrilateral_Formula_4_M 211224

#define Perimeter_of_Quadrilateral_M 21123

#define Pentagon_M 2113

#define About_Pentagon_M 21131
#define Area_of_Pentagon_M 21132
#define Perimeter_of_Pentagon_M 21133

#define Hexagon_M 2114

#define About_Hexagon_M 21141
#define Area_of_Hexagon_M 21142

#define Area_of_Hexagon_Formula_1_M 211421
#define Area_of_Hexagon_Formula_2_M 211422
#define Area_of_Hexagon_Formula_3_M 211423
#define Area_of_Hexagon_Formula_4_M 211424

#define Perimeter_of_Hexagon_M 21143

#define Equation_Solving_M 3

#define Linear_Equation_M 31

#define About_Linear_Equation_M 311
#define Solve_Linear_Equation_Two_Variable_M 312
#define Solve_System_Of_Linear_Equation_M 313

#define Quadratic_Equation_M 32

#define About_Quadratic_Equation_M 321
#define Solve_Quadratic_Equation_M 322

#define Calc_M 4

#define Conversions_M 5

#define Currency_M 51
#define Currency_Select_M 510

#define Currency_One_To_One_Conversion_M 511
#define Currency_One_To_One_Conversion_Done_M 5111
#define Currency_One_To_Many_Conversion_M 512
#define Currency_One_To_Many_Conversion_Calculate_M 5121

#define Update_Currency_Exchange_Rates_M 53

#define Update_Currency_Exchange_Rates_START_M 531
#define View_Update_History_M 532

#define Units_M 52

#define Temperature_M 521
#define Length_M 522
#define Mass_M 523
#define Speed_M 524
#define Volume_M 525
#define Area_M 526
#define Time_M 527
#define Data_Storage_M 528
#define Pressure_M 529
#define Power_M 5210
#define Angle_M 5211
#define Acceleration_M 5212
#define Density_M 5213
#define Energy_M 5214
#define Force_M 5215
#define Torque_M 5216

#define Settings_M 6

#define Update_Settings_M 61
#define Reset_Settings_M 62

// Ending Menu ID's.

// Defining Global Button ID's.

#define First_Time_Yes_Button 1001
#define First_Time_No_Button 1002
#define Exit_Program_Dialog_Yes_Button 1003
#define Exit_Program_Dialog_No_Button 1004
#define Too_Many_Errors_Dialog_Got_It_Button 1005
#define Too_Many_Errors_Dialog_Need_More_Advice_Button 1006
#define Restart_The_Updation_Dialog_Yes_B_F 1007
#define Update_Currency_Rates_Stop_Yes 1008
#define Update_Currency_Rates_Stop_No 1009
#define Update_Currency_Rates_Completed_Yes 1010
#define Update_Currency_Rates_Completed_No 1011
#define Update_Currency_Rates_Reminder_Yes 1012
#define Update_Currency_Rates_Reminder_No 1013
#define Update_Currency_Rates_Completed_Now_Yes 1014
#define Update_Currency_Rates_Completed_Now_No 1015

// Ending Global Button ID's.

// Calc Function ID's

#define Calc_Function_1 1901
#define Calc_Function_2 1902
#define Calc_Function_3 1903
#define Calc_Function_4 1904
#define Calc_Function_5 1905
#define Calc_Function_6 1906
#define Calc_Function_7 1907
#define Calc_Function_8 1908
#define Calc_Function_9 1909
#define Calc_Function_10 1910
#define Calc_Function_11 1911
#define Calc_Function_12 1912
#define Calc_Function_13 1913
#define Calc_Function_14 1914
#define Calc_Function_15 1915
#define Calc_Function_16 1916
#define Calc_Function_17 1917
#define Calc_Function_18 1918
#define Calc_Function_19 1919
#define Calc_Function_20 1920
#define Calc_Function_21 1921
#define Calc_Function_22 1922
#define Calc_Function_23 1923
#define Calc_Function_24 1924
#define Calc_Function_25 1925
#define Calc_Function_26 1926
#define Calc_Function_27 1927
#define Calc_Function_28 1928
#define Calc_Function_29 1929
#define Calc_Function_30 1930
#define Calc_Function_31 1931
#define Calc_Function_32 1932
#define Calc_Function_33 1933

// Ending Calc Function ID's

// Variable Types

#define IntegerType 00001
#define DoubleType 00002
#define CharacterType 00003
#define StringType 00004

// Units Conversions

#define Temperature_Kelvin 5211
#define Temperature_Celsius 5212
#define Temperature_Fahrenheit 5213
#define Temperature_Rankine 5214
#define Temperature_Reaumur 5215
#define Temperature_Newton 5216

#define Length_No 101
#define Mass_No 70
#define Speed_No 25
#define Volume_No 109
#define Area_No 94
#define Time_No 30
#define Data_Storage_No 38
#define Pressure_No 26
#define Power_No 32
#define Angle_No 31
#define Acceleration_No 44
#define Density_No 146
#define Energy_No 45
#define Force_No 16
#define Torque_No 11

// Math Constants

#define Pi 3.14159

// Frames used in program.

char IntroFrames[][81] =
        {
                "                                                                                ",
                "                                                                                ",
                "                                                                                ",
                "                                                                                ",
                "     ##########%                                                                ",
                "     ##########%                                                                ",
                "     ##%                                                              1.0       ",
                "     ##%                                                                        ",
                "     ##%         ####% #%    #####% #% #% #%    ####% #####% #####% #####%      ",
                "     ##%         ####% #%    #%     #% #% #%    ####% #####% #%  #% #####%      ",
                "     ##%         #% #% #%    #%     #% #% #%    #% #%   #%   #%  #% #%  #%      ",
                "     ##%         ####% #%    #%     #% #% #%    ####%   #%   #%  #% #####%      ",
                "     ##########% #% #% ####% #####% ####% ####% #% #%   #%   #####% #% #%       ",
                "     ##########% #% #% ####% #####% ####% ####% #% #%   #%   #####% #% ##%      ",
                "                                                                                ",
                "                                                             DIVYA MAMGAI       ",
                "                                                                                ",
                "                                                                                ",
                "                                                                                ",
                "                                                                                "
        };
char HeaderFrames[][81] =
        {
                "      #####% #####% #%     #####% #% #% #%     #####% #####% #####% #####%    ",
                "      ##%    #%  #% #%     ##%    #% #% #%     #%  #%   #%   #%  #% #%  #%    ",
                "      ##%    #####% #%     ##%    #% #% #%     #####%   #%   #%  #% #####%    ",
                "      ##%    #%  #% #%     ##%    ####% #%     #%  #%   #%   #%  #% #% #%     ",
                "      #####% #%  #% #####% #####% ####% #####% #%  #%   #%   #####% #% ##%    "
        };
char Strings[][StringCharLen] =
        {
                "Do you really wanna exit this program?",  // 0
                "Please wait while program is terminated.",  // 1
                "Looks like you are new to this type of program! Wanna try a intro on how to use this program?",  // 2
                "It looks like this is the first time you have executed the program! You want any tutorials on how to use this program or not?",  // 3
                "Enter the length of 1st side of the triangle: ",  // 4
                "Enter the length of 2nd side of the triangle: ",  // 5
                "Enter the length of 3rd side of the triangle: ",  // 6
                "Please enter a value that qualifies as a \"double\" or a real number type value.",  // 7
                "Please enter a value that qualifies as a \"int\" or a integer number type value.",  // 8
                "Please enter a value that qualifies as a \"char\" or a single character type value.",  // 9
                "Please enter a value that qualifies as a \"char[]\" or a string type value.",  // 10
                "You have to enter a double compliant value, eg.: 2.234, 546.4, 0.654, etc. The values which are not qualified as double are : .54, 23.234.32, asd23.12, and 123,432 (commas not allowed.).",  // 11
                "The area of the `` you entered is: ",  // 12
                "The values of sides that you have entered doesn't qualify for the sides of a real triangle.",  // 13
                "The values of sides that you have entered dosen't qualify for a `` triangle.",  // 14
                "The triangle you provided qualifies as a Isoceles triangle, do you want to proceed to calculate it's `` with the values you have provided?",  // 15
                "The triangle you provided qualifies as a Equilateral triangle, do you want to proceed to calculate it's `` with the values you have provided?",  // 16
                "Do you want to take a look at About `` to get more a detailed view on ``?",  // 17
                "Enter the length of the equal sides: ",  // 18
                "Enter the length of the remaining side: ",  // 19
                "Enter the length of the three sides:- ",  // 20
                "Do you want re-calculate with some different values?",  // 21
                "Do you really want to restart the currency updating process? [Note: This will delete the already saved last updating point.]",  // 22
                "Do you really want to stop currency updation? [Note: Next time you can start from this point too.]",  // 23
                "Update process has been completed successfully. Do you want to restart it? [Note: If the update process was completed some days ago, you are recommended to restart it.]",  // 24
                "Sufficient amount of time has passed since the last update. It is recommended that you update the currency exchange rates now. Do you want start updation?",  // 25
                "You have succesfully updated the currency exchange rates. Do you want to start converting the currencies now?",  // 26
                "Enter the unit of the side: ",  // 27
                "Total No. of completed Countries: ",  // 28
                "Total No. of failed Countries: ",  // 29
                "Last AtTempting Conversion: ",  // 30
                "Last Update AtTempted Date: ",  // 31
                "Updation Completion Date: ",  // 32
                "[Tap Enter to go back.]",  // 33
                "How do you want to Enter the currency of your choice?", // 34
                "Select the Country whose currency you want to convert: ", // 35
                "Select the Country to whose currency you want to convert ``'s currency to: ", // 36
                "The conversion is as follows: ", // 37
                "Enter the amount you want to convert: ", // 38
                "Enter the unit of the amount: ", // 39
                "The conversion is as follows: ", // 40
                "Do you want to convert with different value?", // 41
                "Currently converting ``'s currency.", // 42
                "The conversion for ``'s currency to all is listed below: ", // 43
                "[Press TAB to enter the amount you want to convert.]", // 44
                "Converting ``'s currency to all the currencies.", // 45
                "Enter the value of n: ", // 46
                "Enter the value of a: ", // 47
                "For `252``251`a ,", // 48
                "For a`252` ,", // 49
                "For e`252` ,", // 50
                "For log[a,n] ,where n - Base and a - Any R+ no. ,", // 51
                "Base of log cannot be 1!", // 52
                "Enter to value of r: ", // 53
                "For nCr[n,r] ,", // 54
                "Value of r cannot be more than n!", // 55
                "For nPr[n,r] ,", // 56
                "An error has been generated! Please check the validity of the mathematical expression you entered, and try again.", // 57
                "Enter the values of p, q, and `224` for a Quadrilateral:  [Refer About Quadrilaterals to know about these variables.]", // 58
                "Enter the length of 1st diagonal, p: ", // 59
                "Enter the length of 2nd diagonal, q: ", // 60
                "Enter the value of angle between diagonals, `224`: ", // 61
                "The perimeter of the `` you entered is: ",  // 62
                "Enter the unit of angle: ", // 63
                "Choose the formula you want to use: ", // 64
                "Enter the values of sides a, b, c,and d and angles A and C for a Quadrilateral[ABCD]:  [Refer About Quadrilaterals to know about these variables.]", // 65
                "Enter the length of side a: ", // 66
                "Enter the length of side b: ", // 67
                "Enter the length of side c: ", // 68
                "Enter the length of side d: ", // 69
                "Enter the value of angle A: ", // 70
                "Enter the value of angle C: ", // 71
                "The values you entered for the variables required are not qualified for a real ``.", // 72
                "Enter the value of angle `237`: ", // 73
                "Enter the values of sides a, b, c,and d and angle `237` for a Quadrilateral[ABCD]:  [Refer About Quadrilaterals to know about these variables.]", // 74
                "Enter the value of x: ", // 75
                "Choose the `` units to convert: ", // 76
                "From : ", // 77
                "To : ", // 78
                "Value : ", // 79
                "Result : ", // 80
                "Enter the values of sides a, b, c,and d for a Quadrilateral[ABCD]:  [Refer About Quadrilaterals to know about these variables.]", // 81
                "Select the Temperature Unit you want to convert :", // 82
                "Select desired option from the list :", // 83
                "Enter the values of m and c for the equation; y = mx + c : ", //84
                "Enter the values of m : ", // 85
                "Enter the values of c : ", // 86
                "For the linear euqation you entered : ", // 87
                "The y cordinate becomes zero at x = ", // 88
                "The x cordinate becomes zero at y = ", // 89
                "The given line is inlcined to the +ve x-axis at an angle of ", // 90
                "For the Quadratic equation, ax`253` + bc + c = 0, enter the values of a, b and c: ", // 91
                "Enter the value of a: ", // 92
                "Enter the value of b: ", // 93
                "Enter the value of c: ", // 94
                "For the Quadratic equation you entered : ", // 95
                "The roots are real and distinct.", // 96
                "The roots are imaginary.", // 97
                "The roots are real and equal.", // 98
                "They are : ", // 99
                "Enter the values of a, b, c and d for the equations; ax + by + cz = d", // 100
                "Enter the value of a: ", // 101
                "Enter the value of b: ", // 102
                "Enter the value of c: ", // 103
                "Enter the value of d: ", // 104
                "The system of linear equation is : ", // 105
                "The system of equations is consistent and solution is unique.", // 106
                "The system of equations is dependent.", // 107
                "The system of equations is inconsistent.", // 108
                "The solution to this system of equations is : ", // 109
                "For a Pentagon(ABCDE) enter the length of the sides: ", // 110
                "Enter the value of e: ", // 111
                "For a Pentagon(ABCDE) enter the length of the side (t): [Refer About Pentagon to know about these variables.]", // 112
                "Enter the value of t: ", // 113
                "Enter the side 1: ", // 114
                "Enter the side 2: ", // 115
                "Enter the side 3: ", // 116
                "Enter the side 4: ", // 117
                "Enter the side 5: ", // 118
                "Enter the side 6: ", // 119
                "Enter the side 7: ", // 120
                "Enter the side 8: ", // 121
                "Enter the side 9: ", // 122
                "Enter the side 10: ", // 123
                "Enter the sides of the Hexagon(ABCDEF): ", // 124
                "For a Hexagon(ABCDEF) enter the length of the side (t): [Refer About Hexagon to know about these variables.]", // 125
                "For a Hexagon(ABCDEF) enter the length of the side (d): [Refer About Hexagon to know about these variables.]", // 126
                "Enter the value of d: ", // 127
                "Enter the value of a: ", // 128
                "Enter the value of p: ", // 129
                "For a Hexagon(ABCDEF) enter the value of a and p: [Refer About Hexagon to know about these variables.]", // 130
                "For a Hexagon(ABCDEF) enter the value of a: [Refer About Hexagon to know about these variables.]", // 131
                "Do you realy want to reset your program's Settings?", // 132
                "To complete the Reset Settings procedure the program is going to terminate.", // 133
                "Before you start crunching some numbers with this    program, you should get used to this program's some  of the best features!", // 134
                "First off, let's begin with how to manipulate throughthe Menu's of this program.", // 135
                "Now, here is just an example of what Buttons are: ", // 136
                "Great! You got it quickly!", // 137
                "Now try to use the arrow keys on your keyboard to    hover over the buttons: `24` `25` `26` `27`", // 138
                "Alright, now moving on to the next part, Keyboard    Shortcuts!", // 139
                "There are a bunch of keyboard shortcuts in this      program to make your work effortless!", // 140
                "Now, all the keyboard shortcuts with what they do    will be shown, so try to keep up!", // 141
                "Escape - To go back a menu.", // 142
                "End - To exit program.", // 143
                "+ - To jump to Calc.", // 144
                "Home - To jump to Home.", // 145
                "Was I too fast? Want to see it again?", // 146
                "Okay, I guess it's time to show you the next best    thing! The new style of inputing data!", // 147
                "This is what I'm talking about: ", // 148
                "What? You didn't thought that this was it? Do you?   Well if you did your wrong!", // 149
                "The new and inovative input method you just saw also has a hidden swing to it!", // 150
                "Just try pressing TAB on the scroll input below: ", // 151
                "Cool? You found it already?!", // 152
                "Cool? This is something new?! Just hit and submit anyone of   them to return to intro.", // 153
                "Everything that has been told to you up until now    just don't do justice to what more lies inside this  program! From flawless NO-ERROR input system to fast and easy conversions from over 850 units! And with   the capability to get currency rates  of more than  65 countries act like a cherry on the topping! Themes,Background Music, Keypress Sounds, Intro and  Exit   Styles, whew...{Somebody water please....}", // 154
                "Use Arrow keys to manipulate the scroll input and    press Enter to submit the choice.", // 155
                "Press Enter to End Intro", // 156
                "There is a very crucial error, it seems like your system doesn't have MinGW installed! Calc feature will not be available till this error is resolved! Do you want to close this program and download MinGW or do you want to ignore this meessage?[Note: This error might be generated because of access denied by administrator.],", // 157
                "Insert - To insert math functions in Calc.", // 158
                "Page Up - To scroll up the function sets in Calc.", // 159
                "Page Down - To scroll down the function sets in Calc." // 160
        };

// Prototype Declaration of Functions.

void InitializeVariable();

int VariableIsEmpty(int, int, int);

void EmptyVariable(int, int, int);

void InitializeTheme();

void CursorToggle(int);

void SetConsoleDimensions(int, int);

void SetCord(short, short);

WORD GetConsoleTextAttribute(HANDLE);

//void SetConsoleFont(int,int,int);
void WebLinkLaunch(char *);

string WebGetData(char *);

int GetCurrentDate(int);

void CopyFileNew(char *, char *);

void ClearFileContents(char *);

void ColorOut(char, int);

void ColorOut(char *, int);

void ColorOut(string, int);

void PauseConsole(float);

void Music(int, int);

void KeypressSound();

void BackgroundMusic(void *);

void IntroMisc(void *);

void SettingsUpdateOnTerminate(void *);

void Terminate(int);

int StringLength(char *);

int StringLength(string);

void StringInterpret(string &, int, string StringReplaceDefault = "");

void Header();

void HeaderMisc(int, int);

void ClearConsole(int);

void ClearFrame(short, short, int, int);

void ButtonFunctions(int);

int CreateButtons(int, button[], int[][2], int[][2], int);

int CreateDialogBox(char[], char[], int, int, int, int[5], int ForceShiftX = 0, int ForceShiftY = 0);

void FirstTimeIntro(int);

void CurrentAddress(char[]);

void MainFrame();

void DefaultMainFrame();

void FrameHeader(short, short, int, short, char *, int);

void StringOut(int, short, short, int, int, string InterpretString = "");

void StringOut(string, short, short, int, int, string InterpretString = "");

void StringOut(string &, short &, short &, int &, int, string InterpretString = "");

int StringDigitValidation(string);

int StringUnitsValidation(string);

int ScrollInput(short, short, short, scrolllist[], int, int, int AdditionalStringID = 83);

void InputDataVariable(int, input);

string SettingsValueInterpreter(int, int);

void SettingsChanger(int, int, int, int);

void UpdateSettingsMenu();

void CurrencyOneToManyCalculate();

void Calc();

void Menu(int);

void About(char *, int, int, char *);

double GetCurrencyRate(char *, char *);

void UpdateCurrencyRatesTerminator(void *);

void UpdateCurrencyRates();

void UnitConversionScrollListGenerator(scrolllist *, int, char *);

double UnitConversionFromFile(char *, int, int, double);

string UnitConvertor(int, int, int);

double Calculate(int);

int CheckMinGW();

void ExitProgram(void);

// Defining the SettingsClass class.

class SettingsClass {
public:
    // All the variables.
    string SettingsStringHolder;
    long int SettingValue[100];

    void DefaultSettings() {
        ofstream SettingsFile(SettingsFilePath);
        // Do not alter this variable unless you are certain of the change it might cause.
        SettingsFile <<
        "PROGRAM_EXECUTION_NO#0|CURRENT_CALCULATION_UNIT#0|COUNTRY_ATTEMPTING#68|COUNTRY_CURRENCY_RATE_ATTEMPTING#68|TOTAL_FAILED#2|TOTAL_COMPLETED#4759|CURRENCY_UPDATE_COMPLETED_DATE_YEAR#14|URRENCY_UPDATE_COMPLETED_DATE_MONTH#1|URRENCY_UPDATE_COMPLETED_DATE_DAY#6|CURRENCY_UPDATE_ATTEMPTING_DATE_YEAR#14|URRENCY_UPDATE_ATTEMPTING_DATE_MONTH#1|URRENCY_UPDATE_ATTEMPTING_DATE_DAY#6|THEME#1|INTRO_MUSIC#0|BACKGROUND_MUSIC#0|KEYPRESS_SOUNDS#0|INTRO_STYLE#5|CONSOLE_POSITION#1|EXIT_STYLE#2";
        SettingsFile.close();
        // To re-establish the Settings Variables.
        SettingsInitializer();
    }

    void SettingsInitializer() {
        ifstream SettingsFile(SettingsFilePath);
        if (SettingsFile.is_open()) {
            while (!(SettingsFile.eof())) {
                getline(SettingsFile, SettingsStringHolder);
            }
            if (StringLength(SettingsStringHolder) == 0) {
                DefaultSettings();
            }
            else {
                string IndividualSettingHolder;
                stringstream SettingsStreamHolder;
                SettingsStreamHolder.str(SettingsStringHolder);
                int SettingIDTemp = 0;
                while (getline(SettingsStreamHolder, IndividualSettingHolder, '|')) {
                    string SettingValueHolderTemp;
                    stringstream SettingValueStreamHolder(IndividualSettingHolder);
                    int Flag = 0;
                    while (getline(SettingValueStreamHolder, SettingValueHolderTemp, '#')) {
                        if (Flag == 1) SettingValue[SettingIDTemp] = atoi(SettingValueHolderTemp.c_str());
                        Flag++;
                    }
                    SettingIDTemp++;
                }
            }
        }
        else {
            DefaultSettings();
        }
        SettingsFile.close();
    }

    // Updating the Settings according to the user's need.
    void SettingsUpdate(int SettingID, int SettingValueHolder) {
        stringstream CompleteSettingsString;
        ifstream SettingsFile(SettingsFilePath);
        if (SettingsFile.is_open()) {
            while (!(SettingsFile.eof())) {
                getline(SettingsFile, SettingsStringHolder);
            }
            string IndividualSettingHolder;
            stringstream SettingsStreamHolder;
            SettingsStreamHolder.str(SettingsStringHolder);
            int SettingIDTemp = 0;
            while (getline(SettingsStreamHolder, IndividualSettingHolder, '|')) {
                string SettingValueHolderTemp;
                stringstream SettingValueStreamHolder(IndividualSettingHolder);
                int Flag = 0;
                while (getline(SettingValueStreamHolder, SettingValueHolderTemp, '#')) {
                    if (Flag == 1) {
                        if (SettingIDTemp == SettingID) {
                            CompleteSettingsString << SettingValueHolder;
                        }
                        else {
                            CompleteSettingsString << SettingValueHolderTemp;
                        }
                        CompleteSettingsString << "|";
                    }
                    else {
                        CompleteSettingsString << SettingValueHolderTemp;
                        CompleteSettingsString << "#";
                    }
                    Flag++;
                }
                SettingIDTemp++;
            }
        }
        SettingsFile.close();
        ofstream SettingsFileUpdateStream(SettingsFilePath, ios::trunc);
        SettingsFileUpdateStream << CompleteSettingsString.str();
        SettingsFileUpdateStream.close();
        SettingsInitializer();
    }

    //Getting Default Unit ID.
    int GetDefaultUnitID() {
        for (int i = 0; i <= 20; i++) {
            if (SettingValue[1] == DefaultUnits[i].UnitPowerValue) {
                return i + 1;
            }
        }
        return 0;
    }

    // Defining the Constructor for the SettingsClass class.
    SettingsClass() {
        SettingsInitializer();
        ifstream MinGWFile(MinGWFilePath);
        if (MinGWFile.is_open()) {
            getline(MinGWFile, MinGWPath);
            MinGWFile.close();
        }
    }
} SettingsObject;                          // Creating SettingsObject object for SettingsClass class.

// Defining the CurrencyClass class.

class CurrencyClass {
public:
    string CurrencyStringHolder;
    string ConversionStringHolder;
    char CurrencyCode[NumberOfCurrencies][4];
    char CurrencyName[NumberOfCurrencies][StringCharLen];
    char CurrencyCountry[NumberOfCurrencies][StringCharLen];

    void DefaultCurrency() {
        ofstream CurrencyFile(CurrencyDataFilePath);
        CurrencyFile <<
        "Argentina#Peso#ARS|Australia#Dollar#AUD|Austria#Euro#EUR|Bahrain#Dinar#BHD|Belgium#Euro#EUR|Bolivia#Boliviano#BOB|Brazil#Real#BRL|Brunei Darussalam#Dollar#BND|Bulgaria#Lev#BGN|Canada#Dollar#CAD|Chile#Peso#CLP|China#Yuan Renminbi#CNY|Colombia#Peso#COP|Croatia#Kuna#HRK|Cyprus#Euro#EUR|Czech Republic#Koruna#CZK|Denmark#Krone#DKK|Egypt#Pound#EGP|Fiji#Dollar#FJD|Finland#Euro#EUR|France#Euro#EUR|Germany#Euro#EUR|Hong Kong#Dollar#HKD|Hungary#Forint#HUF|India#Rupee#INR|Indonesia#Rupiah#IDR|Israel#Shekel#ILS|Italy#Euro#EUR|Japan#Yen#JPY|Kenya#Shilling#KES|Korea (South)#Won#KRW|Kuwait#Dinar#KWD|Lithuania#Litas#LTL|Luxembourg#Euro#EUR|Malaysia#Ringgit#MYR|Malta#Euro#EUR|Mexico#Peso#MXN|Monaco#Euro#EUR|Morocco#Dirham#MAD|Netherlands#Euro#EUR|New Zealand#Dollar#NZD|Norway#Krone#NOK|Pakistan#Rupee#PKR|Peru#Nuevo Sol#PEN|Philippines#Peso#PHP|Poland#Zloty#PLN|Portugal#Euro#EUR|Romania#New Leu#RON|Russia#Ruble#RUB|San Marino#Euro#EUR|Saudi Arabia#Riyal#SAR|Serbia#Dinar#RSD|Singapore#Dollar#SGD|Slovakia#Euro#EUR|Slovenia#Euro#EUR|South Africa#Rand#ZAR|Spain#Euro#EUR|Sweden#Krona#SEK|Switzerland#Franc#CHF|Taiwan#New Dollar#TWD|Thailand#Baht#THB|Turkey#Lira#TRY|Ukraine#Hryvna#UAH|United Arab Emirates#Dirham#AED|United Kingdom#Pound#GBP|United States#Dollar#USD|Vatican#Euro#EUR|Venezuela#Bolivar Fuerte#VEF|Viet Nam#Dong#VND";
        CurrencyFile.close();
        CurrencyInitializer();
    }

    void DefaultCurrencyConversion() {
        UpdateCurrencyRates();
    }

    void CurrencyInitializer() {
        ifstream CurrencyFile(CurrencyDataFilePath);
        if (CurrencyFile.is_open()) {
            while (!(CurrencyFile.eof())) {
                getline(CurrencyFile, CurrencyStringHolder);
            }
            if (StringLength(CurrencyStringHolder) == 0) {
                DefaultCurrency();
            }
            else {
                string IndividualCurrencyHolder;
                stringstream CurrencyStreamHolder;
                CurrencyStreamHolder.str(CurrencyStringHolder);
                int CurrencyIDTemp = 0;
                while (getline(CurrencyStreamHolder, IndividualCurrencyHolder, '|')) {
                    string CurrencyValueHolder;
                    stringstream CurrencyValueStreamHolder(IndividualCurrencyHolder);
                    int Flag = 0;
                    while (getline(CurrencyValueStreamHolder, CurrencyValueHolder, '#')) {
                        if (Flag == 0) strcpy(CurrencyCountry[CurrencyIDTemp], CurrencyValueHolder.c_str());
                        if (Flag == 1) strcpy(CurrencyName[CurrencyIDTemp], CurrencyValueHolder.c_str());
                        if (Flag == 2) strcpy(CurrencyCode[CurrencyIDTemp], CurrencyValueHolder.c_str());
                        Flag++;
                    }
                    CurrencyIDTemp++;
                }
            }
        }
        else {
            DefaultCurrency();
        }
        CurrencyFile.close();
    }

    double CurrencyConversion(int ConversionFromID, int ConversionToID) {
        if ((ConversionFromID > NumberOfCurrencies) || (ConversionToID > NumberOfCurrencies)) return 0;
        if (ConversionFromID == ConversionToID) return 1;
        int ConversionID = ConversionFromID * 69 + ConversionToID;
        ifstream CurrencyConversionFile(CurrencyRateDataFilePath);
        if (CurrencyConversionFile.is_open()) {
            while (!(CurrencyConversionFile.eof())) {
                getline(CurrencyConversionFile, ConversionStringHolder);
            }
            if (StringLength(ConversionStringHolder) == 0) {
                DefaultCurrencyConversion();
            }
            else {
                string IndividualConversionHolder;
                stringstream ConversionStreamHolder;
                ConversionStreamHolder.str(ConversionStringHolder);
                int ConversionIDTemp = 0;
                while (getline(ConversionStreamHolder, IndividualConversionHolder, '|')) {
                    if (ConversionIDTemp == ConversionID) {
                        string ConversionValueHolder;
                        stringstream ConversionValueStreamHolder(IndividualConversionHolder);
                        int Flag = 0;
                        while (getline(ConversionValueStreamHolder, ConversionValueHolder, '#')) {
                            if (Flag == 2) {
                                return atof(ConversionValueHolder.c_str());
                            }
                            Flag++;
                        }
                    }
                    ConversionIDTemp++;
                }
            }
        }
        else {
            DefaultCurrencyConversion();
        }
        CurrencyConversionFile.close();
        return 0;
    }

    CurrencyClass() {
        CurrencyInitializer();
    }
} CurrencyObject;

// Defining Required functions.

// The InitializeVariable() function is used to initialize the variables with some initial value.

void InitializeVariable() {
    // Initializing Calculating variables.
    for (int i = 0; i <= 9; i++) {
        DoubleVariable[i] = 0;
        IntegerVariable[i] = 0;
        CharacterVariable[i] = ' ';
        StringVariable[i] = "";
        UnitVariable[i] = 0;
        VariableConvertStatus[i] = 1;
    }
    // Initializing Unit variables.
    for (int i = 0; i <= 20; i++) {
        int UnitPower;
        char UnitName[80];
        switch (i) {
            case 0:
                UnitPower = -24;
                strcpy(UnitName, "yocto");
                break;
            case 1:
                UnitPower = -21;
                strcpy(UnitName, "zepto");
                break;
            case 2:
                UnitPower = -18;
                strcpy(UnitName, "atto");
                break;
            case 3:
                UnitPower = -15;
                strcpy(UnitName, "femto");
                break;
            case 4:
                UnitPower = -12;
                strcpy(UnitName, "pico");
                break;
            case 5:
                UnitPower = -9;
                strcpy(UnitName, "nano");
                break;
            case 6:
                UnitPower = -6;
                strcpy(UnitName, "micro");
                break;
            case 7:
                UnitPower = -3;
                strcpy(UnitName, "milli");
                break;
            case 8:
                UnitPower = -2;
                strcpy(UnitName, "centi");
                break;
            case 9:
                UnitPower = -1;
                strcpy(UnitName, "deci");
                break;
            case 10:
                UnitPower = 0;
                strcpy(UnitName, "");
                break;
            case 11:
                UnitPower = 1;
                strcpy(UnitName, "deca");
                break;
            case 12:
                UnitPower = 2;
                strcpy(UnitName, "hecto");
                break;
            case 13:
                UnitPower = 3;
                strcpy(UnitName, "kilo");
                break;
            case 14:
                UnitPower = 6;
                strcpy(UnitName, "mega");
                break;
            case 15:
                UnitPower = 9;
                strcpy(UnitName, "giga");
                break;
            case 16:
                UnitPower = 12;
                strcpy(UnitName, "tera");
                break;
            case 17:
                UnitPower = 15;
                strcpy(UnitName, "peta");
                break;
            case 18:
                UnitPower = 18;
                strcpy(UnitName, "exa");
                break;
            case 19:
                UnitPower = 21;
                strcpy(UnitName, "zetta");
                break;
            case 20:
                UnitPower = 24;
                strcpy(UnitName, "yotta");
                break;
            default:
                UnitPower = 0;
                strcpy(UnitName, "");
                break;
        }
        DefaultUnits[i].UnitID = i;
        DefaultUnits[i].UnitPowerValue = UnitPower;
        strcpy(DefaultUnits[i].UnitName, UnitName);
    }
    KeypressSoundID = SettingsObject.SettingValue[15];
    IntroMusicID = SettingsObject.SettingValue[13];
    MusicID = SettingsObject.SettingValue[14];
    IntroStyleID = SettingsObject.SettingValue[16];
    for (int i = 0; i <= 20; i++) {
        if (SettingsObject.SettingValue[1] == DefaultUnits[i].UnitPowerValue) {
            DefaultCalculationUnitName = DefaultUnits[i].UnitName;
            break;
        }
    }
    // Initializing Theme variables.
    InitializeTheme();
}

// The VariableIsEmpty(int,int,int) function is used to check whether the variables are having some value in them or not.

int VariableIsEmpty(int Type, int VariableStartID, int VariableEndID) {
    for (int i = VariableStartID; i <= VariableEndID; i++) {
        switch (Type) {
            case 1:
                if (DoubleVariable[i] == 0) {
                    return 1;
                }
                break;
            case 2:
                if (IntegerVariable[i] == 0) {
                    return 1;
                }
                break;
            case 3:
                if (CharacterVariable[i] == ' ') {
                    return 1;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}

// The EmptyVariable(int,int,int) function is used to make every variable have default null values.

void EmptyVariable(int Type, int VariableStartID, int VariableEndID) {
    for (int i = VariableStartID; i <= VariableEndID; i++) {
        switch (Type) {
            case 1:
                DoubleVariable[i] = 0;
                break;
            case 2:
                IntegerVariable[i] = 0;
                break;
            case 3:
                CharacterVariable[i] = ' ';
                break;
            default:
                break;
        }
    }
}

// The InitializeTheme() is used to initialize the theme variables.

void InitializeTheme() {
    switch (SettingsObject.SettingValue[12]) {
        case 1:
            LoadingSpirit = (char) (177);
            LoadingFrameTopBottomSpirit = (char) (196);
            LoadingFrameLeftRightSpirit = (char) (179);
            LoadingFrameEdgeTopRightSpirit = (char) (43);
            LoadingFrameEdgeTopLeftSpirit = (char) (43);
            LoadingFrameEdgeBottomRightSpirit = (char) (43);
            LoadingFrameEdgeBottomLeftSpirit = (char) (43);
            HeaderSeparatorSpirit = (char) (45);
            FrameHeaderSpiritMain = (char) (37);
            FrameHeaderEdgeLeftSpirit = (char) (92);
            FrameHeaderEdgeRightSpirit = (char) (47);
            FrameHeaderInnerMainSpirit = (char) (37);
            FrameHeaderMainTopBottomSpirit = (char) (37);
            FrameHeaderMainInnerSpirit = (char) (37);
            FrameHeaderMainLeftRightSpirit = (char) (37);
            FrameHeaderMainEdgesSpirit = (char) (37);
            FrameHeaderMainInnerCornerTopLeftSpirit = (char) (37);
            FrameHeaderMainInnerCornerTopRightSpirit = (char) (37);
            FrameHeaderMainInnerCornerBottomLeftSpirit = (char) (37);
            FrameHeaderMainInnerCornerBottomRightSpirit = (char) (37);
            CurrentAddressSeparatorSpirit = (char) (125);
            CurrentAddressSeparatorRepeatCount = 2;
            DialogBoxMainTopBottomSpirit = (char) (37);
            DialogBoxMainLeftRightSpirit = (char) (37);
            DialogBoxMainInnerSpirit = (char) (37);
            DialogBoxMainOutterSpirit = (char) (0);
            DialogBoxMainEdgeTopRightSpirit = (char) (92);
            DialogBoxMainEdgeTopLeftSpirit = (char) (47);
            DialogBoxMainEdgeBottomRightSpirit = (char) (47);
            DialogBoxMainEdgeBottomLeftSpirit = (char) (92);
            DialogBoxContentSeparatorSpirit = (char) (196);
            SettingsBoxTop = (char) (196);
            SettingsBoxBottom = (char) (196);
            SettingsBoxLeft = (char) (179);
            SettingsBoxRight = (char) (179);
            SettingsBoxSeparator = (char) (179);
            SettingsBoxTopRight = (char) (191);
            SettingsBoxTopLeft = (char) (218);
            SettingsBoxBottomLeft = (char) (192);
            SettingsBoxBottomRight = (char) (217);
            CurrencyOneToManyBoxTop = (char) (196);
            CurrencyOneToManyBoxBottom = (char) (196);
            CurrencyOneToManyBoxLeft = (char) (179);
            CurrencyOneToManyBoxRight = (char) (179);
            CurrencyOneToManyBoxSeparator = (char) (179);
            CurrencyOneToManyBoxTopRight = (char) (191);
            CurrencyOneToManyBoxTopLeft = (char) (218);
            CurrencyOneToManyBoxBottomLeft = (char) (192);
            CurrencyOneToManyBoxBottomRight = (char) (217);
            CalcBoxTop = (char) (196);
            CalcBoxBottom = (char) (196);
            CalcBoxLeft = (char) (179);
            CalcBoxRight = (char) (179);
            CalcBoxSeparator = (char) (179);
            CalcBoxTopRight = (char) (191);
            CalcBoxTopLeft = (char) (218);
            CalcBoxBottomLeft = (char) (192);
            CalcBoxBottomRight = (char) (217);
            ScrollUpSpirit = (char) (30);
            ScrollDownSpirit = (char) (31);
            ScrollLeftSpirit = (char) (17);
            ScrollRightSpirit = (char) (16);
            break;
        case 2:
            LoadingSpirit = (char) (254);
            LoadingFrameTopBottomSpirit = (char) (196);
            LoadingFrameLeftRightSpirit = (char) (58);
            LoadingFrameEdgeTopRightSpirit = (char) (191);
            LoadingFrameEdgeTopLeftSpirit = (char) (218);
            LoadingFrameEdgeBottomRightSpirit = (char) (217);
            LoadingFrameEdgeBottomLeftSpirit = (char) (192);
            HeaderSeparatorSpirit = (char) (58);
            FrameHeaderSpiritMain = (char) (254);
            FrameHeaderEdgeLeftSpirit = (char) (254);
            FrameHeaderEdgeRightSpirit = (char) (254);
            FrameHeaderInnerMainSpirit = (char) (254);
            FrameHeaderMainTopBottomSpirit = (char) (254);
            FrameHeaderMainInnerSpirit = (char) (254);
            FrameHeaderMainLeftRightSpirit = (char) (254);
            FrameHeaderMainEdgesSpirit = (char) (254);
            FrameHeaderMainInnerCornerTopLeftSpirit = (char) (254);
            FrameHeaderMainInnerCornerTopRightSpirit = (char) (254);
            FrameHeaderMainInnerCornerBottomLeftSpirit = (char) (254);
            FrameHeaderMainInnerCornerBottomRightSpirit = (char) (254);
            CurrentAddressSeparatorSpirit = (char) (175);
            CurrentAddressSeparatorRepeatCount = 1;
            DialogBoxMainTopBottomSpirit = (char) (254);
            DialogBoxMainLeftRightSpirit = (char) (254);
            DialogBoxMainInnerSpirit = (char) (254);
            DialogBoxMainOutterSpirit = (char) (0);
            DialogBoxMainEdgeTopRightSpirit = (char) (254);
            DialogBoxMainEdgeTopLeftSpirit = (char) (254);
            DialogBoxMainEdgeBottomRightSpirit = (char) (254);
            DialogBoxMainEdgeBottomLeftSpirit = (char) (254);
            DialogBoxContentSeparatorSpirit = (char) (196);
            SettingsBoxTop = (char) (196);
            SettingsBoxBottom = (char) (196);
            SettingsBoxLeft = (char) (179);
            SettingsBoxRight = (char) (179);
            SettingsBoxSeparator = (char) (196);
            SettingsBoxTopRight = (char) (196);
            SettingsBoxTopLeft = (char) (196);
            SettingsBoxBottomLeft = (char) (196);
            SettingsBoxBottomRight = (char) (196);
            CurrencyOneToManyBoxTop = (char) (196);
            CurrencyOneToManyBoxBottom = (char) (196);
            CurrencyOneToManyBoxLeft = (char) (179);
            CurrencyOneToManyBoxRight = (char) (179);
            CurrencyOneToManyBoxSeparator = (char) (196);
            CurrencyOneToManyBoxTopRight = (char) (196);
            CurrencyOneToManyBoxTopLeft = (char) (196);
            CurrencyOneToManyBoxBottomLeft = (char) (196);
            CurrencyOneToManyBoxBottomRight = (char) (196);
            CalcBoxTop = (char) (196);
            CalcBoxBottom = (char) (196);
            CalcBoxLeft = (char) (179);
            CalcBoxRight = (char) (179);
            CalcBoxSeparator = (char) (196);
            CalcBoxTopRight = (char) (196);
            CalcBoxTopLeft = (char) (196);
            CalcBoxBottomLeft = (char) (196);
            CalcBoxBottomRight = (char) (196);
            ScrollUpSpirit = (char) (30);
            ScrollDownSpirit = (char) (31);
            ScrollLeftSpirit = (char) (17);
            ScrollRightSpirit = (char) (16);
            break;
        default:
            break;
    }
}

// The CursorToggle(int) is used to hide or unhide the cursor. (Note: It implements the console handle concepts of C++.)

void CursorToggle(int VisibilityFlag) {
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    switch (VisibilityFlag) {
        case 1:
            ConCurInf.bVisible = TRUE;
            break;
        case 0:
            ConCurInf.bVisible = FALSE;
            break;
        default:
            break;
    }
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

// The SetConsoleDimensions(int,int) is used to set the dimensions of the console window.

void SetConsoleDimensions(int WindowWidth, int WindowHeight) {
    HWND Console = GetConsoleWindow();
    const HWND Desktop = GetDesktopWindow();
    RECT ConsoleRect, DesktopRect;
    GetWindowRect(Console, &ConsoleRect);
    GetWindowRect(Desktop, &DesktopRect);
    int ConsolePositionX = 0, ConsolePositionY = 0;
    int ScreenWidth = DesktopRect.right, ScreenHeight = DesktopRect.bottom;
    if (WindowWidth >= ScreenWidth || WindowHeight >= ScreenHeight) {
        WindowWidth = ScreenWidth - 20;
        WindowHeight = ScreenHeight - 20;
    }
    switch (SettingsObject.SettingValue[17]) {
        case 1:
            ConsolePositionX = (ScreenWidth - WindowWidth) / 2;
            ConsolePositionY = (ScreenHeight - WindowHeight) / 2;
            break;
        case 2:
            ConsolePositionX = 50;
            ConsolePositionY = 50;
            break;
        case 3:
            ConsolePositionX = ScreenWidth - WindowWidth + 50;
            ConsolePositionY = 50;
            break;
        case 4:
            ConsolePositionX = 50;
            ConsolePositionY = ScreenHeight - WindowHeight - 50;
            break;
        case 5:
            ConsolePositionX = ScreenWidth - WindowWidth + 50;
            ConsolePositionY = ScreenHeight - WindowHeight - 50;
            break;
        case 6:
            ConsolePositionX = ConsoleRect.left;
            ConsolePositionY = ConsoleRect.top;
            break;
        default:
            break;
    }
    MoveWindow(Console, ConsolePositionX, ConsolePositionY, WindowWidth, WindowHeight, TRUE);
}

// The SetCord(short,short) function is used to jump to defined coordinates in the console plane for output.

void SetCord(short x, short y) {
    COORD Coordinates = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coordinates);
}

// The function GetConsoleTextAttribute(HANDLE) is used to get the current attributes of the console.

WORD GetConsoleTextAttribute(HANDLE HandleConsole) {
    CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
    GetConsoleScreenBufferInfo(HandleConsole, &ConsoleInfo);
    return ConsoleInfo.wAttributes;
}

//// The function SetConsoleFont(int,int,const char*) is used to set the console font properties.
//
//void SetConsoleFont(int FontSizeX, int FontSizeY, int FontFamily){
//    HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_FONT_INFO ConsoleFont;
//    GetCurrentConsoleFont(ConsoleHandle, false, &ConsoleFont);
//    ConsoleFont.dwFontSize.X = FontSizeX;
//    ConsoleFont.dwFontSize.Y = FontSizeY;
//    ConsoleFont.nFont = FontFamily;
//    SetCurrentConsoleFont(ConsoleHandle, false, &ConsoleFont);
//}

// The WebLinkLaunch(char*) is used to execute a website link.

void WebLinkLaunch(char *Address) {
    ShellExecute(0, "open", Address, 0, 0, 1);
}

// The WebGetData(char*) is used to retrive data from a web url. [ Note: This function has a limit to read only 20KB data at a time. ][ Note:  ]

string WebGetData(const char *WebUrl) {
    HINTERNET WebConnect = InternetOpen("Default_User_Agent", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (!WebConnect) {
        InternetCloseHandle(WebConnect);
        return "{lhs: \"\",rhs: \"\",error: \"404\",icc: false}";
    }
    HINTERNET WebAddress = InternetOpenUrl(WebConnect, WebUrl, NULL, 0,
                                           INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_PRAGMA_NOCACHE |
                                           INTERNET_FLAG_RELOAD, 0);
    if (!WebAddress) {
        InternetCloseHandle(WebAddress);
        InternetCloseHandle(WebConnect);
        return "{lhs: \"\",rhs: \"\",error: \"500\",icc: false}";
    }
    char _DataRecieved[WebRecieveDataSize];
    DWORD NumberOfBytesRead = 0;
    while (InternetReadFile(WebAddress, _DataRecieved, WebRecieveDataSize, &NumberOfBytesRead) && (NumberOfBytesRead));
    InternetCloseHandle(WebAddress);
    InternetCloseHandle(WebConnect);
    string DataResponse = string(_DataRecieved);
    return DataResponse;
}

// The GetCurrentDate(int) is used to get the current date.  [1-Year,2-Month,3-Day]

int GetCurrentDate(int DateType) {
    time_t CurrentTime = time(0);
    struct tm CurrentTimeStruct;
    char CurrentTimeCharArray[80];
    CurrentTimeStruct = *localtime(&CurrentTime);
    switch (DateType) {
        case 1:
            strftime(CurrentTimeCharArray, sizeof(CurrentTimeCharArray), "%y", &CurrentTimeStruct);
            return atoi(CurrentTimeCharArray);
            break;
        case 2:
            strftime(CurrentTimeCharArray, sizeof(CurrentTimeCharArray), "%m", &CurrentTimeStruct);
            return atoi(CurrentTimeCharArray);
            break;
        case 3:
            strftime(CurrentTimeCharArray, sizeof(CurrentTimeCharArray), "%d", &CurrentTimeStruct);
            return atoi(CurrentTimeCharArray);
            break;
    }
}

// The CopyFileNew(char*,char*) is used to copy the contents of one file into the other.

void CopyFileNew(const char *FileToCopyFrom, const char *FileToCopyTo) {
    ifstream FileInput(FileToCopyFrom);
    ofstream FileOutput(FileToCopyTo);
    if (FileInput.is_open()) {
        string FileInputData;
        while (FileInput.good()) {
            getline(FileInput, FileInputData);
            FileOutput << FileInputData;
        }
    }
    else {
        cout << "Failed..";
    }
}

// The ClearFileContents(char*) is used to clear the contents of a file.

void ClearFileContents(const char *File) {
    fstream FileStream;
    FileStream.open(File);
    if (FileStream.is_open()) {
        FileStream.close();
        FileStream.open(File, fstream::out | fstream::trunc);
    }
    else {
        cout << "Failed..";
    }
    FileStream.close();
}

// The ColorOut(char,int) is used output a single colored character in the console.

void ColorOut(char Character, int ColorType) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);
    switch (ColorType) {
        case 1:
            SetConsoleTextAttribute(hConsole,
                                    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case 2:
            SetConsoleTextAttribute(hConsole,
                                    BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, 0);
            break;
        case 5:
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
            break;
    }
    cout << Character;
    SetConsoleTextAttribute(hConsole, saved_colors);
}

// The ColorOut(char*,int) is used to output a colored set of characters or array of characters to the console.

void ColorOut(char *Character, int ColorType) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);
    switch (ColorType) {
        case 1:
            SetConsoleTextAttribute(hConsole,
                                    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case 2:
            SetConsoleTextAttribute(hConsole,
                                    BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, 0);
            break;
        case 5:
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
            break;
    }
    cout << Character;
    SetConsoleTextAttribute(hConsole, saved_colors);
}

// The ColorOut(char*,int) is used to output a colored set of characters or array of characters to the console.

void ColorOut(string String, int ColorType) {
    HANDLE HandleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int SavedColors = GetConsoleTextAttribute(HandleConsole);
    switch (ColorType) {
        case 1:
            SetConsoleTextAttribute(HandleConsole,
                                    FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case 2:
            SetConsoleTextAttribute(HandleConsole,
                                    BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
            break;
        case 3:
            SetConsoleTextAttribute(HandleConsole, FOREGROUND_INTENSITY);
            break;
        case 4:
            SetConsoleTextAttribute(HandleConsole, 0);
            break;
        case 5:
            SetConsoleTextAttribute(HandleConsole, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
            break;
    }
    cout << String;
    SetConsoleTextAttribute(HandleConsole, SavedColors);
}

// The PauseConsole(float) is used to pause the console for some defined amount of time.

void PauseConsole(float PauseTime) {
    Sleep((DWORD) PauseTime);
}

// The Music(char,int) is used to play a desired note of sound (by the use Beep(int,int) function) for desired amount of time.

void Music(int MusicNote, int Time) {
    switch (MusicNote) {
        break;
        case 1:
            Beep(200, Time);
            break;
        case 2:
            Beep(150, Time);
            break;
        case 3:
            Beep(100, Time);
            break;
        case 4:
            Beep(225, Time);
            break;
        case 5:
            Beep(250, Time);
            break;
        case 6:
            Beep(175, Time);
            break;
        default:
            Beep(MusicNote, Time);
    }
}

// The KeypressSound() is used to play a sound on press of a button defined by a unique ID.

void KeypressSound() {
    if ((MusicID == 0) && (KeypressSoundID != 0)) {
        switch (KeypressSoundID) {
            case 1:
                Music(1, 200);
                break;
            case 2:
                Music(2, 200);
                break;
            case 3:
                Music(3, 200);
                break;
            case 4:
                Music(4, 200);
                break;
            case 5:
                Music(5, 200);
                break;
            case 6:
                Music(6, 200);
                break;
        }
    }
}

// The BackgroundMusic(void*) is used to play music at the time of intro. This function implements the use of Multi-Threading.

void BackgroundMusic(void *Temp) {
    while ((BackgroundMusicFlag) && (BackgroundMusicID)) {
        switch (BackgroundMusicID) {
            case 1:
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 480, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1568, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1568, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1568, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 369.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 369.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 83.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 830.61, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 987.77, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 830.61, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 987.77, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1108, 10);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1174.7, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1480, 10);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1568, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 830.61, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 987.77, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 784, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 784, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587.33, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 784, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587.33, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587.33, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587.33, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493.88, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349.23, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493.88, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 466.16, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493.88, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493.88, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1760, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493.88, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1568, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349.23, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 415.2, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1396.92, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349.23, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 311.13, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 400);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493.88, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493.88, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1760, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493.88, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 1568, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349.23, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 00);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659.25, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698.46, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 739.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783.99, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 185, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 185, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 207.65, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 233.08, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 246.94, 200);
                break;
            case 2:
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293.66, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293.66, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 207.65, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293.66, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174.61, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174.61, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174.61, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174.61, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 207.65, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293.66, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293.66, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 207.65, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293.66, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174.61, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174.61, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 220.00, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174.61, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174.61, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261.63, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 207.65, 250);
                break;
            case 3:
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 784, 800);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 784, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 876, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 876, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 876, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 876, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 784, 800);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 876, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 876, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 876, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 876, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 784, 800);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 700);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 250);
                break;
            case 4:
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329, 100);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 200);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 500);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329, 100);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 493, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 150);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349, 250);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 400);
                break;
            case 5:
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 329, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(300 * 2);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 622, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 440, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 659, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 880, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 783, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 698, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 587, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 523, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                break;
            case 6:
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 130, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 146, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 164, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 146, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 130, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 146, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 164, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 392, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 349, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293, 300);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Sleep(600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 174, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 293, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 261, 600);
                if ((BackgroundMusicFlag) && (BackgroundMusicID))Beep((DWORD) 196, 600);
                break;
        }
    }
    BackgroundMusicEndFlag = 1;
    _endthread();
}

// The IntroMisc(void*) is used to flash 'PRESS ENTER TO CONTINUE' on the intro screen. This function implements the use of Multi-Threading.

void IntroMisc(void *Temp) {
    SetCord(26, 21);
    ColorOut("  TAP ENTER TO CONTINUE....  ", 1);
    while (!IntroEndFlag) {
        if (IntroMusicID) {
            PauseConsole(FPS * 100);
            SetCord(26, 21);
            ColorOut("  TAP ENTER TO CONTINUE....  ", 0);
            PauseConsole(FPS * 100);
            PauseConsole(FPS * 100);
            PauseConsole(FPS * 100);
            PauseConsole(FPS * 100);
            PauseConsole(FPS * 100);
            PauseConsole(FPS * 100);
            SetCord(26, 21);
            ColorOut("  TAP ENTER TO CONTINUE....  ", 1);
            continue;
        }
        for (int x = 0; x <= 8; x++) {
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 80; j++) {
                    SetCord(j, i + 1);
                    if (j >= (0 + (x * 10)) && j <= (10 + (x * 10))) {
                        if (IntroFrames[i][j] == '%') ColorOut('#', 0);
                        else ColorOut(IntroFrames[i][j], 1);
                    }
                    else {
                        if (IntroFrames[i][j] == '%') ColorOut('#', 3);
                        else ColorOut(IntroFrames[i][j], 0);
                    }
                }
            }
        }
    }
    IntroEndFlag = 2;
    _endthread();
}

// The SettingsUpdateOnTerminate(void*) is used to update the settings on the termination of the program. This function implements the use of Multi-Threading.

void SettingsUpdateOnTerminate(void *Temp) {
    SettingsObject.SettingsUpdate(0, (++SettingsObject.SettingValue[0]));
    _endthread();
}

// The Terminate(int) is used to generate the terminating dialog.

void Terminate(int Flag) {
    int ButtonsFunction[5] = {Exit_Program_Dialog_Yes_Button, Exit_Program_Dialog_No_Button, 0, 0, 0};
    srand(time(
            0));                                                                                 // Initializing random seed.
    int RepeatHeaderMisc = rand() % 5 + 1;
    switch (Flag) {
        case 1:
            CreateDialogBox("Exit Program!", Strings[0], 50, 12, 1, ButtonsFunction);
            break;
        case 2:
            CreateDialogBox("Program Terminating.", Strings[1], 60, 12, 2, ButtonsFunction);
            _beginthread(SettingsUpdateOnTerminate, 0,
                         (void *) &Temp);                             // Applying multi-threading concept to thread multiple processes at once.
            BackgroundMusicFlag = 0;
            BackgroundMusicID = 0;
            HeaderMisc(600, RepeatHeaderMisc);
            exit(0);
            break;
        case 3:
            CreateDialogBox("Program Terminating.", Strings[133], 60, 14, 4, ButtonsFunction, 0, 1);
            BackgroundMusicFlag = 0;
            BackgroundMusicID = 0;
            HeaderMisc(600, RepeatHeaderMisc);
            exit(0);
            break;
    }
}

// The StringLength(char*) is used to get the length of complete array of characters (char).

int StringLength(char *String) {
    int StringLength;
    for (StringLength = 0; String[StringLength] != '\0'; ++StringLength);
    return StringLength;
}

// The StringLength(string) is used to get the length of a string stored in string variable.

int StringLength(string String) {
    int StringLength;
    for (StringLength = 0; String[StringLength] != '\0'; ++StringLength);
    return StringLength;
}

// The StringDigitValidation(string) is used to validate a string to see if it contains correct set of digits which qualifies for float type number.

int StringDigitValidation(string TempString) {
    int DecimalPointCount = 0;
    for (int i = 0; i < StringLength(TempString); i++) {
        if (TempString[i] == '.') DecimalPointCount++;
        if (DecimalPointCount > 1) return 0;
        else {
            if (!isdigit(TempString[i]) && TempString[i] != '.') return 0;
        }
    }
    return 1;
}

// The StringInterpret(string&) is used to interpret string variables.

void StringInterpret(string &String, int InterpretType, string StringReplaceDefault) {
    size_t StartPosition = 0;
    while ((StartPosition = String.find('`', StartPosition)) != string::npos) {
        int InterpretDelimiterFlag = 0;
        int TempPosition = StartPosition + 1;
        while (TempPosition != string::npos) {
            if (!(StringDigitValidation(String.substr(TempPosition, 1)))) {
                if (String[TempPosition] == '`') {
                    InterpretDelimiterFlag = 1;
                    break;
                }
            }
            TempPosition++;
        }
        if (InterpretDelimiterFlag) {
            if ((TempPosition == (StartPosition + 1)) && (InterpretType == 2)) {
                String.replace(StartPosition, 2, StringReplaceDefault);
                StartPosition += StringReplaceDefault.length();
            }
            else if (InterpretType == 1) {
                string TempString = String.substr(StartPosition + 1, TempPosition - StartPosition);
                TempString = (char) (atoi(TempString.c_str()));
                String.replace(StartPosition, (TempPosition - StartPosition + 1), TempString);
                StartPosition += TempString.length();
            }
        }
        else StartPosition++;
    }
}

// The Header() is used to generate the Header of the program.

void Header() {
    CursorToggle(0);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 80; j++) {
            SetCord(j, i);
            if (i == 0 || i == 6) cout << HeaderSeparatorSpirit;
            else {
                if (HeaderFrames[i - 1][j] == '%') ColorOut('#', 3);
                else ColorOut(HeaderFrames[i - 1][j], 0);
            }
        }
    }
}

// The HeaderMisc(int,int) is used to generate the animation of the Header of the program.

void HeaderMisc(int DelayTime, int RepeatCounter) {
    CursorToggle(0);
    while (RepeatCounter) {
        PauseConsole(DelayTime);
        for (int x = 0; x <= 8; x++) {
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 80; j++) {
                    SetCord(j, i);
                    if (j >= (0 + (x * 10)) && j <= (10 + (x * 10))) {
                        if (i == 0 || i == 6) ColorOut(HeaderSeparatorSpirit, 1);
                        else {
                            if (HeaderFrames[i - 1][j] == '%') ColorOut('#', 0);
                            else ColorOut(HeaderFrames[i - 1][j], 1);
                        }
                    }
                    else {
                        if (i == 0 || i == 6) cout << HeaderSeparatorSpirit;
                        else {
                            if (HeaderFrames[i - 1][j] == '%') ColorOut('#', 3);
                            else ColorOut(HeaderFrames[i - 1][j], 0);
                        }
                    }
                }
            }
        }
        RepeatCounter--;
    }
    CursorToggle(1);
}

// The ClearConsole(int) is used to clear the contents of the console after a delay.(Note: The Header() is called and therefore only the contents other than header gets deleted.)

void ClearConsole(int DelayTime) {
    cin.clear();
    PauseConsole(DelayTime);
    HeaderMisc(DelayTime, 1);
    system("cls");
    Header();
}

// The ClearFrame(short,short,int,int) is used to clear just a frame of the output screen.

void ClearFrame(short StartX, short StartY, int Width, int Height) {
    CursorToggle(0);
    for (int i = 0; i <= Height; ++i) {
        for (int j = 0; j <= Width; ++j) {
            SetCord(StartX + j, StartY + i);
            cout << " ";
        }
    }
    SetCord(StartX, StartY);
}

// The ButtonFunctions(int) is used call the set instructions according to the ID of the instructions passed to it. It stores the instructions for the buttons.

void ButtonFunctions(int FunctionID) {
    ostringstream CalcStringStream;
    int Restart_The_Updation_DialogButtonFunctions[5] = {Restart_The_Updation_Dialog_Yes_B_F, Back_B_F, 0, 0, 0};
    int OriginalCalcStringLength = StringLength(CalcStringGet);
    input Calc_Function_5_6_7_8_Input1 = {IntegerType, 0, 9, 46, 0, 2, 20, 52, 2, 0, "Dummy"};
    input Calc_Function_5_6_7_8_Input2 = {IntegerType, 1, 9, 47, 0, 2, 20, 52, 2, 0, "Dummy"};
    input Calc_Function_19_20_Input1 = {IntegerType, 0, 9, 46, 0, 2, 20, 52, 2, 0, "Dummy"};
    input Calc_Function_19_20_Input2 = {IntegerType, 1, 9, 53, 0, 2, 20, 52, 2, 0, "Dummy"};
    switch (FunctionID) {
        case Main_Menu_B_F:
            ClearConsole(0);
            Menu(Main_Menu_M);
            break;
            // First Time Yes Function.
        case First_Time_Yes_Button:
            ClearConsole(0);
            FirstTimeIntro(2);
            break;
            // First Time No Function.
        case First_Time_No_Button:
            ClearConsole(0);
            Menu(Main_Menu_M);
            break;

            // Exit Program Dialog Yes Function.
        case Exit_Program_Dialog_Yes_Button:
            Terminate(2);
            break;
            // Exit Program Dialog No Function.
        case Exit_Program_Dialog_No_Button:
            ClearConsole(0);
            Menu(CurrentMenuID);
            break;
            // Too Many Errors Got It Function.
        case Too_Many_Errors_Dialog_Got_It_Button:
            ClearConsole(0);
            Menu(CurrentMenuID);
            break;
            // Too Many Errors Need More Advice Function.
        case Too_Many_Errors_Dialog_Need_More_Advice_Button:
            ClearConsole(0);
            Menu(PreviousMenuID);
            break;
        case About_Jump_B_F:
            ClearConsole(0);
            Menu(AboutJumpID);
            break;

            // Geometrical Calculations
        case Geometrical_Calculations_B_F:
            ClearConsole(0);
            Menu(Geometrical_Calculations_M);
            break;
        case Triangles_B_F:
            ClearConsole(0);
            Menu(Triangles_M);
            break;
        case About_Triangles_B_F:
            ClearConsole(0);
            Menu(About_Triangles_M);
            break;
        case About_Information_B_F:
            ClearConsole(0);
            About(AboutCurrentPageTitle, AboutCurrentStartYCordinate, 1, AboutCurrentCurrentAddressText);
            break;
        case About_Properties_B_F:
            ClearConsole(0);
            About(AboutCurrentPageTitle, AboutCurrentStartYCordinate, 2, AboutCurrentCurrentAddressText);
            break;
        case About_Formulas_B_F:
            ClearConsole(0);
            About(AboutCurrentPageTitle, AboutCurrentStartYCordinate, 3, AboutCurrentCurrentAddressText);
            break;
        case About_More_B_F:
            ClearConsole(0);
            About(AboutCurrentPageTitle, AboutCurrentStartYCordinate, 4, AboutCurrentCurrentAddressText);
            break;
        case Area_of_Triangles_B_F:
            ClearConsole(0);
            Menu(Area_of_Triangles_M);
            break;
        case For_Scalene_Triangle_B_F:
            ClearConsole(0);
            Menu(For_Scalene_Triangle_M);
            break;
        case For_Equilateral_Triangle_B_F:
            ClearConsole(0);
            Menu(For_Equilateral_Triangle_M);
            break;
        case For_Isosceles_Triangle_B_F:
            ClearConsole(0);
            Menu(For_Isosceles_Triangle_M);
            break;
        case Perimeter_of_Triangles_B_F:
            ClearConsole(0);
            Menu(Perimeter_of_Triangles_M);
            break;
        case For_Scalene_Triangle_Perimeter_B_F:
            ClearConsole(0);
            Menu(For_Scalene_Triangle_Perimeter_M);
            break;
        case For_Equilateral_Triangle_Perimeter_B_F:
            ClearConsole(0);
            Menu(For_Equilateral_Triangle_Perimeter_M);
            break;
        case For_Isosceles_Triangle_Perimeter_B_F:
            ClearConsole(0);
            Menu(For_Isosceles_Triangle_Perimeter_M);
            break;
        case Quadrilateral_B_F:
            ClearConsole(0);
            Menu(Quadrilateral_M);
            break;
        case Area_of_Quadrilateral_B_F:
            ClearConsole(0);
            Menu(Area_of_Quadrilateral_M);
            break;
        case Area_of_Quadrilateral_Formula_1_B_F:
            ClearConsole(0);
            Menu(Area_of_Quadrilateral_Formula_1_M);
            break;
        case Area_of_Quadrilateral_Formula_2_B_F:
            ClearConsole(0);
            Menu(Area_of_Quadrilateral_Formula_2_M);
            break;
        case Area_of_Quadrilateral_Formula_3_B_F:
            ClearConsole(0);
            Menu(Area_of_Quadrilateral_Formula_3_M);
            break;
        case Area_of_Quadrilateral_Formula_4_B_F:
            ClearConsole(0);
            Menu(Area_of_Quadrilateral_Formula_4_M);
            break;
        case Perimeter_of_Quadrilateral_B_F:
            ClearConsole(0);
            Menu(Perimeter_of_Quadrilateral_M);
            break;
        case About_Quadrilateral_B_F:
            ClearConsole(0);
            Menu(About_Quadrilateral_M);
            break;
        case Pentagon_B_F:
            ClearConsole(0);
            Menu(Pentagon_M);
            break;
        case About_Pentagon_B_F:
            ClearConsole(0);
            Menu(About_Pentagon_M);
            break;
        case Area_of_Pentagon_B_F:
            ClearConsole(0);
            Menu(Area_of_Pentagon_M);
            break;
        case Perimeter_of_Pentagon_B_F:
            ClearConsole(0);
            Menu(Perimeter_of_Pentagon_M);
            break;
        case Hexagon_B_F:
            ClearConsole(0);
            Menu(Hexagon_M);
            break;
        case About_Hexagon_B_F:
            ClearConsole(0);
            Menu(About_Hexagon_M);
            break;
        case Area_of_Hexagon_B_F:
            ClearConsole(0);
            Menu(Area_of_Hexagon_M);
            break;
        case Area_of_Hexagon_Formula_1_B_F:
            ClearConsole(0);
            Menu(Area_of_Hexagon_Formula_1_M);
            break;
        case Area_of_Hexagon_Formula_2_B_F:
            ClearConsole(0);
            Menu(Area_of_Hexagon_Formula_2_M);
            break;
        case Area_of_Hexagon_Formula_3_B_F:
            ClearConsole(0);
            Menu(Area_of_Hexagon_Formula_3_M);
            break;
        case Area_of_Hexagon_Formula_4_B_F:
            ClearConsole(0);
            Menu(Area_of_Hexagon_Formula_4_M);
            break;
        case Perimeter_of_Hexagon_B_F:
            ClearConsole(0);
            Menu(Perimeter_of_Hexagon_M);
            break;

            // Calc
        case Calc_B_F:
            ClearConsole(0);
            Menu(Calc_M);
            break;

            // Equation Solving
        case Equation_Solving_B_F:
            ClearConsole(0);
            Menu(Equation_Solving_M);
            break;
        case Linear_Equation_B_F:
            ClearConsole(0);
            Menu(Linear_Equation_M);
            break;
        case Solve_Linear_Equation_Two_Variable_B_F:
            ClearConsole(0);
            Menu(Solve_Linear_Equation_Two_Variable_M);
            break;
        case Solve_System_Of_Linear_Equation_B_F:
            ClearConsole(0);
            Menu(Solve_System_Of_Linear_Equation_M);
            break;
        case About_Linear_Equation_B_F:
            ClearConsole(0);
            Menu(About_Linear_Equation_M);
            break;
        case Quadratic_Equation_B_F:
            ClearConsole(0);
            Menu(Quadratic_Equation_M);
            break;
        case About_Quadratic_Equation_B_F:
            ClearConsole(0);
            Menu(About_Quadratic_Equation_M);
            break;
        case Solve_Quadratic_Equation_B_F:
            ClearConsole(0);
            Menu(Solve_Quadratic_Equation_M);
            break;

            // Conversions
        case Conversions_B_F:
            ClearConsole(0);
            Menu(Conversions_M);
            break;
        case Currency_B_F:
            ClearConsole(0);
            Menu(Currency_Select_M);
            break;
        case Currency_One_To_One_Conversion_B_F:
            ClearConsole(0);
            Menu(Currency_One_To_One_Conversion_M);
            break;
        case Currency_One_To_Many_Conversion_B_F:
            ClearConsole(0);
            Menu(Currency_One_To_Many_Conversion_M);
            break;
        case Update_Currency_Exchange_Rates_B_F:
            ClearConsole(0);
            Menu(Update_Currency_Exchange_Rates_M);
            break;
        case Continue_From_Last_Point_B_F:
            ClearConsole(0);
            Menu(Update_Currency_Exchange_Rates_START_M);
            break;
        case Update_Currency_Rates_Stop_Yes:
            ClearConsole(0);
            UpdateCurrencyRatesTerminateFlag = 0;
            Menu(PreviousMenuID);
            break;
        case Update_Currency_Rates_Stop_No:
            ClearConsole(0);
            UpdateCurrencyRatesTerminateFlag = 0;
            Menu(Update_Currency_Exchange_Rates_START_M);
            break;
        case Update_Currency_Rates_Completed_Yes:
            UpdateCurrencyRatesTerminateFlag = 0;
            ButtonFunctions(Restart_The_Updation_B_F);
            break;
        case Update_Currency_Rates_Completed_No:
            ClearConsole(0);
            UpdateCurrencyRatesTerminateFlag = 2;
            Menu(PreviousMenuID);
            break;
        case Update_Currency_Rates_Completed_Now_Yes:
            ClearConsole(0);
            Menu(Conversions_M);
            break;
        case Update_Currency_Rates_Completed_Now_No:
            ClearConsole(0);
            Menu(Update_Currency_Exchange_Rates_M);
            break;
        case Update_Currency_Rates_Reminder_Yes:
            SettingsObject.SettingsUpdate(2, 0);
            SettingsObject.SettingsUpdate(3, 0);
            SettingsObject.SettingsUpdate(4, 0);
            SettingsObject.SettingsUpdate(5, 0);
            SettingsObject.SettingsUpdate(6, 0);
            SettingsObject.SettingsUpdate(7, 0);
            SettingsObject.SettingsUpdate(8, 0);
            ClearFileContents(CurrencyRateDataTempFilePath);
            ClearConsole(0);
            Menu(Update_Currency_Exchange_Rates_START_M);
            break;
        case Update_Currency_Rates_Reminder_No:
            ClearConsole(0);
            Menu(Update_Currency_Exchange_Rates_M);
            break;
        case View_Update_History_B_F:
            ClearConsole(0);
            Menu(View_Update_History_M);
            break;
        case Restart_The_Updation_B_F:
            PreviousMenuID = Update_Currency_Exchange_Rates_M;
            CreateDialogBox("Restart Updation!", Strings[22], 65, 14, 1, Restart_The_Updation_DialogButtonFunctions, 0,
                            1);
            break;
        case Restart_The_Updation_Dialog_Yes_B_F:
            SettingsObject.SettingsUpdate(2, 0);
            SettingsObject.SettingsUpdate(3, 0);
            SettingsObject.SettingsUpdate(4, 0);
            SettingsObject.SettingsUpdate(5, 0);
            SettingsObject.SettingsUpdate(6, 0);
            SettingsObject.SettingsUpdate(7, 0);
            SettingsObject.SettingsUpdate(8, 0);
            ClearFileContents(CurrencyRateDataTempFilePath);
            UpdateCurrencyRatesTerminateFlag = 0;
            ClearConsole(0);
            Menu(Update_Currency_Exchange_Rates_START_M);
            break;
        case Units_B_F:
            ClearConsole(0);
            Menu(Units_M);
            break;
        case Temperature_B_F:
            ClearConsole(0);
            Menu(Temperature_M);
            break;
        case Length_B_F:
            ClearConsole(0);
            Menu(Length_M);
            break;
        case Mass_B_F:
            ClearConsole(0);
            Menu(Mass_M);
            break;
        case Speed_B_F:
            ClearConsole(0);
            Menu(Speed_M);
            break;
        case Volume_B_F:
            ClearConsole(0);
            Menu(Volume_M);
            break;
        case Area_B_F:
            ClearConsole(0);
            Menu(Area_M);
            break;
        case Time_B_F:
            ClearConsole(0);
            Menu(Time_M);
            break;
        case Data_Storage_B_F:
            ClearConsole(0);
            Menu(Data_Storage_M);
            break;
        case Pressure_B_F:
            ClearConsole(0);
            Menu(Pressure_M);
            break;
        case Power_B_F:
            ClearConsole(0);
            Menu(Power_M);
            break;
        case Angle_B_F:
            ClearConsole(0);
            Menu(Angle_M);
            break;
        case Acceleration_B_F:
            ClearConsole(0);
            Menu(Acceleration_M);
            break;
        case Density_B_F:
            ClearConsole(0);
            Menu(Density_M);
            break;
        case Energy_B_F:
            ClearConsole(0);
            Menu(Energy_M);
            break;
        case Force_B_F:
            ClearConsole(0);
            Menu(Force_M);
            break;
        case Torque_B_F:
            ClearConsole(0);
            Menu(Torque_M);
            break;


            // Settings
        case Settings_B_F:
            ClearConsole(0);
            Menu(Settings_M);
            break;
        case Update_Settings_B_F:
            ClearConsole(0);
            Menu(Update_Settings_M);
            break;
        case Reset_Settings_B_F:
            ClearConsole(0);
            Menu(Reset_Settings_M);
            break;
        case Reset_Settings_Yes_B_F:
            SettingsObject.DefaultSettings();
            Terminate(3);
            break;

            // Misc Functions.
        case Re_Calculate_B_F:
            ClearConsole(0);
            Menu(PreviousCalculationID);
            break;
        case Exit_B_F:
            Terminate(1);
            break;
        case Back_B_F:
            if ((PreviousMenuID == 1) && (CurrentMenuID == 1)) {
                ButtonFunctions(Exit_B_F);
            }
            else {
                ClearConsole(0);
                Menu(PreviousMenuID);
            }
            break;
        case Play_Intro_B_F:
            ClearConsole(0);
            FirstTimeIntro(2);
            break;

            // Calc Functions
        case Calc_Function_1:
            CalcStringGet += 'P';
            CalcCharCount++;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_2:
            CalcStringGet += 'E';
            CalcCharCount++;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_3:
            CalcStringGet += "1.0/";
            CalcCharCount += 4;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_4:
            CalcStringGet += 'e';
            CalcCharCount++;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_5:
            PreviousMenuID = Calc_M;
            StringOut(48, 2, 19, 52, 0);
            InputDataVariable(1, Calc_Function_5_6_7_8_Input1);
            InputDataVariable(1, Calc_Function_5_6_7_8_Input2);
            ClearFrame(2, 19, 52, 3);
            CalcStringStream << "pow[" << IntegerVariable[1] << ",[1/" << IntegerVariable[0] << "]]";
            CalcStringGet += CalcStringStream.str();
            CalcCharCount += StringLength(CalcStringGet) - OriginalCalcStringLength;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_6:
            PreviousMenuID = Calc_M;
            StringOut(49, 2, 19, 52, 0);
            InputDataVariable(1, Calc_Function_5_6_7_8_Input2);
            InputDataVariable(1, Calc_Function_5_6_7_8_Input1);
            ClearFrame(2, 19, 52, 3);
            CalcStringStream << "pow[" << IntegerVariable[1] << "," << IntegerVariable[0] << "]";
            CalcStringGet += CalcStringStream.str();
            CalcCharCount += StringLength(CalcStringGet) - OriginalCalcStringLength;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_7:
            PreviousMenuID = Calc_M;
            StringOut(50, 2, 19, 52, 0);
            InputDataVariable(1, Calc_Function_5_6_7_8_Input1);
            ClearFrame(2, 19, 52, 3);
            CalcStringStream << "pow[e," << IntegerVariable[0] << "]";
            CalcStringGet += CalcStringStream.str();
            CalcCharCount += StringLength(CalcStringGet) - OriginalCalcStringLength;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_8:
        Calc_Function_8_On_Error_Flag:
            PreviousMenuID = Calc_M;
            StringOut(51, 2, 19, 52, 0);
            InputDataVariable(1, Calc_Function_5_6_7_8_Input2);
            InputDataVariable(1, Calc_Function_5_6_7_8_Input1);
            if (IntegerVariable[0] == 1) {
                StringOut(52, 2, 21, 52, 0);
                PauseConsole(1000);
                goto Calc_Function_8_On_Error_Flag;
            }
            ClearFrame(2, 19, 52, 3);
            CalcStringStream << "log[" << IntegerVariable[1] << "," << IntegerVariable[0] << "]";
            CalcStringGet += CalcStringStream.str();
            CalcCharCount += StringLength(CalcStringGet) - OriginalCalcStringLength;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_9:
            CalcStringGet += "ln[";
            CalcCharCount += 3;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_10:
            CalcStringGet += "sin[";
            CalcCharCount += 4;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_11:
            CalcStringGet += "cos[";
            CalcCharCount += 4;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_12:
            CalcStringGet += "tan[";
            CalcCharCount += 4;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_13:
            CalcStringGet += "asin[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_14:
            CalcStringGet += "acos[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_15:
            CalcStringGet += "atan[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_16:
            CalcStringGet += "cot[";
            CalcCharCount += 4;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_17:
            CalcStringGet += "sec[";
            CalcCharCount += 4;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_18:
            CalcStringGet += "csc[";
            CalcCharCount += 4;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_19:
        Calc_Function_19_On_Error_Flag:
            PreviousMenuID = Calc_M;
            StringOut(54, 2, 19, 52, 0);
            InputDataVariable(1, Calc_Function_19_20_Input1);
            InputDataVariable(1, Calc_Function_19_20_Input2);
            if (IntegerVariable[1] > IntegerVariable[0]) {
                StringOut(55, 2, 21, 52, 0);
                PauseConsole(1000);
                goto Calc_Function_19_On_Error_Flag;
            }
            ClearFrame(2, 19, 52, 3);
            CalcStringStream << "nCr[" << IntegerVariable[0] << "," << IntegerVariable[1] << "]";
            CalcStringGet += CalcStringStream.str();
            CalcCharCount += StringLength(CalcStringGet) - OriginalCalcStringLength;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_20:
        Calc_Function_20_On_Error_Flag:
            PreviousMenuID = Calc_M;
            StringOut(56, 2, 19, 52, 0);
            InputDataVariable(1, Calc_Function_19_20_Input1);
            InputDataVariable(1, Calc_Function_19_20_Input2);
            if (IntegerVariable[1] > IntegerVariable[0]) {
                StringOut(55, 2, 21, 52, 0);
                PauseConsole(1000);
                goto Calc_Function_20_On_Error_Flag;
            }
            ClearFrame(2, 19, 52, 3);
            CalcStringStream << "nPr[" << IntegerVariable[0] << "," << IntegerVariable[1] << "]";
            CalcStringGet += CalcStringStream.str();
            CalcCharCount += StringLength(CalcStringGet) - OriginalCalcStringLength;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_21:
            CalcStringGet += "fact[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_22:
            CalcStringGet += "acot[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_23:
            CalcStringGet += "asec[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_24:
            CalcStringGet += "acsc[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_25:
            CalcStringGet += "sinh[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_26:
            CalcStringGet += "cosh[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_27:
            CalcStringGet += "tanh[";
            CalcCharCount += 5;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_28:
            CalcStringGet += "asinh[";
            CalcCharCount += 6;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_29:
            CalcStringGet += "acosh[";
            CalcCharCount += 6;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_30:
            CalcStringGet += "atanh[";
            CalcCharCount += 6;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_31:
            CalcStringGet += "acsch[";
            CalcCharCount += 6;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_32:
            CalcStringGet += "asech[";
            CalcCharCount += 6;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;
        case Calc_Function_33:
            CalcStringGet += "acoth[";
            CalcCharCount += 6;
            if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                CalcLineCount++;
                SetCord(2, 10 + CalcLineCount);
            }
            Calc();
            break;

            // Demo
        case FirstTimeIntroDemoButton:
            FirstTimeIntro(3);
            break;
        case FirstTimeIntroDemoButton2:
            FirstTimeIntro(4);
            break;
        case FirstTimeIntroDemoButtonRedoYes:
            FirstTimeIntro(4);
            break;
        case FirstTimeIntroDemoButtonRedoNo:
            FirstTimeIntro(5);
            break;

            // On Error
        case ErrorDownloadYes:
            WebLinkLaunch("http://www.mingw.org/");
            Terminate(2);
            break;

        default:
            ClearConsole(0);
            Menu(PreviousMenuID);
            break;
    }
}

// The CreateButtons(button[][5],int,int[2]) is used to generate the buttons framework.

int CreateButtons(button Button[][ButtonsColumnLimit], int NumberOfRows, int DefaultButton[2], int FunctionType = 1) {
    CursorToggle(0);
    int Count = 0;
    int NumberOfColumns = 0;
    for (int i = 0; i < NumberOfRows; i++) {
        int TempNumberOfColumns = 0;
        for (int j = 0; j < ButtonsColumnLimit; j++) {
            if (Button[i][j].Status == 1) TempNumberOfColumns++;
        }
        if (TempNumberOfColumns >= NumberOfColumns) NumberOfColumns = TempNumberOfColumns;
    }
    int CurrentButton[2] = {DefaultButton[0], DefaultButton[1]};
    int PreviousButton[2] = {DefaultButton[0], DefaultButton[1]};
    DWORD ConsoleMode;
    INPUT_RECORD InputEvent;
    BOOL Flag = TRUE;
    HANDLE StandardInputHandle = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(StandardInputHandle, &ConsoleMode);
    SetConsoleMode(StandardInputHandle, 0);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));                 // To flush the non-required previous data.
    while (Flag) {
        if ((WaitForSingleObject(StandardInputHandle, 0) == WAIT_OBJECT_0) && (Count != 0)) {
            DWORD ConsoleInputCount;
            ReadConsoleInput(StandardInputHandle, &InputEvent, 1, &ConsoleInputCount);
            if ((InputEvent.EventType == KEY_EVENT) && (InputEvent.Event.KeyEvent.bKeyDown)) {
                switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                    case VK_RIGHT:
                        if (CurrentButton[1] < (NumberOfColumns - 1)) {
                            if (Button[CurrentButton[0]][(CurrentButton[1] + 1)].Status) CurrentButton[1]++;
                        }
                        else if (CurrentButton[1] == (NumberOfColumns - 1)) {
                            if (Button[CurrentButton[0]][0].Status) CurrentButton[1] = 0;
                        }
                        break;
                    case VK_LEFT:
                        if (CurrentButton[1] <= (NumberOfColumns - 1) && CurrentButton[1] != 0) {
                            if (Button[CurrentButton[0]][(CurrentButton[1] - 1)].Status) CurrentButton[1]--;
                        }
                        else if (CurrentButton[1] == 0) {
                            if (Button[CurrentButton[0]][(NumberOfColumns - 1)].Status)
                                CurrentButton[1] = NumberOfColumns - 1;
                        }
                        break;
                    case VK_UP:
                        if (CurrentButton[0] <= (NumberOfRows - 1) && CurrentButton[0] > 0) {
                            if (Button[(CurrentButton[0] - 1)][CurrentButton[1]].Status) CurrentButton[0]--;
                        }
                        else if (CurrentButton[0] == 0) {
                            if (Button[(NumberOfRows - 1)][CurrentButton[1]].Status)
                                CurrentButton[0] = NumberOfRows - 1;
                        }
                        break;
                    case VK_DOWN:
                        if (CurrentButton[0] < (NumberOfRows - 1)) {
                            if (Button[(CurrentButton[0] + 1)][CurrentButton[1]].Status) CurrentButton[0]++;
                        }
                        else if (CurrentButton[0] == (NumberOfRows - 1)) {
                            if (Button[0][CurrentButton[1]].Status) CurrentButton[0] = 0;
                        }
                        break;
                    case VK_RETURN:
                        switch (FunctionType) {
                            case 1:
                            case 3:
                                Flag = FALSE;
                                KeypressSound();
                                SetConsoleMode(StandardInputHandle, ConsoleMode);
                                ButtonFunctions(Button[CurrentButton[0]][CurrentButton[1]].FunctionCallID);
                                break;
                            case 2:
                                Flag = FALSE;
                                KeypressSound();
                                SetConsoleMode(StandardInputHandle, ConsoleMode);
                                return Button[CurrentButton[0]][CurrentButton[1]].FunctionCallID;
                                break;
                        }
                        break;
                    case VK_ESCAPE:
                        Flag = FALSE;
                        KeypressSound();
                        SetConsoleMode(StandardInputHandle, ConsoleMode);
                        ButtonFunctions(Back_B_F);
                        break;
                    case VK_HOME:
                        Flag = FALSE;
                        KeypressSound();
                        SetConsoleMode(StandardInputHandle, ConsoleMode);
                        ClearConsole(0);
                        Menu(Main_Menu_M);
                        break;
                    case VK_END:
                        Flag = FALSE;
                        KeypressSound();
                        SetConsoleMode(StandardInputHandle, ConsoleMode);
                        ButtonFunctions(Exit_B_F);
                        break;
                    case VK_INSERT:
                        switch (FunctionType) {
                            case 3:
                                string ButtonCurrentString = Button[CurrentButton[0]][CurrentButton[1]].Text;
                                StringInterpret(ButtonCurrentString, 1);
                                SetCord(Button[CurrentButton[0]][CurrentButton[1]].x,
                                        Button[CurrentButton[0]][CurrentButton[1]].y);
                                ColorOut(ButtonCurrentString, 3);
                                return 0;
                                break;
                        }
                        break;
                    case 0xBB:
                    case 0x6B:
                        if (CurrentMenuID != Calc_M) ButtonFunctions(Calc_B_F);
                        break;
                }
            }
        }
        if ((Count == 0) && (Flag)) {
            for (int i = 0; i < NumberOfRows; i++) {
                for (int j = 0; j < NumberOfColumns; j++) {
                    if (Button[i][j].Status) {
                        string ButtonString = Button[i][j].Text;
                        StringInterpret(ButtonString, 1);
                        if (i == CurrentButton[0] && j == CurrentButton[1])
                            StringOut(ButtonString, Button[i][j].x, Button[i][j].y, CreateButtonColumnWidthValue, 1);
                        else StringOut(ButtonString, Button[i][j].x, Button[i][j].y, CreateButtonColumnWidthValue, 3);
                    }
                }
            }
        }
        else if ((((PreviousButton[0] != CurrentButton[0]) || (PreviousButton[1] != CurrentButton[1])) && (Flag))) {
            string ButtonCurrentString = Button[CurrentButton[0]][CurrentButton[1]].Text;
            StringInterpret(ButtonCurrentString, 1);
            StringOut(ButtonCurrentString, Button[CurrentButton[0]][CurrentButton[1]].x,
                      Button[CurrentButton[0]][CurrentButton[1]].y, CreateButtonColumnWidthValue, 1);
            string ButtonPreviousString = Button[PreviousButton[0]][PreviousButton[1]].Text;
            StringInterpret(ButtonPreviousString, 1);
            StringOut(ButtonPreviousString, Button[PreviousButton[0]][PreviousButton[1]].x,
                      Button[PreviousButton[0]][PreviousButton[1]].y, CreateButtonColumnWidthValue, 3);
            PreviousButton[0] = CurrentButton[0];
            PreviousButton[1] = CurrentButton[1];
        }
        Count++;
    }
    CursorToggle(1);
}

// The CreateDialogBox(char[],char[],int,int,int,int[5]) is used to generate a dialog box with the given details.

int CreateDialogBox(char DialogTitle[], char DialogData[], int DialogWidth, int DialogHeight, int DialogType,
                    int ButtonsFunction[5], int ForceShiftX, int ForceShiftY) {
    CursorToggle(0);
    if (DialogHeight > 16 || DialogWidth > 78) {
        return 0;
    }
    int ReturnData;
    int X1, Y1, X2, Y2;
    int TitleLength = StringLength(DialogTitle);
    int DataLength = StringLength(DialogData);
    int TitleLineRequired = 1, DataLineRequired = 1;
    int LastTitleCharacterCoordinate[2], LastDataCharacterCoordinate[2];
    // Calculating Important variables value.
    X1 = 40 - (DialogWidth / 2) + ForceShiftX - 1;
    X2 = 40 + (DialogWidth / 2) + ForceShiftX;
    Y1 = 14 - (DialogHeight / 2) + ForceShiftY;
    Y2 = 14 + (DialogHeight / 2) + ForceShiftY;
    int TitleLengthTemp = TitleLength, DataLengthTemp = DataLength;
    for (int i = 0; i <= TitleLengthTemp; i++) {
        if (i > (DialogWidth - 7)) {
            TitleLineRequired++;
            TitleLengthTemp = TitleLengthTemp - i;
            i = 0;
        }
    }
    for (int i = 0; i <= DataLengthTemp; i++) {
        if (i > (DialogWidth - 7)) {
            DataLineRequired++;
            DataLengthTemp = DataLengthTemp - i;
            i = 0;
        }
    }
    // Generating Dialog Frame.
    for (int i = Y1 - 1; i <= Y2 + 1; i++) {
        for (int j = X1 - 1; j <= X2 + 1; j++) {
            SetCord(j, i);
            if (i == (Y1 - 1) || i == (Y2 + 1)) {
                cout << DialogBoxMainOutterSpirit;
            }
            if (i == Y1 || i == Y2) {
                if (j == X1) {
                    if (i == Y1) ColorOut(DialogBoxMainEdgeTopLeftSpirit, 1);
                    else if (i == Y2) ColorOut(DialogBoxMainEdgeBottomLeftSpirit, 1);
                }
                else if (j == X2) {
                    if (i == Y1) ColorOut(DialogBoxMainEdgeTopRightSpirit, 1);
                    else if (i == Y2) ColorOut(DialogBoxMainEdgeBottomRightSpirit, 1);
                }
                else if (j > (X1 - 1) && j < (X2 + 1)) ColorOut(DialogBoxMainTopBottomSpirit, 1);
                else if (j == X1 - 1 || j == X2 + 1) cout << DialogBoxMainOutterSpirit;
            }
            if (i > Y1 && i < Y2) {
                if ((j == X1 || j == X2)) ColorOut(DialogBoxMainLeftRightSpirit, 1);
                else if ((j == X1 + 1 || j == X2 - 1)) ColorOut(DialogBoxMainInnerSpirit, 1);
                else cout << DialogBoxMainOutterSpirit;
            }
        }
    }
    for (int i = X1 + 2; i <= X2 - 2; i++) {
        SetCord(i, Y1 + (TitleLineRequired + 3));
        ColorOut(DialogBoxContentSeparatorSpirit, 1);
    }
    int TitleCharacterCount = 0, DataCharacterCount = 0;
    for (int i = 1; i <= TitleLineRequired; i++) {
        SetCord((X1 + 4), (Y1 + i + 1));
        for (; (TitleCharacterCount < TitleLength) &&
               (TitleCharacterCount < (i * (DialogWidth - 7))); TitleCharacterCount++) {
            ColorOut(DialogTitle[TitleCharacterCount], 1);
            LastTitleCharacterCoordinate[0] = (X1 + 4 + TitleCharacterCount);
            LastTitleCharacterCoordinate[1] = (Y1 + i + 1);
        }
    }
    for (int i = 1; i <= DataLineRequired; i++) {
        SetCord((X1 + 4), (Y1 + i + 4 + TitleLineRequired));
        for (; (DataCharacterCount < DataLength) &&
               (DataCharacterCount < (i * (DialogWidth - 7))); DataCharacterCount++) {
            ColorOut(DialogData[DataCharacterCount], 0);
            LastDataCharacterCoordinate[0] = (X1 + 4 + DataCharacterCount);
            LastDataCharacterCoordinate[1] = (Y1 + i + 4 + TitleLineRequired);
        }
    }
    for (int i = X1 + 2; i <= X2 - 2; i++) {
        SetCord(i, (Y2 - 4));
        ColorOut(DialogBoxContentSeparatorSpirit, 1);
    }
    // Creating the types of Return for the dialogs.
    button B1[1][ButtonsColumnLimit] =
            {
                    {
                            {1, X1 + (DialogWidth / 2 - 11), (Y2 - 2), "Yes", ButtonsFunction[0]},
                            {1, X1 + (DialogWidth / 2 + 11), (Y2 - 2), "No", ButtonsFunction[1]},
                            {0},
                            {0},
                            {0}
                    }
            };
    button B2[1][ButtonsColumnLimit] =
            {
                    {
                            {1, X1 + (DialogWidth / 2 - 22), (Y2 - 2), "Got It", ButtonsFunction[0]},
                            {1, X1 + (DialogWidth / 2 + 5), (Y2 - 2), "Need More Advice", ButtonsFunction[1]},
                            {0},
                            {0},
                            {0}
                    }
            };
    int D_B[2] = {0, 0};
    switch (DialogType) {
        case 1:
            SetCord((DialogWidth / 2 - 3), Y2 - 2);
            CreateButtons(B1, 1, D_B);
            break;
        case 2:
            SetCord(LastDataCharacterCoordinate[0], LastDataCharacterCoordinate[1]);
            for (int i = 0; i <= 5; i++) {
                PauseConsole(200);
                ColorOut(".", 1);
            }
            break;
        case 3:
            SetCord((DialogWidth / 2 - 3), Y2 - 2);
            CreateButtons(B2, 1, D_B);
            break;
        case 4:
            SetCord(34, 15);
            for (int i = 0; i <= 5; i++) {
                PauseConsole(200);
                ColorOut(".", 1);
            }
            break;
    }
    CursorToggle(1);
    return ReturnData;
}

// The FirstTimeIntro(int) is used to generate the menu for the first-time user.

void FirstTimeIntro(int Type) {
    int ButtonsFunction[5] = {First_Time_Yes_Button, First_Time_No_Button, 0, 0, 0};
    int DB[2] = {0, 0};
    button Demo[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 22, 19, "Hi! Hit Enter to see what's next!", FirstTimeIntroDemoButton}, {0}, {0}, {0}, {0}, {0}
                    }
            };
    button Demo2[2][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 19, "Try Me!", FirstTimeIntroDemoButton2},
                                 {1, 33, 19, "No I'm Better!", FirstTimeIntroDemoButton2},
                                                                                           {1, 57, 19, "I'm Fine.", FirstTimeIntroDemoButton2}, {0}, {0}, {0}
                    },
                    {
                            {0}, {1, 37, 21, "Hmmm...",        FirstTimeIntroDemoButton2}, {0},                                                 {0}, {0}, {0}
                    }
            };
    button DemoReDo[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 17, "Yes", FirstTimeIntroDemoButtonRedoYes},
                            {1, 44, 17, "No", FirstTimeIntroDemoButtonRedoNo}, {0}, {0}, {0}, {0}
                    }
            };
    button DemoEnd[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 27, 24, "Press Enter to End Intro", Main_Menu_M}, {0}, {0}, {0}, {0}, {0}
                    }
            };
    scrolllist DemoScroll[2] =
            {
                    {1, "Cool!",     1, "Yeah!"},
                    {1, "Isn't it?", 2, "No, not much huh?"}
            };
    int DemoScrollInput = 0;
    switch (Type) {
        case 1:
            SetConsoleDimensions(800, 400);
            CreateDialogBox("First Run!", Strings[2], 70, 14, 1, ButtonsFunction, 0, 1);
            break;
        case 2:
            SetConsoleDimensions(800, 400);
            CursorToggle(0);
            MainFrameShiftY = 7;
            MainFrameHeight = 22;
            MainFrame();
            FrameHeader(11, 8, 57, 0, "Welcome To Calculator.1.1", 1);
            PauseConsole(500);
            StringOut(134, 13, 16, 52, 3);
            PauseConsole(500);
            StringOut(134, 13, 16, 52, 0);
            PauseConsole(500);
            StringOut(134, 13, 16, 52, 1);
            PauseConsole(8000);
            StringOut(134, 13, 16, 52, 1);
            PauseConsole(500);
            StringOut(134, 13, 16, 52, 0);
            PauseConsole(500);
            StringOut(134, 13, 16, 52, 3);
            ClearFrame(13, 16, 52, StringOutNoOfLines);
            PauseConsole(500);
            StringOut(135, 13, 14, 52, 3);
            PauseConsole(500);
            StringOut(135, 13, 14, 52, 0);
            PauseConsole(500);
            StringOut(135, 13, 14, 52, 1);
            PauseConsole(4000);
            StringOut(136, 13, 17, 52, 3);
            PauseConsole(500);
            StringOut(136, 13, 17, 52, 0);
            PauseConsole(500);
            StringOut(136, 13, 17, 52, 1);
            PauseConsole(1000);
            CreateButtons(Demo, 1, DB, 1);
            break;
        case 3:
            ClearFrame(13, 14, 52, 5);
            PauseConsole(500);
            StringOut(137, 26, 13, 52, 3);
            PauseConsole(500);
            StringOut(137, 26, 13, 52, 0);
            PauseConsole(500);
            StringOut(137, 26, 13, 52, 1);
            PauseConsole(2000);
            StringOut(138, 13, 15, 52, 3);
            PauseConsole(500);
            StringOut(138, 13, 15, 52, 0);
            PauseConsole(500);
            StringOut(138, 13, 15, 52, 1);
            PauseConsole(2000);
            CreateButtons(Demo2, 2, DB, 1);
            break;
        case 4:
            ClearFrame(13, 13, 52, 9);
            PauseConsole(500);
            StringOut(139, 13, 14, 52, 3);
            PauseConsole(500);
            StringOut(139, 13, 14, 52, 0);
            PauseConsole(500);
            StringOut(139, 13, 14, 52, 1);
            PauseConsole(2000);
            StringOut(140, 13, 17, 52, 3);
            PauseConsole(500);
            StringOut(140, 13, 17, 52, 0);
            PauseConsole(500);
            StringOut(140, 13, 17, 52, 1);
            PauseConsole(2000);
            StringOut(141, 13, 20, 52, 3);
            PauseConsole(500);
            StringOut(141, 13, 20, 52, 0);
            PauseConsole(500);
            StringOut(141, 13, 20, 52, 1);
            PauseConsole(8000);
            ClearFrame(13, 13, 52, 9);
            PauseConsole(500);
            StringOut(142, 10, 14, 52, 3);
            PauseConsole(500);
            StringOut(142, 10, 14, 52, 0);
            PauseConsole(500);
            StringOut(142, 10, 14, 52, 1);
            PauseConsole(500);
            StringOut(143, 45, 14, 52, 3);
            PauseConsole(500);
            StringOut(143, 45, 14, 52, 0);
            PauseConsole(500);
            StringOut(143, 45, 14, 52, 1);
            PauseConsole(500);
            StringOut(144, 10, 16, 52, 3);
            PauseConsole(500);
            StringOut(144, 10, 16, 52, 0);
            PauseConsole(500);
            StringOut(144, 10, 16, 52, 1);
            PauseConsole(500);
            StringOut(145, 45, 16, 52, 3);
            PauseConsole(500);
            StringOut(145, 45, 16, 52, 0);
            PauseConsole(500);
            StringOut(145, 45, 16, 52, 1);
            PauseConsole(500);
            StringOut(158, 10, 18, 52, 3);
            PauseConsole(500);
            StringOut(158, 10, 18, 52, 0);
            PauseConsole(500);
            StringOut(158, 10, 18, 52, 1);
            PauseConsole(500);
            StringOut(159, 10, 20, 52, 3);
            PauseConsole(500);
            StringOut(159, 10, 20, 52, 0);
            PauseConsole(500);
            StringOut(159, 10, 20, 52, 1);
            PauseConsole(500);
            StringOut(160, 10, 22, 52, 3);
            PauseConsole(500);
            StringOut(160, 10, 22, 52, 0);
            PauseConsole(500);
            StringOut(160, 10, 22, 52, 1);
            PauseConsole(12000);
            ClearFrame(10, 13, 65, 9);
            PauseConsole(500);
            StringOut(146, 20, 14, 52, 3);
            PauseConsole(500);
            StringOut(146, 20, 14, 52, 0);
            PauseConsole(500);
            StringOut(146, 20, 14, 52, 1);
            PauseConsole(2000);
            CreateButtons(DemoReDo, 1, DB, 1);
            break;
        case 5:
            ClearFrame(13, 13, 52, 9);
            PauseConsole(500);
            StringOut(147, 13, 14, 52, 3);
            PauseConsole(500);
            StringOut(147, 13, 14, 52, 0);
            PauseConsole(500);
            StringOut(147, 13, 14, 52, 1);
            PauseConsole(4000);
            StringOut(148, 13, 17, 52, 3);
            PauseConsole(500);
            StringOut(148, 13, 17, 52, 0);
            PauseConsole(500);
            StringOut(148, 13, 17, 52, 1);
            PauseConsole(500);
            StringOut(155, 13, 23, 52, 3);
            PauseConsole(500);
            StringOut(155, 13, 23, 52, 0);
            PauseConsole(500);
            StringOut(155, 13, 23, 52, 1);
            DemoScrollInput = ScrollInput(1, 35, 20, DemoScroll, 2, 1, 152);
            if (DemoScrollInput) FirstTimeIntro(6);
            break;
        case 6:
            ClearFrame(13, 13, 52, 11);
            PauseConsole(500);
            StringOut(149, 13, 14, 52, 3);
            PauseConsole(500);
            StringOut(149, 13, 14, 52, 0);
            PauseConsole(500);
            StringOut(149, 13, 14, 52, 1);
            PauseConsole(2000);
            StringOut(150, 13, 17, 52, 3);
            PauseConsole(500);
            StringOut(150, 13, 17, 52, 0);
            PauseConsole(500);
            StringOut(150, 13, 17, 52, 1);
            PauseConsole(2000);
            StringOut(151, 13, 20, 52, 3);
            PauseConsole(500);
            StringOut(151, 13, 20, 52, 0);
            PauseConsole(500);
            StringOut(151, 13, 20, 52, 1);
            PauseConsole(2000);
            DemoScrollInput = ScrollInput(1, 35, 23, DemoScroll, 2, 1, 153);
            if (DemoScrollInput) FirstTimeIntro(7);
            break;
        case 7:
            ClearFrame(13, 13, 52, 10);
            PauseConsole(500);
            StringOut(154, 13, 14, 52, 3);
            PauseConsole(500);
            StringOut(154, 13, 14, 52, 0);
            PauseConsole(500);
            StringOut(154, 13, 14, 52, 1);
            PauseConsole(15000);
            StringOut(156, 27, 24, 52, 3);
            PauseConsole(500);
            StringOut(156, 27, 24, 52, 0);
            PauseConsole(500);
            StringOut(156, 27, 24, 52, 1);
            CreateButtons(DemoEnd, 1, DB, 1);
            break;
    }
}

// The CurrentAddress(char[]) is used to generate or update the address bar of the program.

void CurrentAddress(char Text[]) {
    int AddressLength = StringLength(Text);
    int NumberOfLines = 0;
    int j = 0;
    for (int i = 0; (i <= 73) && (j < AddressLength); i++) {
        if (Text[j] == '~') {
            i += CurrentAddressSeparatorRepeatCount - 1;
        }
        if (i >= 73) {
            NumberOfLines++;
            i = 0;
        }
        j++;
    }
    SetCord(0, 7);
    cout << " ";
    for (int i = 1; i <= CurrentAddressSeparatorRepeatCount; ++i) cout << CurrentAddressSeparatorSpirit;
    cout << " ";
    int k = 0;
    for (int i = 0; i <= NumberOfLines; i++) {
        if (i != 0) for (int l = 1; l <= 2 + CurrentAddressSeparatorRepeatCount; ++l) cout << " ";
        for (int j = 0; (j <= 73) && (j <= AddressLength + 1); j++) {
            if (k < AddressLength) {
                if (Text[k] == '~') {
                    for (int i = 1; i <= CurrentAddressSeparatorRepeatCount; ++i) cout << CurrentAddressSeparatorSpirit;
                    j += CurrentAddressSeparatorRepeatCount - 1;
                }
                else cout << Text[k];
            }
            k++;
        }
        cout << "\n";
    }
    for (int i = 0; i < 80; i++) cout << HeaderSeparatorSpirit;
    CurrentAddressNoOfLines = NumberOfLines;
}

// The MainFrame(int,int,int,int,int,int) is used to generate the frame for the program output.

void MainFrame() {
    int ShiftX = MainFrameShiftX;
    int ShiftY = MainFrameShiftY;
    int Width = MainFrameWidth;
    int Height = MainFrameHeight;
    int ColorType = MainFrameColourType;
    int CornerRoundFlag = MainFrameRoundFlag;
    Width += ShiftX;
    Height += ShiftY;
    for (int i = ShiftY; i <= Height; i++) {
        for (int j = ShiftX; j <= Width; j++) {
            SetCord(j, i);
            if (i == ShiftY || i == Height) {
                if (j == ShiftX || j == Width) ColorOut(FrameHeaderMainEdgesSpirit, ColorType);
                else ColorOut(FrameHeaderMainTopBottomSpirit, ColorType);
            }
            else if ((j == ShiftX || j == Width)) ColorOut(FrameHeaderMainLeftRightSpirit, ColorType);
            else if ((j == ShiftX + 1 || j == Width - 1)) ColorOut(FrameHeaderMainInnerSpirit, ColorType);
            else if ((CornerRoundFlag == 1 || CornerRoundFlag == 2) &&
                     ((i == ShiftY + 1) && (j == ShiftX + 2) || (i == ShiftY + 1) && (j == ShiftX + 3) ||
                      (i == ShiftY + 1) && (j == ShiftX + 4) || (i == ShiftY + 2) && (j == ShiftX + 2) ||
                      (i == ShiftY + 2) && (j == ShiftX + 3) || (i == ShiftY + 3) && (j == ShiftX + 2)))
                ColorOut(FrameHeaderMainInnerCornerTopLeftSpirit, ColorType);
            else if ((CornerRoundFlag == 1 || CornerRoundFlag == 2) &&
                     ((i == Height - 1) && (j == Width - 2) || (i == Height - 1) && (j == Width - 3) ||
                      (i == Height - 1) && (j == Width - 4) || (i == Height - 2) && (j == Width - 2) ||
                      (i == Height - 2) && (j == Width - 3) || (i == Height - 3) && (j == Width - 2)))
                ColorOut(FrameHeaderMainInnerCornerBottomLeftSpirit, ColorType);
            else if ((CornerRoundFlag == 2) &&
                     ((i == ShiftY + 1) && (j == Width - 2) || (i == ShiftY + 1) && (j == Width - 3) ||
                      (i == ShiftY + 1) && (j == Width - 4) || (i == ShiftY + 2) && (j == Width - 2) ||
                      (i == ShiftY + 2) && (j == Width - 3) || (i == ShiftY + 3) && (j == Width - 2)))
                ColorOut(FrameHeaderMainInnerCornerTopRightSpirit, ColorType);
            else if ((CornerRoundFlag == 2) &&
                     ((i == Height - 1) && (j == ShiftX + 2) || (i == Height - 1) && (j == ShiftX + 3) ||
                      (i == Height - 1) && (j == ShiftX + 4) || (i == Height - 2) && (j == ShiftX + 2) ||
                      (i == Height - 2) && (j == ShiftX + 3) || (i == Height - 3) && (j == ShiftX + 2)))
                ColorOut(FrameHeaderMainInnerCornerBottomRightSpirit, ColorType);
        }
        if (Width < 89) cout << "\n";
    }
    SetCord(0, 0);
    SetCord(ShiftY + 1, ShiftX + 1);
}

// The DefaultMainFrame() is used to assign default values to the Global Mainframe Variables.

void DefaultMainFrame() {
    MainFrameShiftX = 0;                                    // Default Value.
    MainFrameShiftY = 9;                                    // Default Value.
    MainFrameWidth = 79;                                     // Default Value.
    MainFrameHeight = 15;                                    // Default Value.
    MainFrameColourType = 0;                                // Default Value.
    MainFrameRoundFlag = 2;                                 // Default Value.
};

// The FrameHeader(short,short,int,short,char*,int) is used to generate a Page Header layout.

void FrameHeader(short X, short Y, int Width, short ColorType, char *Text, int Type) {
    for (int h = Y; h <= Y + 3; h++) {
        for (int i = X; i <= X + Width; i++) {
            SetCord(i, h);
            if ((i == X || i == X + Width) && (h == Y || h == Y + 1 || h == Y + 2))
                ColorOut(FrameHeaderSpiritMain, ColorType);
            if ((i == X + 1 || i == X + Width - 1) && (h == Y || h == Y + 1 || h == Y + 2))
                ColorOut(FrameHeaderInnerMainSpirit, ColorType);
            if (h == Y + 3) {
                if (i == X) ColorOut(FrameHeaderEdgeLeftSpirit, ColorType);
                else if (i == X + Width) ColorOut(FrameHeaderEdgeRightSpirit, ColorType);
                else ColorOut(FrameHeaderSpiritMain, ColorType);
            }
        }
    }
    SetCord(X + 4, Y + 1);
    ColorOut(Text, ColorType);
}

// The StringOut(int,short,short,int) is used to generate a string output stream as desired.

void StringOut(int StringID, short StartX, short StartY, int ParagraphWidth, int ColorType, string InterpretString) {
    string TempString = Strings[StringID];
    if (StringLength(InterpretString)) StringInterpret(TempString, 2, InterpretString);
    else StringInterpret(TempString, 1, InterpretString);
    int StringLengthInt = StringLength(TempString);
    int NumberOfLines = StringLengthInt / ParagraphWidth;
    short EndX, EndY;
    for (int i = 0; i <= NumberOfLines; i++) {
        SetCord(StartX, i + StartY);
        EndX = 0;
        for (int j = i * (ParagraphWidth + 1); (j <= StringLengthInt) && (j <= ((i + 1) * (ParagraphWidth)) + i); j++) {
            EndX++;
            ColorOut(TempString[j], ColorType);
            if (i == NumberOfLines && j == StringLengthInt) {
                EndY = i;
                EndX--;
            }
        }
    }
    StringOutNoOfLines = NumberOfLines;
    StringOutEndX = EndX + StartX;
    StringOutEndY = StartY + EndY;
    SetCord(EndX + StartX, StartY + EndY);
}

void StringOut(string StringToDisplay, short StartX, short StartY, int ParagraphWidth, int ColorType,
               string InterpretString) {
    string TempString = StringToDisplay;
    if (StringLength(InterpretString)) StringInterpret(TempString, 2, InterpretString);
    else StringInterpret(TempString, 1, InterpretString);
    int StringLengthInt = StringLength(TempString);
    int NumberOfLines = StringLengthInt / ParagraphWidth;
    short EndX, EndY;
    for (int i = 0; i <= NumberOfLines; i++) {
        SetCord(StartX, i + StartY);
        EndX = 0;
        for (int j = i * (ParagraphWidth + 1); (j <= StringLengthInt) && (j <= ((i + 1) * (ParagraphWidth)) + i); j++) {
            EndX++;
            ColorOut(TempString[j], ColorType);
            if (i == NumberOfLines && j == StringLengthInt) {
                EndY = i;
                EndX--;
            }
        }
    }
    StringOutNoOfLines = NumberOfLines;
    SetCord(EndX + StartX, StartY + EndY);
}

void StringOut(string &StringToDisplay, short &StartX, short &StartY, int &ParagraphWidth, int ColorType,
               string InterpretString) {
    string TempString = StringToDisplay;
    if (StringLength(InterpretString)) StringInterpret(TempString, 2, InterpretString);
    else StringInterpret(TempString, 1, InterpretString);
    int StringLengthInt = StringLength(TempString);
    int NumberOfLines = StringLengthInt / ParagraphWidth;
    short EndX, EndY;
    for (int i = 0; i <= NumberOfLines; i++) {
        SetCord(StartX, i + StartY);
        EndX = 0;
        for (int j = i * (ParagraphWidth + 1); (j <= StringLengthInt) && (j <= ((i + 1) * (ParagraphWidth)) + i); j++) {
            EndX++;
            ColorOut(TempString[j], ColorType);
            if (i == NumberOfLines && j == StringLengthInt) {
                EndY = i;
                EndX--;
            }
        }
    }
    StringOutNoOfLines = NumberOfLines;
    SetCord(EndX + StartX, StartY + EndY);
}

// The ScrollInput(short,short,short,scrollist[],int,int) is used to create a scroll type input framework.

int ScrollInput(short Type, short x, short y, scrolllist ScrollList[], int NumberOfObjects, int StartID,
                int AdditionalStringID) {
    CursorToggle(0);
    if (ScrollList[StartID - 1].Status == 0) StartID = 1;
    int ScrollInputButtonStartX = 9, ScrollInputButtonStartY = 99;
    button ScrollInputButton[ButtonsRowLimit][ButtonsColumnLimit];
    int ScrollInputButtonReturn = 0;
    int ScrollInputButtonRows = 0;
    int DefaultButtonID[2] = {0, 0};
    int CurrentID = StartID;
    int CoordinatesOfPreviousKey[2];
    int CoordinatesOfNextKey[2];
    int Count = 0;
    int PreviousID = StartID;
    string ScrollInputTextString, ScrollInputAdditionalTextString;
    DWORD ConsoleMode;
    INPUT_RECORD InputEvent;
    BOOL Flag = TRUE;
    HANDLE StandardInputHandle = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(StandardInputHandle, &ConsoleMode);
    SetConsoleMode(StandardInputHandle, 0);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));                 // To flush the non-required previous data.
    CoordinatesOfPreviousKey[0] = x;
    CoordinatesOfPreviousKey[1] = y;
    CoordinatesOfNextKey[0] = x + 2 + StringLength(ScrollList[CurrentID - 1].Text);
    CoordinatesOfNextKey[1] = y;
    ClearFrame(x, y, (CoordinatesOfNextKey[0] - CoordinatesOfPreviousKey[0] + 1), 0);
    while (Flag) {
        if ((WaitForSingleObject(StandardInputHandle, 0) == WAIT_OBJECT_0) && (Count != 0)) {
            DWORD ConsoleInputCount;
            ReadConsoleInput(StandardInputHandle, &InputEvent, 1, &ConsoleInputCount);
            if ((InputEvent.EventType == KEY_EVENT) && (InputEvent.Event.KeyEvent.bKeyDown)) {
                switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                    case VK_RIGHT:
                        SetCord(CoordinatesOfNextKey[0] + 1, CoordinatesOfNextKey[1]);
                        ColorOut(ScrollRightSpirit, 1);
                        CurrentID++;
                        if (CurrentID > NumberOfObjects) CurrentID = 1;
                        break;
                    case VK_LEFT:
                        SetCord(CoordinatesOfPreviousKey[0], CoordinatesOfPreviousKey[1]);
                        ColorOut(ScrollLeftSpirit, 1);
                        CurrentID--;
                        if (CurrentID <= 0) CurrentID = NumberOfObjects;
                        break;
                    case VK_RETURN:
                        ScrollInputTextString = ScrollList[CurrentID - 1].Text;
                        ScrollInputAdditionalTextString = ScrollList[CurrentID - 1].AdditionalText;
                        StringInterpret(ScrollInputTextString, 1);
                        StringInterpret(ScrollInputAdditionalTextString, 1);
                        SetCord(CoordinatesOfPreviousKey[0] + 2, CoordinatesOfPreviousKey[1]);
                        ColorOut(ScrollInputTextString, 1);
                        KeypressSound();
                        PauseConsole(FPS * 1000);
                        ClearFrame(x, y, (CoordinatesOfNextKey[0] - CoordinatesOfPreviousKey[0] +
                                          StringLength(ScrollInputAdditionalTextString) + 2), 0);
                        SetCord(x, y);
                        cout << ScrollInputTextString << " " << ScrollInputAdditionalTextString;
                        SetConsoleMode(StandardInputHandle, ConsoleMode);
                        return ScrollList[CurrentID - 1].AssociatedID;
                        break;
                    case VK_TAB:
                        if (ScrollInputButtonColumnHack) SetConsoleDimensions(800, 840);
                        SetCord(0, ScrollInputButtonStartY * 2);
                        for (int i = 0, k = 0; i < ButtonsRowLimit; i++) {
                            for (int j = 0; j < ButtonsColumnLimit; j++) {
                                if ((j < 3 - ScrollInputButtonColumnHack) && (k < NumberOfObjects)) {
                                    ScrollInputButton[i][j].FunctionCallID = k;
                                    ScrollInputButton[i][j].Status = 1;
                                    ScrollInputButton[i][j].x =
                                            ScrollInputButtonStartX + (24 + 10 * ScrollInputButtonColumnHack) * j;
                                    ScrollInputButton[i][j].y = ScrollInputButtonStartY + 4 + i * 2;
                                    ScrollInputButton[i][j].Text = ScrollList[k].Text;
                                    k++;
                                } else {
                                    ScrollInputButton[i][j].FunctionCallID = 0;
                                    ScrollInputButton[i][j].Status = 0;
                                    ScrollInputButton[i][j].x = 0;
                                    ScrollInputButton[i][j].y = 0;
                                    ScrollInputButton[i][j].Text = "";
                                }
                                if (k == NumberOfObjects) {
                                    ScrollInputButtonRows = i + 1;
                                    k++;
                                }
                            }
                        }
                        StringOut(AdditionalStringID, ScrollInputButtonStartX, ScrollInputButtonStartY - 3, 61, 0);
                        MainFrameShiftX = 0;
                        MainFrameWidth = 79;
                        MainFrameColourType = 0;
                        MainFrameRoundFlag = 2;
                        MainFrameShiftY = ScrollInputButtonStartY - 5;
                        MainFrameHeight = 4 + StringOutNoOfLines;
                        MainFrame();
                        MainFrameShiftY = ScrollInputButtonStartY + StringOutNoOfLines;
                        if (ScrollInputButtonRows < 7) MainFrameHeight = 26 - MainFrameHeight;
                        else MainFrameHeight = 12 + ScrollInputButtonRows * 2 - MainFrameHeight;
                        MainFrame();
                        SetCord(0, MainFrameShiftY + MainFrameHeight);
                        ScrollInputButtonReturn = CreateButtons(ScrollInputButton, ScrollInputButtonRows,
                                                                DefaultButtonID, 2);
                        ClearFrame(0, MainFrameShiftY, 80, MainFrameHeight);
                        SetCord(0, 0);
                        ScrollInputTextString = ScrollList[ScrollInputButtonReturn].Text;
                        ScrollInputAdditionalTextString = ScrollList[ScrollInputButtonReturn].AdditionalText;
                        StringInterpret(ScrollInputTextString, 1);
                        StringInterpret(ScrollInputAdditionalTextString, 1);
                        ClearFrame(x, y, (CoordinatesOfNextKey[0] - CoordinatesOfPreviousKey[0] +
                                          StringLength(ScrollInputAdditionalTextString) + 2), 0);
                        SetCord(x, y);
                        cout << ScrollInputTextString << " " << ScrollInputAdditionalTextString;
                        SetConsoleMode(StandardInputHandle, ConsoleMode);
                        return ScrollList[ScrollInputButtonReturn].AssociatedID;
                        break;
                    case VK_ESCAPE:
                        ClearConsole(0);
                        Menu(PreviousMenuID);
                        break;
                }
            }
        }
        if ((PreviousID != CurrentID) || Count == 0) {
            PauseConsole(FPS * 1000);
            ScrollInputTextString = ScrollList[CurrentID - 1].Text;
            ScrollInputAdditionalTextString = ScrollList[CurrentID - 1].AdditionalText;
            StringInterpret(ScrollInputTextString, 1);
            StringInterpret(ScrollInputAdditionalTextString, 1);
            ClearFrame(x, y, (CoordinatesOfNextKey[0] - CoordinatesOfPreviousKey[0] +
                              StringLength(ScrollInputAdditionalTextString) + 2), 0);
            CoordinatesOfPreviousKey[0] = x;
            CoordinatesOfPreviousKey[1] = y;
            CoordinatesOfNextKey[0] = x + 2 + StringLength(ScrollInputTextString);
            CoordinatesOfNextKey[1] = y;
            SetCord(CoordinatesOfPreviousKey[0], CoordinatesOfPreviousKey[1]);
            cout << ScrollLeftSpirit;
            SetCord(CoordinatesOfPreviousKey[0] + 2, CoordinatesOfPreviousKey[1]);
            cout << ScrollInputTextString;
            SetCord(CoordinatesOfNextKey[0], CoordinatesOfNextKey[1]);
            cout << " " << ScrollRightSpirit;
            if (Type == 2) {
                cout << " " << ScrollInputAdditionalTextString;
            }
            PreviousID = CurrentID;
        }
        Count++;
    }
    return 0;
}

// The InputDataVariable(int,int,int,int,int,short,short,int,int,short) is used to generate input framework.

void InputDataVariable(int InputType, input InputStruct) {
    cin.clear();
    string InputTempString;
    string InputInformationTextIDTempString = Strings[InputStruct.InputInformationTextID];
    string InputInformationSecondaryTextIDTempString = Strings[InputStruct.InputInformationSecondaryTextID];
    StringInterpret(InputInformationTextIDTempString, 1);
    StringInterpret(InputInformationSecondaryTextIDTempString, 1);
    int CharCount = 0;
    int DecimalCount = 0;
    int DecimalPlace = 0;
    int InitialXCordOfInput = InputStruct.InputFrameStartX;
    int InitialYCordOfInput = InputStruct.InputFrameStartY;
    int k = 0, j = 0;
    for (int i = 0; i <= StringLength(InputInformationTextIDTempString); i++) {
        if (k == InputStruct.InputFrameWidth) {
            k = 0;
            InitialYCordOfInput++;
            j++;
        }
        if (i == StringLength(InputInformationTextIDTempString)) InitialXCordOfInput += k - j;
        k++;
    }
    scrolllist ScrollList[21];
    scrolllist ScrollListAngle[2];
    for (int i = 0; i <= 20; i++) {
        ScrollList[i].Status = 1;
        ScrollList[i].AssociatedID = DefaultUnits[i].UnitPowerValue;
        strcpy(ScrollList[i].Text, DefaultUnits[i].UnitName);
        strcpy(ScrollList[i].AdditionalText, InputStruct.UnitName);
    }
    for (int i = 0; i <= 1; i++) {
        ScrollListAngle[i].Status = 1;
        ScrollListAngle[i].AssociatedID = i;
        switch (i) {
            case 0:
                strcpy(ScrollListAngle[i].Text, "degree(s)");
                break;
            case 1:
                strcpy(ScrollListAngle[i].Text, "radian(s)");
                break;
        }
        strcpy(ScrollListAngle[i].AdditionalText, "");
    }
    int InitialXCordOfInputScroll = InputStruct.InputFrameStartX;
    int InitialYCordOfInputScroll = InitialYCordOfInput + 2;
    k = 0;
    j = 0;
    for (int i = 0; i <= StringLength(InputInformationSecondaryTextIDTempString); i++) {
        if (k == InputStruct.InputFrameWidth) {
            k = 0;
            InitialYCordOfInputScroll++;
            j++;
        }
        if (i == StringLength(InputInformationSecondaryTextIDTempString)) InitialXCordOfInputScroll += k - j;
        k++;
    }
    switch (InputType) {
        case 1:
        case 2:
        case 3:
            StringOut(InputStruct.InputInformationTextID, InputStruct.InputFrameStartX, InputStruct.InputFrameStartY,
                      InputStruct.InputFrameWidth, 0);
            SetCord(InitialXCordOfInput, InitialYCordOfInput);
            CursorToggle(1);
            int Count = 0;
        InputModeLabel:
            DWORD ConsoleMode;
            INPUT_RECORD InputEvent;
            BOOL Flag = TRUE;
            HANDLE StandardInputHandle = GetStdHandle(STD_INPUT_HANDLE);
            GetConsoleMode(StandardInputHandle, &ConsoleMode);
            SetConsoleMode(StandardInputHandle, 0);
            FlushConsoleInputBuffer(
                    GetStdHandle(STD_INPUT_HANDLE));                 // To flush the non-required previous data.
            while (Flag) {
                if ((WaitForSingleObject(StandardInputHandle, 0) == WAIT_OBJECT_0) && (Count != 0)) {
                    DWORD ConsoleInputCount;
                    ReadConsoleInput(StandardInputHandle, &InputEvent, 1, &ConsoleInputCount);
                    if ((InputEvent.EventType == KEY_EVENT) && (InputEvent.Event.KeyEvent.bKeyDown)) {
                        if (CharCount > InputStruct.MaximumChar) {
                            switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                                case VK_BACK:
                                    CharCount--;
                                    if (DecimalPlace == CharCount) DecimalCount = 0;
                                    if (CharCount >= 0) {
                                        SetCord(InitialXCordOfInput + CharCount, InitialYCordOfInput);
                                        cout << " ";
                                        InputTempString.erase(InputTempString.end() - 1);
                                    } else CharCount++;
                                    SetCord(InitialXCordOfInput + CharCount, InitialYCordOfInput);
                                    break;
                                case VK_DELETE:
                                    ClearFrame(InitialXCordOfInput, InitialYCordOfInput, InputStruct.MaximumChar, 1);
                                    InputTempString.erase(InputTempString.begin(), InputTempString.end());
                                    CharCount = 0;
                                    break;
                                case VK_RETURN:
                                    if (CharCount == 0) {
                                        KeypressSound();
                                        break;
                                    }
                                    Flag = 0;
                                    goto InputGetStringDone;
                                    break;
                                case VK_ESCAPE:
                                    ClearConsole(0);
                                    Menu(PreviousMenuID);
                                    break;
                                default:
                                    KeypressSound();
                                    break;
                            }
                            goto InputModeLabel;
                        }
                        switch (InputStruct.DataVariableType) {
                            case IntegerType:
                            case DoubleType:
                                switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                                    case VK_RETURN:
                                        if (CharCount == 0) {
                                            KeypressSound();
                                            break;
                                        }
                                        Flag = 0;
                                        goto InputGetStringDone;
                                        break;
                                    case VK_ESCAPE:
                                        ClearConsole(0);
                                        Menu(PreviousMenuID);
                                        break;
                                    case VK_BACK:
                                        CharCount--;
                                        if (DecimalPlace == CharCount) DecimalCount = 0;
                                        if (CharCount >= 0) {
                                            SetCord(InitialXCordOfInput + CharCount, InitialYCordOfInput);
                                            cout << " ";
                                            InputTempString.erase(InputTempString.end() - 1);
                                        } else CharCount++;
                                        SetCord(InitialXCordOfInput + CharCount, InitialYCordOfInput);
                                        break;
                                    case VK_DELETE:
                                        ClearFrame(InitialXCordOfInput, InitialYCordOfInput, InputStruct.MaximumChar,
                                                   1);
                                        InputTempString.erase(InputTempString.begin(), InputTempString.end());
                                        CharCount = 0;
                                        break;
                                    case VK_NUMPAD0:
                                    case 0x30:
                                        cout << "0";
                                        InputTempString += "0";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD1:
                                    case 0x31:
                                        cout << "1";
                                        InputTempString += "1";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD2:
                                    case 0x32:
                                        cout << "2";
                                        InputTempString += "2";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD3:
                                    case 0x33:
                                        cout << "3";
                                        InputTempString += "3";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD4:
                                    case 0x34:
                                        cout << "4";
                                        InputTempString += "4";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD5:
                                    case 0x35:
                                        cout << "5";
                                        InputTempString += "5";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD6:
                                    case 0x36:
                                        cout << "6";
                                        InputTempString += "6";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD7:
                                    case 0x37:
                                        cout << "7";
                                        InputTempString += "7";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD8:
                                    case 0x38:
                                        cout << "8";
                                        InputTempString += "8";
                                        CharCount++;
                                        break;
                                    case VK_NUMPAD9:
                                    case 0x39:
                                        cout << "9";
                                        InputTempString += "9";
                                        CharCount++;
                                        break;
                                    case 0xBD:
                                    case VK_SUBTRACT:
                                        if (CharCount == 0) {
                                            cout << "-";
                                            InputTempString += "-";
                                            CharCount++;
                                        }
                                        break;
                                    case 0x6E:
                                    case 0xBE:
                                        switch (InputStruct.DataVariableType) {
                                            case IntegerType:
                                                KeypressSound();
                                                break;
                                            case DoubleType:
                                                if (DecimalCount || CharCount == InputStruct.MaximumChar) {
                                                    KeypressSound();
                                                    break;
                                                }
                                                DecimalCount++;
                                                cout << ".";
                                                InputTempString += ".";
                                                CharCount++;
                                                DecimalPlace = CharCount;
                                                break;
                                        }
                                        break;
                                }
                                break;
                        }
                    }
                }
                Count++;
            }
        InputGetStringDone:
            CursorToggle(0);
            switch (InputStruct.DataVariableType) {
                case IntegerType:
                    IntegerVariable[InputStruct.DataVariableID] = atoi(InputTempString.c_str());
                    break;
                case DoubleType:
                    DoubleVariable[InputStruct.DataVariableID] = atof(InputTempString.c_str());
                    break;
            }
            break;
    }
    switch (InputType) {
        case 1:
            VariableConvertStatus[InputStruct.DataVariableID] = 1;
            break;
        case 2:
            VariableConvertStatus[InputStruct.DataVariableID] = 1;
            StringOut(InputStruct.InputInformationSecondaryTextID, InputStruct.InputFrameStartX,
                      InitialYCordOfInput + 2, InputStruct.InputFrameWidth, 0);
            UnitVariable[InputStruct.DataVariableID] = ScrollInput(2, InitialXCordOfInputScroll,
                                                                   InitialYCordOfInputScroll, ScrollList, 21,
                                                                   SettingsObject.GetDefaultUnitID());
            break;
        case 3:
            VariableConvertStatus[InputStruct.DataVariableID] = 0;
            StringOut(InputStruct.InputInformationSecondaryTextID, InputStruct.InputFrameStartX,
                      InitialYCordOfInput + 2, InputStruct.InputFrameWidth, 0);
            UnitVariable[InputStruct.DataVariableID] = ScrollInput(2, InitialXCordOfInputScroll,
                                                                   InitialYCordOfInputScroll, ScrollListAngle, 2, 0);
            break;
    }
    ClearFrame(InputStruct.InputFrameStartX, InputStruct.InputFrameStartY, InputStruct.InputFrameWidth,
               InputStruct.InputFrameHeight);
}

// The SettingsValueInterpreter(int,int) is used to get the current value of the setting and convert it into user readable form.

string SettingsValueInterpreter(int SettingsID, int SettingsValue) {
    switch (SettingsID) {
        case 1:
            for (int i = 0; i <= 20; i++) {
                if (SettingsValue == DefaultUnits[i].UnitPowerValue) {
                    string UnitName = DefaultUnits[i].UnitName;
                    UnitName += " metre";
                    return UnitName;
                }
            }
            break;
        case 12:
            switch (SettingsValue) {
                case 1:
                    return "Default";
                    break;
                case 2:
                    return "Pixelate";
                    break;
            }
            break;
        case 15:
            switch (SettingsValue) {
                case 1:
                    return "Type - 1";
                    break;
                case 2:
                    return "Type - 2";
                    break;
                case 3:
                    return "Type - 3";
                    break;
                case 4:
                    return "Type - 4";
                    break;
                case 5:
                    return "Type - 5";
                    break;
                case 6:
                    return "Type - 6";
                    break;
                case 0:
                    return "Off";
                    break;
            }
            break;
        case 13:
        case 14:
            switch (SettingsValue) {
                case 0:
                    return "Off";
                    break;
                case 1:
                    return "Happiness";
                    break;
                case 2:
                    return "Future";
                    break;
                case 3:
                    return "Kid";
                    break;
                case 4:
                    return "Sorrow";
                    break;
                case 5:
                    return "Christmas";
                    break;
                case 6:
                    return "Dance";
                    break;
            }
            break;
        case 16:
            switch (SettingsValue) {
                case 1:
                    return "Vertical Swipe";
                    break;
                case 2:
                    return "Diagonal Wipe";
                    break;
                case 3:
                    return "Cross Swipe";
                    break;
                case 4:
                    return "Pixelate";
                    break;
                case 5:
                    return "Random";
                    break;
            }
            break;
        case 17:
            switch (SettingsValue) {
                case 1:
                    return "Center";
                    break;
                case 2:
                    return "Top Left";
                    break;
                case 3:
                    return "Top Right";
                    break;
                case 4:
                    return "Bottom Left";
                    break;
                case 5:
                    return "Bottom Right";
                    break;
                case 6:
                    return "Manual";
                    break;
            }
            break;
        case 18:
            switch (SettingsValue) {
                case 1:
                    return "Vertical Swipe";
                    break;
                case 2:
                    return "Pixelate";
                    break;
            }
            break;
        default:
            return "NOT_SET";
            break;
    }
}

// The SettingsChanger(int,int,int,int) is used to change the desired settings.

void SettingsChanger(int SettingsID, int SettingsValue, int x, int y) {
    CursorToggle(0);
    scrolllist ScrollListDefaultCalculationUnit[21];
    for (int i = 0; i <= 20; i++) {
        ScrollListDefaultCalculationUnit[i].Status = 1;
        ScrollListDefaultCalculationUnit[i].AssociatedID = DefaultUnits[i].UnitPowerValue;
        strcpy(ScrollListDefaultCalculationUnit[i].Text, DefaultUnits[i].UnitName);
        strcpy(ScrollListDefaultCalculationUnit[i].AdditionalText, "metre");
    }
    scrolllist ScrollListThemes[2] =
            {
                    {1, "Default",  1, ""},
                    {1, "Pixelate", 2, ""}
            };
    scrolllist ScrollListBackgroundMusic[7] =
            {
                    {1, "Off",       0, ""},
                    {1, "Happiness", 1, ""},
                    {1, "Future",    2, ""},
                    {1, "Kid",       3, ""},
                    {1, "Sorrow",    4, ""},
                    {1, "Christmas", 5, ""},
                    {1, "Dance",     6, ""}
            };
    scrolllist ScrollListKeypressSound[7] =
            {
                    {1, "Off",      0, ""},
                    {1, "Type - 1", 1, ""},
                    {1, "Type - 2", 2, ""},
                    {1, "Type - 3", 3, ""},
                    {1, "Type - 4", 4, ""},
                    {1, "Type - 5", 5, ""},
                    {1, "Type - 6", 6, ""}
            };
    scrolllist ScrollListIntroStyle[5] =
            {
                    {1, "Vertical Swipe", 1, ""},
                    {1, "Diagonal Wipe",  2, ""},
                    {1, "Cross Swipe",    3, ""},
                    {1, "Pixelate",       4, ""},
                    {1, "Random",         5, ""}
            };
    scrolllist ScrollProgramPosition[6] =
            {
                    {1, "Center",       1, ""},
                    {1, "Top Left",     2, ""},
                    {1, "Top Right",    3, ""},
                    {1, "Bottom Left",  4, ""},
                    {1, "Bottom Right", 5, ""},
                    {1, "Manual",       6, ""}
            };
    scrolllist ScrollExitStyle[2] =
            {
                    {1, "Vertical Swipe", 1, ""},
                    {1, "Pixelate",       2, ""}
            };

    int NewSettingValue = 0;
    int SettingStartID = 0;
    switch (SettingsID) {
        case 1:
            for (int i = 0; i <= 20; i++) {
                if (SettingsValue == DefaultUnits[i].UnitPowerValue) {
                    SettingStartID = i + 1;
                    break;
                }
            }
            NewSettingValue = ScrollInput(2, x, y, ScrollListDefaultCalculationUnit, 21, SettingStartID);
            break;
        case 12:
            SettingStartID = SettingsValue;
            NewSettingValue = ScrollInput(1, x, y, ScrollListThemes, 2, SettingStartID);
            break;
        case 14:
            SettingStartID = SettingsValue + 1;
            NewSettingValue = ScrollInput(1, x, y, ScrollListBackgroundMusic, 7, SettingStartID);
            BackgroundMusicFlag = 0;
            BackgroundMusicID = 0;
            BackgroundMusicExecutedCount = 0;
            break;
        case 13:
            SettingStartID = SettingsValue + 1;
            NewSettingValue = ScrollInput(1, x, y, ScrollListBackgroundMusic, 7, SettingStartID);
            break;
        case 15:
            SettingStartID = SettingsValue + 1;
            NewSettingValue = ScrollInput(1, x, y, ScrollListKeypressSound, 7, SettingStartID);
            break;
        case 16:
            SettingStartID = SettingsValue;
            NewSettingValue = ScrollInput(1, x, y, ScrollListIntroStyle, 5, SettingStartID);
            break;
        case 17:
            SettingStartID = SettingsValue;
            NewSettingValue = ScrollInput(1, x, y, ScrollProgramPosition, 6, SettingStartID);
            break;
        case 18:
            SettingStartID = SettingsValue;
            NewSettingValue = ScrollInput(1, x, y, ScrollExitStyle, 2, SettingStartID);
            break;
    }
    SettingsObject.SettingsUpdate(SettingsID, NewSettingValue);
    InitializeVariable();
}

// The UpdateSettingsMenu() is used to update the Settings.

void UpdateSettingsMenu() {
    CursorToggle(0);
    SetConsoleDimensions(800, 625);
    int CurrentSettingID = 1;
    int LastSettingID = 1;
    const int TotalSettings = 8;
    settingslist SettingsListArray[TotalSettings] =
            {
                    {1, "Default Calculation Unit", 1},
                    {1, "Theme",                    12},
                    {1, "Intro Music",              13},
                    {1, "Background Music",         14},
                    {1, "Keypress Sounds",          15},
                    {1, "Intro Style",              16},
                    {1, "Program Position",         17},
                    {1, "Exit Style",               18}
            };
    int Count = 0;
    DWORD ConsoleMode;
    INPUT_RECORD InputEvent;
    BOOL Flag = TRUE;
    HANDLE StandardInputHandle = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(StandardInputHandle, &ConsoleMode);
    SetConsoleMode(StandardInputHandle, 0);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));                 // To flush the non-required previous data.
    while (Flag) {
        if ((WaitForSingleObject(StandardInputHandle, 0) == WAIT_OBJECT_0) && (Count != 0)) {
            DWORD ConsoleInputCount;
            ReadConsoleInput(StandardInputHandle, &InputEvent, 1, &ConsoleInputCount);
            if ((InputEvent.EventType == KEY_EVENT) && (InputEvent.Event.KeyEvent.bKeyDown)) {
                switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                    case VK_UP:
                        CurrentSettingID--;
                        if (CurrentSettingID == 0) CurrentSettingID = TotalSettings;
                        break;
                    case VK_DOWN:
                        CurrentSettingID++;
                        if (CurrentSettingID > TotalSettings) CurrentSettingID = 1;
                        break;
                    case VK_RETURN:
                        KeypressSound();
                        SettingsChanger(SettingsListArray[CurrentSettingID - 1].SettingID,
                                        SettingsObject.SettingValue[SettingsListArray[CurrentSettingID - 1].SettingID],
                                        44, ((CurrentSettingID - 1) * 3 + 17));
                        if (SettingsListArray[CurrentSettingID - 1].SettingID == 14) {
                            while (1) {
                                if (BackgroundMusicEndFlag) {
                                    if (MusicID != 0) {
                                        BackgroundMusicFlag = 1;
                                        BackgroundMusicID = MusicID;
                                        PauseConsole(FPS * 7000);
                                        Music(1, 200);
                                        PauseConsole(FPS * 7000);
                                        _beginthread(BackgroundMusic, 0,
                                                     (void *) &Temp);                            // Applying multi-threading concept to thread multiple processes at once.
                                        BackgroundMusicExecutedCount++;
                                        BackgroundMusicEndFlag = 0;
                                    }
                                    break;
                                }
                                else continue;
                            }
                        }
                        else if (SettingsListArray[CurrentSettingID - 1].SettingID == 12) {
                            HeaderMisc(0, 1);
                            Menu(Update_Settings_M);
                        }
                        else if (SettingsListArray[CurrentSettingID - 1].SettingID == 15) {
                            PauseConsole(FPS * 7000);
                            KeypressSound();
                            PauseConsole(FPS * 7000);
                        }
                        else if (SettingsListArray[CurrentSettingID - 1].SettingID == 17) {
                            SetConsoleDimensions(800, 625);
                        }
                        SetConsoleMode(StandardInputHandle, ConsoleMode);
                        break;
                    case VK_ESCAPE:
                        KeypressSound();
                        ClearConsole(0);
                        Menu(PreviousMenuID);
                        break;
                }
            }
        }
        if ((LastSettingID != CurrentSettingID) || Count == 0) {
            for (int i = 0; i < TotalSettings; i++) {
                if (i == CurrentSettingID - 1) {
                    SetCord(8, i * 3 + 16);
                    for (int j = 0; j <= 63; j++) {
                        if (j == 0) ColorOut(SettingsBoxTopLeft, 1);
                        else if (j == 63) ColorOut(SettingsBoxTopRight, 1);
                        else ColorOut(SettingsBoxTop, 1);
                    }
                    SetCord(8, i * 3 + 17);
                    ColorOut(SettingsBoxLeft, 1);
                    cout << " ";
                    ColorOut(SettingsListArray[i].Text, 1);
                    SetCord(42, i * 3 + 17);
                    cout << SettingsBoxSeparator << " ";
                    cout << SettingsValueInterpreter(SettingsListArray[i].SettingID,
                                                     SettingsObject.SettingValue[SettingsListArray[i].SettingID]);
                    SetCord(71, i * 3 + 17);
                    ColorOut(SettingsBoxRight, 1);
                    SetCord(8, i * 3 + 18);
                    for (int j = 0; j <= 63; j++) {
                        if (j == 0) ColorOut(SettingsBoxBottomLeft, 1);
                        else if (j == 63) ColorOut(SettingsBoxBottomRight, 1);
                        else ColorOut(SettingsBoxBottom, 1);
                    }
                }
                else {
                    SetCord(8, i * 3 + 16);
                    for (int j = 0; j <= 63; j++) {
                        if (j == 0) ColorOut(SettingsBoxTopLeft, 0);
                        else if (j == 63) ColorOut(SettingsBoxTopRight, 0);
                        else ColorOut(SettingsBoxTop, 0);
                    }
                    SetCord(8, i * 3 + 17);
                    cout << SettingsBoxLeft << " ";
                    cout << SettingsListArray[i].Text;
                    SetCord(42, i * 3 + 17);
                    cout << SettingsBoxSeparator << " ";
                    cout << SettingsValueInterpreter(SettingsListArray[i].SettingID,
                                                     SettingsObject.SettingValue[SettingsListArray[i].SettingID]);
                    SetCord(71, i * 3 + 17);
                    cout << SettingsBoxRight;
                    SetCord(8, i * 3 + 18);
                    for (int j = 0; j <= 63; j++) {
                        if (j == 0) ColorOut(SettingsBoxBottomLeft, 0);
                        else if (j == 63) ColorOut(SettingsBoxBottomRight, 0);
                        else ColorOut(SettingsBoxBottom, 0);
                    }
                }
                LastSettingID = CurrentSettingID;
            }
        }
        Count++;
    }
}

// The CurrencyOneToManyCalculate() is used for conversion of one currency to all the currencies this program support.

void CurrencyOneToManyCalculate() {
    input CurrencyOneToManyCalculateInput = {DoubleType, 0, 9, 38, 27, 13, 17, 53, 4, 1,
                                             CurrencyObject.CurrencyCode[IntegerVariable[0]]};
    int Count = 0;
    DWORD ConsoleMode;
    INPUT_RECORD InputEvent;
    BOOL Flag = TRUE;
    HANDLE StandardInputHandle = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(StandardInputHandle, &ConsoleMode);
    SetConsoleMode(StandardInputHandle, 0);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));                 // To flush the non-required previous data.
    while (Flag) {
        if ((WaitForSingleObject(StandardInputHandle, 0) == WAIT_OBJECT_0) && (Count != 0)) {
            DWORD ConsoleInputCount;
            ReadConsoleInput(StandardInputHandle, &InputEvent, 1, &ConsoleInputCount);
            if ((InputEvent.EventType == KEY_EVENT) && (InputEvent.Event.KeyEvent.bKeyDown)) {
                switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                    case VK_TAB:
                        SetConsoleMode(StandardInputHandle, ConsoleMode);
                        ClearConsole(0);
                        SetConsoleDimensions(DefaultConsoleWidth, DefaultConsoleHeight);
                        DefaultMainFrame();
                        CurrentAddress("Conversions ~ Currency ~ One to Many Conversion");
                        MainFrame();
                        FrameHeader(11, 10, 57, 0, "One to Many Conversion", 1);
                        PreviousMenuID = Currency_One_To_Many_Conversion_M;
                        StringOut(45, 13, 15, 53, 0, CurrencyObject.CurrencyCountry[IntegerVariable[0]]);
                        InputDataVariable(1, CurrencyOneToManyCalculateInput);
                        SetCord(13, 17);
                        cout << "Converting....";
                        ClearConsole(0);
                        Menu(Currency_One_To_Many_Conversion_Calculate_M);
                        break;
                    case VK_ESCAPE:
                        ClearConsole(0);
                        Menu(Currency_M);
                        break;
                }
            }
        }
        Count++;
    }
}

// The CalcResultGenerator() is used to generate the result of mathematical exp.

double CalcResultGenerator() {
    SetCord(2, 19);
    cout << "Calculating...";
    string CalcResultString, CompileCommand = MinGWPath;
    for (int i = 0; i < CalcCharCount; i++) {
        if (CalcStringGet[i] == '[') CalcStringGet[i] = '(';
        else if (CalcStringGet[i] == ']') CalcStringGet[i] = ')';
    }
    fstream CalcTempFile;
    cout << ".";
    CalcTempFile.open("CalcResultFile.cpp", ios::out);
    CalcTempFile << "#include<iostream>\n";
    CalcTempFile << "#include<fstream>\n";
    CalcTempFile << "#include<math.h>\n";
    CalcTempFile << "#include\"resources/calcmath.h\"\n";
    cout << ".";
    CalcTempFile << "using namespace std;\n";
    CalcTempFile << "int main(){\n";
    CalcTempFile << "fstream CalcResultFile(\"CalcResultFile.txt\",ios::out);\n";
    CalcTempFile << "double CalcResult = ";
    CalcTempFile << CalcStringGet.c_str();
    CalcTempFile << ";\n";
    cout << ".";
    CalcTempFile << "CalcResultFile<<CalcResult;\n";
    CalcTempFile << "CalcResultFile.close();\n";
    CalcTempFile << "return 0;\n";
    CalcTempFile << "}\n";
    CalcTempFile.close();
    cout << ".";
    system("@echo off");
    CompileCommand += " -o CalcResultFile CalcResultFile.cpp >nul 2>&1";
    system(CompileCommand.c_str());
    cout << ".";
    fstream CalcResultCheck;
    CalcResultCheck.open("CalcResultFile.exe", ios::in);
    if (CalcResultCheck.is_open()) {
        cout << ".";
        CalcResultCheck.close();
        system("CalcResultFile.exe");
        remove("CalcResultFile.exe");
        cout << ".";
        fstream CalcResultTempFile;
        CalcResultTempFile.open("CalcResultFile.txt", ios::in);
        cout << ".";
        CalcResultTempFile >> CalcResultString;
        CalcResultTempFile.close();
        remove("CalcResultFile.txt");
        cout << ".";
        ClearFrame(2, 19, 52, 3);
        SetCord(2, 19);
    } else {
        StringOut(57, 2, 19, 52, 0);
    }
    remove("CalcResultFile.cpp");
    CalcResultCheck.close();
    for (int i = 0; i < CalcCharCount; i++) {
        if (CalcStringGet[i] == '(') CalcStringGet[i] = '[';
        else if (CalcStringGet[i] == ')') CalcStringGet[i] = ']';
    }
    return atof(CalcResultString.c_str());
}

// The Calc() is used to generate the Calculator Layout and its Functions.

void Calc() {
    if (ErrorFlag == 1) ButtonFunctions(Main_Menu_M);
    PreviousMenuID = Main_Menu_M;
    CursorToggle(0);
    string CalcStringGetTemp = CalcStringGet;
    for (int i = 0; i < CalcCharCount; i++)if (CalcStringGetTemp[i] == 'P') CalcStringGetTemp[i] = 227;
    StringOut(CalcStringGetTemp, 2, 10, 52, 0);
    SetCord(1, 9);
    for (int j = 0; j <= 54; j++) {
        if (j == 0) ColorOut(CalcBoxTopLeft, 0);
        else if (j == 54) ColorOut(CalcBoxTopRight, 0);
        else ColorOut(CalcBoxTop, 0);
    }
    for (int i = 1; i < 8; i++) {
        SetCord(1, 9 + i);
        ColorOut(CalcBoxLeft, 0);
        SetCord(55, 9 + i);
        ColorOut(CalcBoxRight, 0);
    }
    SetCord(1, 17);
    for (int j = 0; j <= 54; j++) {
        if (j == 0) ColorOut(CalcBoxBottomLeft, 0);
        else if (j == 54) ColorOut(CalcBoxBottomRight, 0);
        else ColorOut(CalcBoxBottom, 0);
    }
    ClearFrame(58, 10, 21, 13);
    SetCord(57, 9);
    for (int j = 0; j <= 21; j++) {
        if (j == 0) ColorOut(CalcBoxTopLeft, 0);
        else if (j == 21) ColorOut(CalcBoxTopRight, 0);
        else ColorOut(CalcBoxTop, 0);
    }
    for (int i = 1; i < 14; i++) {
        SetCord(57, 9 + i);
        ColorOut(CalcBoxLeft, 0);
        SetCord(78, 9 + i);
        ColorOut(CalcBoxRight, 0);
    }
    SetCord(57, 23);
    for (int j = 0; j <= 21; j++) {
        if (j == 0) ColorOut(CalcBoxBottomLeft, 0);
        else if (j == 21) ColorOut(CalcBoxBottomRight, 0);
        else ColorOut(CalcBoxBottom, 0);
    }
    SetCord(1, 18);
    for (int j = 0; j <= 54; j++) {
        if (j == 0) ColorOut(CalcBoxTopLeft, 0);
        else if (j == 54) ColorOut(CalcBoxTopRight, 0);
        else ColorOut(CalcBoxTop, 0);
    }
    for (int i = 1; i < 6; i++) {
        SetCord(1, 18 + i);
        ColorOut(CalcBoxLeft, 0);
        SetCord(55, 18 + i);
        ColorOut(CalcBoxRight, 0);
    }
    SetCord(1, 23);
    for (int j = 0; j <= 54; j++) {
        if (j == 0) ColorOut(CalcBoxBottomLeft, 0);
        else if (j == 54) ColorOut(CalcBoxBottomRight, 0);
        else ColorOut(CalcBoxBottom, 0);
    }
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 13; j++) {
            SetCord(57 + i * 7, 9 + j);
            ColorOut(CalcBoxRight, 0);
        }
    }
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 20; j++) {
            SetCord(57 + j, 9 + (i - 1) * 2);
            ColorOut(CalcBoxBottom, 0);
        }
    }
    button CalcSideButtons1[7][ButtonsColumnLimit] =
            {
                    {
                            {1, 60, 10, "`227`",  Calc_Function_1},
                            {1, 67, 10, "EXP",         Calc_Function_2},
                            {1, 74, 10, "1/a",    Calc_Function_3},  {0}, {0}, {0}
                    },
                    {
                            {1, 60, 12, "e",      Calc_Function_4},
                            {1, 67, 12, "`252``251`a", Calc_Function_5},
                            {1, 74, 12, "a`252`", Calc_Function_6},  {0}, {0}, {0}
                    },
                    {
                            {1, 60, 14, "e`252`", Calc_Function_7},
                            {1, 67, 14, "log",         Calc_Function_8},
                            {1, 74, 14, "ln",     Calc_Function_9},  {0}, {0}, {0}
                    },
                    {
                            {1, 60, 16, "sin",    Calc_Function_10},
                            {1, 67, 16, "cos",         Calc_Function_11},
                            {1, 74, 16, "tan",    Calc_Function_12}, {0}, {0}, {0}
                    },
                    {
                            {1, 59, 18, "asin",   Calc_Function_13},
                            {1, 66, 18, "acos",        Calc_Function_14},
                            {1, 73, 18, "atan",   Calc_Function_15}, {0}, {0}, {0}
                    },
                    {
                            {1, 60, 20, "cot",    Calc_Function_16},
                            {1, 67, 20, "sec",         Calc_Function_17},
                            {1, 74, 20, "csc",    Calc_Function_18}, {0}, {0}, {0}
                    },
                    {
                            {1, 60, 22, "nCr",    Calc_Function_19},
                            {1, 67, 22, "nPr",         Calc_Function_20},
                            {1, 73, 22, "fact",   Calc_Function_21}, {0}, {0}, {0}
                    }
            };
    button CalcSideButtons2[4][ButtonsColumnLimit] =
            {
                    {
                            {1, 59, 10, "acot",  Calc_Function_22},
                            {1, 66, 10, "asec",  Calc_Function_23},
                            {1, 73, 10, "acsc",  Calc_Function_24}, {0}, {0}, {0}
                    },
                    {
                            {1, 59, 12, "sinh",  Calc_Function_25},
                            {1, 66, 12, "cosh",  Calc_Function_26},
                            {1, 73, 12, "tanh",  Calc_Function_27}, {0}, {0}, {0}
                    },
                    {
                            {1, 59, 14, "asinh", Calc_Function_28},
                            {1, 66, 14, "acosh", Calc_Function_29},
                            {1, 73, 14, "atanh", Calc_Function_30}, {0}, {0}, {0}
                    },
                    {
                            {1, 59, 16, "acsch", Calc_Function_31},
                            {1, 66, 16, "asech", Calc_Function_32},
                            {1, 73, 16, "acoth", Calc_Function_33}, {0}, {0}, {0}
                    }
            };
    int DefaultButtonID[2] = {0, 0};
    switch (CalcCurrentSideMenu) {
        case 1:
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < ButtonsColumnLimit; j++) {
                    if (CalcSideButtons1[i][j].Status) {
                        string ButtonString = CalcSideButtons1[i][j].Text;
                        StringInterpret(ButtonString, 1);
                        SetCord(CalcSideButtons1[i][j].x, CalcSideButtons1[i][j].y);
                        ColorOut(ButtonString, 3);
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < ButtonsColumnLimit; j++) {
                    if (CalcSideButtons2[i][j].Status) {
                        string ButtonString = CalcSideButtons2[i][j].Text;
                        StringInterpret(ButtonString, 1);
                        SetCord(CalcSideButtons2[i][j].x, CalcSideButtons2[i][j].y);
                        ColorOut(ButtonString, 3);
                    }
                }
            }
            break;
    }
    SetCord(2, 10);
    SetCord(2 + CalcCharCount - (53 * (CalcLineCount)), 10 + CalcLineCount);
    CursorToggle(1);
    int Count = 0;
    CalcInputLabel:
    DWORD ConsoleMode;
    INPUT_RECORD InputEvent;
    BOOL Flag = TRUE;
    HANDLE StandardInputHandle = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(StandardInputHandle, &ConsoleMode);
    SetConsoleMode(StandardInputHandle, 0);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));                 // To flush the non-required previous data.
    while (Flag) {
        if ((WaitForSingleObject(StandardInputHandle, 0) == WAIT_OBJECT_0) && (Count != 0)) {
            DWORD ConsoleInputCount;
            ReadConsoleInput(StandardInputHandle, &InputEvent, 1, &ConsoleInputCount);
            if ((InputEvent.EventType == KEY_EVENT) && (InputEvent.Event.KeyEvent.bKeyDown)) {
                if (CalcCharCount > (52 * (CalcLineCount + 1) + CalcLineCount)) {
                    CalcLineCount++;
                    SetCord(2, 10 + CalcLineCount);
                }
                if (CalcLineCount > 6) {
                    SetCord(54, 16);
                    switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                        case VK_BACK:
                            CalcCharCount--;
                            if (CalcCharCount < (52 * CalcLineCount + CalcLineCount)) CalcLineCount--;
                            if (CalcCharCount >= 0) {
                                SetCord(2 + CalcCharCount - (53 * (CalcLineCount)), 10 + CalcLineCount);
                                cout << " ";
                                CalcStringGet.erase(CalcStringGet.end() - 1);
                            } else CalcCharCount++;
                            if (CalcCharCount == 0) SetCord(2, 10);
                            else SetCord(2 + CalcCharCount - (53 * (CalcLineCount)), 10 + CalcLineCount);
                            break;
                        case VK_DELETE:
                            ClearFrame(2, 10, 52, 6);
                            CalcStringGet.erase(CalcStringGet.begin(), CalcStringGet.end());
                            CalcCharCount = 0;
                            CalcLineCount = 0;
                            break;
                        case VK_ESCAPE:
                            CursorToggle(0);
                            ClearConsole(0);
                            Menu(PreviousMenuID);
                            break;
                        case VK_RETURN:
                            ClearFrame(2, 19, 52, 3);
                            SetCord(2, 19);
                            if (CalcResultGenerator()) cout << CalcResultGenerator();
                            Calc();
                            break;
                        default:
                            KeypressSound();
                            break;
                    }
                    goto CalcInputLabel;
                }
                switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                    case VK_RETURN:
                        ClearFrame(2, 19, 52, 3);
                        SetCord(2, 19);
                        if (CalcResultGenerator()) cout << CalcResultGenerator();
                        Calc();
                        break;
                    case VK_INSERT:
                        ClearFrame(2, 19, 52, 3);
                        switch (CalcCurrentSideMenu) {
                            case 1:
                                CreateButtons(CalcSideButtons1, 7, DefaultButtonID, 3);
                                break;
                            case 2:
                                CreateButtons(CalcSideButtons2, 4, DefaultButtonID, 3);
                                break;
                        }
                        SetCord(2 + CalcCharCount - (53 * (CalcLineCount)), 10 + CalcLineCount);
                        break;
                    case VK_PRIOR:
                        if (CalcCurrentSideMenu < 2) CalcCurrentSideMenu++;
                        else CalcCurrentSideMenu = 1;
                        Calc();
                        break;
                    case VK_NEXT:
                        if (CalcCurrentSideMenu > 1) CalcCurrentSideMenu--;
                        else CalcCurrentSideMenu = 2;
                        Calc();
                        break;
                    case VK_BACK:
                        CalcCharCount--;
                        if (CalcCharCount < (52 * CalcLineCount + CalcLineCount)) CalcLineCount--;
                        if (CalcCharCount >= 0) {
                            SetCord(2 + CalcCharCount - (53 * (CalcLineCount)), 10 + CalcLineCount);
                            cout << " ";
                            CalcStringGet.erase(CalcStringGet.end() - 1);
                        } else CalcCharCount++;
                        if (CalcCharCount == 0) SetCord(2, 10);
                        else SetCord(2 + CalcCharCount - (53 * (CalcLineCount)), 10 + CalcLineCount);
                        break;
                    case VK_DELETE:
                        ClearFrame(2, 10, 52, 6);
                        CalcStringGet.erase(CalcStringGet.begin(), CalcStringGet.end());
                        CalcCharCount = 0;
                        CalcLineCount = 0;
                        break;
                    case VK_ESCAPE:
                        CursorToggle(0);
                        ClearConsole(0);
                        Menu(PreviousMenuID);
                        break;
                    case 0xDB:
                        cout << "[";
                        CalcStringGet += "[";
                        CalcCharCount++;
                        break;
                    case 0xDD:
                        cout << "]";
                        CalcStringGet += "]";
                        CalcCharCount++;
                        break;
                    case 0x6A:
                        cout << "*";
                        CalcStringGet += "*";
                        CalcCharCount++;
                        break;
                    case 0xBB:
                    case 0x6B:
                        cout << "+";
                        CalcStringGet += "+";
                        CalcCharCount++;
                        break;
                    case 0xBD:
                    case VK_SUBTRACT:
                        cout << "-";
                        CalcStringGet += "-";
                        CalcCharCount++;
                        break;
                    case 0x6E:
                    case 0xBE:
                        cout << ".";
                        CalcStringGet += ".";
                        CalcCharCount++;
                        break;
                    case 0x6F:
                    case 0xBF:
                        cout << "/";
                        CalcStringGet += "/";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD0:
                    case 0x30:
                        cout << "0";
                        CalcStringGet += "0";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD1:
                    case 0x31:
                        cout << "1";
                        CalcStringGet += "1";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD2:
                    case 0x32:
                        cout << "2";
                        CalcStringGet += "2";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD3:
                    case 0x33:
                        cout << "3";
                        CalcStringGet += "3";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD4:
                    case 0x34:
                        cout << "4";
                        CalcStringGet += "4";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD5:
                    case 0x35:
                        cout << "5";
                        CalcStringGet += "5";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD6:
                    case 0x36:
                        cout << "6";
                        CalcStringGet += "6";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD7:
                    case 0x37:
                        cout << "7";
                        CalcStringGet += "7";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD8:
                    case 0x38:
                        cout << "8";
                        CalcStringGet += "8";
                        CalcCharCount++;
                        break;
                    case VK_NUMPAD9:
                    case 0x39:
                        cout << "9";
                        CalcStringGet += "9";
                        CalcCharCount++;
                        break;
                    case 'A':
                        cout << "a";
                        CalcStringGet += "a";
                        CalcCharCount++;
                        break;
                    case 'B':
                        cout << "b";
                        CalcStringGet += "b";
                        CalcCharCount++;
                        break;
                    case 'C':
                        cout << "c";
                        CalcStringGet += "c";
                        CalcCharCount++;
                        break;
                    case 'D':
                        cout << "d";
                        CalcStringGet += "d";
                        CalcCharCount++;
                        break;
                    case 'E':
                        cout << "e";
                        CalcStringGet += "e";
                        CalcCharCount++;
                        break;
                    case 'F':
                        cout << "f";
                        CalcStringGet += "f";
                        CalcCharCount++;
                        break;
                    case 'G':
                        cout << "g";
                        CalcStringGet += "g";
                        CalcCharCount++;
                        break;
                    case 'H':
                        cout << "h";
                        CalcStringGet += "h";
                        CalcCharCount++;
                        break;
                    case 'I':
                        cout << "i";
                        CalcStringGet += "i";
                        CalcCharCount++;
                        break;
                    case 'J':
                        cout << "j";
                        CalcStringGet += "j";
                        CalcCharCount++;
                        break;
                    case 'K':
                        cout << "k";
                        CalcStringGet += "k";
                        CalcCharCount++;
                        break;
                    case 'L':
                        cout << "l";
                        CalcStringGet += "l";
                        CalcCharCount++;
                        break;
                    case 'M':
                        cout << "m";
                        CalcStringGet += "m";
                        CalcCharCount++;
                        break;
                    case 'N':
                        cout << "n";
                        CalcStringGet += "n";
                        CalcCharCount++;
                        break;
                    case 'O':
                        cout << "o";
                        CalcStringGet += "o";
                        CalcCharCount++;
                        break;
                    case 'P':
                        cout << "p";
                        CalcStringGet += "p";
                        CalcCharCount++;
                        break;
                    case 'Q':
                        cout << "q";
                        CalcStringGet += "q";
                        CalcCharCount++;
                        break;
                    case 'R':
                        cout << "r";
                        CalcStringGet += "r";
                        CalcCharCount++;
                        break;
                    case 'S':
                        cout << "s";
                        CalcStringGet += "s";
                        CalcCharCount++;
                        break;
                    case 'T':
                        cout << "t";
                        CalcStringGet += "t";
                        CalcCharCount++;
                        break;
                    case 'U':
                        cout << "u";
                        CalcStringGet += "u";
                        CalcCharCount++;
                        break;
                    case 'V':
                        cout << "v";
                        CalcStringGet += "v";
                        CalcCharCount++;
                        break;
                    case 'W':
                        cout << "w";
                        CalcStringGet += "w";
                        CalcCharCount++;
                        break;
                    case 'X':
                        cout << "x";
                        CalcStringGet += "x";
                        CalcCharCount++;
                        break;
                    case 'Y':
                        cout << "y";
                        CalcStringGet += "y";
                        CalcCharCount++;
                        break;
                    case 'Z':
                        cout << "z";
                        CalcStringGet += "z";
                        CalcCharCount++;
                        break;
                }
            }
        }
        Count++;
    }
    CursorToggle(0);
}

// The Menu(int) is used for displaying or creating the main menu of the program.

void Menu(int MenuID) {
    CurrentMenuID = MenuID;
    // Initializing Default values for MAINFRAME() funcion psuedo arguements.
    DefaultMainFrame();
    SetConsoleDimensions(DefaultConsoleWidth, DefaultConsoleHeight);
    if ((MusicID != 0) && (BackgroundMusicExecutedCount <= 0)) {
        BackgroundMusicFlag = 1;
        BackgroundMusicID = MusicID;
        BackgroundMusicEndFlag = 0;
        _beginthread(BackgroundMusic, 0,
                     (void *) &Temp);                            // Applying multi-threading concept to thread multiple processes at once.
        BackgroundMusicExecutedCount++;
    }

    button ON_ERROR_BUTTONS[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", ErrorDownloadYes},
                            {1, 44, 22, "No", Main_Menu_B_F}, {0}, {0}, {0}, {0}
                    }
            };

    // Main Menu
    button MAIN_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "Geometrical Calculations", Geometrical_Calculations_B_F},
                            {1, 51, 16, "Equation Solving", Equation_Solving_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Calc",                     Calc_B_F},
                            {1, 51, 18, "Conversions",      Conversions_B_F},      {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Settings",                 Settings_B_F},
                            {1, 51, 20, "Exit",             Exit_B_F},             {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "Triangles", Triangles_B_F},
                            {1, 50, 16, "Quadrilateral", Quadrilateral_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Pentagon",  Pentagon_B_F},
                            {1, 50, 18, "Hexagon",       Hexagon_B_F},       {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",      Back_B_F},
                            {1, 50, 20, "Exit",          Exit_B_F},          {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "About Triangles",        About_Triangles_B_F},
                                                                                               {1, 45, 16, "Area of Triangles", Area_of_Triangles_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Perimeter of Triangles", Perimeter_of_Triangles_B_F}, {0},                                                     {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                   Back_B_F},
                                                                                               {1, 45, 20, "Exit",              Exit_B_F},              {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_AREA_OF_TRIANGLES_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "For Scalene Triangle",   For_Scalene_Triangle_B_F},
                                                                                               {1, 43, 16, "For Equilateral Triangle", For_Equilateral_Triangle_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "For Isosceles Triangle", For_Isosceles_Triangle_B_F}, {0},                                                                   {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                   Back_B_F},
                                                                                               {1, 43, 20, "Exit",                     Exit_B_F},                     {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_AREA_OF_TRIANGLES_EQUILATERAL_TRIANGLE_TRANSFER_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", For_Equilateral_Triangle_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_AREA_OF_TRIANGLES_ISOSCELES_TRIANGLE_TRANSFER_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", For_Isosceles_Triangle_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_AREA_OF_TRIANGLES_SCALENE_TRIANGLE_TRANSFER_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", For_Scalene_Triangle_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_INVALID_TRIANGLE_ADVICE_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", About_Triangles_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button RE_CALCULATE_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", Re_Calculate_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_PERIMETER_OF_TRIANGLES_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 17, "For Scalene Triangle",   For_Scalene_Triangle_Perimeter_B_F},
                                                                                                         {1, 43, 17, "For Equilateral Triangle", For_Equilateral_Triangle_Perimeter_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 19, "For Isosceles Triangle", For_Isosceles_Triangle_Perimeter_B_F}, {0},                                                                             {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 21, "Back",                   Back_B_F},
                                                                                                         {1, 43, 21, "Exit",                     Exit_B_F},                               {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_PERIMETER_OF_TRIANGLES_EQUILATERAL_TRIANGLE_TRANSFER_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", For_Equilateral_Triangle_Perimeter_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_PERIMETER_OF_TRIANGLES_ISOSCELES_TRIANGLE_TRANSFER_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", For_Isosceles_Triangle_Perimeter_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_PERIMETER_OF_TRIANGLES_SCALENE_TRIANGLE_TRANSFER_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", For_Scalene_Triangle_Perimeter_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_QUADRILATERAL_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "About Quadrilaterals",        About_Quadrilateral_B_F},
                                                                                                        {1, 45, 16, "Area of Quadrilaterals", Area_of_Quadrilateral_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Perimeter of Quadrilaterals", Perimeter_of_Quadrilateral_B_F}, {0},                                                              {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                        Back_B_F},
                                                                                                        {1, 45, 20, "Exit",                   Exit_B_F},                  {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_QUADRILATERAL_AREA_OF_QUADRILATERAL_MENU_BUTTON[5][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 17, "K = `171`[pq.sin(`224`)]",                                                          Area_of_Quadrilateral_Formula_1_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 19, "K = `251`[(s-a)(s-b)(s-c)(s-d)-`171`{abcd(1+cos(A+C))}]",                           Area_of_Quadrilateral_Formula_2_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 21, "K = `171`[ad.sin(A)]+`171`[bc.sin(C)]",                                             Area_of_Quadrilateral_Formula_3_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 23, "K = `172`{`251`[(2(a`253`+c`253`)-4x`253`)(2(b`253`+d`253`)-4x`253`)]}.sin(`237`)", Area_of_Quadrilateral_Formula_4_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 25, "Back",                                                                              Back_B_F},
                                                                                                                                                                   {1, 60, 25, "Exit", Exit_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_PENTAGON_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "About Pentagons",        About_Pentagon_B_F},
                                                                                              {1, 45, 16, "Area of Pentagons", Area_of_Pentagon_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Perimeter of Pentagons", Perimeter_of_Pentagon_B_F}, {0},                                                    {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                   Back_B_F},
                                                                                              {1, 45, 20, "Exit",              Exit_B_F},             {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_HEXAGON_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "About Hexagons",        About_Hexagon_B_F},
                                                                                            {1, 45, 16, "Area of Hexagons", Area_of_Hexagon_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Perimeter of Hexagons", Perimeter_of_Hexagon_B_F}, {0},                                                  {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                  Back_B_F},
                                                                                            {1, 45, 20, "Exit",             Exit_B_F},            {0}, {0}, {0}, {0}
                    }
            };
    button TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_HEXAGON_AREA_OF_HEXAGON_MENU_BUTTON[5][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 17, "A `247` (2.598076211)t`253`", Area_of_Hexagon_Formula_1_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 19, "A `247` (0.866025404)d`253`", Area_of_Hexagon_Formula_2_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 21, "A = (ap)/2",                  Area_of_Hexagon_Formula_3_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 23, "A `247` (3.464102)a`253`",    Area_of_Hexagon_Formula_4_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 25, "Back",                        Back_B_F},
                                                                                                       {1, 60, 25, "Exit", Exit_B_F}, {0}, {0}, {0}, {0}
                    }
            };


    input Triangle_Perimeter_Area_Input_1 = {DoubleType, 0, 9, 4, 27, 13, 18, 52, 2, 0, "metre"};
    input Triangle_Perimeter_Area_Input_2 = {DoubleType, 1, 9, 5, 27, 13, 18, 52, 2, 0, "metre"};
    input Triangle_Perimeter_Area_Input_3 = {DoubleType, 2, 9, 6, 27, 13, 18, 52, 2, 0, "metre"};
    input Triangle_Perimeter_Area_Input_1_Equitorial = {DoubleType, 0, 9, 18, 27, 13, 18, 52, 2, 0, "metre"};
    input Triangle_Perimeter_Area_Input_1_Isoceles = {DoubleType, 0, 9, 18, 27, 13, 18, 52, 2, 0, "metre"};
    input Triangle_Perimeter_Area_Input_3_Isoceles = {DoubleType, 2, 9, 19, 27, 13, 18, 52, 2, 0, "metre"};

    input Area_of_Quadrilateral_Formula_1_Input_1 = {DoubleType, 0, 9, 59, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Quadrilateral_Formula_1_Input_2 = {DoubleType, 1, 9, 60, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Quadrilateral_Formula_1_Input_3 = {DoubleType, 2, 9, 61, 63, 13, 20, 52, 2, 0, ""};

    input Area_of_Quadrilateral_Formula_2_3_4_Input_1 = {DoubleType, 0, 9, 66, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Quadrilateral_Formula_2_3_4_Input_2 = {DoubleType, 1, 9, 67, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Quadrilateral_Formula_2_3_4_Input_3 = {DoubleType, 2, 9, 68, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Quadrilateral_Formula_2_3_4_Input_4 = {DoubleType, 3, 9, 69, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Quadrilateral_Formula_2_3_Input_5 = {DoubleType, 4, 9, 70, 63, 13, 20, 52, 2, 0, ""};
    input Area_of_Quadrilateral_Formula_2_3_Input_6 = {DoubleType, 5, 9, 71, 63, 13, 20, 52, 2, 0, ""};

    input Area_of_Quadrilateral_Formula_4_Input_5 = {DoubleType, 4, 9, 75, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Quadrilateral_Formula_4_Input_6 = {DoubleType, 5, 9, 73, 63, 13, 20, 52, 2, 0, ""};

    input Area_of_Pentagon_Hexagon_Formula_Input = {DoubleType, 0, 9, 113, 27, 13, 20, 52, 2, 0, "metre"};

    input Area_of_Hexagon_Formula_2_Input = {DoubleType, 0, 9, 127, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Hexagon_Formula_3_Input_1 = {DoubleType, 0, 9, 128, 27, 13, 20, 52, 2, 0, "metre"};
    input Area_of_Hexagon_Formula_3_Input_2 = {DoubleType, 1, 9, 129, 27, 13, 20, 52, 2, 0, "metre"};


    input Polygon_Side_Input_1 = {DoubleType, 0, 9, 114, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_2 = {DoubleType, 1, 9, 115, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_3 = {DoubleType, 2, 9, 116, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_4 = {DoubleType, 3, 9, 117, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_5 = {DoubleType, 4, 9, 118, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_6 = {DoubleType, 5, 9, 119, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_7 = {DoubleType, 6, 9, 120, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_8 = {DoubleType, 7, 9, 121, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_9 = {DoubleType, 8, 9, 122, 27, 13, 19, 52, 2, 0, "metre"};
    input Polygon_Side_Input_10 = {DoubleType, 9, 9, 123, 27, 13, 19, 52, 2, 0, "metre"};

    // Equation Solving
    button EQUATION_SOLVING_MENU_BUTTON[][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "Linear Equation",    Linear_Equation_B_F},    {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Quadratic Equation", Quadratic_Equation_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",               Back_B_F},
                                                                                       {1, 45, 20, "Exit", Exit_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button EQUATION_SOLVING_LINEAR_EQUATION_MENU_BUTTON[][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "About Linear Equation", About_Linear_Equation_B_F},
                                                                                                       {1, 45, 16, "Two Variables Equation", Solve_Linear_Equation_Two_Variable_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "System Of Equation",    Solve_System_Of_Linear_Equation_B_F}, {0},                                                                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                  Back_B_F},
                                                                                                       {1, 45, 20, "Exit",                   Exit_B_F},                               {0}, {0}, {0}, {0}
                    }
            };
    button EQUATION_SOLVING_QUADRATIC_EQUATION_MENU_BUTTON[][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "About Quadratic Equation", About_Quadratic_Equation_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Solve Quadratic Equation", Solve_Quadratic_Equation_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                     Back_B_F},
                                                                                                   {1, 45, 20, "Exit", Exit_B_F}, {0}, {0}, {0}, {0}
                    }
            };

    input Solve_Linear_Equation_Two_Variable_Input_1 = {DoubleType, 0, 9, 85, 0, 13, 19, 52, 2, 0, ""};
    input Solve_Linear_Equation_Two_Variable_Input_2 = {DoubleType, 1, 9, 86, 0, 13, 19, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_1_1 = {DoubleType, 0, 9, 101, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_1_2 = {DoubleType, 1, 9, 102, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_1_3 = {DoubleType, 2, 9, 103, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_1_4 = {DoubleType, 3, 9, 104, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_2_1 = {DoubleType, 4, 9, 101, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_2_2 = {DoubleType, 5, 9, 102, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_2_3 = {DoubleType, 6, 9, 103, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_2_4 = {DoubleType, 7, 9, 104, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_3_1 = {DoubleType, 8, 9, 101, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_3_2 = {DoubleType, 9, 9, 102, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_3_3 = {DoubleType, 10, 9, 103, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Linear_Equation_Three_Variable_Input_3_4 = {DoubleType, 11, 9, 104, 0, 13, 21, 52, 2, 0, ""};
    input Solve_Quadratic_Equation_Input_1 = {DoubleType, 0, 9, 92, 0, 13, 19, 52, 2, 0, ""};
    input Solve_Quadratic_Equation_Input_2 = {DoubleType, 1, 9, 93, 0, 13, 19, 52, 2, 0, ""};
    input Solve_Quadratic_Equation_Input_3 = {DoubleType, 2, 9, 94, 0, 13, 19, 52, 2, 0, ""};

    button ABOUT_JUMP_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", About_Jump_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };

    // Conversions
    button CONVERSIONS_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "Currency",                       Currency_B_F},
                                                                                                               {1, 53, 16, "Units", Units_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Update Currency Exchange Rates", Update_Currency_Exchange_Rates_B_F}, {0},                             {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                           Back_B_F},
                                                                                                               {1, 53, 20, "Exit",  Exit_B_F},  {0}, {0}, {0}, {0}
                    }
            };
    button CONVERSIONS_CURRENCY_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 17, "One to One Conversion", Currency_One_To_One_Conversion_B_F},  {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 19, "One to All Conversion", Currency_One_To_Many_Conversion_B_F}, {0},                           {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 21, "Back",                  Back_B_F},
                                                                                                       {1, 53, 21, "Exit", Exit_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button CONVERSIONS_UPDATE_CURRENCY_EXCHANGE_RATES_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "",                     Continue_From_Last_Point_B_F},
                                                                                           {1, 48, 16, "View Update History", View_Update_History_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Restart The Updation", Restart_The_Updation_B_F}, {0},                                                         {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",                 Back_B_F},
                                                                                           {1, 48, 20, "Exit",                Exit_B_F},                {0}, {0}, {0}, {0}
                    }
            };
    if (SettingsObject.SettingValue[3] > 0)
        CONVERSIONS_UPDATE_CURRENCY_EXCHANGE_RATES_MENU_BUTTON[0][0].Text = "Continue From Last Point";
    else CONVERSIONS_UPDATE_CURRENCY_EXCHANGE_RATES_MENU_BUTTON[0][0].Text = "Start Updation";
    button CURRENY_ONE_TO_ONE_CONVERSION_RE_BUTTONS[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 22, "Yes", Re_Calculate_B_F},
                            {1, 44, 22, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button CONVERSIONS_UNITS_MENU_BUTTON[5][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "Temperature", Temperature_B_F},
                            {1, 30, 16, "Length", Length_B_F},
                                                             {1, 44, 16, "Mass",  Mass_B_F},
                                                                  {1, 56, 16, "Speed",        Speed_B_F},        {0}, {0}
                    },
                    {
                            {1, 13, 18, "Volume",      Volume_B_F},
                            {1, 30, 18, "Area",   Area_B_F},
                                                             {1, 44, 18, "Time",  Time_B_F},
                                                                  {1, 56, 18, "Data Storage", Data_Storage_B_F}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Pressure",    Pressure_B_F},
                            {1, 30, 20, "Power",  Power_B_F},
                                                             {1, 44, 20, "Angle", Angle_B_F},
                                                                  {1, 56, 20, "Acceleration", Acceleration_B_F}, {0}, {0}
                    },
                    {
                            {1, 13, 22, "Density",     Density_B_F},
                            {1, 30, 22, "Energy", Energy_B_F},
                                                             {1, 44, 22, "Force", Force_B_F},
                                                                  {1, 56, 22, "Torque",       Torque_B_F},       {0}, {0}
                    },
                    {
                            {1, 13, 24, "Back",        Back_B_F},
                            {1, 30, 24, "Exit",   Exit_B_F}, {0}, {0},                                           {0}, {0}
                    }
            };
    button CONVERSIONS_UNITS_RE_BUTTONS[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 26, "Yes", Re_Calculate_B_F},
                            {1, 44, 26, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button RE_CALCULATE_BUTTON_SOLVE_LINEAR_EQUATION[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 29, "Yes", Re_Calculate_B_F},
                            {1, 44, 29, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };
    button RE_CALCULATE_BUTTON_SOLVE_LINEAR_EQUATION_SYSTEM[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 32, "Yes", Re_Calculate_B_F},
                            {1, 44, 32, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };

    scrolllist ScrollListUnitsTemperature[6] =
            {
                    {1, "Kelvin[K]",          Temperature_Kelvin,     ""},
                    {1, "Celsius[`248`C]",    Temperature_Celsius,    ""},
                    {1, "Fahrenheit[`248`F]", Temperature_Fahrenheit, ""},
                    {1, "Rankine[`248`R]",    Temperature_Rankine,    ""},
                    {1, "Reaumur[`248`r]",    Temperature_Reaumur,    ""},
                    {1, "Newton[`248`N]",     Temperature_Newton,     ""}
            };

    scrolllist ScrollListUnitsLength[Length_No];
    scrolllist ScrollListUnitsMass[Mass_No];
    scrolllist ScrollListUnitsSpeed[Speed_No];

    input UnitsInput = {DoubleType, 0, 9, 79, 0, 13, 21, 52, 2, 0, ""};

    // Settings
    button SETTINGS_MENU_BUTTON[3][ButtonsColumnLimit] =
            {
                    {
                            {1, 13, 16, "Update Settings", Update_Settings_B_F},
                                                                                {1, 53, 16, "Play Intro", Play_Intro_B_F}, {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 18, "Reset Settings",  Reset_Settings_B_F}, {0},                                       {0}, {0}, {0}, {0}
                    },
                    {
                            {1, 13, 20, "Back",            Back_B_F},
                                                                                {1, 53, 20, "Exit",       Exit_B_F},       {0}, {0}, {0}, {0}
                    }
            };
    button SETTINGS_RESET_SETTINGS_MENU_BUTTON[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 34, 18, "Yes", Reset_Settings_Yes_B_F},
                            {1, 44, 18, "No", Back_B_F}, {0}, {0}, {0}, {0}
                    }
            };

    const int CURRENCY_COUNTRY_SELECT_LIST_ROWS = (NumberOfCurrencies / 3);
    button CURRENCY_COUNTRY_SELECT_LIST_BUTTON[CURRENCY_COUNTRY_SELECT_LIST_ROWS][ButtonsColumnLimit];

    int k = 0;
    for (int i = 0; i < CURRENCY_COUNTRY_SELECT_LIST_ROWS; i++) {
        for (int j = 0; j < ButtonsColumnLimit; j++) {
            if ((k < NumberOfCurrencies) && (j <= 2)) {
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].Status = 1;
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].x = 13 + j * 22;
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].y = 18 + i * 2;
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].Text = CurrencyObject.CurrencyCountry[k];
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].FunctionCallID = k;
                k++;
            }
            else {
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].Status = 0;
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].x = 0;
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].y = 0;
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].Text = "";
                CURRENCY_COUNTRY_SELECT_LIST_BUTTON[i][j].FunctionCallID = 0;
            }
        }
    }

    input CurrencyConversionInput = {DoubleType, 0, 9, 38, 0, 13, 17, 52, 2, 0,
                                     CurrencyObject.CurrencyCode[IntegerVariable[0]]};

    int DefaultButtonID[2] = {0, 0};

    switch (MenuID) {

        // On Error
        case ERROR_M:
            DefaultMainFrame();
            CurrentAddress("Error");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Error - MinGW not installed!", 1);
            StringOut(157, 12, 15, 56, 1);
            CreateButtons(ON_ERROR_BUTTONS, 1, DefaultButtonID);
            break;

            // Main Menu
        case Main_Menu_M:
            DefaultMainFrame();
            CurrentAddress("Home");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Main Menu", 1);
            CreateButtons(MAIN_MENU_BUTTON, 3, DefaultButtonID);
            break;

            // Geometrical Calculations
        case Geometrical_Calculations_M:
            DefaultMainFrame();
            CurrentAddress("Geometrical Calculations");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Geometrical Calculations", 1);
            PreviousMenuID = Main_Menu_M;
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Triangles_M:
            CurrentAddress("Geometrical Calculations ~ Triangles");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Triangles", 1);
            PreviousMenuID = Geometrical_Calculations_M;
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case About_Triangles_M:
            PreviousMenuID = Triangles_M;
            About("TRIANGLE", 9, 1, "Geometrical Calculations ~ Triangles ~ About Triangles");
            break;
        case Area_of_Triangles_M:
            CurrentAddress("Geometrical Calculations ~ Triangles ~ Area of Triangles");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area of Triangles", 1);
            PreviousMenuID = Triangles_M;
            EmptyVariable(1, 0, 2);
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_AREA_OF_TRIANGLES_MENU_BUTTON, 3,
                          DefaultButtonID);
            break;
        case For_Scalene_Triangle_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Triangles ~ Area of Triangles ~ For Scalene Triangle");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Area of Scalene Triangle", 1);
            PreviousMenuID = Area_of_Triangles_M;
            PreviousCalculationID = For_Scalene_Triangle_M;
            StringOut(20, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 2)) {
                InputDataVariable(2, Triangle_Perimeter_Area_Input_1);
                InputDataVariable(2, Triangle_Perimeter_Area_Input_2);
                InputDataVariable(2, Triangle_Perimeter_Area_Input_3);
            }
            if (Calculate(101)) {
                if (Calculate(102) == 3) {
                    StringOut(12, 13, 16, 53, 0, "Scalene Triangle");
                    SetCord(13, 18);
                    cout << Calculate(1) << " square " << DefaultCalculationUnitName << "metre(s).";
                }
                else if (Calculate(102) == 2) {
                    StringOut(14, 13, 16, 53, 0, "Scalene");
                    StringOut(15, 13, 18, 53, 1, "Area");
                    CreateButtons(
                            TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_AREA_OF_TRIANGLES_ISOSCELES_TRIANGLE_TRANSFER_BUTTON,
                            1, DefaultButtonID);
                }
                else {
                    StringOut(14, 13, 16, 53, 0, "Scalene");
                    StringOut(16, 13, 18, 53, 1, "Area");
                    CreateButtons(
                            TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_AREA_OF_TRIANGLES_EQUILATERAL_TRIANGLE_TRANSFER_BUTTON,
                            1, DefaultButtonID);
                }
            }
            else {
                StringOut(13, 13, 16, 53, 0);
                StringOut(17, 13, 19, 53, 1, "Triangles");
                CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_INVALID_TRIANGLE_ADVICE_BUTTON, 1,
                              DefaultButtonID);
            }
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case For_Equilateral_Triangle_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Triangles ~ Area of Triangles ~ For Equilateral Triangle");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Area of Equilateral Triangle", 1);
            PreviousMenuID = Area_of_Triangles_M;
            PreviousCalculationID = For_Equilateral_Triangle_M;
            StringOut(20, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 0)) {
                InputDataVariable(2, Triangle_Perimeter_Area_Input_1);
            }
            StringOut(12, 13, 16, 53, 0, "Equilateral Triangle");
            SetCord(13, 18);
            cout << Calculate(2) << " square " << DefaultCalculationUnitName << "metre(s).";
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case For_Isosceles_Triangle_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Triangles ~ Area of Triangles ~ For Isosceles Triangle");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Area of Isosceles Triangle", 1);
            PreviousMenuID = Area_of_Triangles_M;
            PreviousCalculationID = For_Isosceles_Triangle_M;
            StringOut(20, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 0)) {
                InputDataVariable(2, Triangle_Perimeter_Area_Input_1);
                DoubleVariable[1] = DoubleVariable[0];
            }
            if (VariableIsEmpty(1, 2, 2)) {
                InputDataVariable(2, Triangle_Perimeter_Area_Input_3);
            }
            if (Calculate(101)) {
                if (Calculate(102) == 2) {
                    StringOut(12, 13, 16, 53, 0, "Isosceles Triangle");
                    SetCord(13, 18);
                    cout << Calculate(3) << " square " << DefaultCalculationUnitName << "metre(s).";
                }
                else {
                    StringOut(14, 13, 16, 53, 0, "Isosceles");
                    StringOut(16, 13, 18, 53, 1, "Area");
                    CreateButtons(
                            TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_AREA_OF_TRIANGLES_EQUILATERAL_TRIANGLE_TRANSFER_BUTTON,
                            1, DefaultButtonID);
                }
            }
            else {
                StringOut(13, 13, 16, 53, 0);
                StringOut(17, 13, 19, 53, 1, "Triangles");
                CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_INVALID_TRIANGLE_ADVICE_BUTTON, 1,
                              DefaultButtonID);
            }
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case Perimeter_of_Triangles_M:
            CurrentAddress("Geometrical Calculations ~ Triangles ~ Perimeter of Triangles");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Perimeter of Triangles", 1);
            PreviousMenuID = Triangles_M;
            EmptyVariable(1, 0, 2);
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_PERIMETER_OF_TRIANGLES_MENU_BUTTON, 3,
                          DefaultButtonID);
            break;
        case For_Scalene_Triangle_Perimeter_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Triangles ~ Perimeter of Triangles ~ For Scalene Triangle");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Perimeter of Scalene Triangle", 1);
            PreviousMenuID = Perimeter_of_Triangles_M;
            EmptyVariable(1, 0, 2);
            PreviousCalculationID = For_Scalene_Triangle_Perimeter_M;
            StringOut(20, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 2)) {
                InputDataVariable(2, Triangle_Perimeter_Area_Input_1);
                InputDataVariable(2, Triangle_Perimeter_Area_Input_2);
                InputDataVariable(2, Triangle_Perimeter_Area_Input_3);
            }
            if (Calculate(101)) {
                if (Calculate(102) == 3) {
                    StringOut(62, 13, 16, 53, 0, "Scalene Triangle");
                    SetCord(13, 18);
                    cout << Calculate(103) << " " << DefaultCalculationUnitName << "metre(s).";
                }
                else if (Calculate(102) == 2) {
                    StringOut(14, 13, 16, 53, 0, "Scalene");
                    StringOut(15, 13, 18, 53, 1, "Perimeter");
                    CreateButtons(
                            TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_PERIMETER_OF_TRIANGLES_ISOSCELES_TRIANGLE_TRANSFER_BUTTON,
                            1, DefaultButtonID);
                }
                else {
                    StringOut(14, 13, 16, 53, 0, "Scalene");
                    StringOut(16, 13, 18, 53, 1, "Perimeter");
                    CreateButtons(
                            TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_PERIMETER_OF_TRIANGLES_EQUILATERAL_TRIANGLE_TRANSFER_BUTTON,
                            1, DefaultButtonID);
                }
            }
            else {
                StringOut(13, 13, 16, 53, 0);
                StringOut(17, 13, 19, 53, 1, "Triangles");
                CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_INVALID_TRIANGLE_ADVICE_BUTTON, 1,
                              DefaultButtonID);
            }
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case For_Equilateral_Triangle_Perimeter_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Triangles ~ Perimeter of Triangles ~ For Equilateral Triangle");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Perimeter of Equilateral Triangle", 1);
            PreviousMenuID = Perimeter_of_Triangles_M;
            PreviousCalculationID = For_Equilateral_Triangle_M;
            StringOut(20, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 0)) {
                InputDataVariable(2, Triangle_Perimeter_Area_Input_1);
                DoubleVariable[1] = DoubleVariable[0];
                DoubleVariable[2] = DoubleVariable[0];
            }
            StringOut(62, 13, 16, 53, 0, "Equilateral Triangle");
            SetCord(13, 18);
            cout << Calculate(103) << " " << DefaultCalculationUnitName << "metre(s).";
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case For_Isosceles_Triangle_Perimeter_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Triangles ~ Perimeter of Triangles ~ For Isosceles Triangle");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Perimeter of Isosceles Triangle", 1);
            PreviousMenuID = Perimeter_of_Triangles_M;
            PreviousCalculationID = For_Isosceles_Triangle_M;
            StringOut(20, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 0)) {
                InputDataVariable(2, Triangle_Perimeter_Area_Input_1);
                DoubleVariable[1] = DoubleVariable[0];
            }
            if (VariableIsEmpty(1, 2, 2)) {
                InputDataVariable(2, Triangle_Perimeter_Area_Input_3);
            }
            if (Calculate(101)) {
                if (Calculate(102) == 2) {
                    StringOut(62, 13, 16, 53, 0, "Isosceles Triangle");
                    SetCord(13, 18);
                    cout << Calculate(3) << " " << DefaultCalculationUnitName << "metre(s).";
                }
                else {
                    StringOut(14, 13, 16, 53, 0, "Isosceles");
                    StringOut(16, 13, 18, 53, 1, "Perimeter");
                    CreateButtons(
                            TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_PERIMETER_OF_TRIANGLES_EQUILATERAL_TRIANGLE_TRANSFER_BUTTON,
                            1, DefaultButtonID);
                }
            }
            else {
                StringOut(13, 13, 16, 53, 0);
                StringOut(17, 13, 19, 53, 1, "Triangles");
                CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_TRIANGLES_INVALID_TRIANGLE_ADVICE_BUTTON, 1,
                              DefaultButtonID);
            }
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case Quadrilateral_M:
            CurrentAddress("Geometrical Calculations ~ Quadrilateral");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Quadrilateral", 1);
            PreviousMenuID = Geometrical_Calculations_M;
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_QUADRILATERAL_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Area_of_Quadrilateral_M:
            SetConsoleDimensions(DefaultConsoleWidth, DefaultConsoleHeight + 50);
            MainFrameHeight = 19;
            CurrentAddress("Geometrical Calculations ~ Quadrilateral ~ Area of Quadrilateral");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area of Quadrilateral", 1);
            PreviousMenuID = Quadrilateral_M;
            StringOut(64, 13, 15, 53, 0);
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_QUADRILATERAL_AREA_OF_QUADRILATERAL_MENU_BUTTON, 5,
                          DefaultButtonID);
            break;
        case Area_of_Quadrilateral_Formula_1_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Quadrilateral ~ Area of Quadrilateral ~ Formula - 1");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Area of Quadrilateral : Formula - 1", 1);
            PreviousMenuID = Area_of_Quadrilateral_M;
            PreviousCalculationID = Area_of_Quadrilateral_Formula_1_M;
            StringOut(58, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 9)) {
                InputDataVariable(2, Area_of_Quadrilateral_Formula_1_Input_1);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_1_Input_2);
                InputDataVariable(3, Area_of_Quadrilateral_Formula_1_Input_3);
            }
            ClearFrame(13, 16, 53, 2);
            StringOut(12, 13, 16, 53, 0, "Quadrilateral");
            SetCord(13, 18);
            cout << Calculate(201) << " square " << DefaultCalculationUnitName << "metre(s).";
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case Area_of_Quadrilateral_Formula_2_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Quadrilateral ~ Area of Quadrilateral ~ Formula - 2");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Area of Quadrilateral : Formula - 2", 1);
            PreviousMenuID = Area_of_Quadrilateral_M;
            PreviousCalculationID = Area_of_Quadrilateral_Formula_2_M;
            StringOut(65, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 2)) {
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_1);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_2);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_3);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_4);
                InputDataVariable(3, Area_of_Quadrilateral_Formula_2_3_Input_5);
                InputDataVariable(3, Area_of_Quadrilateral_Formula_2_3_Input_6);
                DoubleVariable[6] = (DoubleVariable[0] + DoubleVariable[1] + DoubleVariable[2] + DoubleVariable[3]) / 2;
            }
            ClearFrame(13, 16, 53, 2);
            if (Calculate(202) >= 0) {
                StringOut(12, 13, 16, 53, 0, "Quadrilateral");
                SetCord(13, 18);
                cout << Calculate(202) << " square " << DefaultCalculationUnitName << "metre(s).";
                StringOut(21, 13, 20, 53, 1);
                EmptyVariable(1, 0, 2);
                CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            } else {
                StringOut(72, 13, 16, 53, 0, "Quadrilaterals");
                StringOut(17, 13, 19, 53, 1, "Quadrilaterals");
                EmptyVariable(1, 0, 2);
                AboutJumpID = About_Quadrilateral_M;
                CreateButtons(ABOUT_JUMP_BUTTON, 1, DefaultButtonID);
            }
            break;
        case Area_of_Quadrilateral_Formula_3_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Quadrilateral ~ Area of Quadrilateral ~ Formula - 3");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Area of Quadrilateral : Formula - 3", 1);
            PreviousMenuID = Area_of_Quadrilateral_M;
            PreviousCalculationID = Area_of_Quadrilateral_Formula_3_M;
            StringOut(65, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 2)) {
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_1);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_2);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_3);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_4);
                InputDataVariable(3, Area_of_Quadrilateral_Formula_2_3_Input_5);
                InputDataVariable(3, Area_of_Quadrilateral_Formula_2_3_Input_6);
            }
            ClearFrame(13, 16, 53, 2);
            if (Calculate(203) >= 0) {
                StringOut(12, 13, 16, 53, 0, "Quadrilateral");
                SetCord(13, 18);
                cout << Calculate(203) << " square " << DefaultCalculationUnitName << "metre(s).";
                StringOut(21, 13, 20, 53, 1);
                EmptyVariable(1, 0, 2);
                CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            } else {
                StringOut(72, 13, 16, 53, 0, "Quadrilaterals");
                StringOut(17, 13, 19, 53, 1, "Quadrilaterals");
                EmptyVariable(1, 0, 2);
                AboutJumpID = About_Quadrilateral_M;
                CreateButtons(ABOUT_JUMP_BUTTON, 1, DefaultButtonID);
            }
            break;
        case Area_of_Quadrilateral_Formula_4_M:
            MainFrameShiftY = 10;
            MainFrameHeight = 14;
            CurrentAddress("Geometrical Calculations ~ Quadrilateral ~ Area of Quadrilateral ~ Formula - 3");
            MainFrame();
            FrameHeader(11, 11, 57, 0, "Area of Quadrilateral : Formula - 3", 1);
            PreviousMenuID = Area_of_Quadrilateral_M;
            PreviousCalculationID = Area_of_Quadrilateral_Formula_3_M;
            StringOut(74, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 2)) {
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_1);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_2);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_3);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_4);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_4_Input_5);
                InputDataVariable(3, Area_of_Quadrilateral_Formula_4_Input_6);
            }
            ClearFrame(13, 16, 53, 2);
            if (Calculate(204) >= 0) {
                StringOut(12, 13, 16, 53, 0, "Quadrilateral");
                SetCord(13, 18);
                cout << Calculate(204) << " square " << DefaultCalculationUnitName << "metre(s).";
                StringOut(21, 13, 20, 53, 1);
                EmptyVariable(1, 0, 2);
                CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            } else {
                StringOut(72, 13, 16, 53, 0, "Quadrilaterals");
                StringOut(17, 13, 19, 53, 1, "Quadrilaterals");
                EmptyVariable(1, 0, 2);
                AboutJumpID = About_Quadrilateral_M;
                CreateButtons(ABOUT_JUMP_BUTTON, 1, DefaultButtonID);
            }
            break;
        case Perimeter_of_Quadrilateral_M:
            CurrentAddress("Geometrical Calculations ~ Quadrilateral ~ Perimeter of Quadrilateral");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Perimeter of Quadrilateral", 1);
            PreviousMenuID = Quadrilateral_M;
            PreviousCalculationID = Perimeter_of_Quadrilateral_M;
            StringOut(81, 13, 15, 53, 0);
            if (VariableIsEmpty(1, 0, 10)) {
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_1);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_2);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_3);
                InputDataVariable(2, Area_of_Quadrilateral_Formula_2_3_4_Input_4);
            }
            ClearFrame(13, 15, 53, 2);
            if (Calculate(103) >= 0) {
                StringOut(62, 13, 15, 53, 0, "Quadrilateral");
                SetCord(13, 17);
                cout << Calculate(103) << " " << DefaultCalculationUnitName << "metre(s).";
                StringOut(21, 13, 19, 53, 1);
                EmptyVariable(1, 0, 2);
                CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            } else {
                StringOut(72, 13, 15, 53, 0, "Quadrilaterals");
                StringOut(17, 13, 18, 53, 1, "Quadrilaterals");
                EmptyVariable(1, 0, 2);
                AboutJumpID = About_Quadrilateral_M;
                CreateButtons(ABOUT_JUMP_BUTTON, 1, DefaultButtonID);
            }
            break;
        case About_Quadrilateral_M:
            PreviousMenuID = Quadrilateral_M;
            About("QUADRILATERAL", 9, 1, "Geometrical Calculations ~ Quadrilateral ~ About Quadrilateral");
            break;
        case Pentagon_M:
            CurrentAddress("Geometrical Calculations ~ Pentagon");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Pentagon", 1);
            PreviousMenuID = Geometrical_Calculations_M;
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_PENTAGON_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Area_of_Pentagon_M:
            CurrentAddress("Geometrical Calculations ~ Pentagon ~ Area of Pentagon");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area of Pentagon", 1);
            PreviousMenuID = Pentagon_M;
            PreviousCalculationID = Area_of_Pentagon_M;
            StringOut(112, 13, 16, 48, 0);
            if (VariableIsEmpty(1, 0, 0)) {
                InputDataVariable(2, Area_of_Pentagon_Hexagon_Formula_Input);
            }
            ClearFrame(13, 16, 53, 2);
            StringOut(12, 13, 16, 53, 0, "Pentagon");
            SetCord(13, 18);
            cout << Calculate(205) << " square " << DefaultCalculationUnitName << "metre(s).";
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case Perimeter_of_Pentagon_M:
            CurrentAddress("Geometrical Calculations ~ Pentagon ~ Perimeter of Pentagon");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Perimeter of Pentagon", 1);
            PreviousMenuID = Pentagon_M;
            PreviousCalculationID = Perimeter_of_Pentagon_M;
            StringOut(110, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 4)) {
                InputDataVariable(2, Polygon_Side_Input_1);
                InputDataVariable(2, Polygon_Side_Input_2);
                InputDataVariable(2, Polygon_Side_Input_3);
                InputDataVariable(2, Polygon_Side_Input_4);
                InputDataVariable(2, Polygon_Side_Input_5);
            }
            ClearFrame(13, 16, 53, 2);
            if (Calculate(103) >= 0) {
                StringOut(62, 13, 16, 53, 0, "Pentagon");
                SetCord(13, 18);
                cout << Calculate(103) << " " << DefaultCalculationUnitName << "metre(s).";
                StringOut(21, 13, 20, 53, 1);
                EmptyVariable(1, 0, 2);
                CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            } else {
                StringOut(72, 13, 16, 53, 0, "Pentagon");
                StringOut(17, 13, 19, 53, 1, "Pentagon");
                EmptyVariable(1, 0, 2);
                AboutJumpID = About_Pentagon_M;
                CreateButtons(ABOUT_JUMP_BUTTON, 1, DefaultButtonID);
            }
            break;
        case About_Pentagon_M:
            PreviousMenuID = Pentagon_M;
            About("PENTAGON", 9, 1, "Geometrical Calculations ~ Pentagon ~ About Pentagon");
            break;
        case Hexagon_M:
            CurrentAddress("Geometrical Calculations ~ Hexagon");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Hexagon", 1);
            PreviousMenuID = Geometrical_Calculations_M;
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_HEXAGON_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Area_of_Hexagon_M:
            SetConsoleDimensions(DefaultConsoleWidth, DefaultConsoleHeight + 50);
            MainFrameHeight = 19;
            CurrentAddress("Geometrical Calculations ~ Hexagon ~ Area of Hexagon");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area of Hexagon", 1);
            PreviousMenuID = Hexagon_M;
            StringOut(64, 13, 15, 53, 0);
            CreateButtons(TWO_DIMENSIONAL_SHAPES_REGULAR_POLYGONS_HEXAGON_AREA_OF_HEXAGON_MENU_BUTTON, 5,
                          DefaultButtonID);
            break;
        case Area_of_Hexagon_Formula_1_M:
            CurrentAddress("Geometrical Calculations ~ Hexagon ~ Area of Hexagon Formula - 1");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area of Hexagon : Formula - 1", 1);
            PreviousMenuID = Area_of_Hexagon_M;
            PreviousCalculationID = Area_of_Hexagon_Formula_1_M;
            StringOut(125, 13, 16, 48, 0);
            if (VariableIsEmpty(1, 0, 0)) {
                InputDataVariable(2, Area_of_Pentagon_Hexagon_Formula_Input);
            }
            ClearFrame(13, 16, 53, 2);
            StringOut(12, 13, 16, 53, 0, "Hexagon");
            SetCord(13, 18);
            cout << Calculate(206) << " square " << DefaultCalculationUnitName << "metre(s).";
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case Area_of_Hexagon_Formula_2_M:
            CurrentAddress("Geometrical Calculations ~ Hexagon ~ Area of Hexagon Formula - 2");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area of Hexagon : Formula - 2", 1);
            PreviousMenuID = Area_of_Hexagon_M;
            PreviousCalculationID = Area_of_Hexagon_Formula_2_M;
            StringOut(126, 13, 16, 48, 0);
            if (VariableIsEmpty(1, 0, 0)) {
                InputDataVariable(2, Area_of_Hexagon_Formula_2_Input);
            }
            ClearFrame(13, 16, 53, 2);
            StringOut(12, 13, 16, 53, 0, "Hexagon");
            SetCord(13, 18);
            cout << Calculate(207) << " square " << DefaultCalculationUnitName << "metre(s).";
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case Area_of_Hexagon_Formula_3_M:
            CurrentAddress("Geometrical Calculations ~ Hexagon ~ Area of Hexagon Formula - 3");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area of Hexagon : Formula - 3", 1);
            PreviousMenuID = Area_of_Hexagon_M;
            PreviousCalculationID = Area_of_Hexagon_Formula_3_M;
            StringOut(130, 13, 16, 48, 0);
            if (VariableIsEmpty(1, 0, 1)) {
                InputDataVariable(2, Area_of_Hexagon_Formula_3_Input_1);
                InputDataVariable(2, Area_of_Hexagon_Formula_3_Input_2);
            }
            ClearFrame(13, 16, 53, 2);
            StringOut(12, 13, 16, 53, 0, "Hexagon");
            SetCord(13, 18);
            cout << Calculate(208) << " square " << DefaultCalculationUnitName << "metre(s).";
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case Area_of_Hexagon_Formula_4_M:
            CurrentAddress("Geometrical Calculations ~ Hexagon ~ Area of Hexagon Formula - 4");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area of Hexagon : Formula - 4", 1);
            PreviousMenuID = Area_of_Hexagon_M;
            PreviousCalculationID = Area_of_Hexagon_Formula_4_M;
            StringOut(131, 13, 16, 48, 0);
            if (VariableIsEmpty(1, 0, 0)) {
                InputDataVariable(2, Area_of_Hexagon_Formula_3_Input_1);
            }
            ClearFrame(13, 16, 53, 2);
            StringOut(12, 13, 16, 53, 0, "Hexagon");
            SetCord(13, 18);
            cout << Calculate(209) << " square " << DefaultCalculationUnitName << "metre(s).";
            StringOut(21, 13, 20, 53, 1);
            EmptyVariable(1, 0, 2);
            CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            break;
        case Perimeter_of_Hexagon_M:
            CurrentAddress("Geometrical Calculations ~ Hexagon ~ Perimeter of Hexagon");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Perimeter of Hexagon", 1);
            PreviousMenuID = Hexagon_M;
            PreviousCalculationID = Perimeter_of_Hexagon_M;
            StringOut(124, 13, 16, 53, 0);
            if (VariableIsEmpty(1, 0, 5)) {
                InputDataVariable(2, Polygon_Side_Input_1);
                InputDataVariable(2, Polygon_Side_Input_2);
                InputDataVariable(2, Polygon_Side_Input_3);
                InputDataVariable(2, Polygon_Side_Input_4);
                InputDataVariable(2, Polygon_Side_Input_5);
                InputDataVariable(2, Polygon_Side_Input_6);
            }
            ClearFrame(13, 16, 53, 2);
            if (Calculate(103) >= 0) {
                StringOut(62, 13, 16, 53, 0, "Hexagon");
                SetCord(13, 18);
                cout << Calculate(103) << " " << DefaultCalculationUnitName << "metre(s).";
                StringOut(21, 13, 20, 53, 1);
                EmptyVariable(1, 0, 2);
                CreateButtons(RE_CALCULATE_BUTTON, 1, DefaultButtonID);
            } else {
                StringOut(72, 13, 16, 53, 0, "Hexagon");
                StringOut(17, 13, 19, 53, 1, "Hexagon");
                EmptyVariable(1, 0, 2);
                AboutJumpID = About_Hexagon_M;
                CreateButtons(ABOUT_JUMP_BUTTON, 1, DefaultButtonID);
            }
            break;
        case About_Hexagon_M:
            PreviousMenuID = Pentagon_M;
            About("HEXAGON", 9, 1, "Geometrical Calculations ~ Hexagon ~ About Hexagon");
            break;

            // Equation Solving
        case Equation_Solving_M:
            DefaultMainFrame();
            CurrentAddress("Equation Solving");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Equation Solving", 1);
            PreviousMenuID = Main_Menu_M;
            CreateButtons(EQUATION_SOLVING_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Linear_Equation_M:
            DefaultMainFrame();
            CurrentAddress("Equation Solving ~ Linear Equation");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Linear Equation", 1);
            PreviousMenuID = Equation_Solving_M;
            CreateButtons(EQUATION_SOLVING_LINEAR_EQUATION_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Solve_Linear_Equation_Two_Variable_M:
            DefaultMainFrame();
            MainFrameHeight = 22;
            SetConsoleDimensions(800, 430);
            CurrentAddress("Equation Solving ~ Linear Equation ~ Solve Linear Equation Two Variable");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Solve Linear Equation Two Variable", 1);
            PreviousMenuID = Linear_Equation_M;
            PreviousCalculationID = Solve_Linear_Equation_Two_Variable_M;
            StringOut(84, 13, 16, 45, 0);
            if (VariableIsEmpty(1, 0, 1)) {
                InputDataVariable(1, Solve_Linear_Equation_Two_Variable_Input_1);
                InputDataVariable(1, Solve_Linear_Equation_Two_Variable_Input_2);
            }
            ClearFrame(13, 16, 53, 2);
            StringOut(87, 13, 16, 53, 0);
            SetCord(13, 18);
            cout << "y = " << DoubleVariable[0] << "x + " << DoubleVariable[1];
            StringOut(88, 13, 20, 53, 0);
            cout << Calculate(301);
            StringOut(89, 13, 22, 53, 0);
            cout << Calculate(302);
            StringOut(90, 13, 24, 53, 0);
            cout << Calculate(303) << char(248) << ".";
            StringOut(21, 13, 27, 53, 1);
            EmptyVariable(1, 0, 1);
            CreateButtons(RE_CALCULATE_BUTTON_SOLVE_LINEAR_EQUATION, 1, DefaultButtonID);
            break;
        case Solve_System_Of_Linear_Equation_M:
            DefaultMainFrame();
            MainFrameHeight = 26;
            SetConsoleDimensions(800, 480);
            CurrentAddress("Equation Solving ~ Linear Equation ~ Solve System Of Linear Equation");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Solve System Of Linear Equation", 1);
            PreviousMenuID = Linear_Equation_M;
            PreviousCalculationID = Solve_System_Of_Linear_Equation_M;
            SetCord(13, 16);
            cout << "Equation - " << 1;
            StringOut(100, 13, 18, 50, 0);
            if (VariableIsEmpty(1, 0, 3)) {
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_1_1);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_1_2);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_1_3);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_1_4);
            }
            ClearFrame(13, 16, 53, 4);
            SetCord(13, 16);
            cout << "Equation - " << 2;
            StringOut(100, 13, 18, 50, 0);
            if (VariableIsEmpty(1, 4, 7)) {
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_2_1);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_2_2);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_2_3);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_2_4);
            }
            ClearFrame(13, 16, 53, 4);
            SetCord(13, 16);
            cout << "Equation - " << 3;
            StringOut(100, 13, 18, 50, 0);
            if (VariableIsEmpty(1, 8, 11)) {
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_3_1);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_3_2);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_3_3);
                InputDataVariable(1, Solve_Linear_Equation_Three_Variable_Input_3_4);
            }
            ClearFrame(13, 16, 53, 4);
            StringOut(105, 13, 16, 53, 0);
            SetCord(13, 18);
            cout << "Equation - " << 1 << " : " << DoubleVariable[0] << "x + " << DoubleVariable[1] << "y + " <<
            DoubleVariable[2] << "z = " << DoubleVariable[3];
            SetCord(13, 20);
            cout << "Equation - " << 2 << " : " << DoubleVariable[4] << "x + " << DoubleVariable[5] << "y + " <<
            DoubleVariable[6] << "z = " << DoubleVariable[7];
            SetCord(13, 22);
            cout << "Equation - " << 3 << " : " << DoubleVariable[8] << "x + " << DoubleVariable[9] << "y + " <<
            DoubleVariable[10] << "z = " << DoubleVariable[11];
            if (Calculate(401) != 0) {
                StringOut(106, 13, 24, 53, 0);
                StringOut(109, 13, 26, 53, 0);
                SetCord(13, 28);
                cout << "x = " << Calculate(402) / Calculate(401) << " , y = " << Calculate(403) / Calculate(401) <<
                " , z = " << Calculate(404) / Calculate(401);
            } else {
                if ((Calculate(402) != 0) || (Calculate(403) != 0) || (Calculate(404) != 0)) {
                    StringOut(108, 13, 24, 53, 0);
                } else {
                    StringOut(107, 13, 24, 53, 0);
                }
            }
            StringOut(21, 13, 30, 53, 1);
            EmptyVariable(1, 0, 1);
            CreateButtons(RE_CALCULATE_BUTTON_SOLVE_LINEAR_EQUATION_SYSTEM, 1, DefaultButtonID);
            break;
        case About_Linear_Equation_M:
            PreviousMenuID = Linear_Equation_M;
            About("LINEAR EQUATION", 9, 1, "Equation Solving ~ Linear Equation ~ About Linear Equation");
            break;
        case Quadratic_Equation_M:
            DefaultMainFrame();
            CurrentAddress("Equation Solving ~ Quadratic Equation");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Quadratic Equation", 1);
            PreviousMenuID = Equation_Solving_M;
            CreateButtons(EQUATION_SOLVING_QUADRATIC_EQUATION_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Solve_Quadratic_Equation_M:
            DefaultMainFrame();
            MainFrameHeight = 22;
            SetConsoleDimensions(800, 430);
            CurrentAddress("Equation Solving ~ Quadratic Equation ~ Solve Quadratic Equation");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Solve Quadratic Equation", 1);
            PreviousMenuID = Quadratic_Equation_M;
            PreviousCalculationID = Solve_Quadratic_Equation_M;
            StringOut(91, 13, 16, 45, 0);
            if (VariableIsEmpty(1, 0, 1)) {
                InputDataVariable(1, Solve_Quadratic_Equation_Input_1);
                InputDataVariable(1, Solve_Quadratic_Equation_Input_2);
                InputDataVariable(1, Solve_Quadratic_Equation_Input_3);
            }
            ClearFrame(13, 16, 53, 2);
            StringOut(95, 13, 16, 53, 0);
            SetCord(13, 18);
            cout << DoubleVariable[0] << "x" << char(253) << " + " << DoubleVariable[1] << "x + " <<
            DoubleVariable[2] << " = 0";
            if (Calculate(304) == 1) {
                StringOut(96, 13, 20, 53, 0);
                StringOut(99, 13, 22, 53, 0);
                SetCord(13, 24);
                cout << Calculate(306) << " and " << Calculate(307);
            } else if (Calculate(304) == -1) {
                StringOut(97, 13, 20, 53, 0);
                StringOut(99, 13, 22, 53, 0);
                SetCord(13, 24);
                cout << (-DoubleVariable[1]) << " + " << Calculate(305) << "i and " << (-DoubleVariable[1]) << " - " <<
                Calculate(305) << "i";
            } else {
                StringOut(98, 13, 20, 53, 0);
                StringOut(99, 13, 22, 53, 0);
                SetCord(13, 24);
                cout << Calculate(306);
            }
            StringOut(21, 13, 27, 53, 1);
            EmptyVariable(1, 0, 1);
            CreateButtons(RE_CALCULATE_BUTTON_SOLVE_LINEAR_EQUATION, 1, DefaultButtonID);
            break;
        case About_Quadratic_Equation_M:
            PreviousMenuID = Quadratic_Equation_M;
            About("QUADRATIC EQUATION", 9, 1, "Equation Solving ~ Quadratic Equation ~ About Quadratic Equation");
            break;

            // Calc
        case Calc_M:
            CurrentAddress("Calc");
            PreviousMenuID = Main_Menu_M;
            Calc();
            break;

            // Conversions
        case Conversions_M:
            DefaultMainFrame();
            CurrentAddress("Conversions");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Conversions", 1);
            PreviousMenuID = Main_Menu_M;
            CreateButtons(CONVERSIONS_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Currency_M:
            DefaultMainFrame();
            CurrentAddress("Conversions ~ Currency");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Currency", 1);
            PreviousMenuID = Conversions_M;
            StringOut(42, 13, 15, 53, 0, CurrencyObject.CurrencyCountry[IntegerVariable[0]]);
            CreateButtons(CONVERSIONS_CURRENCY_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Currency_Select_M:
            DefaultMainFrame();
            MainFrameHeight = 10 + CURRENCY_COUNTRY_SELECT_LIST_ROWS * 2;
            CurrentAddress("Conversions ~ Currency");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Currency", 1);
            PreviousMenuID = Conversions_M;
            SetConsoleDimensions(800, 840);
            StringOut(35, 13, 15, 53, 0);
            IntegerVariable[0] = CreateButtons(CURRENCY_COUNTRY_SELECT_LIST_BUTTON, CURRENCY_COUNTRY_SELECT_LIST_ROWS,
                                               DefaultButtonID, 2);
            ClearConsole(0);
            Menu(Currency_M);
            break;
        case Currency_One_To_One_Conversion_M:
            DefaultMainFrame();
            MainFrameHeight = 10 + CURRENCY_COUNTRY_SELECT_LIST_ROWS * 2;
            CurrentAddress("Conversions ~ Currency ~ One to One Conversion");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "One to One Conversion", 1);
            PreviousMenuID = Currency_M;
            SetConsoleDimensions(800, 840);
            StringOut(36, 13, 15, 53, 0, CurrencyObject.CurrencyCountry[IntegerVariable[0]]);
            IntegerVariable[1] = CreateButtons(CURRENCY_COUNTRY_SELECT_LIST_BUTTON, CURRENCY_COUNTRY_SELECT_LIST_ROWS,
                                               DefaultButtonID, 2);
            ClearConsole(0);
            Menu(Currency_One_To_One_Conversion_Done_M);
            break;
        case Currency_One_To_One_Conversion_Done_M:
            DefaultMainFrame();
            CurrentAddress("Conversions ~ Currency ~ One to One Conversion");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "One to One Conversion", 1);
            PreviousMenuID = Currency_M;
            StringOut(37, 13, 15, 53, 0);
            SetCord(43, 15);
            cout << "1 " << CurrencyObject.CurrencyCode[IntegerVariable[0]] << " = " <<
            CurrencyObject.CurrencyConversion(IntegerVariable[0], IntegerVariable[1]) << " " <<
            CurrencyObject.CurrencyCode[IntegerVariable[1]];
            InputDataVariable(1, CurrencyConversionInput);
            StringOut(40, 13, 15, 53, 0);
            SetCord(13, 17);
            cout << DoubleVariable[0] << " " << CurrencyObject.CurrencyCode[IntegerVariable[0]] << " = " <<
            (DoubleVariable[0] * CurrencyObject.CurrencyConversion(IntegerVariable[0], IntegerVariable[1])) << " " <<
            CurrencyObject.CurrencyCode[IntegerVariable[1]];
            StringOut(41, 13, 20, 53, 1);
            SetCord(43, 15);
            cout << "1 " << CurrencyObject.CurrencyCode[IntegerVariable[0]] << " = " <<
            CurrencyObject.CurrencyConversion(IntegerVariable[0], IntegerVariable[1]) << " " <<
            CurrencyObject.CurrencyCode[IntegerVariable[1]];
            PreviousCalculationID = Currency_One_To_One_Conversion_Done_M;
            CreateButtons(CURRENY_ONE_TO_ONE_CONVERSION_RE_BUTTONS, 1, DefaultButtonID);
            ClearConsole(0);
            Menu(Currency_One_To_One_Conversion_M);
            break;
        case Currency_One_To_Many_Conversion_M:
            DefaultMainFrame();
            SetConsoleDimensions(800, 840);
            MainFrameHeight = NumberOfCurrencies * 3 + 12;
            CurrentAddress("Conversions ~ Currency ~ One to Many Conversion");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "One to Many Conversion", 1);
            StringOut(43, 13, 15, 53, 0, CurrencyObject.CurrencyCountry[IntegerVariable[0]]);
            StringOut(44, 13, 16, 53, 0);
            PreviousMenuID = Currency_M;
            for (int i = 0; i < NumberOfCurrencies; i++) {
                SetCord(13, i * 3 + 18);
                for (int j = 0; j <= 53; j++) {
                    if (j == 0) ColorOut(CurrencyOneToManyBoxTopLeft, 0);
                    else if (j == 53) ColorOut(CurrencyOneToManyBoxTopRight, 0);
                    else ColorOut(CurrencyOneToManyBoxTop, 0);
                }
                SetCord(13, i * 3 + 19);
                cout << CurrencyOneToManyBoxLeft << " 1 " << CurrencyObject.CurrencyCode[IntegerVariable[0]] << " = " <<
                (1 / CurrencyObject.CurrencyConversion(IntegerVariable[0], i)) << " " << CurrencyObject.CurrencyCode[i];
                SetCord(66, i * 3 + 19);
                cout << CurrencyOneToManyBoxRight;
                SetCord(13, i * 3 + 20);
                for (int j = 0; j <= 53; j++) {
                    if (j == 0) ColorOut(CurrencyOneToManyBoxBottomLeft, 0);
                    else if (j == 53) ColorOut(CurrencyOneToManyBoxBottomRight, 0);
                    else ColorOut(CurrencyOneToManyBoxBottom, 0);
                }
            }
            SetCord(0, 0);
            CurrencyOneToManyCalculate();
            break;
        case Currency_One_To_Many_Conversion_Calculate_M:
            DefaultMainFrame();
            SetConsoleDimensions(800, 840);
            MainFrameHeight = NumberOfCurrencies * 3 + 12;
            CurrentAddress("Conversions ~ Currency ~ One to Many Conversion");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "One to Many Conversion", 1);
            StringOut(43, 13, 15, 53, 0, CurrencyObject.CurrencyCountry[IntegerVariable[0]]);
            StringOut(44, 13, 16, 53, 0);
            PreviousMenuID = Currency_M;
            for (int i = 0; i < NumberOfCurrencies; i++) {
                SetCord(13, i * 3 + 18);
                for (int j = 0; j <= 53; j++) {
                    if (j == 0) ColorOut(CurrencyOneToManyBoxTopLeft, 0);
                    else if (j == 53) ColorOut(CurrencyOneToManyBoxTopRight, 0);
                    else ColorOut(CurrencyOneToManyBoxTop, 0);
                }
                SetCord(13, i * 3 + 19);
                cout << CurrencyOneToManyBoxLeft << " " << DoubleVariable[0] << " " <<
                CurrencyObject.CurrencyCode[IntegerVariable[0]] << " = " <<
                (1 / CurrencyObject.CurrencyConversion(IntegerVariable[0], i)) * DoubleVariable[0] << " " <<
                CurrencyObject.CurrencyCode[i];
                SetCord(66, i * 3 + 19);
                cout << CurrencyOneToManyBoxRight;
                SetCord(13, i * 3 + 20);
                for (int j = 0; j <= 53; j++) {
                    if (j == 0) ColorOut(CurrencyOneToManyBoxBottomLeft, 0);
                    else if (j == 53) ColorOut(CurrencyOneToManyBoxBottomRight, 0);
                    else ColorOut(CurrencyOneToManyBoxBottom, 0);
                }
            }
            SetCord(0, 0);
            CurrencyOneToManyCalculate();
            break;
        case Update_Currency_Exchange_Rates_M:
            DefaultMainFrame();
            CurrentAddress("Conversions ~ Update Currency Exchange Rates");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Update Currency Exchange Rates", 1);
            PreviousMenuID = Conversions_M;
            CreateButtons(CONVERSIONS_UPDATE_CURRENCY_EXCHANGE_RATES_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Update_Currency_Exchange_Rates_START_M:
            DefaultMainFrame();
            CurrentAddress("Conversions ~ Update Currency Exchange Rates ~ Updating...");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Update Currency Exchange Rates", 1);
            PreviousMenuID = Update_Currency_Exchange_Rates_M;
            UpdateCurrencyRates();
            break;
        case View_Update_History_M:
            DefaultMainFrame();
            CurrentAddress("Conversions ~ Update Currency Exchange Rates ~ View Update History");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "View Update History", 1);
            PreviousMenuID = Update_Currency_Exchange_Rates_M;
            StringOut(28, 13, 15, 53, 0);
            cout << (SettingsObject.SettingValue[5] / 69);
            StringOut(29, 13, 16, 53, 0);
            cout << SettingsObject.SettingValue[4];
            StringOut(30, 13, 17, 53, 0);
            cout << "From - " << CurrencyObject.CurrencyCode[SettingsObject.SettingValue[2]] << "  To - " <<
            CurrencyObject.CurrencyCode[SettingsObject.SettingValue[3]];
            StringOut(31, 13, 18, 53, 0);
            cout << SettingsObject.SettingValue[11] << "/" << SettingsObject.SettingValue[10] << "/" <<
            SettingsObject.SettingValue[9];
            if (SettingsObject.SettingValue[8] != 0 && SettingsObject.SettingValue[7] != 0 &&
                SettingsObject.SettingValue[6] != 0) {
                StringOut(32, 13, 19, 53, 0);
                cout << SettingsObject.SettingValue[8] << "/" << SettingsObject.SettingValue[7] << "/" <<
                SettingsObject.SettingValue[6];
            }
            StringOut(33, 13, 21, 53, 0);
            getchar();
            if (cin.get() == '\n') {
                ClearConsole(0);
                Menu(PreviousMenuID);
            }
            break;
        case Units_M:
            DefaultMainFrame();
            CurrentAddress("Conversions ~ Units");
            SetConsoleDimensions(800, 380);
            MainFrameHeight = 18;
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Units", 1);
            PreviousMenuID = Conversions_M;
            CreateButtons(CONVERSIONS_UNITS_MENU_BUTTON, 5, DefaultButtonID);
            break;
        case Temperature_M:
            DefaultMainFrame();
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Temperature");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Temperature", 1);
            PreviousMenuID = Units_M;
            PreviousCalculationID = Temperature_M;
            StringOut(76, 13, 15, 53, 0, "Temperature");
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsTemperature, 6, 1,
                                             82);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsTemperature, 6, 1,
                                             82);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Temperature_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX,
                      StringOutEndY, 53 - StringLength(Strings[80]), 0);
            StringOut(41, 13, 24, 53, 1);
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Length_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Length_No, "LENGTH");
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Length");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Length", 1);
            PreviousMenuID = Units_M;
            PreviousCalculationID = Length_M;
            StringOut(76, 13, 15, 53, 0, "Length");
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Length_No,
                                             1);
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Length_No,
                                             1);
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Length_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0);
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Mass_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsMass, Mass_No, "MASS");
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Mass");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Mass", 1);
            PreviousMenuID = Units_M;
            PreviousCalculationID = Mass_M;
            StringOut(76, 13, 15, 53, 0, "Mass");
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsMass, Mass_No, 1);
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsMass, Mass_No, 1);
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Mass_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0);
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Speed_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsSpeed, Speed_No, "SPEED");
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Speed");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Speed", 1);
            PreviousMenuID = Units_M;
            PreviousCalculationID = Speed_M;
            StringOut(76, 13, 15, 53, 0, "Speed");
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsSpeed, Speed_No, 1);
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsSpeed, Speed_No, 1);
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Speed_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0);
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Volume_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsSpeed, Volume_No, "VOLUME");
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Volume");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Volume", 1);
            PreviousMenuID = Units_M;
            PreviousCalculationID = Volume_M;
            StringOut(76, 13, 15, 53, 0, "Volume");
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsSpeed, Volume_No, 1);
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsSpeed, Volume_No, 1);
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Volume_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0);
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Area_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Area_No, "AREA"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Area"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Area", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Area_M; //
            StringOut(76, 13, 15, 53, 0, "Area"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Area_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Area_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Area_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Time_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Time_No, "TIME"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Time"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Time", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Time_M; //
            StringOut(76, 13, 15, 53, 0, "Time"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Time_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Time_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Time_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Data_Storage_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Data_Storage_No, "DATA STORAGE"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Data Storage"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Data Storage", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Data_Storage_M; //
            StringOut(76, 13, 15, 53, 0, "Data Storage"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength,
                                             Data_Storage_No, 1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength,
                                             Data_Storage_No, 1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Data_Storage_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX,
                      StringOutEndY, 53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Pressure_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Pressure_No, "PRESSURE"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Pressure"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Pressure", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Pressure_M; //
            StringOut(76, 13, 15, 53, 0, "Pressure"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Pressure_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Pressure_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Pressure_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Power_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Power_No, "POWER"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Power"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Power", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Power_M; //
            StringOut(76, 13, 15, 53, 0, "Power"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Power_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Power_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Power_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Angle_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Angle_No, "ANGLE"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Angle"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Angle", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Angle_M; //
            StringOut(76, 13, 15, 53, 0, "Angle"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Angle_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Angle_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Angle_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Acceleration_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Acceleration_No, "ACCELERATION"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Acceleration"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Acceleration", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Acceleration_M; //
            StringOut(76, 13, 15, 53, 0, "Acceleration"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength,
                                             Acceleration_No, 1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength,
                                             Acceleration_No, 1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Acceleration_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX,
                      StringOutEndY, 53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Density_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsSpeed, Density_No, "DENSITY");
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Density");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Density", 1);
            PreviousMenuID = Units_M;
            PreviousCalculationID = Density_M;
            StringOut(76, 13, 15, 53, 0, "Density");
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsSpeed, Density_No,
                                             1);
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsSpeed, Density_No,
                                             1);
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Density_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0);
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Energy_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Energy_No, "ENERGY"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Energy"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Energy", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Energy_M; //
            StringOut(76, 13, 15, 53, 0, "Energy"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Energy_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Energy_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Energy_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Force_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Force_No, "FORCE"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Force"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Force", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Force_M; //
            StringOut(76, 13, 15, 53, 0, "Force"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Force_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Force_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Force_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;
        case Torque_M:
            DefaultMainFrame();
            ScrollInputButtonColumnHack = 1;
            CreateButtonColumnWidthValue = 30;
            UnitConversionScrollListGenerator(ScrollListUnitsLength, Torque_No, "TORQUE"); //
            SetConsoleDimensions(800, 390);
            MainFrameHeight = 19;
            CurrentAddress("Conversions ~ Units ~ Torque"); //
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Torque", 1); //
            PreviousMenuID = Units_M;
            PreviousCalculationID = Torque_M; //
            StringOut(76, 13, 15, 53, 0, "Torque"); //
            StringOut(77, 13, 17, 53, 0);
            IntegerVariable[0] = ScrollInput(1, 13 + StringLength(Strings[77]), 17, ScrollListUnitsLength, Torque_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            StringOut(78, 13, 19, 53, 0);
            IntegerVariable[1] = ScrollInput(1, 13 + StringLength(Strings[78]), 19, ScrollListUnitsLength, Torque_No,
                                             1); //
            SetConsoleDimensions(800, 385);
            InputDataVariable(1, UnitsInput);
            StringOut(80, 13, 21, 53, 0);
            StringOut(UnitConvertor(Torque_M, IntegerVariable[0], IntegerVariable[1]), StringOutEndX, StringOutEndY,
                      53 - StringLength(Strings[80]), 0); //
            StringOut(41, 13, 24, 53, 1);
            ScrollInputButtonColumnHack = 0;
            CreateButtonColumnWidthValue = DefaultCreateButtonColumnWidthValue;
            CreateButtons(CONVERSIONS_UNITS_RE_BUTTONS, 1, DefaultButtonID);
            break;

            // Settings
        case Settings_M:
            DefaultMainFrame();
            CurrentAddress("Settings");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Settings", 1);
            PreviousMenuID = Main_Menu_M;
            CreateButtons(SETTINGS_MENU_BUTTON, 3, DefaultButtonID);
            break;
        case Update_Settings_M:
            DefaultMainFrame();
            MainFrameHeight = 38;
            MainFrameRoundFlag = 1;
            CurrentAddress("Settings ~ Update Settings");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Update Settings", 1);
            PreviousMenuID = Settings_M;
            UpdateSettingsMenu();
            break;
        case Reset_Settings_M:
            DefaultMainFrame();
            CurrentAddress("Settings ~ Reset Settings");
            MainFrame();
            FrameHeader(11, 10, 57, 0, "Reset Settings", 1);
            PreviousMenuID = Settings_M;
            StringOut(132, 13, 16, 53, 0);
            CreateButtons(SETTINGS_RESET_SETTINGS_MENU_BUTTON, 1, DefaultButtonID);
            break;
    }
}

// The About(char*,int) is used for retrieving and displaying the information about a particular mathematical expression, formula or even geometrical shapes.
// #} Note: AboutStartYCoordinate doesn't include to coordinate of Current Address. Instead one should have to provide the AboutStartYCoordinate accordingly so that it doesn't overlap or overshoot the Current Address layout.

void About(char *Title, int AboutStartYCoordinate, int AboutPageID, char *CurrentAddressText) {

    AboutCurrentPageTitle = Title;
    AboutCurrentStartYCordinate = AboutStartYCoordinate;
    AboutCurrentCurrentAddressText = CurrentAddressText;

    CurrentAddress(CurrentAddressText);

    MainFrameShiftX = 0;
    MainFrameWidth = 79;
    MainFrameColourType = 0;
    MainFrameRoundFlag = 2;

    MainFrameShiftY = AboutStartYCoordinate;
    MainFrameHeight = 4;
    MainFrame();

    SetCord(8, AboutStartYCoordinate + 2);
    cout << "ABOUT " << Title;

    int StartYCoordinate;

    if (AboutPageID != 4) {
        MainFrameShiftY = AboutStartYCoordinate + 4;
        MainFrameHeight = 4;
        MainFrameRoundFlag = 2;
        MainFrame();
        StartYCoordinate = AboutStartYCoordinate + 8;
    }
    else StartYCoordinate = AboutStartYCoordinate + 4;

    string AboutDataString, IndividualAboutDataString, IndividualAboutData, IndividualAboutDataInterpreted, IndividualAboutDataInterpretedLine;
    ifstream AboutDataFile(AboutDataFilePath);
    if (AboutDataFile.is_open()) {
        while (!(AboutDataFile.eof())) {
            getline(AboutDataFile, AboutDataString);
            stringstream AboutDataStream;
            AboutDataStream.str(AboutDataString);
            int Flag = 0;
            int TempFlag = 0;
            while (getline(AboutDataStream, IndividualAboutDataString, '#')) {
                if (Flag == 0) {
                    if (IndividualAboutDataString == Title) TempFlag = 1;
                }
                else {
                    if (TempFlag == 1) {
                        stringstream IndividualAboutDataStream;
                        IndividualAboutDataStream.str(IndividualAboutDataString);
                        int _TempFlag = 1;
                        while (getline(IndividualAboutDataStream, IndividualAboutData, '|')) {
                            if ((_TempFlag == AboutPageID) && (AboutPageID != 4)) {
                                stringstream IndividualAboutDataLineStream;
                                IndividualAboutDataLineStream.str(IndividualAboutData);
                                IndividualAboutDataInterpreted = IndividualAboutDataLineStream.str();
                                StringInterpret(IndividualAboutDataInterpreted, 1);
                                IndividualAboutDataLineStream.str(IndividualAboutDataInterpreted);
                                if (_TempFlag == 1) FrameHeader(11, StartYCoordinate + 1, 57, 0, "Information", 1);
                                else if (_TempFlag == 2) FrameHeader(11, StartYCoordinate + 1, 57, 0, "Properties", 1);
                                else if (_TempFlag == 3) FrameHeader(11, StartYCoordinate + 1, 57, 0, "Formulas", 1);
                                int LineNumber = 0;
                                while (getline(IndividualAboutDataLineStream, IndividualAboutDataInterpretedLine,
                                               '~')) {
                                    StringOut(IndividualAboutDataInterpretedLine, 4,
                                              (6 + LineNumber + StartYCoordinate), 70, 0);
                                    LineNumber += StringOutNoOfLines + 1;
                                }
                                MainFrameShiftY = StartYCoordinate;
                                MainFrameHeight = LineNumber + 8;
                                MainFrameRoundFlag = 0;
                                MainFrame();
                                SetConsoleDimensions(DefaultConsoleWidth, DefaultConsoleHeight * 2);
                            }
                            else if ((_TempFlag == AboutPageID) && (AboutPageID == 4)) {
                                stringstream IndividualAboutDataLineStream;
                                IndividualAboutDataLineStream.str(IndividualAboutData);
                                MainFrameShiftY = StartYCoordinate;
                                MainFrameHeight = 11 - CurrentAddressNoOfLines;
                                MainFrameRoundFlag = 1;
                                MainFrame();
                                FrameHeader(11, StartYCoordinate + 1, 57, 0, "More", 1);
                                SetCord(0, AboutStartYCoordinate + 4);

                                SetCord(13, StartYCoordinate + 6);
                                cout << "You are being directed to the website for more";
                                SetCord(13, StartYCoordinate + 7);
                                cout << "information.";

                                SetConsoleDimensions(DefaultConsoleWidth, DefaultConsoleHeight);
                                int Count = 1;
                                while (Count <= 10) {
                                    cout << ".";
                                    PauseConsole(FPS * (500 * Count));
                                    Count++;
                                }
                                Count = 0;
                                while (getline(IndividualAboutDataLineStream, IndividualAboutDataInterpretedLine,
                                               '~') && Count == 0) {
                                    string AboutLink = IndividualAboutDataInterpretedLine;
                                    char AboutLinkCharacterArray[100];
                                    strcpy(AboutLinkCharacterArray, IndividualAboutDataInterpretedLine.c_str());
                                    WebLinkLaunch(AboutLinkCharacterArray);
                                    Count++;
                                }
                                ClearConsole(0);
                                Menu(PreviousMenuID);
                            }
                            _TempFlag++;
                        }
                        TempFlag = 0;
                    }
                }
                Flag++;
            }
        }
    }
    AboutDataFile.close();
    SetCord(0, 0);
    int DefaultButtonID[2] = {0, AboutPageID - 1};
    button ABOUT_MENU_BUTTONS[1][ButtonsColumnLimit] =
            {
                    {
                            {1, 10, AboutStartYCoordinate + 6, "Information", About_Information_B_F},
                            {1, 27, AboutStartYCoordinate + 6, "Properties", About_Properties_B_F},
                            {1, 43, AboutStartYCoordinate + 6, "Formulas", About_Formulas_B_F},
                            {1, 57, AboutStartYCoordinate + 6, "More", About_More_B_F},
                            {1, 66, AboutStartYCoordinate + 6, "Back", Back_B_F}
                    }
            };
    CreateButtons(ABOUT_MENU_BUTTONS, 1, DefaultButtonID);
}

// The GetCurrencyRate(char*,char*) is used to get current currency rates.

double GetCurrencyRate(char *From, char *To) {
    double CurrencyRateData = 0;
    // Getting Response String from the Server.
    string RequestString = "http://rate-exchange.appspot.com/currency?from=";
    RequestString += string(From);
    RequestString += string("&to=");
    RequestString += string(To);
    string ResponseString = WebGetData(RequestString.c_str());
    unsigned int RatePosition = ResponseString.find("rate");
    // Parsing Rate from Response String.
    if (RatePosition >= 0) {
        string RateStringTemp = ResponseString.substr(RatePosition + 7);
        unsigned int RateTerminatePosition = RateStringTemp.find(", \"from");
        string RateString = RateStringTemp.substr(1, RateTerminatePosition);
        unsigned int RateStringLength = RateString.length();
        string RateDigitString = "";
        for (int i = 0; i < RateStringLength; i++) {
            if (isdigit(RateString[i]) || RateString[i] == '.') {
                RateDigitString += RateString[i];
            }
            else {
                break;
            }
        }
        CurrencyRateData = atof(RateDigitString.c_str());
    }
    else {
        cout << "An Error Has Occured!";
    }

    return CurrencyRateData;
}

// The UpdateCurrencyRatesTerminator(void*) is used to terminate the process of updation of currencies.

void UpdateCurrencyRatesTerminator(void *Temp) {
    while (!UpdateCurrencyRatesTerminateFlag && UpdateCurrencyRatesTerminateFlag != 2) {
        FlushConsoleInputBuffer(
                GetStdHandle(STD_INPUT_HANDLE));                 // To flush the non-required previous data.
        getch();
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            UpdateCurrencyRatesTerminateFlag = 1;
        }
    }
    _endthread();
}

// The UpdateCurrencyRates() is used to update the currency rates stored in data bin of the program.

void UpdateCurrencyRates() {
    CursorToggle(0);
    int CountryAttempting = SettingsObject.SettingValue[2];
    int LastCountryAttempting = CountryAttempting;
    int CountryCurrencyRateAttempting = SettingsObject.SettingValue[3];
    int TotalFailed = SettingsObject.SettingValue[4];
    int TotalCompleted = SettingsObject.SettingValue[5];
    int UpdateCompleteYear = SettingsObject.SettingValue[6];
    int UpdateCompleteMonth = SettingsObject.SettingValue[7];
    int UpdateCompleteDay = SettingsObject.SettingValue[8];
    float PercentCompleted = (TotalCompleted + TotalFailed) / 47.61;
    if ((TotalFailed + TotalCompleted) == (NumberOfCurrencies * NumberOfCurrencies)) {
        UpdateCompleteYear = SettingsObject.SettingValue[6];
        UpdateCompleteMonth = SettingsObject.SettingValue[7];
        UpdateCompleteDay = SettingsObject.SettingValue[8];
        if (UpdateCompleteYear < GetCurrentDate(1)) {
            int UPDATE_CURRENCY_RATES_REMINDER_DIALOG_BUTTON_FUNCTIONS[5] = {Update_Currency_Rates_Reminder_Yes,
                                                                             Update_Currency_Rates_Reminder_No, 0, 0,
                                                                             0};
            CreateDialogBox("Update Reminder", Strings[25], 65, 14, 1,
                            UPDATE_CURRENCY_RATES_REMINDER_DIALOG_BUTTON_FUNCTIONS, 0, 1);
        }
        else if (UpdateCompleteMonth < GetCurrentDate(2)) {
            int UPDATE_CURRENCY_RATES_REMINDER_DIALOG_BUTTON_FUNCTIONS[5] = {Update_Currency_Rates_Reminder_Yes,
                                                                             Update_Currency_Rates_Reminder_No, 0, 0,
                                                                             0};
            CreateDialogBox("Update Reminder", Strings[25], 65, 14, 1,
                            UPDATE_CURRENCY_RATES_REMINDER_DIALOG_BUTTON_FUNCTIONS, 0, 1);
        }
        else if (UpdateCompleteDay < (GetCurrentDate(3) - 5)) {
            int UPDATE_CURRENCY_RATES_REMINDER_DIALOG_BUTTON_FUNCTIONS[5] = {Update_Currency_Rates_Reminder_Yes,
                                                                             Update_Currency_Rates_Reminder_No, 0, 0,
                                                                             0};
            CreateDialogBox("Update Reminder", Strings[25], 65, 14, 1,
                            UPDATE_CURRENCY_RATES_REMINDER_DIALOG_BUTTON_FUNCTIONS, 0, 1);
        }
        else {
            int UPDATE_CURRENCY_RATES_COMPLETED_NOW_DIALOG_BUTTON_FUNCTIONS[5] = {
                    Update_Currency_Rates_Completed_Now_Yes, Update_Currency_Rates_Completed_Now_No, 0, 0, 0};
            CreateDialogBox("Updation Complete", Strings[26], 65, 14, 1,
                            UPDATE_CURRENCY_RATES_COMPLETED_NOW_DIALOG_BUTTON_FUNCTIONS, 0, 1);
        }

    }
    SetCord(13, 15);
    ColorOut("Countries Done: ", 1);
    cout << TotalCompleted;
    SetCord(43, 15);
    ColorOut("Countries Failed: ", 1);
    cout << TotalFailed;
    SetCord(13, 17);
    ColorOut("Current Currency From: ", 1);
    cout << CurrencyObject.CurrencyCode[CountryAttempting];
    SetCord(43, 17);
    ColorOut("Current Currency To: ", 1);
    cout << CurrencyObject.CurrencyCode[CountryCurrencyRateAttempting];
    SetCord(12, 19);
    cout << LoadingFrameEdgeTopLeftSpirit;
    for (int i = 0; i <= 53; i++) {
        cout << LoadingFrameTopBottomSpirit;
    }
    cout << LoadingFrameEdgeTopRightSpirit;
    SetCord(12, 20);
    cout << LoadingFrameLeftRightSpirit;
    SetCord(67, 20);
    cout << LoadingFrameLeftRightSpirit;
    SetCord(12, 21);
    cout << LoadingFrameEdgeBottomLeftSpirit;
    for (int i = 0; i <= 53; i++) {
        cout << LoadingFrameTopBottomSpirit;
    }
    cout << LoadingFrameEdgeBottomRightSpirit;
    for (int k = 0; k < (int) (PercentCompleted * 0.53); k++) {
        if (k == 25 || k == 26 || k == 27 || k == 28 || k == 29) continue;
        SetCord(13 + k, 20);
        ColorOut(LoadingSpirit, 1);
    }
    SetCord(39, 20);
    cout << (int) (PercentCompleted) << "% ";
    SetCord(25, 22);
    cout << "[Press Escape to stop Updation.]";
    _beginthread(UpdateCurrencyRatesTerminator, 0,
                 (void *) &Temp); // Applying multi-threading concept to thread multiple processes at once.
    fstream CurrencyLogData(CurrencyLogDataFilePath, ios::app);
    if (CurrencyLogData.is_open()) {
        CurrencyLogData << "### Currency Conversion Log | " << GetCurrentDate(3) << "-" << GetCurrentDate(2) << "-" <<
        GetCurrentDate(1) << "\n";
    }
    ofstream CurrencyRateDataFile(CurrencyRateDataTempFilePath, ios::app);
    if (CurrencyRateDataFile.is_open()) {
        for (int i = LastCountryAttempting; i < NumberOfCurrencies; i++) {
            CountryAttempting = i;
            SetCord(36, 17);
            cout << CurrencyObject.CurrencyCode[CountryAttempting];
            int j = 0;
            if (i == (LastCountryAttempting)) {
                j = (CountryCurrencyRateAttempting == 0) ? 0 : (++CountryCurrencyRateAttempting);
            }
            for (; j < NumberOfCurrencies; j++) {
                CountryCurrencyRateAttempting = j;
                if (strcmp(CurrencyObject.CurrencyCode[i], CurrencyObject.CurrencyCode[j]) != 0) {
                    double CurrencyConversionRate = GetCurrencyRate(CurrencyObject.CurrencyCode[i],
                                                                    CurrencyObject.CurrencyCode[j]);
                    if (CurrencyConversionRate == 0) {
                        TotalFailed++;
                        CurrencyLogData << "### " << TotalFailed << ". Currency Update Failed - From: " <<
                        CurrencyObject.CurrencyCode[i] << " | To: " << CurrencyObject.CurrencyCode[j] << "\n";
                    }
                    else {
                        TotalCompleted++;
                    }
                    CurrencyRateDataFile << CurrencyObject.CurrencyCode[i] << "#" << CurrencyObject.CurrencyCode[j] <<
                    "#" << CurrencyConversionRate << "|";
                }
                else {
                    CurrencyRateDataFile << CurrencyObject.CurrencyCode[i] << "#" << CurrencyObject.CurrencyCode[j] <<
                    "#" << 1 << "|";
                    TotalCompleted++;
                }
                PercentCompleted = (TotalCompleted + TotalFailed) / 47.61;
                SetCord(29, 15);
                cout << TotalCompleted;
                SetCord(61, 15);
                cout << TotalFailed;
                SetCord(64, 17);
                cout << CurrencyObject.CurrencyCode[CountryCurrencyRateAttempting];
                int k = 0;
                if ((int) (PercentCompleted * 0.53) != 0) k = (int) (PercentCompleted * 0.53) - 1;
                for (; k <= (int) (PercentCompleted * 0.53); k++) {
                    if (k == 25 || k == 26 || k == 27 || k == 28 || k == 29) continue;
                    SetCord(13 + k, 20);
                    ColorOut(LoadingSpirit, 1);
                }
                SetCord(39, 20);
                cout << (int) (PercentCompleted) << "% ";
                SettingsObject.SettingsUpdate(2, CountryAttempting);
                SettingsObject.SettingsUpdate(3, CountryCurrencyRateAttempting);
                SettingsObject.SettingsUpdate(4, TotalFailed);
                SettingsObject.SettingsUpdate(5, TotalCompleted);
                SettingsObject.SettingsUpdate(9, GetCurrentDate(1));
                SettingsObject.SettingsUpdate(10, GetCurrentDate(2));
                SettingsObject.SettingsUpdate(11, GetCurrentDate(3));
                if (UpdateCurrencyRatesTerminateFlag == 1) {
                    CurrencyRateDataFile.close();
                    CurrencyLogData.close();
                    int UPDATE_CURRENCY_RATES_DIALOG_BUTTON_FUNCTIONS[5] = {Update_Currency_Rates_Stop_Yes,
                                                                            Update_Currency_Rates_Stop_No, 0, 0, 0};
                    PreviousMenuID = Update_Currency_Exchange_Rates_M;
                    CreateDialogBox("Stop Updation!", Strings[23], 65, 14, 1,
                                    UPDATE_CURRENCY_RATES_DIALOG_BUTTON_FUNCTIONS, 0, 1);
                }
            }
            if (i == (NumberOfCurrencies - 1)) UpdateCurrencyRatesTerminateFlag = 2;
        }
    }
    else {
        cout << "Failed...";
    }
    CurrencyRateDataFile.close();
    CurrencyLogData << "### Rate Conversion Completed!";
    CurrencyLogData.close();
    ClearFileContents(CurrencyRateDataFilePath);
    fstream CurrencyRateDataMain(CurrencyRateDataFilePath);
    if (CurrencyRateDataMain.is_open()) {
        CurrencyRateDataMain.seekp(0, ios::end);
        size_t CurrencyRateDataFileSize = CurrencyRateDataMain.tellg();
        if (CurrencyRateDataFileSize == 0) {
            CopyFileNew(CurrencyRateDataTempFilePath, CurrencyRateDataFilePath);
            SettingsObject.SettingsUpdate(6, GetCurrentDate(1));
            SettingsObject.SettingsUpdate(7, GetCurrentDate(2));
            SettingsObject.SettingsUpdate(8, GetCurrentDate(3));
            ClearFileContents(CurrencyRateDataTempFilePath);
        }
    }
    int UPDATE_CURRENCY_RATES_COMPLETED_NOW_DIALOG_BUTTON_FUNCTIONS[5] = {Update_Currency_Rates_Completed_Now_Yes,
                                                                          Update_Currency_Rates_Completed_Now_No, 0, 0,
                                                                          0};
    CreateDialogBox("Updation Complete", Strings[26], 65, 14, 1,
                    UPDATE_CURRENCY_RATES_COMPLETED_NOW_DIALOG_BUTTON_FUNCTIONS, 0, 1);
}

// The Calculate(int,double) function is used for storing the required mathematical functions.

double Calculate(int FunctionID) {
    double result = 0;
    double CalcVar[10];
    for (int i = 0; i < 10; i++) {
        if (VariableConvertStatus[i])
            CalcVar[i] = (DoubleVariable[i]) * pow(10, UnitVariable[i]) / pow(10, SettingsObject.SettingValue[1]);
        else CalcVar[i] = DoubleVariable[i];
    }
    int EqualityFlag = 0;
    int ValidateFlag = 0;
    switch (FunctionID) {

        // Scalene Triangle Area Function
        case 1:
            result = CalcVar[0] + CalcVar[1] + CalcVar[2];
            result = result / 2;
            result = result * (result - CalcVar[0]) * (result - CalcVar[1]) * (result - CalcVar[2]);
            result = sqrt(result);
            break;

            // Equilateral Triangle Area Function
        case 2:
            result = (sqrt(3) * (pow(CalcVar[0], 2))) / 4;
            break;

        case 3:
            result = (CalcVar[2] / 4) * (sqrt(4 * (pow(CalcVar[0], 2)) - (pow(CalcVar[2], 2))));
            break;

            // Equality of any two or more than two numbers.
        case 1001:
            for (int i = 0; (i < 10) && (CalcVar[i] != 0); i++) {
                for (int j = 0; (j < 10) && (CalcVar[j] != 0); j++) {
                    if (j == i) continue;
                    if (CalcVar[i] == CalcVar[j]) {
                        EqualityFlag++;
                    }
                }
                if (EqualityFlag > 0) {
                    result = 1;
                    break;
                }
            }
            break;

            // Validating a triangle.
        case 101:
            for (int i = 0; i < 3; i++) {
                double OtherSidesSumation = 0;
                for (int j = 0; j < 3; j++) {
                    if (j == i) continue;
                    OtherSidesSumation += CalcVar[j];
                }
                if (OtherSidesSumation <= CalcVar[i]) {
                    ValidateFlag = 0;
                    break;
                }
                else {
                    ValidateFlag = 1;
                    continue;
                }
            }
            result = ValidateFlag;
            break;

            // Triangle type. [1: Equilateral triangle, 2: Isoceles triangle, 3: Scalene triangle]
        case 102:
            if ((CalcVar[0] == CalcVar[1]) && (CalcVar[0] == CalcVar[2])) {
                result = 1;
            }
            else if ((CalcVar[0] == CalcVar[1]) && (CalcVar[0] != CalcVar[2]) ||
                     (CalcVar[0] == CalcVar[2]) && (CalcVar[0] != CalcVar[1]) ||
                     (CalcVar[1] == CalcVar[0]) && (CalcVar[1] != CalcVar[2]) ||
                     (CalcVar[1] == CalcVar[2]) && (CalcVar[1] != CalcVar[0]) ||
                     (CalcVar[2] == CalcVar[0]) && (CalcVar[2] != CalcVar[1]) ||
                     (CalcVar[2] == CalcVar[1]) && (CalcVar[2] != CalcVar[0])) {
                result = 2;
            }
            else {
                result = 3;
            }
            break;

            // Adding all the variables.
        case 103:
            for (int i = 0; i < 10; i++) {
                result += CalcVar[i];
            }
            break;
        case 201:
            switch (UnitVariable[2]) {
                case 0:
                    CalcVar[2] = (CalcVar[2] * Pi) / 180;
                    break;
                case 1:
                    CalcVar[2] = CalcVar[2];
                    break;
            }
            result = fabs((0.5) * (CalcVar[0] * CalcVar[1] * sin(CalcVar[2])));
            break;
        case 202:
            switch (UnitVariable[5]) {
                case 0:
                    CalcVar[5] = (CalcVar[5] * Pi) / 180;
                    break;
                case 1:
                    CalcVar[5] = CalcVar[5];
                    break;
            }
            switch (UnitVariable[4]) {
                case 0:
                    CalcVar[4] = (CalcVar[4] * Pi) / 180;
                    break;
                case 1:
                    CalcVar[4] = CalcVar[4];
                    break;
            }
            if (((CalcVar[6] - CalcVar[0]) * (CalcVar[6] - CalcVar[1]) * (CalcVar[6] - CalcVar[2]) *
                 (CalcVar[6] - CalcVar[3])) >=
                (0.5 * (CalcVar[0] * CalcVar[1] * CalcVar[2] * CalcVar[3] * (1 + cos(CalcVar[4] + CalcVar[5]))))) {
                result = sqrt(((CalcVar[6] - CalcVar[0]) * (CalcVar[6] - CalcVar[1]) * (CalcVar[6] - CalcVar[2]) *
                               (CalcVar[6] - CalcVar[3])) - (0.5 * (CalcVar[0] * CalcVar[1] * CalcVar[2] * CalcVar[3] *
                                                                    (1 + cos(CalcVar[4] + CalcVar[5])))));
            } else {
                result = -1;
            }
            break;
        case 203:
            switch (UnitVariable[5]) {
                case 0:
                    CalcVar[5] = (CalcVar[5] * Pi) / 180;
                    break;
                case 1:
                    CalcVar[5] = CalcVar[5];
                    break;
            }
            switch (UnitVariable[4]) {
                case 0:
                    CalcVar[4] = (CalcVar[4] * Pi) / 180;
                    break;
                case 1:
                    CalcVar[4] = CalcVar[4];
                    break;
            }
            result = 0.5 * CalcVar[0] * CalcVar[3] * sin(CalcVar[4]) + 0.5 * CalcVar[1] * CalcVar[2] * sin(CalcVar[5]);
            break;
        case 204:
            switch (UnitVariable[5]) {
                case 0:
                    CalcVar[5] = (CalcVar[5] * Pi) / 180;
                    break;
                case 1:
                    CalcVar[5] = CalcVar[5];
                    break;
            }
            if ((2 * (CalcVar[0] * CalcVar[0] - CalcVar[2] * CalcVar[2]) - 4 * CalcVar[4] * CalcVar[4]) *
                (2 * (CalcVar[1] * CalcVar[1] - CalcVar[3] * CalcVar[3]) - 4 * CalcVar[4] * CalcVar[4]) >= 0) {
                result = 0.25 * sin(CalcVar[5]) *
                         sqrt((2 * (CalcVar[0] * CalcVar[0] - CalcVar[2] * CalcVar[2]) - 4 * CalcVar[4] * CalcVar[4]) *
                              (2 * (CalcVar[1] * CalcVar[1] - CalcVar[3] * CalcVar[3]) - 4 * CalcVar[4] * CalcVar[4]));
            } else {
                result = -1;
            }
            break;
        case 205:
            result = 1.720477401 * CalcVar[0] * CalcVar[0];
            break;
        case 206:
            result = 2.598076211 * CalcVar[0] * CalcVar[0];
            break;
        case 207:
            result = 0.866025404 * CalcVar[0] * CalcVar[0];
            break;
        case 208:
            result = (CalcVar[0] * CalcVar[1]) / 2;
            break;
        case 209:
            result = 3.464102 * CalcVar[0] * CalcVar[0];
            break;
        case 301:
            result = -CalcVar[1] / CalcVar[0];
            break;
        case 302:
            result = CalcVar[1];
            break;
        case 303:
            result = (atan(CalcVar[0]) * 180) / Pi;
            break;
        case 304:
            if ((pow(CalcVar[1], 2) - 4 * CalcVar[0] * CalcVar[2]) > 0) result = 1;
            else if ((pow(CalcVar[1], 2) - 4 * CalcVar[0] * CalcVar[2]) < 0) result = -1;
            else result = 0;
            break;
        case 305:
            result = sqrt(fabs((pow(CalcVar[1], 2) - 4 * CalcVar[0] * CalcVar[2])));
            break;
        case 306:
            result = (-CalcVar[1] + sqrt((pow(CalcVar[1], 2) - 4 * CalcVar[0] * CalcVar[2]))) / (2 * CalcVar[0]);
            break;
        case 307:
            result = (-CalcVar[1] - sqrt((pow(CalcVar[1], 2) - 4 * CalcVar[0] * CalcVar[2]))) / (2 * CalcVar[0]);
            break;
        case 401:
            result = CalcVar[0] * ((CalcVar[5] * CalcVar[10]) - (CalcVar[6] * CalcVar[9])) -
                     CalcVar[4] * ((CalcVar[1] * CalcVar[10]) - (CalcVar[2] * CalcVar[9])) +
                     CalcVar[8] * ((CalcVar[1] * CalcVar[6]) - (CalcVar[2] * CalcVar[5]));
            break;
        case 402:
            result = CalcVar[3] * ((CalcVar[5] * CalcVar[10]) - (CalcVar[6] * CalcVar[9])) -
                     CalcVar[7] * ((CalcVar[1] * CalcVar[10]) - (CalcVar[2] * CalcVar[9])) +
                     CalcVar[11] * ((CalcVar[1] * CalcVar[6]) - (CalcVar[2] * CalcVar[5]));
            break;
        case 403:
            result = CalcVar[0] * ((CalcVar[7] * CalcVar[10]) - (CalcVar[6] * CalcVar[11])) -
                     CalcVar[4] * ((CalcVar[3] * CalcVar[10]) - (CalcVar[2] * CalcVar[11])) +
                     CalcVar[8] * ((CalcVar[3] * CalcVar[6]) - (CalcVar[2] * CalcVar[7]));
            break;
        case 404:
            result = CalcVar[0] * ((CalcVar[5] * CalcVar[11]) - (CalcVar[7] * CalcVar[9])) -
                     CalcVar[4] * ((CalcVar[1] * CalcVar[11]) - (CalcVar[3] * CalcVar[9])) +
                     CalcVar[8] * ((CalcVar[1] * CalcVar[7]) - (CalcVar[3] * CalcVar[5]));
            break;
    }
    return result;
}

// The UnitConversionScrollListGenerator(scrolllist*,int,char*) is used to create scrollist variables for the Units in the Conversion Data.

void UnitConversionScrollListGenerator(scrolllist *UnitScrollList, int NoOfUnits, char *UnitType) {
    string ConvertDataString, IndividualConvertDataString, IndividualConvertData, _IndividualConvertData;
    ifstream ConvertDataFile(ConvertDataFilePath);
    if (ConvertDataFile.is_open()) {
        while (!(ConvertDataFile.eof())) {
            getline(ConvertDataFile, ConvertDataString);
            stringstream ConvertDataStream;
            ConvertDataStream.str(ConvertDataString);
            int Flag = 0;
            int TempFlag = 0;
            while (getline(ConvertDataStream, IndividualConvertDataString, '#')) {
                if (Flag == 0) {
                    if (IndividualConvertDataString == UnitType) TempFlag = 1;
                }
                else {
                    if (TempFlag == 1) {
                        stringstream IndividualConvertDataStream;
                        IndividualConvertDataStream.str(IndividualConvertDataString);
                        int _TempFlag = 1;
                        while (getline(IndividualConvertDataStream, IndividualConvertData, '%')) {
                            stringstream _IndividualConvertDataStream;
                            _IndividualConvertDataStream.str(IndividualConvertData);
                            int __TempFlag = 1;
                            while (getline(_IndividualConvertDataStream, _IndividualConvertData, '|')) {
                                if ((__TempFlag == 1) && (_TempFlag <= NoOfUnits)) {
                                    UnitScrollList[_TempFlag - 1].Status = 1;
                                    strcpy(UnitScrollList[_TempFlag - 1].Text, _IndividualConvertData.c_str());
                                    UnitScrollList[_TempFlag - 1].AssociatedID = _TempFlag;
                                    strcpy(UnitScrollList[_TempFlag - 1].AdditionalText, "");
                                }
                                __TempFlag++;
                            }
                            _TempFlag++;
                        }
                        TempFlag = 0;
                    }
                }
                Flag++;
            }
        }
    }
    ConvertDataFile.close();
}

// The UnitConversionFromFile(char*,int,int,double) is used to get the conversion data from the Conversion Data file.

double UnitConversionFromFile(char *UnitTitle, int FromID, int ToID, double Var) {
    double ConversionValueFrom = 0.0, ConversionValueTo = 0.0, Result = 0.0;
    string ConvertDataString, IndividualConvertDataString, IndividualConvertData, _IndividualConvertData;
    ifstream ConvertDataFile(ConvertDataFilePath);
    if (ConvertDataFile.is_open()) {
        while (!(ConvertDataFile.eof())) {
            getline(ConvertDataFile, ConvertDataString);
            stringstream ConvertDataStream;
            ConvertDataStream.str(ConvertDataString);
            int Flag = 0;
            int TempFlag = 0;
            while (getline(ConvertDataStream, IndividualConvertDataString, '#')) {
                if (Flag == 0) {
                    if (IndividualConvertDataString == UnitTitle) TempFlag = 1;
                }
                else {
                    if (TempFlag == 1) {
                        stringstream IndividualConvertDataStream;
                        IndividualConvertDataStream.str(IndividualConvertDataString);
                        int _TempFlag = 1;
                        while (getline(IndividualConvertDataStream, IndividualConvertData, '%')) {
                            if ((_TempFlag == FromID) || (_TempFlag == ToID)) {
                                stringstream _IndividualConvertDataStream;
                                _IndividualConvertDataStream.str(IndividualConvertData);
                                int __TempFlag = 1;
                                while (getline(_IndividualConvertDataStream, _IndividualConvertData, '|')) {
                                    if (FromID == ToID) {
                                        if (__TempFlag == 1) {
                                            UnitConversionFromFileFromSuffix = _IndividualConvertData;
                                            UnitConversionFromFileToSuffix = _IndividualConvertData;
                                        } else if (__TempFlag == 2) {
                                            ConversionValueFrom = 1;
                                            ConversionValueTo = 1;
                                        }
                                    } else {
                                        if ((_TempFlag == FromID)) {
                                            if (__TempFlag == 1) {
                                                UnitConversionFromFileFromSuffix = _IndividualConvertData;
                                            } else if (__TempFlag == 2) {
                                                ConversionValueFrom = atof(_IndividualConvertData.c_str());
                                            }
                                        } else if ((_TempFlag == ToID)) {
                                            if (__TempFlag == 1) {
                                                UnitConversionFromFileToSuffix = _IndividualConvertData;
                                            } else if (__TempFlag == 2) {
                                                ConversionValueTo = atof(_IndividualConvertData.c_str());
                                            }
                                        }
                                    }
                                    __TempFlag++;
                                }
                            }
                            _TempFlag++;
                        }
                        TempFlag = 0;
                    }
                }
                Flag++;
            }
        }
    }
    ConvertDataFile.close();
    Result = (ConversionValueFrom / ConversionValueTo) * Var;
    return Result;
}

// The UnitConvertor(int,int,int) is used to convert the units.

string UnitConvertor(int UnitID, int FromID, int ToID) {
    double UnitVar = DoubleVariable[0];
    string UnitFromSuffix, UnitToSuffix;
    stringstream UnitConversionStringResultStream;
    if (FromID == ToID) UnitConversionResult = UnitVar;
    switch (UnitID) {
        case Temperature_M:
            switch (FromID) {
                case Temperature_Kelvin:
                    UnitFromSuffix = "Kelvin[K]";
                    switch (ToID) {
                        case Temperature_Celsius:
                            UnitConversionResult = UnitVar - 273.15;
                            UnitToSuffix = "Celsius[`248`C]";
                            break;
                        case Temperature_Fahrenheit:
                            UnitConversionResult = (1.8 * (UnitVar - 273.15)) + 32.0;
                            UnitToSuffix = "Fahrenheit[`248`F]";
                            break;
                        case Temperature_Rankine:
                            UnitConversionResult = UnitVar * 1.8;
                            UnitToSuffix = "Rankine[`248`R]";
                            break;
                        case Temperature_Reaumur:
                            UnitConversionResult = (UnitVar - 273.15) * 0.8;
                            UnitToSuffix = "Reaumur[`248`r]";
                            break;
                        case Temperature_Newton:
                            UnitConversionResult = (UnitVar - 273.15) * 0.33;
                            UnitToSuffix = "Newton[`248`N]";
                            break;
                        default:
                            UnitToSuffix = "Kelvin[K]";
                            break;
                    }
                    break;
                case Temperature_Celsius:
                    UnitFromSuffix = "Celsius[`248`C]";
                    switch (ToID) {
                        case Temperature_Kelvin:
                            UnitConversionResult = UnitVar + 273.15;
                            UnitToSuffix = "Kelvin[K]";
                            break;
                        case Temperature_Fahrenheit:
                            UnitConversionResult = (UnitVar * 1.8) + 32.0;
                            UnitToSuffix = "Fahrenheit[`248`F]";
                            break;
                        case Temperature_Rankine:
                            UnitConversionResult = (UnitVar * 1.8) + 491.67;
                            UnitToSuffix = "Rankine[`248`R]";
                            break;
                        case Temperature_Reaumur:
                            UnitConversionResult = UnitVar * 0.8;
                            UnitToSuffix = "Reaumur[`248`r]";
                            break;
                        case Temperature_Newton:
                            UnitConversionResult = UnitVar * 0.33;
                            UnitToSuffix = "Newton[`248`N]";
                            break;
                        default:
                            UnitToSuffix = "Celsius[`248`C]";
                            break;
                    }
                    break;
                case Temperature_Fahrenheit:
                    UnitFromSuffix = "Fahrenheit[`248`F]";
                    switch (ToID) {
                        case Temperature_Kelvin:
                            UnitConversionResult = (UnitVar + 459.67) / 1.8;
                            UnitToSuffix = "Kelvin[K]";
                            break;
                        case Temperature_Celsius:
                            UnitConversionResult = (UnitVar - 32.0) / 1.8;
                            UnitToSuffix = "Celsius[`248`C]";
                            break;
                        case Temperature_Rankine:
                            UnitConversionResult = UnitVar + 459.67;
                            UnitToSuffix = "Rankine[`248`R]";
                            break;
                        case Temperature_Reaumur:
                            UnitConversionResult = (UnitVar - 32) / 2.25;
                            UnitToSuffix = "Reaumur[`248`r]";
                            break;
                        case Temperature_Newton:
                            UnitConversionResult = (UnitVar - 32.0) * (11.0 / 60.0);
                            UnitToSuffix = "Newton[`248`N]";
                            break;
                        default:
                            UnitToSuffix = "Fahrenheit[`248`F]";
                            break;
                    }
                    break;
                case Temperature_Rankine:
                    UnitFromSuffix = "Rankine[`248`R]";
                    switch (ToID) {
                        case Temperature_Kelvin:
                            UnitConversionResult = UnitVar / 1.8;
                            UnitToSuffix = "Kelvin[K]";
                            break;
                        case Temperature_Celsius:
                            UnitConversionResult = (UnitVar / 1.8) - 273.15;
                            UnitToSuffix = "Celsius[`248`C]";
                            break;
                        case Temperature_Fahrenheit:
                            UnitConversionResult = UnitVar - 459.67;
                            UnitToSuffix = "Fahrenheit[`248`F]";
                            break;
                        case Temperature_Reaumur:
                            UnitConversionResult = ((UnitVar / 1.8) + 273.15) * 0.8;
                            UnitToSuffix = "Reaumur[`248`r]";
                            break;
                        case Temperature_Newton:
                            UnitConversionResult = (UnitVar - 491.67) * (11.0 / 60.0);
                            UnitToSuffix = "Newton[`248`N]";
                            break;
                        default:
                            UnitToSuffix = "Rankine[`248`R]";
                            break;
                    }
                    break;
                case Temperature_Reaumur:
                    UnitFromSuffix = "Reaumur[`248`r]";
                    switch (ToID) {
                        case Temperature_Kelvin:
                            UnitConversionResult = (UnitVar / 0.8) + 273.15;
                            UnitToSuffix = "Kelvin[K]";
                            break;
                        case Temperature_Celsius:
                            UnitConversionResult = UnitVar / 0.8;
                            UnitToSuffix = "Celsius[`248`C]";
                            break;
                        case Temperature_Fahrenheit:
                            UnitConversionResult = (UnitVar * 2.25) + 3;
                            UnitToSuffix = "Fahrenheit[`248`F]";
                            break;
                        case Temperature_Rankine:
                            UnitConversionResult = (UnitVar * 2.25) + 491.67;
                            UnitToSuffix = "Rankine[`248`R]";
                            break;
                        case Temperature_Newton:
                            UnitConversionResult = UnitVar * (33.0 / 80.0);
                            UnitToSuffix = "Newton[`248`N]";
                            break;
                        default:
                            UnitToSuffix = "Reaumur[`248`r]";
                            break;
                    }
                case Temperature_Newton:
                    UnitFromSuffix = "Newton[`248`N]";
                    switch (ToID) {
                        case Temperature_Kelvin:
                            UnitConversionResult = (UnitVar * (100.0 / 33.0)) + 273.15;
                            UnitToSuffix = "Kelvin[K]";
                            break;
                        case Temperature_Celsius:
                            UnitConversionResult = UnitVar * (100.0 / 33.0);
                            UnitToSuffix = "Celsius[`248`C]";
                            break;
                        case Temperature_Fahrenheit:
                            UnitConversionResult = UnitVar * (60.0 / 11.0) + 32;
                            UnitToSuffix = "Fahrenheit[`248`F]";
                            break;
                        case Temperature_Rankine:
                            UnitConversionResult = UnitVar * (60.0 / 11.0) + 491.67;
                            UnitToSuffix = "Rankine[`248`R]";
                            break;
                        case Temperature_Reaumur:
                            UnitConversionResult = UnitVar * (80.0 / 33.0);
                            UnitToSuffix = "Reaumur[`248`r]";
                            break;
                        default:
                            UnitToSuffix = "Newton[`248`N]";
                            break;
                    }
                    break;
            }
            break;
        case Length_M:
            UnitConversionResult = UnitConversionFromFile("LENGTH", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Mass_M:
            UnitConversionResult = UnitConversionFromFile("MASS", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Speed_M:
            UnitConversionResult = UnitConversionFromFile("SPEED", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Volume_M:
            UnitConversionResult = UnitConversionFromFile("VOLUME", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Area_M:
            UnitConversionResult = UnitConversionFromFile("AREA", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Time_M:
            UnitConversionResult = UnitConversionFromFile("TIME", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Data_Storage_M:
            UnitConversionResult = UnitConversionFromFile("DATA STORAGE", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Pressure_M:
            UnitConversionResult = UnitConversionFromFile("PRESSURE", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Power_M:
            UnitConversionResult = UnitConversionFromFile("POWER", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Angle_M:
            UnitConversionResult = UnitConversionFromFile("ANGLE", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Acceleration_M:
            UnitConversionResult = UnitConversionFromFile("ACCELERATION", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Density_M:
            UnitConversionResult = UnitConversionFromFile("DENSITY", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Energy_M:
            UnitConversionResult = UnitConversionFromFile("ENERGY", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Force_M:
            UnitConversionResult = UnitConversionFromFile("FORCE", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
        case Torque_M:
            UnitConversionResult = UnitConversionFromFile("TORQUE", FromID, ToID, UnitVar);
            UnitFromSuffix = UnitConversionFromFileFromSuffix;
            UnitToSuffix = UnitConversionFromFileToSuffix;
            break;
    }
    StringInterpret(UnitFromSuffix, 1);
    StringInterpret(UnitToSuffix, 1);
    UnitConversionStringResultStream << UnitVar << " " << UnitFromSuffix << " = " << UnitConversionResult << " " <<
    UnitToSuffix;
    UnitConversionStringResult = UnitConversionStringResultStream.str();
    return UnitConversionStringResult;
}

// Checking if MinGW is installed

int CheckMinGW() {
    string MinGWCheckCommand = "IF EXIST ";
    MinGWCheckCommand += MinGWPath;
    MinGWCheckCommand += " ( copy nul mingw-found.txt > nul )";
    system(MinGWCheckCommand.c_str());
    fstream MinGWFile;
    MinGWFile.open("mingw-found.txt", ios::in);
    if (MinGWFile.is_open()) {
        MinGWFile.close();
        remove("mingw-found.txt");
        return 1;
    } else {
        ErrorFlag = 1;
        return 0;
    }
}

// Defining the class Calculator.

class Calculator {
private:
    void Intro(int Type, float fps) {
        switch (Type) {
            case 1:
                for (int i = 0; i < 20; i++) {
                    for (int j = 0; j < 80; j++) {
                        SetCord(j, i + 1);
                        if (IntroFrames[i][j] == '%') ColorOut('#', 0);
                        else ColorOut(IntroFrames[i][j], 1);
                        PauseConsole(fps * 9.5);
                    }
                }
                break;
            case 2:
                for (int x = 0; x <= 8; x++) {
                    for (int i = 0; i < 20; i++) {
                        for (int j = 0; j < (i + (x * 10)); j++) {
                            SetCord(j, i + 1);
                            if (IntroFrames[i][j] == '%') ColorOut('#', 0);
                            else ColorOut(IntroFrames[i][j], 1);
                            PauseConsole(fps * 9.5);
                        }
                    }
                }
                SetCord(0, 20);
                for (int i = 0; i <= 240; i++) cout << " ";
                break;
            case 3:
                for (int x = 0; x < 8; x++) {
                    for (int i = 0; i < 20; i++) {
                        for (int j = x * 10; j < (((x + 1) * 10)); j++) {
                            SetCord(j, i + 1);
                            if (IntroFrames[i][j] == '%') ColorOut('#', 0);
                            else ColorOut(IntroFrames[i][j], 1);
                            PauseConsole(fps * 9.5);
                        }
                    }
                }
                break;
            case 4:
                srand(time(0));
                for (int n = 0; n <= 10000; n++) {
                    int i = rand() % 20;
                    int j = rand() % 80;
                    SetCord(j, i + 1);
                    if (IntroFrames[i][j] == '%') ColorOut('#', 2);
                    else ColorOut(IntroFrames[i][j], 2);
                    PauseConsole(fps);
                }
                break;
        }
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 80; j++) {
                SetCord(j, i + 1);
                if (IntroFrames[i][j] == '%') ColorOut('#', 3);
                else cout << IntroFrames[i][j];
            }
        }

    }

    void HOME_MENU() {
        IntroEndFlag = 2;
        system("cls");
        Header();
        if (CheckMinGW() == 1) {
            if (SettingsObject.SettingValue[0] == 0) {
                FirstTimeIntro(1);
            }
            else {
                Menu(Main_Menu_M);
            }
        } else {
            Menu(ERROR_M);
        }
    }

public:
    void Initialize() {
        SetConsoleDimensions(DefaultConsoleWidth, DefaultConsoleHeight);
        int IntroClipID;
        if (IntroStyleID == 5) {
            srand(time(0));
            IntroClipID = rand() % 4 + 1;
        }
        else IntroClipID = IntroStyleID;
        if (SettingsObject.SettingValue[0] == 0) {
            IntroClipID = 2;
        }
        system("cls");
        CursorToggle(0);
        if (IntroMusicID) {
            BackgroundMusicFlag = 1;
            BackgroundMusicID = IntroMusicID;
            BackgroundMusicEndFlag = 0;
            _beginthread(BackgroundMusic, 0,
                         (void *) &Temp);                   // Applying multi-threading concept to thread multiple processes at once.
        }
        Intro(IntroClipID, FPS);
        _beginthread(IntroMisc, 0,
                     (void *) &Temp);                             // Applying multi-threading concept to thread multiple processes at once.
        int Count = 0;
        DWORD ConsoleMode;
        INPUT_RECORD InputEvent;
        BOOL Flag = TRUE;
        HANDLE StandardInputHandle = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(StandardInputHandle, &ConsoleMode);
        SetConsoleMode(StandardInputHandle, 0);
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));            // To flush the non-required previous data.
        while (Flag) {
            if ((WaitForSingleObject(StandardInputHandle, 0) == WAIT_OBJECT_0) && (Count != 0)) {
                DWORD ConsoleInputCount;
                ReadConsoleInput(StandardInputHandle, &InputEvent, 1, &ConsoleInputCount);
                if ((InputEvent.EventType == KEY_EVENT) && (InputEvent.Event.KeyEvent.bKeyDown)) {
                    switch (InputEvent.Event.KeyEvent.wVirtualKeyCode) {
                        case VK_RETURN:
                            getch();
                            SetConsoleMode(StandardInputHandle, ConsoleMode);
                            IntroEndFlag = 1;
                            while (IntroEndFlag != 3) {
                                for (int i = 0; (i <= 8) && (IntroEndFlag == 2); i++) {
                                    SetCord(53 + i, 21);
                                    ColorOut('.', 1);
                                    PauseConsole(FPS * (1500 + (200 * i)));
                                    if (i == 8) IntroEndFlag = 3;
                                }
                            }
                            BackgroundMusicFlag = 0;
                            BackgroundMusicID = 0;
                            HOME_MENU();
                            break;
                    }
                }
            }
            Count++;
        }
    }
};

void ExitProgram(void) {
    CursorToggle(0);
    SetConsoleDimensions(DefaultConsoleWidth, DefaultConsoleHeight);
    int Type = SettingsObject.SettingValue[18];
    switch (Type) {
        case 1:
            for (int i = 7; i <= 24; i++) {
                for (int j = 0; j <= 79; j++) {
                    if (i == 24 && j == 79) break;
                    SetCord(j, i);
                    PauseConsole(FPS);
                    cout << " ";
                }
            }
            break;
        case 2:
            srand(time(0));
            for (int n = 0; n <= 10000; n++) {
                int i = rand() % 25;
                int j = rand() % 80;
                while ((i == 24) && (j == 79)) {
                    j = rand() % 78;
                }
                SetCord(j, i);
                cout << " ";
                PauseConsole(FPS * 9);
            }
            SetCord(0, 0);
            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 80; j++) {
                    cout << " ";
                }
            }
            SetCord(0, 12);
            break;
    }
    CursorToggle(1);
}

int main() {
    atexit(ExitProgram);
    SetConsoleTitle(CALCULATOR_TITLE);
    // Initializing Variables.
    InitializeVariable();
    // Creating Main Class Object.
    Calculator CALC;
    cout << setprecision(9);
    // Initializing Class Object
    CALC.Initialize();
    return EXIT_SUCCESS;
}
