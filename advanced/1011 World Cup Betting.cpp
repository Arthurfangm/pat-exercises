#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
    double tri[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%lf",&tri[i][j]);
        }
    }
    double r=1.0;
    for(int i=0;i<3;i++){
        if(tri[i][0]>tri[i][1]&&tri[i][1]>tri[i][2]){
            printf("W ");
            r*=tri[i][0];
        }
        if(tri[i][1]>tri[i][0]&&tri[i][1]>tri[i][2]){
            printf("T ");
            r*=tri[i][1];
        }
        if(tri[i][2]>tri[i][1]&&tri[i][2]>tri[i][0]){
            printf("L ");
            r*=tri[i][2];
        }
    }
    printf("%.2f",(r*0.65-1)*2);
    return 0;
}

