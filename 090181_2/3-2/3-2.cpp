#include<iostream>
#include<queue>
#include<ctime>
#include<string>
using namespace std;

//起飞用时5分钟，降落用时3分钟
//处理十次起飞或降落
typedef struct plane {
	int id;
	int time;//开始请求调度的时间
	string request;//takeoff \ land
	bool flag;
} Plane;
int curtime=0;
Plane curplane,node;

int aircontrol(Plane arr[], int size) {
	queue<Plane> runway, waiting;

	while (1) {
		curtime++;
		if (!runway.empty() && runway.front().request == "takeoff") {
			if (curtime - runway.front().time == 5)
				runway.pop();
		}

		else if (!runway.empty() && runway.front().request == "land") {
			if (curtime - runway.front().time == 3)
				runway.pop();
		}
		for (int i = 0; i < size; ++i) {
			if (curtime == arr[i].time) {
				arr[i].flag = 1;
				curplane = arr[i];
				waiting.push(curplane);
				cout << "Current time:" << curtime << "			" << curplane.id << "请求" << curplane.request << endl;
			}
		}
		if (runway.empty()&& !waiting.empty()) {
			runway.push(waiting.front());
			waiting.pop();
			runway.front().time = curtime;
			if (runway.front().request == "takeoff")
				cout << "Current time:" << curtime << "			" << runway.front().id << "起飞中....\n";
			else if (runway.front().request == "land")
				cout << "Current time:" << curtime << "			" << runway.front().id << "降落中....\n";
		}

		if (runway.empty() && waiting.empty())
		{
			int j = 0;
			for (int i = 0; i < 10; ++i) {
				if (arr[i].flag == 1)
					++j;
			}
			if (j == 10)
				return 0;

		}
	}
}
int main() {
	srand(int(time(0)));

	Plane planeArray[10];
	for (int i = 0; i < 10; ++i) {
		planeArray[i].id = i;
		planeArray[i].time = rand()%30+1;//time ranges from 1 to 30
		planeArray[i].flag = 0;
		if (i == 3 || i == 7)
			planeArray[i].request = "takeoff";//planeArray[3]、planeArray[7]请求为takeoff,其余皆为land
		else
			planeArray[i].request = "land";
	}
	//for (int j = 0; j < 10; ++j) {
	//	cout << planeArray[j].id << planeArray[j].time << planeArray[j].request << planeArray[j].flag<< endl;
	//}
	cout << "Current time:" << curtime << "			" << "机场开启\n";
	aircontrol(planeArray,10);
	cout << "Current time:" << curtime << "			" << "机场关闭\n";

	system("pause");
}
