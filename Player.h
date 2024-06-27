#include <string>
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public:
        int getAge();
        std :: string getName();
        void setAge(int a);
        void setName( std :: string n );

        std::vector< std :: string > getHand();
        void setHand( std :: vector< std :: string > h );

    private: 
        int age;
        std :: string name ;
        std :: vector< std :: string >hand;
};

#endif // !PLAYER_H
