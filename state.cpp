#include <iostream>

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