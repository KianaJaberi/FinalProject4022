#include <iostream>
#include <vector>

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

    private :
        int age ;
        std :: string color ;
        std :: vector <int> states ;
};