#include <string>
#include <vector>
#include "Player.h"
#include "Cart.h"

#ifndef CONTROL_H
#define CONTROL_H
class Control{
    public:
        int getNumber();
        void setNumber(int n);

        void getData();

        void dealCardsToPlayers();

        int CheckSmall();
        void show();
        
        std :: vector < std :: string > checkSarbaz(int i);
    private:
        int number , age ;
        std :: string name;
        Cart card;
        std :: vector < Player > play;
        std :: vector < std :: string > sarbaz ;
};

#endif // !CONTROL_H