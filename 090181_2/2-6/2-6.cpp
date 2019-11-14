#include <iostream>
#include<cstdlib>
#include<cmath>
#include"LinkedList.h"
using namespace std;

void RemoveDuplication(List<int>& L) {
	LinkNode<int> *ptr = L.getHead()->link;

	int size=0;
	while (ptr != NULL) {
		if (size <= abs(ptr->data))
			size = ptr->data;

		ptr = ptr->link;
	}
	size++;
	int *array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = 0;

	LinkNode<int> *p = L.getHead()->link;
	int counter = 1,n;
	while (p != NULL) {//p！=NULL 铭记！！
		if (array[abs(p->data)] == 0)
			array[abs(p->data)] = 1;
		else {
			p = p->link;//先逃离，再摧毁
			L.Remove(counter, n);//访问权限错误，指针断掉了....... 用counter记录当前节点的次序 传给i
			continue;
		}
		p = p->link;
		counter++;
	}
}

int main() {
	int testData[] = { 21,-15,7 ,15,15 };
	List<int> L;
	for (int i = 0; i < 5; i++)
	{
		L.Insert(i,testData[i]);
	}
	cout << "输入的L：\n";
	L.output();
	RemoveDuplication(L);
	cout << "去重之后的L：\n";
	L.output();
	system("pause");
	return 0;
}