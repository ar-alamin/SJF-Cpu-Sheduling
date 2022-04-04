# include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
}

void fcfs(int process, int *bt){
    int p, wt[process], tat[process], swt, stat;

    qsort(bt, process, sizeof(int), cmp);

    printf("Process \t Burst Time \t Waiting Time \t TAT \n");
    printf("---------------------------------------------------------\n");
    for(swt=0, stat=0, wt[0]=0, p=0; p<process; p++){
        tat[p] = bt[p]+wt[p];
        printf("%d \t\t %d \t\t %d \t\t %d\n", p, bt[p], wt[p] ,tat[p]);
        wt[p+1] = tat[p];

        swt+=wt[p];
        stat+=tat[p];
    }

    printf("\nAverage Waiting Time -> %f\n", (float) (swt/process));
    printf("Average Turn Around Time -> %f\n", (float) (stat/process));
}

int main() {

    int process,p;
    int bt[500];
    printf("Enter the number of process: ");
    scanf("%d", &process);

    for(p=0; p<process; p++){
        printf("Enter the burst time (p%d): ", p);
        scanf("%d", &bt[p]);
    }

    fcfs(process, &bt);

    return 0;
}

