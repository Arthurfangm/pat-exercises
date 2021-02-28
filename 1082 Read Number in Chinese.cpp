#include <cstdio>
#include <cstring>
char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[5][5]={"Shi","Bai","Qian","Wan","Yi"};
int main()
{
    char str[11];
    scanf("%s",str);
    if(str[0]=='0'){
        printf("ling");
        return 0;
    }
    int len=strlen(str);
    int left=0,right=len-1;
    if(str[0]=='-'){
        printf("Fu");
        left++;
    }
    while(left+4<=right){
        right-=4;
    }
    while(left<=len-1){
        int flag0=0;
        int printed=0;
        while(left<=right){
            if(str[left]=='0'){
                flag0++;
            }else{
                if(flag0>0){
                    printf(" ling");
                    flag0=0;
                }
                if(left>0){
                    printf(" ");
                }
                printf("%s",num[str[left]-'0']);
                if(left!=right){
                    printf(" %s",wei[right-left-1]);
                }
                printed=1;
            }
            left++;
        }
        if(printed&&left<len){
            printf(" %s",wei[(len-1-right)/4+2]);
        }
        right+=4;
    }
    return 0;
}

