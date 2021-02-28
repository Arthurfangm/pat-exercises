#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    float e;
    int D;
    float maybe=0,sure=0;
    int K;
    float E;
    scanf("%d%f%d",&N,&e,&D);
    for(int i=0;i<N;i++){
        int counter=0;
        scanf("%d",&K);
        for(int j=0;j<K;j++){
            scanf("%f",&E);
            if(E<e)
                counter++;
        }
        if(counter>K/2){
            if(K>D)
                sure++;
            else
                maybe++;
        }
    }
    maybe=maybe/N*100;
    sure=sure/N*100;
    printf("%.1f%% %.1f%%\n",maybe,sure);
    return 0;
}

