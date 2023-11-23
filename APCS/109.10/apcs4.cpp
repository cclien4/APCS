#include<bits/stdc++.h>
using namespace std;

int qry[100001][2]={};
int  cnt_grp[450]={};
bool cnt_one[200001]={};

/* �����B�z */
int grp_sz;
void ChunkQuery(int qL,int qR,long &ans_sum){
	int grp_qL=qL/grp_sz;
	int grp_qR=qR/grp_sz;
	/* �Q�׬O�_ ���b�P�@�Ӭd�߰϶������p�H */
	if(grp_qL==grp_qR){
		for(int i=qL+1; i<qR; i++)
			ans_sum+=cnt_one[i];
	}else{
		for(int i=qL+1; i<(grp_qL+1)*grp_sz;i++)
			ans_sum+=cnt_one[i];
		for(int i=grp_qL+1; i<grp_qR; i++)
			ans_sum+=cnt_grp[i];
		for(int i=grp_qR*grp_sz;i<qR;i++)
			ans_sum+=cnt_one[i];
	}
	/*��s��Ӹ`�I�M�U�۩��ݪ��϶���T */
	cnt_one[qL]+=1; cnt_grp[grp_qL]+=1;
	cnt_one[qR]+=1; cnt_grp[grp_qR]+=1;
}

int main(){
	int uN, N, num;
	scanf("%d\n",&uN); 
	/* �I�Ƭ�2���A�ó]�w�϶��j�p */
	N=uN<<1;
	grp_sz=sqrt(N);
	/* Ū���Ʀr�ɨ��x�s�d�߶��ǡA�Y�O�Ĥ@����J�h qry[num][0]==0 */
	for(int i=1;i<=N;i++){
		scanf("%d",&num);
		qry[num][ qry[num][0]>0 ]=i;
	}
	long ans_sum=0;
	for(int i=1;i<=uN;i++)
		ChunkQuery(qry[i][0],qry[i][1],ans_sum);
	printf("%ld\n",ans_sum);
}
