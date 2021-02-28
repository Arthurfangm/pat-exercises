#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string s;
int len;
string a[14]={"tre","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string b[14]={"####","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
void fun1(int t)
{
	if(t/13) cout<<b[t/13];
	if((t/13)&&(t%13)) cout<<" ";
	if(t%13||t==0) cout<<a[t%13];
}
void fun2()
{
	int t1=0,t2=0;
	string s1,s2;
	s1=s.substr(0,3);
	if(len>4){
		s2=s.substr(4,3);
	}
	for(int i=0;i<13;i++){
		if(s2==a[i])
            t2=i;
		if(s1==a[i]||s1==b[i])
            t1=i;
	}
	cout<<t1*13+t2;
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	int nn=n;
	for(int i=0;i<n;i++){
		getline(cin,s);
		len=s.length();
		if(s[0]>='0'&&s[0]<='9')
			fun1(stoi(s));
		else
			fun2();
		cout<<endl;
		n=nn;
	}
	return 0;
}

