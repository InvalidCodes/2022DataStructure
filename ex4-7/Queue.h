#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
}LinkNode;

typedef struct {
    LinkNode* front, * rear;
}LinkQueue;

bool InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    return true;
}

void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    if (!s)cout << "Creation failed!" << endl;
    else s->data = x;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear) return false;
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)Q.rear = Q.front;
    free(p);
    return true;
}
