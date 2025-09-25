#include <iostream>
#include "lk_queue.h"
using namespace std;

int main() {
	LinkQueue<int> queue; // ��int��ʾ�����
	int nextNumber = 1;   // ��һ������ĺ����
    
	while (true) {
		cout << "\nҽԺ�к�ϵͳ�˵���\n";
		cout << "1) ȡ��\n2) �к�\n3) �˳�ϵͳ\n";
		cout << "��ѡ��˵���(1-3)��";

		int choice;
		cin >> choice;

		if (choice == 1) {
			// ȡ��
			queue.InQueue(nextNumber);
			cout << "���ĺ����Ϊ��" << nextNumber << endl;
			nextNumber++;
		}
        else if (choice == 2) {
			// �к�
			int patientNo;
			if (queue.OutQueue(patientNo)) {
				cout << "��" << patientNo << "�Ż��߽������ҡ�" << endl;
			}
            else {
				cout << "��ǰ�޺��ﻼ�ߡ�" << endl;
			}
		}
        else if (choice == 3) {
			cout << "ϵͳ���˳���" << endl;
			break;
		}
        else {
			cout << "��������������ѡ��" << endl;
		}
	}
	return 0;
}