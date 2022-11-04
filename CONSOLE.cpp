//THIS CONTAINS CONSOLE CODES
#include <iostream>
#include <conio.h>  //IMPROTANT
#include <windows.h>    //IMPORTANT
using namespace std;
//DATA & VARIABLES
int k,x,y;
//PROTOTYPES
void gotoxy(int x, int y);
void colorscale();
void demo();
//IMPLEMENTS
void gotoxy(int x, int y){
    COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void colorscale(){
    HANDLE colorize = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k = 1; k < 255; k++){
        // pick the color attribute k you want
        SetConsoleTextAttribute(colorize, k);
        cout << k << " TECH NO BRAIN " << endl;
    }
}
void demo(){
    cout << "   (_____)  (_)_  (_)    (_)     (_)  (_)   (____)   " << endl;
    cout << "  (_)___    (___)_(_)  (_)__(_)  (_)_(_)   (_)___    " << endl;
    cout << "   (____)   (_) (___)  (______)  (____)     (____)   " << endl;
    cout << "   ____(_)  (_)  (__)  (_)  (_)  (_) (_)   (_)___    " << endl;
    cout << "  (_____)   (_)   (_)  (_)  (_)  (_)  (_)   (____)    "<< endl;
    while(!kbhit()){
        system("Color 02");
        system("Color 01");
        system("Color 0D");
        system("Color 04");
        system("Color 00");
        system("Color 07");
        //Sleep(1000); //Delay in console
    }
	system("cls");
}

int main()
{
    // TEST GOTO XY
    /*
    cout << "X: "; cin >> x;
    cout << "Y: "; cin >> y;
    gotoxy(x,y);
    cout << "O";*/

    demo();// TEST COLOR CHANGES

    //colorscale(); //COLOR ATTRIBUTE TEST
    return 0;
}
