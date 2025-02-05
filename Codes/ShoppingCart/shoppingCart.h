﻿#pragma once
#include<map>
#include<string>
#include"../Shop/goods.h"
using namespace std;

//预声明
class Customer;

//购物车数据实体
//数据访问对象模式
class CartData {
public:
    //添加商品数据
    bool add(Goods, int);
    //删除商品数据
    bool remove(Goods);
    //获取商品数据
    bool get(string, Goods&);
    //获取商品map
    map<Goods,int>& getMap();
    //设置商品数量
    bool setNum(Goods, int);
private:
    map<Goods,int> goods;
};

class ShoppingCart{
public:
    ShoppingCart(Customer* c){
        goodsData = new CartData;
        this->customer = c;
        goodsData=new CartData;
    }
    void addGoods(Goods gd, int num);
    bool removeGoods(Goods gd);
    bool getGoods(string name,Goods& gd);
    bool setGoodsNum(Goods, int);
    void showAllGoods();

    //输入为一个Goods的数组指针
    //若商品售罄则返回false
    bool generateOrder(map<Goods,int> gds);
    map<Goods,int>& getGoodsMap();

    //Observer同步更新
    void update(Goods);

private:
    CartData* goodsData;//为一个map的key-value映射表，初始为空
    Customer *customer;
    bool isUpdate = false;//标记该购物车中是否有商品被商店下架
    vector<Goods> offShelfGoods;//存储已被商店下架的商品，每次打印更新信息后清空
};