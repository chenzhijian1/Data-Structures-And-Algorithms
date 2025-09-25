#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__

#ifndef DEFAULT_SIZE
#define DEFAULT_SIZE 1000											// ȱʡԪ�ظ���
#endif

// ˳��ջ��ģ��
template<class ElemType>
class SqStack 
{
protected:
// ���ݳ�Ա:
	ElemType *elems;												// Ԫ�ش洢�ռ�
	int maxSize;													// ջ���Ԫ�ظ���
	int count;														// Ԫ�ظ���

public:
// �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	SqStack(int size = DEFAULT_SIZE);								// ���캯��ģ��
	virtual ~SqStack();												// ��������ģ��
	int Length() const;												// ��ջ����			 
	bool Empty() const;												// �ж�ջ�Ƿ�Ϊ��
	void Clear();													// ��ջ���
	void Traverse(void (*visit)(const ElemType &)) const;			// ����ջ
	bool Push(const ElemType &e);									// ��ջ
	bool Top(ElemType &e) const;									// ����ջ��Ԫ��
	bool Pop(ElemType &e);											// ��ջ
	bool Pop();														// ��ջ
	SqStack(const SqStack<ElemType> &source);						// ���ƹ��캯��ģ��
	SqStack<ElemType> &operator =(const SqStack<ElemType> &source);	// ���ظ�ֵ�����
};


// ˳��ջ��ģ���ʵ�ֲ���

template<class ElemType>
SqStack<ElemType>::SqStack(int size)
// �������������һ�����Ԫ�ظ���Ϊsize�Ŀ�ջ
{
	maxSize = size;													// ���Ԫ�ظ���
	elems = new ElemType[maxSize];									// ����洢�ռ�
	count = 0;														// ��ջԪ�ظ���Ϊ0
}

template<class ElemType>
SqStack<ElemType>::~SqStack()
// �������������ջ
{
	delete []elems;													// �ͷŴ洢�ռ�
}

template <class ElemType>
int SqStack<ElemType>::Length() const
// �������������ջԪ�ظ���
{
	return count;													// count��ʾջԪ�ظ���
}

template<class ElemType>
bool SqStack<ElemType>::Empty() const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
	return count == 0;												// count == 0��ʾջΪ��
}

template<class ElemType>
void SqStack<ElemType>::Clear()
// ������������ջ
{
	count = 0;														// ���ջ��Ԫ�ظ���Ϊ0
}

template <class ElemType>
void SqStack<ElemType>::Traverse(void (*visit)(const ElemType &)) const
// �����������ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���(*visit)
{
	for (int temPos = 1; temPos <= Length(); temPos++)
	{	// ��ջ�׵�ջ����ջ��ÿ��Ԫ�ص��ú���(*visit)
		(*visit)(elems[temPos - 1]);
	}
}

template<class ElemType>
bool SqStack<ElemType>::Push(const ElemType &e)
// �����������Ԫ��e׷�ӵ�ջ��,��ɹ��򷵼�true,��ջ����������false
{
	if (count == maxSize) 
	{	// ջ����
		return false;												// ��ջʧ��
	}
	else
	{	// �����ɹ�
		elems[count] = e;											// ��Ԫ��e׷�ӵ�ջ�� 
		count++;													// ��ջ�ɹ���Ԫ�ظ����Լ�1 
		return true;												// ��ջ�ɹ�
	}
}

template<class ElemType>
bool SqStack<ElemType>::Top(ElemType &e) const
// �����������ջ�ǿ�,��e����ջ��Ԫ��,����true,���򷵻�false
{
	if(Empty())
	{	// ջ��
		return false;												// ʧ��
	}
	else
	{	// ջ�ǿ�,�����ɹ�
		e = elems[count - 1];										// ��e����ջ��Ԫ��
		return true;												// �ɹ�
	}
}

template<class ElemType>
bool SqStack<ElemType>::Pop(ElemType &e)
// �����������ջ�ǿ�,ɾ��ջ��Ԫ��,����e����ջ��Ԫ��,����true,����
//	����false
{
	if (Empty())
	{	// ջ��
		return false;												// ʧ��
	}
	else
	{	// �����ɹ�
		e = elems[count - 1];										// ��e����ջ��Ԫ��
		count--;													// ��ջ�ɹ���Ԫ�ظ����Լ�1
		return true;												// �ɹ�
	}
}

template<class ElemType>
bool SqStack<ElemType>::Pop()
// �����������ջ�ǿ�,ɾ��ջ��Ԫ��,����true,����
//	����false
{
	if (Empty())
	{	// ջ��
		return false;												// ʧ��
	}
	else
	{	// �����ɹ�
		count--;													// ��ջ�ɹ���Ԫ�ظ����Լ�1
		return true;												// �ɹ�
	}
}

template<class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType> &source) 
// �����������ջsource������ջ�������ƹ��캯��ģ��
{
	maxSize = source.maxSize;										// ���Ԫ�ظ���
	elems = new ElemType[maxSize];									// ����洢�ռ�
	count = source.count;											// ջԪ�ظ���
	for (int temPos = 1; temPos <= Length(); temPos++)
	{	// ��ջ�׵�ջ����ջsource��ÿ��Ԫ�ؽ��и���
		elems[temPos - 1] = source.elems[temPos - 1];
	}
}

template<class ElemType>
SqStack<ElemType> &SqStack<ElemType>::operator = (const SqStack<ElemType> &source)
// �����������ջsource��ֵ����ǰջ�������ظ�ֵ�����
{
	if (&source != this)
	{
		maxSize = source.maxSize;									// ���Ԫ�ظ���
		delete []elems;	// �ͷŴ洢�ռ�
		elems = new ElemType[maxSize];								// ����洢�ռ�
		count = source.count;										// ����ջԪ�ظ���
		for (int temPos = 1; temPos <= Length(); temPos++)
		{	// ��ջ�׵�ջ����ջsource��ÿ��Ԫ�ؽ��и���
			elems[temPos - 1] = source.elems[temPos - 1];
		}
	}
	return *this;
}

#endif