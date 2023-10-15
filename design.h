#ifndef ALL_USE
#include<bits/stdc++.h>
using namespace std;

enum class commodity_type {
    //货物类型
    TYPE_1,
    TYPE_2,
    TYPE_3

};

class repository {//仓库类
public:

    static repository& get_instance() {
        static repository repo;
        return repo;
    }

    unsigned get_cnt_of_type(commodity_type ty) {
        return list[ty];
    }

    void add(commodity_type ty, unsigned cnt) {
        cout << "repo: +" << cnt << endl;
        list[ty] += cnt;
    }

    void del(commodity_type ty, unsigned  cnt) {

        if (list[ty] > cnt) {
            list[ty] -= cnt;
            cout << "repo: -" << cnt << "\n";

        }
        else {
            assert(list[ty] >= cnt);
            cout << "repo: exceed sub cnt,so don't redece\n";
        }
    }
    //todo
    void get_info() {
        for (auto item : list) {
            if (item.first == commodity_type::TYPE_1)
                cout << "type1: " << item.second << '\n';
            else if (item.first == commodity_type::TYPE_2)
                cout << "type2: " << item.second << '\n';
            else if (item.first == commodity_type::TYPE_3)
                cout << "type3: " << item.second << '\n';
        }
    }
private:
    unordered_map<commodity_type, unsigned > list;


    repository() { };

    repository(const repository& repo);

    repository& operator = (const repository&) = delete;


};

class admin {//服务员

public:
    void add_to_repo(unordered_map<commodity_type, unsigned>list, repository& repo) {
        for (auto item : list) {

            repo.add(item.first, item.second);
        }
    }

    void del_to_repo(unordered_map<commodity_type, unsigned>list, repository& repo) {
        for (auto item : list) {
            //transaction character
            if (item.second > repo.get_cnt_of_type(item.first)) {
                cout << "exceed cnt,admin ALL del failed\n ";
                return;
            }
        }
        for (auto item : list) {

            repo.del(item.first, item.second);
        }
    }
};

class order_list {
private:
    unordered_map<commodity_type, unsigned>list;

public:
    void add_to_list(commodity_type ty, unsigned  cnt) {
        cout << "order list: +" << cnt << endl;
        list[ty] += cnt;
    }

    void reduce_to_list(commodity_type ty, unsigned cnt) {
        if (list[ty] < cnt) {
            cout << "exceed sub cnt,so DON't redece\n";
        }
        else {
            list[ty] -= cnt;
            cout << "order list: -" << cnt << "\tnow have: " << list[ty] << '\n';
        }
        return;
    }

    unordered_map<commodity_type, unsigned> get_list() {
        return list;
    }

    void clean_list() {
        list.clear();
    }
};

class consumer {
    order_list buy_list;

public:
    void  buy_commodity(commodity_type ty, unsigned  cnt) {
        cout << "consumer: ";
        buy_list.add_to_list(ty, cnt);
    }

    void reduce_commodity(commodity_type ty, unsigned  cnt) {
        cout << "consumer: ";
        buy_list.reduce_to_list(ty, cnt);
    }

    order_list get_final_order() {
        return buy_list;
    }
};


class Commodity {
public:
    virtual void printInfo() = 0;
    virtual ~Commodity() { }
    virtual commodity_type get_type() = 0;
    virtual Commodity* clone() = 0;
};

class TV : public Commodity {
public:
    TV(std::string model) : model_(model) { }
    TV(const TV& other) : model_(other.model_) { }
    void printInfo() override {
        std::cout << "TV Model: " << model_ << std::endl;
    }
    commodity_type get_type() override {
        return commodity_type::TYPE_1;
    }
    Commodity* clone() override {
        return new TV(*this);
    }
    static TV* getInstance() { // 静态方法，用于获取一个可克隆的实例
        static TV instance("Sony");
        return &instance;
    }
private:
    std::string model_;
};


class Computer : public Commodity {
public:
    Computer(std::string type) : type_(type) { }
    Computer(const Computer& other) : type_(other.type_) { } // copy constructor
    void printInfo() override {
        std::cout << "Computer Type: " << type_ << std::endl;
    }
    commodity_type get_type() override {
        return commodity_type::TYPE_2;
    }
    Commodity* clone() override {
        return new Computer(*this);
    }
    static Computer* getInstance() { // 静态方法，用于获取一个可克隆的实例
        static Computer instance("Laptop");
        return &instance;
    }
private:
    std::string type_;
};

class Refrigerator : public Commodity {
public:
    Refrigerator(std::string brand) : brand_(brand) { }
    Refrigerator(const Refrigerator& other) : brand_(other.brand_) { } // copy constructor
    void printInfo() override {
        std::cout << "Refrigerator Brand: " << brand_ << std::endl;
    }
    commodity_type get_type() override {
        return commodity_type::TYPE_3;
    }
    Commodity* clone() override {
        return new Refrigerator(*this);
    }
    static Refrigerator* getInstance() { // 静态方法，用于获取一个可克隆的实例
        static Refrigerator instance("Samsung");
        return &instance;
    }
private:
    std::string brand_;
};

class CommodityFactory { //抽象工厂
public:
    virtual Commodity* clone() = 0;
    virtual ~CommodityFactory() { }
};

class TVFactory : public CommodityFactory {
public:
    Commodity* clone() override {
        return TV::getInstance()->clone(); // 克隆 TV 的静态实例
    }
};

class ComputerFactory : public CommodityFactory {
public:
    Commodity* clone() override {
        return Computer::getInstance()->clone(); // 克隆 TV 的静态实例
    }
};

class RefrigeratorFactory : public CommodityFactory {
public:
    Commodity* clone() override {
        return Refrigerator::getInstance()->clone(); // 克隆 TV 的静态实例
    }
};


#endif