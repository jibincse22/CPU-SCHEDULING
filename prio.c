#include<stdio.h>
struct job
{
	int id;
	int data;
	int prio;
};

struct job burst[10],temp;

void main()
{
	int wait[10],turnaround[10],i,j,size,wsum=0,tsum=0,sum2=0;
	float avg1,avg2;
	printf("ENTER TOTAL NUMBER OF PROCESS :");
	scanf("%d",&size);
	printf("\nENTER THE CPU BURST TIME OF EACH PROCESS IN MILLISECONDS\n");
	for(i=0;i<size;i++)
	{
		printf("\nP%d :",i);
		scanf("%d",&burst[i].data);
		burst[i].id=i;
	}
	printf("\nENTER THE PRIORITY ORDER OF EACH PROCESS\n");
	for(i=0;i<size;i++)
	{
		printf("\nP%d :",i);
		scanf("%d",&burst[i].prio);
		burst[i].id=i;
	}
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if((burst[j].prio)>(burst[j+1].prio))
			{
				temp=burst[j];
				burst[j]=burst[j+1];
				burst[j+1]=temp;
			}
		}
	}
	for(i=0;i<size;i++)
	{
		wait[i]=wsum;
		turnaround[i]=wait[i]+burst[i].data;
		wsum=wsum+burst[i].data;	
		tsum=tsum+turnaround[i];
		sum2=wait[i]+sum2;
	}
	avg1=(float)sum2/size;
	avg2=(float)tsum/size;
	printf("\nPROCESS NAME\t\tPRIORITY\t\tBURST TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n");
	for(i=0;i<size;i++)
	{
		printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t\t\t%d\n",burst[i].id,burst[i].prio,burst[i].data,wait[i],turnaround[i]);
	}
	printf("\nAVERAGE WAITING TIME : %f\nAVERAGE TURNAROUND TIME : %f",avg1,avg2);
}
