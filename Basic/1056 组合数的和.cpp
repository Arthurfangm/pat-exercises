#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    int sum=0;
    scanf("%d",&N);
    int a=0;
    for(int i=0;i<N;i++){
        scanf("%d",&a);
        sum+=a*10*(N-1)+a*(N-1);
    }
    printf("%d",sum);
    return 0;
}

