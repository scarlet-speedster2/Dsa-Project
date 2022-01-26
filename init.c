#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"process.h"


void display(Queue q){

	while(q != NULL){
		printf("Id = %d \nName = %s \nPriority = %d\nCpu time = %d\nType = %s\ndata = %s\n",q->id,q->name,q->priority,q->cpu_time,q->type,q->data);
		q = q ->next;
		printf("\n");
	}
}
void init(Queue* q,int n){

	(*q) = NULL;
	
	int i = 0;

	for(i = 0;i<5;i++){

		Process* p = (Process*) malloc(sizeof(Process));

		int id_;
		char* name_;
		int priority_;

		int cpu_time_;
		char* type_;
		char* data_; 
		if(n ==1){	
		id_ = rand();
		name_ = "Auto Process";
		priority_ = rand()%4;
		if(!priority_){
			priority_ = 1;}

		cpu_time_ = rand()%11;
		if(!cpu_time_) cpu_time_ = 1;
		type_ = "System";
		data_ = "Data";
		}

		if(n ==2){	
		id_ = rand();
		name_ = "Auto Process";
		priority_ = rand()%6;
		if(!priority_){
			priority_ = 2;}

		cpu_time_ = rand()%21;
		if(!cpu_time_) cpu_time_ = 1;
		type_ = "System";
		data_ = "Data";
		}
				
	
		if(n ==3){	
		id_ = rand();
		name_ = "Auto Process";
		priority_ = rand()%6;
		if(!priority_){
			priority_ = 2;}

		cpu_time_ = rand()%41;
		if(!cpu_time_) cpu_time_ = 1;
		type_ = "System";
		data_ = "Data";
		}
	

		p ->id = id_;
		p ->name = name_;
		p ->priority = priority_;
		p ->cpu_time = cpu_time_;
		p ->type = type_;
		p ->data = data_;
		p ->next = NULL;

		if((*q) == NULL){

			(*q) = p;
			}
		else{
			Process* temp = (*q);
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = p;
		}
	}
	if(n ==1){
	sort_Queue(&(*q),0);}
	if(n ==2){
		sort_Queue(&(*q),1);
	}
}
		


