#include<cstdio>
using namespace std;
struct Student {
	char name[11];
	char id[11];
	int score;
};
Student students[100];
int main()
{
	int n;
	Student max,min;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s %d",students[i].name,students[i].id,&students[i].score);
		if(i==0){
			max=students[i];
			min=students[i];
		}
		else{
			if(students[i].score>max.score) max=students[i];
			if(students[i].score<min.score) min=students[i];
		}
	}
	printf("%s %s\n%s %s\n",max.name,max.id,min.name,min.id);
	return 0;
} 
