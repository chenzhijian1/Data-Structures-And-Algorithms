#ifndef __SIMPLE_LK_LIST_H__
#define __SIMPLE_LK_LIST_H__

#include "node.h"								// �����ģ��

// ������������ģ��
template <class ElemType>
class SimpleLinkList 
{
protected:
// ���ݳ�Ա:
	Node<ElemType> *head;						// ͷ���ָ��

// ��������ģ��:
	Node<ElemType> *GetElemPtr(int position) const;			// ����ָ���position������ָ��

public:
// �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	SimpleLinkList();							// �޲����Ĺ��캯��ģ��
	virtual ~SimpleLinkList();					// ��������ģ��
	int Length() const;							// �����Ա���			 
	bool Empty() const;							// �ж����Ա��Ƿ�Ϊ��
	void Clear();								// �����Ա����
	void Traverse(void (*visit)(const ElemType &)) const;	// �������Ա�
	bool GetElem(int position, ElemType &e) const;			// ��ָ��λ�õ�Ԫ��	
	bool SetElem(int position, const ElemType &e);			// ����ָ��λ�õ�Ԫ��ֵ
	bool Delete(int position, ElemType &e);					// ɾ��Ԫ��		
	bool Delete(int position);								// ɾ��Ԫ��		
	bool Insert(int position, const ElemType &e);			// ����Ԫ��
	SimpleLinkList(const SimpleLinkList<ElemType> &source);	// ���ƹ��캯��ģ��
	SimpleLinkList<ElemType> &operator =(const SimpleLinkList<ElemType> &source); // ���ظ�ֵ�����
};


// ������������ģ���ʵ�ֲ���
template<class ElemType>
Node<ElemType> *SimpleLinkList<ElemType>::GetElemPtr(int position) const
// �������������ָ���position������ָ��
{
	Node<ElemType> *temPtr = head;				// ��temPtr�������Ա��Բ��ҵ�position�����
	int temPos = 0;								// temPtr��ָ����λ�� 

	while (temPtr != NULL && temPos < position)
	{	// ˳ָ�������ң�ֱ��temPtrָ���position�����
		temPtr = temPtr->next;
		temPos++;
	}

	if (temPtr != NULL && temPos == position)
	{	// ���ҳɹ�
		return temPtr;	
	}
	else
	{	// ����ʧ��
		return NULL;	
	}
}

template <class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList()
// �������������һ��������
{
	head = new Node<ElemType>;					// ����ͷ��㣬������ֻ��ͷ���
}

template <class ElemType>
SimpleLinkList<ElemType>::~SimpleLinkList()
// ����������������Ա�
{
	Clear();									// ������Ա�
	delete head;								// �ͷ�ͷ�������ռ�
}

template <class ElemType>
int SimpleLinkList<ElemType>::Length() const
// ����������������Ա�Ԫ�ظ���
{
	int count = 0;								// ������ 
	for (Node<ElemType> *temPtr = head->next; temPtr != NULL; temPtr = temPtr->next)
	{	// ��temPtr����ָ��ÿ��Ԫ��
		count++;								// �����Ա��ÿ��Ԫ�ؽ��м���
	}
	return count;								// ����Ԫ�ظ���
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Empty() const
// ��������������Ա�Ϊ�գ��򷵻�true�����򷵻�false
{
	return head->next == NULL;
}

template <class ElemType>
void SimpleLinkList<ElemType>::Clear()
// ���������������Ա�
{
	while (!Empty())
	{	// ���Ա�ǿգ���ɾ����1��Ԫ��
		Delete(1);								// ɾ����1��Ԫ��
	}
}

template <class ElemType>
void SimpleLinkList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
// ������������ζ����Ա��ÿ��Ԫ�ص��ú���(*visit)
{
	for (Node<ElemType> *temPtr = head->next; temPtr != NULL; temPtr = temPtr->next)
	{	// ��temPtr����ָ��ÿ��Ԫ��
		(*visit)(temPtr->data);					// �����Ա��ÿ��Ԫ�ص��ú���(*visit)
	}
}

template <class ElemType>
bool SimpleLinkList<ElemType>::GetElem(int position, ElemType &e) const
// ��������������Ա���ڵ�position��Ԫ��ʱ����e������ֵ������true,
//	���򷵻�false
{
	if (position < 1 || position > Length())
	{	// position��Χ��
		return false;							// Ԫ�ز�����
	}
	else
	{	// position�Ϸ�
		Node<ElemType> *temPtr = GetElemPtr(position);			// ȡ��ָ���position������ָ��	
		e = temPtr->data;						// ��e���ص�position��Ԫ�ص�ֵ
		return true;							// Ԫ�ش���
	}
}

template <class ElemType>
bool SimpleLinkList<ElemType>::SetElem(int position, const ElemType &e)
// ��������������Ա�ĵ�position��Ԫ�ظ�ֵΪe,
//	position��ȡֵ��ΧΪ1��position��Length(),
//	position�Ϸ�ʱ����true,���򷵻�false
{
	if (position < 1 || position > Length())
	{	// position��Χ��
		return false;							// ��Χ��
	}
	else
	{	// position�Ϸ�
		Node<ElemType> *temPtr = GetElemPtr(position);			// ȡ��ָ���position������ָ��
		temPtr->data = e;						// ���õ�position��Ԫ�ص�ֵ
		return true;							// ����Ԫ�سɹ�
	}
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Delete(int position, ElemType &e)
// ���������ɾ�����Ա�ĵ�position��Ԫ��, ����e������ֵ,
//	position��ȡֵ��ΧΪ1��position��Length(),
//	position�Ϸ�ʱ����true,���򷵻�false
{
	if (position < 1 || position > Length())
	{	// position��Χ��
		return false;							// ��Χ��
	}
	else
	{	// position�Ϸ�
		Node<ElemType> *temPtr = GetElemPtr(position - 1);		// ȡ��ָ���position-1������ָ��
		Node<ElemType> *nextPtr = temPtr->next;// nextPtrΪtemPtr�ĺ��
		temPtr->next = nextPtr->next;			// ɾ�����
		e = nextPtr->data;						// ��e���ر�ɾ���Ԫ��ֵ	
		delete nextPtr;							// �ͷű�ɾ���
		return true;							// ɾ���ɹ�
	}
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Delete(int position)
// ���������ɾ�����Ա�ĵ�position��Ԫ��,
//	position��ȡֵ��ΧΪ1��position��Length(),
//	position�Ϸ�ʱ����true,���򷵻�false
{
	if (position < 1 || position > Length())
	{	// position��Χ��
		return false;							// ��Χ��
	}
	else
	{	// position�Ϸ�
		Node<ElemType> *temPtr = GetElemPtr(position - 1);		// ȡ��ָ���position-1������ָ��
		Node<ElemType> *nextPtr = temPtr->next;// nextPtrΪtemPtr�ĺ��
		temPtr->next = nextPtr->next;			// ɾ�����
		delete nextPtr;							// �ͷű�ɾ���
		return true;							// ɾ���ɹ�
	}
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Insert(int position, const ElemType &e)
// ��������������Ա�ĵ�position��Ԫ��ǰ����Ԫ��e
//	position��ȡֵ��ΧΪ1��position��Length()+1
//	position�Ϸ�ʱ����true, ���򷵻�false
{
	if (position < 1 || position > Length() + 1)
	{	// position��Χ��
		return false;							// λ�ò��Ϸ�
	}
	else
	{	// position�Ϸ�
		Node<ElemType> *temPtr = GetElemPtr(position - 1);				// ȡ��ָ���position-1������ָ��
		Node<ElemType> *newPtr = new Node<ElemType>(e, temPtr->next);	// �����½��
		temPtr->next = newPtr;					// ��temPtr���뵽������
		return true;							// ����ɹ�
	}
}

template <class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList(const SimpleLinkList<ElemType> &source)
// ��������������Ա�source���������Ա������ƹ��캯��ģ��
{
	int sourceLength = source.Length();			// source�ĳ���
	ElemType tempElem;							// ��ʱԪ��
	head = new Node<ElemType>;					// ��ʼ�������Ա�������ֻ��ͷ���

	for (int temPos = 1; temPos <= sourceLength; temPos++)
	{	// ��������Ԫ��
		source.GetElem(temPos, tempElem);		// ȡ����temPos��Ԫ��
		Insert(Length() + 1, tempElem);			// ��tempElem���뵽��ǰ���Ա�
	}
}

template <class ElemType>
SimpleLinkList<ElemType> &SimpleLinkList<ElemType>::operator =(const SimpleLinkList<ElemType> &source)
// ��������������Ա�source��ֵ����ǰ���Ա������ظ�ֵ�����
{
	if (&source != this)
	{
		int sourceLength = source.Length();		// source�ĳ���
		ElemType tempElem;						// ��ʱԪ��
		Clear();								// ��յ�ǰ���Ա�

		for (int temPos = 1; temPos <= sourceLength; temPos++)
		{	// ��������Ԫ��
			source.GetElem(temPos, tempElem);	// ȡ����temPos��Ԫ��
			Insert(Length() + 1, tempElem);		// ��tempElem���뵽��ǰ���Ա�
		}
	}
	return *this;
}

#endif
