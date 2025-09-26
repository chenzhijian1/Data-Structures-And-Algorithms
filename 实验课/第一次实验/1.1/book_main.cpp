#include <iostream>
#include "book_list.h"
using namespace std;

// 显示教材信息的函数
void displayBook(const BookInfo& book) {
    cout << book << endl;
}

// 显示菜单
void showMenu() {
    cout << "\n========== 教材信息管理系统 ==========" << endl;
    cout << "1. 添加教材" << endl;
    cout << "2. 删除教材" << endl;
    cout << "3. 修改教材信息" << endl;
    cout << "4. 查找教材（按ISBN）" << endl;
    cout << "5. 查找教材（按作者）" << endl;
    cout << "6. 显示所有教材" << endl;
    cout << "7. 按价格排序" << endl;
    cout << "8. 更新价格" << endl;
    cout << "9. 测试基本功能" << endl;
    cout << "0. 退出" << endl;
    cout << "=====================================" << endl;
    cout << "请选择操作: ";
}

int main() {
    BookList bookList(50); // 创建可存储50本书的列表
    int choice;
    
    // 初始化一些测试数据
    BookInfo book1("978-7-111-26357-4", "机械工业出版社", "谭浩强", 45.5);
    BookInfo book2("978-7-302-25710-7", "清华大学出版社", "严蔚敏", 52.0);
    BookInfo book3("978-7-115-28935-2", "人民邮电出版社", "王红梅", 38.8);
    
    bookList.Insert(1, book1);
    bookList.Insert(2, book2);
    bookList.Insert(3, book3);
    
    cout << "欢迎使用教材信息管理系统！" << endl;
    cout << "已预设3本教材信息供测试。" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: { // 添加教材
                cout << "\n请输入教材信息：" << endl;
                string isbn, publisher, author;
                double price;
                
                cout << "ISBN: ";
                cin >> isbn;
                cout << "出版社: ";
                cin >> publisher;
                cout << "作者: ";
                cin >> author;
                cout << "价格: ";
                cin >> price;
                
                BookInfo newBook(isbn, publisher, author, price);
                if (bookList.Insert(bookList.Length() + 1, newBook)) {
                    cout << "教材添加成功！" << endl;
                } else {
                    cout << "教材添加失败！" << endl;
                }
                break;
            }
            
            case 2: { // 删除教材
                cout << "\n请输入要删除的教材位置: ";
                int pos;
                cin >> pos;
                
                BookInfo deletedBook;
                if (bookList.Delete(pos, deletedBook)) {
                    cout << "成功删除教材: " << deletedBook << endl;
                } else {
                    cout << "删除失败！位置不存在。" << endl;
                }
                break;
            }
            
            case 3: { // 修改教材信息
                cout << "\n请输入要修改的教材位置: ";
                int pos;
                cin >> pos;
                
                BookInfo currentBook;
                if (bookList.GetElem(pos, currentBook)) {
                    cout << "当前教材信息: " << currentBook << endl;
                    cout << "请输入新的教材信息：" << endl;
                    
                    string isbn, publisher, author;
                    double price;
                    
                    cout << "新ISBN: ";
                    cin >> isbn;
                    cout << "新出版社: ";
                    cin >> publisher;
                    cout << "新作者: ";
                    cin >> author;
                    cout << "新价格: ";
                    cin >> price;
                    
                    BookInfo newBook(isbn, publisher, author, price);
                    if (bookList.SetElem(pos, newBook)) {
                        cout << "教材信息修改成功！" << endl;
                    } else {
                        cout << "修改失败！" << endl;
                    }
                } else {
                    cout << "位置不存在！" << endl;
                }
                break;
            }
            
            case 4: { // 按ISBN查找
                cout << "\n请输入ISBN: ";
                string isbn;
                cin >> isbn;
                
                int pos = bookList.SearchByISBN(isbn);
                if (pos > 0) {
                    BookInfo foundBook;
                    bookList.GetElem(pos, foundBook);
                    cout << "找到教材（位置" << pos << "）: " << foundBook << endl;
                } else {
                    cout << "未找到该ISBN的教材。" << endl;
                }
                break;
            }
            
            case 5: { // 按作者查找
                cout << "\n请输入作者姓名: ";
                string author;
                cin >> author;
                
                int pos = bookList.SearchByAuthor(author);
                if (pos > 0) {
                    BookInfo foundBook;
                    bookList.GetElem(pos, foundBook);
                    cout << "找到教材（位置" << pos << "）: " << foundBook << endl;
                } else {
                    cout << "未找到该作者的教材。" << endl;
                }
                break;
            }
            
            case 6: { // 显示所有教材
                cout << endl;
                bookList.DisplayAll();
                break;
            }
            
            case 7: { // 按价格排序
                bookList.SortByPrice();
                cout << "\n已按价格从低到高排序！" << endl;
                bookList.DisplayAll();
                break;
            }
            
            case 8: { // 更新价格
                cout << "\n请输入要更新价格的ISBN: ";
                string isbn;
                cin >> isbn;
                cout << "请输入新价格: ";
                double newPrice;
                cin >> newPrice;
                
                if (bookList.UpdatePrice(isbn, newPrice)) {
                    cout << "价格更新成功！" << endl;
                } else {
                    cout << "更新失败！未找到该ISBN的教材。" << endl;
                }
                break;
            }
            
            case 9: { // 测试基本功能
                cout << "\n========== 基本功能测试 ==========" << endl;
                
                // 测试长度和是否为空
                cout << "当前教材数量: " << bookList.Length() << endl;
                cout << "列表是否为空: " << (bookList.Empty() ? "是" : "否") << endl;
                
                // 测试遍历
                cout << "\n使用遍历函数显示所有教材:" << endl;
                bookList.Traverse(displayBook);
                
                // 测试复制构造函数
                BookList copyList(bookList);
                cout << "\n复制列表的教材数量: " << copyList.Length() << endl;
                
                // 测试赋值运算符
                BookList assignList;
                assignList = bookList;
                cout << "赋值列表的教材数量: " << assignList.Length() << endl;
                
                cout << "基本功能测试完成！" << endl;
                break;
            }
            
            case 0:
                cout << "感谢使用教材信息管理系统！再见！" << endl;
                break;
                
            default:
                cout << "无效选择！请重新输入。" << endl;
                break;
        }
        
    } while (choice != 0);
    
    return 0;
}