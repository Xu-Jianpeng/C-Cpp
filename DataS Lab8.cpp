#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

//冒泡排序
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


//直接插入排序
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
//快速排序
void Quick(long a[],int low,int high){
	if (high <= low) return;
	int temp;
    int i = low;
    int j = high + 1;
    int key = a[low];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (a[++i] < key)
        {
            if (i == high){
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (a[--j] > key)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    /*中枢值与j对应值交换*/
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
    //冒泡计时
	for(i=0;i<N;i++){
		a[i]=rand();
	}
	start = clock();

	Bubble(a);
//	for(i=0;i<N;i++){		printf("%d\t",a[i]);	}

	finish = clock();
	total_timeB = (double)(finish-start)/CLOCKS_PER_SEC;
	 
	//直接插入计时
	for(i=0;i<N;i++){
		a[i]=rand();
	}
	start = clock();

	Sinsert(a);
//	for(i=0;i<N;i++){		printf("%d\t",a[i]);	}

	finish = clock();
	total_timeS = (double)(finish-start)/CLOCKS_PER_SEC;

	//快速计时
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

