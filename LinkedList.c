#include <stdio.h>
#include <stdlib.h>

typedef struct n_node {
	int val;
	struct n_node * next;
} node;

void sort(int *, int);
void sortLinkedList(node *);
node * traverseLinkedList(node *, node *, int);
void print(int *, int);
node * findSmallestNode(node *currentNode, node *lhs, node *smallestNode, int smallestVal);
void printLL(node *head);

int main() {

	node * list = (node *)malloc(sizeof(node));

	// list->val = 100;

	// node * ptr = list;
	// ptr->val = 50;
	// ptr = NULL;
	// ptr = realloc(ptr, 0);
	// printf("%d\n", list->val);

	node * node1 = (node *)malloc(sizeof(node));
	node * node2 = (node *)malloc(sizeof(node));
	node * node3 = (node *)malloc(sizeof(node));
	node * node4 = (node *)malloc(sizeof(node));
	node * node5 = (node *)malloc(sizeof(node));

	node1->val = 500;
	node2->val = 50;
	node3->val = 10;
	node4->val = 900;
	node5->val = 9;

	list->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;


	printLL(list);

	//sortLinkedList(list);
	sortLinkedList(list);

	printLL(list);	// sortLinkedList(list);

	// printLL(list);
	//printLL(list);
	return 0;
}

void sort(int *list, int size) {
	for (int i = 0; i < size - 1; i++) {
		int smallestNumIndex = i;
		for (int j = i; j < size; j++) {
			if (*(list + j) < *(list + smallestNumIndex)) {
				smallestNumIndex = j;
			}
		}
		int currentNum = *(list + i);
		*(list + i) = *(list + smallestNumIndex);
		*(list + smallestNumIndex) = currentNum;
	}
}

void print(int *list, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", *(list + i));
	}
	printf("\n\n");
}

void sortLinkedList(node *head) {
	node *tempHead = head;
	while (tempHead->next != NULL) {
		node *nextNode = tempHead->next->next;
		node *smallestNode = findSmallestNode(tempHead->next, tempHead->next, tempHead->next, tempHead->next->val);
		if (smallestNode == nextNode && smallestNode != NULL) {
			smallestNode->next = tempHead->next;
		}
		else
			smallestNode->next = nextNode;

		tempHead->next = smallestNode;
		tempHead = smallestNode->next;
	}
}

node * findSmallestNode(node *currentNode, node *lhs, node *toSmallestNode, int smallestVal) {
	if (currentNode->next == NULL) {
		node *smallestNode = toSmallestNode->next;
		toSmallestNode->next = lhs;		
		lhs->next = smallestNode->next;
		return smallestNode;
	}

	if (currentNode->next != NULL) {
		if (currentNode->next->val < smallestVal) {
			toSmallestNode = currentNode;
			smallestVal = currentNode->next->val;
		}
		findSmallestNode(currentNode->next, lhs, toSmallestNode, smallestVal);
	}
}

void printLL(node *head) {
	while(head->next != NULL) {
		printf("%d\n", head->next->val);
		head = head->next;
	}
	printf("%s\n", "-----------");
}