#include <iostream>
#include "simple_lk_list.h"					// ������������ģ��
using namespace std;

void PrintElem(const int &e) {
    cout << e << " ";
}

SimpleLinkList<int> DifferenceSet(const SimpleLinkList<int>& la, const SimpleLinkList<int>& lb);

int main(){
	// ���������������򼯺�A��B
	SimpleLinkList<int> la, lb;
	// ʾ����������
	la.Insert(1, 1);
	la.Insert(2, 3);
	la.Insert(3, 5);
	la.Insert(4, 7);
	lb.Insert(1, 3);
	lb.Insert(2, 4);
	lb.Insert(3, 7);

	cout<< "����AΪ" << endl;
	la.Traverse(PrintElem);
	cout << endl;
	
	cout<< "����BΪ" << endl;
	lb.Traverse(PrintElem);
	cout << endl;

	// ��C = A - B
	SimpleLinkList<int> lc = DifferenceSet(la, lb);
	cout << "A - B �ĲΪ��";
	lc.Traverse(PrintElem);
	cout << endl;
	return 0;
}

SimpleLinkList<int> DifferenceSet(const SimpleLinkList<int>& la, const SimpleLinkList<int>& lb) {
	SimpleLinkList<int> lc;
	int i = 1, j = 1;
	int a, b;
	int lenA = la.Length(), lenB = lb.Length();
	while (i <= lenA && j <= lenB) {
		la.GetElem(i, a);
		lb.GetElem(j, b);
		if (a < b) {
			lc.Insert(lc.Length() + 1, a);
			i++;
		}
		else if (a == b) {
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	// Aʣ�µĶ����ڲ
	while (i <= lenA) {
		la.GetElem(i, a);
		lc.Insert(lc.Length() + 1, a);
		i++;
	}
	return lc;
}