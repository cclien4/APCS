// NPSC 2008 �����ըM�� 
// �D�� H - ���X�������{ 
// By sagit at TCGS
#include <cstdlib>
#include <cstdio>

using namespace std;

const int MAX=1002, VERY_LONG=100000;
int G[MAX][MAX], D[MAX], V[MAX], Ans[MAX], An, Num, Dis;
// G �O�����I�������Z��, D �O����Y�I���̵u�Z��, V �O�����I�O�_�w���� 
// Ans �O������, An �����׭Ӽ�, Num ���I���`��, Dis ���n�D���Z�� 

int main()
{
    freopen("ph.in", "rt", stdin);
    freopen("ph.out", "w+t", stdout);
    int k, m, i, j, a, b, c;
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d%d%d", &Num, &m, &Dis);
        for (i=1; i<=Num; i++)          // �N�Ҧ��I���Z���]���ܤj 
            for (j=1; j<=Num; j++)
                G[i][j]=VERY_LONG;
        for (i=0; i<m; i++)             // ��J�C���I���Z�� 
        {
            scanf("%d%d%d", &a, &b, &c);
            if (a==b||G[a][b]<c) continue; // �s��ۤv�έ��ЦӸ������䤣�B�z 
            G[a][b]=c;
        }
        for (i=1, An=0; i<=Num; i++)    // �v�I�� Dijkstra 
        {
            for (j=1; j<=Num; j++)      // �ҩl�ưʧ@ 
                D[j]=G[i][j], V[j]=0;
            while (1)
            {
                for (j=1, a=0, b=VERY_LONG-1; j<=Num; j++) // ��@�ӳ̪��I 
                    if (!V[j]&&D[j]<b) a=j, b=D[j];
                if (a==0||b>Dis) break; // �䤣��N���} 
                V[a]=1;
                for (j=1; j<=Num; j++)  // �H���I��s�۾F�I���Z�� 
                    if (!V[j]&&D[a]+G[a][j]<D[j]) D[j]=D[a]+G[a][j];
                if (D[i]<=Dis)          // �Y�^����I�b���w�Z����, �h��쵪�� 
                {
                    Ans[An++]=i;
                    break;
                }
            }
        }
        printf("%d\n", An);             // �C�L���� 
        for (i=0; i<An; i++)
        {
            if (i>0) printf(" ");
            printf("%d", Ans[i]);
        }
        printf("\n");
    }
//    system("PAUSE");
    return 0;
}
