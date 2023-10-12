#ifndef ALL_USE
#include<bits/stdc++.h>
using namespace std;

enum class commodity_type {
    TYPE_1,
    TYPE_2,
    TYPE_3
};

class repository {
    void add_commodity();
    void del_commodity();

};

class admin {

};

class order_list {
    private:
    vector<pair<commodity_type, int>>list;

    public:
    void add_to_list(pair<commodity_type, int> todo) {
        list.push_back(todo);
    }

    vector<pair<commodity_type, int>> get_list() {
        return list;
    }
    bool clean_list() {
        list.clear();
    }
};

class consumer {
    order_list buy_list;
    void  buy_commodity(commodity_type ty, unsigned int cnt) {
        buy_list.add_to_list(pair<commodity_type, unsigned int>{ty, cnt});
    }
};


class commdity { };

class original_factory { };


#endif