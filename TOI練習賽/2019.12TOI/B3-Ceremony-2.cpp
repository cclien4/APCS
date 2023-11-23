#include <iostream>
using namespace std;
int main()
{
    int N=0;
    char id[100][10]={}, name[100][11]={};
    cin>>N;
    for(int i=0;i<N;i+=1)
    {
        cin>>id[i]>>name[i];
    }
    for(int i=0;i<N;i+=1)
    {
        for(int j=0;j<N-i-1;j+=1)
        {
            if(id[j][8]>id[j+1][8])
            {
                swap(id[j],id[j+1]);
                swap(name[j],name[j+1]);
            }
            else if(id[j][8]==id[j+1][8] && id[j][0]>id[j+1][0])
            {
                swap(id[j],id[j+1]);
                swap(name[j],name[j+1]);
            }
        }
    }
    for(int i=0;i<N;i+=1)
    {
        cout<<id[i][8]<<": "<<name[i]<<endl;
    }
}

