#include <bits/stdc++.h> 

using namespace std;

int scan(char s[100],int a,int b)
{
    int i = a;            // �j�ƪ��Ʀr��m
    int j = b;   			// �r�ꪺ�r����m
    int num=0;
    int c[a];
    while(i>=b)
    {
    	c[i-b] = s[j++] - '0';   // �r���Y���A�ˡA�s�J�}�C
		i=i-1;
	}
	for(j=0;j<=a-b;j++)
		num=num+c[j]*pow(10,j);
	return num;
}

int compute(int a,int b,int op)
{
	if(op==1)
		return a+b;
	else if(op==2)
		return a-b;
	else if(op==3)
		return a*b;
	else
		return a/b;	
}

int main()
{
	char s[100];
	int a1,a2,s1,reg_n,op; //a1=num1 a2=num2 s1=sum op =+-*/  //�^����ƥ� 
	int a[8],err_cnt=0;//a[2]�̦h��� [3]�T�ӼƦr    //�@���}�C��K�᭱��� 
	int ans_cnt=0,reg_a,reg_b,reg_c; //reg_ab reg outputdata
	int n;
	
	//while(cin>>s)
	cin>>n;
	while(n!=0)
	{
	//==================��J���^�������===================// 
		cin>>s;
		
			for(int i=0;i<strlen(s);i++)
			{
				if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
					{
						a1=scan(s,i-1,0);
						if(s[i]=='+') op=1;
						else if(s[i]=='-') op=2;
						else if(s[i]=='*') op=3;
						else if(s[i]=='/') op=4;
						reg_n=i+1;
					}
				else if(s[i]=='=')
					{
						a2=scan(s,i-1,reg_n);
						reg_n=i+1;				
					}
				else if(i==strlen(s)-1)
					{
						//cout<<strlen(s)<<reg_n<<endl;
						s1=scan(s,i,reg_n);
					}
			}
			//==================��J���^�������===================//
		//==========�P�_�O�_���~===============//	
		if(op==1)
		{
			if(a1+a2!=s1)
			{
				a[err_cnt*3+0]=a1;
				a[err_cnt*3+1]=a2;
				a[err_cnt*3+2]=s1;
				a[err_cnt+6]=1;
				err_cnt++;
			}
		}
		else if(op==2)
		{
			if(a1-a2!=s1)
			{
				a[err_cnt*3+0]=a1;
				a[err_cnt*3+1]=a2;
				a[err_cnt*3+2]=s1;
				a[err_cnt+6]=2;
				err_cnt++;
			}
		}
		else if(op==3)
		{
			if(a1*a2!=s1)
			{
				a[err_cnt*3+0]=a1;
				a[err_cnt*3+1]=a2;
				a[err_cnt*3+2]=s1;
				a[err_cnt+6]=3;
				err_cnt++;
			}
		}
		else if(op==4) 
		{
			if(a1/a2!=s1)
			{
				a[err_cnt*3+0]=a1;
				a[err_cnt*3+1]=a2;
				a[err_cnt*3+2]=s1;
				a[err_cnt+6]=4;
				err_cnt++;
			}
			
		}
		n--;
 
	//==================�P�_�O�_���T===================// 
/*	cout<<a1<<endl;
	cout<<op<<endl;
	cout<<a2<<endl;
	cout<<s1<<endl;*/
	}
	
	cout<<"err"<<err_cnt<<endl;
	//=============�}�l���P�_�åB��X============// 
	if(err_cnt>2)
	{
		cout<<"100"<<endl; 
	}
	else if(err_cnt==1)
	{
		cout<<"op"<<a[6]<<endl;
		//========�洫�P�_==========// 
		for(int i=0;i<err_cnt*3-1;i++)
		{
			for(int j=i+1;j<err_cnt*3;j++)
			{
				swap(a[i],a[j]);
				if(compute(a[0],a[1],a[6])==a[2])
				{
					if(a[i]>a[j])
					{
						reg_a=a[j];
						reg_b=a[i];
					}
					else
					{
						reg_a=a[i];
						reg_b=a[j];
					}
					ans_cnt++;
				}
				swap(a[i],a[j]);
			}
		}
	}
	else if(err_cnt==2)
	{
		
		for(int i=0;i<err_cnt*3-1;i++)
		{
			for(int j=i+1;j<err_cnt*3;j++)
			{
				 
				swap(a[i],a[j]);
				//cout<<compute(a[0],a[1],a[6])<<a[2]<<endl;
			//	cout<<a[3]<<a[4]<<a[5]<<endl;
				if(compute(a[0],a[1],a[6])==a[2] && compute(a[3],a[4],a[7])==a[5] )
				{
					cout<<"aaaaaaaa";
					if(a[i]>a[j])
					{
						reg_a=a[j];
						reg_b=a[i];
					}
					else
					{
						reg_a=a[i];
						reg_b=a[j];
					}
					ans_cnt++;
				}
				swap(a[i],a[j]);				
			}
		}

	}
	else
		cout<<err_cnt<<endl; 

	cout<<"ans_cnt"<<ans_cnt<<endl;
	//========���k�P�_�O�_���]�� =========//
	if(err_cnt==1 || err_cnt==2)
	{
		if(a[6]==3 && (a[2]%a[1]==0 || a[2]%a[0]==0) && ans_cnt==0)
			cout<<a[2]<<a[1]*a[0];
		else if(ans_cnt==1)
			cout<<reg_a<<reg_b;
		else
			cout<<"100";
	}

}
