#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"process.h"
#include"queue.h"
void main(){
	Queue q1,q2,q3;
	init(&q1,1);
	init(&q2,2);

	init(&q3,3);
	printf("--------------Menu----------------\n");
	int choice;
	
	do{
		printf("1. Create User Process\n");
		printf("2. Print current Executing process\n");
		printf("3. Display Queues\n");
		printf("4. Exit Menu\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
		                add(&q1,&q2,&q3);
				break;
			case 2:
				current_Executing(q1);
				break;
			case 3:
				printf("Queue 1....\n\n");
				display(q1);
				printf("Queue 2.....\n\n");
				display(q2);
				printf("Queue 3......\n\n");
				display(q3);
				break;


			default:
				if(choice != 3)
				printf("\n Invalid option\n");

		}
	}while(choice !=4);
	
		remove1(&q1);
		remove2(&q2,&q1);
		remove3(&q3,&q2);
		sort_Queue(&q1,0);
	while(q1){
		printf("Current Executing Process\n");
		delay(1000);
		remove1(&q1);
	}


}
