#include<iostream>
//#include"LinearList.h"
#include"LinkedList.h"
//#include"StaticList.h"
using namespace std;

////顺序表方式
//double Sequence_Calculate(double x, SeqList<double> S) {
//	double result = 0.0;
//	for (int i=0;i<S.Length();i++) 
//		result = result * x + data[i];
//
//	return result;
//}

//单链表方式
double List_Calculate(double x,List<double> L) {
	LinkNode<double>* p = L.getHead()->link;
	double result = 0.0;
	while (p!= NULL) {
		result = result * x + p->data;
		p = p->link;
	}
	return result;
}

//静态链表方式
//double StaticList_Calculate(double x, StaticList<double> SL) {
//	double result = 0.0;
//	for (int i = 0; !SL.IsEmpty(); i++) {
//		double p = SL[locate(i)].data;
//		result = result * x + p;
//	}
//	return result;
//}

int main() {
	const int size = 4;
	double test[size] = { 4.0,3.0,2.0,1.0 };

	/*LinearList<double> S;
	for (int i = 0; i < size; i++)
		S.Insert(i , test[i]);
	cout << "当x=5时，顺序表的计算结果：" << Sequence_Calculate(5.0, S) << endl;
*/
	List<double> L;
	for (int i = 0; i < size; i++)
		L.Insert(i, test[i]);
	cout<<"当x=5时，单链表的计算结果："<<List_Calculate(5.0, L)<<endl;

	//StaticList<double> SL;
	//for (int i = 1; i < size+1; i++)//带头节点的静态链表，从下标为1的位置开始存起
	//	SL.Append(test[i]);
	//cout << "当x=5时，静态链表的计算结果：" << StaticList_Calculate(5.0, SL) << endl;
	system("pause");
	return 0;
}