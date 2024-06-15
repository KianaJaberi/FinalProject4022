#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>

using namespace std ;

int main() {
    // ایجاد وکتور از رشته‌ها
    vector<string> cards = {
        "yel1", "yel2", "yel3", "yel4", "yel5", "yel6", "yel7", "yel8", "yel9", "yel10",
        // ... (سایر کارت‌ها)
        "matarsak"
    };

    // بر بزندن کارت‌ها
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);

    for (const auto& card : cards) {
       cout << card << "\n" ;
    }
    cout << "\n\n" ;

    // فرض کنید می‌خواهیم تعداد n کارت به بازیکنان بدهیم
    int n = 5; // تعداد کارت‌هایی که می‌خواهید حذف شوند

    // حذف n کارت از ابتدای وکتور
    cards.erase(cards.begin(), cards.begin() + n);

    // چاپ کارت‌های باقیمانده
    for (const auto& card : cards) {
       cout << card << "\n" ;
    }

    return 0;
}