#pragma once
#include<map>
using namespace std;


class Goods;
class Customer;

class ShoppingCart{
public:
    ShoppingCart(Customer* cm):customer(cm){}//?
    void addGoods(Goods gd);
    bool removeGoods(Goods gd);
    Goods& getGoods(string name);
    //输入为一个Goods的数组指针
    //若商品售罄则返回false
    bool generateOrder(Goods* gd);
    Customer* getCustomer(){return customer;}
    map<Goods,int>& getGoodsMap(){return goods;}
private:
    Customer* customer;
    map<Goods,int> goods;//为一个map的key-value映射表，初始为空
};