#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>


using namespace std ;

class States {

    public:

        bool vicinityStatus ( int state1 , int state2 ){
            if ( states [state1][state2] == 1 ){
                return true ;
            }
            else {
                return false ;
            }
        }

        void setProprietor ( int player , int state ){
            proprietor [state] = player ;
        }
        
        int getProprietor ( int state ){
            return proprietor [state] ;
        }

        std :: string getStateName ( int s ){
            switch (s){
                case 0 : return "BELLA" ;
                case 1 : return "CALINE" ;
                case 2 : return "ENNA" ;
                case 3 : return "ATELA" ;
                case 4 : return "PLADACI" ;
                case 5 : return "BORGE" ;
                case 6 : return "DIMASE" ;
                case 7 : return "MORINA" ;
                case 8 : return "OLIVADI" ;
                case 9 : return "ROLLO" ;
                case 10 : return "TALMONE" ;
                case 11 : return "ARMENTO" ;
                case 12 : return "LIA" ;
                case 13 : return "ELINIA" ;
            }
        }

    private:

        int states [14][14] = { {0,1,0,0,1,1,0,0,0,0,0,0,0,0},//BELLA
                                {1,0,1,1,1,1,0,0,0,0,0,0,0,0},//CALINE
                                {0,1,0,1,0,1,1,0,0,0,0,0,0,0},//ENNA
                                {0,1,1,0,0,0,1,0,0,0,0,0,0,0},//ATELA
                                {1,1,0,0,0,1,0,1,0,1,0,0,0,0},//PLADACI
                                {1,1,1,0,1,0,1,1,1,0,0,0,0,0},//BORGE
                                {0,0,1,1,0,1,0,0,1,0,0,0,0,0},//DIMASE
                                {0,0,0,0,1,1,0,0,1,1,1,1,0,0},//MORINA
                                {0,0,0,0,0,1,1,1,0,0,0,1,1,0},//OLIVADI
                                {0,0,0,0,1,0,0,1,0,0,1,0,0,1},//ROLLO
                                {0,0,0,0,0,0,0,1,0,1,0,1,0,1},//TALMONE
                                {0,0,0,0,0,0,0,1,1,0,1,0,1,0},//ARMENTO
                                {0,0,0,0,0,0,0,0,1,0,0,1,0,0},//LIA
                                {0,0,0,0,0,0,0,0,0,1,1,0,0,0},//ELINIA
                               };
        int proprietor [14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
};

class Player {

    public :

        Player (){
        }

        void setAge ( int a ){
            if ( age > 0 )
                age = 0 ;
            else
                age = 0 ;
        }

        int getAge (){
            return age ;
        }

        void setName ( std :: string n ){
            name = n ;
        }

        std :: string getName (){
            return name ;
        }

        void setColor ( std :: string c ){
            color = c ;
        }

        std :: string getColor (){
            return color ;
        }

        void setStates ( int s ){
            states.push_back (s) ;
        }

        bool getStates ( int s ){
            for ( int i = 0 ; i < states.size () ; i ++ ){
                if ( states [i] == s )
                    return true ;
                else 
                    return false ;
            }
        }

        int numberOfStates (){
            return states.size () ;
        }

    private :

        int age ;
        std :: string name ;
        std :: string color ;
        std :: vector <int> states ;
};

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

            random_device rd;
            mt19937 g(rd());
            shuffle(cards.begin(), cards.end(), g);

            //////////////////////////////////////////////
        }

    private :

        int numberOfPlayers = 0 ;
        int youngestPerson = 0 ;
        std :: vector < Player > players ;
        std :: vector < std :: string > cards ={"sarbaz1","sarbaz1","sarbaz1","sarbaz1","sarbaz1","sarbaz1","sarbaz1"
        ,"sarbaz1","sarbaz1","sarbaz1","sarbaz2","sarbaz2","sarbaz2",
        "sarbaz2","sarbaz2","sarbaz2","sarbaz2","sarbaz2","sarbaz3","sarbaz3","sarbaz3"
        ,"sarbaz3","sarbaz3","sarbaz3","sarbaz3","sarbaz3","sarbaz4","sarbaz4","sarbaz4",
        "sarbaz4","sarbaz4","sarbaz4","sarbaz4","sarbaz4","sarbaz5","sarbaz5","sarbaz5","sarbaz5","sarbaz5",
        "sarbaz5","sarbaz5","sarbaz5","sarbaz6","sarbaz6","sarbaz6",
        "sarbaz6","sarbaz6","sarbaz6","sarbaz6","sarbaz6","sarbaz10","sarbaz10","sarbaz10","sarbaz10",
        "sarbaz10","sarbaz10","sarbaz10","sarbaz10",
        "zemestan","zemestan","zemestan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","bahar",
        "bahar","bahar","shah_dokht","shah_dokht","shah_dokht","matarsak","matarsak","matarsak","matarsak","matarsak",
        "matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak",
        "matarsak"} ;
};

int main (){

    Condottiere c ;
    c.setNumberOfPlayers () ;
    c.setInformations () ;

    return 0 ;
}