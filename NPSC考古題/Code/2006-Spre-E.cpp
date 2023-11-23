// NPSC 2006 初賽 - 題目 E - 漢米頓的麻煩 //
#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX 100
#define MAX_TIME 1000000

using namespace std;

int T[MAX][MAX];

int main()
{
    ifstream fin("pe.in");
    ofstream fout("pe.out");
    int n, m, i, j, k;

    while (1)
    {
        fin >> n;
    //當輸入=0 代表結束，跳出迴圈
        if ( n==0 ) break;
    //---把檔案輸入到陣列資料去---// 
    //---同時把0設定很大的數，代表走不到---//
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
            {
                fin >> T[i][j];
                if ( T[i][j]==0 ) T[i][j]=MAX_TIME;
            }
    //---開始進行三維陣列的flody演算法--//
        for (k=0; k<n; k++)
            for (i=0; i<n; i++)
                for (j=0; j<n; j++)
                    if ( T[i][k]+T[k][j] < T[i][j] )
                        T[i][j]=T[i][k]+T[k][j];
    //---如果起點到終點的距離有被更動的話則輸出m--//
        for (i=0, m=MAX_TIME; i<n; i++)
            if ( T[i][i] < m ) m= T[i][i];
        if ( m < MAX_TIME ) fout << m << endl;
        else fout << -1 << endl;
    }

//    system("PAUSE");
    return 0;
}
