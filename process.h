
typedef struct Process{
	
	int id;
	char* name;
	int priority;
	int cpu_time;
	char* type;
	char* data;
	struct Process* next;

}Process;

typedef Process* Queue;

void init(Queue* q,int no);

int count(Queue q);

void current_Executing(Queue q);

void sort_Queue(Queue* q,int sorting_parameter);
void display(Queue q);

void append(Queue* q, Process** p);
void remove1(Queue* q);
void remove2(Queue* q,Queue* q1);
void remove3(Queue* q,Queue* q2);





