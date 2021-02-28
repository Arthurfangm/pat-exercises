#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char key[22];
    memset(key,0,sizeof(key));
    int N;
    scanf("%s %d",key,&N);
    getchar();
    char try_[100];
    memset(try_,0,sizeof(try_));
    int counter=0;
    while(cin.getline(try_,100))
    {
        if(strcmp(try_,"#")==0)
        {
            break;
        }
        else
        {
            counter++;
            if(strcmp(try_,key)==0)
            {
                printf("Welcome in\n");
                break;
            }
            else
            {
                printf("Wrong password: %s\n",try_);
                if(counter==N)
                {
                    printf("Account locked\n");
                    break;
                }
            }
        }
    }
    return 0;
}

