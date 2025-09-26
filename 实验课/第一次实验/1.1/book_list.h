#ifndef __BOOK_LIST_H__
#define __BOOK_LIST_H__

#include <iostream>
#include <string>
using namespace std;

#ifndef DEFAULT_SIZE
#define DEFAULT_SIZE 1000		// 缺省元素个数
#endif

// 教材信息结构体
struct BookInfo {
    string isbn;        // ISBN号
    string publisher;   // 出版社
    string author;      // 作者
    double price;       // 价格
    
    // 默认构造函数
    BookInfo() : isbn(""), publisher(""), author(""), price(0.0) {}
    
    // 带参构造函数
    BookInfo(const string& i, const string& p, const string& a, double pr) 
        : isbn(i), publisher(p), author(a), price(pr) {}
    
    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const BookInfo& book) {
        os << "ISBN: " << book.isbn << ", 出版社: " << book.publisher 
           << ", 作者: " << book.author << ", 价格: " << book.price;
        return os;
    }
    
    // 重载比较运算符（按ISBN比较）
    bool operator==(const BookInfo& other) const {
        return isbn == other.isbn;
    }
};

// 教材信息顺序表类
class BookList {
public:
    // 构造和析构函数
    BookList(int size = DEFAULT_SIZE);
    BookList(const BookList& source);                    // 复制构造函数
    BookList& operator=(const BookList& source);         // 赋值运算符重载
    virtual ~BookList();                                 // 析构函数
    
    // 基本操作
    int Length() const;                                  // 求线性表长度
    bool Empty() const;                                  // 判断线性表是否为空
    void Clear();                                        // 将线性表清空
    void Traverse(void (*visit)(const BookInfo&)) const; // 遍历线性表
    bool GetElem(int position, BookInfo& e) const;       // 求指定位置的元素
    bool SetElem(int position, const BookInfo& e);       // 设置指定位置的元素值
    bool Delete(int position, BookInfo& e);              // 删除元素
    bool Delete(int position);                           // 删除元素
    bool Insert(int position, const BookInfo& e);        // 插入元素
    
    // 教材信息特有操作
    int SearchByISBN(const string& isbn) const;          // 按ISBN查找
    int SearchByAuthor(const string& author) const;      // 按作者查找
    void DisplayAll() const;                             // 显示所有教材信息
    bool UpdatePrice(const string& isbn, double newPrice); // 更新价格
    void SortByPrice();                                  // 按价格排序
    
protected:
    BookInfo* elems;        // 元素存储空间
    int maxSize;           // 顺序表最大元素个数
    int count;             // 元素个数
};

// 实现部分

// 构造函数
BookList::BookList(int size) {
    maxSize = size;
    elems = new BookInfo[maxSize];
    count = 0;
}

// 析构函数
BookList::~BookList() {
    delete[] elems;
}

// 复制构造函数
BookList::BookList(const BookList& source) {
    maxSize = source.maxSize;
    count = source.count;
    elems = new BookInfo[maxSize];
    for (int i = 0; i < count; i++) {
        elems[i] = source.elems[i];
    }
}

// 赋值运算符重载
BookList& BookList::operator=(const BookList& source) {
    if (this != &source) {
        delete[] elems;
        maxSize = source.maxSize;
        count = source.count;
        elems = new BookInfo[maxSize];
        for (int i = 0; i < count; i++) {
            elems[i] = source.elems[i];
        }
    }
    return *this;
}

// 求长度
int BookList::Length() const {
    return count;
}

// 判断是否为空
bool BookList::Empty() const {
    return count == 0;
}

// 清空
void BookList::Clear() {
    count = 0;
}

// 遍历
void BookList::Traverse(void (*visit)(const BookInfo&)) const {
    for (int i = 0; i < count; i++) {
        (*visit)(elems[i]);
    }
}

// 获取元素
bool BookList::GetElem(int position, BookInfo& e) const {
    if (position < 1 || position > count) {
        return false;
    }
    e = elems[position - 1];
    return true;
}

// 设置元素
bool BookList::SetElem(int position, const BookInfo& e) {
    if (position < 1 || position > count) {
        return false;
    }
    elems[position - 1] = e;
    return true;
}

// 删除元素（返回被删除的元素）
bool BookList::Delete(int position, BookInfo& e) {
    if (position < 1 || position > count) {
        return false;
    }
    e = elems[position - 1];
    for (int i = position - 1; i < count - 1; i++) {
        elems[i] = elems[i + 1];
    }
    count--;
    return true;
}

// 删除元素（不返回被删除的元素）
bool BookList::Delete(int position) {
    if (position < 1 || position > count) {
        return false;
    }
    for (int i = position - 1; i < count - 1; i++) {
        elems[i] = elems[i + 1];
    }
    count--;
    return true;
}

// 插入元素
bool BookList::Insert(int position, const BookInfo& e) {
    if (position < 1 || position > count + 1) {
        return false;
    }
    if (count >= maxSize) {
        return false;
    }
    for (int i = count; i >= position; i--) {
        elems[i] = elems[i - 1];
    }
    elems[position - 1] = e;
    count++;
    return true;
}

// 按ISBN查找
int BookList::SearchByISBN(const string& isbn) const {
    for (int i = 0; i < count; i++) {
        if (elems[i].isbn == isbn) {
            return i + 1; // 返回位置（从1开始）
        }
    }
    return 0; // 未找到
}

// 按作者查找
int BookList::SearchByAuthor(const string& author) const {
    for (int i = 0; i < count; i++) {
        if (elems[i].author == author) {
            return i + 1; // 返回位置（从1开始）
        }
    }
    return 0; // 未找到
}

// 显示所有教材信息
void BookList::DisplayAll() const {
    cout << "教材列表（共" << count << "本）：" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << "第" << (i + 1) << "本：" << elems[i] << endl;
    }
    cout << "----------------------------------------" << endl;
}

// 更新价格
bool BookList::UpdatePrice(const string& isbn, double newPrice) {
    int pos = SearchByISBN(isbn);
    if (pos > 0) {
        elems[pos - 1].price = newPrice;
        return true;
    }
    return false;
}

// 按价格排序（冒泡排序）
void BookList::SortByPrice() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (elems[j].price > elems[j + 1].price) {
                BookInfo temp = elems[j];
                elems[j] = elems[j + 1];
                elems[j + 1] = temp;
            }
        }
    }
}

#endif