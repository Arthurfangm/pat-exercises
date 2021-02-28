#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
struct Fraction{
	LL up,down;
};
LL gcd(LL a,LL b){
	return !b?a:gcd(b,a%b);
}
Fraction reduction(Fraction f){
	if(f.down<0){
		f.up=-f.up;
		f.down=-f.down;
	}
	if(f.up==0){
		f.down=1;
	}else{
		LL d=gcd(abs(f.up),abs(f.down));
		f.up/=d;
		f.down/=d;
	}
	return f;
}
Fraction add(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down+f2.up*f1.down;
	result.down=f1.down*f2.down;
	return reduction(result);
}
Fraction minu(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down-f2.up*f1.down;
	result.down=f1.down*f2.down;
	return reduction(result);
}
Fraction multi(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.up;
	result.down=f1.down*f2.down;
	return reduction(result);
}
Fraction divide(Fraction f1,Fraction f2){
	Fraction result;
	result.up=f1.up*f2.down;
	result.down=f1.down*f2.up;
	return reduction(result);
}
void showFraction(Fraction f){
	reduction(f);
	if(f.up==0){
		printf("0");
	}else if(f.up>0){
		if(f.up<f.down){
			printf("%lld/%lld",f.up,f.down);
		}else{
			if(f.up%f.down==0){
				printf("%lld",f.up/f.down);
			}else{
				printf("%lld %lld/%lld",f.up/f.down,f.up%f.down,f.down);
			}
		}
	}else{
		if(abs(f.up)<f.down){
			printf("(%lld/%lld)",f.up,f.down);
		}else{
			if(f.up%f.down==0){
				printf("(%lld)",f.up/f.down);
			}else{
				printf("(%lld %lld/%lld)",f.up/f.down,abs(f.up)%f.down,f.down);
			}
		}
	}
}
void showResult(Fraction f1,Fraction f2,char c){
	Fraction result;
	switch(c){
		case '+':
			showFraction(f1);
			printf(" + ");
			showFraction(f2);
			printf(" = ");
			result=add(f1,f2);
			showFraction(result);
			break;
		case '-':
			showFraction(f1);
			printf(" - ");
			showFraction(f2);
			printf(" = ");
			result=minu(f1,f2);
			showFraction(result);
			break;
		case '*':
			showFraction(f1);
			printf(" * ");
			showFraction(f2);
			printf(" = ");
			result=multi(f1,f2);
			showFraction(result);
			break;
		case '/':
			showFraction(f1);
			printf(" / ");
			showFraction(f2);
			printf(" = ");
			result=divide(f1,f2);
			if(f2.up==0){
				printf("Inf");
			}else{
				showFraction(result);
			}
			break;
	}
		
}
int main()
{
	Fraction f1,f2;
	scanf("%lld/%lld %lld/%lld",&f1.up,&f1.down,&f2.up,&f2.down);
	f1=reduction(f1);
	f2=reduction(f2);
	showResult(f1,f2,'+');
	printf("\n");
	showResult(f1,f2,'-');
	printf("\n");
	showResult(f1,f2,'*');
	printf("\n");
	showResult(f1,f2,'/');
	printf("\n");
	return 0;
}
