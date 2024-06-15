#include <iostream>
#include <windows.h>

using namespace std ;

int main (){

    HANDLE color ;
	color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;

    for ( int i = 0 ; i < 15 ; i ++ ){
        SetConsoleTextAttribute ( color , i ) ;
        cout << i << endl ;
    }
    
    return 0 ;
}