#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
void f(char str[],int l,int g){
    int count=0;
    for(int i=0;i<l;i++){
        if(str[i]=='['){
            count++;
            if(count==g){
                int u=i+1;
                while(str[u]!=']'){
                    printf("%c",str[u]);
                    u++;
                }
            }
        }
    }
}
int main()
{
    char s[45]="Are you kidding me? @\\/@\n";
    char hand[45],eye[45],mouse[45];
    memset(hand,0,45);
    memset(eye,0,45);
    memset(mouse,0,45);
    cin.getline(hand,45);
    cin.getline(eye,45);
    cin.getline(mouse,45);
    int len_hand=strlen(hand);
    int len_eye=strlen(eye);
    int len_mouse=strlen(mouse);
    int num_hand=0,num_eye=0,num_mouse=0;
    for(int i=0;i<len_hand;i++){
        if(hand[i]=='[')
            num_hand++;
    }
    for(int i=0;i<len_eye;i++){
        if(eye[i]=='[')
            num_eye++;
    }
    for(int i=0;i<len_mouse;i++){
        if(mouse[i]=='[')
            num_mouse++;
    }
    int n;
    int a[5];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	int flag=1;
    	for(int t=0;t<5;t++){
    		scanf("%d",&a[t]);
		}
		if(a[0]>num_hand||a[0]<1){
			flag=0;
		}
		if(a[1]>num_eye||a[1]<1){
			flag=0;
		}
		if(a[2]>num_mouse||a[2]<1){
			flag=0;
		}
		if(a[3]>num_eye||a[3]<1){
			flag=0;
		}
		if(a[4]>num_hand||a[4]<1){
			flag=0;
		}
		if(flag==0){
			printf("%s",s);
			continue;
		}
        else{
            f(hand,len_hand,a[0]);
            printf("(");
            f(eye,len_eye,a[1]);
            f(mouse,len_mouse,a[2]);
            f(eye,len_eye,a[3]);
            printf(")");
            f(hand,len_hand,a[4]);
            printf("\n");
        }
    }
    return 0;
}

