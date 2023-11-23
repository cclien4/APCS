// NPSC 2006 ���� - �D�� E - �~�̹y���·� //
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
    //���J=0 �N�����A���X�j��
        if ( n==0 ) break;
    //---���ɮ׿�J��}�C��ƥh---// 
    //---�P�ɧ�0�]�w�ܤj���ơA�N������---//
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
            {
                fin >> T[i][j];
                if ( T[i][j]==0 ) T[i][j]=MAX_TIME;
            }
    //---�}�l�i��T���}�C��flody�t��k--//
        for (k=0; k<n; k++)
            for (i=0; i<n; i++)
                for (j=0; j<n; j++)
                    if ( T[i][k]+T[k][j] < T[i][j] )
                        T[i][j]=T[i][k]+T[k][j];
    //---�p�G�_�I����I���Z�����Q��ʪ��ܫh��Xm--//
        for (i=0, m=MAX_TIME; i<n; i++)
            if ( T[i][i] < m ) m= T[i][i];
        if ( m < MAX_TIME ) fout << m << endl;
        else fout << -1 << endl;
    }

//    system("PAUSE");
    return 0;
}
