#include <stdio.h>

main()
{
	char A[100];//定义一个数组Ａ， 接收教学行为序列；
	int c=0,g=0;//定义变量ｃ记录教师行为（T）的个数；定义变量g记录连续相同行为的连数；    
	int i=0,sum;
	float rt,ch;

	scanf("%s",A);
	while(A[i]!='\0')
	{
		if(A[i]=='T'||A[i]=='t')
		{
			c++;
		}
		if(A[i]==A[i+1])
		{
			g++;
		}
		i++;
	}
	sum=i;
	printf("行为总个数为：%d\n",sum);
	printf("T行为个数为：%d\n",c);
	printf("连续相同行为个数为：%d\n",g);
	rt=c/sum;
	ch=0;(g-1)/sum;
	printf("rt=%f	ch=%f",rt,ch);
}
