#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N;

string itos(int x) {
       string ans;
       while(x) {ans += char(x%10+'0'); x /= 10;}
       reverse(ans.begin(),ans.end());
       return ans;
}

int main() {
    while(cin>>N) {
        string s="1";
        int back = 2;
        while(N>s.size()) {
            N-=s.size();
            s += itos(back++);
        }
        cout<<s[N-1]<<endl;
    }
    system("pause");
    return 0;   
}
