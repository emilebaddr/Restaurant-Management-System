#include <iostream>
#include <iomanip>
using namespace std;
void Add(string*& add, int& k, int*& itemid, double *&price) {
    cout << "add menu section (type -2 to go back)\n";
    string input;
    while (true) {
        cin >> input;
        if (input == "-2")
            break;
        *(add + k) = input;
        *(itemid + k) = k;
        price[k] = 0;
        cout << input << " got assigned itemid:" << k<<endl;
        k++;
    }

}
void prices(int* itemid, double*& price, int k) {
    while (true) {
        int input;
        cout << "enter item id (press -2 to exit): ";
        cin >> input;

        if (input == -2)
            break;
        if (input < 0 || input >= k) {
            cout << "invalid, try again\n";
            continue;
        }
        cout << "type the price of this item: $";
        cin >> price[input];
    }
}
void availibility(int* itemid, bool*& available, int k) {
    int input;
    char yep;
    cout << "enter item id(press -2 to exit): ";
    while (true) {
        cin >> input;
        if (input == -2)
            break;
        if (input < 0 || input >= k) {
            cout << "invalid, try again\n";
            continue;
        }
        cout << "make it available (y/n)\n";
        cin >> yep;
        if (yep == 'y')
            *(available + input) = true;
        else if (yep == 'n')
            *(available + input) = false;
        else
            cout << "invalid\n";
    }
}
void removeitem(string*& menu, int*& itemid, double*& price, bool*& available, int& k) {
    int input;
    while (true) {
        cout << "which one do you want to remove by item id?(press -2 to exit): ";
        cin >> input;
        if (input == -2)
            break;
        if (input < 0 || input >= k) {
            cout << "invalid, try again\n";
            continue;
        }
        for (int i = input; i < k - 1; i++) {
            menu[i] = menu[i + 1];
            itemid[i] = itemid[i + 1];
            price[i] = price[i + 1];
            available[i] = available[i + 1];
        }

        k--;
        cout << "Item removed.\n";
    }
}
void display(int* itemid, double* price, string* menu, bool* available, int k) {
    cout << left << setw(20) << "Menu"<< right << setw(10) << "Price"<< setw(10) << "Item ID" << setw(15) << "Availability" << endl;

    for (int i = 0; i < k; i++) {
        cout << left << setw(20) << *(menu + i)  << right << setw(10) << *(price + i) << setw(10) << fixed << setprecision(2) << *(itemid + i) << setw(15) << (*(available + i) ? "Available" : "Unavailable") << endl;
    }
}
void iddisplay(int* itemid, double* price, string* menu, bool* available, int k) {
    int input;
    while (true) {
        cout << "enter id(enter -2 to exit): ";
        cin >> input;
        if (input == -2)
            break;
        if (input < 0 || input >= k) {
            cout << "invalid, try again\n";
            continue;
        }
        cout << left << setw(20) << "Menu" << right << setw(10) << "Price" << setw(15)  << "Availability" << endl;
            cout << left << setw(20) << *(menu + input) << right << setw(10) << *(price + input) << setw(15) << fixed << setprecision(2) << (*(available + input) ? "Available" : "Unavailable") << endl;

    }
}
void sorting(double*& price, string*& menu, int*& itemid, int k) {
    double tmp;
    string tmp1;
    int tmp2;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (*(price + i) > *(price + i + 1))
            {
                tmp = price[j];
                tmp1 = menu[j];
                tmp2 = itemid[j];
                price[j] = price[j + 1];
                menu[j] = menu[j + 1];
                itemid[j] = itemid[j + 1];
                price[j + 1] = tmp;
                menu[j + 1] = tmp1;
                itemid[j + 1] = tmp2;
            }
        }
    }
}
void categories(int*& category, string*& menu, double*& price, int*& itemid, int k) {
    int input;
    while (true) {
        cout << "Choose a category (1=drinks, 2=appetizers, 3=salad, 4=mains, 5=back): ";
        cin >> input;
        if (input == 5)
            break;

        if (input < 1 || input > 4) {
            cout << "Invalid category, try again.\n";
            continue;
        }

        int itemInput;
        cout << "Enter item id to assign to this category (-2 to stop): ";
        while (true) {
            cin >> itemInput;
            if (itemInput == -2)
                break;
            if (itemInput < 0 || itemInput >= k) {
                cout << "Invalid item id, try again.\n";
                continue;
            }
            category[itemInput] = input;
            cout << "Assigned " << menu[itemInput] << " to category " << input << endl;
        }
    }
}

void clean(string*& menu, int* category, double*& price, int*& itemid, int k)
{
    int choice;
    cout << "1.by price\n2.by category\n";
    cin >> choice;
    if (choice == 1)
        sorting(price, menu, itemid, k);
    else if (choice == 2)
        categories(category, menu, price, itemid, k);
    else
        cout << "Invalid choice\n";
}
void addtable(int& k, int*& tableid, int *& capci,int *&status) {
    cout << "wanna add tables press y to do so (type - 2 to go back)\n";
    string input;

    while (true) {

        cin >> input;
        if (input == "-2")
            break;
        else if (input == "y") {
            *(tableid + k) = k;
            k++;
            cout << "added " << k << " table\n";
            cout << "table number" << k << " got assigned itemid:" << k-1 << endl;
            capci[k - 1] = 0;
            status[k - 1] = 0;
        }
        else
            cout << "invalid output";
    }

}
void Capacity(int*& capci, int* tableid, int k) {
    cout << "enter table id(-2 to exit): ";
    int input;
    while (true) {
        cin >> input;
        if (input == -2)
            break;
        if (input < 0 || input >= k) {
            cout << "invalid, try again\n";
            continue;
        } cout << "enter capacity: ";
    cin >> capci[input];
    break;
    }
   

}
void status(int*& status, int* tableid, int k) {
    cout << "enter table id(-2 to exit): ";
    int input;
    bool sasa = false;
    while (true) {
        cin >> input;
        if (input == -2)
            break;
        for (int i = 0; i < k; i++) {
            if (tableid[i] == input) {
                sasa = true;
                break;
            }

        }
        if (!sasa) {
            cout << "invalid, try again\n";
            continue;
        }
    }
    int choice;
    cout << "enter choice:\n1.free\n2.occupied\n3.reserved\n";
    cin >> choice;
    if (choice == 1)
        *(status + input) = 0;
    else if (choice == 2)
        *(status + input) = 1;
    else if (choice == 3)
        *(status + input) = 2;
    else
        cout << "invalid" << endl;
}
#include <iostream>
#include <iomanip>
using namespace std;

void display1(int* tableid, int* status, int* capacity, int k) {
    cout << left << setw(12) << "Table ID" << left << setw(15) << "Status" << right << setw(10) << "Capacity" << endl;

    for (int i = 0; i < k; i++) {
        string statustext;
        switch (*(status + i)) {
        case 0: statustext = "Free"; break;
        case 1: statustext = "Occupied"; break;
        case 2: statustext = "Reserved"; break;
        default: statustext = "Unknown"; break;
        }

        cout << left << setw(12) << *(tableid + i)<< left << setw(15) << statustext << right << setw(10) << *(capacity + i)<< endl;
    }
}


void iddisplay1(int* itemid, int* price, int* menu) {
    int input;
    while (true) {
        cout << "enter id (enter -2 to exit): ";
        cin >> input;

        if (input == -2)
            break;

        if (itemid[input] == input) {
            string statusText;
            switch (menu[input]) {
            case 0: statusText = "Free"; break;
            case 1: statusText = "Occupied"; break;
            case 2: statusText = "Reserved"; break;
            default: statusText = "Unknown"; break;
            }

            cout << left << setw(12) << "Capacity:" << right << setw(8) << menu[input] << endl;
            cout << left << setw(12) << "Price:"<< right << setw(8) << price[input] << endl;
            cout << left << setw(12) << "Status:" << right << setw(12) << statusText << endl;
        }
        else {
            cout << "invalid, try again\n";
        }
    }
}

void itemtable(int* tableid, int* itemid, int k, int j, int& index, int& input) {
    cout << "enter tableid";
    while (true) {
        cin >> input;
        if (input == -2)
            break;
        if (input < 0 || input >= k) {
            cout << "invalid, try again\n";
            continue;
        }

    }
    cout << "enter itemid";
    while (true) {
        cin >> index;
        if (index == -2)
            break;
        if (index < 0 || index >= j) {
            cout << "invalid, try again\n";
            continue;
        }
    }
}
void Addorder(int* idtable, int* itemid, int k, int j,
    int*& additems, int*& addtables,
    int*& addquantity, double* price, double*& addprice,
    string* menu, bool* available, int index, int input, int& p) {

    while (true) {
        itemtable(idtable, itemid, k, j, index, input);

        if (index == -2 || input == -2)
            break;

        if (!available[index]) {
            cout << "unavailable\n";
            continue;
        }


        bool found = false;
        for (int i = 0; i < p; i++) {
            if (additems[i] == index && addtables[i] == input) {
                addquantity[i]++;
                cout << menu[index] << " x" << addquantity[i] << endl;
                found = true;
                break;
            }
        }


        if (!found) {
            additems[p] = index;
            addtables[p] = input;
            addquantity[p] = 1;
            addprice[p] = price[index];
            cout << "Added " << menu[index] << " to table " << input << endl;
            p++;
        }
    }
}
void modifyquantity(int* additems, int* addtables, int* addquantity,
    double* addprice, string* menu,
    int p, int k, int j) {

    int tableInput, itemInput;
    cout << "Enter table id (-2 to exit): ";
    cin >> tableInput;
    if (tableInput == -2)
        return;

    cout << "Enter item id: ";
    cin >> itemInput;
    if (itemInput < 0 || itemInput >= k) {
        cout << "Invalid item ID\n";
        return;
    }

    bool found = false;
    for (int i = 0; i < p; i++) {
        if (additems[i] == itemInput && addtables[i] == tableInput) {
            found = true;

            cout << "Current quantity of " << menu[itemInput]
                << ": " << addquantity[i] << endl;
            cout << "Enter new quantity: ";

            int newQty;
            cin >> newQty;

            if (newQty <= 0) {
                cout << "Quantity is 0 → Removing item from the order.\n";
                for (int m = i; m < p - 1; m++) {
                    additems[m] = additems[m + 1];
                    addtables[m] = addtables[m + 1];
                    addquantity[m] = addquantity[m + 1];
                    addprice[m] = addprice[m + 1];
                }
                p--;
            }
            else {
                addquantity[i] = newQty;
                cout << "Quantity updated!\n";
            }
            break;
        }
    }

    if (!found)
        cout << "No such item ordered on this table.\n";
}
void canceltableorder(int* additems, int* addtables, int* addquantity,
    double* addprice, int& p) {

    int tableInput;
    cout << "Enter table id to cancel order (-2 to exit): ";
    cin >> tableInput;
    if (tableInput == -2)
        return;

    bool found = false;

    for (int i = 0; i < p; i++) {
        if (addtables[i] == tableInput) {
            found = true;


            for (int m = i; m < p - 1; m++) {
                additems[m] = additems[m + 1];
                addtables[m] = addtables[m + 1];
                addquantity[m] = addquantity[m + 1];
                addprice[m] = addprice[m + 1];
            }

            p--;
            i--;
        }
    }

    if (found)
        cout << "All orders for Table " << tableInput << " cancelled.\n";
    else
        cout << "No orders found for that table.\n";
}
void MarkServed(int table, int* additems, int* addtables, double* addprice, int& p, int j) {
    do {
        cout << "enter which table (-2 to exit)";
        cin >> table;
    } while (table < j);
    if (table == -2)
        return;
    for (int i = 0; i < p; i++) {
        if (addtables[i] == table) {


            for (int j = i; j < p - 1; j++) {
                additems[j] = additems[j + 1];
                addtables[j] = addtables[j + 1];
                addprice[j] = addprice[j + 1];
            }

            p--;
            cout << "One order for Table " << table << " is served.\n";
            return;
        }
    }

    cout << "No orders found for Table " << table << ".\n";
}


void displayTableOrders(int* tableid, int j, int* addtables, int* additems, int* addquantity, double* addprice, string* menu, int p) {
    int tableInput;
    cout << "Enter table id to display orders (-2 to exit): ";
    cin >> tableInput;
    if (tableInput == -2) return;


    bool valid = false;
    for (int i = 0; i < j; i++) {
        if (tableid[i] == tableInput) {
            valid = true;
            break;
        }
    }
    if (!valid) {
        cout << "Invalid table id.\n";
        return;
    }

    bool found = false;
    cout << "Orders for table " << tableInput << ":\n";
    cout << setw(8) << "Item" << setw(8) << "Qty" << setw(8) << "Price" << setw(8) << "Total" << endl;

    for (int i = 0; i < p; i++) {
        if (addtables[i] == tableInput) {
            found = true;
            double total = addquantity[i] * addprice[i];
            cout << setw(8) << menu[additems[i]]
                << setw(8) << addquantity[i]
                << setw(8) << addprice[i]
                << setw(8) << total << endl;
        }
    }

    if (!found) {
        cout << "No orders found for this table.\n";
    }
}
#include <cstdlib> 
#include <ctime>   

void closebill(int tableInput, int* additems, int* addtables, int* addquantity,
    double* addprice, int& p,
    int*& transID, int*& transTable, double*& transAmount, int& t) {

    srand(time(0));

    double total = 0;
    bool found = false;

    for (int i = 0; i < p; i++) {
        if (addtables[i] == tableInput) {
            found = true;
            total += addquantity[i] * addprice[i];
        }
    }

    if (!found) {
        cout << "No open orders for this table.\n";
        return;
    }


    int r = rand() % 2;
    if (r == 0) {
        total *= 1.10;
        cout << "Service Fee +10% Applied\n";
    }
    else {
        total *= 0.95;
        cout << "5% Discount Applied\n";
    }

    cout << "Total bill for table " << tableInput << ": $" << total << endl;

    transID[t] = t + 1;
    transTable[t] = tableInput;
    transAmount[t] = total;
    t++;


    for (int i = 0; i < p; i++) {
        if (addtables[i] == tableInput) {
            for (int j = i; j < p - 1; j++) {
                additems[j] = additems[j + 1];
                addtables[j] = addtables[j + 1];
                addprice[j] = addprice[j + 1];
                addquantity[j] = addquantity[j + 1];
            }
            p--;
            i--;
        }
    }

    cout << "Bill Closed  Orders cleared.\n";
}
int binarysearch(int* itemid, int k) {
    int target;
    while (true) {
        cout << "enter id(enter -2 to exit): ";
        cin >> target;
        if (target == -2)
            break;
        if (target < 0 || target >= k) {
            cout << "invalid, try again\n";
            continue;
        }
    }
    int left = 0, right = k - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (itemid[mid] == target)
            return mid;
        else if (itemid[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void reporttable(int* tablestatus, int tableCount) {
    cout << "\n--- Table Status Report ---\n";
    for (int i = 0; i < tableCount; i++) {
        cout << "Table " << i << ": "
            << (*(tablestatus + i) == 0 ? "Free" : "Occupied") << endl;
    }
}
void reportcategory(int* category, int* qty, int p) {
    int freq[10] = { 0 };

    for (int i = 0; i < p; i++) {
        freq[*(category + i)] += *(qty + i);
    }

    int maxCat = 0;
    for (int i = 1; i < 10; i++) {
        if (freq[i] > freq[maxCat]) maxCat = i;
    }

    cout << "\nMost Ordered Category = " << maxCat
        << " with " << freq[maxCat] << " items ordered.\n";
}
bool password() {
    const string managerPassword = "1234";
    string input;
    cout << "Enter manager password: ";
    cin >> input;
    if (input == managerPassword) {
        return true;
    }
    else {
        cout << "Incorrect password!\n";
        return false;
    }
}
int main() {
    int* itemid = new int[100], * categorycode = new int[100];
    double* price = new double[100], * addprice = new double[100], * transmoney = new double[100];
    bool* availabilitystatus = new bool[100];
    int choose;
    string* add = new string[100], stop;
    int k = 0, j = 0, t = 0;
    int* tableid = new int[100], * capacity = new int[100], * statuscode = new int[100];
    int* orderid = new int[100], * quantity = new int[100], * orderstatus = new int[100], index = 0, input = 0;//inputtable----indexmenu
    int* addtables = new int[100], p = 0, * additems = new int[100], * trans = new int[100], * transT = new int[100];

    do {
        cout << "you need to choose by the numbers shown below\n";
        cout << "1.add menu\n2.update menu item\n3.add table\n4.update tables\n5.create order\n6.modify order\n7.close bill\n8.Reports\n9.exit\n";
        cin >> choose;
        if (choose == 1) {
            Add(add, k, itemid,price);

        }
        else if (choose == 2) {
            do {
                int choice;
                cout << "you need to choose by the numbers shown below\n";
                cout << "1.update price or availibility\n2.remove menu items\n3.display all menu items\n4.search menu item by id\n5.sort menu items by category or price\n6.back\n";
                cin >> choice;
                if (choice == 1) {
                    int choicce;
                    cout << "1.add price\n2.add availability\n";
                    cin >> choicce;
                    if (choicce == 1)
                        prices(itemid, price, k);
                    else if (choicce == 2)
                        availibility(itemid, availabilitystatus, k);
                }
                else if (choice == 2) {
                    if (password())
                        removeitem(add, itemid, price, availabilitystatus, k);
                    else
                        cout << "denied\n";
                }
                else if (choice == 3)
                    display(itemid, price, add, availabilitystatus, k);
                else if (choice == 4)
                    iddisplay(itemid, price, add, availabilitystatus, k);
                else if (choice == 5)
                    clean(add, categorycode, price, itemid, k);
                else if (choice == 6)
                    break;
                else
                    cout << "invalid" << endl;
            } while (true);

        }
        else if (choose == 3) {
            addtable(j, tableid,capacity,statuscode);
        }
        else if (choose == 4) {
            do {
                int choice;
                cout << "1.update capacity\n2.change table status\n3.display all tables\n4.search for table by id\n5.back\n";
                cin >> choice;
                if (choice == 1)
                    Capacity(capacity, tableid, j);
                else if (choice == 2)
                    status(statuscode, tableid, j);
                else if (choice == 3)
                    display1(tableid, statuscode, capacity, j);
                else if (choice == 4)
                    iddisplay1(tableid, statuscode, capacity);
                else if (choice == 5)
                    break;
                else
                    cout << "invalid\n";
            } while (true);
        }
        else if (choose == 5) {
            int choice;
            do {
                cout << "1.add order\n2.modify quantity\n3.cancel order\n4.mark order as served\n5.display all orders for one table\n6.back";
                cin >> choice;
                if (choice == 1) {
                    Addorder(tableid, itemid, k, j, additems, addtables, quantity, price, addprice, add, availabilitystatus, index, input, p);
                }
                else if (choice == 2) {
                    modifyquantity(additems, addtables, quantity, addprice, add, p, k, j);/*modifyquantity(int* additems, int* addtables, int* addquantity,
            double* addprice, string* menu,
            int p, int k, int j) {*/
                }
                else if (choice == 3)/* void CancelTableOrder(int* additems, int* addtables, int* addquantity,
            double* addprice, int& p) {*/
                    canceltableorder(additems, addtables, quantity, addprice, p);
                else if (choice == 4)
                    MarkServed(input, additems, addtables, addprice, p, j);/*(int table, int* additems, int* addtables, double* addprice, int& p) {
            for (int i = 0; i < p; i++)*/
                else if (choice == 5)/*int* tableid, int j, int* addtables, int* additems, int* addquantity, double* addprice, string* menu, int p) {*/
                    displayTableOrders(tableid, j, addtables, additems, quantity, addprice, add, p);
                else if (choice == 6)
                    break;
                else
                    cout << "invalid\n";
            } while (true);
        }
        else if (choose == 6)/* void closebill(int table, int* additems, int* addtables, int* addquantity,
        double* addprice, int& p,
        int*& transID, int*& transTable, double*& transAmount, int& t) {*/
            closebill(input, additems, addtables, quantity, addprice, p, trans, transT, transmoney, t);
        else if (choose == 7)
        {
            if (password()) {
                int choice;
                do {
                    cout << "1.binarysearch\n2.daily revenue summary\n3.most orderedcategory code\n4.back\n";
                    cin >> choice;
                    if (choice == 1)
                        binarysearch(itemid, k);
                    else if (choice == 2)
                        reporttable(orderstatus, j);
                    else if (choice == 3)
                        reportcategory(categorycode, quantity, p);
                    else if (choice == 4)
                        break;
                    else
                        cout << "invalid\n";
                } while (true);
            }
            else
                cout << "denied\n";
        }
    } while (choose != 9);
    cout << "bye";
    delete[] itemid;
    delete[] categorycode;
    delete[] price;
    delete[] addprice;
    delete[] transmoney;
    delete[] availabilitystatus;
    delete[] add;
    delete[] tableid;
    delete[] capacity;
    delete[] statuscode;
    delete[] orderid;
    delete[] quantity;
    delete[] orderstatus;
    delete[] addtables;
    delete[] additems;
    delete[] trans;
    delete[] transT;

    itemid = categorycode = nullptr;
    price = addprice = transmoney = nullptr;
    availabilitystatus = nullptr;
    add = nullptr;
    tableid = capacity = statuscode = nullptr;
    orderid = quantity = orderstatus = nullptr;
    addtables = additems = trans = transT = nullptr;
}