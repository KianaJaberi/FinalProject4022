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

            int age ;
            int smallestAge = 100 ;
            std :: string input ;
            Player newPlayer ;
            std :: vector < std :: string > colorsList = { "yellow" , "orange" , "red" ,
                                                           "green"  , "blue"   , "purple" } ;
            HANDLE color ;
	        color = GetStdHandle ( STD_OUTPUT_HANDLE ) ;

            for ( int i = 1 ; i <= numberOfPlayers ; i ++ ){

                std :: cout << "Enter the name of player (" << i << ") : " ;
                std :: cin >> input ;

                newPlayer.setName ( input ) ;

                while ( true ){
                
                    std :: cout << "Enter the age of player (" << i << ") : " ;
                    std :: cin >> age ;

                    if ( age <= 0 ){
                        std :: cout << "Error !\n" ;
                        continue ;
                    }
                    else {
                        newPlayer.setAge (age) ;

                        if ( age < smallestAge ){
                            smallestAge = age ;
                            youngestPerson = i ;
                        }
                        break ;
                    }
                }

                while ( true ){

                    for ( int j = 0 ; j < colorsList.size () ; j ++ ){

                        if ( colorsList [j] == "yellow" ){
                            SetConsoleTextAttribute ( color , 14 ) ;
                            std :: cout << colorsList [j] ;
                        }
                        else if ( colorsList [j] == "orange" ){
                            SetConsoleTextAttribute ( color , 6 ) ;
                            std :: cout << colorsList [j] ;
                        }
                        else if ( colorsList [j] == "red" ){
                            SetConsoleTextAttribute ( color , 12 ) ;
                            std :: cout << colorsList [j] ;
                        }
                        else if ( colorsList [j] == "green" ){
                            SetConsoleTextAttribute ( color , 10 ) ;
                            std :: cout << colorsList [j] ;
                        }
                        else if ( colorsList [j] == "blue" ){
                            SetConsoleTextAttribute ( color , 3 ) ;
                            std :: cout << colorsList [j] ;
                        }
                        else if ( colorsList [j] == "purple" ){
                            SetConsoleTextAttribute ( color , 13 ) ;
                            std :: cout << colorsList [j] ;
                        }

                        SetConsoleTextAttribute ( color , 7 ) ;
                        std :: cout << "  " ;
                    }

                    std :: cout << "\nEnter the color of player (" << i << ") : " ;
                    std :: cin >> input ;

                    if ( input != "yellow" && input != "orange" && input != "red" &&
                         input != "green"  && input != "blue"   && input != "purple" ){

                        std :: cout << "Error !\n" ;
                        continue ;
                    }
                    else {
                        newPlayer.setColor ( input ) ;

                        for ( int j = 0 ; j < colorsList.size () ; j ++ ){
                            if ( colorsList [j] == input ){
                                colorsList [j] = "null" ;
                            }
                        }
                        break ;
                    }
                }
                players.push_back ( newPlayer ) ;
                std :: cout << "\n" ;
            }
        }

        void game (){

            std :: vector < std :: vector < std :: string > > playersCards ( numberOfPlayers , ( std :: vector < std :: string > (10) ) ) ;
            bool flag = true ;
            
            while ( true ){

                flag = checkCards ( playersCards ) ;
                if ( flag == true ){}
            }
        }

        bool checkCards ( std :: vector < std :: vector < std :: string > > vec ){

            for ( int i = 0 ; i < numberOfPlayers ; i ++ ){
                for ( int j = 0 ; j < vec [i].size () ; j++ ){
                    if ( vec [i][j] != "null" ){
                        return false ;
                    }
                }
            }
            return true ;
        }

        void shuffleCards ( std :: vector < std :: vector < std :: string > >& vec ){
            
        }

    private :

        int numberOfPlayers = 0 ;
        int youngestPerson = 0 ;
        std :: vector < Player > players ;
        //std :: vector < std :: string > 
};