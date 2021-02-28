#include <iostream>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    int M,N,S;
    set<string> st;
    string str[1010];
    int flag=0;
    scanf("%d %d %d",&M,&N,&S);
    if(M>S)
    {
        for(int i=1; i<=M; i++)
        {
            cin>>str[i];
        }
        for(int i=S; i<=M; i+=3)
        {
            pair<set<string>::iterator,bool> result = st.insert(str[i]);
            while(!result.second&&i<=M)
            {
                i++;
                result=st.insert(str[i]);
            }
            if(i<=M)
            {
                flag++;
                cout<<str[i]<<endl;
            }
        }
        if(flag==0)
        {
            printf("Keep going...\n");
        }
    }
    else
        printf("Keep going...\n");

    return 0;
}

