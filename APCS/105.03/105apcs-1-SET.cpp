#include <iostream>
#include <set>
using namespace std;



int main (){

set<int> mset;
set<int>::iterator it;
int n,i,s,reg=0;
cin>>n;

for (i=1; i<=n; i++) 
{
    cin>>s;
    mset.insert(s);
}
/*
itl=mset.find(4);
mset.erase(itl);
*/
//output ¦¨ÁZ 
for (it=mset.begin(); it!=mset.end();it++){
cout << *it << ' ';
}
cout<<endl;

for (it=mset.begin(); it!=mset.end();it++){
    if(reg<60 && *it>=60){
         cout << reg <<endl;
         cout << *it <<endl;
    }
    reg=*it;     
}
cout << endl;
system("pause");
}
