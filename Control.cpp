#include <iostream>
#include "Control.h"


int Control :: getNumber(){return number ;}

void Control:: setNumber(int n){number=n;}

void Control :: getData(){
    std :: cout << "Enter tne numbers of players : " ;
    std :: cin >> number;
    for (int i = 0; i < number; i++)
    {
        Player newPlayer;
        std :: cout << "Enter the name and age of player" << i+1 << " : " ;
        std :: cin >> name >> age;
        newPlayer.setAge(age);
        newPlayer.setName(name);
        play.push_back(newPlayer);
    }
    dealCardsToPlayers();
}

void Control :: dealCardsToPlayers(){
    for (int i = 0 ; i < number ; i++) {
        std :: vector < std :: string > hand = card.dealCards(10);
        play[i].setHand(hand);
    }
}

int Control :: CheckSmall(){
    std :: vector<int>temp(1);
    int j=0;
    temp[0]= play[0].getAge();
    for(int i=1 ; i<number ; i++){
        if(temp[0]>play[i].getAge())
        {
            temp[0]=play[i].getAge();
            j=i;
        }
    }
    return j;

}

void Control :: show(){
    std :: cout << play[CheckSmall()].getAge() << play[CheckSmall()].getName() << "\n-----" << std :: endl;

	std :: vector< std :: vector< std :: string>> playersYelCards(number);

	for (int i = 0; i < number; i++) {
		std :: cout << "player " << (i + 1) << " : ";
		for (const auto& card : play[i].getHand()) {
			std :: cout << card << " / ";
			if (card.find("yel") == 0) {
				playersYelCards[i].push_back(card); 
			}
		}
		std :: cout << std ::endl;
	}

	for (int i = 0; i < number; i++) {
		std :: cout << "yel cards for player " << (i + 1) << " : ";
		for (const auto& yelCard : playersYelCards[i]) {
			std :: cout << yelCard << " / ";
		}
		std :: cout << std ::endl;
	}
}

        
std :: vector < std :: string > Control :: checkSarbaz(int i){
    for(int j=0 ; j<play[i].getHand().size() ; j++){
        if(play[i].getHand()[j]=="yel1"||play[i].getHand()[j]=="yel2"|| play[i].getHand()[j]=="yel3" ||play[i].getHand()[j]=="yel4"
        ||play[i].getHand()[j]=="yel5" ||play[i].getHand()[j]=="yel6"||play[i].getHand()[j]=="yel10")
        {
            sarbaz.push_back(play[i].getHand()[j]); 
        }
    }
    return sarbaz ;
}