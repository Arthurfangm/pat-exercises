#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int cmp(int a[],int b[]){
    if(a[0]!=b[0]){
        return a[0]>b[0];
    }else{
        if(a[1]!=b[1]){
            return a[1]>b[1];
        }else{
            return a[2]>b[2];
        }
    }
}
int main()
{
    int m,unlock_a[3],lock_a[3],temp_a1[3],temp_a2[3];
    char unlock[20],lock[20],temp[20];
    scanf("%d",&m);
    scanf("%s %d:%d:%d %d:%d:%d",temp,&unlock_a[0],&unlock_a[1],
              &unlock_a[2],&lock_a[0],&lock_a[1],&lock_a[2]);
    strcpy(unlock,temp);
    strcpy(lock,temp);
    for(int i=1;i<m;i++){
        scanf("%s %d:%d:%d %d:%d:%d",temp,&temp_a1[0],&temp_a1[1],
              &temp_a1[2],&temp_a2[0],&temp_a2[1],&temp_a2[2]);
        if(!cmp(temp_a1,unlock_a)){
            strcpy(unlock,temp);
            unlock_a[0]=temp_a1[0];
            unlock_a[1]=temp_a1[1];
            unlock_a[2]=temp_a1[2];
        }
        if(cmp(temp_a2,lock_a)){
            strcpy(lock,temp);
            lock_a[0]=temp_a2[0];
            lock_a[1]=temp_a2[1];
            lock_a[2]=temp_a2[2];
        }
    }
    printf("%s %s",unlock,lock);
    return 0;
}

