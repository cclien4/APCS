#include <stdio.h>
#include <math.h> /* pow, log10 */
static int poj_1019 (int);
int main (int argc, char ** argv){
    int i,n;
    int k,r;
    
    
        scanf ("%d",&i);
        r = poj_1019 (i);
        printf ("%d ", r);
    
}
unsigned int a[31270];
unsigned int s[31270];
static int poj_1019 (int n){
    int i;
    int length = 0;
    int pos;
    a[1] = 1;
    s[1] = 1;
    for (i=2; i<31270; i++){
        a[i] = a[i-1] + (int)log10((double)i)+1;
        s[i] = s[i-1] + a[i];
    }
    
    for (i=1; s[i]<n; i++){
         ;
    }
    pos = n - s[i-1];
    for (i=1; length < pos; i++){
         length += (int)log10((double)i) + 1;
    }
    return (i-1)/ (int)pow((double)10, length - pos)%10;/*?¤°¤\¤£¬O (i-1)%10 */
}

