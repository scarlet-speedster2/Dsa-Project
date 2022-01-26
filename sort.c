#include<stdio.h>
#include"process.h"


struct Process* SortedMerge(struct Process* a, struct Process* b,int sort);
void FrontBackSplit(struct Process* source,
					struct Process** frontRef, struct Process** backRef);

void sort_Queue(Queue* headRef, int sorting_parameter)
{
	struct Process* head = *headRef;
	struct Process* a;
	struct Process* b;

	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	FrontBackSplit(head, &a, &b);

	sort_Queue(&a,sorting_parameter);
	sort_Queue(&b,sorting_parameter);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b,sorting_parameter);
}

struct Process* SortedMerge(struct Process* a, struct Process* b,int sort)
{
	struct Process* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if(sort == 0){
	if (a->priority <= b->priority) {
		result = a;
		result->next = SortedMerge(a->next, b,sort);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next,sort);
	}
	return (result);
	}
	else{
		if (a->cpu_time <= b->cpu_time) {
        result = a;
        result->next = SortedMerge(a->next, b,sort);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next,sort);
    }
    return (result);
	}
		
}

/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
void FrontBackSplit(struct Process* source,
					struct Process** frontRef, struct Process** backRef)
{
	struct Process* fast;
	struct Process* slow;
	slow = source;
	fast = source->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}



