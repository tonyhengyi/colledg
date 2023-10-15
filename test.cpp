#include"design.h"
repository& repo = repository::get_instance();
void test()
{
    CommodityFactory* tvFactory = new TVFactory();
    CommodityFactory* computerFactory = new ComputerFactory();
    CommodityFactory* refrigeratorFactory = new RefrigeratorFactory();

    Commodity* tv = tvFactory->create();
    Commodity* computer = computerFactory->create();
    Commodity* refrigerator = refrigeratorFactory->create();
    cout<<"============================"<<endl;
    cout<<"   Product name:   brand:   "<<endl;
    tv->printInfo();
    computer->printInfo();
    refrigerator->printInfo();
    cout<<"============================"<<endl;
    cout<<"User order:"<<endl;
    //用户的订单每样增加20个商品
    consumer fa_con;
    cout<<"(Store)Please enter the quantity you need for each product"<<endl;
    unsigned cnt1,cnt2,cnt3;
    cout<<"Please enter the quantity you need for tv"<<endl;
    cin>>cnt1;
    cout<<"Please enter the quantity you need for computer "<<endl;
    cin>>cnt2;
    cout<<"Please enter the quantity you need for refrigerator"<<endl;
    cin>>cnt3;
    fa_con.buy_commodity(tv->get_type(), cnt1);
    fa_con.buy_commodity(computer->get_type(), cnt2);
    fa_con.buy_commodity(refrigerator->get_type(), cnt3);
    cout<<"Factory production:"<<endl;

    admin factory_admin;
    factory_admin.add_to_repo(fa_con.get_final_order().get_list(), repo);

    admin admin_one;
    order_list test_list;
    consumer con;
    unsigned cnt4,cnt5,cnt6;
    while(1)
    {

        cout<<"(Customer)Please enter the quantity you need for each product"<<endl;

        cout<<"Please enter the quantity you need for tv"<<endl;
        cin>>cnt4;
        cout<<"Please enter the quantity you need for computer "<<endl;
        cin>>cnt5;
        cout<<"Please enter the quantity you need for refrigerator"<<endl;
        cin>>cnt6;
        cout<<"Submit order or not(y/n)"<<endl;
        char submit;
        cin>>submit;
        if(submit=='y')
        {
            
            break;
        }
    }
    con.buy_commodity(commodity_type::TYPE_1, cnt4);
    con.buy_commodity(commodity_type::TYPE_2, cnt5);
    con.buy_commodity(commodity_type::TYPE_3, cnt6);
    admin_one.del_to_repo(con.get_final_order().get_list(), repo);
    cout<<"Final storage:"<<endl;
    repo.get_info();
    delete tvFactory;
    delete computerFactory;
    delete refrigeratorFactory;

    delete tv;
    delete computer;
    delete refrigerator;
}
int main() {
    test();
    return 0;
}