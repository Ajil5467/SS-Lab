
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {

  int i;
  int rem_bt[n];
  for (i = 0; i < n; i++)
    rem_bt[i] = bt[i];

  int t = 0;

  while (1) {
    bool done = true;

    int i;
    for (i = 0; i < n; i++) {

      if (rem_bt[i] > 0) {
        done = false;

        if (rem_bt[i] > quantum) {
          t += quantum;

          rem_bt[i] -= quantum;
        }

        else {
          t = t + rem_bt[i];

          wt[i] = t - bt[i];

          rem_bt[i] = 0;
        }
      }
    }

    if (done == true)
      break;
  }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {

  int i;
  for (i = 0; i < n; i++)
    tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int quantum) {
  int wt[n], tat[n], total_wt = 0, total_tat = 0;

  findWaitingTime(processes, n, bt, wt, quantum);

  findTurnAroundTime(processes, n, bt, wt, tat);

  printf("process    Burst Time   WaitingTime   Turn around time");

  int i;
  for (i = 0; i < n; i++) {
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];

    printf("\n%d \t \t %d \t %d \t \t %d\n", i + 1, bt[i], wt[i], tat[i]);
  }

  printf("\nAverage waiting time =%.2f\n", (float)total_wt / (float)n);
  printf("Average turn around time =%.2f\n", (float)total_tat / (float)n);
}

int main() {

  int i;
  int j;
  int processes[10];
  FILE *fp;
  char btt[10], prr[10];
  int bt[10];
  int n;
  char str[100];
  fp = fopen("rr.txt", "r");
  if (fp == NULL) {
    printf("\nError in file opening");
  }
  fgets(str, 2, fp);
  n = atoi(str);
  for (i = 0; i < n; i++) {
    fscanf(fp, "%s :  %s", prr, btt);
    processes[i] = atoi(prr);
    bt[i] = atoi(btt);
  }
  for (i = 0; i < n; i++) {
    printf("\nP%d  %d\n", processes[i], bt[i]);
  }

  fclose(fp);

  int quantum = 2;
  findavgTime(processes, n, bt, quantum);
  return 0;
}
