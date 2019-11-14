#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct LinkNode {
	T data;//������
	LinkNode<T> *link;//��ָ����
	LinkNode(LinkNode<T>*ptr = NULL) { link = ptr; }//����ʼ��ָ���Ա�Ĺ��캯��
	LinkNode(const T&item, LinkNode<T>*ptr = NULL)//��ʼ�����ݺ�ָ���Ա�Ĺ��캯��
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
	if (newNode == NULL) { cerr << "�洢�������" << endl; exit(1); }
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


