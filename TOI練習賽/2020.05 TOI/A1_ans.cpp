#include<iostream>
using namespace std;
int main()
{
    int a1,a2,a3;
    int b1,b2,b3;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;

    int ans = 1;
    while(true)
    {
        if(ans%a1 == b1 && ans%a2 == b2 && ans%a3 == b3)
        {
            cout << ans  << endl;
            return 0;
        }
        ans++;
    }
    return 0;
}
