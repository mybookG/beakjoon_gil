#include <stdio.h>
#include <stdlib.h>

typedef struct Check_C {
	int data[4];
	struct Check_C* link;
}Check_C;

typedef struct {
	Check_C* top;
}C_top;

C_top* createLink(void) {
	C_top* head;
	head = (C_top*)malloc(sizeof(C_top));
	head->top = NULL;
	return head;
}

void push_Check(int C,C_top* head) {
	Check_C* p;
	Check_C* tmp = (Check_C*)malloc(sizeof(Check_C));
	tmp->data[0] = C / 25;
	C %= 25;
	tmp->data[1] = C / 10;
	C %= 10;
	tmp->data[2] = C / 5;
	C %= 5;
	tmp->data[3] = C;
	p = head -> top;
	if (head->top == NULL) {
		tmp->link = NULL;
		head->top = tmp;
	}
	else {
		while (p->link != NULL) { p = p->link; }
		p->link = tmp;
		tmp->link = NULL;
	}
}

void print_C(C_top* head) {
	Check_C* p;
	p = head->top;
	while (p != NULL) {
		printf("%d %d %d %d\n", p->data[0], p->data[1], p->data[2], p->data[3]);
		p = p->link;
	}
}

int main() {
	int T,C;
	scanf("%d",&T);
	C_top* head;
	head = createLink();
	for (int i = 0; i < T; i++) {
		scanf("%d", &C);
		push_Check(C,head);
	}
	print_C(head);
	return 0;
}