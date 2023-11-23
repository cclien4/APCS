#include<iostream>
using namespace std;

int main()
{
	int M, N;
	cin>>M>>N;
	int ant=0, grasshopper=0;
	for(int i=0; i<M; ++i)
	{
		int a;
		cin>>a;
		ant += a;
	}
	for(int j=0; j<N; ++j)
	{
		int g;
		cin>>g;
		grasshopper += g;
	}
	if(ant>grasshopper && M>N)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
}
