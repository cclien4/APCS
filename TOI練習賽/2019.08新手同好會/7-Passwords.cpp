#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int len=str.length();
    int num=0,letter=0,score=0;

    for(int i=0;i<len;i+=1){
        if(isdigit(str[i])) num+=1;
        else if(isalpha(str[i])) letter+=1;
    }
    score+=len*3+letter*3+num*2;
    if(len>7 && letter*num!=0 ) score+=10;
    else score-=5;

    if(num==0 || letter==0) score-=len;
    int n=0;
    for(int i=1;i<len;i+=1){
        if(isdigit(str[i-1])*isdigit(str[i])==1) n+=1;
    }
    score-=n*2;
    cout<<score;
}
