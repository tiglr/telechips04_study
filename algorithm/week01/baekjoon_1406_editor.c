/*
문제 : 에디터
Link : https://www.acmicpc.net/problem/1406
Date : 2026-03-18
Created By: tiglr
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _DLL_Node {
	char data;
	struct _DLL_Node* next;
	struct _DLL_Node* prev;
}DLL_Node;

int N; // 명령어 개수
DLL_Node* head;
DLL_Node* tail;
DLL_Node* cursor;

DLL_Node* createDLLNode(char data);
void appendDLLNode(DLL_Node* t, char data);
void deleteDLLNode(DLL_Node* node);
void printDLLNode(DLL_Node* p);
void insertBefore(char data, DLL_Node* node);
void freeDLL(DLL_Node*);
void initList();

int main() {
	char op, a; // op : 명령 종류, a : P인경우 입력받는 추가 char
	int size; // 입력받은 문자열의 크기

	initList(); // head, tail, cursor 초기화

	char* string = (char*)calloc(100001, sizeof(char));
	if (string == NULL) return 0;

	(void)scanf("%s", string);
	size = strlen(string);
	for (int i = 0; i < size; ++i) {
		appendDLLNode(tail, string[i]);
	}

	(void)scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		(void)scanf(" %c", &op);
		switch (op) {
		case 'L':
			if (cursor->prev != head) cursor = cursor->prev;
			break;
		case 'D':
			if (cursor->next != NULL) cursor = cursor->next;
			break;
		case 'B':
			deleteDLLNode(cursor->prev);
			break;
		case 'P':
			(void)scanf(" %c", &a);
			insertBefore(a, cursor);
			break;
		default:
			break;
		}
	}
	printDLLNode(head);
	free(string);
	freeDLL(head);
	head = tail = cursor = NULL;
	return 0;
}

DLL_Node* createDLLNode(char data) {
	DLL_Node* node = (DLL_Node*)calloc(1, sizeof(DLL_Node));
	if (node == NULL) return NULL;
	node->data = data;
	return node;
}

void appendDLLNode(DLL_Node* t, char data) {
	DLL_Node* newNode = createDLLNode(data);
	if (newNode == NULL) exit(1);

	DLL_Node* prevNode = t->prev;

	prevNode->next = newNode;
	newNode->prev = prevNode;
	newNode->next = t;
	t->prev = newNode;
}

void deleteDLLNode(DLL_Node* node) {
	if (node == head) return;
	DLL_Node* prevNode = node->prev;
	DLL_Node* nextNode = node->next;
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	free(node);
}

void printDLLNode(DLL_Node* p) {
	if (p == head) {
		p = p->next;
	}
	while (p != tail) {
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

void insertBefore(char data, DLL_Node* node) {
	if (node == head) node = node->next;
	DLL_Node* newNode = createDLLNode(data);
	newNode->next = node;
	newNode->prev = node->prev;
	node->prev->next = newNode;
	node->prev = newNode;
}

void freeDLL(DLL_Node* node) {
	DLL_Node* next;

	while (node != NULL) {
		next = node->next;
		free(node);
		node = next;
	}
}

void initList() {
	head = createDLLNode('\0');
	tail = createDLLNode('\0');

	head->next = tail;
	tail->prev = head;
	cursor = tail;
}