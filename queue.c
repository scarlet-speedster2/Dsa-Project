#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"process.h"
#include"queue.h"

void add(Queue* q1,Queue* q2,Queue* q3){
	Process* new = (Process*) malloc(sizeof(Process));
	if(!new) return;
	int id_,cpu_time_,priority_;
	char name_[20];
	char* data_;
	char* type_ = "User";
	id_ = rand();
	printf("\n Enter Cpu time : ");
	scanf("%d",&cpu_time_);
	printf("\n Enter Process Name : ");
	scanf("%s",&name_);
	printf("\n Enter Process Priority");
	scanf("%d",&priority_);
	data_ = "Process data";
	
	new ->id = id_;
	new ->cpu_time = cpu_time_;
	new ->priority = priority_;
	new ->name = name_;
	new ->data = data_;
	new ->type = type_;
	new ->next = NULL;
	printf("%s",name_);
	printf("\n Id = %d\nTime=%d\nName = %s",new->id,new->cpu_time,new->name);
	
	if(priority_ == 1){
		append(&(*q1),&new);
	}
	else if(cpu_time_ > 20){
		append(&(*q3),&new);
	}
	else{
		append(&(*q2),&new);
	}

	
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}


