#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

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
    public:
        void shuffleArray(string arr[], int n) {
            srand(time(nullptr));
            for (int i = n - 1; i > 0; --i) {
                int j = rand() % (i + 1);
                swap(arr[i], arr[j]);
            }
        }

        void print(int n){
            shuffleArray(cards , 89);
            for (int i = 0; i <89; i +=n ) {
                cout << "Player " << (i / n) + 1 << " : ";
                for (int j = 0; j < 10; ++j){
                    cout << cards[i + j] << " / ";
                }
            cout << endl;
            }
        }

    private:
        string cards[89]={"yel1","yel1","yel1","yel1","yel1","yel1","yel1","yel1","yel1","yel1","yel2","yel2","yel2",
        "yel2","yel2","yel2","yel2","yel2","yel3","yel3","yel3","yel3","yel3","yel3","yel3","yel3","yel4","yel4","yel4",
        "yel4","yel4","yel4","yel4","yel4","yel5","yel5","yel5","yel5","yel5","yel5","yel5","yel5","yel6","yel6","yel6",
        "yel6","yel6","yel6","yel6","yel6","yel10","yel10","yel10","yel10","yel10","yel10","yel10","yel10",
        "zemestan","zemestan","zemestan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","bahar",
        "bahar","bahar","shah_dokht","shah_dokht","shah_dokht","matarsak","matarsak","matarsak","matarsak","matarsak",
        "matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak",
        "matarsak"};

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
        //Control(int num):number(num){};
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
            printShuffle();
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
        void printShuffle(){
            switch (getNumber())
            {
            case 3:
                card.print(30);
                break;
            case 4:
                card.print(25);
                break;
            case 5:
                card.print(19);
                break;
            case 6:
                card.print(15);
                break;
            default:
                break;
            }
        }
    private:
        int number , age ;
        string name;
        Cart card;
        vector<Player>play;
};


int main(){
    Control cont;
    cont.getData();
    Cart cardes;    
    return 0;
}

