#include <iostream>
#include <vector>

class PurpleCards {

    public :

        virtual int getPriority (){
            return priority ;
        }

        void fill ( std :: vector < std :: string >& vec ){
            for ( int i = 0 ; i < 16 ; i ++ ){
                vec.push_back ( "matarsak" ) ;
            }
            for ( int i = 0 ; i < 6 ; i ++ ){
                vec.push_back ( "tabl_zan" ) ;
            }
            for ( int i = 0 ; i < 3 ; i ++ ){
                vec.push_back ( "bahar" ) ;
            }
            for ( int i = 0 ; i < 3 ; i ++ ){
                vec.push_back ( "zemestan" ) ;
            }
            for ( int i = 0 ; i < 3 ; i ++ ){
                vec.push_back ( "shah_dokht" ) ;
            }
        }

    protected :

        int priority ;
};