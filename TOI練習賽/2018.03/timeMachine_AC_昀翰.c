#include <stdio.h>
int N, M, ok;

void DFS(int i, int x)
{
	if(ok) return;
	if(x == M) { ok=1; return; }
	printf("DFS(%d, %d)\n", i, x);
	int shift = 2*i - 1;
	if(x+shift < N) DFS(i+1, x+shift);
	if(x-shift > 0) DFS(i+1, x-shift);
}

int main(int argc, char **argv)
{ 
	scanf("%d%d", &N, &M);
	DFS(2, 1);
	printf("%s\n", ok?"We can save the world!!":"No!!");
	system("pause");
	return 0;
}
