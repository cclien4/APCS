#include <iostream>
using namespace std;

int main() {
    int AMOUNT;  

    while (cin >> AMOUNT) {
    if (AMOUNT >= 0 && AMOUNT <= 10)    
        cout << AMOUNT * 6 << endl;   
    else if (AMOUNT >= 11 && AMOUNT <= 20)
        cout << 60 + (AMOUNT - 10) * 2 << endl;    
    else if (AMOUNT >= 21 && AMOUNT <= 40)
        cout << 80 + (AMOUNT - 20) << endl;    
    else if (AMOUNT > 40)
        cout << 100 << endl;    
    }
}
