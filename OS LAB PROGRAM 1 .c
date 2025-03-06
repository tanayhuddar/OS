
#include <stdio.h>
int main(){
    int n ;
    printf("no of process : ");
    scanf("%d",&n);
    int ArrivalTime[n];
    int BurstTime[n];
    int CompletionTime[n];
    int TurnAroundTime[n];
    int WaitingTime[n];
    printf("ARRIVAL TIME OF EACH PROCESS : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&ArrivalTime[i]);
    }
    printf("BURST TIME OF EACH PROCESS : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&BurstTime[i]);
    }
    int sum = 0 ;
    for(int i = 0 ; i < n ;i++){
        sum += BurstTime[i];
        CompletionTime[i] = sum;
    }
    for(int i = 0 ; i < n ;i++){
        TurnAroundTime[i] = CompletionTime[i]-ArrivalTime[i];
    }
    for(int i = 0 ; i < n ;i++){
        WaitingTime[i]=TurnAroundTime[i]-BurstTime[i];
    }
    float CT,TAT,WT;
    for(int i = 0 ; i < n ; i++){
        WT+=WaitingTime[i];
        CT+=CompletionTime[i];
        TAT+=TurnAroundTime[i];
    }
    WT/=n;
    CT/=n;
    TAT/=n;
    printf("COMPLETION TIME : %f \nTURN AROUND TIME : %f \nWAITING TIME : %f",CT,TAT,WT);
}


    
