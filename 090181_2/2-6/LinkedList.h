#pragma once
#include <iostream>
#include<cstdlib>
using namespace std;

template<class T>
struct LinkNode
{
	T data;
	LinkNode* link;
	LinkNode(LinkNode<T> *ptr = NULL) : link(ptr) {}
	LinkNode(const T& item, LinkNode<T> *ptr = NULL) : data(item), link(ptr) {}
};

template<class T>
class List {
public:
	List() { first = new LinkNode<T>; }
	List(const T&x) { first = new LinkNode<T>(x); }
	List(List<T>&L);
	~List() { makeEmpty(); }
	void makeEmpty();
	int Length()const;
	LinkNode<T>*getHead()const { return first; }
	LinkNode<T>*Search(T x);
	LinkNode<T>*Locate(int i);
	bool getData(int i, T& x)const;
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty()const
	{
		return first->link == NULL ? true : false;
	}
	bool IsFull()const { return false; }
	/*void Sort();
	void input();*/
	void output();
	List<T>& operator=(List<T>&L);
protected:
	LinkNode<T> *first;
};

//template<class T>
//List<T>::List(List<T>&L) {
//	T value;
//	LinkNode<T> *srcptr = L.getHead();
//	LinkNode<T> *desptr = first = new LinkNode<T>;
//	while (srcptr->link != NULL) {
//		value = srcptr->link->data;
//		destptr->link = new LinkNode<T>(value);
//		destptr = destptr->link;
//		srcptr = srcptr->link;
//	}
//	destptr->link = NULL;
//};

template<class T>
void List<T>::makeEmpty() {
	LinkNode<T>*q;
	while (first->link != NULL) {
		q = first->link;
		first->link = q->link;
		delete q;
	}
};

template<class T>
int List<T>::Length()const {
	LinkNode<T>*p = first->link;
	int count = 0;
	while (p != NULL)
	{
		p = p->link; count++;
	}
	return count;
};

template<class T>
LinkNode<T>*List<T>::Search(T x) {
	LinkNode<T>*current = first->link;
	while (current != NULL)
		if (current->data == x)break;
		else current = current->link;
	return current;
};

template<class T>
LinkNode<T>*List<T>::Locate(int i) {
	if (i < 0)return NULL;
	LinkNode<T>*current = first;
	int k = 0;
	while (current != NULL && k < i)
	{
		current = current->link; k++;
	}
	return current;
};

template<class T>
bool List<T>::getData(int i, T& x)const {
	if (i <= 0)return NULL;
	LinkNode<T>*current = Locate(i);
	if (current == NULL)return false;
	else { x = current->data; return true; }
};

template<class T>
void List<T>::setData(int i, T& x) {
	if (i <= 0)return;
	LinkNode<T>*current = Locate(i);
	if (current == NULL)return;
	else current->data = x;
};

template<class T>
bool List<T>::Insert(int i, T&x) {
	LinkNode<T>*current = Locate(i);
	if (current == NULL)return false;
	LinkNode<T>*newNode = new LinkNode<T>(x);
	if (newNode == NULL) { cerr << "�洢�������" << endl; exit(1); }
	newNode->link = current->link;
	current->link = newNode;
	return true;
};

template<class T>
bool List<T>::Remove(int i, T&x) {
	LinkNode<T>*current = Locate(i - 1);
	if (current == NULL || current->link == NULL)return false;
	LinkNode<T>*del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
};

template<class T>
void List<T>::output() {
	LinkNode<T>*current = first->link;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->link;
	}
};

template<class T>
List<T>&List<T>::operator=(List<T>& L) {
	T value;
	LinkNode<T>*srcptr = L.getHead();
	LinkNode<T>*destptr = first = new LinkNode<T>;
	while (srcptr->link != NULL) {
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
	return *this;
};

