#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Problem {
    int grade;
    int allOption;
    int rightOption;
    char ro[6];
};
struct Answer {
    int choosenOption;
    char co[6];
};
int judge(char s1[],char s2[]){
    int ll=strlen(s2);
    for(int i=0;i<ll;i++){
        if(!strchr(s2,s1[i]))
            return 0;
    }
    return true;
}
int main()
{
    Problem problems[110];
    int wrong[110];
    int grades[1010];
    int maxWrong=-1;
    memset(wrong,0,sizeof(wrong));
    memset(grades,0,sizeof(grades));
    int N,M;
    scanf("%d %d",&N,&M);
    char a=getchar();
    char str[20];
    for(int i=0;i<M;i++){
        memset(problems[i].ro,0,sizeof(problems[i].ro));
        cin.getline(str,20);
        problems[i].grade=str[0]-'0';
        problems[i].allOption=str[2]-'0';
        problems[i].rightOption=str[4]-'0';
        int len=strlen(str);
        int counter=0;
        for(int j=6;j<len;j+=2){
            problems[i].ro[counter++]=str[j];
        }
    }
    char str2[1300];
    for(int s=0;s<N;s++){
        cin.getline(str2,1300);
        int len=strlen(str2);
        int counter=-1;
        for(int i=0;i<len;i++){
            if(str2[i]=='('){
                counter++;
                Answer answer;
                memset(answer.co,0,sizeof(answer.co));
                answer.choosenOption=str2[i+1]-'0';
                if(str2[i+1]-'0'==problems[counter].rightOption){
                    i++;
                    for(int j=1;j<=problems[counter].rightOption;j++){
                        answer.co[j-1]=str2[i+2*j];
                    }
                    if(judge(problems[counter].ro,answer.co)){
                        grades[s]+=problems[counter].grade;
                    }
                    else{
                        wrong[counter]++;
                        if(wrong[counter]>maxWrong)
                            maxWrong=wrong[counter];
                    }
                    i+=2*answer.choosenOption+2;
                }
                else{
                    i+=2*answer.choosenOption+2;
                    wrong[counter]++;
                    if(wrong[counter]>maxWrong)
                            maxWrong=wrong[counter];
                }
            }
        }
    }
    for(int g=0;g<N;g++){
        printf("%d\n",grades[g]);
    }
    if(maxWrong==-1){
        printf("Too simple");
    }
    else{
        printf("%d",maxWrong);
        for(int g=0;g<M;g++){
            if(wrong[g]==maxWrong)
                printf(" %d",g+1);
        }
    }
    printf("\n");
    return 0;
}

