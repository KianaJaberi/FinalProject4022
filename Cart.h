#include <string>
#include <vector>

#ifndef CART_H
#define CART_H

class Cart{
    public:
        void shuffleArray(std :: vector< std :: string>& arr, int n);
        std :: vector < std :: string > dealCards(int numCards);

    private:
        std :: vector < std :: string > cards={"yel1","yel1","yel1","yel1","yel1","yel1","yel1","yel1","yel1","yel1","yel2","yel2",
        "yel2","yel2","yel2","yel2","yel2","yel2","yel3","yel3","yel3","yel3","yel3","yel3","yel3","yel3","yel4","yel4","yel4",
        "yel4","yel4","yel4","yel4","yel4","yel5","yel5","yel5","yel5","yel5","yel5","yel5","yel5","yel6","yel6","yel6",
        "yel6","yel6","yel6","yel6","yel6","yel10","yel10","yel10","yel10","yel10","yel10","yel10","yel10",
        "zemestan","zemestan","zemestan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","tabl_zan","bahar",
        "bahar","bahar","shah_dokht","shah_dokht","shah_dokht","matarsak","matarsak","matarsak","matarsak","matarsak",
        "matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak","matarsak",
        "matarsak"};
    
};


#endif // !CART_H
