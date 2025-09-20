#include <iostream>
#include "sq_list.h"
using namespace std;

void PrintElem(const char &e) {
    cout << e << " ";
}

int main() {
    // ����˳���A��B������Ϊchar
    SqList<char> A, B;

    // ��˳���A����Ԫ��
    A.Insert(1, 'A');
    A.Insert(2, 'B');
    A.Insert(3, 'C');
    A.Insert(4, 'D');

    // ��˳���B����Ԫ��
    B.Insert(1, 'B');
    B.Insert(2, 'C');
    B.Insert(3, 'E');
    B.Insert(4, 'F');
    B.Insert(5, 'G');

    cout << "���Ա�A��Ԫ��Ϊ: ";
    A.Traverse(PrintElem);
    cout << endl;

    cout << "���Ա�B��Ԫ��Ϊ: ";
    B.Traverse(PrintElem);
    cout << endl;

    // ------------------ �������� ------------------
    // �������Ƚ�A������Ԫ�ؼ��������ٽ�B�в���A�е�Ԫ�ؼ�����
    SqList<char> UnionAB = A; // �ȸ���A
    for (int i = 1; i <= B.Length(); i++) {
        char e;
        B.GetElem(i, e); // ȡB�ĵ�i��Ԫ��
        bool found = false;
        // ���A���Ƿ��и�Ԫ��
        for (int j = 1; j <= A.Length(); j++) {
            char a;
            A.GetElem(j, a);
            if (a == e) {
                found = true;
                break;
            }
        }
        // ���A��û�У�����벢��
        if (!found) UnionAB.Insert(UnionAB.Length() + 1, e);
    }

    // ------------------ �������� ------------------
    // ������A��B��������Ԫ��
    SqList<char> InterAB;
    for (int i = 1; i <= A.Length(); i++) {
        char e;
        A.GetElem(i, e); // ȡA�ĵ�i��Ԫ��
        for (int j = 1; j <= B.Length(); j++) {
            char b;
            B.GetElem(j, b);
            if (e == b) { // ���B��Ҳ�и�Ԫ��
                InterAB.Insert(InterAB.Length() + 1, e); // ���뽻��
                break; // �ҵ��������ڲ�ѭ��
            }
        }
    }

    // ------------------ �A-B���� ------------------
    // �A-B��A���е�B��û�е�Ԫ��
    SqList<char> DiffAB;
    for (int i = 1; i <= A.Length(); i++) {
        char e;
        A.GetElem(i, e);
        bool found = false;
        for (int j = 1; j <= B.Length(); j++) {
            char b;
            B.GetElem(j, b);
            if (e == b) {
                found = true;
                break;
            }
        }
        // ���B��û�и�Ԫ�أ������
        if (!found) DiffAB.Insert(DiffAB.Length() + 1, e);
    }

    // ------------------ �B-A���� ------------------
    // �B-A��B���е�A��û�е�Ԫ��
    SqList<char> DiffBA;
    for (int i = 1; i <= B.Length(); i++) {
        char e;
        B.GetElem(i, e);
        bool found = false;
        for (int j = 1; j <= A.Length(); j++) {
            char a;
            A.GetElem(j, a);
            if (e == a) {
                found = true;
                break;
            }
        }
        // ���A��û�и�Ԫ�أ������
        if (!found) DiffBA.Insert(DiffBA.Length() + 1, e);
    }

    // ------------------ ������ ------------------
    cout << "A �� BΪ: ";
    UnionAB.Traverse(PrintElem); // �������
    cout << endl;

    cout << "A �� BΪ: ";
    InterAB.Traverse(PrintElem); // �������
    cout << endl;

    cout << "A - BΪ: ";
    DiffAB.Traverse(PrintElem); // �A-B���
    cout << endl;

    cout << "B - AΪ: ";
    DiffBA.Traverse(PrintElem); // �B-A���
    cout << endl;

    // �������
}