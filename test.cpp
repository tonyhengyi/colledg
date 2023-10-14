#include"design.h"

void wq_test() {
    repository& repo = repository::get_instance();
    admin admin_one;
    order_list test_list;

    test_list.add_to_list(commodity_type::TYPE_1, 10);
    test_list.add_to_list(commodity_type::TYPE_2, 10);
    test_list.add_to_list(commodity_type::TYPE_3, 10);

    admin_one.add_to_repo(test_list.get_list(), repo);


    consumer con;
    con.buy_commodity(commodity_type::TYPE_1, 5);
    con.reduce_commodity(commodity_type::TYPE_1, 3);

    admin_one.del_to_repo(con.get_final_order().get_list(), repo);

    repo.get_info();
}
void zhy_test()
{
    CommodityFactory* tvFactory = new TVFactory();
    CommodityFactory* computerFactory = new ComputerFactory();
    CommodityFactory* refrigeratorFactory = new RefrigeratorFactory();

    Commodity* tv = tvFactory->create();
    Commodity* computer = computerFactory->create();
    Commodity* refrigerator = refrigeratorFactory->create();

    tv->printInfo();
    computer->printInfo();
    refrigerator->printInfo();

    delete tvFactory;
    delete computerFactory;
    delete refrigeratorFactory;

    delete tv;
    delete computer;
    delete refrigerator;
}
int main() {
    wq_test();
    cout<<"========\n";
    zhy_test();
    return 0;
}