#include <iostream>

class State {
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