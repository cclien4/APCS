#include <bits/stdc++.h> 

using namespace std;

int scan(char s[100],int a,int b)
{
    int i = a;            // 大數的數字位置
    int j = b;   			// 字串的字元位置
    int num=0;
    int c[a];
    while(i>=b)
    {
    	c[i-b] = s[j++] - '0';   // 字串頭尾顛倒，存入陣列
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
	int a1,a2,s1,reg_n,op; //a1=num1 a2=num2 s1=sum op =+-*/  //擷取資料用 
	int a[8],err_cnt=0;//a[2]最多兩組 [3]三個數字    //一維陣列方便後面比對 
	int ans_cnt=0,reg_a,reg_b,reg_c; //reg_ab reg outputdata
	int n;
	
	//while(cin>>s)
	cin>>n;
	while(n!=0)
	{
	//==================輸入並擷取完資料===================// 
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
			//==================輸入並擷取完資料===================//
		//==========判斷是否錯誤===============//	
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
 
	//==================判斷是否正確===================// 
/*	cout<<a1<<endl;
	cout<<op<<endl;
	cout<<a2<<endl;
	cout<<s1<<endl;*/
	}
	
	cout<<"err"<<err_cnt<<endl;
	//=============開始做判斷並且輸出============// 
	if(err_cnt>2)
	{
		cout<<"100"<<endl; 
	}
	else if(err_cnt==1)
	{
		cout<<"op"<<a[6]<<endl;
		//========交換判斷==========// 
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
	//========乘法判斷是否為因數 =========//
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
