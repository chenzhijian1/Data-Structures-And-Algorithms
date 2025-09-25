#include <iostream>
#include "lk_queue.h"
using namespace std;

int main() {
	LinkQueue<int> queue; // 用int表示候诊号
	int nextNumber = 1;   // 下一个分配的候诊号
    
	while (true) {
		cout << "\n医院叫号系统菜单：\n";
		cout << "1) 取号\n2) 叫号\n3) 退出系统\n";
		cout << "请选择菜单项(1-3)：";

		int choice;
		cin >> choice;

		if (choice == 1) {
			// 取号
			queue.InQueue(nextNumber);
			cout << "您的候诊号为：" << nextNumber << endl;
			nextNumber++;
		}
        else if (choice == 2) {
			// 叫号
			int patientNo;
			if (queue.OutQueue(patientNo)) {
				cout << "请" << patientNo << "号患者进入诊室。" << endl;
			}
            else {
				cout << "当前无候诊患者。" << endl;
			}
		}
        else if (choice == 3) {
			cout << "系统已退出。" << endl;
			break;
		}
        else {
			cout << "输入有误，请重新选择。" << endl;
		}
	}
	return 0;
}