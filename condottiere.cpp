#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class State{
    public:
        void setState(){
        int state[14][14]={{0,1,0,0,1,1,0,0,0,0,0,0,0,0}    //BELLA
                          ,{1,0,1,1,1,1,0,0,0,0,0,0,0,0}    //CALINE
                          ,{0,1,0,1,0,1,1,0,0,0,0,0,0,0}    //ENNA
                          ,{0,1,1,0,0,0,1,0,0,0,0,0,0,0}    //ATELA
                          ,{1,1,0,0,0,1,0,1,0,1,0,0,0,0}    //PLADACI
                          ,{1,1,1,0,1,0,1,1,1,0,0,0,0,0}    //BORGE
                          ,{0,0,1,1,0,1,0,0,1,0,0,0,0,0}    //DIMASE
                          ,{0,0,0,0,1,1,0,0,1,1,1,1,0,0}    //MORINA
                          ,{0,0,0,0,0,1,1,1,0,0,0,1,1,0}    //OLIVADI
                          ,{0,0,0,0,1,0,0,1,0,0,1,0,0,1}    //ROLLO
                          ,{0,0,0,0,0,0,0,1,0,1,0,1,0,1}    //TALMONE
                          ,{0,0,0,0,0,0,0,1,1,0,1,0,1,0}    //ARMENTO
                          ,{0,0,0,0,0,0,0,0,1,0,0,1,0,0}    //LIA
                          ,{0,0,0,0,0,0,0,0,0,1,1,0,0,0}    //ELINIA
                          };  
        }


    private:
        int state[14][14];
};

class Cart{



};

class Player{
    public:
        int getAge(){return age;}
        string getName(){return name;}
        void setAge(int a){age=a;}
        void setName(string n){name=n;}

    private: 
        int age;
        string name ;
};

class Control{
    public:
        int getNumber(){return number ;}
        void setNumber(int n){number=n;}

        void getData(){
            cout << "Enter tne numbers of players : " ;
            cin >> number;
            for (int i = 0; i < number; i++)
            {
                Player newPlayer;
                cout << "Enter the name and age of players : ";
                cin >> name >> age;
                newPlayer.setAge(age);
                newPlayer.setName(name);
                play.push_back(newPlayer);
            }
        }

        int CheckSmall(){
            vector<int>temp(1);
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
        void show(){
            cout << play[CheckSmall()].getAge() << play[CheckSmall()].getName()<< "\n-----" <<endl;
            for(int i=0 ; i<number ; i++){
                cout<< play[i].getAge() << " "<< play[i].getName() <<endl;
            }
        }

    private:
        int number , age ;
        string name;
        vector<Player>play;
};

int main(){
    Control cont;
    cont.getData();
    cont.show();
    
    return 0;
}

