#include <stdio.h>
#include <string.h>

main(){
	char c;
	int i=0,j,n=0,num[100]={0},count=0;
	char str[100][100];
	FILE* f = fopen("d:\\SEIT2019.txt", "r");
	printf("原文如下:\n");
	while((c=fgetc(f)) !=EOF)
	{
		if(c<65||(c>93&&c<97)||c>122) continue;
		j=0;
		while((c>=65&&c<=93)||(c>=97&&c<=122)||c==45){
			if(c>=65&&c<=93) str[i][j]=c+32;
			else str[i][j]=c;
			j++;
			c = fgetc(f);
		}
		count++;
		str[i][j]='\0';
		printf("%s ",str[i]);
		for(j=0;j<i;j++){
			if(strcmp(str[i],str[j])!=0) continue;
			num[j]++;
			n++;
		}
		if(n==0) i++;
		n=0;
		
	}
	printf("\n\n本文的总单词数为：%d\n\n",count);
	for(j=0;j<i;j++){
		printf("%s\t出现的次数为:\t%d\n",str[j],num[j]+1);
	}
	fclose(f);
}