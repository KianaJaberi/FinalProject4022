#include <iostream>
#include <vector>

class YellowCards {

    public :

        int getPoint ( std :: string card ){
            if ( card == "sarbaz_1" ){
                return 1 ;
            }
            else if ( card == "sarbaz_2" ){
                return 2 ;
            }
            else if ( card == "sarbaz_3" ){
                return 3 ;
            }
            else if ( card == "sarbaz_4" ){
                return 4 ;
            }
            else if ( card == "sarbaz_5" ){
                return 5 ;
            }
            else if ( card == "sarbaz_6" ){
                return 6 ;
            }
            else if ( card == "sarbaz_10" ){
                return 10 ;
            }
        }

        void fill ( std :: vector < std :: string >& vec ){
            for ( int i = 0 ; i < 10 ; i ++ ){
                vec.push_back ( "sarbaz_1" ) ;
            }
            for ( int i = 0 ; i < 8 ; i ++ ){
                vec.push_back ( "sarbaz_2" ) ;
            }
            for ( int i = 0 ; i < 8 ; i ++ ){
                vec.push_back ( "sarbaz_3" ) ;
            }
            for ( int i = 0 ; i < 8 ; i ++ ){
                vec.push_back ( "sarbaz_4" ) ;
            }
            for ( int i = 0 ; i < 8 ; i ++ ){
                vec.push_back ( "sarbaz_5" ) ;
            }
            for ( int i = 0 ; i < 8 ; i ++ ){
                vec.push_back ( "sarbaz_6" ) ;
            }
            for ( int i = 0 ; i < 8 ; i ++ ){
                vec.push_back ( "sarbaz_10" ) ;
            }
        }

    private :
        int point ;
        
};