#ifndef ALL_USE
#include<bits/stdc++.h>
using namespace std;

enum class commodity_type {
    TYPE_1,
    TYPE_2,
    TYPE_3

};

class repository {
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

class admin {

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


class commdity { };

class original_factory { };


#endif