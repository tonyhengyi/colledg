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


class Commodity {//原型模式，通过复制来的得到新的类型
public:
    virtual void printInfo() = 0;
    virtual ~Commodity() {}
};

class TV : public Commodity {
public:
    TV(std::string model) : model_(model) {}
    void printInfo() {
        std::cout << "TV Model: " << model_ << std::endl;
    }
private:
    std::string model_;
};

class Computer : public Commodity {
public:
    Computer(std::string type) : type_(type) {}
    void printInfo() {
        std::cout << "Computer Type: " << type_ << std::endl;
    }
private:
    std::string type_;
};

class Refrigerator : public Commodity {
public:
    Refrigerator(std::string brand) : brand_(brand) {}
    void printInfo() {
        std::cout << "Refrigerator Brand: " << brand_ << std::endl;
    }
private:
    std::string brand_;
};

class CommodityFactory {//抽象工厂
public:
    virtual Commodity* create() = 0;
    virtual ~CommodityFactory() {}
};

class TVFactory : public CommodityFactory {
public:
    Commodity* create() {
        return new TV("Sony");
    }
};

class ComputerFactory : public CommodityFactory {
public:
    Commodity* create() {
        return new Computer("Laptop");
    }
};

class RefrigeratorFactory : public CommodityFactory {
public:
    Commodity* create() {
        return new Refrigerator("Samsung");
    }
};


#endif