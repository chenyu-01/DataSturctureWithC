#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct{
	ElemType *elem;//整型指针
	int TableLen;
}SSTable;

void ST_Init(SSTable &ST,int len)
{
	ST.TableLen=len+1;//实际申请11个元素的空间
	ST.elem=(ElemType *)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for(i=0;i<ST.TableLen;i++)
	{
		ST.elem[i]=rand()%100;//随机了11个数，但是第一个元素是没有用到的
	}
}
void ST_print(SSTable ST)
{
	for(int i=0;i<ST.TableLen;i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}
//插入排序，从小到大排序，升序
void InsertSort(ElemType A[],int n)
{
	int i,j;
	//24 66 94  2 15 74 28 51 22 18  2
	for(i=2;i<=n;i++)
	{
		if(A[i]<A[i-1])
		{
			A[0]=A[i];//放到暂存位置
			for(j=i-1;A[0]<A[j];--j)
				A[j+1]=A[j];
			A[j+1]=A[0];
		}
	}
}
//折半查找 插入排序
void MidInsertSort(ElemType A[],int n)
{
	int i,j,low,high,mid;
	for(i=2;i<=n;i++)
	{
		A[0]=A[i];
		low=1;high=i-1;
		while(low<=high)//先通过二分查找找到待插入位置
		{
			mid=(low+high)/2;
			if(A[mid]>A[0])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=high+1;--j)
			A[j+1]=A[j];
		A[high+1]=A[0];
	}
}
//希尔排序  
//多轮插入排序，考的概率很低，因为编写起来复杂，同时效率并不如快排，堆排
void ShellSort(ElemType A[],int n)
{
	int dk,i,j;
	// 73 29 74 51 29 90 37 48 72 54 83
	for(dk=n/2;dk>=1;dk=dk/2)//步长变化
	{
		for(i=dk+1;i<=n;++i)//以dk为步长进行插入排序
		{
			if(A[i]<A[i-dk])
			{
				A[0]=A[i];
				for(j=i-dk;j>0&&A[0]<A[j];j=j-dk)
					A[j+dk]=A[j];
				A[j+dk]=A[0];
			}
		}
	}
}

//《王道C督学营》
int main()
{
	SSTable ST;
	ST_Init(ST,10);//实际申请了11个元素空间
	ST_print(ST);
	InsertSort(ST.elem,10);
	//MidInsertSort(ST.elem,10);
	//ShellSort(ST.elem,10);
	ST_print(ST);
	system("pause");
}