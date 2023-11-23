#include <iostream>
using namespace std;

int main(void) {
    string str;
    char c; // 目標char
    while (cin >> str) {
        int curr = -1; //前一個特定char位置
        cin >> c;
        c = tolower(c); //統一用小寫
        for (int i = 0; i < str.length(); i++) {
            if (tolower(str[i]) == c) {
                if (curr == -1) curr = i; //如果剛開頭不用印出i-curr
                else {
                    cout << i - curr << " ";
                    curr = i;
                }
            }
        }
        cout << endl;
    }
}
