#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    char c;
    int num, x=0, y=0;
    cin >> c;
    cin >> c;
    while(c!='E'){
                  cin >> num;
                  switch(c){
                            case 'X':
                                 x = num;
                                 break;
                            case 'Y':
                                 y = num;
                                 break;
                            case 'U':
                                 y += num;
                                 break;
                            case 'D':
                                 y -= num;
                                 break;
                            case 'L':
                                 x -= num;
                                 break;
                            case 'R':
                                 x += num;
                                 break;
                  }
                  cin >> c;
    }
    cout << x << endl << y << endl;
    system("PAUSE");
    return 0;
}
