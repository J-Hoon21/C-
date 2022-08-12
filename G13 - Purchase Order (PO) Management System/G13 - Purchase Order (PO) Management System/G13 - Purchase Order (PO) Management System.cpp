#include<iostream>
#include <iomanip> // to setw()
#include<string>
#include<sstream>
#include<fstream>
#include<conio.h> // for password
using namespace std;

//STRUCT SALE ----------------------------------------STRUCT SALES-----------------------------------STRUCT SALES

struct SalesNode {
    string order_id, order_date, order_status, item_id, item_name;
    int order_quantity;
    double item_price, delivery_price, total_price;
    string cust_id, cust_name, cust_contnum, cust_address;

    int iSold;
    double sTotal;
    SalesNode* next;
};
struct CustomerNode {
    string customer_id, customer_name, customer_contact, customer_address;
    CustomerNode* next;
};
struct ItemNode {
    string Item_id, Item_name, Item_category;
    double Item_price;
    ItemNode* next;
};



struct SalesLinkedList {
    SalesNode* head = new SalesNode;
    SalesNode* head2 = new SalesNode;
    CustomerNode* head3 = new CustomerNode;
    ItemNode* head4 = new ItemNode;
    SalesLinkedList() {
        this->head = nullptr;
        this->head2 = nullptr;
        this->head3 = nullptr;
        this->head4 = nullptr;
    }
    bool checkID(string id) {
        SalesNode* temp = head;
        if (head == NULL)
            return false;
        temp = head;
        while (temp != NULL) {
            if (temp->order_id == id)
                return true;
            temp = temp->next;
        }
        return false;
    }
    //-----------------------------------------------------------------------------------------------------------
    //FUNCTIONS-----------------------------------------FUNCTIONS---------------------------------------FUNCTIONS
    //-----------------------------------------------------------------------------------------------------------

    //Receive Records--------------------------------Receive Records------------------------------Receive Records
    void receive_order_data(string order_id, string order_date, string order_status,
        string item_id, string item_name,
        int order_quantity,
        double item_price, double delivery_price, double total_price,
        string cust_id, string cust_name, string cust_contnum, string cust_address) {
        //create new node to add new data
        SalesNode* data = new SalesNode();
        data->order_id = order_id;
        data->order_date = order_date;
        data->order_status = order_status;

        data->item_id = item_id;
        data->item_name = item_name;
        data->order_quantity = order_quantity;
        data->item_price = item_price;
        data->delivery_price = delivery_price;
        data->total_price = total_price;

        data->cust_id = cust_id;
        data->cust_name = cust_name;
        data->cust_contnum = cust_contnum;
        data->cust_address = cust_address;
        data->next = NULL;

        //Check ID
        if (checkID(order_id)) {
            cout << " The order ID already exists." << endl;
            cout << " Please put new order ID." << endl;
            return;
        }
        //Insert in front
        if (head == NULL || (head->order_id >= data->order_id)) {
            data->next = head;
            head = data;
        }
        else {
            SalesNode* last = head;
            while (last->next != NULL && last->next->order_id < data->order_id) {
                last = last->next;
            }
            data->next = last->next;
            last->next = data;
        }
        cout << "Added records successfully " << endl;
    }

    void receive_customer_data(string customer_id, string customer_name, string customer_contact, string customer_address) {
        CustomerNode* data3 = new CustomerNode();
        data3->customer_id = customer_id;
        data3->customer_name = customer_name;
        data3->customer_contact = customer_contact;
        data3->customer_address = customer_address;

        //Check ID
        if (checkID(customer_id)) {
            cout << " The Customer ID already exists." << endl;
            cout << " Please put new Customer ID." << endl;
            return;
        }
        //Insert in front
        if (head3 == NULL || (head3->customer_id >= data3->customer_id)) {
            data3->next = head3;
            head3 = data3;
        }
        else {
            CustomerNode* last3 = head3;
            while (last3->next != NULL && last3->next->customer_id < data3->customer_id) {
                last3 = last3->next;
            }
            data3->next = last3->next;
            last3->next = data3;
        }
        cout << "Added Customer records successfully " << endl;
    }

    void receive_item_data(string Item_id, string Item_name, string Item_category, double Item_price) {
        ItemNode* data4 = new ItemNode();
        data4->Item_id = Item_id;
        data4->Item_name = Item_name;
        data4->Item_category = Item_category;
        data4->Item_price = Item_price;

        //Check ID
        if (checkID(Item_id)) {
            cout << " The Item ID already exists." << endl;
            cout << " Please put new Item ID." << endl;
            return;
        }
        //Insert in front
        if (head4 == NULL || (head4->Item_id >= data4->Item_id)) {
            data4->next = head4;
            head4 = data4;
        }
        else {
            ItemNode* last4 = head4;
            while (last4->next != NULL && last4->next->Item_id < data4->Item_id) {
                last4 = last4->next;
            }
            data4->next = last4->next;
            last4->next = data4;
        }
        cout << "Added Item records successfully " << endl;
    }




    //Add Records--------------------------------------Add Records------------------------------------Add Records
    void add_order() {
        system("cls");
        string input;
        string order_id, order_date, order_status, item_id, item_name;
        int order_quantity;
        double item_price, delivery_price, total_price;
        string cust_id, cust_name, cust_contnum, cust_address;

        string cus_id; // Customer Node
        string itm_id; // Item Node


        SalesNode* temp = head;
        CustomerNode* cus = head3;
        ItemNode* itm = head4;
        if (temp != NULL && cus != NULL) {
        view_order_list();
        cout << "*********************Add New Order*******************" << endl;
        cout << "  Enter 0 Exit to Main Menu" << endl;
        cout << "  Enter New Order ID: " << endl;
        cin >> order_id;
        if (order_id == "0") {
            system("cls");
        }
        else {
            cout << "Date format (DD/MM/YYYY)" << endl;
            cout << "Enter Order Date: ";
            cin.ignore();
            getline(cin, input);
            stringstream(input) >> order_date;

            customer_list();
            cout << "Enter Customer ID (enter 0 to cancel order): ";
            cin >> cus_id;
                while (cus != NULL) {
                    if (cus->customer_id == cus_id) {
                        cust_id = cus->customer_id;
                        cust_name = cus->customer_name;
                        cust_contnum = cus->customer_contact;
                        cust_address = cus->customer_address;
                    }
                    else if (cus_id == "0") {
                        cout << "Add Order Cancel" << endl;
                        system("pause");
                        system("cls");
                        add_order();
                    }
                    cus = cus->next;
                }
            if (cust_name == "") {
                cout << "Customer ID Not Found Please Try Again!" << endl;
                system("pause");
                add_order();
            }



            item_list();
            cout << "Enter Item ID (enter 0 to cancel order): \n";
            cin.ignore();
            cin >> itm_id;
            while (itm != NULL) {
                if (itm->Item_id == itm_id) {
                    item_id = itm->Item_id;
                    item_name = itm->Item_name;
                    item_price = itm->Item_price;
                }
                else if (itm_id == "0") {
                    cout << "Add Order Cancel" << endl;
                    system("pause");
                    system("cls");
                    add_order();
                }
                itm = itm->next;
            }
            if (item_name == "") {
                cout << "Item ID Not Found Please Try Again!" << endl;
                system("pause");
                add_order();
            }
            cout << "Enter Quantity: ";
            cin >> order_quantity;
            cout << "Enter Delivery Price: ";
            cin >> delivery_price;
            total_price = (item_price * order_quantity) + delivery_price;
            order_status = "Pending";

            receive_order_data(order_id, order_date, order_status,
                item_id, item_name, order_quantity, item_price, delivery_price, total_price,
                cust_id, cust_name, cust_contnum, cust_address);
            system("pause");
            system("cls");
            view_order_list();
            system("pause");
            system("cls");
        }
    }
    }
    //Display Records--------------------------------Display Records------------------------------Display Records
    void view_order_list() {
        SalesNode* temp = head;
        if (temp != NULL) {
            cout << "********* View All Records *********" << endl;
            cout << "| Order ID | Order Date | Order Status | Item ID |  Item Name  | Quantity | Price $ | Delivery $ | Total $ | Customer ID | Customer Name |   Contact   |    Address    |" << endl;
            while (temp != NULL) {
                cout << "|" << "  " << temp->order_id << "  "
                    << "|" << "  " << temp->order_date << "  "
                    << "|" << "  " << temp->order_status << "  "
                    << "|" << "  " << temp->item_id << "  "
                    << "|" << "  " << temp->item_name << "  "
                    << "|" << "  " << temp->order_quantity << "  "
                    << "|" << "  " << temp->item_price << "  "
                    << "|" << "  " << temp->delivery_price << "  "
                    << "|" << "  " << temp->total_price << "  "
                    << "|" << "  " << temp->cust_id << "  "
                    << "|" << "  " << temp->cust_name << "  "
                    << "|" << "  " << temp->cust_contnum << "  "
                    << "|" << "  " << temp->cust_address << "  " << "|" << endl;
                temp = temp->next;
            }
        }
        else {
            cout << "The list is empty.\n";
        }
    }
    void show_pending() // view order list "Pending"
    {
        SalesNode* temp = head;
        if (temp != NULL) {
            cout << "********* View All Pending Records *********" << endl;
            cout << "| Order ID | Order Date | Order Status | Item ID |  Item Name  | Quantity | Price $ | Delivery $ | Total $ | Customer ID | Customer Name |   Contact   |    Address    |" << endl;
            while (temp != NULL) {
                if (temp->order_status == "Pending") {
                    cout << "|" << "  " << temp->order_id << "  "
                        << "|" << "  " << temp->order_date << "  "
                        << "|" << "  " << temp->order_status << "  "
                        << "|" << "  " << temp->item_id << "  "
                        << "|" << "  " << temp->item_name << "  "
                        << "|" << "  " << temp->order_quantity << "  "
                        << "|" << "  " << temp->item_price << "  "
                        << "|" << "  " << temp->delivery_price << "  "
                        << "|" << "  " << temp->total_price << "  "
                        << "|" << "  " << temp->cust_id << "  "
                        << "|" << "  " << temp->cust_name << "  "
                        << "|" << "  " << temp->cust_contnum << "  "
                        << "|" << "  " << temp->cust_address << "  " << "|" << endl;
                }
                temp = temp->next;
            }
        }
        else {
            cout << "The list is empty.\n";
        }
    }
    void show_notdeliver() // view order list "Not Deliver"
    {
        SalesNode* temp = head;
        if (temp != NULL) {
            cout << "********* View All Not Deliver Records *********" << endl;
            cout << "| Order ID | Order Date | Order Status | Item ID |  Item Name  | Quantity | Price $ | Delivery $ | Total $ | Customer ID | Customer Name |   Contact   |    Address    |" << endl;
            while (temp != NULL) {
                if (temp->order_status == "Not Deliver") {
                    cout << "|" << "  " << temp->order_id << "  "
                        << "|" << "  " << temp->order_date << "  "
                        << "|" << "  " << temp->order_status << "  "
                        << "|" << "  " << temp->item_id << "  "
                        << "|" << "  " << temp->item_name << "  "
                        << "|" << "  " << temp->order_quantity << "  "
                        << "|" << "  " << temp->item_price << "  "
                        << "|" << "  " << temp->delivery_price << "  "
                        << "|" << "  " << temp->total_price << "  "
                        << "|" << "  " << temp->cust_id << "  "
                        << "|" << "  " << temp->cust_name << "  "
                        << "|" << "  " << temp->cust_contnum << "  "
                        << "|" << "  " << temp->cust_address << "  " << "|" << endl;
                }
                temp = temp->next;
            }
        }
        else {
            cout << "The list is empty.\n";
        }
    }
    void show_delivered() // view order list "Deliver "
    {
        SalesNode* temp = head;
        if (temp != NULL) {
            cout << "********* View All Delivered Records *********" << endl;
            cout << "| Order ID | Order Date | Order Status | Item ID |  Item Name  | Quantity | Price $ | Delivery $ | Total $ | Customer ID | Customer Name |   Contact   |    Address    |" << endl;
            while (temp != NULL) {
                if (temp->order_status == "Delivered") {
                    cout << "|" << "  " << temp->order_id << "  "
                        << "|" << "  " << temp->order_date << "  "
                        << "|" << "  " << temp->order_status << "  "
                        << "|" << "  " << temp->item_id << "  "
                        << "|" << "  " << temp->item_name << "  "
                        << "|" << "  " << temp->order_quantity << "  "
                        << "|" << "  " << temp->item_price << "  "
                        << "|" << "  " << temp->delivery_price << "  "
                        << "|" << "  " << temp->total_price << "  "
                        << "|" << "  " << temp->cust_id << "  "
                        << "|" << "  " << temp->cust_name << "  "
                        << "|" << "  " << temp->cust_contnum << "  "
                        << "|" << "  " << temp->cust_address << "  " << "|" << endl;
                }
                temp = temp->next;
            }
        }
        else {
            cout << "The list is empty.\n";
        }
    }
    //Modify/Update Records-----------------------Modify/Update Records---------------------Modify/Update Records
    void edit_order() {
        string order_id, order_date, order_status, item_id, item_name;
        int order_quantity;
        double item_price, delivery_price, total_price;
        string cust_id, cust_name, cust_address, cust_contnum;

        string cus_id, customer_id, customer_name, customer_contact, customer_address; // Customer Node
        string itm_id, Item_id, Item_name, Item_category; double Item_price; // Item Node


        SalesNode* temp = head;
        CustomerNode* cus = head3;
        ItemNode* itm = head4;
        if (temp != NULL) {
            cout << "********* Edit Order *********" << endl;
            cout << "| Order ID | Order Date | Order Status | Item ID |  Item Name  | Quantity | Price $ | Delivery $ | Total $ | Customer ID | Customer Name |   Contact   |    Address    |" << endl;
            while (temp != NULL && cus != NULL) {
                if (temp->order_status == "Pending" || temp->order_status == "Not Deliver") {
                    cout << "|" << "  " << temp->order_id << "  "
                        << "|" << "  " << temp->order_date << "  "
                        << "|" << "  " << temp->order_status << "  "
                        << "|" << "  " << temp->item_id << "  "
                        << "|" << "  " << temp->item_name << "  "
                        << "|" << "  " << temp->order_quantity << "  "
                        << "|" << "  " << temp->item_price << "  "
                        << "|" << "  " << temp->delivery_price << "  "
                        << "|" << "  " << temp->total_price << "  "
                        << "|" << "  " << temp->cust_id << "  "
                        << "|" << "  " << temp->cust_name << "  "
                        << "|" << "  " << temp->cust_contnum << "  "
                        << "|" << "  " << temp->cust_address << "  " << "|" << endl;
                } temp = temp->next;
            }
            int choice;
            string Order_ID, Item_ID, Customer_ID, Order_Status;
            bool Flag;
            SalesNode* current = head;
            cout << "\n Enter a Order ID:" << endl;
            cin >> Order_ID;
            system("cls");
            while (current != NULL && cus != NULL) {
                if (current->order_id == Order_ID && current->order_status != "Delivered") {
                    cout << "| Order ID | Order Date | Order Status | Item ID |  Item Name  | Quantity | Price $ | Delivery $ | Total $ | Customer ID | Customer Name |   Contact   |    Address    |" << endl;
                    cout << "|" << "  " << current->order_id << "  "
                        << "|" << "  " << current->order_date << "  "
                        << "|" << "  " << current->order_status << "  "
                        << "|" << "  " << current->item_id << "  "
                        << "|" << "  " << current->item_name << "  "
                        << "|" << "  " << current->order_quantity << "  "
                        << "|" << "  " << current->item_price << "  "
                        << "|" << "  " << current->delivery_price << "  "
                        << "|" << "  " << current->total_price << "  "
                        << "|" << "  " << current->cust_id << "  "
                        << "|" << "  " << current->cust_name << "  "
                        << "|" << "  " << current->cust_contnum << "  "
                        << "|" << "  " << current->cust_address << "  " << "|" << endl;
                    cout << "  Enter The Number: " << endl;
                    cout << "  1. Edit Order Status" << endl;
                    cout << "  2. Edit Item ID" << endl;
                    cout << "  3. Edit Order Quantity" << endl;
                    cout << "  4. Edit Delivery Price" << endl;
                    cout << "  5. Edit Customer ID" << endl;
                    cout << "  6. Edit Contact Number" << endl;
                    cout << "  7. Edit Address" << endl;
                    cout << "  0. Exit to Menu Page" << endl;
                    cout << "\nEnter your Choice: ";
                    cin >> choice;
                    if (choice == 1) {
                        cout << "Note: Action is Irreversible If Status Change to 'Delivered' \n";
                        cout << "Order Status Update (Pending/Not Deliver/Delivered): \n";
                        cin.ignore();
                        getline(cin, Order_Status);
                        if (Order_Status == "Pending" || Order_Status == "Not Deliver" || Order_Status == "Delivered") {
                            current->order_status = Order_Status;
                            cout << "\nOrder Status Update Successfully\n";
                        }
                        else {
                            cout << "Invalid Order Status. Please Try Again" << endl;
                            system("pause");
                        }

                    }
                    else if (choice == 2) {
                        item_list();
                        cout << "Item ID Update (Total Price Will Auto Update): \n";
                        cin >> itm_id;
                        bool change = false;
                        while (itm != NULL) {
                            if (itm_id == itm->Item_id) {
                                current->item_id = itm->Item_id;
                                current->item_name = itm->Item_name;
                                current->item_price = itm->Item_price;
                                current->total_price = (current->order_quantity * current->item_price) + current->delivery_price;
                                change = true;
                                cout << "\nItem Data Update Successfully\n";
                            }
                            itm = itm->next;
                        }
                        if (change == false) {
                            cout << "\nUpdate Unsuccessful, Please Input Valid ID\n";
                        }
                    }
                    else if (choice == 3) {
                        do {
                            cin.ignore();
                            cout << "Order Quantity Update (Total Price Will Auto Update):\n";
                            cin >> current->order_quantity;
                            current->total_price = (current->order_quantity * current->item_price) + current->delivery_price;
                            Flag = cin.fail();
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } while (Flag == true);
                        cout << "\nOrder Quantity Update Successfully\n";
                    }
                    else if (choice == 4) {
                        do {
                            cin.ignore();
                            cout << "Delivery Price Update (Total Price Will Auto Update):\n";
                            cin >> current->delivery_price;
                            current->total_price = (current->order_quantity * current->item_price) + current->delivery_price;
                            Flag = cin.fail();
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } while (Flag == true);
                        cout << "\nDelivery Price Update Successfully\n";
                    }
                    else if (choice == 5) {
                        customer_list();
                        cout << "Enter Customer ID (enter 0 to cancel order): ";
                        cin >> cus_id;
                        bool change = false;
                        while (cus != NULL) {
                            if (cus_id == cus->customer_id) {
                                current->cust_id = cus->customer_id;
                                current->cust_name = cus->customer_name;
                                current->cust_contnum = cus->customer_contact;
                                current->cust_address = cus->customer_address;
                                change = true;
                                cout << "\nCustomer Data Update Successfully\n";
                            }
                            cus = cus->next;
                        } 
                        if (change == false) {
                            cout << "\nUpdate Unsuccessful, Please Input Valid ID\n";
                    }
                    }
                    else if (choice == 6) {
                        do {
                            cin.ignore();
                            cout << "Customer Contact Number Update:\n";
                            cin >> current->cust_contnum;
                            Flag = cin.fail();
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } while (Flag == true);
                        cout << "\nCustomer Contact Number Update Successfully\n";
                    }
                    else if (choice == 7) {
                        cout << "Customer Address Update: \n";
                        cin.ignore();
                        cin >> current->cust_address;
                        cout << "\nCustomer Address Update Successfully\n";
                    }
                    else if (choice == 0) {
                        system("pause");
                        system("cls");
                    }
                    else {
                        cout << "\nSomething Went Wrong, Please Try Again\n";
                    }
                    break;
                }
                current = current->next;
            }
        } // End Edit Order
        else {
            cout << "The list is empty.\n";
        }
    }
    //Search Records----------------------------------Search Records-------------------------------Search Records
    void search_order() {
        string order_id, order_date, order_status, item_id, item_name;
        int order_quantity;
        double item_price, delivery_price, total_price;
        string cust_id, cust_name, cust_contnum, cust_address;

        int choice;

        string Search;
        int Num;
        view_order_list();
        cout << "\n Search Area: Order ID / Order Date / Order Status / Item Name / Customer ID / Customer Name / Contact Number / Customer Address" << endl;
        cout << "\n Search:" << endl;
        cin >> Search;


        SalesNode* current = head;
        if (current != NULL) {
            cout << "********* Seach Order *********" << endl;
            cout << "| Order ID | Order Date | Order Status | Item ID |  Item Name  | Quantity | Price $ | Delivery $ | Total $ | Customer ID | Customer Name |   Contact   |    Address    |" << endl;
            while (current != NULL) {
                if (current->order_id == Search || current->order_date == Search || current->order_status == Search ||
                    current->item_name == Search ||
                    current->cust_id == Search || current->cust_name == Search || current->cust_contnum == Search || current->cust_address == Search) {
                    cout << "|" << "  " << current->order_id << "  "
                        << "|" << "  " << current->order_date << "  "
                        << "|" << "  " << current->order_status << "  "
                        << "|" << "  " << current->item_id << "  "
                        << "|" << "  " << current->item_name << "  "
                        << "|" << "  " << current->order_quantity << "  "
                        << "|" << "  " << current->item_price << "  "
                        << "|" << "  " << current->delivery_price << "  "
                        << "|" << "  " << current->total_price << "  "
                        << "|" << "  " << current->cust_id << "  "
                        << "|" << "  " << current->cust_name << "  "
                        << "|" << "  " << current->cust_contnum << "  "
                        << "|" << "  " << current->cust_address << "  " << "|" << endl;
                }
                current = current->next;
            }
        }
        else {
            cout << "The list is empty.\n";
        }


    }
    //Sort Records-------------------------------------Sort Records----------------------------------Sort Records
    void sort_orderid_asc() {
        SalesNode* current = head, * index = NULL;
        int itemp;
        double dtemp;
        string stemp;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->order_id > index->order_id) {
                        stemp = current->order_id;
                        current->order_id = index->order_id;
                        index->order_id = stemp;

                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        stemp = current->order_status;
                        current->order_status = index->order_status;
                        index->order_status = stemp;

                        stemp = current->item_id;
                        current->item_id = index->item_id;
                        index->item_id = stemp;

                        stemp = current->item_name;
                        current->item_name = index->item_name;
                        index->item_name = stemp;

                        itemp = current->order_quantity;
                        current->order_quantity = index->order_quantity;
                        index->order_quantity = itemp;

                        dtemp = current->item_price;
                        current->item_price = index->item_price;
                        index->item_price = dtemp;

                        dtemp = current->delivery_price;
                        current->delivery_price = index->delivery_price;
                        index->delivery_price = dtemp;

                        dtemp = current->total_price;
                        current->total_price = index->total_price;
                        index->total_price = dtemp;

                        stemp = current->cust_id;
                        current->cust_id = index->cust_id;
                        index->cust_id = stemp;

                        stemp = current->cust_name;
                        current->cust_name = index->cust_name;
                        index->cust_name = stemp;

                        stemp = current->cust_contnum;
                        current->cust_contnum = index->cust_contnum;
                        index->cust_contnum = stemp;

                        stemp = current->cust_address;
                        current->cust_address = index->cust_address;
                        index->cust_address = stemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        view_order_list();
    }
    void sort_orderid_dsc() {
        SalesNode* current = head, * index = NULL;
        int itemp;
        double dtemp;
        string stemp;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->order_id < index->order_id) {
                        stemp = current->order_id;
                        current->order_id = index->order_id;
                        index->order_id = stemp;

                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        stemp = current->order_status;
                        current->order_status = index->order_status;
                        index->order_status = stemp;

                        stemp = current->item_id;
                        current->item_id = index->item_id;
                        index->item_id = stemp;

                        stemp = current->item_name;
                        current->item_name = index->item_name;
                        index->item_name = stemp;

                        itemp = current->order_quantity;
                        current->order_quantity = index->order_quantity;
                        index->order_quantity = itemp;

                        dtemp = current->item_price;
                        current->item_price = index->item_price;
                        index->item_price = dtemp;

                        dtemp = current->delivery_price;
                        current->delivery_price = index->delivery_price;
                        index->delivery_price = dtemp;

                        dtemp = current->total_price;
                        current->total_price = index->total_price;
                        index->total_price = dtemp;

                        stemp = current->cust_id;
                        current->cust_id = index->cust_id;
                        index->cust_id = stemp;

                        stemp = current->cust_name;
                        current->cust_name = index->cust_name;
                        index->cust_name = stemp;

                        stemp = current->cust_contnum;
                        current->cust_contnum = index->cust_contnum;
                        index->cust_contnum = stemp;

                        stemp = current->cust_address;
                        current->cust_address = index->cust_address;
                        index->cust_address = stemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        view_order_list();
    }
    void sort_totalprice_highlow() {
        SalesNode* current = head, * index = NULL;
        int itemp;
        double dtemp;
        string stemp;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->total_price < index->total_price) {
                        stemp = current->order_id;
                        current->order_id = index->order_id;
                        index->order_id = stemp;

                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        stemp = current->order_status;
                        current->order_status = index->order_status;
                        index->order_status = stemp;

                        stemp = current->item_id;
                        current->item_id = index->item_id;
                        index->item_id = stemp;

                        stemp = current->item_name;
                        current->item_name = index->item_name;
                        index->item_name = stemp;

                        itemp = current->order_quantity;
                        current->order_quantity = index->order_quantity;
                        index->order_quantity = itemp;

                        dtemp = current->item_price;
                        current->item_price = index->item_price;
                        index->item_price = dtemp;

                        dtemp = current->delivery_price;
                        current->delivery_price = index->delivery_price;
                        index->delivery_price = dtemp;

                        dtemp = current->total_price;
                        current->total_price = index->total_price;
                        index->total_price = dtemp;

                        stemp = current->cust_id;
                        current->cust_id = index->cust_id;
                        index->cust_id = stemp;

                        stemp = current->cust_name;
                        current->cust_name = index->cust_name;
                        index->cust_name = stemp;

                        stemp = current->cust_contnum;
                        current->cust_contnum = index->cust_contnum;
                        index->cust_contnum = stemp;

                        stemp = current->cust_address;
                        current->cust_address = index->cust_address;
                        index->cust_address = stemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        show_pending();
        system("pause");
        system("cls");
        show_notdeliver();
    }
    void sort_totalprice_lowhigh() {
        SalesNode* current = head, * index = NULL;
        int itemp;
        double dtemp;
        string stemp;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->total_price > index->total_price) {
                        stemp = current->order_id;
                        current->order_id = index->order_id;
                        index->order_id = stemp;

                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        stemp = current->order_status;
                        current->order_status = index->order_status;
                        index->order_status = stemp;

                        stemp = current->item_id;
                        current->item_id = index->item_id;
                        index->item_id = stemp;

                        stemp = current->item_name;
                        current->item_name = index->item_name;
                        index->item_name = stemp;

                        itemp = current->order_quantity;
                        current->order_quantity = index->order_quantity;
                        index->order_quantity = itemp;

                        dtemp = current->item_price;
                        current->item_price = index->item_price;
                        index->item_price = dtemp;

                        dtemp = current->delivery_price;
                        current->delivery_price = index->delivery_price;
                        index->delivery_price = dtemp;

                        dtemp = current->total_price;
                        current->total_price = index->total_price;
                        index->total_price = dtemp;

                        stemp = current->cust_id;
                        current->cust_id = index->cust_id;
                        index->cust_id = stemp;

                        stemp = current->cust_name;
                        current->cust_name = index->cust_name;
                        index->cust_name = stemp;

                        stemp = current->cust_contnum;
                        current->cust_contnum = index->cust_contnum;
                        index->cust_contnum = stemp;

                        stemp = current->cust_address;
                        current->cust_address = index->cust_address;
                        index->cust_address = stemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        show_pending();
        system("pause");
        system("cls");
        show_notdeliver();
    }
    void sort_orderquantity_highlow() {
        SalesNode* current = head, * index = NULL;
        int itemp;
        double dtemp;
        string stemp;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->order_quantity < index->order_quantity) {
                        stemp = current->order_id;
                        current->order_id = index->order_id;
                        index->order_id = stemp;

                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        stemp = current->order_status;
                        current->order_status = index->order_status;
                        index->order_status = stemp;

                        stemp = current->item_id;
                        current->item_id = index->item_id;
                        index->item_id = stemp;

                        stemp = current->item_name;
                        current->item_name = index->item_name;
                        index->item_name = stemp;

                        itemp = current->order_quantity;
                        current->order_quantity = index->order_quantity;
                        index->order_quantity = itemp;

                        dtemp = current->item_price;
                        current->item_price = index->item_price;
                        index->item_price = dtemp;

                        dtemp = current->delivery_price;
                        current->delivery_price = index->delivery_price;
                        index->delivery_price = dtemp;

                        dtemp = current->total_price;
                        current->total_price = index->total_price;
                        index->total_price = dtemp;

                        stemp = current->cust_id;
                        current->cust_id = index->cust_id;
                        index->cust_id = stemp;

                        stemp = current->cust_name;
                        current->cust_name = index->cust_name;
                        index->cust_name = stemp;

                        stemp = current->cust_contnum;
                        current->cust_contnum = index->cust_contnum;
                        index->cust_contnum = stemp;

                        stemp = current->cust_address;
                        current->cust_address = index->cust_address;
                        index->cust_address = stemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        show_pending();
        system("pause");
        system("cls");
        show_notdeliver();
    }
    void sort_orderquantity_lowhigh() {
        SalesNode* current = head, * index = NULL;
        int itemp;
        double dtemp;
        string stemp;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->order_quantity > index->order_quantity) {
                        stemp = current->order_id;
                        current->order_id = index->order_id;
                        index->order_id = stemp;

                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        stemp = current->order_status;
                        current->order_status = index->order_status;
                        index->order_status = stemp;

                        stemp = current->item_id;
                        current->item_id = index->item_id;
                        index->item_id = stemp;

                        stemp = current->item_name;
                        current->item_name = index->item_name;
                        index->item_name = stemp;

                        itemp = current->order_quantity;
                        current->order_quantity = index->order_quantity;
                        index->order_quantity = itemp;

                        dtemp = current->item_price;
                        current->item_price = index->item_price;
                        index->item_price = dtemp;

                        dtemp = current->delivery_price;
                        current->delivery_price = index->delivery_price;
                        index->delivery_price = dtemp;

                        dtemp = current->total_price;
                        current->total_price = index->total_price;
                        index->total_price = dtemp;

                        stemp = current->cust_id;
                        current->cust_id = index->cust_id;
                        index->cust_id = stemp;

                        stemp = current->cust_name;
                        current->cust_name = index->cust_name;
                        index->cust_name = stemp;

                        stemp = current->cust_contnum;
                        current->cust_contnum = index->cust_contnum;
                        index->cust_contnum = stemp;

                        stemp = current->cust_address;
                        current->cust_address = index->cust_address;
                        index->cust_address = stemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        show_pending();
        system("pause");
        system("cls");
        show_notdeliver();
    }
    //Delete Records----------------------------------Delete Records-------------------------------Delete Records
    void delete_order(string order_id) {
        //Check if the list is empty
        if (head != NULL) {
            SalesNode* current = head;
            if (head->order_id == order_id) { //check the node to delete is first node
                head = head->next;
                delete current;
            }
            else { // check the node to delete is not in first node
                SalesNode* prev = NULL;
                while (current != NULL && current->order_id != order_id) {
                    prev = current;
                    current = current->next;
                }
                //check if get the result
                if (current != NULL) {
                    //get the result and delete it
                    prev->next = current->next;
                    delete current;
                }
            }
        }
    }
    //Item Records-------------------------------------Item Records----------------------------------Item Records
    void item_list() {
        ItemNode* itm = head4;
        if (itm != NULL) {
            cout << "********* Item List *********" << endl;
            cout << "| Item ID | Item Name | Item Category | Item Price |" << endl;
            while (itm != NULL) {
                cout << "|" << "  " << itm->Item_id << "  "
                    << "|" << "  " << itm->Item_name << "  "
                    << "|" << "  " << itm->Item_category << "  "
                    << "|" << "  " << itm->Item_price << "  " << "|" << endl;
                itm = itm->next;
            }
        }
        else {
            cout << "The item list is empty.\n";
        }
    }
    //Customer Records-------------------------------Customer Records----------------------------Customer Records
    void customer_list() {
        CustomerNode* cus = head3;
        if (cus != NULL) {
            cout << "********* Customer List *********" << endl;
            cout << "| Customer ID | Customer Name | Contact Number | Address |"<< endl;
            while (cus != NULL) {
                cout << "|" << "  " << cus->customer_id << "  "
                    << "|" << "  " << cus->customer_name << "  "
                    << "|" << "  " << cus->customer_contact << "  "
                    << "|" << "  " << cus->customer_address << "  " << "|" << endl;
                cus = cus ->next;
            }
        }
        else {
            cout << "The customer list is empty.\n";
        }
    }



    //Generate Reports-------------------------------Generate Reports----------------------------Generate Reports
    //admin features
    //duplicate the date data in head to the head2
    //to avoid any changes that will affected the data in head
    void copyList() {
        SalesNode* current = head;
        SalesNode* data = new SalesNode;
        SalesNode* temp = head2;
        data->next = NULL;
        if (current == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                data->order_date = current->order_date;
                add(data->order_date, 0, 0);
                current = current->next;
            }
        }

    }
    //add data into rhead
    void add(string orderDate, int iSold, double sTotal) {
        SalesNode* temp = new SalesNode;
        temp->order_date = orderDate;
        temp->iSold = iSold;
        temp->sTotal = sTotal;
        temp->next = head2;
        head2 = temp;
    }
    //remove the duplicate date data
    void removeDuplicate() {
        SalesNode* current = head2;
        SalesNode* index = NULL, * temp = NULL;
        //pick nodes one by one
        while (current != NULL && current->next != NULL) {
            index = current;
            //compare the picked node with the rest nodes
            while (index->next != NULL) {
                //if duplicate then delete it
                if (current->order_date == index->next->order_date) {
                    temp = index->next;
                    index->next = index->next->next;
                    delete (temp);
                }
                else
                    index = index->next;
            }
            current = current->next;
        }

    }
    //calculate the total item sold and sales total based on the date
    //save the total item sold per day into iSold
    //save the sales total per day into sTotal
    void generateReport() {
        SalesNode* current = head;
        SalesNode* temp = head2;
        SalesNode* index = NULL;
        string stemp;
        int iSold = 0;
        double sTotal = 0;

        if (temp != NULL) {
            while (temp != NULL) {
                while (current != NULL) {
                    if (temp->order_date == current->order_date) {

                        stemp = temp->order_date;
                        temp->order_date = stemp;

                        iSold = iSold + current->order_quantity;
                        temp->iSold = iSold;

                        sTotal = sTotal + current->total_price;
                        temp->sTotal = sTotal;
                    }
                    current = current->next;
                }
                temp = temp->next;
                current = head;
                iSold = 0;
                sTotal = 0;
            }

            cout << "Report Generated Successfully!" << endl;
        }
        else {
            cout << " No list is empty. " << endl;
        }
    }
    void viewReport() {
        SalesNode* temp = head2;
        if (temp != NULL) {
            cout << "-----------------Order List---------------" << endl;
            cout << "| Order Date | Items Sold | Sales Total |" << endl;

            while (temp != NULL) {
                cout << "|" << setw(10) << temp->order_date << setw(3)
                    << "|" << setw(7) << temp->iSold << setw(6)
                    << "|" << setw(8) << temp->sTotal << setw(6) << "|" << endl;
                temp = temp->next;

            }
            cout << "------------------------------------------" << endl;

        }
        else {
            cout << "The report is empty" << endl;
        }

    }
    void sortiSold_Asc() {
        SalesNode* current = head2, * index = NULL;
        int temp;
        double dtemp;
        string stemp;
        if (current == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->iSold > index->iSold) {
                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        temp = current->iSold;
                        current->iSold = index->iSold;
                        index->iSold = temp;

                        dtemp = current->sTotal;
                        current->sTotal = index->sTotal;
                        index->sTotal = dtemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        viewReport();
    }
    void sortiSold_Dec() {
        SalesNode* current = head2, * index = NULL;
        int temp;
        double dtemp;
        string stemp;
        if (current == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->iSold < index->iSold) {
                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        temp = current->iSold;
                        current->iSold = index->iSold;
                        index->iSold = temp;

                        dtemp = current->sTotal;
                        current->sTotal = index->sTotal;
                        index->sTotal = dtemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        viewReport();
    }
    void sortsTotal_Asc() {
        SalesNode* current = head2, * index = NULL;
        int temp;
        double dtemp;
        string stemp;
        if (current == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->sTotal > index->sTotal) {
                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        temp = current->iSold;
                        current->iSold = index->iSold;
                        index->iSold = temp;

                        dtemp = current->sTotal;
                        current->sTotal = index->sTotal;
                        index->sTotal = dtemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        viewReport();
    }
    void sortsTotal_Dec() {
        SalesNode* current = head2, * index = NULL;
        int temp;
        double dtemp;
        string stemp;
        if (current == NULL) {
            return;
        }
        else {
            while (current != NULL) {
                index = current->next;
                while (index != NULL) {
                    if (current->sTotal < index->sTotal) {
                        stemp = current->order_date;
                        current->order_date = index->order_date;
                        index->order_date = stemp;

                        temp = current->iSold;
                        current->iSold = index->iSold;
                        index->iSold = temp;

                        dtemp = current->sTotal;
                        current->sTotal = index->sTotal;
                        index->sTotal = dtemp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        viewReport();
    }
};


//-------------------------------------------------------------------------------------------------------
//CONSOLE INTERFACE-------------------------CONSOLE INTERFACE---------------------------CONSOLE INTERFACE
//-------------------------------------------------------------------------------------------------------

int main() {
    int LogOpt, choice, logout;
    char ch, password[32];
    string name, pw, sales, spw, admin, apw;
    SalesLinkedList list;
    sales = "sales";
    spw = "sales";
    admin = "admin";
    apw = "admin";


    string order_id, order_date, order_status, item_id, item_name;
    int order_quantity;
    double item_price, delivery_price, total_price;
    string cust_id, cust_name, cust_contnum, cust_address;


    list.receive_order_data("01", "11/07/2022", "Delivered", "GE006", "Dumbbell 5KG", 2, 50.00, 2.00, 52.00, "C01", "Paine", "019-8765432", "Bukit Jalil");
    list.receive_order_data("02", "11/07/2022", "Delivered", "GE008", "Dumbbell 10KG", 1, 80.00, 2.00, 82.00, "C02", "Torune", "012-3456789", "Seri Kembangan");
    list.receive_order_data("03", "11/07/2022", "Delivered", "GE007", "Dumbbell 7KG", 1, 60.00, 2.00, 62.00, "C03", "Neffe", "012-3456789", "KL");
    list.receive_order_data("04", "25/07/2022", "Not Deliver", "S003", "Blitzball", 1, 15.00, 1.00, 16.00, "C02", "Torune", "012-3456789", "Seri Kembangan");
    list.receive_order_data("05", "25/07/2022", "Not Deliver", "FP001", "Heady Perfume", 5, 22.00, 1.00, 111.00, "C06", "Yuyui", "019-8765432", "Bukit Jalil");
    list.receive_order_data("06", "25/07/2022", "Not Deliver", "FP001", "Heady Perfume", 2, 22.00, 1.00, 45.00, "C05", "Lucil", "019-8765432", "Bukit Jalil");
    list.receive_order_data("07", "25/07/2022", "Not Deliver", "S003", "Blitzball", 2, 15.00, 1.00, 31.00, "C04", "Cahhan", "012-3456789", "KL");
    list.receive_order_data("08", "25/07/2022", "Pending", "FP001", "Heady Perfume", 3, 22.00, 1.00, 67.00, "C01", "Paine", "019-8765432", "Bukit Jalil");
    list.receive_order_data("09", "25/07/2022", "Pending", "B008", "Black Grimore", 1, 10.00, 1.00, 11.00, "C02", "Torune", "012-3456789", "Seri Kembangan");
    list.receive_order_data("10", "25/07/2022", "Pending", "FP002", "Tobacco Oud", 3, 33.00, 1.00, 100.00, "C03", "Neffe", "012-3456789", "KL");
    
    
    
    list.receive_customer_data("C01", "Paine", "019-8765432", "Bukit Jalil");
    list.receive_customer_data("C02", "Torune", "012-3456789", "Seri Kembangan");
    list.receive_customer_data("C03", "Neffe", "012-3456789", "KL");
    list.receive_customer_data("C04", "Cahhan", "012-3456789", "KL");
    list.receive_customer_data("C05", "Lucil", "019-8765432", "Bukit Jalil");
    list.receive_customer_data("C06", "Yuyui", "019-8765432", "Bukit Jalil");
    list.receive_customer_data("C07", "Shino", "012-3456789", "Bukit Jalil");
    list.receive_customer_data("C08", "Nedus", "012-3456789", "KL");
    list.receive_customer_data("C09", "Bayra", "012-3456789", "Seri Kembangan");
    list.receive_customer_data("C10", "Kaori", "019-8765432", "Seri Kembangan");



    list.receive_item_data("FP001","Heady Perfume","Fragrance & Perfume", 22.00);
    list.receive_item_data("FP002","Tobacco Oud", "Fragrance & Perfume", 33.00);
    list.receive_item_data("S003", "Blitzball", "Sports", 15.00);
    list.receive_item_data("S004", "Badminton Set", "Sports", 15.00);
    list.receive_item_data("GE005", "Dumbbell 5KG", "Gym Equipment", 50.00);
    list.receive_item_data("GE006", "Dumbbell 7KG", "Gym Equipment", 60.00);
    list.receive_item_data("GE007", "Dumbbell 10KG", "Gym Equipment", 80.00);
    list.receive_item_data("B008", "Black Grimore", "Books", 10.00);
    list.receive_item_data("B009", "Chant Of Light", "Books", 10.00);
    list.receive_item_data("B010", "Alfred Tennyson", "Books", 10.00);
    system("cls");

    //Login Page--------------------------------------Login Page-------------------------------------Login Page
login:
    cout << "Welcome to LiveOrder Sdn Bhd" << endl;
    cout << "   Purchase Order System    " << endl;
    cout << "********* Login Page *********" << endl;
    cout << "Enter username: ";
    cin >> name;
    cout << "Enter password: ";
    for (int i = 0;;) {
        ch = _getch(); //stores char typed in ch
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            //check if character input is numeric or alpabet
            password[i] = ch; //stores character in password
            ++i;
            cout << "*";
        }
        if (ch == '\b' && i >= 1) { //backspace
            cout << "\b \b"; //erase the character behind the cursor
            --i;
        }
        if (ch == '\r') {
            password[i] = '\0'; //null = end of string
            break;
        }
    }
    if (name == sales && password == spw) {
        cout << "\nLogin Successful! " << endl;
        system("pause");
        system("cls");
        goto sales;
    }
    else if (name == admin && password == apw) {
        cout << "\nLogin Successful! " << endl;
        system("pause");
        system("cls");
        goto admin;
    }
    else {
        cout << "\nInvalid username or password" << endl;
        system("pause");
        system("cls");
        goto login;
    }


    //Sales Interface--------------------------------Sales Interface------------------------------Sales Interface
sales:
    while (true) {
        system("cls");
        cout << "\t              LiveOrder Sdn Bhd" << endl;
        cout << "\t     Purchase Order(PO) Management System" << endl;
        cout << "****************** Sales Interface ******************" << endl;
        cout << "  Enter The Number: " << endl;
        cout << "  1. View Order List" << endl;
        cout << "  2. Add New Order" << endl;
        cout << "  3. Edit Order" << endl;
        cout << "  4. Delete Order" << endl;
        cout << "  5. Sort Order List" << endl;
        cout << "  9. Logout" << endl;
        cout << "  0. Exit" << endl;
        cout << "*****************************************************" << endl;
        cout << "\nEnter your Choice: ";
        cin >> choice;

        //CHOICE 1-----------------------------------CHOICE 1-------------------------------------CHOICE 1 (View Order List)
        if (choice == 1) {
            system("cls");
            cout << "*******************View Order List*******************" << endl;
            cout << "  Enter The Number: " << endl;
            cout << "  1. Display All Order" << endl;
            cout << "  2. Display Order (Pending)" << endl;
            cout << "  3. Display Order (Not Delivered)" << endl;
            cout << "  4. Display Order (Delivered)" << endl;
            cout << "  5. Search Order" << endl;
            cout << "  0. Exit to Menu Page" << endl;
            cout << "*****************************************************" << endl;
            cout << "\nEnter your Choice: ";
            cin >> choice;
            if (choice == 1) {
                system("cls");
                list.view_order_list();
                system("pause");
            }
            else if (choice == 2) {
                system("cls");
                list.show_pending();
                system("pause");
            }
            else if (choice == 3) {
                system("cls");
                list.show_notdeliver();
                system("pause");
            }
            else if (choice == 4) {
                system("cls");
                list.show_delivered();
                system("pause");
            }
            else if (choice == 5) {
                system("cls");
                list.search_order();
                system("pause");
            }
            else if (choice == 0) {
                system("cls");
            }
        }
        //CHOICE 2-----------------------------------CHOICE 2-------------------------------------CHOICE 2 (Add Order)
        else if (choice == 2) {
            system("cls");
            list.add_order();
            system("pause");
        }
        //CHOICE 3-----------------------------------CHOICE 3-------------------------------------CHOICE 3 (Edit Order)
        else if (choice == 3) {
            system("cls");
            list.edit_order();
            system("pause");
        }
        //CHOICE 4-----------------------------------CHOICE 4-------------------------------------CHOICE 4 (Delete Order)
        else if (choice == 4) {
            system("cls");
            list.view_order_list();
            cout << "Enter Order ID to Delete Order: ";
            cin >> order_id;
            list.delete_order(order_id);
            cout << "Delete Successful" << endl;
            system("pause");
            system("cls");
            list.view_order_list();
            system("pause");
            system("cls");
        }
        //CHOICE 5-----------------------------------CHOICE 5-------------------------------------CHOICE 5 (Sort Order List)
        else if (choice == 5) {
            system("cls");
            cout << "*******************Sort Order List*******************" << endl;
            cout << "  Enter The Number: " << endl;
            cout << "  1. Sort Order (Oldest to Newest)" << endl;
            cout << "  2. Sort Order (Newest to Oldest)" << endl;
            cout << "  3. Sort Order (High Total Price to Low Total Price - Pending and Not Deliver Only)" << endl;
            cout << "  4. Sort Order (Low Total Price to High Total Price - Pending and Not Deliver Only)" << endl;
            cout << "  5. Sort Order (High Order Quantity to Low Order Quantity - Pending and Not Deliver Only)" << endl;
            cout << "  6. Sort Order (Low Order Quantity to High Order Quantity - Pending and Not Deliver Only)" << endl;
            cout << "  0. Exit to Menu Page" << endl;
            cout << "*****************************************************" << endl;
            cout << "\nEnter your Choice: ";
            cin >> choice;
            if (choice == 1) {
                system("cls");
                list.sort_orderid_asc();
                system("pause");
            }
            else if (choice == 2) {
                system("cls");
                list.sort_orderid_dsc();
                system("pause");
            }
            else if (choice == 3) {
                system("cls");
                list.sort_totalprice_highlow();
                system("pause");
            }
            else if (choice == 4) {
                system("cls");
                list.sort_totalprice_lowhigh();
                system("pause");
            }
            else if (choice == 5) {
                system("cls");
                list.sort_orderquantity_highlow();
                system("pause");
            }
            else if (choice == 6) {
                system("cls");
                list.sort_orderquantity_lowhigh();
                system("pause");
            }
            else if (choice == 0) {
                system("cls");
            }

        }
        //CHOICE 9-----------------------------------CHOICE 9-------------------------------------CHOICE 9
        else if (choice == 9) {
            while (true) {
                system("cls");
                cout << "Are you sure you want to Logout?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "\nEnter your Choice: " << endl;
                cin >> logout;
                if (logout == 1) {
                    cout << "Logout Successful! Returning to Login Page." << endl;
                    system("pause");
                    system("cls");
                    goto login;
                }
                else if (logout == 2) {
                    cout << "Logout Terminated! Returning to Sales Interface." << endl;
                    system("pause");
                    system("cls");
                    goto sales;
                }
                else {
                    cout << "Invalid Input! Returning to Sales Interface." << endl;
                    system("pause");
                    system("cls");
                    goto sales;
                }
            }
        }
        //CHOICE 0-----------------------------------CHOICE 0-------------------------------------CHOICE 0
        else if (choice == 0) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                << "Try Again\n";
        }
    }







    // Admin Interface--------------------------------Admin Interface------------------------------Admin Interface
admin:
    while (true) {
        system("cls");
        cout << "\t              LiveOrder Sdn Bhd" << endl;
        cout << "\t     Purchase Order(PO) Management System" << endl;
        cout << "****************** Admin Interface ******************" << endl;
        cout << "  Enter The Number: " << endl;
        cout << "  1. View Order List" << endl;
        cout << "  2. Add New Order" << endl;
        cout << "  3. Edit Order" << endl;
        cout << "  4. Delete Order" << endl;
        cout << "  5. Sort Order List" << endl;
        cout << "  6. Generate Reports" << endl;
        cout << "  7. View Reports" << endl;
        cout << "  9. Logout" << endl;
        cout << "  0. Exit" << endl;
        cout << "*****************************************************" << endl;
        cout << "\nEnter your Choice: ";
        cin >> choice;

        //CHOICE 1-----------------------------------CHOICE 1-------------------------------------CHOICE 1 (View Order List)
        if (choice == 1) {
            system("cls");
            cout << "*******************View Order List*******************" << endl;
            cout << "  Enter The Number: " << endl;
            cout << "  1. Display All Order" << endl;
            cout << "  2. Display Order (Pending)" << endl;
            cout << "  3. Display Order (Not Delivered)" << endl;
            cout << "  4. Display Order (Delivered)" << endl;
            cout << "  5. Search Order" << endl;
            cout << "  0. Exit to Menu Page" << endl;
            cout << "*****************************************************" << endl;
            cout << "\nEnter your Choice: ";
            cin >> choice;
            if (choice == 1) {
                system("cls");
                list.view_order_list();
                system("pause");
            }
            else if (choice == 2) {
                system("cls");
                list.show_pending();
                system("pause");
            }
            else if (choice == 3) {
                system("cls");
                list.show_notdeliver();
                system("pause");
            }
            else if (choice == 4) {
                system("cls");
                list.show_delivered();
                system("pause");
            }
            else if (choice == 5) {
                system("cls");
                list.search_order();
                system("pause");
            }
            else if (choice == 0) {
                system("cls");
            }
        }
        //CHOICE 2-----------------------------------CHOICE 2-------------------------------------CHOICE 2 (Add Order)
        else if (choice == 2) {
            system("cls");
            list.add_order();
            system("pause");
        }
        //CHOICE 3-----------------------------------CHOICE 3-------------------------------------CHOICE 3 (Edit Order)
        else if (choice == 3) {
            system("cls");
            list.edit_order();
            system("pause");
        }
        //CHOICE 4-----------------------------------CHOICE 4-------------------------------------CHOICE 4 (Delete Order)
        else if (choice == 4) {
            system("cls");
            list.view_order_list();
            cout << "Enter Order ID to Delete Order: ";
            cin >> order_id;
            list.delete_order(order_id);
            cout << "Delete Successful" << endl;
            system("pause");
            system("cls");
            list.view_order_list();
            system("pause");
            system("cls");
        }
        //CHOICE 5-----------------------------------CHOICE 5-------------------------------------CHOICE 5 (Sort Order List)
        else if (choice == 5) {
            system("cls");
            cout << "*******************Sort Order List*******************" << endl;
            cout << "  Enter The Number: " << endl;
            cout << "  1. Sort Order (Oldest to Newest)" << endl;
            cout << "  2. Sort Order (Newest to Oldest)" << endl;
            cout << "  3. Sort Order (High Total Price to Low Total Price - Pending and Not Deliver Only)" << endl;
            cout << "  4. Sort Order (Low Total Price to High Total Price - Pending and Not Deliver Only)" << endl;
            cout << "  5. Sort Order (High Order Quantity to Low Order Quantity - Pending and Not Deliver Only)" << endl;
            cout << "  6. Sort Order (Low Order Quantity to High Order Quantity - Pending and Not Deliver Only)" << endl;
            cout << "  0. Exit to Menu Page" << endl;
            cout << "*****************************************************" << endl;
            cout << "\nEnter your Choice: ";
            cin >> choice;
            if (choice == 1) {
                system("cls");
                list.sort_orderid_asc();
                system("pause");
            }
            else if (choice == 2) {
                system("cls");
                list.sort_orderid_dsc();
                system("pause");
            }
            else if (choice == 3) {
                system("cls");
                list.sort_totalprice_highlow();
                system("pause");
            }
            else if (choice == 4) {
                system("cls");
                list.sort_totalprice_lowhigh();
                system("pause");
            }
            else if (choice == 5) {
                system("cls");
                list.sort_orderquantity_highlow();
                system("pause");
            }
            else if (choice == 6) {
                system("cls");
                list.sort_orderquantity_lowhigh();
                system("pause");
            }
            else if (choice == 0) {
                system("cls");
            }

        }
        //CHOICE 6-----------------------------------CHOICE 6-------------------------------------CHOICE 6
        else if (choice == 6) {
            system("cls");
            list.copyList();
            list.removeDuplicate();
            list.generateReport();
            list.viewReport();
            system("pause");
        }
        //CHOICE 7-----------------------------------CHOICE 7-------------------------------------CHOICE 7
        else if (choice == 7) {
        system("cls");
        cout << "*********************View Report**********************" << endl;
        cout << "  Enter The Number: " << endl;
        cout << "  1. View All Report" << endl;
        cout << "  2. Sort report by item solds (Ascending)" << endl;
        cout << "  3. Sort report by item solds (Descending)" << endl;
        cout << "  4. Sort report by sales total (Ascending)" << endl;
        cout << "  5. Sort report by sales total (Descending)" << endl;
        cout << "  0. Exit to Menu Page" << endl;
        cout << "*****************************************************" << endl;
        cout << "\nEnter your Choice: ";
        cin >> choice;
        if (choice == 1) {
            system("cls");
            list.viewReport();
            system("pause");
        }
        else if (choice == 2) {
            system("cls");
            list.sortiSold_Asc();
            system("pause");
        }
        else if (choice == 3) {
            system("cls");
            list.sortiSold_Dec();
            system("pause");
        }
        else if (choice == 4) {
            system("cls");
            list.sortsTotal_Asc();
            system("pause");
        }
        else if (choice == 5) {
            system("cls");
            list.sortsTotal_Dec();
            system("pause");
        }
        else if (choice == 0) {
            system("cls");
        }
        }
        //CHOICE 9-----------------------------------CHOICE 9-------------------------------------CHOICE 9
        else if (choice == 9) {
            while (true) {
                system("cls");
                cout << "Are you sure you want to Logout?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "\nEnter your Choice: " << endl;
                cin >> logout;
                if (logout == 1) {
                    cout << "Logout Successful! Returning to Login Page." << endl;
                    system("pause");
                    system("cls");
                    goto login;
                }
                else if (logout == 2) {
                    cout << "Logout Terminated! Returning to Admin Interface." << endl;
                    system("pause");
                    system("cls");
                    goto admin;
                }
                else {
                    cout << "Invalid input! Returning to Admin Interface." << endl;
                    system("pause");
                    system("cls");
                    goto admin;
                }
            }
        }
        //CHOICE 0-----------------------------------CHOICE 0-------------------------------------CHOICE 0
        else if (choice == 0) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                << "Try Again\n";
        }
    }
}
