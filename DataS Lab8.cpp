#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

//ð������
void Bubble(long a[]){
	long i,j,temp;
	for(i=0;i<N;i++)
		for(j=0;j<N-i;j++)
			if(a[i]<a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
}


//ֱ�Ӳ�������
void Sinsert(long a[]){
	long i,j,temp;
	for(i=0;i<N;i++){
		temp=a[i];
		j=i-1;
		while(j>-1&&temp<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
//��������
void Quick(long a[],int low,int high){
	if (high <= low) return;
	int temp;
    int i = low;
    int j = high + 1;
    int key = a[low];
    while (true)
    {
        /*���������ұ�key���ֵ*/
        while (a[++i] < key)
        {
            if (i == high){
                break;
            }
        }
        /*���������ұ�keyС��ֵ*/
        while (a[--j] > key)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*����i,j��Ӧ��ֵ*/
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    /*����ֵ��j��Ӧֵ����*/
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
	Quick(a,low,j-1);
	Quick(a,j+1,high);
}

main(){
	long a[N];
	int i;
	clock_t start, finish;
	double total_timeB,total_timeS,total_timeQ;
    //ð�ݼ�ʱ
	for(i=0;i<N;i++){
		a[i]=rand();
	}
	start = clock();

	Bubble(a);
//	for(i=0;i<N;i++){		printf("%d\t",a[i]);	}

	finish = clock();
	total_timeB = (double)(finish-start)/CLOCKS_PER_SEC;
	 
	//ֱ�Ӳ����ʱ
	for(i=0;i<N;i++){
		a[i]=rand();
	}
	start = clock();

	Sinsert(a);
//	for(i=0;i<N;i++){		printf("%d\t",a[i]);	}

	finish = clock();
	total_timeS = (double)(finish-start)/CLOCKS_PER_SEC;

	//���ټ�ʱ
	for(i=0;i<N;i++){
		a[i]=rand();
	}
	start = clock();

	Quick(a,0,N-1);
//	for(i=0;i<N;i++){		printf("%d\t",a[i]);	}

	finish = clock();
	total_timeQ = (double)(finish-start)/CLOCKS_PER_SEC;

	printf( "Bubble:\t %f seconds\n", total_timeB);
	printf( "Sinsert: %f seconds\n", total_timeS); 
	printf( "Quick:\t %f seconds\n", total_timeQ); 
}

