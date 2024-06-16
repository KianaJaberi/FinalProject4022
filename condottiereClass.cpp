#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <random>
#include <iterator>
#include "statesClass.cpp" 
#include "playerClass.cpp"
#include "YellowCardsClass.cpp"
#include "purpleCardsClass.cpp"

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
            system ( "cls" ) ;
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
                            std :: cout << colorsList [j] << " " ;
                        }
                        else if ( colorsList [j] == "orange" ){
                            SetConsoleTextAttribute ( color , 6 ) ;
                            std :: cout << colorsList [j] << " " ;
                        }
                        else if ( colorsList [j] == "red" ){
                            SetConsoleTextAttribute ( color , 12 ) ;
                            std :: cout << colorsList [j] << " " ;
                        }
                        else if ( colorsList [j] == "green" ){
                            SetConsoleTextAttribute ( color , 10 ) ;
                            std :: cout << colorsList [j] << " " ;
                        }
                        else if ( colorsList [j] == "blue" ){
                            SetConsoleTextAttribute ( color , 3 ) ;
                            std :: cout << colorsList [j] << " " ;
                        }
                        else if ( colorsList [j] == "purple" ){
                            SetConsoleTextAttribute ( color , 13 ) ;
                            std :: cout << colorsList [j] << " " ;
                        }
                    }

                    SetConsoleTextAttribute ( color , 7 ) ;
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

                system ( "cls" ) ;
            }
        }

        void game (){

            std :: vector < std :: vector < std :: string > > playersCards ( numberOfPlayers , ( std :: vector < std :: string > (10) ) ) ;
            emptyingPlayersCards ( playersCards ) ;

            std :: vector < std :: vector < std :: string > > cardsPlayed ( numberOfPlayers ) ;

            std :: vector < std :: string > cards ;

            std :: vector < int > pass ( numberOfPlayers , 0 ) ; 

            std :: string input ;

            YellowCards yellowCards ;
            yellowCards.fill ( cards ) ;

            PurpleCards purpleCards ;
            purpleCards.fill ( cards ) ;

            int warBadgeHolder = youngestPerson ;

            std :: string selectedState ;

            bool flag = true ;
            
            while ( true ){

                flag = checkCards ( playersCards ) ;
                if ( flag == true ){
                    shuffleCards ( cards , playersCards ) ;
                }

                selectedState = placeOfWar ( warBadgeHolder ) ;

                while ( true ){

                    for ( int i = 0 ; i < numberOfPlayers ; i ++ ){

                        if ( ( warBadgeHolder + i ) == warBadgeHolder ){
                            if ( pass [warBadgeHolder-1] == 0 ){
                                std :: cout << "Are you ready " << players [warBadgeHolder-1].getName () << " ? ( if yes enter 1 )" ;
                                std :: cin >> input ;

                                if ( input == "1" ){
                                    input = display ( warBadgeHolder , cardsPlayed , playersCards [warBadgeHolder-1] , selectedState ) ;
                                    if ( input == "pass" ){
                                        pass [warBadgeHolder-1] = 1 ;
                                    }
                                }
                                else {
                                    std :: cout << "Error !\n" ;
                                    i -- ;
                                }
                            }
                        }
                        else if ( ( warBadgeHolder + i ) > warBadgeHolder && ( warBadgeHolder + i ) <= numberOfPlayers ){
                            if ( pass [(warBadgeHolder+i)-1] == 0 ){
                                std :: cout << "Are you ready " << players [(warBadgeHolder+i)-1].getName () << " ? ( if yes enter 1 )" ;
                                std :: cin >> input ;

                                if ( input == "1" ){
                                    display ( (warBadgeHolder+i) , cardsPlayed , playersCards [(warBadgeHolder+i)-1] , selectedState ) ;
                                    if ( input == "pass" ){
                                        pass [(warBadgeHolder+i)-1] = 1 ;
                                    }
                                }
                                else {
                                    std :: cout << "Error !\n" ;
                                    i -- ;
                                }
                            }
                        }
                        else if ( ( warBadgeHolder + i ) > numberOfPlayers ){
                            if ( pass [(i-warBadgeHolder)-1] == 0 ){
                                std :: cout << "Are you ready " << players [(i-warBadgeHolder)-1].getName () << " ? ( if yes enter 1 )" ;
                                std :: cin >> input ;

                                if ( input == "1" ){
                                    display ( (i-warBadgeHolder) , cardsPlayed , playersCards [(i-warBadgeHolder)-1] , selectedState ) ;
                                    if ( input == "pass" ){
                                        pass [(i-warBadgeHolder)-1] = 1 ;
                                    }
                                }
                                else {
                                    std :: cout << "Error !\n" ;
                                    i -- ;
                                }
                            }
                        }
                    }
                    int counter = 0 ;

                    for ( int i = 0 ; i < numberOfPlayers ; i ++ ){
                        if ( pass [i] == 1 ){
                            counter ++ ;
                        }
                    }
                    if ( counter == numberOfPlayers ){}
                }
            }
        }

        bool checkCards ( std :: vector < std :: vector < std :: string > > vec ){

            for ( int i = 0 ; i < numberOfPlayers ; i ++ ){
                if ( vec [i].size () > 0 ){
                    return false ;
                }
            }
            return true ;
        }

        void emptyingPlayersCards ( std :: vector < std :: vector < std :: string > >& vec ){
            for ( int i = 0 ; i < numberOfPlayers ; i ++ ){
                for ( int j = vec [i].size () ; j > 0 ; j -- ){
                    vec [i].pop_back () ;
                }
            }
        }

        void shuffleCards ( std :: vector < std :: string >& cards , std :: vector < std :: vector < std :: string > >& playersCards ){
            std :: random_device rd;
            std :: mt19937 g(rd());

            shuffle(cards.begin(), cards.end(), g);

            int k = 0 ;

            for ( int i = 0 ; i < numberOfPlayers ; i ++ ){
                for ( int j = 0 ; j < 10 ; j ++ ){
                    playersCards [i][j] = cards [k] ;
                    k ++ ;
                }
                for ( int j = 0 ; j < players [i].numberOfStates () ; j ++ ){
                    playersCards [i].push_back ( cards [k] ) ;
                    k ++ ;
                }
            }

            cards.erase ( cards.begin () , cards.begin () + ( k + 1 ) ) ;
        }

        std :: string display ( int n , std :: vector < std :: vector < std :: string > >& cardsPlayed ,
                                std :: vector < std :: string >& playerCards , std :: string selectedState ){

            for ( int i = 0 ; i < numberOfPlayers ; i ++ ){

                std :: cout << players [i].getName () << " : " ;

                for ( int j = 0 ; j < cardsPlayed [i].size () ; j ++ ){
                    std :: cout << cardsPlayed [i][j] << " , " ;
                }

                std :: cout << "\n" ;
            }

            std :: cout << "_________________________________________\n" ;

            for ( int i = 0 ; i < numberOfPlayers ; i ++ ){

                std :: cout << players [i].getName () << " : " ;

                for ( int j = 0 ; j < 14 ; j ++ ){
                    if ( states.getProprietor (j) == ( i + 1 ) ){
                        std :: cout << states.getStateName (j) << " , " ;
                    }
                }

                std :: cout << "\n" ;
            }

            std :: cout << "_________________________________________\n" ;

            std :: cout << "place of war : " << selectedState << "\n" ;

            while ( true ){

                std :: string input ;
                bool flag = false ;

                for ( int i = 0 ; i < playerCards.size () ; i ++ ){
                    std :: cout << playerCards [i] << " , " ;
                }
                std :: cout << "or pass\n" ;

                std :: cout << "@" << players [n].getName () << " : " ;
                std :: cin >> input ;

                if ( input == "pass" ){
                    return input ;
                }
                else {
                    for ( int i = 0 ; i < playerCards.size () ; i ++ ){
                        if ( playerCards [i] == input ){

                            playerCards.erase ( playerCards.begin () + i ) ;
                            cardsPlayed [n-1].push_back ( input ) ;

                            return input ;
                        }
                    }

                    std :: cout << "Error !\n" ;
                    continue ;
                }
            }
        }

        std :: string placeOfWar ( int warBadgeHolder ){

            std :: string state ;

            while ( true ){

                for ( int i = 0 ; i < 14 ; i ++ ){
                    if ( states.getProprietor (i) == 0 ){
                        std :: cout << states.getStateName (i) << " / " ;
                    }
                }
                std :: cout << "\n" ;

                std :: cout << players [ warBadgeHolder ].getName () << " select a state for war : " ;
                std :: cin >> state ;

                if ( state != "BELLA"  && state != "CALINE"  && state != "ENNA"    &&
                     state != "ATELA"  && state != "PLADACI" && state != "BORGE"   &&
                     state != "DIMASE" && state != "MORINA"  && state != "OLIVADI" &&
                     state != "ROLLO"  && state != "TALMONE" && state != "ARMENTO" &&
                     state != "LIA"    && state != "ELINIA" ){
                    
                    std :: cout << "Error !" << "\n" ;
                    continue ;
                }
                else {
                    return state ;
                }
            }
        }

    private :

        int numberOfPlayers = 0 ;
        int youngestPerson = 0 ;
        std :: vector < Player > players ;
        States states ;
};