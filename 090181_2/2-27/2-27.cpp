#include<iostream>
//#include"LinearList.h"
#include"LinkedList.h"
//#include"StaticList.h"
using namespace std;

////˳���ʽ
//double Sequence_Calculate(double x, SeqList<double> S) {
//	double result = 0.0;
//	for (int i=0;i<S.Length();i++) 
//		result = result * x + data[i];
//
//	return result;
//}

//������ʽ
double List_Calculate(double x,List<double> L) {
	LinkNode<double>* p = L.getHead()->link;
	double result = 0.0;
	while (p!= NULL) {
		result = result * x + p->data;
		p = p->link;
	}
	return result;
}

//��̬����ʽ
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
	cout << "��x=5ʱ��˳���ļ�������" << Sequence_Calculate(5.0, S) << endl;
*/
	List<double> L;
	for (int i = 0; i < size; i++)
		L.Insert(i, test[i]);
	cout<<"��x=5ʱ��������ļ�������"<<List_Calculate(5.0, L)<<endl;

	//StaticList<double> SL;
	//for (int i = 1; i < size+1; i++)//��ͷ�ڵ�ľ�̬�������±�Ϊ1��λ�ÿ�ʼ����
	//	SL.Append(test[i]);
	//cout << "��x=5ʱ����̬����ļ�������" << StaticList_Calculate(5.0, SL) << endl;
	system("pause");
	return 0;
}