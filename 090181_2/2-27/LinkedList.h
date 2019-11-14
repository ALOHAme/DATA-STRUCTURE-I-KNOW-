#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct LinkNode {
	T data;//数据域
	LinkNode<T> *link;//链指针域
	LinkNode(LinkNode<T>*ptr = NULL) { link = ptr; }//仅初始化指针成员的构造函数
	LinkNode(const T&item, LinkNode<T>*ptr = NULL)//初始化数据和指针成员的构造函数
	{
		data = item; link = ptr;
	}
};


template<class T>
class List {
public:
	List() { first = new LinkNode<T>; }
	LinkNode<T>*Locate(int i);
	bool Insert(int i, T&x);
	LinkNode<T>*getHead()const { return first; }
	void output();
protected:
	LinkNode<T> *first;
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
bool List<T>::Insert(int i, T&x) {
	LinkNode<T>*current = Locate(i);
	if (current == NULL)return false;
	LinkNode<T>*newNode = new LinkNode<T>(x);
	if (newNode == NULL) { cerr << "存储分配错误！" << endl; exit(1); }
	newNode->link = current->link;
	current->link = newNode;
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


