#include<stdio.h>
void main()
{
	int burst[10],wait[10],turnaround[10],i,size,wsum=0,tsum=0,sum2=0;
	float avg1,avg2;
	printf("ENTER TOTAL NUMBER OF PROCESS :");
	scanf("%d",&size);
	printf("\nENTER THE CPU BURST TIME OF EACH PROCESS IN MILLISECONDS\n");
	for(i=0;i<size;i++)
	{
		printf("\nP%d :",i);
		scanf("%d",&burst[i]);
		wait[i]=wsum;
		turnaround[i]=wait[i]+burst[i];
		wsum=wsum+burst[i];
		sum2=wait[i]+sum2;
		tsum=tsum+turnaround[i];
		
	}
	
	avg1=(float)sum2/size;
		avg2=(float)tsum/size;
	printf("\nPROCESS NAME\t\tBURST TIME\t\tWAITING TIME\t\tTURNAROUND TIME\n");
	for(i=0;i<size;i++)
	{
		printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i,burst[i],wait[i],turnaround[i]);
	}
	
	printf("\nAVERAGE WAITING TIME : %f\nAVERAGE TURNAROUND TIME : %f",avg1,avg2);
	
}
