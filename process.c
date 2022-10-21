#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"process.h"
#include"queue.h"
//this is
int count(Queue q){
	int c =0;
	while(!q){
		c++;
		q = q->next;
	}
	return c;
}


void current_Executing(Queue q){
	printf("Process Id = %d\n Name = %s\nPriority = %d\nCpu Time = %d\nType = %s\nData = %s\n",q->id,q->name,q->priority,q->cpu_time,q->type,q->data);
	printf("\n");
	
}

void append(Queue* q,Process** p){

	Process* temp = (*q);
	while(temp -> next != NULL){
		temp = temp ->next;
	}
	temp ->next = (*p);


}
void remove1(Queue* q){
	if(!(*q))
		return;
	Process* temp = (*q);
	(*q) = (*q) ->next;
	current_Executing(temp);
	free(temp);
}
void remove2(Queue* q,Queue* q1){
	if(!(*q))
		return;
	Process* temp = (*q);
	Process* t = (*q);
	(*q) = (*q) ->next;
	append(&(*q1),&temp);
	
}
void remove3(Queue* q,Queue *q2){
	if(!(*q))
		return;
	Process* temp = (*q);
	(*q) = (*q) ->next;
	append(&(*q2),&temp);
	
}
