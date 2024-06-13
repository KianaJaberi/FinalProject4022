#include <iostream>
#include <vector>
#include <windows.h>
#include "player.cpp"

class Condottiere {

    public :
        void setNumberOfPlayers (){
            int num ;

            while ( true ){
                
                std :: cout << "Enter the number of players : " ;
                std :: cin >> num ;

                if ( num >= 3 ){
                    numberOfPlayers = num ;
                    break ;
                }
                else {
                    std :: cout << "Error !\n" ;
                    continue ;
                }
            }
        }

        void setInformations (){
            std :: string name ;
            std :: string color1 ;
            int age ;
            Player newPlayer ;
            HANDLE color ;
	        color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;

            for ( int i = 1 ; i <= numberOfPlayers ; i ++ ){

                std :: cout << "Enter the name of player (" << i << ") : " ;
                std :: cin >> name ;
                newPlayer.setName (name) ;

                while ( true ){
                
                    std :: cout << "Enter the age of player (" << i << ") : " ;
                    std :: cin >> age ;

                    if ( age <= 0 ){
                        std :: cout << "Error !\n" ;
                        continue ;
                    }
                    else {
                        newPlayer.setAge (age) ;
                        break ;
                    }
                }

                while ( true ){
                    SetConsoleTextAttribute ( color , 14 ) ;
                    std :: cout << "yellow , " ;
                    SetConsoleTextAttribute ( color , 6 ) ;
                    std :: cout << "orange , " ;
                    SetConsoleTextAttribute ( color , 12 ) ;
                    std :: cout << "red , " ;
                    SetConsoleTextAttribute ( color , 10 ) ;
                    std :: cout << "green , " ;
                    SetConsoleTextAttribute ( color , 3 ) ;
                    std :: cout << "blue or " ;
                    SetConsoleTextAttribute ( color , 13 ) ;
                    std :: cout << "purple\n" ;
                    std :: cout << "Enter the color of player (" << i << ") : " ;

                    SetConsoleTextAttribute ( color , 7 ) ;
                    std :: cin >> color1 ;

                    if ( color1 != "yellow" && color1 != "orange" && color1 != "red" &&
                         color1 != "green" && color1 != "blue" && color1 != "purple" ){

                        std :: cout << "Error !\n" ;
                        continue ;
                    }
                    else {
                        newPlayer.setColor ( color1 ) ;
                        break ;
                    }
                }
                players.push_back ( newPlayer ) ;
            }
        }

    private :
        int numberOfPlayers ;
        std :: vector < Player & > players ;

};