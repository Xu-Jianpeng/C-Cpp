#include <stdio.h>
#define N 5
#define M 3

struct Student {
	char id[16];
	char name[16];
	float grades[3];
};

//定义表头便于阅读
Menu(){
	int j;
	printf("  \t学号\t姓名\t");
	for(j=0;j<M;j++)
		printf("成绩%d\t",j+1);
	printf("平均成绩\n");
}

//输出学生相关数据
void Output(struct Student ss[],int i,float avg[]){
	int j;
	printf("同学%d:\t%s\t",i+1,ss[i].id);
	printf("%s\t",ss[i].name);
	for (j=0;j<M;j++)
		printf("%0.2f\t",ss[i].grades[j]);
	printf("%0.2f",avg[i]);
	printf("\n");
}

//输入学生相关数据
void Input(struct Student ss[]){
	int i,j;
	for(i=0;i<N;i++){
		printf("同学%d:\t",i+1);
		scanf("%s",&ss[i].id);
		scanf("%s",&ss[i].name);
		for (j=0;j<M;j++)
			scanf("%f",&ss[i].grades[j]);
	}
}

//求每个学生的平均分
void Avg(struct Student ss[],float avg[]){
	int i,j;
	float sum[N]={0};
	for(i=0;i<N;i++){
		for(j=0;j<M;j++)
			sum[i]+=ss[i].grades[j];
		avg[i]=sum[i]/M;
	}
}

//最高平均分学生的角标
int Max(float avg[]){
	int i,temp=0;
	float Gmax=0;
	for(i=0;i<N;i++){
		if(avg[i]>Gmax){
			temp = i;
			Gmax = avg[i];
		}
	}
	return temp;
}

main(){
	struct Student ss[N];
	int i,temp=0;
	float avg[N]={0};

	Menu();
	Input(ss);
	
	Avg(ss,avg);

	temp = Max(avg);

	Menu();
	for(i=0;i<N;i++)
		Output(ss,i,avg);

	printf("最高平均分的学生的各项数据:\n");
	Menu();
	Output(ss,temp,avg);
	
}