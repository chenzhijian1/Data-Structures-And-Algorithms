#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__

#ifndef DEFAULT_SIZE
#define DEFAULT_SIZE 1000		// 缺省元素个数
#endif

// 顺序表类模板
template <class ElemType>
class SqList {
protected:
// 数据成员:
    ElemType *elems;					// 元素存储空间
    int maxSize;						// 顺序表最大元素个数
    int count;							// 元素个数

public:
// 抽象数据类型方法声明及重载编译系统默认方法声明:
    SqList(int size = DEFAULT_SIZE);
    
}