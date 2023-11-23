#include<stdio.h>

int Fibonacci(int n)
{
    if(n == 1)
        return n;

    return (Fibonacci(n-1)+Fibonacci(n-2));
}

int main()
{
	int N = 0;
	scanf("%d",&N);

	int h = 0, w = 0;
	h = Fibonacci(N);
	w = h + Fibonacci(N-1)

	printf("%d:%d",h,w);
	return 0;
}

