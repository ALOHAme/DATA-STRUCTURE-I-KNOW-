#include<iostream>
#include<limits>
#include<algorithm>
using namespace std;

int factorial(int m) {
	int j=1;
	for (; m > 0; m--)
		j =j* m;
	return j;
}

int power(int n) {
	int z = 1;
	for(;n>0;n--)
		z =z* 2;

	return z;
}

int complexCompute(int k) {
	
	return factorial(k) * power(k);
}

void display(int a[],int size) {
	int i=0;
	while( i<size )
	{
		cout << a[i] << " ";

		i++;
		if (i % 10 == 0) cout << endl;
	}
}
int main() {
	int maxInt= (numeric_limits<int>::max)() ;
	int i = 0;
	long result1=0,result2=0;

	int m = 0;
	while (result1 <= maxInt/(i+1)) {
		result1=factorial(i);
		i++;
	} 

	cout << "m=" << i - 1 << "\nm!=" << result1<<endl;

	int n = 0;
	while (result2 <= maxInt/2 ) {
		result2 = power(n);
		n++;
	}

	cout << "n=" << n - 1 << "\n2^n=" << result2 << endl;

    int maxSize=min(m, n);
	int *A;
	A=new int [maxSize];
	int k = 0;
	while (complexCompute(k) <= maxInt/(k+1)/2) {
		int a=0;
		A[a] = complexCompute(k);
		k++,a++;
	}


	display(A,k);
	delete[] A;
	return 0;
}