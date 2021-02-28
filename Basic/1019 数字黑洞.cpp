#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int array[5];
void to_array(int a)
{
	array[0]=a/1000;
	array[1]=(a-array[0]*1000)/100;
	array[2]=(a-array[0]*1000-array[1]*100)/10;
	array[3]=a%10;
}
int to_int(int array[])
{
	int a=1000*array[0]+100*array[1]+10*array[2]+array[3];
	return a;
}
int main()
{
	int a;
	int max=0,min=0,result=0;
	scanf("%d",&a);
	to_array(a);
	if(array[0]==array[1]&&array[0]==array[1]&&array[0]==array[2]&&array[0]==array[3]){
		printf("%d - %d = 0000\n",a,a);
	}
	else{
		do{
			to_array(a);
			sort(array,array+4,greater<int>());
			max=to_int(array);
			sort(array,array+4);
			min=to_int(array);
			result = max-min;
			printf("%04d - %04d = %04d\n",max,min,result);
			a=result;
		}while(result!=6174&&result!=0);
	}
	return 0;
}
