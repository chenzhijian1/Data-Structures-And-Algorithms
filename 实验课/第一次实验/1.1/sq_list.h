#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

#ifndef DEFAULT_SIZE
#define DEFAULT_SIZE 1000		// 缺省元素个数
#endif

// 顺序表类模板
template <class ElemType>
class SqList {
public:
// 抽象数据类型方法声明及重载编译系统默认方法声明:
    SqList(int size = DEFAULT_SIZE);
    virtual ~SqList(); // 析构函数
    int Length() const;					// 求线性表长度			 
	bool Empty() const;					// 判断线性表是否为空
	void Clear();						// 将线性表清空
	void Traverse(void (*visit)(const ElemType &)) const;		// 遍历线性表
	bool GetElem(int position, ElemType &e) const;				// 求指定位置的元素	
	bool SetElem(int position, const ElemType &e);				// 设置指定位置的元素值
	bool Delete(int position, ElemType &e);						// 删除元素		
	bool Delete(int position);			// 删除元素		
	bool Insert(int position, const ElemType &e);				// 插入元素
    SqList(const SqList<ElemType> &source);						// 复制构造函数模板
	SqList<ElemType> &operator =(const SqList<ElemType> &source); // 重载赋值运算符
	
protected:
// 数据成员:
    ElemType *elems;					// 元素存储空间
    int maxSize;						// 顺序表最大元素个数
    int count;							// 元素个数
    
};

// 实现部分
template <class ElemType>
SqList<ElemType>::SqList(int size) {
    maxSize = size;
    elems = new ElemType[maxSize];
    count = 0;
}

template <class ElemType>
SqList<ElemType>::~SqList() {
    delete [] elems;
}

template <class ElemType>
int SqList<ElemType>::Length() const {
    return count;
}

template <class ElemType>
bool SqList<ElemType>::Empty() const {
    return count == 0;
}

template <class ElemType>
void SqList<ElemType>::Clear() {
    count = 0;
}

template <class ElemType>
void SqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const {
    for (int i = 0; i < Length(); i++) {
        (*visit)(elems[i]);
    }
}

template <class ElemType>
bool SqList<ElemType>::GetElem(int position, ElemType &e) const {
    if (position < 1 || position > Length()) {
        return false;
    }
    else {
        e = elems[position - 1];
        return true;
    }
}

template <class ElemType>
bool SqList<ElemType>::SetElem(int position, const ElemType &e) { // 常亮引用防止修改
    if (position < 1 || position > Length()) {
        return false;
    }
    else {
        elems[position - 1] = e;
        return true;
    }
}

template <class ElemType>
bool SqList<ElemType>::Delete(int position, ElemType &e) {
    if (position < 1 || position > Length()) {
        return false;
    }
    else {
        GetElem(position, e);
        for (int i = position; i < Length(); i++) {
            elems[i - 1] = elems[i];
        }
        count--;
        return true;
    }
}

template <class ElemType>
bool SqList<ElemType>::Delete(int position) {
    if (position < 1 || position > Length()) {
        return false;
    }
    else {
        for (int i = position; i < Length(); i++) {
            elems[i - 1] = elems[i];
        }
        count--;
        return true;
    }
}

template <class ElemType>
bool SqList<ElemType>::Insert(int position, const ElemType &e) {
    if (position < 1 || position > Length() + 1) {
        return false;
    }
    if (Length() == maxSize) { // 顺序表满
        return false;
    }
    for (int i = Length(); i >= position; i--) { // 原先的尾部是Length()-1
        elems[i] = elems[i - 1];
    }
    elems[position - 1] = e;
    count++;
    return true;
}

template <class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType> &source) { // 复制构造函数模板
    maxSize = source.maxSize;
    count = source.count;
    elems = new ElemType[maxSize];
    for (int i = 0; i < count; i++) {
        elems[i] = source.elems[i];
    }
}

template <class ElemType>
SqList<ElemType> &SqList<ElemType>::operator =(const SqList<ElemType> &source) { // 重载赋值运算符，防止浅拷贝b = a导致两个对象共用同内存
    if (this != &source) { // 不是自赋值
        delete [] elems; // 释放原有空间
        maxSize = source.maxSize;
        count = source.count;
        elems = new ElemType[maxSize];
        for (int i = 0; i < count; i++) {
            elems[i] = source.elems[i];
        }
    }
    return *this;
}

#endif