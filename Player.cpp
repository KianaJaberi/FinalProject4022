#include "Player.h"

int Player :: getAge(){ return age; }

std :: string Player :: getName(){ return name; }

void Player :: setAge(int a){ age=a; }

void Player :: setName( std :: string n){ name=n; }

std::vector< std :: string> Player :: getHand(){ return hand; }

void Player :: setHand( std :: vector< std :: string > h ){ hand=h; }