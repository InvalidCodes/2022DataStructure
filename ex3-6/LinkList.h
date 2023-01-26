#ifndef LINKLIST_H
#define LINKLIST_H
#include"Node.h"

template<class ElemType>
class OrdLinkList {
public:
	OrdLinkList();
	OrdLinkList(int n, ElemType v[100]);
	~OrdLinkList();
	void Display();
	void Insert(const ElemType& e);
	void Delete(ElemType& e);
	void QuickSort();
protected:
	Node<ElemType>* head;
	int length;
};

template<class ElemType>
OrdLinkList<ElemType>::OrdLinkList() {
	head = new Node<ElemType>;
	if (!head) cout << "Creation failed." << endl;
	length = 0;
}

template<class ElemType>
OrdLinkList<ElemType>::OrdLinkList(int n, ElemType v[100]) {
	Node<ElemType>* p;
	p = head = new Node<ElemType>;
	if (!head) cout << "Creation failed." << endl;
	for (int i = 0; i < n; i++) {
		p->next = new Node<ElemType>(n, v[i]);
		if (!p->next) cout << "Creation failed." << endl;
		p = p->next;
	}
	length = n;
}

template<class ElemType>
OrdLinkList<ElemType>::~OrdLinkList() {
	Node<ElemType>* p = head->next;
	while (p != NULL) {
		head->next = p->next;
		delete p;
		p = head->next;
	}
	delete head;
	length = 0;
}

template<class ElemType>
void OrdLinkList<ElemType>::Display() {
	for (Node<ElemType>* p = head; p != NULL; p = p->next) {
		cout << p->data << " ";
	}	
}

template<class ElemType>
void OrdLinkList<ElemType>::Insert(const ElemType& e) {
	Node<ElemType>* p = head, * q = NULL;
	while (p->next != NULL && p->next->data <= e)
		p = p->next;
	q = new Node<ElemType>(e, p->next);
	p->next = q;
	length++;
}

template<class ElemType>
void OrdLinkList<ElemType>::Delete(ElemType& e) {
	Node<ElemType>* p = head, *q = NULL;
	while (p->next != NULL && p->next->data < e)
		p = p->next;
	while (p->next != NULL && p->next->data == e) {
		q = p->next;
		p->next = q->next;
		delete q;
		length--;
	}
}

template<class ElemType>
void OrdLinkList<ElemType>::QuickSort() {
	Node<ElemType>* p = head, * q = p->next;
	while (q != NULL) {
		if (q->data < head->data) {
			p = p->next;
			swap(p->data, q->data);
		}
		q = q->next;
	}
	swap(head->data, p->data); 
}

#endif
