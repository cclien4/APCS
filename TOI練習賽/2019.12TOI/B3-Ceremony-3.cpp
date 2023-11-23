#include <stdio.h>
#include <algorithm>
using namespace std;
struct Students
{
    char ID[10]={};
    char Name[11]={};
};
bool ID0_sort(const Students &s1, const Students &s2) {
        return (s1.ID[0]-'0') < (s2.ID[0]-'0');
}
bool ID8_sort(const Students &s1, const Students &s2) {
        return (s1.ID[8]-'A') < (s2.ID[8]-'A');
}
int main()
{
    int N=0;
    Students stu[10000]={};
    scanf("%d",&N);
    for(int i=0;i<N;i+=1)
    {
        scanf("%s",stu[i].ID);
        scanf("%s",stu[i].Name);
    }
    stable_sort(stu, stu+N, ID0_sort);
    stable_sort(stu, stu+N, ID8_sort);
    for(int i=0;i<N;i+=1)
    {
        printf("%c: %s\n",stu[i].ID[8], stu[i].Name);
    }
}
