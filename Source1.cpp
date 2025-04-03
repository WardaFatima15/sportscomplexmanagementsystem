//#include <iostream>
//#include<cctype>
//#include"person.cpp"
//#include <sqlite3.h>
//#include <string>
//#include <iomanip>
//#include<fstream>
//#include<sstream>
//template <class visitor>
//int SIZE = 0;
//using namespace std;
//int count(sqlite3* db) {
//    sqlite3_stmt* stmt;
//    const char* countSQL = "SELECT COUNT(*) FROM visitors;";
//    int counter = 0;
//
//    if (sqlite3_prepare_v2(db, countSQL, -1, &stmt, nullptr) != SQLITE_OK) {
//        cerr << "Error preparing count query: " << sqlite3_errmsg(db) << endl;
//        return -1;
//    }
//
//    if (sqlite3_step(stmt) == SQLITE_ROW) {
//        counter = sqlite3_column_int(stmt, 0);
//    }
//
//    sqlite3_finalize(stmt);
//
//    return counter;
//}
//class visitor :public person {
//    double bill;
//
//
//public:
//    visitor() {
//        bill = 0;
//    }
//    visitor(int i, string na, int a, string nu) :person(i, na, a, nu)
//    {
//
//    }
//    void setBill(double x
//    ) {
//        bill = x;
//    }
//    double getBill() const { return bill; }
//
//    void saveToDatabase(sqlite3* db) {
//        string sql = "insert into table (name , age , phone number,  bill) VALUES (? , ? , ? , ?)";
//        sqlite3_stmt* stmt;
//        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
//            sqlite3_bind_text(stmt, 1, getName().c_str(), -1, SQLITE_STATIC);
//            sqlite3_bind_int(stmt, 2, getAge());
//            sqlite3_bind_text(stmt, 3, getPhoneNumber().c_str(), -1, SQLITE_STATIC);
//            sqlite3_bind_double(stmt, 4, getBill());
//            sqlite3_step(stmt);
//            sqlite3_finalize(stmt);
//        }
//    }
//
//
//};
//class gokarting {
//
//    int age;
//    double charge;
//    string optype;
//    string ktype;
//    string timeslot[3];
//    double kit;
//    string seltime;
//public:
//    gokarting(visitor& x) {
//        age = 0;
//        charge = 0;
//        double round = 1000;
//        double typecharge[3] = { 0,1000,1500 };
//        kit = 1500;
//        timeslot[0] = "8:00-10:00 AM(MORNING)";
//        timeslot[1] = "12:00-2:00 PM (AFTERNOON)";
//        timeslot[2] = "6:00-8:00 PM  (NIGHT)";
//        char choice;
//        cout << "DO YOU WANT TO MAKE AN INDIVIDUAL BOOKING OR GROUP BOOKING" << endl;
//        cout << "PRESS I FOR INDIVIDUAL AND G FOR GROUP BOOKING" << endl;
//        cin >> choice;
//        while (cin.fail() || choice != 'I' && choice != 'G') {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 'I' or 'G': ";
//            cin >> choice;
//        }
//        if (choice == 'I' || choice == 'i') {
//            indi();
//        }
//        else if (choice == 'G' || choice == 'g') {
//            group();
//
//        }
//        else {
//            cout << "ENTER VALID CHOICE" << endl;
//        }
//        selectage();
//        selecttime();
//        selectkart();
//        selectkit();
//        display(x);
//    }
//    void indi() {
//        cout << " HOW MANY ROUNS WILL YOU LIKE (max 10 rounds)" << endl;
//        int round;
//        cin >> round;
//        while (cin.fail() || round <= 0 || round > 10) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 10: ";
//            cin >> round;
//        }
//        charge = round * 1000;
//    }
//    void selectage() {
//        int age;
//        cout << "ENTER YOUR AGE PLEASE" << endl;
//        cin >> age;
//        while (cin.fail() || age <= 0 || age < 15) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.You are not eligible for GOKARTING. ";
//            exit(0);
//        }
//        if (age >= 16 && age <= 60) {
//
//            cout << "You are eligible.  Cant wait to have you" << endl;
//
//        }
//        else if (age > 60 && age < 100) {
//            cout << "YOU WILL GWT 20% OFF DUE TO SENIOR CITIZENSHIP" << endl;
//            charge *= 0.8;
//        }
//    }
//    void selecttime() {
//        bool flag = false;
//        cout << "CHOOSE TIME SLOT  " << endl;
//        int choose;
//        cin >> choose;
//        while (cin.fail() || choose <= 0 || choose > 3) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.Please enter a number between 1 and 3: ";
//            cin >> choose;
//        }
//        for (int i = 0; i < 3; i++) {
//
//            cout << i + 1 << " )" << timeslot[i] << endl;
//
//
//        }
//        do {
//            cout << " Enter your choice please" << endl;
//            cin >> choose;
//            while (cin.fail() || choose <= 0 || choose > 3) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input.Please enter a number between 1 and 3: ";
//                cin >> choose;
//            }
//            if (choose >= 1 && choose <= 3) {
//
//
//                cout << " YOU CHOSE" << "  " << timeslot[choose - 1] << endl;
//                seltime = timeslot[choose - 1];
//                flag = true;
//            }
//            else {
//                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//            }
//
//        } while (!flag);
//    }
//    string gettype(int choose) {
//
//        switch (choose)
//        {
//        case 1:
//            return "Regular Kart";
//
//        case 2:
//            return "Turbo Kart";
//        case 3:
//            return "Super Kart";
//        }
//
//
//
//
//    }
//    void selectkart() {
//
//        cout << "CHOOSE THE TYPE OF KART YOU WANT" << endl;
//
//        cout << " 1)   :REGULAR KART " << endl;
//        cout << " 2)   :TURBO KART       " << endl;
//        cout << " 3)   : SUPER KART       " << endl;
//        int choose;
//        do {
//            cout << " Enter your choice please" << endl;
//            cin >> choose;
//            while (cin.fail() || choose <= 0 || choose > 3) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input.Please enter a number from 1 to 3: ";
//                cin >> choose;
//            }
//            if (choose >= 1 && choose <= 3) {
//
//
//                cout << " YOU CHOSE" << " " << choose << endl;
//                charge += (choose - 1) * 500;
//
//                ktype = gettype(choose);
//                break;
//            }
//            else {
//                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//            }
//        } while (true);
//
//    }
//    void selectkit() {
//
//        cout << "GOKARTING KIT IS NECESSARY EITHER BRING YOUR OWN OR YOU CAN RENT IT FOR RS.1000" << endl;
//        char choice;
//        cout << "ENTER Y IF YOU WANT TO RENT IT AND N IF YOU CAN BRING YOUR OWN" << endl;
//        cin >> choice;
//        while (cin.fail() || choice != 'y' && choice != 'Y') {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.Please enter 'y' or 'Y': ";
//            cin >> choice;
//        }
//        if (choice == 'Y' || choice == 'y') {
//
//            charge += kit;
//            cout << "KIT RENTED" << endl;;
//        }
//        else {
//            cout << "KIT NOT RENTED" << endl;
//        }
//
//    }
//    void group() {
//        int size;
//        cout << "ENTER YOUR GROUP SIZE(max 5)" << endl;
//        cin >> size;
//        while (cin.fail() || size <= 0 || size > 5) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.Please enter the size between 1 and 5: ";
//            cin >> size;
//        }
//        for (int i = 0; i < size; i++) {
//
//            cout << "kart" << " " << i + 1 << endl;
//            indi();
//        }
//    }
//    void display(visitor& x) {
//        cout << "VISIT TYPE:" << " " << optype << endl;;
//        cout << " KART TYPE:" << " " << ktype << endl;
//        cout << " TIMESLOT" << "" << seltime << endl;
//        x.setBill(charge);
//        cout << " TOTAL CHARGE:" << fixed << setprecision(2) << " " << charge << endl;
//    }
//};
//
//class runningtrack {
//    char basicchoice;
//    char gender;
//    int age;
//    char mehour;
//    int km[4];
//    string fhour;
//    string track[5];
//    string refreshment[4];
//    double rcharges[4];
//public:
//    runningtrack(visitor& x) {
//        cout << "Please enter your age: ";
//        cin >> age;
//        while (cin.fail() || age <= 0) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a positive non zero integer: ";
//            cin >> age;
//        }
//        cout << "\t\t\t\tWould you like to join us for:\n";
//        cout << "a.Walking.\n";
//        cout << "b.Jogging.\n";
//        cout << "Press a or b: ";
//        cin >> basicchoice;
//        while (cin.fail() || basicchoice != 'a' && basicchoice != 'b') {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 'a' or 'b' ";
//            cin >> basicchoice;
//        }
//        cout << "Please select your gender:\n";
//        cout << "Female\n";
//        cout << "Male\n";
//        cout << "Press f or m: ";
//        cin >> gender;
//        while (cin.fail() || gender != 'f' && gender != 'm') {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 'f' or 'm' ";
//            cin >> gender;
//        }
//        cout << "Would you prefer morning or evening walking/jogging:\n";
//        cout << "a.morning\n";
//        cout << "b.evening\n";
//        cin >> mehour;
//        while (cin.fail() || mehour != 'a' && mehour != 'b') {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 'a' or 'b' ";
//            cin >> mehour;
//        }
//        if ((basicchoice == 'a' || basicchoice == 'b') && gender == 'f' && mehour == 'a') {
//            fhour = "5 am to 6 am";
//        }
//        else if ((basicchoice == 'a' || basicchoice == 'b') && gender == 'f' && mehour == 'b') {
//            fhour = "5 pm to 6 pm";
//        }
//        else if ((basicchoice == 'a' || basicchoice == 'b') && gender == 'm' && mehour == 'a') {
//            fhour = "6 am to 7 am";
//        }
//        else if ((basicchoice == 'a' || basicchoice == 'b') && gender == 'm' && mehour == 'b') {
//            fhour = "6 pm to 7 pm";
//        }
//        kmtrack(x);
//        monthlybooking(x);
//    }
//    void kmtrack(visitor& x) {
//        cout << "\t\t\t\tWhat kind of track would you prefer:\n";
//        track[0] = "Sand Track";
//        track[1] = "Grass Track";
//        track[2] = "Fitness Trail";
//        track[3] = "Sprint Track";
//        track[4] = "Paved Track";
//        for (int i = 0; i < 5; i++) {
//            cout << track[i] << endl;
//        }
//        int c;
//        cout << "Please enter your choice (1-5): ";
//        cin >> c;
//        while (cin.fail() || c < 1 || c>5) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 5: ";
//            cin >> c;
//        }
//        if (c >= 1 && c <= 5) {
//            cout << "You have selected " << track[c - 1] << " track" << endl;
//        }
//        else {
//            cout << "Invalid option.";
//        }
//        cout << "How many km track would you prefer:\n";
//        km[0] = 1;
//        km[1] = 2;
//        km[2] = 3;
//        km[3] = 4;
//        for (int i = 0; i < 4; i++) {
//            cout << km[i] << endl;
//        }
//        int c1;
//        cout << "Please enter your choice (1-4): ";
//        cin >> c1;
//        while (cin.fail() || c1 < 1 || c1>4) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 4 ";
//            cin >> c1;
//        }
//        if (c1 >= 1 && c1 <= 4) {
//            cout << "You have selected " << km[c1 - 1] << " km track.\n";
//        }
//        else {
//            cout << "Invalid option.";
//        }
//    }
//    void monthlybooking(visitor& x) {
//        int c;
//        cout << "\t\t\t\tWould you like to prefer booking at us for:\n ";
//        cout << "Press 1 2 3:\n";
//        cout << "1.a week\n";
//        cout << "2.a month\n";
//        cout << "3.selective number of days\n";
//        cin >> c;
//        while (cin.fail() || c < 1 || c>3) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 1 or 2 or 3 ";
//            cin >> c;
//        }
//        double totalcharges = 0.0;
//        if (c == 1) {
//            totalcharges = 3500;
//        }
//        else if (c == 2) {
//            totalcharges = 15000;
//        }
//        else if (c == 3) {
//            int d;
//            cout << "For how many days you want to join us: ";
//            cin >> d;
//            while (cin.fail() || d <= 0) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a non zero integer: ";
//                cin >> d;
//            }
//            totalcharges = 700 * d;
//        }
//        cout << "Your current bill is: " << totalcharges << endl;
//        cout << "Would you prefer to book any refreshments:\n";
//        refreshment[0] = "Waterbottle";
//        refreshment[1] = "Energy Bars";
//        refreshment[2] = "Chilled Lemonade";
//        refreshment[3] = "Tea or coffee";
//        rcharges[0] = 120;
//        rcharges[1] = 250;
//        rcharges[2] = 300;
//        rcharges[3] = 200;
//        for (int i = 0; i < 4; i++) {
//            cout << i + 1 << " " << refreshment[i] << " Rs: " << rcharges[i] << endl;
//        }
//        int c1;
//        cout << "Please enter your choice (1-4): ";
//        cin >> c1;
//        while (cin.fail() || c1 < 1 || c1>4) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please entera number between 1 and 4: ";
//            cin >> c1;
//        }
//        if (c1 >= 1 && c1 <= 4) {
//            totalcharges += rcharges[c1 - 1];
//            cout << "You have selected " << refreshment[c1 - 1] << endl;
//        }
//        else {
//            cout << "Invalid option.";
//        }
//        x.setBill(totalcharges);
//        cout << "Your chosen slot is: " << fhour << endl;
//        cout << "Your total bill is: " << totalcharges << endl;
//        cout << "Happy Walking" << endl;
//    }
//};
//class gym
//{
//    int age;
//    double charge;
//    string opttype;
//    string wtype;
//    string tname;
//    string ttype;
//    string opt[2];
//    double opttypecharge[2];
//    string workout[3];
//    double workoutcharge[3];
//    string trainer[3][3];
//    double trianercharge[3][3];
//    string timeslot[3];
//    bool summer;
//public:
//    gym(visitor& x) {
//
//        charge = 0.0;
//        opttypecharge[0] = 5500;
//        opttypecharge[1] = 500;
//        workoutcharge[0] = 0;
//        workoutcharge[1] = 500;
//        workoutcharge[2] = 1000;
//        trainer[0][0] = "john slayer";
//        trainer[0][1] = "material gurl";
//        trainer[0][2] = "anita maxvynn";
//        trainer[1][0] = "ho lee shyt";
//        trainer[1][1] = "say my name";
//        trainer[1][2] = "Kaalmi Maibi";
//        trainer[2][0] = "Crystal Metheeny";
//        trainer[2][1] = "Dam soun";
//        trainer[2][2] = "prachi gram ar";
//
//
//        timeslot[0] = "8:00-10:00 AM(MORNING)";
//        timeslot[1] = "12:00-2:00 PM (AFTERNOON)";
//        timeslot[2] = "6:00-8:00 PM  (NIGHT)    ";
//        cout << "WELCOME TO OUR GYM" << endl;
//        cout << " Choose one option for your booking please" << endl;
//        cout << " 1:   MONTHLY MEMBERSHIP  (RS.5500 only)" << endl;
//        cout << " 2:    ONETIME VISIT        (RS.500 only)" << endl;
//        int choose;
//        do {
//            cout << " Enter your choice please" << endl;
//            cin >> choose;
//            while (cin.fail() || choose <= 0 || choose > 2) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a positive non zero integer between 1 and 2: ";
//                cin >> choose;
//            }
//            if (choose == 1 || choose == 2) {
//
//
//                cout << " YOU CHOSE" << " " << choose << endl;
//                charge = opttypecharge[choose - 1];
//                break;
//            }
//            else {
//                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//            }
//        }
//
//
//        while (true);
//
//        selectage();
//        selectworkout();
//        selecttrainer();
//        selecttime();
//        display(x);
//    }
//    void selectage() {
//        int age;
//        cout << "ENTER YOUR AGE PLEASE" << endl;
//        cin >> age;
//        while (cin.fail() || age <= 0 || age < 16) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input.You are not eligble for GYM please explore other activities: ";
//            cin >> age;
//        }
//        if (age >= 16 && age <= 60) {
//
//            cout << "You are eligble.  Cant wait to have you" << endl;
//
//        }
//        else if (age > 60 && age < 100) {
//            cout << "YOU WILL GWT 20% OFF DUE TO SENIOR CITIZENSHIP" << endl;
//            charge *= 0.8;
//        }
//    }
//    void selectworkout() {
//
//        cout << "CHOOSE THE TYPE OF WORKOUT YOU WANT" << endl;
//
//        cout << " 1)   : WEIGHTLIFTING " << endl;
//        cout << " 2)   : CARDIO        " << endl;
//        cout << " 3 )  : YOGA       " << endl;
//        int choose;
//        do {
//            cout << " Enter your choice please" << endl;
//            cin >> choose;
//            while (cin.fail() || choose <= 0 || choose > 3) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a number between 1 and 3:  ";
//                cin >> choose;
//            }
//            if (choose >= 1 && choose <= 3) {
//
//
//                cout << " YOU CHOSE" << " " << choose << endl;
//                charge = workoutcharge[choose - 1];
//
//                wtype = gettype(choose);
//                break;
//            }
//            else {
//                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//            }
//        }
//
//
//        while (true);
//
//
//    }
//    string gettype(int choose) {
//
//        switch (choose)
//        {
//        case 1:
//            return "Heavylifting";
//
//        case 2:
//            return "Cardio";
//        case 3:
//            return "Yoga";
//        }
//
//
//
//
//    }
//    string getname(string type, int ind) {
//
//        if (type == "Heavylifting") {
//            return "Heavylifting Trainer";
//        }
//        else	if (type == "Cardio") {
//            return "Cardio Trainer";
//        }
//        else if (type == "Yoga") {
//            return "Yoga Trainer";
//        }
//        else {
//            return "";
//        }
//    }
//    int getind(string type) {
//        if (type == "Heavylifting") {
//            return 0;
//        }
//        else	if (type == "Cardio") {
//            return 1;
//        }
//        else if (type == "Yoga") {
//            return 2;
//        }
//        else {
//            return -1;
//        }
//
//    }
//    void selecttrainer() {
//        cout << "CHOOSE TRAINER FOR " << "  " << wtype << endl;
//        int choice;
//        for (int i = 0; i < 3; i++) {
//
//            cout << i + 1 << "  ) " << trainer[getind(wtype)][i] << endl;
//
//
//        }
//        do {
//
//            cout << "ENTER YOUR CHOICE" << endl;
//            cin >> choice;
//            while (cin.fail() || choice < 1 || choice>3) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a number between 1 and 3: ";
//                cin >> choice;
//            }
//            if (choice >= 1 && choice <= 3) {
//
//
//                cout << "You selected" << " " << trainer[getind(wtype)][choice - 1] << endl;
//
//
//                tname = trainer[getind(wtype)][choice - 1];
//                ttype = getname(wtype, choice - 1);
//                break;
//            }
//            else {
//                cout << "invalid choice" << endl;
//            }
//        } while (true);
//    }
//    void selecttime() {
//        bool flag = false;
//        cout << "CHOOSE TIME SLOT  " << endl;
//        int choose;
//        for (int i = 0; i < 3; i++) {
//
//            cout << i + 1 << timeslot[i] << endl;
//
//
//        }
//        do {
//            cout << " Enter your choice please" << endl;
//            cin >> choose;
//            while (cin.fail() || choose < 1 || choose>3) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input.Please enter a number between 1 and 3: ";
//                cin >> choose;
//            }
//            if (choose >= 1 && choose <= 3) {
//
//
//                cout << " YOU CHOSE" << "  " << timeslot[choose - 1] << endl;
//                flag = true;
//            }
//            else {
//                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//            }
//
//        } while (!flag);
//    }
//    void display(visitor& x) {
//        x.setBill(charge);
//
//        cout << "VISIT TYPE:" << " " << opttype << endl;;
//        cout << " WORKOUT TYPE:" << " " << wtype << endl;
//        cout << " TRAINER: " << " " << tname << endl;
//        cout << " TOTAL CHARGE:" << fixed << setprecision(2) << " " << charge << endl;
//
//    }
//};
//
//class Cafeteria {
//private:
//    string menuNames[50];
//    int menuQuantities[50];
//    double menuPrices[50];
//    int itemCount;
//    string orderHistory[100];
//    int orderCount;
//    double totalBill;
//public:
//    Cafeteria(visitor& x) {
//        itemCount = 0;
//        orderCount = 0;
//        totalBill = 0.0;
//        addItem("Coffee", 10, 2.5);
//        addItem("Sandwich", 20, 5.0);
//        addItem("Salad", 15, 7.5);
//        addItem("zinger shawarma", 30, 100);
//        addItem("Biryani", 40, 150);
//        addItem("Pasta", 15, 200);
//        displayMenu();
//        placeOrder();
//        printIndividualBills();
//        showBill(x);
//    }
//
//    void addItem(string name, int quantity, double price) {
//
//        menuNames[itemCount] = name;
//        menuQuantities[itemCount] = quantity;
//        menuPrices[itemCount] = price;
//        itemCount++;
//    }
//
//    void displayMenu() {
//        cout << "\n";
//        cout << "                 Cafeteria Menu    \n";
//        cout << "\n";
//
//        cout << setw(4) << left << "No." << setw(20) << left << "Item" << setw(15) << left << "Quantity" << setw(10) << "Price" << endl;
//        cout << "---------------------------------------------\n";
//
//        for (int i = 0; i < itemCount; ++i) {
//            cout << setw(4) << left << i + 1
//                << setw(20) << left << menuNames[i]
//                << setw(15) << left << menuQuantities[i]
//                << "$" << setw(9) << fixed << setprecision(2) << menuPrices[i] << endl;
//        }
//    }
//    void placeOrder() {
//        int index = 0;
//        while (index != -1) {
//            cout << "Enter the index of the item you want to buy. Press -1 if you are done buying: ";
//            cin >> index;
//            if (cin.fail()) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input." << endl;
//                continue;
//            }
//            if (index == -1) {
//                break;
//            }
//            if (index >= 1 && index <= itemCount) {
//                cout << "Enter quantity: ";
//                int quantity;
//                cin >> quantity;
//                if (cin.fail() || quantity <= 0) {
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    cout << "Invalid quantity. Please enter a positive integer.";
//                    cin >> quantity;
//                }
//                if (quantity > menuQuantities[index - 1]) {
//                    cout << "Insufficient quantity in inventory!" << endl;
//                    continue;
//                }
//                // If the quantity is valid and sufficient
//                menuQuantities[index - 1] -= quantity;
//                totalBill += quantity * menuPrices[index - 1];
//                orderHistory[orderCount++] = menuNames[index - 1] + " x" + to_string(quantity);
//                cout << "Order placed successfully!" << endl;
//            }
//            else if (index != -1) {
//                cout << "Invalid item index!" << endl;
//            }
//        }
//    }
//    void printIndividualBills() {
//        cout << "\n";
//        cout << "      Order Bill      \n";
//        cout << "\n";
//
//        cout << setw(20) << left << "Item" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
//        cout << "---------------------------------------------\n";
//
//        for (int i = 0; i < orderCount; ++i) {
//
//            int itemIndex = -1;
//            for (int j = 0; j < itemCount; ++j) {
//                int k = 0;
//                while (k < orderHistory[i].length() && k < menuNames[j].length()) {
//                    if (orderHistory[i][k] != menuNames[j][k]) {
//                        break;
//                    }
//                    k++;
//                }
//                if (k == orderHistory[i].find('x') - 1) {
//                    itemIndex = j;
//                    break;
//                }
//            }
//
//            double itemPrice = menuPrices[itemIndex];
//
//            int quantity = 0;
//            bool foundX = false;
//            for (int k = 0; k < orderHistory[i].length(); ++k) {
//                char c = orderHistory[i][k];
//                if (isdigit(c) && foundX) {
//                    quantity = quantity * 10 + (c - '0');
//                }
//                else if (c == 'x') {
//                    foundX = true;
//                }
//            }
//
//
//            double total = quantity * itemPrice;
//
//            cout << setw(20) << left << orderHistory[i].substr(0, orderHistory[i].find('x') - 1)
//                << setw(10) << quantity
//                << "$" << setw(9) << fixed << setprecision(2) << itemPrice
//                << "$" << setw(9) << fixed << setprecision(2) << total << endl;
//        }
//
//
//        cout << "---------------------------------------------\n";
//    }
//    int findItemIndex(string itemName) {
//        for (int i = 0; i < itemCount; ++i) {
//            int j = 0;
//            while (j < itemName.length() && j < menuNames[i].length()) {
//                if (itemName[j] != menuNames[i][j]) {
//                    break;
//                }
//                j++;
//            }
//            if (j == itemName.find('x') - 1) {
//                return i;
//            }
//        }
//        return -1;
//    }
//
//
//
//    void showBill(visitor& x) {
//        x.setBill(totalBill);
//        cout << "Total Bill: $" << totalBill << endl;
//    }
//
//};
//class HorseRidingActivity {
//private:
//    string horsesName[100];
//    string horsesBreed[100];
//    string timeSlots[100];
//    string instructors[100];
//    double horseCharges[100];
//    int numHorses;
//    int numTimeSlots;
//    int numInstructors;
//    string selectedHorse;
//    string selectedInstructor;
//    string selectedTimeSlot;
//    double totalCharge;
//
//public:
//    HorseRidingActivity(visitor& x) {
//
//        numHorses = 5;
//        horsesName[1] = "Maiza";
//        horsesName[2] = "Ushna";
//        horsesName[3] = "Charlie";
//        horsesName[4] = "Bella";
//        horsesName[5] = "Max";
//
//        horsesBreed[1] = "Maham";
//        horsesBreed[2] = "Dar";
//        horsesBreed[3] = "Arabian";
//        horsesBreed[4] = "Thoroughbred";
//        horsesBreed[5] = "Shetland";
//
//        horseCharges[1] = 25.0;
//        horseCharges[2] = 30.0;
//        horseCharges[3] = 20.0;
//        horseCharges[4] = 35.0;
//        horseCharges[5] = 40.0;
//
//
//        numTimeSlots = 4;
//        timeSlots[1] = "9 to 12";
//        timeSlots[2] = "12 to 3";
//        timeSlots[3] = "3 to 6";
//        timeSlots[4] = "6 to 9";
//
//        numInstructors = 5;
//        instructors[1] = "Meta AI";
//        instructors[2] = "ABCD";
//        instructors[3] = "Nobita";
//        instructors[4] = "Meow";
//        instructors[5] = "Billu";
//
//        if (takeInfo()) {
//            showHorses();
//
//            int horseIndex, timeSlotIndex;
//            cout << "Enter the number of the horse you want: ";
//            cin >> horseIndex;
//            while (cin.fail() || horseIndex <= 0 || horseIndex > 5) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a positive non zero integer: ";
//                cin >> horseIndex;
//            }
//            selectHorse(horseIndex);
//
//            showInstructors();
//
//            int instructorIndex;
//            cout << "Enter the number of the instructor you want: ";
//            cin >> instructorIndex;
//            while (cin.fail() || instructorIndex <= 0 || instructorIndex > 5) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a positive non zero integer: ";
//                cin >> instructorIndex;
//            }
//            selectInstructor(instructorIndex);
//
//            displayTimeSlots();
//            cout << "Enter index of time slot: ";
//            cin >> timeSlotIndex;
//            while (cin.fail() || timeSlotIndex <= 0 || timeSlotIndex > 4) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a positive non zero integer: ";
//                cin >> timeSlotIndex;
//            }
//            selectTimeSlot(timeSlotIndex);
//
//            double totalCharge = calculateTotalCharge(x);
//
//            cout << "\n\n-------------------------" << endl;
//            cout << "    YOUR RECEIPT" << endl;
//            cout << "-------------------------" << endl;
//            cout << "Horse: " << getSelectedHorse() << endl;
//            cout << "Instructor: " << getSelectedInstructor() << endl;
//            cout << "Time Slot: " << getSelectedTimeSlot() << endl;
//            cout << "Total Charges: $" << totalCharge << endl;
//        }
//    }
//
//    bool takeInfo() {
//        int age;
//
//        cout << "Enter your age: ";
//        cin >> age;
//        while (cin.fail() || age <= 0) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a positive non zero integer: ";
//            cin >> age;
//        }
//        if (age <= 3) {
//            cout << "Go to play area." << endl;
//            return false;
//        }
//        else {
//            cout << "You can participate in horse riding." << endl;
//            return true;
//        }
//    }
//
//
//    void showHorses() {
//        cout << "Available horses in stable:" << endl;
//        for (int i = 1; i <= numHorses; i++) {
//            cout << i << ". " << "Name: " << horsesName[i] << ", Breed: " << horsesBreed[i] << ", Charge: $" << horseCharges[i] << endl;
//        }
//    }
//
//    void selectHorse(int index) {
//        selectedHorse = horsesName[index];
//        cout << "Selected horse: " << selectedHorse << " (" << horsesBreed[index] << ")" << endl;
//    }
//
//    void selectTimeSlot(int index) {
//        selectedTimeSlot = timeSlots[index];
//        cout << "Selected time slot: " << selectedTimeSlot << endl;
//    }
//
//    void selectInstructor(int index) {
//        selectedInstructor = instructors[index];
//        cout << "Selected instructor: " << selectedInstructor << endl;
//    }
//
//    void displayTimeSlots() {
//        cout << "Available time slots:" << endl;
//        for (int i = 1; i <= numTimeSlots; i++) {
//            cout << i << ": " << timeSlots[i] << endl;
//        }
//    }
//
//    double calculateTotalCharge(visitor& x) {
//        totalCharge = horseCharges[getSelectedHorseIndex()];
//        totalCharge += 10.0;
//        x.setBill(totalCharge);
//        return totalCharge;
//    }
//
//    int getSelectedHorseIndex() {
//        for (int i = 1; i <= numHorses; i++) {
//            if (horsesName[i] == selectedHorse) {
//                return i;
//            }
//        }
//        return -1;
//    }
//    void showInstructors() {
//        cout << "Available instructors:" << endl;
//        for (int i = 1; i <= numInstructors; i++) {
//            cout << i << ". " << instructors[i] << endl;
//        }
//    }
//
//    string getSelectedHorse() {
//        return selectedHorse;
//    }
//
//    string getSelectedInstructor() {
//        return selectedInstructor;
//    }
//
//    string getSelectedTimeSlot() {
//        return selectedTimeSlot;
//    }
//
//    double getTotalCharge() {
//        return totalCharge;
//    }
//};
//
//class BoatingActivity {
//private:
//    string boatstype[100];
//    string boatssize[100];
//    string boatcolor[100];
//    double chargers[100];
//    int numTimeSlots;
//    string timeSlots[5];
//    double totalCharge;
//    string selectedBoatType;
//    string selectedBoatSize;
//    string selectedBoatColor;
//    string selectedTimeSlot;
//
//public:
//    BoatingActivity(visitor& x) {
//        numTimeSlots = 4;
//        timeSlots[0] = "9 to 12";
//        timeSlots[1] = "12 to 3";
//        timeSlots[2] = "3 to 6";
//        timeSlots[3] = "6 to 9";
//
//
//        boatstype[0] = "Canoe";
//        boatstype[1] = "Kayak";
//        boatstype[2] = "Rowboat";
//        boatstype[3] = "Paddle Boat";
//        boatstype[4] = "Speedboat";
//
//        boatssize[0] = "Small";
//        boatssize[1] = "Medium";
//        boatssize[2] = "Large";
//        boatssize[3] = "Extra Large";
//        boatssize[4] = "Jumbo";
//
//        boatcolor[0] = "Red";
//        boatcolor[1] = "Blue";
//        boatcolor[2] = "Green";
//        boatcolor[3] = "Yellow";
//        boatcolor[4] = "Orange";
//
//        chargers[0] = 10.0;
//        chargers[1] = 15.0;
//        chargers[2] = 20.0;
//        chargers[3] = 25.0;
//        chargers[4] = 30.0;
//
//        if (takeInfo()) {
//            showBoatTypes();
//            int boatTypeIndex;
//            cout << "Enter the index of the boat type you want to select: ";
//            cin >> boatTypeIndex;
//            while (cin.fail() || boatTypeIndex <= 0 || boatTypeIndex > 5) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a positive non zero integer: ";
//                cin >> boatTypeIndex;
//            }
//            selectBoatType(boatTypeIndex);
//
//            showBoatSizes();
//            int boatSizeIndex;
//            cout << "Enter the index of the boat size you want to select: ";
//            cin >> boatSizeIndex;
//            while (cin.fail() || boatSizeIndex <= 0 || boatSizeIndex > 5) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a positive non zero integer: ";
//                cin >> boatSizeIndex;
//            }
//            selectBoatSize(boatSizeIndex);
//
//            showBoatColors();
//            int boatColorIndex;
//            cout << "Enter the index of the boat color you want to select: ";
//            cin >> boatColorIndex;
//            while (cin.fail() || boatColorIndex <= 0 || boatColorIndex > 5) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a positive non zero integer: ";
//                cin >> boatColorIndex;
//            }
//            selectBoatColor(boatColorIndex);
//
//            calculateTotalCharge(boatTypeIndex, boatSizeIndex, boatColorIndex, x);
//
//            displayTimeSlots();
//            int timeSlotIndex;
//            cout << "Enter the index of the time slot you want to select: ";
//            cin >> timeSlotIndex;
//            while (cin.fail() || timeSlotIndex <= 0 || timeSlotIndex > 4) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a positive non zero integer: ";
//                cin >> timeSlotIndex;
//            }
//            selectTimeSlot(timeSlotIndex);
//
//            cout << "\n\n-------------------------" << endl;
//            cout << "    YOUR RECEIPT" << endl;
//            cout << "-------------------------" << endl;
//            cout << "Boat Type: " << getSelectedBoatType() << endl;
//            cout << "Boat Size: " << getSelectedBoatSize() << endl;
//            cout << "Boat Color: " << getSelectedBoatColor() << endl;
//            cout << "Time Slot: " << getSelectedTimeSlot() << endl;
//            cout << "Total Charges: $" << getTotalCharge() << endl;
//        }
//    }
//
//
//    string getSelectedBoatType() {
//        return selectedBoatType;
//    }
//
//    string getSelectedBoatSize() {
//        return selectedBoatSize;
//    }
//
//    string getSelectedBoatColor() {
//        return selectedBoatColor;
//    }
//
//    string getSelectedTimeSlot() {
//        return selectedTimeSlot;
//    }
//
//    double getTotalCharge() {
//        return totalCharge;
//    }
//
//    bool takeInfo() {
//        int age;
//        cout << "Enter your age: ";
//        cin >> age;
//        while (cin.fail() || age <= 0) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a positive non zero integer: ";
//            cin >> age;
//        }
//        if (age <= 3) {
//            cout << "Sorry, children below 3 years old are not allowed for boating activities." << endl;
//            return false;
//        }
//        else {
//            cout << "You can participate in boating activities." << endl;
//            return true;
//        }
//    }
//
//
//    void showBoatTypes() {
//        cout << "Available boat types:" << endl;
//        for (int i = 0; i < 5; ++i) {
//            cout << i + 1 << ". " << boatstype[i] << endl;
//        }
//    }
//
//    void showBoatSizes() {
//        cout << "Available boat sizes:" << endl;
//        for (int i = 0; i < 5; ++i) {
//            cout << i + 1 << ". " << boatssize[i] << endl;
//        }
//    }
//
//    void showBoatColors() {
//        cout << "Available boat colors:" << endl;
//        for (int i = 0; i < 5; ++i) {
//            cout << i + 1 << ". " << boatcolor[i] << endl;
//        }
//    }
//
//    void selectBoatType(int index) {
//        selectedBoatType = boatstype[index - 1];
//        cout << "Selected boat type: " << selectedBoatType << endl;
//    }
//
//    void selectBoatSize(int index) {
//        selectedBoatSize = boatssize[index - 1];
//        cout << "Selected boat size: " << selectedBoatSize << endl;
//    }
//
//    void selectBoatColor(int index) {
//        selectedBoatColor = boatcolor[index - 1];
//        cout << "Selected boat color: " << selectedBoatColor << endl;
//    }
//
//    void selectTimeSlot(int index) {
//        selectedTimeSlot = timeSlots[index - 1];
//        cout << "Selected time slot: " << selectedTimeSlot << endl;
//    }
//
//    void calculateTotalCharge(int boatTypeIndex, int boatSizeIndex, int boatColorIndex, visitor& x) {
//        totalCharge = 0;
//        totalCharge += chargers[boatTypeIndex] + chargers[boatSizeIndex] + chargers[boatColorIndex];
//        x.setBill(totalCharge);
//    }
//
//    void displayTimeSlots() {
//        cout << "Available time slots:" << endl;
//        for (int i = 0; i < numTimeSlots; ++i) {
//            cout << i + 1 << ". " << timeSlots[i] << endl;
//        }
//    }
//};
//
//
//
//
//class IndoorArcade {
//private:
//    int age;
//    string games[10];
//    double gamesCharges[10];
//    int vSlot;
//    int eSlot;
//    int goldCard;
//    int silverCard;
//    int selectedGames[10];
//    int numSelectedGames;
//
//public:
//    IndoorArcade(visitor& temp) {
//        cout << "\t\t\t\tWelcome to our Arcade\t\t\t\t\t" << endl;
//        cout << "You can book us from 4 pm to 11 pm." << endl;
//        cout << "Enter your visiting time: ";
//        cin >> vSlot;
//        while (cin.fail() || vSlot <= 0 || vSlot < 4 || vSlot>11) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 4 and 11: ";
//            cin >> vSlot;
//        }
//        cout << "Enter your leaving time: ";
//        cin >> eSlot;
//        while (cin.fail() || eSlot <= 0 || eSlot < 4 || eSlot>11 || eSlot <= vSlot) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a valid exit time: ";
//            cin >> eSlot;
//        }
//        cout << "You have booked from " << vSlot << " pm to " << eSlot << " pm" << endl;
//        int hourCount = eSlot - vSlot;
//        cout << "You have booked for " << hourCount << " hours." << endl;
//        cout << "Please enter your age: ";
//        cin >> age;
//        while (cin.fail() || age <= 5) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a non zero positive integer and greater than 5: ";
//            cin >> age;
//        }
//        // Initialize game charges
//        initializeGameCharges();
//        arcadeGames(temp);
//    }
//
//    // Initialize game charges
//    void initializeGameCharges() {
//        games[0] = "Tetris";  gamesCharges[0] = 3000;
//        games[1] = "Twilight Zone";  gamesCharges[1] = 4000;
//        games[2] = "Shooting Game (Time Crisis)";  gamesCharges[2] = 2500;
//        games[3] = "Coin Pushers";  gamesCharges[3] = 1500;
//        games[4] = "Mario Kart";  gamesCharges[4] = 1200;
//        games[5] = "Virtual Reality (VR) Games";  gamesCharges[5] = 3700;
//        games[6] = "Ping Pong (Table Tennis)";  gamesCharges[6] = 1670;
//        games[7] = "Fighting Games (Tekken)";  gamesCharges[7] = 2345;
//        games[8] = "Interactive Rides (motion simulators)";  gamesCharges[8] = 3489;
//        games[9] = "Basketball Shooting";  gamesCharges[9] = 2319;
//
//        goldCard = 50;  // 50% discount for gold card
//        silverCard = 25;  // 25% discount for silver card
//        numSelectedGames = 0;
//    }
//
//    // Display available games and handle card selection
//    void arcadeGames(visitor& temp) {
//        double totalCharges = 0;
//
//        char moreGames;
//        do {
//            cout << "\t\t\t\tYou have the following options for gaming:\t\t\t\t" << endl;
//            for (int i = 0; i < 10; ++i) {
//                cout << i + 1 << ". " << games[i] << " - $" << gamesCharges[i] * (eSlot - vSlot) << endl;
//            }
//
//            int choice;
//            cout << "Please select a game (1-10): ";
//            cin >> choice;
//            while (cin.fail() || choice < 1 || choice>10) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter a number between 1 and 10: ";
//                cin >> choice;
//            }
//            if (choice >= 1 && choice <= 10) {
//                selectedGames[numSelectedGames++] = choice - 1;
//                totalCharges += gamesCharges[choice - 1] * (eSlot - vSlot);
//            }
//            else {
//                cout << "Invalid game selection." << endl;
//            }
//            do {
//                cout << "More games->specialoffers\n";
//                cout << "Do you want to select more games? (y/n): ";
//                cin >> moreGames;
//                if (cin.fail() || (moreGames != 'y' && moreGames != 'n')) {
//                    cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                }
//            } while (cin.fail() || (moreGames != 'y' && moreGames != 'n'));
//        } while (moreGames == 'y' || moreGames == 'Y');
//
//        // Display selected games for confirmation
//        cout << "You have selected the following games:" << endl;
//        for (int i = 0; i < numSelectedGames; ++i) {
//            cout << i + 1 << ". " << games[selectedGames[i]] << endl;
//        }
//
//        // Allow user to cancel any game if needed
//        char cancelGame;
//        do {
//            cout << "Do you want to cancel any game? (y/n): ";
//            cin >> cancelGame;
//            if (cin.fail() || (cancelGame != 'y' && cancelGame != 'n')) {
//                cout << "Invalid input. Please enter 'y' for yes or 'n' for no: " << endl;
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            }
//        } while (cin.fail() || (cancelGame != 'y' && cancelGame != 'n'));
//        if (cancelGame == 'y' || cancelGame == 'Y') {
//            int gameNumber;
//            cout << "Enter the number of the game you want to cancel: ";
//            cin >> gameNumber;
//            while (cin.fail() || gameNumber < 1 || gameNumber >= numSelectedGames) {
//                cin.clear();
//                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "Invalid input. Please enter the number from your selected games: ";
//                cin >> gameNumber;
//            }
//            if (gameNumber >= 1 && gameNumber <= numSelectedGames) {
//                // Calculate refund amount
//                double refundAmount = gamesCharges[selectedGames[gameNumber - 1]] * (eSlot - vSlot);
//
//                // Remove the selected game from the list
//                for (int i = gameNumber - 1; i < numSelectedGames - 1; ++i) {
//                    selectedGames[i] = selectedGames[i + 1];
//                }
//                numSelectedGames--;
//
//                cout << "Game canceled successfully. Refund amount: $" << refundAmount << endl;
//            }
//            else {
//                cout << "Invalid game number." << endl;
//            }
//        }
//
//        char cardChoice;
//        cout << "Please select your card for booking with us (gold/silver). Press 'g' or 's': ";
//        cin >> cardChoice;
//        while (cin.fail() || cardChoice != 'g' && cardChoice != 's') {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 'g' or 's': ";
//            cin >> cardChoice;
//        }
//        double finalCharges = totalCharges;
//
//        cout << "Total charges after discount: $" << finalCharges << endl;
//        if (cardChoice == 'g') {
//            // Gold card owner
//            finalCharges -= (finalCharges * goldCard) / 100;
//            cout << "50% discount granted for gold card." << endl;
//            if (numSelectedGames == 2) {
//                cout << "Special offer for you: Free movie ticket!" << endl;
//            }
//            else if (numSelectedGames >= 2) {
//                cout << "Special offer for you: Free cotton candy!" << endl;
//            }
//        }
//        else if (cardChoice == 's') {
//            // Silver card owner
//            finalCharges -= (finalCharges * silverCard) / 100;
//            cout << "25% discount granted for silver card." << endl;
//            if (numSelectedGames == 2) {
//                cout << "Special offer for you: Free ice cream!" << endl;
//            }
//            if (numSelectedGames >= 2) {
//                cout << "Special offer for you: Free chocolate chip cookies!" << endl;
//            }
//        }
//        else {
//            cout << "Invalid card choice." << endl;
//            return;
//        }
//        temp.setBill(finalCharges);
//    }
//};
//class swimming {
//private:
//    int date;
//    int month;
//    double totalCharges;
//    string slots;
//    char genderchoice;
//    int age;
//    string options[8];
//    double optionCharges[8];
//    string essentials[5];
//    double essentialCharges[5];
//    string postswim[4];
//    double postswimCharges[4];
//    bool summercheck;
//
//public:
//    swimming(visitor v) {
//        cout << "Swimming activity for visitor: " << v.getName() << endl;
//        totalCharges = 0.0;
//        cout << "Enter the date on which you want to come: ";
//        cin >> date;
//        cout << "Enter the month(1-12): ";
//        cin >> month;
//        if (month > 12 || month < 1) {
//            cout << "Invalid month. Please enter a valid month (1-12)." << endl;
//            return;
//        }
//        if ((month >= 1 && month <= 4) || (month >= 10 && month <= 12)) {
//            cout << "Winter booking is not allowed." << endl;
//            cout << "Please join us in Summers." << endl;
//            summercheck = false;
//            return;
//        }
//        else {
//            cout << "Beat the Heat this Summer with us." << endl;
//            summercheck = true;
//        }
//
//        // Initialize charges for options
//        optionCharges[0] = 5559.0;  // Charge for Beach
//        optionCharges[1] = 4008.0;  // Charge for Typhoon River
//        optionCharges[2] = 3005.0;  // Charge for Space Hole
//        optionCharges[3] = 6500.0;  // Charge for Free Fall
//        optionCharges[4] = 7000.0;  // Charge for Multi Surf
//        optionCharges[5] = 8000.0;  // Charge for Splash Zone
//        optionCharges[6] = 2000.0;   // Charge for Kids Aqua Zone
//        optionCharges[7] = 2500.0;  // Charge for Rafting Slide Coaster
//
//        // Initialize charges for essentials
//        essentialCharges[0] = 1500.0;  // Charge for Swim suit
//        essentialCharges[1] = 1000.0;  // Charge for Swim tubes
//        essentialCharges[2] = 3400.0;  // Charge for Life jackets
//        essentialCharges[3] = 2340.0;  // Charge for Goggles
//        essentialCharges[4] = 2900.5;  // Charge for Swim caps
//
//        // Initialize charges for post-swim essentials
//        postswimCharges[0] = 300.0;  // Charge for Towel
//        postswimCharges[1] = 420.0;  // Charge for Chlorine Removal Shampoo
//        postswimCharges[2] = 289.5;  // Charge for Moisturiser
//        postswimCharges[3] = 256.0;  // Charge for Body Wash
//
//        tellgender();
//        selectoptions();
//        selectessentials();
//        displayBill(v);
//    }
//
//    void tellgender() {
//        if (!summercheck) {
//            cout << "Booking is not available in winter months. Please come in summers." << endl;
//            return;
//        }
//
//        cout << "Select your gender: " << endl;
//        cout << "a. Female" << endl;
//        cout << "b. Male" << endl;
//        cin >> genderchoice;
//
//        if (genderchoice == 'a') {
//            cout << "Following slots are available for females: 12 pm to 3 pm" << endl;
//            slots = "12 pm to 3 pm";
//        }
//        else if (genderchoice == 'b') {
//            cout << "Following slots are available for males: 4 pm to 7 pm" << endl;
//            slots = "4 pm to 7 pm";
//        }
//        cout << "Enter your age: ";
//        cin >> age;
//        if (age <= 3) {
//            cout << "Please send your child to kids play area." << endl;
//            exit(0);
//        }
//    }
//    void selectoptions() {
//        options[0] = "Beach   Rs:5559";
//        options[1] = "Typhoon River  Rs:4008";
//        options[2] = "Space Hole    Rs:3005";
//        options[3] = "Free Fall   Rs:6500";
//        options[4] = "Multi Surf  Rs:7000";
//        options[5] = "Splash Zone  Rs:8000";
//        options[6] = "Aqua Zone  Rs:2000";
//        options[7] = "Rafting Slide Coaster  2500";
//        cout << "\t\t\t\tYou have following options\t\t\t\t\t" << endl;
//        cout << setw(5) << "Option" << setw(30) << "Price" << setw(10) << endl;
//        for (int i = 0; i < 8; i++) {
//            cout << setw(5) << (i + 1) << setw(30) << options[i] << setw(10) << optionCharges[i] << endl;
//        }
//
//        int choice;
//        do {
//            cout << "Please select an option (1-8): ";
//            cin >> choice;
//
//            if (choice >= 1 && choice <= 8) {
//                cout << "You have selected: " << options[choice - 1] << endl;
//                totalCharges += optionCharges[choice - 1]; // Add selected option charge to total charges
//            }
//            else {
//                cout << "Invalid option selected!" << endl;
//            }
//
//            cout << "Current total charges: Rs: " << totalCharges << endl;
//
//            char proceed;
//            cout << "Do you want to select another option? (y/n): ";
//            cin >> proceed;
//
//            if (proceed != 'y' && proceed != 'Y') {
//                break;
//            }
//
//        } while (true);
//
//    }
//    void selectessentials() {
//        int quantity = 1;
//        essentials[0] = "Swim suit  Rs:1500";
//        essentials[1] = "Swim tubes  Rs:1000";
//        essentials[2] = "Life jackets  Rs:3400";
//        essentials[3] = "Goggles  Rs:2340";
//        essentials[4] = "Swim caps  Rs:2900";
//
//        cout << "\t\t\t\t " << "Following are the swimming essentials available : " << "\t\t\t" << endl;
//        cout << setw(5) << "Option" << setw(30) << "Price" << setw(10) << endl;
//        for (int i = 0; i < 5; i++) {
//            cout << setw(5) << (i + 1) << setw(30) << essentials[i] << setw(10) << essentialCharges[i] << endl;
//        }
//        int choice;
//        do {
//            cout << "Please select an option (1-5): ";
//            cin >> choice;
//
//            if (choice >= 1 && choice <= 5) {
//                cout << "You have selected: " << essentials[choice - 1] << endl;
//                int quantity;
//                cout << "Enter the quantity: ";
//                cin >> quantity;
//                totalCharges += essentialCharges[choice - 1] * quantity; // Add selected essential charge to total charges
//            }
//            else {
//                cout << "Invalid option selected!" << endl;
//            }
//
//            cout << "Current total charges: Rs: " << totalCharges << endl;
//
//            char proceed;
//            cout << "Do you want to select another essential? (y/n): ";
//            cin >> proceed;
//
//            if (proceed != 'y' && proceed != 'Y') {
//                break;
//            }
//
//        } while (true);
//
//        postswim[0] = "Towel  Rs:300";
//        postswim[1] = "Chlorine Removal Shampoo  Rs:420";
//        postswim[2] = "Moisturiser  Rs:289";
//        postswim[3] = "Body Wash  Rs:256";
//
//        cout << "\t\t\t\tYou have the following options for post swimming essentials :\t\t\t\t\t" << endl;
//        cout << setw(5) << "Option" << setw(30) << "Price" << setw(10) << endl;
//        for (int i = 0; i < 4; i++) {
//            cout << setw(5) << (i + 1) << setw(30) << postswim[i] << setw(10) << postswimCharges[i] << endl;
//        }
//        int choice1;
//        do {
//            cout << "Please select an option (1-4): ";
//            cin >> choice1;
//
//            if (choice1 >= 1 && choice1 <= 4) {
//                cout << "You have selected: " << postswim[choice1 - 1] << endl;
//                int quantity1 = 1;
//                cout << "Enter the quantity: ";
//                cin >> quantity1;
//                totalCharges += postswimCharges[choice - 1] * quantity1; // Add selected essential charge to total charges
//            }
//            else {
//                cout << "Invalid option selected!" << endl;
//            }
//
//            cout << "Current total charges: Rs: " << totalCharges << endl;
//
//            char proceed1;
//            cout << "Do you want to select another essential? (y/n): ";
//            cin >> proceed1;
//
//            if (proceed1 != 'y' && proceed1 != 'Y') {
//                break;
//            }
//
//        } while (true);
//
//    }
//
//    void displayBill(visitor v) {
//        v.setBill(totalCharges);
//        cout << "-------------------------" << endl;
//        cout << "           Bill          " << endl;
//        cout << "-------------------------" << endl;
//        cout << "Slots chosen: " << slots << endl;
//        cout << "Total charges: Rs: " << totalCharges << endl;
//    }
//    bool isSummerBookingAllowed() {
//        return summercheck;
//    }
//
//};
//class Faculty : public person {
//private:
//
//    char gender;
//    int workingHours;
//    int workingDays;
//
//public:
//    Faculty() : person() {
//
//        workingHours = 0;
//        workingDays = 0;
//    }
//
//    Faculty(const string& n, int iid, int a, char g, const string& ph, int hours, int days) : person(iid, n, a, ph) {
//        id = iid;
//        gender = g;
//        workingHours = hours;
//        workingDays = days;
//    }
//    string toString() const {
//        stringstream ss;
//        ss << name << "," << id << "," << age << "," << gender << "," << phoneNumber << "," << workingHours << "," << workingDays;
//        return ss.str();
//    }
//
//    char getGender() {
//        return gender;
//    }
//
//    int getWorkingHours() {
//        return workingHours;
//    }
//    int getWorkingDays() {
//        return workingDays;
//    }
//    int calculateSalary() {
//
//        int salaryPerDay = 100;
//        return workingDays * salaryPerDay;
//    }
//};
//class Trainer : public person {
//private:
//
//    int workingHours;
//    int workingDays;
//    char gender;
//public:
//
//    Trainer() : person() {
//
//        workingHours = 0;
//        workingDays = 0;
//    }
//
//    Trainer(const string& n, int iid, int a, char g, const string& ph, int hours, int days) : person(iid, n, a, ph) {
//        id = iid;
//        gender = g;
//        workingHours = hours;
//        workingDays = days;
//    }
//
//
//    int getWorkingHours() {
//        return workingHours;
//    }
//    char getGender() {
//        return gender;
//    }
//    int getWorkingDays() {
//        return workingDays;
//    }
//    string toString() {
//        stringstream ss;
//        ss << name << "," << id << "," << age << "," << gender << "," << phoneNumber << "," << workingHours << "," << workingDays;
//        return ss.str();
//    }
//
//    int calculateSalary() {
//
//        int salaryPerDay = 100;
//        return workingDays * salaryPerDay;
//    }
//};
//class Admin {
//private:
//    string username;
//    string password;
//    static const int MAX_FACULTY = 100; // Maximum number of faculty members
//    Faculty facultyArray[MAX_FACULTY]; // Array to store faculty members
//    int count = 0; // Counter for the number of faculty members
//    static const int MAX_TRAINERS = 100; // Maximum number of trainers
//    Trainer trainerArray[MAX_TRAINERS]; // Array to store trainers
//    int count1 = 0; // Counter for the number of trainers
//
//public:
//    // Default constructor
//    Admin() : username("admin"), password("password") {}
//
//    // Parameterized constructor
//    Admin(const string& user, const string& pass) : username(user), password(pass) {}
//
//    // Function to perform login
//    bool login(const string& n, const string& p) {
//        return (username == n && password == p);
//    }
//
//    // Function to add a faculty member
//    void addFaculty(const string& name, int id, int age, char gender, const string& phoneNumber, int hours, int days) {
//        if (count < MAX_FACULTY) {
//            facultyArray[count++] = Faculty(name, id, age, gender, phoneNumber, hours, days);
//            cout << "Faculty added: " << name << " (" << id << ", Age: " << age << ", Gender: " << gender << ", Phone: " << phoneNumber << ", Hours: " << hours << ", Days: " << days << ")" << endl;
//            updateFilef();
//        }
//        else {
//            cout << "Error: Maximum number of faculty members reached." << endl;
//        }
//    }
//
//    // Function to remove a faculty member
//    void removeFaculty(const string& name) {
//        int index = -1;
//        for (int i = 0; i < count; ++i) {
//            if (facultyArray[i].getName() == name) {
//                index = i;
//                break;
//            }
//        }
//
//        if (index != -1) {
//            for (int i = index; i < count - 1; ++i) {
//                facultyArray[i] = facultyArray[i + 1];
//            }
//            count--;
//            cout << "Faculty removed: " << name << endl;
//            updateFilef();
//        }
//        else {
//            cout << "Error: Faculty not found." << endl;
//        }
//    }
//
//    // Function to update faculty information
//    void updateFaculty(const string& name, int id, int age, char gender) {
//        int index = -1;
//        for (int i = 0; i < count; ++i) {
//            if (facultyArray[i].getName() == name) {
//                index = i;
//                break;
//            }
//        }
//
//        if (index != -1) {
//            int hours, days;
//            cout << "Enter new working hours for " << name << ": ";
//            cin >> hours;
//            cout << "Enter new working days count for " << name << ": ";
//            cin >> days;
//            facultyArray[index] = Faculty(name, id, age, gender, facultyArray[index].getPhoneNumber(), hours, days);
//            cout << "Faculty updated: " << name << " (" << id << ", Age: " << age << ", Gender: " << gender << ", Phone: " << facultyArray[index].getPhoneNumber() << ", Hours: " << hours << ", Days: " << days << ")" << endl;
//            updateFilef();
//        }
//        else {
//            cout << "Error: Faculty not found." << endl;
//        }
//    }
//
//    // Function to read faculty information from file and store in array
//    void readFacultyArray() {
//
//        count = 0;
//
//        ifstream inFile("faculty.txt");
//        if (inFile.is_open()) {
//            string line;
//            while (getline(inFile, line)) {
//                stringstream ss(line);
//                string name, phoneNumber;
//                int id;
//                int age, hours, days;
//                char gender;
//                getline(ss, name, ',');
//                cin >> id;
//                ss >> age;
//                ss.ignore(); // ignore the comma
//                ss >> gender;
//                ss.ignore(); // ignore the comma
//                getline(ss, phoneNumber, ',');
//                ss >> hours;
//                ss.ignore(); // ignore the comma
//                ss >> days;
//                if (count < MAX_FACULTY) {
//                    facultyArray[count++] = Faculty(name, id, age, gender, phoneNumber, hours, days);
//                }
//                else {
//                    cout << "Warning: Maximum number of faculty members reached. Some faculty members may not be loaded." << endl;
//                    break;
//                }
//            }
//            inFile.close();
//        }
//        else {
//            cout << "Error: Unable to open file." << endl;
//        }
//    }
//    // Function to display all faculty members
//    void displayFaculty() {
//        for (int i = 0; i < count; ++i) {
//            cout << "Name: " << facultyArray[i].getName() << ", ID: " << facultyArray[i].getId() << ", Age: " << facultyArray[i].getAge() << ", Gender: " << facultyArray[i].getGender() << ", Phone: " << facultyArray[i].getPhoneNumber() << ", Hours: " << facultyArray[i].getWorkingHours() << ", Days: " << facultyArray[i].getWorkingDays() << endl;
//        }
//    }
//
//    // Function to update faculty file
//    void updateFilef() {
//        ofstream outFile("faculty.txt");
//        if (outFile.is_open()) {
//            for (int i = 0; i < count; ++i) {
//                outFile << facultyArray[i].toString() << endl;
//            }
//            outFile.close();
//        }
//        else {
//            cout << "Error: Unable to update file." << endl;
//        }
//    }
//
//    // Function to add a trainer
//    void addTrainer(const string& name, int id, int age, char gender, const string& phoneNumber, int hours, int days) {
//        if (count1 < MAX_TRAINERS) {
//            trainerArray[count1++] = Trainer(name, id, age, gender, phoneNumber, hours, days);
//            cout << "Trainer added: " << name << " (" << id << ", Age: " << age << ", Gender: " << gender << ", Phone: " << phoneNumber << ", Hours: " << hours << ", Days: " << days << ")" << endl;
//            updateFile();
//        }
//        else {
//            cout << "Error: Maximum number of trainers reached." << endl;
//        }
//    }
//
//    // Function to remove a trainer
//    void removeTrainer(const string& name) {
//        int index = -1;
//        for (int i = 0; i < count1; ++i) {
//            if (trainerArray[i].getName() == name) {
//                index = i;
//                break;
//            }
//        }
//
//        if (index != -1) {
//            for (int i = index; i < count1 - 1; ++i) {
//                trainerArray[i] = trainerArray[i + 1];
//            }
//            count1--;
//            cout << "Trainer removed: " << name << endl;
//            updateFile();
//        }
//        else {
//            cout << "Error: Trainer not found." << endl;
//        }
//    }
//
//    // Function to update trainer information
//    void updateTrainer(const string& name, int id, int age, char gender) {
//        int index = -1;
//        for (int i = 0; i < count1; ++i) {
//            if (trainerArray[i].getName() == name) {
//                index = i;
//                break;
//            }
//        }
//
//        if (index != -1) {
//            int hours, days;
//            cout << "Enter new working hours for " << name << ": ";
//            cin >> hours;
//            cout << "Enter new working days count for " << name << ": ";
//            cin >> days;
//            trainerArray[index] = Trainer(name, id, age, gender, trainerArray[index].getPhoneNumber(), hours, days);
//            cout << "Trainer updated: " << name << " (" << id << ", Age: " << age << ", Gender: " << gender << ", Phone: " << trainerArray[index].getPhoneNumber() << ", Hours: " << hours << ", Days: " << days << ")" << endl;
//            updateFile();
//        }
//        else {
//            cout << "Error: Trainer not found." << endl;
//        }
//    }
//
//    // Function to read trainer information from file and store in array
//    void readTrainerArray() {
//        // Clear existing trainer data
//        count1 = 0;
//
//        ifstream inFile("trainers.txt");
//        if (inFile.is_open()) {
//            string line;
//            while (getline(inFile, line)) {
//                stringstream ss(line);
//                string name, phoneNumber;
//                int id;
//                int age, hours, days;
//                char gender;
//                getline(ss, name, ',');
//                cin >> id;
//                ss >> age;
//                ss.ignore(); // ignore the comma
//                ss >> gender;
//                ss.ignore(); // ignore the comma
//                getline(ss, phoneNumber, ',');
//                ss >> hours;
//                ss.ignore(); // ignore the comma
//                ss >> days;
//                if (count1 < MAX_TRAINERS) {
//                    trainerArray[count1++] = Trainer(name, id, age, gender, phoneNumber, hours, days);
//                }
//                else {
//                    cout << "Warning: Maximum number of trainers reached. Some trainers may not be loaded." << endl;
//                    break;
//                }
//            }
//            inFile.close();
//        }
//        else {
//            cout << "Error: Unable to open file." << endl;
//        }
//    }
//    // Function to display all trainers
//    void displayTrainers() {
//        for (int i = 0; i < count1; ++i) {
//            cout << "Name: " << trainerArray[i].getName() << ", ID: " << trainerArray[i].getId() << ", Age: " << trainerArray[i].getAge() << ", Gender: " << trainerArray[i].getGender() << ", Phone: " << trainerArray[i].getPhoneNumber() << ", Hours: " << trainerArray[i].getWorkingHours() << ", Days: " << trainerArray[i].getWorkingDays() << endl;
//        }
//    }
//
//    // Function to update trainer file
//    void updateFile() {
//        ofstream outFile("trainers.txt");
//        if (outFile.is_open()) {
//            for (int i = 0; i < count1; ++i) {
//                outFile << trainerArray[i].toString() << endl;
//            }
//            outFile.close();
//        }
//        else {
//            cout << "Error: Unable to update file." << endl;
//        }
//    }
//
//    // Function to calculate and display total salaries of faculty members
//    void displayFacultySalaries() {
//        cout << "Faculty Salaries:" << endl;
//        for (int i = 0; i < count; ++i) {
//
//            cout << "Name: " << facultyArray[i].getName() << ", Salary: $" << facultyArray[i].calculateSalary() << endl;
//        }
//    }
//
//    // Function to calculate and display total salaries of trainers
//    void displayTrainerSalaries() {
//        cout << "Trainer Salaries:" << endl;
//        for (int i = 0; i < count1; ++i) {
//
//            cout << "Name: " << trainerArray[i].getName() << ", Salary: $" << trainerArray[i].calculateSalary() << endl;
//        }
//    }
//};
//
//
//
//
//
//
//
//class eventt {
//protected:
//    string name[5];
//    string date[5];
//    string refreshments[7];
//    double charges[5];
//    long long int totalcharges;
//    int pnum;
//    char tchoice;
//public:
//    eventt() {
//
//    }
//    virtual void personcount() = 0;
//    virtual void ticketing() = 0;
//    virtual void chooseeventt(visitor& x) = 0;
//    virtual void finale() = 0;
//};
//class competition : public eventt {
//public:
//    competition(visitor& x) {
//        name[0] = "5 km marathon";
//        name[1] = "frisbee saga";
//        name[2] = "swimming saga";
//        name[3] = "go karting war";
//        name[4] = "horse riding";
//
//        date[0] = "June 15, 2024 at 10:00 AM";
//        date[1] = "July 20, 2024 at 8:00 AM";
//        date[2] = "August 5, 2024 at 7:30 AM";
//        date[3] = "September 10, 2024 at 9:00 AM";
//        date[4] = "October 1, 2024 at 11:00 AM";
//
//        refreshments[0] = "Lemonade";
//        refreshments[1] = "Energy bars";
//        refreshments[2] = "Iced Tea";
//        refreshments[3] = "Cold Coffee";
//        refreshments[4] = "Snacks";
//        refreshments[5] = "Sparkling Water";
//        refreshments[6] = "Smoothies";
//
//        charges[0] = 50000.0;
//        charges[1] = 60000.0;
//        charges[2] = 70000.0;
//        charges[3] = 80000.0;
//        charges[4] = 90000.0;
//
//        personcount();
//        ticketing();
//        chooseeventt(x);
//        finale();
//    }
//    void personcount() override {
//        cout << "How many persons are you bringing along: ";
//        cin >> pnum;
//        while (cin.fail() || pnum <= 0) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a positive non zero integer: ";
//            cin >> pnum;
//        }
//    }
//    void ticketing() override {
//        cout << "Would you prefer to buy:\n";
//        cout << "a. Gold ticket\n";
//        cout << "b. Silver ticket\n";
//        cout << "Press a for gold ticket and b for silver ticket.\n";
//        cin >> tchoice;
//        while (cin.fail() || (tchoice != 'a' && tchoice != 'b')) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 'a' or 'b': ";
//            cin >> tchoice;
//        }
//    }
//    void chooseeventt(visitor& x) override {
//        double refreshmentPrices[] = { 2.5, 1.5, 2.0, 3.0, 1.0, 1.2, 3.5 };
//
//        cout << "\t\t\t\tYou have following options:\n";
//        for (int i = 0; i < 5; i++) {
//            cout << i + 1 << ". " << name[i] << endl;
//        }
//
//        int choice;
//        cout << "Please choose from 1 to 5: ";
//        cin >> choice;
//        while (cin.fail() || choice < 1 || choice > 5) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 5: ";
//            cin >> choice;
//        }
//        if (choice >= 1 && choice <= 5) {
//            cout << "You have selected " << name[choice - 1] << endl;
//
//            cout << "\t\t\t\tFollowing refreshments are available:\n";
//            for (int i = 0; i < 7; i++) {
//                cout << i + 1 << ". " << refreshments[i] << endl;
//            }
//
//            double refreshmentCost = 0.0;
//            char buyAgain = 'y';
//            while (buyAgain == 'y' || buyAgain == 'Y') {
//                int buy;
//                cout << "Would you like to buy any of them? (press from 1 to 7): ";
//                cin >> buy;
//                while (cin.fail() || buy < 1 || buy > 7) {
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    cout << "Invalid input. Please enter a number between 1 and 7: ";
//                    cin >> buy;
//                }
//                if (buy >= 1 && buy <= 7) {
//                    int quantity;
//                    cout << "Enter quantity: ";
//                    cin >> quantity;
//                    while (cin.fail() || quantity <= 0 || quantity > 50) {
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                        cout << "Invalid input. Please enter a number between 1 and 50: ";
//                        cin >> quantity;
//                    }
//                    refreshmentCost += quantity * refreshmentPrices[buy - 1];
//                    cout << "You have selected: " << quantity << " " << refreshments[buy - 1] << endl;
//                    cout << "Do you want to buy more? (y/n): ";
//                    cin >> buyAgain;
//                    while (buyAgain != 'y' && buyAgain != 'Y' && buyAgain != 'n' && buyAgain != 'N') {
//                        cout << "Invalid input. Please enter 'y' or 'n': ";
//                        cin >> buyAgain;
//                    }
//                }
//                else {
//                    cout << "Invalid choice.\n";
//                    cout << "Do you want to buy again? (y/n): ";
//                    cin >> buyAgain;
//                    while (buyAgain != 'y' && buyAgain != 'Y' && buyAgain != 'n' && buyAgain != 'N') {
//                        cout << "Invalid input. Please enter 'y' or 'n': ";
//                        cin >> buyAgain;
//                    }
//                }
//            }
//            double baseCharge = charges[choice - 1];
//            double discount = 0.0;
//            if (pnum >= 5) {
//                discount = 0.1;
//            }
//            else if (pnum >= 3) {
//                discount = 0.05;
//            }
//
//            long long int totalCharges = (baseCharge * (1 - discount) * pnum) + refreshmentCost;
//
//            if (tchoice == 'a') {
//                totalCharges *= 1.2;
//            }
//            else if (tchoice == 'b') {
//                totalCharges *= 1.1;
//            }
//
//            totalcharges = totalCharges;
//            cout << "Total charges including refreshments: " << totalCharges << endl;
//            x.setBill(totalCharges);
//        }
//        else {
//            cout << "Invalid choice.\n";
//
//        }
//
//        cout << "\t\t\t\tPlease choose your preferred slot:\n";
//        for (int i = 0; i < 5; i++) {
//            cout << date[i] << endl;
//        }
//
//        int choice1;
//        cout << "Please choose from 1 to 5: ";
//        cin >> choice1;
//        while (cin.fail() || choice1 < 1 || choice1 > 5) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 5: ";
//            cin >> choice1;
//        }
//        if (choice1 >= 1 && choice1 <= 5) {
//            cout << "You have selected " << date[choice1 - 1] << endl;
//        }
//        else {
//            cout << "Invalid choice.\n";
//
//        }
//    }
//    double getTotalCharges() const {
//        return totalcharges;
//    }
//    void finale() override {
//        if (tchoice == 'a') {
//            cout << "You have been granted golden tickets.\n";
//            cout << "We most welcome you along with " << pnum << " members.\n";
//            cout << "Total charges to be paid are: " << totalcharges << endl;
//        }
//        else if (tchoice == 'b') {
//            cout << "You have been granted golden tickets.\n";
//            cout << "We most welcome you along with " << pnum << " members.\n";
//            cout << "Total charges to be paid are: " << totalcharges << endl;
//
//        }
//    }
//};
//class match : public eventt {
//public:
//    match(visitor& x) {
//        name[0] = "football match";
//        name[1] = "cricket match";
//        name[2] = "basketball match";
//        name[3] = "badminton match";
//        name[4] = "volleyball match";
//
//        date[0] = "June 11, 2024 at 10:00 AM";
//        date[1] = "July 22, 2024 at 8:00 AM";
//        date[2] = "August 15, 2024 at 7:30 AM";
//        date[3] = "September 1, 2024 at 9:00 AM";
//        date[4] = "October 19, 2024 at 11:00 AM";
//
//        charges[0] = 50000.0;
//        charges[1] = 60000.0;
//        charges[2] = 70000.0;
//        charges[3] = 80000.0;
//        charges[4] = 90000.0;
//
//        personcount();
//        ticketing();
//        chooseeventt(x);
//        finale();
//    }
//    void personcount()override {
//        cout << "How many persons are you bringing along: ";
//        cin >> pnum;
//        while (cin.fail() || pnum <= 0) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a positive integer: ";
//            cin >> pnum;
//        }
//    }
//    void ticketing()override {
//        cout << "Would you prefer to buy:\n";
//        cout << "a.Gold ticket\n";
//        cout << "b.Silver ticket\n";
//        cin >> tchoice;
//        while (cin.fail() || (tchoice != 'a' && tchoice != 'b')) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 'a' or 'b': ";
//            cin >> tchoice;
//        }
//    }
//    void chooseeventt(visitor& x) override {
//        cout << "\t\t\t\tYou have following options:\n";
//        for (int i = 0; i < 5; i++) {
//            cout << i + 1 << ". " << name[i] << endl;
//        }
//
//        int choice;
//        cout << "Please choose from 1 to 5: ";
//        cin >> choice;
//        while (cin.fail() || choice < 1 || choice > 5) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 5: ";
//            cin >> choice;
//        }
//        if (choice >= 1 && choice <= 5) {
//            cout << "You have selected " << name[choice - 1] << endl;
//            char yes;
//            cout << "For this match will you be bringing your equipment along:(y/n) ";
//            cin >> yes;
//            double extraCharge = 0; // Initialize extra charge
//
//            if (yes == 'y') {
//                cout << "No extra charges.\n";
//            }
//            else if (yes == 'n') {
//                extraCharge = 25000.0; // Assuming extra charge is $10
//                cout << "Extra charges will be charged.\n";
//            }
//            else {
//                while (cin.fail() || yes != 'y' && yes != 'n') {
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    cout << "Invalid input. Please enter y or n: ";
//                    cin >> yes;
//                }
//            }
//            // Calculate charges based on the chosen event
//            double baseCharge = charges[choice - 1]; // Get charges for the chosen event
//
//            // Apply discount based on the number of persons
//            double discount = 0.0;
//            if (pnum >= 5) {
//                discount = 0.3; // 10% discount for 5 or more persons
//            }
//            else if (pnum >= 3) {
//                discount = 0.1; // 5% discount for 3 or more persons
//            }
//
//            // Calculate total charges including extra charge
//            totalcharges = (baseCharge + extraCharge) * (1 - discount) * pnum;
//
//            // Grant the chosen ticket type
//            if (tchoice == 'a') {
//                totalcharges *= 1.1; // Increase charge for gold ticket
//            }
//            else if (tchoice == 'b') {
//                totalcharges *= 0.4; // Increase charge for silver ticket
//            }
//            x.setBill(totalcharges);
//        }
//        else {
//            cout << "Invalid choice.\n";
//        }
//
//        cout << "\t\t\t\tPlease choose your preferred slot:\n";
//        for (int i = 0; i < 5; i++) {
//            cout << date[i] << endl;
//        }
//
//        int choice1;
//        cout << "Please choose from 1 to 5: ";
//        cin >> choice1;
//        while (cin.fail() || choice1 < 1 || choice1 > 5) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 5: ";
//            cin >> choice1;
//        }
//        if (choice1 >= 1 && choice1 <= 5) {
//            cout << "You have selected " << date[choice1 - 1] << endl;
//        }
//        else {
//            cout << "Invalid choice.\n";
//        }
//    }
//    double getTotalCharges() const {
//        return totalcharges;
//    }
//    void finale()override {
//        if (tchoice == 'a') {
//            cout << "You have been granted golden tickets.\n";
//            cout << "We most welcome you along with " << pnum << " members.\n";
//            cout << "Total charges to be paid are: " << totalcharges << endl;
//        }
//        else if (tchoice == 'b') {
//            cout << "You have been granted golden tickets.\n";
//            cout << "We most welcome you along with " << pnum << " members.\n";
//            cout << "Total charges to be paid are: " << totalcharges << endl;
//        }
//    }
//};
//class trips : public eventt {
//public:
//    trips(visitor& x) {
//        name[0] = "school trip";
//        name[1] = "college trip";
//        name[2] = "aqua fiesta";
//        name[3] = "sports gala";
//        name[4] = "spring festival";
//
//        date[0] = "June 19, 2024 at 10:00 AM";
//        date[1] = "July 28, 2024 at 8:00 AM";
//        date[2] = "August 9, 2024 at 7:30 AM";
//        date[3] = "September 12, 2024 at 9:00 AM";
//        date[4] = "October 11, 2024 at 11:00 AM";
//
//        charges[0] = 50000.0;
//        charges[1] = 60000.0;
//        charges[2] = 70000.0;
//        charges[3] = 80000.0;
//        charges[4] = 90000.0;
//
//        refreshments[0] = "Lemonade";
//        refreshments[1] = "Energy bars";
//        refreshments[2] = "Iced Tea";
//        refreshments[3] = "Cold Coffee";
//        refreshments[4] = "Snacks";
//        refreshments[5] = "Sparkling Water";
//        refreshments[6] = "Smoothies";
//
//        personcount();
//        ticketing();
//        chooseeventt(x);
//        finale();
//    }
//    void personcount() override {
//        cout << "How many persons are you bringing along: ";
//        cin >> pnum;
//        while (cin.fail() || pnum <= 0) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a positive integer: ";
//            cin >> pnum;
//        }
//    }
//    void ticketing() override {
//        cout << "Would you prefer to buy:\n";
//        cout << "a. Gold ticket\n";
//        cout << "b. Silver ticket\n";
//        cin >> tchoice;
//        while (cin.fail() || (tchoice != 'a' && tchoice != 'b')) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter 'a' or 'b': ";
//            cin >> tchoice;
//        }
//    }
//    void chooseeventt(visitor& x) override {
//        double refreshmentPrices[] = { 250, 150, 200, 300, 100, 120, 350 };
//
//        cout << "\t\t\t\tYou have following options:\n";
//        for (int i = 0; i < 5; i++) {
//            cout << i + 1 << ". " << name[i] << endl;
//        }
//
//        int choice;
//        cout << "Please choose from 1 to 5: ";
//        cin >> choice;
//        while (cin.fail() || choice < 1 || choice > 5) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 5: ";
//            cin >> choice;
//        }
//        if (choice >= 1 && choice <= 5) {
//            cout << "You have selected " << name[choice - 1] << endl;
//            cout << "\t\t\t\tFollowing refreshments are available:\n";
//            for (int i = 0; i < 7; i++) {
//                cout << i + 1 << ". " << refreshments[i] << endl;
//            }
//
//            double refreshmentCost = 0.0;
//
//            char buyAgain = 'y';
//            while (buyAgain == 'y' || buyAgain == 'Y') {
//                int buy;
//                cout << "Would you like to buy any of them? (press from 1 to 7): ";
//                cin >> buy;
//                while (cin.fail() || buy < 1 || buy > 7) {
//                    cin.clear();
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                    cout << "Invalid input. Please enter a number between 1 and 7: ";
//                    cin >> buy;
//                }
//                if (buy >= 1 && buy <= 7) {
//                    int quantity;
//                    cout << "Enter quantity: ";
//                    cin >> quantity;
//                    while (cin.fail() || quantity <= 0 || quantity > 50) {
//                        cin.clear();
//                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                        cout << "Invalid input. Please enter a number between 1 and 50: ";
//                        cin >> quantity;
//                    }
//                    refreshmentCost += quantity * refreshmentPrices[buy - 1];
//                    cout << "You have selected: " << quantity << " " << refreshments[buy - 1] << endl;
//                    cout << "Do you want to buy more? (y/n): ";
//                    cin >> buyAgain;
//                    while (buyAgain != 'y' && buyAgain != 'Y' && buyAgain != 'n' && buyAgain != 'N') {
//                        cout << "Invalid input. Please enter 'y' or 'n': ";
//                        cin >> buyAgain;
//                    }
//                }
//                else {
//                    cout << "Invalid choice.\n";
//                    cout << "Do you want to buy again? (y/n): ";
//                    cin >> buyAgain;
//                    while (buyAgain != 'y' && buyAgain != 'Y' && buyAgain != 'n' && buyAgain != 'N') {
//                        cout << "Invalid input. Please enter 'y' or 'n': ";
//                        cin >> buyAgain;
//                    }
//                }
//            }
//            double baseCharge = charges[choice - 1];
//            double discount = 0.0;
//            if (pnum >= 5) {
//                discount = 0.1;
//            }
//            else if (pnum >= 3) {
//                discount = 0.05;
//            }
//
//            long long int totalCharges = (baseCharge * (1 - discount) * pnum) + refreshmentCost;
//
//            if (tchoice == 'a') {
//                totalCharges *= 1.2;
//            }
//            else if (tchoice == 'b') {
//                totalCharges *= 1.1;
//            }
//
//            totalcharges = totalCharges;
//
//            cout << "Total charges including refreshments: " << totalCharges << endl;
//            x.setBill(totalcharges);
//        }
//        else {
//            cout << "Invalid choice.\n";
//        }
//
//        cout << "\t\t\t\tPlease choose your preferred slot:\n";
//        for (int i = 0; i < 5; i++) {
//            cout << date[i] << endl;
//        }
//
//        int choice1;
//        cout << "Please choose from 1 to 5: ";
//        cin >> choice1;
//        while (cin.fail() || choice1 < 1 || choice1 > 7) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 7: ";
//            cin >> choice1;
//        }
//        if (choice1 >= 1 && choice1 <= 5) {
//            cout << "You have selected " << date[choice1 - 1] << endl;
//        }
//        else {
//            cout << "Invalid choice.\n";
//        }
//
//    }
//    double getTotalCharges() const {
//        return totalcharges;
//    }
//    void finale() override {
//        if (tchoice == 'a') {
//            cout << "You have been granted golden tickets.\n";
//            cout << "We most welcome you along with " << pnum << " members.\n";
//            cout << "Total charges to be paid are: " << totalcharges << endl;
//        }
//        else if (tchoice == 'b') {
//            cout << "You have been granted golden tickets.\n";
//            cout << "We most welcome you along with " << pnum << " members.\n";
//            cout << "Total charges to be paid are: " << totalcharges << endl;
//        }
//    }
//};
//
//
//
//
//int main() {
//    int choice = 0;
//    cout << "enter 1 for visitor and 2 for admin" << endl;
//    cin >> choice;
//    if (choice == 1) {
//        int c;
//        cout << "Enter your choice (1 or 2): ";
//        cin >> c;
//        sqlite3* db;
//        if (c == 1) {
//
//            int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//            if (rc) {
//                cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << endl;
//                sqlite3_close(db);
//                return 1;
//            }
//            cout << "Opened database successfully" << endl;
//
//            char* errMsg = nullptr;
//            const char* createTableSQL = "CREATE TABLE IF NOT EXISTS visitors ("
//                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//                "name TEXT NOT NULL,"
//                "age INTEGER,"
//                "phone_number TEXT,"
//                "bill REAL"
//                ");";
//            rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
//            if (rc != SQLITE_OK) {
//                cerr << "Error creating table: " << errMsg << endl;
//                sqlite3_free(errMsg);
//                sqlite3_close(db);
//                return 1;
//            }
//            else {
//                cout << "Table created successfully" << endl;
//            }
//            char addNewVisitor;
//            cout << "Do you want to add a new visitor? (y/n): ";
//            cin >> addNewVisitor;
//
//            if (addNewVisitor == 'y' || addNewVisitor == 'Y') {
//                string name, phone_number;
//                int age;
//                cout << "Enter name: ";
//                cin.ignore();
//                getline(cin, name);
//                cout << "Enter age: ";
//                cin >> age;
//                cout << "Enter phone number: ";
//                cin.ignore();
//
//                getline(cin, phone_number);
//
//
//                string insertVisitorSQL = "INSERT INTO visitors (name, age, phone_number) "
//                    "VALUES ('" + name + "', " + to_string(age) + ", '" + phone_number + "');";
//
//                rc = sqlite3_exec(db, insertVisitorSQL.c_str(), nullptr, nullptr, &errMsg);
//                if (rc != SQLITE_OK) {
//                    cerr << "Error inserting visitor: " << errMsg << endl;
//                    sqlite3_free(errMsg);
//                    sqlite3_close(db);
//                    return 1;
//                }
//                else {
//                    cout << "New visitor added successfully" << endl;
//                }
//            }
//            visitor visitors[5] = {
//                            visitor(12,"John Doe", 23, "23-456-7890"),
//                            visitor(1, "Jane Smith", 9, "87-654-3210"),
//                            visitor(3,"Michael Johnson", 5, "5-555-5555"),
//                            visitor(4, "Emily Davis", 7, "7-888-9999"),
//                            visitor(5,"David Brown", 4, "4-333-2222")
//            };
//
//            int visitorID;
//            cout << "Enter your visitor ID (1-5): ";
//            cin >> visitorID;
//
//
//            cout << "Choose an activity:" << endl;
//            cout << "1. BOATING" << endl;
//            cout << "2. Horse Riding" << endl;
//            cout << "3. Indoor Arcade" << endl;
//            cout << "4. Swimming" << endl;
//            cout << "5. GYM" << endl;
//            cout << "6. GO KARTING" << endl;
//            cout << "7. RUNNING TRACK" << endl;
//            int activityChoice;
//            cout << "Enter the number of the activity you want to perform: ";
//            cin >> activityChoice;
//
//            switch (activityChoice) {
//            case 1: {
//                BoatingActivity boat(visitors[visitorID - 1]);
//                visitors[visitorID - 1].setBill(boat.getTotalCharge());
//
//
//                break;
//            }
//            case 2: {
//                HorseRidingActivity horseRiding(visitors[visitorID - 1]);
//#include <iostream>
//#include<cctype>
//#include"person.cpp"
//#include <sqlite3.h>
//#include <string>
//#include <iomanip>
//#include<fstream>
//#include<sstream>
//                template <class visitor>
//                int SIZE = 0;
//                using namespace std;
//                int count(sqlite3 * db) {
//                    sqlite3_stmt* stmt;
//                    const char* countSQL = "SELECT COUNT(*) FROM visitors;";
//                    int counter = 0;
//
//                    if (sqlite3_prepare_v2(db, countSQL, -1, &stmt, nullptr) != SQLITE_OK) {
//                        cerr << "Error preparing count query: " << sqlite3_errmsg(db) << endl;
//                        return -1;
//                    }
//
//                    if (sqlite3_step(stmt) == SQLITE_ROW) {
//                        counter = sqlite3_column_int(stmt, 0);
//                    }
//
//                    sqlite3_finalize(stmt);
//
//                    return counter;
//                }
//                class visitor :public person {
//                    double bill;
//
//
//                public:
//                    visitor() {
//                        bill = 0;
//                    }
//                    visitor(int i, string na, int a, string nu) :person(i, na, a, nu)
//                    {
//
//                    }
//                    void setBill(double x
//                    ) {
//                        bill = x;
//                    }
//                    double getBill() const { return bill; }
//
//                    void saveToDatabase(sqlite3* db) {
//                        string sql = "insert into table (name , age , phone number,  bill) VALUES (? , ? , ? , ?)";
//                        sqlite3_stmt* stmt;
//                        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
//                            sqlite3_bind_text(stmt, 1, getName().c_str(), -1, SQLITE_STATIC);
//                            sqlite3_bind_int(stmt, 2, getAge());
//                            sqlite3_bind_text(stmt, 3, getPhoneNumber().c_str(), -1, SQLITE_STATIC);
//                            sqlite3_bind_double(stmt, 4, getBill());
//                            sqlite3_step(stmt);
//                            sqlite3_finalize(stmt);
//                        }
//                    }
//
//
//                };
//                class gokarting {
//
//                    int age;
//                    double charge;
//                    string optype;
//                    string ktype;
//                    string timeslot[3];
//                    double kit;
//                    string seltime;
//                public:
//                    gokarting(visitor& x) {
//                        age = 0;
//                        charge = 0;
//                        double round = 1000;
//                        double typecharge[3] = { 0,1000,1500 };
//                        kit = 1500;
//                        timeslot[0] = "8:00-10:00 AM(MORNING)";
//                        timeslot[1] = "12:00-2:00 PM (AFTERNOON)";
//                        timeslot[2] = "6:00-8:00 PM  (NIGHT)";
//                        char choice;
//                        cout << "DO YOU WANT TO MAKE AN INDIVIDUAL BOOKING OR GROUP BOOKING" << endl;
//                        cout << "PRESS I FOR INDIVIDUAL AND G FOR GROUP BOOKING" << endl;
//                        cin >> choice;
//                        while (cin.fail() || choice != 'I' && choice != 'G') {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 'I' or 'G': ";
//                            cin >> choice;
//                        }
//                        if (choice == 'I' || choice == 'i') {
//                            indi();
//                        }
//                        else if (choice == 'G' || choice == 'g') {
//                            group();
//
//                        }
//                        else {
//                            cout << "ENTER VALID CHOICE" << endl;
//                        }
//                        selectage();
//                        selecttime();
//                        selectkart();
//                        selectkit();
//                        display(x);
//                    }
//                    void indi() {
//                        cout << " HOW MANY ROUNS WILL YOU LIKE (max 10 rounds)" << endl;
//                        int round;
//                        cin >> round;
//                        while (cin.fail() || round <= 0 || round > 10) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 10: ";
//                            cin >> round;
//                        }
//                        charge = round * 1000;
//                    }
//                    void selectage() {
//                        int age;
//                        cout << "ENTER YOUR AGE PLEASE" << endl;
//                        cin >> age;
//                        while (cin.fail() || age <= 0 || age < 15) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input.You are not eligible for GOKARTING. ";
//                            exit(0);
//                        }
//                        if (age >= 16 && age <= 60) {
//
//                            cout << "You are eligible.  Cant wait to have you" << endl;
//
//                        }
//                        else if (age > 60 && age < 100) {
//                            cout << "YOU WILL GWT 20% OFF DUE TO SENIOR CITIZENSHIP" << endl;
//                            charge *= 0.8;
//                        }
//                    }
//                    void selecttime() {
//                        bool flag = false;
//                        cout << "CHOOSE TIME SLOT  " << endl;
//                        int choose;
//                        cin >> choose;
//                        while (cin.fail() || choose <= 0 || choose > 3) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input.Please enter a number between 1 and 3: ";
//                            cin >> choose;
//                        }
//                        for (int i = 0; i < 3; i++) {
//
//                            cout << i + 1 << " )" << timeslot[i] << endl;
//
//
//                        }
//                        do {
//                            cout << " Enter your choice please" << endl;
//                            cin >> choose;
//                            while (cin.fail() || choose <= 0 || choose > 3) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input.Please enter a number between 1 and 3: ";
//                                cin >> choose;
//                            }
//                            if (choose >= 1 && choose <= 3) {
//
//
//                                cout << " YOU CHOSE" << "  " << timeslot[choose - 1] << endl;
//                                seltime = timeslot[choose - 1];
//                                flag = true;
//                            }
//                            else {
//                                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//                            }
//
//                        } while (!flag);
//                    }
//                    string gettype(int choose) {
//
//                        switch (choose)
//                        {
//                        case 1:
//                            return "Regular Kart";
//
//                        case 2:
//                            return "Turbo Kart";
//                        case 3:
//                            return "Super Kart";
//                        }
//
//
//
//
//                    }
//                    void selectkart() {
//
//                        cout << "CHOOSE THE TYPE OF KART YOU WANT" << endl;
//
//                        cout << " 1)   :REGULAR KART " << endl;
//                        cout << " 2)   :TURBO KART       " << endl;
//                        cout << " 3)   : SUPER KART       " << endl;
//                        int choose;
//                        do {
//                            cout << " Enter your choice please" << endl;
//                            cin >> choose;
//                            while (cin.fail() || choose <= 0 || choose > 3) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input.Please enter a number from 1 to 3: ";
//                                cin >> choose;
//                            }
//                            if (choose >= 1 && choose <= 3) {
//
//
//                                cout << " YOU CHOSE" << " " << choose << endl;
//                                charge += (choose - 1) * 500;
//
//                                ktype = gettype(choose);
//                                break;
//                            }
//                            else {
//                                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//                            }
//                        } while (true);
//
//                    }
//                    void selectkit() {
//
//                        cout << "GOKARTING KIT IS NECESSARY EITHER BRING YOUR OWN OR YOU CAN RENT IT FOR RS.1000" << endl;
//                        char choice;
//                        cout << "ENTER Y IF YOU WANT TO RENT IT AND N IF YOU CAN BRING YOUR OWN" << endl;
//                        cin >> choice;
//                        while (cin.fail() || choice != 'y' && choice != 'Y') {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input.Please enter 'y' or 'Y': ";
//                            cin >> choice;
//                        }
//                        if (choice == 'Y' || choice == 'y') {
//
//                            charge += kit;
//                            cout << "KIT RENTED" << endl;;
//                        }
//                        else {
//                            cout << "KIT NOT RENTED" << endl;
//                        }
//
//                    }
//                    void group() {
//                        int size;
//                        cout << "ENTER YOUR GROUP SIZE(max 5)" << endl;
//                        cin >> size;
//                        while (cin.fail() || size <= 0 || size > 5) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input.Please enter the size between 1 and 5: ";
//                            cin >> size;
//                        }
//                        for (int i = 0; i < size; i++) {
//
//                            cout << "kart" << " " << i + 1 << endl;
//                            indi();
//                        }
//                    }
//                    void display(visitor& x) {
//                        cout << "VISIT TYPE:" << " " << optype << endl;;
//                        cout << " KART TYPE:" << " " << ktype << endl;
//                        cout << " TIMESLOT" << "" << seltime << endl;
//                        x.setBill(charge);
//                        cout << " TOTAL CHARGE:" << fixed << setprecision(2) << " " << charge << endl;
//                    }
//                };
//
//                class runningtrack {
//                    char basicchoice;
//                    char gender;
//                    int age;
//                    char mehour;
//                    int km[4];
//                    string fhour;
//                    string track[5];
//                    string refreshment[4];
//                    double rcharges[4];
//                public:
//                    runningtrack(visitor& x) {
//                        cout << "Please enter your age: ";
//                        cin >> age;
//                        while (cin.fail() || age <= 0) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a positive non zero integer: ";
//                            cin >> age;
//                        }
//                        cout << "\t\t\t\tWould you like to join us for:\n";
//                        cout << "a.Walking.\n";
//                        cout << "b.Jogging.\n";
//                        cout << "Press a or b: ";
//                        cin >> basicchoice;
//                        while (cin.fail() || basicchoice != 'a' && basicchoice != 'b') {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 'a' or 'b' ";
//                            cin >> basicchoice;
//                        }
//                        cout << "Please select your gender:\n";
//                        cout << "Female\n";
//                        cout << "Male\n";
//                        cout << "Press f or m: ";
//                        cin >> gender;
//                        while (cin.fail() || gender != 'f' && gender != 'm') {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 'f' or 'm' ";
//                            cin >> gender;
//                        }
//                        cout << "Would you prefer morning or evening walking/jogging:\n";
//                        cout << "a.morning\n";
//                        cout << "b.evening\n";
//                        cin >> mehour;
//                        while (cin.fail() || mehour != 'a' && mehour != 'b') {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 'a' or 'b' ";
//                            cin >> mehour;
//                        }
//                        if ((basicchoice == 'a' || basicchoice == 'b') && gender == 'f' && mehour == 'a') {
//                            fhour = "5 am to 6 am";
//                        }
//                        else if ((basicchoice == 'a' || basicchoice == 'b') && gender == 'f' && mehour == 'b') {
//                            fhour = "5 pm to 6 pm";
//                        }
//                        else if ((basicchoice == 'a' || basicchoice == 'b') && gender == 'm' && mehour == 'a') {
//                            fhour = "6 am to 7 am";
//                        }
//                        else if ((basicchoice == 'a' || basicchoice == 'b') && gender == 'm' && mehour == 'b') {
//                            fhour = "6 pm to 7 pm";
//                        }
//                        kmtrack(x);
//                        monthlybooking(x);
//                    }
//                    void kmtrack(visitor& x) {
//                        cout << "\t\t\t\tWhat kind of track would you prefer:\n";
//                        track[0] = "Sand Track";
//                        track[1] = "Grass Track";
//                        track[2] = "Fitness Trail";
//                        track[3] = "Sprint Track";
//                        track[4] = "Paved Track";
//                        for (int i = 0; i < 5; i++) {
//                            cout << track[i] << endl;
//                        }
//                        int c;
//                        cout << "Please enter your choice (1-5): ";
//                        cin >> c;
//                        while (cin.fail() || c < 1 || c>5) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 5: ";
//                            cin >> c;
//                        }
//                        if (c >= 1 && c <= 5) {
//                            cout << "You have selected " << track[c - 1] << " track" << endl;
//                        }
//                        else {
//                            cout << "Invalid option.";
//                        }
//                        cout << "How many km track would you prefer:\n";
//                        km[0] = 1;
//                        km[1] = 2;
//                        km[2] = 3;
//                        km[3] = 4;
//                        for (int i = 0; i < 4; i++) {
//                            cout << km[i] << endl;
//                        }
//                        int c1;
//                        cout << "Please enter your choice (1-4): ";
//                        cin >> c1;
//                        while (cin.fail() || c1 < 1 || c1>4) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 4 ";
//                            cin >> c1;
//                        }
//                        if (c1 >= 1 && c1 <= 4) {
//                            cout << "You have selected " << km[c1 - 1] << " km track.\n";
//                        }
//                        else {
//                            cout << "Invalid option.";
//                        }
//                    }
//                    void monthlybooking(visitor& x) {
//                        int c;
//                        cout << "\t\t\t\tWould you like to prefer booking at us for:\n ";
//                        cout << "Press 1 2 3:\n";
//                        cout << "1.a week\n";
//                        cout << "2.a month\n";
//                        cout << "3.selective number of days\n";
//                        cin >> c;
//                        while (cin.fail() || c < 1 || c>3) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 1 or 2 or 3 ";
//                            cin >> c;
//                        }
//                        double totalcharges = 0.0;
//                        if (c == 1) {
//                            totalcharges = 3500;
//                        }
//                        else if (c == 2) {
//                            totalcharges = 15000;
//                        }
//                        else if (c == 3) {
//                            int d;
//                            cout << "For how many days you want to join us: ";
//                            cin >> d;
//                            while (cin.fail() || d <= 0) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a non zero integer: ";
//                                cin >> d;
//                            }
//                            totalcharges = 700 * d;
//                        }
//                        cout << "Your current bill is: " << totalcharges << endl;
//                        cout << "Would you prefer to book any refreshments:\n";
//                        refreshment[0] = "Waterbottle";
//                        refreshment[1] = "Energy Bars";
//                        refreshment[2] = "Chilled Lemonade";
//                        refreshment[3] = "Tea or coffee";
//                        rcharges[0] = 120;
//                        rcharges[1] = 250;
//                        rcharges[2] = 300;
//                        rcharges[3] = 200;
//                        for (int i = 0; i < 4; i++) {
//                            cout << i + 1 << " " << refreshment[i] << " Rs: " << rcharges[i] << endl;
//                        }
//                        int c1;
//                        cout << "Please enter your choice (1-4): ";
//                        cin >> c1;
//                        while (cin.fail() || c1 < 1 || c1>4) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please entera number between 1 and 4: ";
//                            cin >> c1;
//                        }
//                        if (c1 >= 1 && c1 <= 4) {
//                            totalcharges += rcharges[c1 - 1];
//                            cout << "You have selected " << refreshment[c1 - 1] << endl;
//                        }
//                        else {
//                            cout << "Invalid option.";
//                        }
//                        x.setBill(totalcharges);
//                        cout << "Your chosen slot is: " << fhour << endl;
//                        cout << "Your total bill is: " << totalcharges << endl;
//                        cout << "Happy Walking" << endl;
//                    }
//                };
//                class gym
//                {
//                    int age;
//                    double charge;
//                    string opttype;
//                    string wtype;
//                    string tname;
//                    string ttype;
//                    string opt[2];
//                    double opttypecharge[2];
//                    string workout[3];
//                    double workoutcharge[3];
//                    string trainer[3][3];
//                    double trianercharge[3][3];
//                    string timeslot[3];
//                    bool summer;
//                public:
//                    gym(visitor& x) {
//
//                        charge = 0.0;
//                        opttypecharge[0] = 5500;
//                        opttypecharge[1] = 500;
//                        workoutcharge[0] = 0;
//                        workoutcharge[1] = 500;
//                        workoutcharge[2] = 1000;
//                        trainer[0][0] = "john slayer";
//                        trainer[0][1] = "material gurl";
//                        trainer[0][2] = "anita maxvynn";
//                        trainer[1][0] = "ho lee shyt";
//                        trainer[1][1] = "say my name";
//                        trainer[1][2] = "Kaalmi Maibi";
//                        trainer[2][0] = "Crystal Metheeny";
//                        trainer[2][1] = "Dam soun";
//                        trainer[2][2] = "prachi gram ar";
//
//
//                        timeslot[0] = "8:00-10:00 AM(MORNING)";
//                        timeslot[1] = "12:00-2:00 PM (AFTERNOON)";
//                        timeslot[2] = "6:00-8:00 PM  (NIGHT)    ";
//                        cout << "WELCOME TO OUR GYM" << endl;
//                        cout << " Choose one option for your booking please" << endl;
//                        cout << " 1:   MONTHLY MEMBERSHIP  (RS.5500 only)" << endl;
//                        cout << " 2:    ONETIME VISIT        (RS.500 only)" << endl;
//                        int choose;
//                        do {
//                            cout << " Enter your choice please" << endl;
//                            cin >> choose;
//                            while (cin.fail() || choose <= 0 || choose > 2) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a positive non zero integer between 1 and 2: ";
//                                cin >> choose;
//                            }
//                            if (choose == 1 || choose == 2) {
//
//
//                                cout << " YOU CHOSE" << " " << choose << endl;
//                                charge = opttypecharge[choose - 1];
//                                break;
//                            }
//                            else {
//                                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//                            }
//                        }
//
//
//                        while (true);
//
//                        selectage();
//                        selectworkout();
//                        selecttrainer();
//                        selecttime();
//                        display(x);
//                    }
//                    void selectage() {
//                        int age;
//                        cout << "ENTER YOUR AGE PLEASE" << endl;
//                        cin >> age;
//                        while (cin.fail() || age <= 0 || age < 16) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input.You are not eligble for GYM please explore other activities: ";
//                            cin >> age;
//                        }
//                        if (age >= 16 && age <= 60) {
//
//                            cout << "You are eligble.  Cant wait to have you" << endl;
//
//                        }
//                        else if (age > 60 && age < 100) {
//                            cout << "YOU WILL GWT 20% OFF DUE TO SENIOR CITIZENSHIP" << endl;
//                            charge *= 0.8;
//                        }
//                    }
//                    void selectworkout() {
//
//                        cout << "CHOOSE THE TYPE OF WORKOUT YOU WANT" << endl;
//
//                        cout << " 1)   : WEIGHTLIFTING " << endl;
//                        cout << " 2)   : CARDIO        " << endl;
//                        cout << " 3 )  : YOGA       " << endl;
//                        int choose;
//                        do {
//                            cout << " Enter your choice please" << endl;
//                            cin >> choose;
//                            while (cin.fail() || choose <= 0 || choose > 3) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a number between 1 and 3:  ";
//                                cin >> choose;
//                            }
//                            if (choose >= 1 && choose <= 3) {
//
//
//                                cout << " YOU CHOSE" << " " << choose << endl;
//                                charge = workoutcharge[choose - 1];
//
//                                wtype = gettype(choose);
//                                break;
//                            }
//                            else {
//                                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//                            }
//                        }
//
//
//                        while (true);
//
//
//                    }
//                    string gettype(int choose) {
//
//                        switch (choose)
//                        {
//                        case 1:
//                            return "Heavylifting";
//
//                        case 2:
//                            return "Cardio";
//                        case 3:
//                            return "Yoga";
//                        }
//
//
//
//
//                    }
//                    string getname(string type, int ind) {
//
//                        if (type == "Heavylifting") {
//                            return "Heavylifting Trainer";
//                        }
//                        else	if (type == "Cardio") {
//                            return "Cardio Trainer";
//                        }
//                        else if (type == "Yoga") {
//                            return "Yoga Trainer";
//                        }
//                        else {
//                            return "";
//                        }
//                    }
//                    int getind(string type) {
//                        if (type == "Heavylifting") {
//                            return 0;
//                        }
//                        else	if (type == "Cardio") {
//                            return 1;
//                        }
//                        else if (type == "Yoga") {
//                            return 2;
//                        }
//                        else {
//                            return -1;
//                        }
//
//                    }
//                    void selecttrainer() {
//                        cout << "CHOOSE TRAINER FOR " << "  " << wtype << endl;
//                        int choice;
//                        for (int i = 0; i < 3; i++) {
//
//                            cout << i + 1 << "  ) " << trainer[getind(wtype)][i] << endl;
//
//
//                        }
//                        do {
//
//                            cout << "ENTER YOUR CHOICE" << endl;
//                            cin >> choice;
//                            while (cin.fail() || choice < 1 || choice>3) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a number between 1 and 3: ";
//                                cin >> choice;
//                            }
//                            if (choice >= 1 && choice <= 3) {
//
//
//                                cout << "You selected" << " " << trainer[getind(wtype)][choice - 1] << endl;
//
//
//                                tname = trainer[getind(wtype)][choice - 1];
//                                ttype = getname(wtype, choice - 1);
//                                break;
//                            }
//                            else {
//                                cout << "invalid choice" << endl;
//                            }
//                        } while (true);
//                    }
//                    void selecttime() {
//                        bool flag = false;
//                        cout << "CHOOSE TIME SLOT  " << endl;
//                        int choose;
//                        for (int i = 0; i < 3; i++) {
//
//                            cout << i + 1 << timeslot[i] << endl;
//
//
//                        }
//                        do {
//                            cout << " Enter your choice please" << endl;
//                            cin >> choose;
//                            while (cin.fail() || choose < 1 || choose>3) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input.Please enter a number between 1 and 3: ";
//                                cin >> choose;
//                            }
//                            if (choose >= 1 && choose <= 3) {
//
//
//                                cout << " YOU CHOSE" << "  " << timeslot[choose - 1] << endl;
//                                flag = true;
//                            }
//                            else {
//                                cout << "PLEASE ENTER A VALID CHOICE" << endl;
//                            }
//
//                        } while (!flag);
//                    }
//                    void display(visitor& x) {
//                        x.setBill(charge);
//
//                        cout << "VISIT TYPE:" << " " << opttype << endl;;
//                        cout << " WORKOUT TYPE:" << " " << wtype << endl;
//                        cout << " TRAINER: " << " " << tname << endl;
//                        cout << " TOTAL CHARGE:" << fixed << setprecision(2) << " " << charge << endl;
//
//                    }
//                };
//
//                class Cafeteria {
//                private:
//                    string menuNames[50];
//                    int menuQuantities[50];
//                    double menuPrices[50];
//                    int itemCount;
//                    string orderHistory[100];
//                    int orderCount;
//                    double totalBill;
//                public:
//                    Cafeteria(visitor& x) {
//                        itemCount = 0;
//                        orderCount = 0;
//                        totalBill = 0.0;
//                        addItem("Coffee", 10, 2.5);
//                        addItem("Sandwich", 20, 5.0);
//                        addItem("Salad", 15, 7.5);
//                        addItem("zinger shawarma", 30, 100);
//                        addItem("Biryani", 40, 150);
//                        addItem("Pasta", 15, 200);
//                        displayMenu();
//                        placeOrder();
//                        printIndividualBills();
//                        showBill(x);
//                    }
//
//                    void addItem(string name, int quantity, double price) {
//
//                        menuNames[itemCount] = name;
//                        menuQuantities[itemCount] = quantity;
//                        menuPrices[itemCount] = price;
//                        itemCount++;
//                    }
//
//                    void displayMenu() {
//                        cout << "\n";
//                        cout << "                 Cafeteria Menu    \n";
//                        cout << "\n";
//
//                        cout << setw(4) << left << "No." << setw(20) << left << "Item" << setw(15) << left << "Quantity" << setw(10) << "Price" << endl;
//                        cout << "---------------------------------------------\n";
//
//                        for (int i = 0; i < itemCount; ++i) {
//                            cout << setw(4) << left << i + 1
//                                << setw(20) << left << menuNames[i]
//                                << setw(15) << left << menuQuantities[i]
//                                << "$" << setw(9) << fixed << setprecision(2) << menuPrices[i] << endl;
//                        }
//                    }
//                    void placeOrder() {
//                        int index = 0;
//                        while (index != -1) {
//                            cout << "Enter the index of the item you want to buy. Press -1 if you are done buying: ";
//                            cin >> index;
//                            if (cin.fail()) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input." << endl;
//                                continue;
//                            }
//                            if (index == -1) {
//                                break;
//                            }
//                            if (index >= 1 && index <= itemCount) {
//                                cout << "Enter quantity: ";
//                                int quantity;
//                                cin >> quantity;
//                                if (cin.fail() || quantity <= 0) {
//                                    cin.clear();
//                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                    cout << "Invalid quantity. Please enter a positive integer.";
//                                    cin >> quantity;
//                                }
//                                if (quantity > menuQuantities[index - 1]) {
//                                    cout << "Insufficient quantity in inventory!" << endl;
//                                    continue;
//                                }
//                                // If the quantity is valid and sufficient
//                                menuQuantities[index - 1] -= quantity;
//                                totalBill += quantity * menuPrices[index - 1];
//                                orderHistory[orderCount++] = menuNames[index - 1] + " x" + to_string(quantity);
//                                cout << "Order placed successfully!" << endl;
//                            }
//                            else if (index != -1) {
//                                cout << "Invalid item index!" << endl;
//                            }
//                        }
//                    }
//                    void printIndividualBills() {
//                        cout << "\n";
//                        cout << "      Order Bill      \n";
//                        cout << "\n";
//
//                        cout << setw(20) << left << "Item" << setw(10) << "Quantity" << setw(10) << "Price" << setw(10) << "Total" << endl;
//                        cout << "---------------------------------------------\n";
//
//                        for (int i = 0; i < orderCount; ++i) {
//
//                            int itemIndex = -1;
//                            for (int j = 0; j < itemCount; ++j) {
//                                int k = 0;
//                                while (k < orderHistory[i].length() && k < menuNames[j].length()) {
//                                    if (orderHistory[i][k] != menuNames[j][k]) {
//                                        break;
//                                    }
//                                    k++;
//                                }
//                                if (k == orderHistory[i].find('x') - 1) {
//                                    itemIndex = j;
//                                    break;
//                                }
//                            }
//
//                            double itemPrice = menuPrices[itemIndex];
//
//                            int quantity = 0;
//                            bool foundX = false;
//                            for (int k = 0; k < orderHistory[i].length(); ++k) {
//                                char c = orderHistory[i][k];
//                                if (isdigit(c) && foundX) {
//                                    quantity = quantity * 10 + (c - '0');
//                                }
//                                else if (c == 'x') {
//                                    foundX = true;
//                                }
//                            }
//
//
//                            double total = quantity * itemPrice;
//
//                            cout << setw(20) << left << orderHistory[i].substr(0, orderHistory[i].find('x') - 1)
//                                << setw(10) << quantity
//                                << "$" << setw(9) << fixed << setprecision(2) << itemPrice
//                                << "$" << setw(9) << fixed << setprecision(2) << total << endl;
//                        }
//
//
//                        cout << "---------------------------------------------\n";
//                    }
//                    int findItemIndex(string itemName) {
//                        for (int i = 0; i < itemCount; ++i) {
//                            int j = 0;
//                            while (j < itemName.length() && j < menuNames[i].length()) {
//                                if (itemName[j] != menuNames[i][j]) {
//                                    break;
//                                }
//                                j++;
//                            }
//                            if (j == itemName.find('x') - 1) {
//                                return i;
//                            }
//                        }
//                        return -1;
//                    }
//
//
//
//                    void showBill(visitor& x) {
//                        x.setBill(totalBill);
//                        cout << "Total Bill: $" << totalBill << endl;
//                    }
//
//                };
//                class HorseRidingActivity {
//                private:
//                    string horsesName[100];
//                    string horsesBreed[100];
//                    string timeSlots[100];
//                    string instructors[100];
//                    double horseCharges[100];
//                    int numHorses;
//                    int numTimeSlots;
//                    int numInstructors;
//                    string selectedHorse;
//                    string selectedInstructor;
//                    string selectedTimeSlot;
//                    double totalCharge;
//
//                public:
//                    HorseRidingActivity(visitor& x) {
//
//                        numHorses = 5;
//                        horsesName[1] = "Maiza";
//                        horsesName[2] = "Ushna";
//                        horsesName[3] = "Charlie";
//                        horsesName[4] = "Bella";
//                        horsesName[5] = "Max";
//
//                        horsesBreed[1] = "Maham";
//                        horsesBreed[2] = "Dar";
//                        horsesBreed[3] = "Arabian";
//                        horsesBreed[4] = "Thoroughbred";
//                        horsesBreed[5] = "Shetland";
//
//                        horseCharges[1] = 25.0;
//                        horseCharges[2] = 30.0;
//                        horseCharges[3] = 20.0;
//                        horseCharges[4] = 35.0;
//                        horseCharges[5] = 40.0;
//
//
//                        numTimeSlots = 4;
//                        timeSlots[1] = "9 to 12";
//                        timeSlots[2] = "12 to 3";
//                        timeSlots[3] = "3 to 6";
//                        timeSlots[4] = "6 to 9";
//
//                        numInstructors = 5;
//                        instructors[1] = "Meta AI";
//                        instructors[2] = "ABCD";
//                        instructors[3] = "Nobita";
//                        instructors[4] = "Meow";
//                        instructors[5] = "Billu";
//
//                        if (takeInfo()) {
//                            showHorses();
//
//                            int horseIndex, timeSlotIndex;
//                            cout << "Enter the number of the horse you want: ";
//                            cin >> horseIndex;
//                            while (cin.fail() || horseIndex <= 0 || horseIndex > 5) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a positive non zero integer: ";
//                                cin >> horseIndex;
//                            }
//                            selectHorse(horseIndex);
//
//                            showInstructors();
//
//                            int instructorIndex;
//                            cout << "Enter the number of the instructor you want: ";
//                            cin >> instructorIndex;
//                            while (cin.fail() || instructorIndex <= 0 || instructorIndex > 5) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a positive non zero integer: ";
//                                cin >> instructorIndex;
//                            }
//                            selectInstructor(instructorIndex);
//
//                            displayTimeSlots();
//                            cout << "Enter index of time slot: ";
//                            cin >> timeSlotIndex;
//                            while (cin.fail() || timeSlotIndex <= 0 || timeSlotIndex > 4) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a positive non zero integer: ";
//                                cin >> timeSlotIndex;
//                            }
//                            selectTimeSlot(timeSlotIndex);
//
//                            double totalCharge = calculateTotalCharge(x);
//
//                            cout << "\n\n-------------------------" << endl;
//                            cout << "    YOUR RECEIPT" << endl;
//                            cout << "-------------------------" << endl;
//                            cout << "Horse: " << getSelectedHorse() << endl;
//                            cout << "Instructor: " << getSelectedInstructor() << endl;
//                            cout << "Time Slot: " << getSelectedTimeSlot() << endl;
//                            cout << "Total Charges: $" << totalCharge << endl;
//                        }
//                    }
//
//                    bool takeInfo() {
//                        int age;
//
//                        cout << "Enter your age: ";
//                        cin >> age;
//                        while (cin.fail() || age <= 0) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a positive non zero integer: ";
//                            cin >> age;
//                        }
//                        if (age <= 3) {
//                            cout << "Go to play area." << endl;
//                            return false;
//                        }
//                        else {
//                            cout << "You can participate in horse riding." << endl;
//                            return true;
//                        }
//                    }
//
//
//                    void showHorses() {
//                        cout << "Available horses in stable:" << endl;
//                        for (int i = 1; i <= numHorses; i++) {
//                            cout << i << ". " << "Name: " << horsesName[i] << ", Breed: " << horsesBreed[i] << ", Charge: $" << horseCharges[i] << endl;
//                        }
//                    }
//
//                    void selectHorse(int index) {
//                        selectedHorse = horsesName[index];
//                        cout << "Selected horse: " << selectedHorse << " (" << horsesBreed[index] << ")" << endl;
//                    }
//
//                    void selectTimeSlot(int index) {
//                        selectedTimeSlot = timeSlots[index];
//                        cout << "Selected time slot: " << selectedTimeSlot << endl;
//                    }
//
//                    void selectInstructor(int index) {
//                        selectedInstructor = instructors[index];
//                        cout << "Selected instructor: " << selectedInstructor << endl;
//                    }
//
//                    void displayTimeSlots() {
//                        cout << "Available time slots:" << endl;
//                        for (int i = 1; i <= numTimeSlots; i++) {
//                            cout << i << ": " << timeSlots[i] << endl;
//                        }
//                    }
//
//                    double calculateTotalCharge(visitor& x) {
//                        totalCharge = horseCharges[getSelectedHorseIndex()];
//                        totalCharge += 10.0;
//                        x.setBill(totalCharge);
//                        return totalCharge;
//                    }
//
//                    int getSelectedHorseIndex() {
//                        for (int i = 1; i <= numHorses; i++) {
//                            if (horsesName[i] == selectedHorse) {
//                                return i;
//                            }
//                        }
//                        return -1;
//                    }
//                    void showInstructors() {
//                        cout << "Available instructors:" << endl;
//                        for (int i = 1; i <= numInstructors; i++) {
//                            cout << i << ". " << instructors[i] << endl;
//                        }
//                    }
//
//                    string getSelectedHorse() {
//                        return selectedHorse;
//                    }
//
//                    string getSelectedInstructor() {
//                        return selectedInstructor;
//                    }
//
//                    string getSelectedTimeSlot() {
//                        return selectedTimeSlot;
//                    }
//
//                    double getTotalCharge() {
//                        return totalCharge;
//                    }
//                };
//
//                class BoatingActivity {
//                private:
//                    string boatstype[100];
//                    string boatssize[100];
//                    string boatcolor[100];
//                    double chargers[100];
//                    int numTimeSlots;
//                    string timeSlots[5];
//                    double totalCharge;
//                    string selectedBoatType;
//                    string selectedBoatSize;
//                    string selectedBoatColor;
//                    string selectedTimeSlot;
//
//                public:
//                    BoatingActivity(visitor& x) {
//                        numTimeSlots = 4;
//                        timeSlots[0] = "9 to 12";
//                        timeSlots[1] = "12 to 3";
//                        timeSlots[2] = "3 to 6";
//                        timeSlots[3] = "6 to 9";
//
//
//                        boatstype[0] = "Canoe";
//                        boatstype[1] = "Kayak";
//                        boatstype[2] = "Rowboat";
//                        boatstype[3] = "Paddle Boat";
//                        boatstype[4] = "Speedboat";
//
//                        boatssize[0] = "Small";
//                        boatssize[1] = "Medium";
//                        boatssize[2] = "Large";
//                        boatssize[3] = "Extra Large";
//                        boatssize[4] = "Jumbo";
//
//                        boatcolor[0] = "Red";
//                        boatcolor[1] = "Blue";
//                        boatcolor[2] = "Green";
//                        boatcolor[3] = "Yellow";
//                        boatcolor[4] = "Orange";
//
//                        chargers[0] = 10.0;
//                        chargers[1] = 15.0;
//                        chargers[2] = 20.0;
//                        chargers[3] = 25.0;
//                        chargers[4] = 30.0;
//
//                        if (takeInfo()) {
//                            showBoatTypes();
//                            int boatTypeIndex;
//                            cout << "Enter the index of the boat type you want to select: ";
//                            cin >> boatTypeIndex;
//                            while (cin.fail() || boatTypeIndex <= 0 || boatTypeIndex > 5) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a positive non zero integer: ";
//                                cin >> boatTypeIndex;
//                            }
//                            selectBoatType(boatTypeIndex);
//
//                            showBoatSizes();
//                            int boatSizeIndex;
//                            cout << "Enter the index of the boat size you want to select: ";
//                            cin >> boatSizeIndex;
//                            while (cin.fail() || boatSizeIndex <= 0 || boatSizeIndex > 5) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a positive non zero integer: ";
//                                cin >> boatSizeIndex;
//                            }
//                            selectBoatSize(boatSizeIndex);
//
//                            showBoatColors();
//                            int boatColorIndex;
//                            cout << "Enter the index of the boat color you want to select: ";
//                            cin >> boatColorIndex;
//                            while (cin.fail() || boatColorIndex <= 0 || boatColorIndex > 5) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a positive non zero integer: ";
//                                cin >> boatColorIndex;
//                            }
//                            selectBoatColor(boatColorIndex);
//
//                            calculateTotalCharge(boatTypeIndex, boatSizeIndex, boatColorIndex, x);
//
//                            displayTimeSlots();
//                            int timeSlotIndex;
//                            cout << "Enter the index of the time slot you want to select: ";
//                            cin >> timeSlotIndex;
//                            while (cin.fail() || timeSlotIndex <= 0 || timeSlotIndex > 4) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a positive non zero integer: ";
//                                cin >> timeSlotIndex;
//                            }
//                            selectTimeSlot(timeSlotIndex);
//
//                            cout << "\n\n-------------------------" << endl;
//                            cout << "    YOUR RECEIPT" << endl;
//                            cout << "-------------------------" << endl;
//                            cout << "Boat Type: " << getSelectedBoatType() << endl;
//                            cout << "Boat Size: " << getSelectedBoatSize() << endl;
//                            cout << "Boat Color: " << getSelectedBoatColor() << endl;
//                            cout << "Time Slot: " << getSelectedTimeSlot() << endl;
//                            cout << "Total Charges: $" << getTotalCharge() << endl;
//                        }
//                    }
//
//
//                    string getSelectedBoatType() {
//                        return selectedBoatType;
//                    }
//
//                    string getSelectedBoatSize() {
//                        return selectedBoatSize;
//                    }
//
//                    string getSelectedBoatColor() {
//                        return selectedBoatColor;
//                    }
//
//                    string getSelectedTimeSlot() {
//                        return selectedTimeSlot;
//                    }
//
//                    double getTotalCharge() {
//                        return totalCharge;
//                    }
//
//                    bool takeInfo() {
//                        int age;
//                        cout << "Enter your age: ";
//                        cin >> age;
//                        while (cin.fail() || age <= 0) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a positive non zero integer: ";
//                            cin >> age;
//                        }
//                        if (age <= 3) {
//                            cout << "Sorry, children below 3 years old are not allowed for boating activities." << endl;
//                            return false;
//                        }
//                        else {
//                            cout << "You can participate in boating activities." << endl;
//                            return true;
//                        }
//                    }
//
//
//                    void showBoatTypes() {
//                        cout << "Available boat types:" << endl;
//                        for (int i = 0; i < 5; ++i) {
//                            cout << i + 1 << ". " << boatstype[i] << endl;
//                        }
//                    }
//
//                    void showBoatSizes() {
//                        cout << "Available boat sizes:" << endl;
//                        for (int i = 0; i < 5; ++i) {
//                            cout << i + 1 << ". " << boatssize[i] << endl;
//                        }
//                    }
//
//                    void showBoatColors() {
//                        cout << "Available boat colors:" << endl;
//                        for (int i = 0; i < 5; ++i) {
//                            cout << i + 1 << ". " << boatcolor[i] << endl;
//                        }
//                    }
//
//                    void selectBoatType(int index) {
//                        selectedBoatType = boatstype[index - 1];
//                        cout << "Selected boat type: " << selectedBoatType << endl;
//                    }
//
//                    void selectBoatSize(int index) {
//                        selectedBoatSize = boatssize[index - 1];
//                        cout << "Selected boat size: " << selectedBoatSize << endl;
//                    }
//
//                    void selectBoatColor(int index) {
//                        selectedBoatColor = boatcolor[index - 1];
//                        cout << "Selected boat color: " << selectedBoatColor << endl;
//                    }
//
//                    void selectTimeSlot(int index) {
//                        selectedTimeSlot = timeSlots[index - 1];
//                        cout << "Selected time slot: " << selectedTimeSlot << endl;
//                    }
//
//                    void calculateTotalCharge(int boatTypeIndex, int boatSizeIndex, int boatColorIndex, visitor& x) {
//                        totalCharge = 0;
//                        totalCharge += chargers[boatTypeIndex] + chargers[boatSizeIndex] + chargers[boatColorIndex];
//                        x.setBill(totalCharge);
//                    }
//
//                    void displayTimeSlots() {
//                        cout << "Available time slots:" << endl;
//                        for (int i = 0; i < numTimeSlots; ++i) {
//                            cout << i + 1 << ". " << timeSlots[i] << endl;
//                        }
//                    }
//                };
//
//
//
//
//                class IndoorArcade {
//                private:
//                    int age;
//                    string games[10];
//                    double gamesCharges[10];
//                    int vSlot;
//                    int eSlot;
//                    int goldCard;
//                    int silverCard;
//                    int selectedGames[10];
//                    int numSelectedGames;
//
//                public:
//                    IndoorArcade(visitor& temp) {
//                        cout << "\t\t\t\tWelcome to our Arcade\t\t\t\t\t" << endl;
//                        cout << "You can book us from 4 pm to 11 pm." << endl;
//                        cout << "Enter your visiting time: ";
//                        cin >> vSlot;
//                        while (cin.fail() || vSlot <= 0 || vSlot < 4 || vSlot>11) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 4 and 11: ";
//                            cin >> vSlot;
//                        }
//                        cout << "Enter your leaving time: ";
//                        cin >> eSlot;
//                        while (cin.fail() || eSlot <= 0 || eSlot < 4 || eSlot>11 || eSlot <= vSlot) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a valid exit time: ";
//                            cin >> eSlot;
//                        }
//                        cout << "You have booked from " << vSlot << " pm to " << eSlot << " pm" << endl;
//                        int hourCount = eSlot - vSlot;
//                        cout << "You have booked for " << hourCount << " hours." << endl;
//                        cout << "Please enter your age: ";
//                        cin >> age;
//                        while (cin.fail() || age <= 5) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a non zero positive integer and greater than 5: ";
//                            cin >> age;
//                        }
//                        // Initialize game charges
//                        initializeGameCharges();
//                        arcadeGames(temp);
//                    }
//
//                    // Initialize game charges
//                    void initializeGameCharges() {
//                        games[0] = "Tetris";  gamesCharges[0] = 3000;
//                        games[1] = "Twilight Zone";  gamesCharges[1] = 4000;
//                        games[2] = "Shooting Game (Time Crisis)";  gamesCharges[2] = 2500;
//                        games[3] = "Coin Pushers";  gamesCharges[3] = 1500;
//                        games[4] = "Mario Kart";  gamesCharges[4] = 1200;
//                        games[5] = "Virtual Reality (VR) Games";  gamesCharges[5] = 3700;
//                        games[6] = "Ping Pong (Table Tennis)";  gamesCharges[6] = 1670;
//                        games[7] = "Fighting Games (Tekken)";  gamesCharges[7] = 2345;
//                        games[8] = "Interactive Rides (motion simulators)";  gamesCharges[8] = 3489;
//                        games[9] = "Basketball Shooting";  gamesCharges[9] = 2319;
//
//                        goldCard = 50;  // 50% discount for gold card
//                        silverCard = 25;  // 25% discount for silver card
//                        numSelectedGames = 0;
//                    }
//
//                    // Display available games and handle card selection
//                    void arcadeGames(visitor& temp) {
//                        double totalCharges = 0;
//
//                        char moreGames;
//                        do {
//                            cout << "\t\t\t\tYou have the following options for gaming:\t\t\t\t" << endl;
//                            for (int i = 0; i < 10; ++i) {
//                                cout << i + 1 << ". " << games[i] << " - $" << gamesCharges[i] * (eSlot - vSlot) << endl;
//                            }
//
//                            int choice;
//                            cout << "Please select a game (1-10): ";
//                            cin >> choice;
//                            while (cin.fail() || choice < 1 || choice>10) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter a number between 1 and 10: ";
//                                cin >> choice;
//                            }
//                            if (choice >= 1 && choice <= 10) {
//                                selectedGames[numSelectedGames++] = choice - 1;
//                                totalCharges += gamesCharges[choice - 1] * (eSlot - vSlot);
//                            }
//                            else {
//                                cout << "Invalid game selection." << endl;
//                            }
//                            do {
//                                cout << "More games->specialoffers\n";
//                                cout << "Do you want to select more games? (y/n): ";
//                                cin >> moreGames;
//                                if (cin.fail() || (moreGames != 'y' && moreGames != 'n')) {
//                                    cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
//                                    cin.clear();
//                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                }
//                            } while (cin.fail() || (moreGames != 'y' && moreGames != 'n'));
//                        } while (moreGames == 'y' || moreGames == 'Y');
//
//                        // Display selected games for confirmation
//                        cout << "You have selected the following games:" << endl;
//                        for (int i = 0; i < numSelectedGames; ++i) {
//                            cout << i + 1 << ". " << games[selectedGames[i]] << endl;
//                        }
//
//                        // Allow user to cancel any game if needed
//                        char cancelGame;
//                        do {
//                            cout << "Do you want to cancel any game? (y/n): ";
//                            cin >> cancelGame;
//                            if (cin.fail() || (cancelGame != 'y' && cancelGame != 'n')) {
//                                cout << "Invalid input. Please enter 'y' for yes or 'n' for no: " << endl;
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            }
//                        } while (cin.fail() || (cancelGame != 'y' && cancelGame != 'n'));
//                        if (cancelGame == 'y' || cancelGame == 'Y') {
//                            int gameNumber;
//                            cout << "Enter the number of the game you want to cancel: ";
//                            cin >> gameNumber;
//                            while (cin.fail() || gameNumber < 1 || gameNumber >= numSelectedGames) {
//                                cin.clear();
//                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                cout << "Invalid input. Please enter the number from your selected games: ";
//                                cin >> gameNumber;
//                            }
//                            if (gameNumber >= 1 && gameNumber <= numSelectedGames) {
//                                // Calculate refund amount
//                                double refundAmount = gamesCharges[selectedGames[gameNumber - 1]] * (eSlot - vSlot);
//
//                                // Remove the selected game from the list
//                                for (int i = gameNumber - 1; i < numSelectedGames - 1; ++i) {
//                                    selectedGames[i] = selectedGames[i + 1];
//                                }
//                                numSelectedGames--;
//
//                                cout << "Game canceled successfully. Refund amount: $" << refundAmount << endl;
//                            }
//                            else {
//                                cout << "Invalid game number." << endl;
//                            }
//                        }
//
//                        char cardChoice;
//                        cout << "Please select your card for booking with us (gold/silver). Press 'g' or 's': ";
//                        cin >> cardChoice;
//                        while (cin.fail() || cardChoice != 'g' && cardChoice != 's') {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 'g' or 's': ";
//                            cin >> cardChoice;
//                        }
//                        double finalCharges = totalCharges;
//
//                        cout << "Total charges after discount: $" << finalCharges << endl;
//                        if (cardChoice == 'g') {
//                            // Gold card owner
//                            finalCharges -= (finalCharges * goldCard) / 100;
//                            cout << "50% discount granted for gold card." << endl;
//                            if (numSelectedGames == 2) {
//                                cout << "Special offer for you: Free movie ticket!" << endl;
//                            }
//                            else if (numSelectedGames >= 2) {
//                                cout << "Special offer for you: Free cotton candy!" << endl;
//                            }
//                        }
//                        else if (cardChoice == 's') {
//                            // Silver card owner
//                            finalCharges -= (finalCharges * silverCard) / 100;
//                            cout << "25% discount granted for silver card." << endl;
//                            if (numSelectedGames == 2) {
//                                cout << "Special offer for you: Free ice cream!" << endl;
//                            }
//                            if (numSelectedGames >= 2) {
//                                cout << "Special offer for you: Free chocolate chip cookies!" << endl;
//                            }
//                        }
//                        else {
//                            cout << "Invalid card choice." << endl;
//                            return;
//                        }
//                        temp.setBill(finalCharges);
//                    }
//                };
//                class swimming {
//                private:
//                    int date;
//                    int month;
//                    double totalCharges;
//                    string slots;
//                    char genderchoice;
//                    int age;
//                    string options[8];
//                    double optionCharges[8];
//                    string essentials[5];
//                    double essentialCharges[5];
//                    string postswim[4];
//                    double postswimCharges[4];
//                    bool summercheck;
//
//                public:
//                    swimming(visitor v) {
//                        cout << "Swimming activity for visitor: " << v.getName() << endl;
//                        totalCharges = 0.0;
//                        cout << "Enter the date on which you want to come: ";
//                        cin >> date;
//                        cout << "Enter the month(1-12): ";
//                        cin >> month;
//                        if (month > 12 || month < 1) {
//                            cout << "Invalid month. Please enter a valid month (1-12)." << endl;
//                            return;
//                        }
//                        if ((month >= 1 && month <= 4) || (month >= 10 && month <= 12)) {
//                            cout << "Winter booking is not allowed." << endl;
//                            cout << "Please join us in Summers." << endl;
//                            summercheck = false;
//                            return;
//                        }
//                        else {
//                            cout << "Beat the Heat this Summer with us." << endl;
//                            summercheck = true;
//                        }
//
//                        // Initialize charges for options
//                        optionCharges[0] = 5559.0;  // Charge for Beach
//                        optionCharges[1] = 4008.0;  // Charge for Typhoon River
//                        optionCharges[2] = 3005.0;  // Charge for Space Hole
//                        optionCharges[3] = 6500.0;  // Charge for Free Fall
//                        optionCharges[4] = 7000.0;  // Charge for Multi Surf
//                        optionCharges[5] = 8000.0;  // Charge for Splash Zone
//                        optionCharges[6] = 2000.0;   // Charge for Kids Aqua Zone
//                        optionCharges[7] = 2500.0;  // Charge for Rafting Slide Coaster
//
//                        // Initialize charges for essentials
//                        essentialCharges[0] = 1500.0;  // Charge for Swim suit
//                        essentialCharges[1] = 1000.0;  // Charge for Swim tubes
//                        essentialCharges[2] = 3400.0;  // Charge for Life jackets
//                        essentialCharges[3] = 2340.0;  // Charge for Goggles
//                        essentialCharges[4] = 2900.5;  // Charge for Swim caps
//
//                        // Initialize charges for post-swim essentials
//                        postswimCharges[0] = 300.0;  // Charge for Towel
//                        postswimCharges[1] = 420.0;  // Charge for Chlorine Removal Shampoo
//                        postswimCharges[2] = 289.5;  // Charge for Moisturiser
//                        postswimCharges[3] = 256.0;  // Charge for Body Wash
//
//                        tellgender();
//                        selectoptions();
//                        selectessentials();
//                        displayBill(v);
//                    }
//
//                    void tellgender() {
//                        if (!summercheck) {
//                            cout << "Booking is not available in winter months. Please come in summers." << endl;
//                            return;
//                        }
//
//                        cout << "Select your gender: " << endl;
//                        cout << "a. Female" << endl;
//                        cout << "b. Male" << endl;
//                        cin >> genderchoice;
//
//                        if (genderchoice == 'a') {
//                            cout << "Following slots are available for females: 12 pm to 3 pm" << endl;
//                            slots = "12 pm to 3 pm";
//                        }
//                        else if (genderchoice == 'b') {
//                            cout << "Following slots are available for males: 4 pm to 7 pm" << endl;
//                            slots = "4 pm to 7 pm";
//                        }
//                        cout << "Enter your age: ";
//                        cin >> age;
//                        if (age <= 3) {
//                            cout << "Please send your child to kids play area." << endl;
//                            exit(0);
//                        }
//                    }
//                    void selectoptions() {
//                        options[0] = "Beach   Rs:5559";
//                        options[1] = "Typhoon River  Rs:4008";
//                        options[2] = "Space Hole    Rs:3005";
//                        options[3] = "Free Fall   Rs:6500";
//                        options[4] = "Multi Surf  Rs:7000";
//                        options[5] = "Splash Zone  Rs:8000";
//                        options[6] = "Aqua Zone  Rs:2000";
//                        options[7] = "Rafting Slide Coaster  2500";
//                        cout << "\t\t\t\tYou have following options\t\t\t\t\t" << endl;
//                        cout << setw(5) << "Option" << setw(30) << "Price" << setw(10) << endl;
//                        for (int i = 0; i < 8; i++) {
//                            cout << setw(5) << (i + 1) << setw(30) << options[i] << setw(10) << optionCharges[i] << endl;
//                        }
//
//                        int choice;
//                        do {
//                            cout << "Please select an option (1-8): ";
//                            cin >> choice;
//
//                            if (choice >= 1 && choice <= 8) {
//                                cout << "You have selected: " << options[choice - 1] << endl;
//                                totalCharges += optionCharges[choice - 1]; // Add selected option charge to total charges
//                            }
//                            else {
//                                cout << "Invalid option selected!" << endl;
//                            }
//
//                            cout << "Current total charges: Rs: " << totalCharges << endl;
//
//                            char proceed;
//                            cout << "Do you want to select another option? (y/n): ";
//                            cin >> proceed;
//
//                            if (proceed != 'y' && proceed != 'Y') {
//                                break;
//                            }
//
//                        } while (true);
//
//                    }
//                    void selectessentials() {
//                        int quantity = 1;
//                        essentials[0] = "Swim suit  Rs:1500";
//                        essentials[1] = "Swim tubes  Rs:1000";
//                        essentials[2] = "Life jackets  Rs:3400";
//                        essentials[3] = "Goggles  Rs:2340";
//                        essentials[4] = "Swim caps  Rs:2900";
//
//                        cout << "\t\t\t\t " << "Following are the swimming essentials available : " << "\t\t\t" << endl;
//                        cout << setw(5) << "Option" << setw(30) << "Price" << setw(10) << endl;
//                        for (int i = 0; i < 5; i++) {
//                            cout << setw(5) << (i + 1) << setw(30) << essentials[i] << setw(10) << essentialCharges[i] << endl;
//                        }
//                        int choice;
//                        do {
//                            cout << "Please select an option (1-5): ";
//                            cin >> choice;
//
//                            if (choice >= 1 && choice <= 5) {
//                                cout << "You have selected: " << essentials[choice - 1] << endl;
//                                int quantity;
//                                cout << "Enter the quantity: ";
//                                cin >> quantity;
//                                totalCharges += essentialCharges[choice - 1] * quantity; // Add selected essential charge to total charges
//                            }
//                            else {
//                                cout << "Invalid option selected!" << endl;
//                            }
//
//                            cout << "Current total charges: Rs: " << totalCharges << endl;
//
//                            char proceed;
//                            cout << "Do you want to select another essential? (y/n): ";
//                            cin >> proceed;
//
//                            if (proceed != 'y' && proceed != 'Y') {
//                                break;
//                            }
//
//                        } while (true);
//
//                        postswim[0] = "Towel  Rs:300";
//                        postswim[1] = "Chlorine Removal Shampoo  Rs:420";
//                        postswim[2] = "Moisturiser  Rs:289";
//                        postswim[3] = "Body Wash  Rs:256";
//
//                        cout << "\t\t\t\tYou have the following options for post swimming essentials :\t\t\t\t\t" << endl;
//                        cout << setw(5) << "Option" << setw(30) << "Price" << setw(10) << endl;
//                        for (int i = 0; i < 4; i++) {
//                            cout << setw(5) << (i + 1) << setw(30) << postswim[i] << setw(10) << postswimCharges[i] << endl;
//                        }
//                        int choice1;
//                        do {
//                            cout << "Please select an option (1-4): ";
//                            cin >> choice1;
//
//                            if (choice1 >= 1 && choice1 <= 4) {
//                                cout << "You have selected: " << postswim[choice1 - 1] << endl;
//                                int quantity1 = 1;
//                                cout << "Enter the quantity: ";
//                                cin >> quantity1;
//                                totalCharges += postswimCharges[choice - 1] * quantity1; // Add selected essential charge to total charges
//                            }
//                            else {
//                                cout << "Invalid option selected!" << endl;
//                            }
//
//                            cout << "Current total charges: Rs: " << totalCharges << endl;
//
//                            char proceed1;
//                            cout << "Do you want to select another essential? (y/n): ";
//                            cin >> proceed1;
//
//                            if (proceed1 != 'y' && proceed1 != 'Y') {
//                                break;
//                            }
//
//                        } while (true);
//
//                    }
//
//                    void displayBill(visitor v) {
//                        v.setBill(totalCharges);
//                        cout << "-------------------------" << endl;
//                        cout << "           Bill          " << endl;
//                        cout << "-------------------------" << endl;
//                        cout << "Slots chosen: " << slots << endl;
//                        cout << "Total charges: Rs: " << totalCharges << endl;
//                    }
//                    bool isSummerBookingAllowed() {
//                        return summercheck;
//                    }
//
//                };
//                class Faculty : public person {
//                private:
//
//                    char gender;
//                    int workingHours;
//                    int workingDays;
//
//                public:
//                    Faculty() : person() {
//
//                        workingHours = 0;
//                        workingDays = 0;
//                    }
//
//                    Faculty(const string& n, int iid, int a, char g, const string& ph, int hours, int days) : person(iid, n, a, ph) {
//                        id = iid;
//                        gender = g;
//                        workingHours = hours;
//                        workingDays = days;
//                    }
//                    string toString() const {
//                        stringstream ss;
//                        ss << name << "," << id << "," << age << "," << gender << "," << phoneNumber << "," << workingHours << "," << workingDays;
//                        return ss.str();
//                    }
//
//                    char getGender() {
//                        return gender;
//                    }
//
//                    int getWorkingHours() {
//                        return workingHours;
//                    }
//                    int getWorkingDays() {
//                        return workingDays;
//                    }
//                    int calculateSalary() {
//
//                        int salaryPerDay = 100;
//                        return workingDays * salaryPerDay;
//                    }
//                };
//                class Trainer : public person {
//                private:
//
//                    int workingHours;
//                    int workingDays;
//                    char gender;
//                public:
//
//                    Trainer() : person() {
//
//                        workingHours = 0;
//                        workingDays = 0;
//                    }
//
//                    Trainer(const string& n, int iid, int a, char g, const string& ph, int hours, int days) : person(iid, n, a, ph) {
//                        id = iid;
//                        gender = g;
//                        workingHours = hours;
//                        workingDays = days;
//                    }
//
//
//                    int getWorkingHours() {
//                        return workingHours;
//                    }
//                    char getGender() {
//                        return gender;
//                    }
//                    int getWorkingDays() {
//                        return workingDays;
//                    }
//                    string toString() {
//                        stringstream ss;
//                        ss << name << "," << id << "," << age << "," << gender << "," << phoneNumber << "," << workingHours << "," << workingDays;
//                        return ss.str();
//                    }
//
//                    int calculateSalary() {
//
//                        int salaryPerDay = 100;
//                        return workingDays * salaryPerDay;
//                    }
//                };
//                class Admin {
//                private:
//                    string username;
//                    string password;
//                    static const int MAX_FACULTY = 100; // Maximum number of faculty members
//                    Faculty facultyArray[MAX_FACULTY]; // Array to store faculty members
//                    int count = 0; // Counter for the number of faculty members
//                    static const int MAX_TRAINERS = 100; // Maximum number of trainers
//                    Trainer trainerArray[MAX_TRAINERS]; // Array to store trainers
//                    int count1 = 0; // Counter for the number of trainers
//
//                public:
//                    // Default constructor
//                    Admin() : username("admin"), password("password") {}
//
//                    // Parameterized constructor
//                    Admin(const string& user, const string& pass) : username(user), password(pass) {}
//
//                    // Function to perform login
//                    bool login(const string& n, const string& p) {
//                        return (username == n && password == p);
//                    }
//
//                    // Function to add a faculty member
//                    void addFaculty(const string& name, int id, int age, char gender, const string& phoneNumber, int hours, int days) {
//                        if (count < MAX_FACULTY) {
//                            facultyArray[count++] = Faculty(name, id, age, gender, phoneNumber, hours, days);
//                            cout << "Faculty added: " << name << " (" << id << ", Age: " << age << ", Gender: " << gender << ", Phone: " << phoneNumber << ", Hours: " << hours << ", Days: " << days << ")" << endl;
//                            updateFilef();
//                        }
//                        else {
//                            cout << "Error: Maximum number of faculty members reached." << endl;
//                        }
//                    }
//
//                    // Function to remove a faculty member
//                    void removeFaculty(const string& name) {
//                        int index = -1;
//                        for (int i = 0; i < count; ++i) {
//                            if (facultyArray[i].getName() == name) {
//                                index = i;
//                                break;
//                            }
//                        }
//
//                        if (index != -1) {
//                            for (int i = index; i < count - 1; ++i) {
//                                facultyArray[i] = facultyArray[i + 1];
//                            }
//                            count--;
//                            cout << "Faculty removed: " << name << endl;
//                            updateFilef();
//                        }
//                        else {
//                            cout << "Error: Faculty not found." << endl;
//                        }
//                    }
//
//                    // Function to update faculty information
//                    void updateFaculty(const string& name, int id, int age, char gender) {
//                        int index = -1;
//                        for (int i = 0; i < count; ++i) {
//                            if (facultyArray[i].getName() == name) {
//                                index = i;
//                                break;
//                            }
//                        }
//
//                        if (index != -1) {
//                            int hours, days;
//                            cout << "Enter new working hours for " << name << ": ";
//                            cin >> hours;
//                            cout << "Enter new working days count for " << name << ": ";
//                            cin >> days;
//                            facultyArray[index] = Faculty(name, id, age, gender, facultyArray[index].getPhoneNumber(), hours, days);
//                            cout << "Faculty updated: " << name << " (" << id << ", Age: " << age << ", Gender: " << gender << ", Phone: " << facultyArray[index].getPhoneNumber() << ", Hours: " << hours << ", Days: " << days << ")" << endl;
//                            updateFilef();
//                        }
//                        else {
//                            cout << "Error: Faculty not found." << endl;
//                        }
//                    }
//
//                    // Function to read faculty information from file and store in array
//                    void readFacultyArray() {
//
//                        count = 0;
//
//                        ifstream inFile("faculty.txt");
//                        if (inFile.is_open()) {
//                            string line;
//                            while (getline(inFile, line)) {
//                                stringstream ss(line);
//                                string name, phoneNumber;
//                                int id;
//                                int age, hours, days;
//                                char gender;
//                                getline(ss, name, ',');
//                                cin >> id;
//                                ss >> age;
//                                ss.ignore(); // ignore the comma
//                                ss >> gender;
//                                ss.ignore(); // ignore the comma
//                                getline(ss, phoneNumber, ',');
//                                ss >> hours;
//                                ss.ignore(); // ignore the comma
//                                ss >> days;
//                                if (count < MAX_FACULTY) {
//                                    facultyArray[count++] = Faculty(name, id, age, gender, phoneNumber, hours, days);
//                                }
//                                else {
//                                    cout << "Warning: Maximum number of faculty members reached. Some faculty members may not be loaded." << endl;
//                                    break;
//                                }
//                            }
//                            inFile.close();
//                        }
//                        else {
//                            cout << "Error: Unable to open file." << endl;
//                        }
//                    }
//                    // Function to display all faculty members
//                    void displayFaculty() {
//                        for (int i = 0; i < count; ++i) {
//                            cout << "Name: " << facultyArray[i].getName() << ", ID: " << facultyArray[i].getId() << ", Age: " << facultyArray[i].getAge() << ", Gender: " << facultyArray[i].getGender() << ", Phone: " << facultyArray[i].getPhoneNumber() << ", Hours: " << facultyArray[i].getWorkingHours() << ", Days: " << facultyArray[i].getWorkingDays() << endl;
//                        }
//                    }
//
//                    // Function to update faculty file
//                    void updateFilef() {
//                        ofstream outFile("faculty.txt");
//                        if (outFile.is_open()) {
//                            for (int i = 0; i < count; ++i) {
//                                outFile << facultyArray[i].toString() << endl;
//                            }
//                            outFile.close();
//                        }
//                        else {
//                            cout << "Error: Unable to update file." << endl;
//                        }
//                    }
//
//                    // Function to add a trainer
//                    void addTrainer(const string& name, int id, int age, char gender, const string& phoneNumber, int hours, int days) {
//                        if (count1 < MAX_TRAINERS) {
//                            trainerArray[count1++] = Trainer(name, id, age, gender, phoneNumber, hours, days);
//                            cout << "Trainer added: " << name << " (" << id << ", Age: " << age << ", Gender: " << gender << ", Phone: " << phoneNumber << ", Hours: " << hours << ", Days: " << days << ")" << endl;
//                            updateFile();
//                        }
//                        else {
//                            cout << "Error: Maximum number of trainers reached." << endl;
//                        }
//                    }
//
//                    // Function to remove a trainer
//                    void removeTrainer(const string& name) {
//                        int index = -1;
//                        for (int i = 0; i < count1; ++i) {
//                            if (trainerArray[i].getName() == name) {
//                                index = i;
//                                break;
//                            }
//                        }
//
//                        if (index != -1) {
//                            for (int i = index; i < count1 - 1; ++i) {
//                                trainerArray[i] = trainerArray[i + 1];
//                            }
//                            count1--;
//                            cout << "Trainer removed: " << name << endl;
//                            updateFile();
//                        }
//                        else {
//                            cout << "Error: Trainer not found." << endl;
//                        }
//                    }
//
//                    // Function to update trainer information
//                    void updateTrainer(const string& name, int id, int age, char gender) {
//                        int index = -1;
//                        for (int i = 0; i < count1; ++i) {
//                            if (trainerArray[i].getName() == name) {
//                                index = i;
//                                break;
//                            }
//                        }
//
//                        if (index != -1) {
//                            int hours, days;
//                            cout << "Enter new working hours for " << name << ": ";
//                            cin >> hours;
//                            cout << "Enter new working days count for " << name << ": ";
//                            cin >> days;
//                            trainerArray[index] = Trainer(name, id, age, gender, trainerArray[index].getPhoneNumber(), hours, days);
//                            cout << "Trainer updated: " << name << " (" << id << ", Age: " << age << ", Gender: " << gender << ", Phone: " << trainerArray[index].getPhoneNumber() << ", Hours: " << hours << ", Days: " << days << ")" << endl;
//                            updateFile();
//                        }
//                        else {
//                            cout << "Error: Trainer not found." << endl;
//                        }
//                    }
//
//                    // Function to read trainer information from file and store in array
//                    void readTrainerArray() {
//                        // Clear existing trainer data
//                        count1 = 0;
//
//                        ifstream inFile("trainers.txt");
//                        if (inFile.is_open()) {
//                            string line;
//                            while (getline(inFile, line)) {
//                                stringstream ss(line);
//                                string name, phoneNumber;
//                                int id;
//                                int age, hours, days;
//                                char gender;
//                                getline(ss, name, ',');
//                                cin >> id;
//                                ss >> age;
//                                ss.ignore(); // ignore the comma
//                                ss >> gender;
//                                ss.ignore(); // ignore the comma
//                                getline(ss, phoneNumber, ',');
//                                ss >> hours;
//                                ss.ignore(); // ignore the comma
//                                ss >> days;
//                                if (count1 < MAX_TRAINERS) {
//                                    trainerArray[count1++] = Trainer(name, id, age, gender, phoneNumber, hours, days);
//                                }
//                                else {
//                                    cout << "Warning: Maximum number of trainers reached. Some trainers may not be loaded." << endl;
//                                    break;
//                                }
//                            }
//                            inFile.close();
//                        }
//                        else {
//                            cout << "Error: Unable to open file." << endl;
//                        }
//                    }
//                    // Function to display all trainers
//                    void displayTrainers() {
//                        for (int i = 0; i < count1; ++i) {
//                            cout << "Name: " << trainerArray[i].getName() << ", ID: " << trainerArray[i].getId() << ", Age: " << trainerArray[i].getAge() << ", Gender: " << trainerArray[i].getGender() << ", Phone: " << trainerArray[i].getPhoneNumber() << ", Hours: " << trainerArray[i].getWorkingHours() << ", Days: " << trainerArray[i].getWorkingDays() << endl;
//                        }
//                    }
//
//                    // Function to update trainer file
//                    void updateFile() {
//                        ofstream outFile("trainers.txt");
//                        if (outFile.is_open()) {
//                            for (int i = 0; i < count1; ++i) {
//                                outFile << trainerArray[i].toString() << endl;
//                            }
//                            outFile.close();
//                        }
//                        else {
//                            cout << "Error: Unable to update file." << endl;
//                        }
//                    }
//
//                    // Function to calculate and display total salaries of faculty members
//                    void displayFacultySalaries() {
//                        cout << "Faculty Salaries:" << endl;
//                        for (int i = 0; i < count; ++i) {
//
//                            cout << "Name: " << facultyArray[i].getName() << ", Salary: $" << facultyArray[i].calculateSalary() << endl;
//                        }
//                    }
//
//                    // Function to calculate and display total salaries of trainers
//                    void displayTrainerSalaries() {
//                        cout << "Trainer Salaries:" << endl;
//                        for (int i = 0; i < count1; ++i) {
//
//                            cout << "Name: " << trainerArray[i].getName() << ", Salary: $" << trainerArray[i].calculateSalary() << endl;
//                        }
//                    }
//                };
//
//
//
//
//
//
//
//                class eventt {
//                protected:
//                    string name[5];
//                    string date[5];
//                    string refreshments[7];
//                    double charges[5];
//                    long long int totalcharges;
//                    int pnum;
//                    char tchoice;
//                public:
//                    eventt() {
//
//                    }
//                    virtual void personcount() = 0;
//                    virtual void ticketing() = 0;
//                    virtual void chooseeventt(visitor& x) = 0;
//                    virtual void finale() = 0;
//                };
//                class competition : public eventt {
//                public:
//                    competition(visitor& x) {
//                        name[0] = "5 km marathon";
//                        name[1] = "frisbee saga";
//                        name[2] = "swimming saga";
//                        name[3] = "go karting war";
//                        name[4] = "horse riding";
//
//                        date[0] = "June 15, 2024 at 10:00 AM";
//                        date[1] = "July 20, 2024 at 8:00 AM";
//                        date[2] = "August 5, 2024 at 7:30 AM";
//                        date[3] = "September 10, 2024 at 9:00 AM";
//                        date[4] = "October 1, 2024 at 11:00 AM";
//
//                        refreshments[0] = "Lemonade";
//                        refreshments[1] = "Energy bars";
//                        refreshments[2] = "Iced Tea";
//                        refreshments[3] = "Cold Coffee";
//                        refreshments[4] = "Snacks";
//                        refreshments[5] = "Sparkling Water";
//                        refreshments[6] = "Smoothies";
//
//                        charges[0] = 50000.0;
//                        charges[1] = 60000.0;
//                        charges[2] = 70000.0;
//                        charges[3] = 80000.0;
//                        charges[4] = 90000.0;
//
//                        personcount();
//                        ticketing();
//                        chooseeventt(x);
//                        finale();
//                    }
//                    void personcount() override {
//                        cout << "How many persons are you bringing along: ";
//                        cin >> pnum;
//                        while (cin.fail() || pnum <= 0) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a positive non zero integer: ";
//                            cin >> pnum;
//                        }
//                    }
//                    void ticketing() override {
//                        cout << "Would you prefer to buy:\n";
//                        cout << "a. Gold ticket\n";
//                        cout << "b. Silver ticket\n";
//                        cout << "Press a for gold ticket and b for silver ticket.\n";
//                        cin >> tchoice;
//                        while (cin.fail() || (tchoice != 'a' && tchoice != 'b')) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 'a' or 'b': ";
//                            cin >> tchoice;
//                        }
//                    }
//                    void chooseeventt(visitor& x) override {
//                        double refreshmentPrices[] = { 2.5, 1.5, 2.0, 3.0, 1.0, 1.2, 3.5 };
//
//                        cout << "\t\t\t\tYou have following options:\n";
//                        for (int i = 0; i < 5; i++) {
//                            cout << i + 1 << ". " << name[i] << endl;
//                        }
//
//                        int choice;
//                        cout << "Please choose from 1 to 5: ";
//                        cin >> choice;
//                        while (cin.fail() || choice < 1 || choice > 5) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 5: ";
//                            cin >> choice;
//                        }
//                        if (choice >= 1 && choice <= 5) {
//                            cout << "You have selected " << name[choice - 1] << endl;
//
//                            cout << "\t\t\t\tFollowing refreshments are available:\n";
//                            for (int i = 0; i < 7; i++) {
//                                cout << i + 1 << ". " << refreshments[i] << endl;
//                            }
//
//                            double refreshmentCost = 0.0;
//                            char buyAgain = 'y';
//                            while (buyAgain == 'y' || buyAgain == 'Y') {
//                                int buy;
//                                cout << "Would you like to buy any of them? (press from 1 to 7): ";
//                                cin >> buy;
//                                while (cin.fail() || buy < 1 || buy > 7) {
//                                    cin.clear();
//                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                    cout << "Invalid input. Please enter a number between 1 and 7: ";
//                                    cin >> buy;
//                                }
//                                if (buy >= 1 && buy <= 7) {
//                                    int quantity;
//                                    cout << "Enter quantity: ";
//                                    cin >> quantity;
//                                    while (cin.fail() || quantity <= 0 || quantity > 50) {
//                                        cin.clear();
//                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                        cout << "Invalid input. Please enter a number between 1 and 50: ";
//                                        cin >> quantity;
//                                    }
//                                    refreshmentCost += quantity * refreshmentPrices[buy - 1];
//                                    cout << "You have selected: " << quantity << " " << refreshments[buy - 1] << endl;
//                                    cout << "Do you want to buy more? (y/n): ";
//                                    cin >> buyAgain;
//                                    while (buyAgain != 'y' && buyAgain != 'Y' && buyAgain != 'n' && buyAgain != 'N') {
//                                        cout << "Invalid input. Please enter 'y' or 'n': ";
//                                        cin >> buyAgain;
//                                    }
//                                }
//                                else {
//                                    cout << "Invalid choice.\n";
//                                    cout << "Do you want to buy again? (y/n): ";
//                                    cin >> buyAgain;
//                                    while (buyAgain != 'y' && buyAgain != 'Y' && buyAgain != 'n' && buyAgain != 'N') {
//                                        cout << "Invalid input. Please enter 'y' or 'n': ";
//                                        cin >> buyAgain;
//                                    }
//                                }
//                            }
//                            double baseCharge = charges[choice - 1];
//                            double discount = 0.0;
//                            if (pnum >= 5) {
//                                discount = 0.1;
//                            }
//                            else if (pnum >= 3) {
//                                discount = 0.05;
//                            }
//
//                            long long int totalCharges = (baseCharge * (1 - discount) * pnum) + refreshmentCost;
//
//                            if (tchoice == 'a') {
//                                totalCharges *= 1.2;
//                            }
//                            else if (tchoice == 'b') {
//                                totalCharges *= 1.1;
//                            }
//
//                            totalcharges = totalCharges;
//                            cout << "Total charges including refreshments: " << totalCharges << endl;
//                            x.setBill(totalCharges);
//                        }
//                        else {
//                            cout << "Invalid choice.\n";
//
//                        }
//
//                        cout << "\t\t\t\tPlease choose your preferred slot:\n";
//                        for (int i = 0; i < 5; i++) {
//                            cout << date[i] << endl;
//                        }
//
//                        int choice1;
//                        cout << "Please choose from 1 to 5: ";
//                        cin >> choice1;
//                        while (cin.fail() || choice1 < 1 || choice1 > 5) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 5: ";
//                            cin >> choice1;
//                        }
//                        if (choice1 >= 1 && choice1 <= 5) {
//                            cout << "You have selected " << date[choice1 - 1] << endl;
//                        }
//                        else {
//                            cout << "Invalid choice.\n";
//
//                        }
//                    }
//                    double getTotalCharges() const {
//                        return totalcharges;
//                    }
//                    void finale() override {
//                        if (tchoice == 'a') {
//                            cout << "You have been granted golden tickets.\n";
//                            cout << "We most welcome you along with " << pnum << " members.\n";
//                            cout << "Total charges to be paid are: " << totalcharges << endl;
//                        }
//                        else if (tchoice == 'b') {
//                            cout << "You have been granted golden tickets.\n";
//                            cout << "We most welcome you along with " << pnum << " members.\n";
//                            cout << "Total charges to be paid are: " << totalcharges << endl;
//
//                        }
//                    }
//                };
//                class match : public eventt {
//                public:
//                    match(visitor& x) {
//                        name[0] = "football match";
//                        name[1] = "cricket match";
//                        name[2] = "basketball match";
//                        name[3] = "badminton match";
//                        name[4] = "volleyball match";
//
//                        date[0] = "June 11, 2024 at 10:00 AM";
//                        date[1] = "July 22, 2024 at 8:00 AM";
//                        date[2] = "August 15, 2024 at 7:30 AM";
//                        date[3] = "September 1, 2024 at 9:00 AM";
//                        date[4] = "October 19, 2024 at 11:00 AM";
//
//                        charges[0] = 50000.0;
//                        charges[1] = 60000.0;
//                        charges[2] = 70000.0;
//                        charges[3] = 80000.0;
//                        charges[4] = 90000.0;
//
//                        personcount();
//                        ticketing();
//                        chooseeventt(x);
//                        finale();
//                    }
//                    void personcount()override {
//                        cout << "How many persons are you bringing along: ";
//                        cin >> pnum;
//                        while (cin.fail() || pnum <= 0) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a positive integer: ";
//                            cin >> pnum;
//                        }
//                    }
//                    void ticketing()override {
//                        cout << "Would you prefer to buy:\n";
//                        cout << "a.Gold ticket\n";
//                        cout << "b.Silver ticket\n";
//                        cin >> tchoice;
//                        while (cin.fail() || (tchoice != 'a' && tchoice != 'b')) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 'a' or 'b': ";
//                            cin >> tchoice;
//                        }
//                    }
//                    void chooseeventt(visitor& x) override {
//                        cout << "\t\t\t\tYou have following options:\n";
//                        for (int i = 0; i < 5; i++) {
//                            cout << i + 1 << ". " << name[i] << endl;
//                        }
//
//                        int choice;
//                        cout << "Please choose from 1 to 5: ";
//                        cin >> choice;
//                        while (cin.fail() || choice < 1 || choice > 5) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 5: ";
//                            cin >> choice;
//                        }
//                        if (choice >= 1 && choice <= 5) {
//                            cout << "You have selected " << name[choice - 1] << endl;
//                            char yes;
//                            cout << "For this match will you be bringing your equipment along:(y/n) ";
//                            cin >> yes;
//                            double extraCharge = 0; // Initialize extra charge
//
//                            if (yes == 'y') {
//                                cout << "No extra charges.\n";
//                            }
//                            else if (yes == 'n') {
//                                extraCharge = 25000.0; // Assuming extra charge is $10
//                                cout << "Extra charges will be charged.\n";
//                            }
//                            else {
//                                while (cin.fail() || yes != 'y' && yes != 'n') {
//                                    cin.clear();
//                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                    cout << "Invalid input. Please enter y or n: ";
//                                    cin >> yes;
//                                }
//                            }
//                            // Calculate charges based on the chosen event
//                            double baseCharge = charges[choice - 1]; // Get charges for the chosen event
//
//                            // Apply discount based on the number of persons
//                            double discount = 0.0;
//                            if (pnum >= 5) {
//                                discount = 0.3; // 10% discount for 5 or more persons
//                            }
//                            else if (pnum >= 3) {
//                                discount = 0.1; // 5% discount for 3 or more persons
//                            }
//
//                            // Calculate total charges including extra charge
//                            totalcharges = (baseCharge + extraCharge) * (1 - discount) * pnum;
//
//                            // Grant the chosen ticket type
//                            if (tchoice == 'a') {
//                                totalcharges *= 1.1; // Increase charge for gold ticket
//                            }
//                            else if (tchoice == 'b') {
//                                totalcharges *= 0.4; // Increase charge for silver ticket
//                            }
//                            x.setBill(totalcharges);
//                        }
//                        else {
//                            cout << "Invalid choice.\n";
//                        }
//
//                        cout << "\t\t\t\tPlease choose your preferred slot:\n";
//                        for (int i = 0; i < 5; i++) {
//                            cout << date[i] << endl;
//                        }
//
//                        int choice1;
//                        cout << "Please choose from 1 to 5: ";
//                        cin >> choice1;
//                        while (cin.fail() || choice1 < 1 || choice1 > 5) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 5: ";
//                            cin >> choice1;
//                        }
//                        if (choice1 >= 1 && choice1 <= 5) {
//                            cout << "You have selected " << date[choice1 - 1] << endl;
//                        }
//                        else {
//                            cout << "Invalid choice.\n";
//                        }
//                    }
//                    double getTotalCharges() const {
//                        return totalcharges;
//                    }
//                    void finale()override {
//                        if (tchoice == 'a') {
//                            cout << "You have been granted golden tickets.\n";
//                            cout << "We most welcome you along with " << pnum << " members.\n";
//                            cout << "Total charges to be paid are: " << totalcharges << endl;
//                        }
//                        else if (tchoice == 'b') {
//                            cout << "You have been granted golden tickets.\n";
//                            cout << "We most welcome you along with " << pnum << " members.\n";
//                            cout << "Total charges to be paid are: " << totalcharges << endl;
//                        }
//                    }
//                };
//                class trips : public eventt {
//                public:
//                    trips(visitor& x) {
//                        name[0] = "school trip";
//                        name[1] = "college trip";
//                        name[2] = "aqua fiesta";
//                        name[3] = "sports gala";
//                        name[4] = "spring festival";
//
//                        date[0] = "June 19, 2024 at 10:00 AM";
//                        date[1] = "July 28, 2024 at 8:00 AM";
//                        date[2] = "August 9, 2024 at 7:30 AM";
//                        date[3] = "September 12, 2024 at 9:00 AM";
//                        date[4] = "October 11, 2024 at 11:00 AM";
//
//                        charges[0] = 50000.0;
//                        charges[1] = 60000.0;
//                        charges[2] = 70000.0;
//                        charges[3] = 80000.0;
//                        charges[4] = 90000.0;
//
//                        refreshments[0] = "Lemonade";
//                        refreshments[1] = "Energy bars";
//                        refreshments[2] = "Iced Tea";
//                        refreshments[3] = "Cold Coffee";
//                        refreshments[4] = "Snacks";
//                        refreshments[5] = "Sparkling Water";
//                        refreshments[6] = "Smoothies";
//
//                        personcount();
//                        ticketing();
//                        chooseeventt(x);
//                        finale();
//                    }
//                    void personcount() override {
//                        cout << "How many persons are you bringing along: ";
//                        cin >> pnum;
//                        while (cin.fail() || pnum <= 0) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a positive integer: ";
//                            cin >> pnum;
//                        }
//                    }
//                    void ticketing() override {
//                        cout << "Would you prefer to buy:\n";
//                        cout << "a. Gold ticket\n";
//                        cout << "b. Silver ticket\n";
//                        cin >> tchoice;
//                        while (cin.fail() || (tchoice != 'a' && tchoice != 'b')) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter 'a' or 'b': ";
//                            cin >> tchoice;
//                        }
//                    }
//                    void chooseeventt(visitor& x) override {
//                        double refreshmentPrices[] = { 250, 150, 200, 300, 100, 120, 350 };
//
//                        cout << "\t\t\t\tYou have following options:\n";
//                        for (int i = 0; i < 5; i++) {
//                            cout << i + 1 << ". " << name[i] << endl;
//                        }
//
//                        int choice;
//                        cout << "Please choose from 1 to 5: ";
//                        cin >> choice;
//                        while (cin.fail() || choice < 1 || choice > 5) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 5: ";
//                            cin >> choice;
//                        }
//                        if (choice >= 1 && choice <= 5) {
//                            cout << "You have selected " << name[choice - 1] << endl;
//                            cout << "\t\t\t\tFollowing refreshments are available:\n";
//                            for (int i = 0; i < 7; i++) {
//                                cout << i + 1 << ". " << refreshments[i] << endl;
//                            }
//
//                            double refreshmentCost = 0.0;
//
//                            char buyAgain = 'y';
//                            while (buyAgain == 'y' || buyAgain == 'Y') {
//                                int buy;
//                                cout << "Would you like to buy any of them? (press from 1 to 7): ";
//                                cin >> buy;
//                                while (cin.fail() || buy < 1 || buy > 7) {
//                                    cin.clear();
//                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                    cout << "Invalid input. Please enter a number between 1 and 7: ";
//                                    cin >> buy;
//                                }
//                                if (buy >= 1 && buy <= 7) {
//                                    int quantity;
//                                    cout << "Enter quantity: ";
//                                    cin >> quantity;
//                                    while (cin.fail() || quantity <= 0 || quantity > 50) {
//                                        cin.clear();
//                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                                        cout << "Invalid input. Please enter a number between 1 and 50: ";
//                                        cin >> quantity;
//                                    }
//                                    refreshmentCost += quantity * refreshmentPrices[buy - 1];
//                                    cout << "You have selected: " << quantity << " " << refreshments[buy - 1] << endl;
//                                    cout << "Do you want to buy more? (y/n): ";
//                                    cin >> buyAgain;
//                                    while (buyAgain != 'y' && buyAgain != 'Y' && buyAgain != 'n' && buyAgain != 'N') {
//                                        cout << "Invalid input. Please enter 'y' or 'n': ";
//                                        cin >> buyAgain;
//                                    }
//                                }
//                                else {
//                                    cout << "Invalid choice.\n";
//                                    cout << "Do you want to buy again? (y/n): ";
//                                    cin >> buyAgain;
//                                    while (buyAgain != 'y' && buyAgain != 'Y' && buyAgain != 'n' && buyAgain != 'N') {
//                                        cout << "Invalid input. Please enter 'y' or 'n': ";
//                                        cin >> buyAgain;
//                                    }
//                                }
//                            }
//                            double baseCharge = charges[choice - 1];
//                            double discount = 0.0;
//                            if (pnum >= 5) {
//                                discount = 0.1;
//                            }
//                            else if (pnum >= 3) {
//                                discount = 0.05;
//                            }
//
//                            long long int totalCharges = (baseCharge * (1 - discount) * pnum) + refreshmentCost;
//
//                            if (tchoice == 'a') {
//                                totalCharges *= 1.2;
//                            }
//                            else if (tchoice == 'b') {
//                                totalCharges *= 1.1;
//                            }
//
//                            totalcharges = totalCharges;
//
//                            cout << "Total charges including refreshments: " << totalCharges << endl;
//                            x.setBill(totalcharges);
//                        }
//                        else {
//                            cout << "Invalid choice.\n";
//                        }
//
//                        cout << "\t\t\t\tPlease choose your preferred slot:\n";
//                        for (int i = 0; i < 5; i++) {
//                            cout << date[i] << endl;
//                        }
//
//                        int choice1;
//                        cout << "Please choose from 1 to 5: ";
//                        cin >> choice1;
//                        while (cin.fail() || choice1 < 1 || choice1 > 7) {
//                            cin.clear();
//                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                            cout << "Invalid input. Please enter a number between 1 and 7: ";
//                            cin >> choice1;
//                        }
//                        if (choice1 >= 1 && choice1 <= 5) {
//                            cout << "You have selected " << date[choice1 - 1] << endl;
//                        }
//                        else {
//                            cout << "Invalid choice.\n";
//                        }
//
//                    }
//                    double getTotalCharges() const {
//                        return totalcharges;
//                    }
//                    void finale() override {
//                        if (tchoice == 'a') {
//                            cout << "You have been granted golden tickets.\n";
//                            cout << "We most welcome you along with " << pnum << " members.\n";
//                            cout << "Total charges to be paid are: " << totalcharges << endl;
//                        }
//                        else if (tchoice == 'b') {
//                            cout << "You have been granted golden tickets.\n";
//                            cout << "We most welcome you along with " << pnum << " members.\n";
//                            cout << "Total charges to be paid are: " << totalcharges << endl;
//                        }
//                    }
//                };
//
//
//
//
//                int main() {
//                    int choice = 0;
//                    cout << "enter 1 for visitor and 2 for admin" << endl;
//                    cin >> choice;
//                    if (choice == 1) {
//                        int c;
//                        cout << "Enter your choice (1 or 2): ";
//                        cin >> c;
//                        sqlite3* db;
//                        if (c == 1) {
//
//                            int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//                            if (rc) {
//                                cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << endl;
//                                sqlite3_close(db);
//                                return 1;
//                            }
//                            cout << "Opened database successfully" << endl;
//
//                            char* errMsg = nullptr;
//                            const char* createTableSQL = "CREATE TABLE IF NOT EXISTS visitors ("
//                                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//                                "name TEXT NOT NULL,"
//                                "age INTEGER,"
//                                "phone_number TEXT,"
//                                "bill REAL" // Add a column for storing the bill
//                                ");";
//                            rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
//                            if (rc != SQLITE_OK) {
//                                cerr << "Error creating table: " << errMsg << endl;
//                                sqlite3_free(errMsg);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//                            else {
//                                cout << "Table created successfully" << endl;
//                            }
//                            char addNewVisitor;
//                            cout << "Do you want to add a new visitor? (y/n): ";
//                            cin >> addNewVisitor;
//
//                            if (addNewVisitor == 'y' || addNewVisitor == 'Y') {
//                                string name, phone_number;
//                                int age;
//                                cout << "Enter name: ";
//                                cin.ignore(); // Ignore newline character from previous input
//                                getline(cin, name);
//                                cout << "Enter age: ";
//                                cin >> age;
//                                cout << "Enter phone number: ";
//                                cin.ignore(); // Ignore newline character from previous input
//                                getline(cin, phone_number);
//
//                                // SQL statement to insert a new row into the visitors table
//                                string insertVisitorSQL = "INSERT INTO visitors (name, age, phone_number) "
//                                    "VALUES ('" + name + "', " + to_string(age) + ", '" + phone_number + "');";
//
//                                rc = sqlite3_exec(db, insertVisitorSQL.c_str(), nullptr, nullptr, &errMsg);
//                                if (rc != SQLITE_OK) {
//                                    cerr << "Error inserting visitor: " << errMsg << endl;
//                                    sqlite3_free(errMsg);
//                                    sqlite3_close(db);
//                                    return 1;
//                                }
//                                else {
//                                    cout << "New visitor added successfully" << endl;
//                                }
//                            }
//                            visitor visitors[5] = {
//                                            visitor(12,"John Doe", 23, "23-456-7890"),
//                                            visitor(1, "Jane Smith", 9, "87-654-3210"),
//                                            visitor(3,"Michael Johnson", 5, "5-555-5555"),
//                                            visitor(4, "Emily Davis", 7, "7-888-9999"),
//                                            visitor(5,"David Brown", 4, "4-333-2222")
//                            };
//
//                            int visitorID;
//                            cout << "Enter your visitor ID (1-5): ";
//                            cin >> visitorID;
//
//
//                            cout << "Choose an activity:" << endl;
//                            cout << "1. BOATING" << endl;
//                            cout << "2. Horse Riding" << endl;
//                            cout << "3. Indoor Arcade" << endl;
//                            cout << "4. Swimming" << endl;
//                            cout << "5. GYM" << endl;
//                            cout << "6. GO KARTING" << endl;
//                            cout << "7. RUNNING TRACK" << endl;
//                            int activityChoice;
//                            cout << "Enter the number of the activity you want to perform: ";
//                            cin >> activityChoice;
//
//                            switch (activityChoice) {
//                            case 1: {
//                                BoatingActivity boat(visitors[visitorID - 1]);
//                                visitors[visitorID - 1].setBill(boat.getTotalCharge());
//
//
//                                break;
//                            }
//                            case 2: {
//                                HorseRidingActivity horseRiding(visitors[visitorID - 1]);
//                                visitors[visitorID - 1].setBill(horseRiding.getTotalCharge());
//                                break;
//                            }
//                            case 3: {
//                                IndoorArcade arcade(visitors[visitorID - 1]);
//                                visitors[visitorID - 1].setBill(horseRiding.getTotalCharge());
//                                break;
//                            }
//                            case 4: {
//                                swimming swimmings(visitors[visitorID - 1]);
//                                visitors[visitorID - 1].setBill(horseRiding.getTotalCharge());
//                                break;
//                            }
//                            case 5: {
//                                gym gymActivity(visitors[visitorID - 1]); // Create an instance of the gym class
//                                visitors[visitorID - 1].setBill(horseRiding.getTotalCharge());
//                                break;
//                            }
//                            case 6: {
//                                gokarting go(visitors[visitorID - 1]);
//                                visitors[visitorID - 1].setBill(horseRiding.getTotalCharge());
//
//                                break;
//                            }
//                            case 7: {
//                                runningtrack run(visitors[visitorID - 1]);
//                                visitors[visitorID - 1].setBill(horseRiding.getTotalCharge());
//
//                                break;
//                            }
//                            default:
//                                cout << "Invalid activity choice!" << endl;
//                                return 1;
//                            }
//
//                            // Update the bill in the SQLite database
//                            const char* updateBillSQL = "UPDATE visitors SET bill = ? WHERE id = ?";
//                            sqlite3_stmt* stmt;
//                            rc = sqlite3_prepare_v2(db, updateBillSQL, -1, &stmt, nullptr);
//                            if (rc != SQLITE_OK) {
//                                cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
//                                sqlite3_close(db);
//                                return 1;
//                            }
//
//                            // Bind parameters
//                            rc = sqlite3_bind_double(stmt, 1, visitors[visitorID - 1].getBill());
//                            if (rc != SQLITE_OK) {
//                                cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//                            rc = sqlite3_bind_int(stmt, 2, visitorID);
//                            if (rc != SQLITE_OK) {
//                                cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//
//                            // Execute the statement
//                            rc = sqlite3_step(stmt);
//                            if (rc != SQLITE_DONE) {
//                                cerr << "Error updating bill: " << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//
//                            cout << "Bill for " << visitors[visitorID - 1].getName() << ": $" << visitors[visitorID - 1].getBill() << endl;
//
//
//                            // Finalize the statement and close the database
//                            sqlite3_finalize(stmt);
//
//                            sqlite3_close(db);
//
//                        }
//
//                        if (c == 2) {
//
//                            // Your existing visitor objects
//                            visitor visitors[5] = {
//                                visitor(12,"John Doe", 23, "23-456-7890"),
//                                visitor(1,"Jane Smith", 9, "87-654-3210"),
//                                visitor(3,"Michael Johnson", 5, "5-555-5555"),
//                                visitor(4,"Emily Davis", 7, "7-888-9999"),
//                                visitor(5,"David Brown", 4, "4-333-2222")
//                            };
//
//                            int visitorID;
//                            cout << "Enter your visitor ID (1-5): ";
//                            cin >> visitorID;
//
//                            cout << "Choose an event:" << endl;
//                            cout << "1. Competition" << endl;
//                            cout << "2. Match" << endl;
//                            cout << "3. Trip" << endl;
//                            int eventChoice;
//                            cout << "Enter the number of the event you participated in: ";
//                            cin >> eventChoice;
//
//                            switch (eventChoice) {
//                            case 1: {
//                                // Create a competition object using the visitor's information
//                                competition competitions(visitors[visitorID - 1]);
//                                // Call the member functions to handle the competition
//
//                                // Open the SQLite database
//                                int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//                                if (rc) {
//                                    cout << "Invalid format. Error in opening database file. " << sqlite3_errmsg(db) << endl;
//                                    sqlite3_close(db);
//                                    return 1;
//                                }
//
//                                // Update the bill column in the visitors table
//                                string updateBillSQL = "Visitor Bill to be updated." + to_string(competitions.getTotalCharges()) + " where id is: " + to_string(visitorID) + ";";
//                                char* errMsg = nullptr;
//                                rc = sqlite3_exec(db, updateBillSQL.c_str(), nullptr, nullptr, &errMsg);
//                                if (rc != SQLITE_OK) {
//                                    cout << "Invalid operation. Bill cannot be updated." << errMsg << endl;
//                                    sqlite3_free(errMsg);
//                                    sqlite3_close(db);
//                                    return 1;
//                                }
//                                else {
//                                    cout << "Update in bill is successful." << endl;
//                                }
//
//                                // Close the SQLite database connection
//                                sqlite3_close(db);
//
//                                break;
//                            }
//                            case 2: {
//                                match matches(visitors[visitorID - 1]);
//                                // Call the member functions to handle the competition
//
//                                // Open the SQLite database
//                                int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//                                if (rc) {
//                                    cout << "Invalid format. Error in opening database file. " << sqlite3_errmsg(db) << endl;
//                                    sqlite3_close(db);
//                                    return 1;
//                                }
//
//                                // Update the bill column in the visitors table
//                                string updateBillSQL = "Visitor Bill to be updated." + to_string(matches.getTotalCharges()) + " where id is: " + to_string(visitorID) + ";";
//                                char* errMsg = nullptr;
//                                rc = sqlite3_exec(db, updateBillSQL.c_str(), nullptr, nullptr, &errMsg);
//                                if (rc != SQLITE_OK) {
//                                    cout << "Invalid operation. Bill cannot be updated." << errMsg << endl;
//                                    sqlite3_free(errMsg);
//                                    sqlite3_close(db);
//                                    return 1;
//                                }
//                                else {
//                                    cout << "Update in bill is successful." << endl;
//                                }
//                                break;
//                            }
//                            case 3: {
//                                trips trip(visitors[visitorID - 1]);
//                                // Call the member functions to handle the competition
//
//                                // Open the SQLite database
//                                int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//                                if (rc) {
//                                    cout << "Invalid format. Error in opening database file. " << sqlite3_errmsg(db) << endl;
//                                    sqlite3_close(db);
//                                    return 1;
//                                }
//
//                                // Update the bill column in the visitors table
//                                string updateBillSQL = "Visitor Bill to be updated." + to_string(trip.getTotalCharges()) + " where id is: " + to_string(visitorID) + ";";
//                                char* errMsg = nullptr;
//                                rc = sqlite3_exec(db, updateBillSQL.c_str(), nullptr, nullptr, &errMsg);
//                                if (rc != SQLITE_OK) {
//                                    cout << "Invalid operation. Bill cannot be updated." << errMsg << endl;
//                                    sqlite3_free(errMsg);
//                                    sqlite3_close(db);
//                                    return 1;
//                                }
//                                else {
//                                    cout << "Update in bill is successful." << endl;
//                                }
//                                break;
//
//                            }
//                            default:
//                                cout << "Invalid event choice!" << endl;
//                                return 1;
//                            }
//                        }
//                        else if (c == 3) {
//                            // Open the SQLite database
//                            int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//                            if (rc) {
//                                cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << endl;
//                                sqlite3_close(db);
//                                return 1;
//                            }
//                            visitor visitors[5] = {
//                               visitor(12,"John Doe", 23, "23-456-7890"),
//                               visitor(1,"Jane Smith", 9, "87-654-3210"),
//                               visitor(3,"Michael Johnson", 5, "5-555-5555"),
//                               visitor(4,"Emily Davis", 7, "7-888-9999"),
//                               visitor(5,"David Brown", 4, "4-333-2222")
//                            };
//                            int visitorID = 0;
//                            cout << "enter visitor id" << endl;
//                            cin >> visitorID;
//                            // Create a competition object using the visitor's information
//                            Cafeteria cafe(visitors[visitorID - 1]);
//                            // Call the member functions to handle the competition
//
//                            const char* updateBillSQL = "UPDATE visitors SET bill = ? WHERE id = ?";
//                            sqlite3_stmt* stmt;
//                            rc = sqlite3_prepare_v2(db, updateBillSQL, -1, &stmt, nullptr);
//                            if (rc != SQLITE_OK) {
//                                cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
//                                sqlite3_close(db);
//                                return 1;
//                            }
//
//                            rc = sqlite3_bind_double(stmt, 1, visitors[visitorID - 1].getBill());
//                            if (rc != SQLITE_OK) {
//                                cout << "ERROR:Parameters incorrectly binded" << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//                            rc = sqlite3_bind_int(stmt, 2, visitorID);
//                            if (rc != SQLITE_OK) {
//                                cout << "ERROR:Parameters incorrectly binded" << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//
//
//                            rc = sqlite3_step(stmt);
//                            if (rc != SQLITE_DONE) {
//                                cout << "Error Bind" << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//                            cout << "YOUR RECEIPT" << endl;
//                            cout << "Total Charges for the Visitor " << visitors[visitorID - 1].getName() << " are " << visitors[visitorID - 1].getBill() << endl;
//
//
//                            sqlite3_finalize(stmt);
//                            rc = sqlite3_bind_double(stmt, 1, visitors[visitorID - 1].getBill());
//                            if (rc != SQLITE_OK) {
//                                cout << "parameters are not binded correctly..error " << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//                            rc = sqlite3_bind_int(stmt, 2, visitorID);
//                            if (rc != SQLITE_OK) {
//                                cout << "parameters are not binded correctly..error " << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//
//
//                            rc = sqlite3_step(stmt);
//                            if (rc != SQLITE_DONE) {
//                                cout << "bill error " << sqlite3_errmsg(db) << endl;
//                                sqlite3_finalize(stmt);
//                                sqlite3_close(db);
//                                return 1;
//                            }
//                            cout << "YOUR RECEIPT\n";
//                            cout << "Total Charges(bill) for the visitos named " << visitors[visitorID - 1].getName() << " is " << visitors[visitorID - 1].getBill() << endl;
//
//
//                            sqlite3_finalize(stmt);
//
//                            sqlite3_close(db);
//                        }
//                        else if (choice == 2) {
//                            Admin admin("admin", "password");
//
//                            // Login
//                            string username, password;
//                            cout << "Admin Login" << endl;
//                            cout << "Username: ";
//                            cin >> username;
//                            cout << "Password: ";
//                            cin >> password;
//
//                            if (admin.login(username, password)) {
//                                cout << "Login Successful!" << endl;
//
//                                char choice;
//                                do {
//                                    // Display menu options
//                                    cout << "Choose an option:" << endl;
//                                    cout << "1. Faculty Management" << endl;
//                                    cout << "2. Trainer Management" << endl;
//                                    cout << "e. Exit" << endl;
//
//                                    cin >> choice;
//
//                                    switch (choice) {
//                                    case '1': {
//                                        // Faculty Management
//                                        // Load faculty data from file
//                                        admin.readFacultyArray();
//
//                                        // Display faculty management menu
//                                        cout << "Faculty Management Menu:" << endl;
//                                        cout << "1. Add Faculty" << endl;
//                                        cout << "2. Update Faculty" << endl;
//                                        cout << "3. Remove Faculty" << endl;
//                                        cout << "4. Display Faculty" << endl;
//                                        cout << "5. Display Faculty Salaries" << endl;
//                                        cout << "e. Exit" << endl;
//
//                                        char option;
//                                        cin >> option;
//
//                                        switch (option) {
//                                        case '1': {
//                                            // Add Faculty
//                                            string name, phoneNumber;
//                                            int age, hours, days, id;
//                                            char gender;
//
//                                            cout << "Enter name: ";
//                                            cin >> name;
//                                            cout << "Enter ID: ";
//                                            cin >> id;
//                                            cout << "Enter age: ";
//                                            cin >> age;
//                                            cout << "Enter gender: ";
//                                            cin >> gender;
//                                            cout << "Enter phone number: ";
//                                            cin >> phoneNumber;
//                                            cout << "Enter working hours: ";
//                                            cin >> hours;
//                                            cout << "Enter working days: ";
//                                            cin >> days;
//
//                                            admin.addFaculty(name, id, age, gender, phoneNumber, hours, days);
//                                            break;
//                                        }
//                                        case '2': {
//                                            // Update Faculty
//                                            string name;
//                                            int id;
//                                            int age;
//                                            char gender;
//
//                                            cout << "Enter name of faculty to update: ";
//                                            cin >> name;
//                                            cout << "Enter new ID: ";
//                                            cin >> id;
//                                            cout << "Enter new age: ";
//                                            cin >> age;
//                                            cout << "Enter new gender: ";
//                                            cin >> gender;
//
//                                            admin.updateFaculty(name, id, age, gender);
//                                            break;
//                                        }
//                                        case '3': {
//                                            // Remove Faculty
//                                            string name;
//                                            cout << "Enter name of faculty to remove: ";
//                                            cin >> name;
//                                            admin.removeFaculty(name);
//                                            break;
//                                        }
//                                        case '4': {
//                                            // Display Faculty
//                                            admin.displayFaculty();
//                                            break;
//                                        }
//                                        case '5': {
//                                            // Display Faculty Salaries
//                                            admin.displayFacultySalaries();
//                                            break;
//                                        }
//                                        case 'e':
//                                            cout << "Exiting faculty management..." << endl;
//                                            break;
//                                        default:
//                                            cout << "Invalid choice" << endl;
//                                        }
//
//                                        break;
//                                    }
//                                    case '2': {
//                                        // Trainer Management
//                                        // Load trainer data from file
//                                        admin.readTrainerArray();
//
//                                        // Display trainer management menu
//                                        cout << "Trainer Management Menu:" << endl;
//                                        cout << "1. Add Trainer" << endl;
//                                        cout << "2. Update Trainer" << endl;
//                                        cout << "3. Remove Trainer" << endl;
//                                        cout << "4. Display Trainers" << endl;
//                                        cout << "5. Display Trainer Salaries" << endl;
//                                        cout << "e. Exit" << endl;
//
//                                        char option;
//                                        cin >> option;
//
//                                        switch (option) {
//                                        case '1': {
//                                            // Add Trainer
//                                            string name;
//                                            int id;
//                                            string phoneNumber;
//                                            int age, hours, days;
//                                            char gender;
//
//                                            cout << "Enter name: ";
//                                            cin >> name;
//                                            cout << "Enter ID: ";
//                                            cin >> id;
//                                            cout << "Enter age: ";
//                                            cin >> age;
//                                            cout << "Enter gender: ";
//                                            cin >> gender;
//                                            cout << "Enter phone number: ";
//                                            cin >> phoneNumber;
//                                            cout << "Enter working hours: ";
//                                            cin >> hours;
//                                            cout << "Enter working days: ";
//                                            cin >> days;
//
//                                            admin.addTrainer(name, id, age, gender, phoneNumber, hours, days);
//                                            break;
//                                        }
//                                        case '2': {
//                                            // Update Trainer
//                                            string name;
//                                            int id;
//                                            int age;
//                                            char gender;
//
//                                            cout << "Enter name of trainer to update: ";
//                                            cin >> name;
//                                            cout << "Enter new ID: ";
//                                            cin >> id;
//                                            cout << "Enter new age: ";
//                                            cin >> age;
//                                            cout << "Enter new gender: ";
//                                            cin >> gender;
//
//                                            admin.updateTrainer(name, id, age, gender);
//                                            break;
//                                        }
//                                        case '3': {
//                                            // Remove Trainer
//                                            string name;
//                                            cout << "Enter name of trainer to remove: ";
//                                            cin >> name;
//                                            admin.removeTrainer(name);
//                                            break;
//                                        }
//                                        case '4': {
//                                            // Display Trainers
//                                            admin.displayTrainers();
//                                            break;
//                                        }
//                                        case '5': {
//                                            // Display Trainer Salaries
//                                            admin.displayTrainerSalaries();
//                                            break;
//                                        }
//                                        case 'e':
//                                            cout << "Exiting trainer management..." << endl;
//                                            break;
//                                        default:
//                                            cout << "Invalid choice" << endl;
//                                        }
//
//                                        break;
//                                    }
//                                    case 'e':
//                                        cout << "Exiting..." << endl;
//                                        break;
//                                    default:
//                                        cout << "Invalid choice" << endl;
//                                    }
//
//                                } while (choice != 'e');
//                            }
//                            else {
//                                cout << "Login Failed!" << endl;
//                            }
//                        }
//                    }
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//                };
//                break;
//            }
//            case 3: {
//                IndoorArcade arcade(visitors[visitorID - 1]);
//
//                break;
//            }
//            case 4: {
//                swimming swimmings(visitors[visitorID - 1]);
//                break;
//            }
//            case 5: {
//                gym gymActivity(visitors[visitorID - 1]); // Create an instance of the gym class
//
//                break;
//            }
//            case 6: {
//                gokarting go(visitors[visitorID - 1]);
//
//                break;
//            }
//            case 7: {
//                runningtrack run(visitors[visitorID - 1]);
//
//
//                break;
//            }
//            default:
//                cout << "Invalid activity choice!" << endl;
//                return 1;
//            }
//
//            // Update the bill in the SQLite database
//            const char* updateBillSQL = "UPDATE visitors SET bill = ? WHERE id = ?";
//            sqlite3_stmt* stmt;
//            rc = sqlite3_prepare_v2(db, updateBillSQL, -1, &stmt, nullptr);
//            if (rc != SQLITE_OK) {
//                cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
//                sqlite3_close(db);
//                return 1;
//            }
//
//            // Bind parameters
//            rc = sqlite3_bind_double(stmt, 1, visitors[visitorID - 1].getBill());
//            if (rc != SQLITE_OK) {
//                cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//            rc = sqlite3_bind_int(stmt, 2, visitorID);
//            if (rc != SQLITE_OK) {
//                cerr << "Error binding parameter: " << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//
//            // Execute the statement
//            rc = sqlite3_step(stmt);
//            if (rc != SQLITE_DONE) {
//                cerr << "Error updating bill: " << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//
//            cout << "Bill for " << visitors[visitorID - 1].getName() << ": $" << visitors[visitorID - 1].getBill() << endl;
//
//
//            sqlite3_finalize(stmt);
//
//            sqlite3_close(db);
//
//        }
//
//        if (c == 2) {
//
//
//            visitor visitors[5] = {
//                visitor(12,"John Doe", 23, "23-456-7890"),
//                visitor(1,"Jane Smith", 9, "87-654-3210"),
//                visitor(3,"Michael Johnson", 5, "5-555-5555"),
//                visitor(4,"Emily Davis", 7, "7-888-9999"),
//                visitor(5,"David Brown", 4, "4-333-2222")
//            };
//
//            int visitorID;
//            cout << "Enter your visitor ID (1-5): ";
//            cin >> visitorID;
//
//            cout << "Choose an event:" << endl;
//            cout << "1. Competition" << endl;
//            cout << "2. Match" << endl;
//            cout << "3. Trip" << endl;
//            int eventChoice;
//            cout << "Enter the number of the event you participated in: ";
//            cin >> eventChoice;
//
//            switch (eventChoice) {
//            case 1: {
//
//                competition competitions(visitors[visitorID - 1]);
//
//
//                int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//                if (rc) {
//                    cout << "Invalid format. Error in opening database file. " << sqlite3_errmsg(db) << endl;
//
//                    sqlite3_close(db);
//
//                    return 1;
//                }
//
//
//                string updateBillSQL = "Visitor Bill to be updated." + to_string(competitions.getTotalCharges()) + " where id is: " + to_string(visitorID) + ";";
//                char* errMsg = nullptr;
//                rc = sqlite3_exec(db, updateBillSQL.c_str(), nullptr, nullptr, &errMsg);
//                if (rc != SQLITE_OK) {
//                    cout << "Invalid operation. Bill cannot be updated." << errMsg << endl;
//                    sqlite3_free(errMsg);
//
//                    sqlite3_close(db);
//                    return 1;
//                }
//                else {
//                    cout << "Update l is successful." << endl;
//                }
//
//
//                sqlite3_close(db);
//
//                break;
//            }
//            case 2: {
//                match matches(visitors[visitorID - 1]);
//
//                int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//                if (rc) {
//
//                    cout << "Invalid format. Error in opening database file. " << sqlite3_errmsg(db) << endl;
//                    sqlite3_close(db);
//                    return 1;
//                }
//
//
//                string updateBillSQL = "Visitor Bill to be updated." + to_string(matches.getTotalCharges()) + " where id is: " + to_string(visitorID) + ";";
//                char* errMsg = nullptr;
//
//                rc = sqlite3_exec(db, updateBillSQL.c_str(), nullptr, nullptr, &errMsg);
//                if (rc != SQLITE_OK) {
//                    cout << "Invalid operation. Bill cannot be updated." << errMsg << endl;
//                    sqlite3_free(errMsg);
//
//                    sqlite3_close(db);
//                    return 1;
//                }
//                else {
//                    cout << "Update in bill is successful." << endl;
//                }
//                break;
//            }
//            case 3: {
//                trips trip(visitors[visitorID - 1]);
//
//                int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//                if (rc) {
//
//                    cout << "Invalid format. Error in opening database file. " << sqlite3_errmsg(db) << endl;
//                    sqlite3_close(db);
//                    return 1;
//                }
//
//
//                string updateBillSQL = "Visitor Bill to be updated." + to_string(trip.getTotalCharges()) + " where id is: " + to_string(visitorID) + ";";
//                char* errMsg = nullptr;
//
//
//
//                rc = sqlite3_exec(db, updateBillSQL.c_str(), nullptr, nullptr, &errMsg);
//                if (rc != SQLITE_OK) {
//                    cout << "Invalid operation." << errMsg << endl;
//                    sqlite3_free(errMsg);
//                    \
//                        sqlite3_close(db);
//                    return 1;
//                }
//                else {
//                    cout << "Update in bill is successful." << endl;
//                }
//                break;
//
//            }
//            default:
//                cout << "Invalid event choice!" << endl;
//                return 1;
//            }
//        }
//        else if (c == 3) {
//
//            int rc = sqlite3_open("C:\\Users\\CW\\Desktop\\please\\please.db", &db);
//            if (rc) {
//                cerr << "Error opening SQLite database: " << sqlite3_errmsg(db) << endl;
//                sqlite3_close(db);
//                return 1;
//            }
//            visitor visitors[5] = {
//               visitor(12,"John Doe", 23, "23-456-7890"),
//               visitor(1,"Jane Smith", 9, "87-654-3210"),
//               visitor(3,"Michael Johnson", 5, "5-555-5555"),
//               visitor(4,"Emily Davis", 7, "7-888-9999"),
//               visitor(5,"David Brown", 4, "4-333-2222")
//            };
//            int visitorID = 0;
//            cout << "enter visitor id" << endl;
//            cin >> visitorID;
//
//            Cafeteria cafe(visitors[visitorID - 1]);
//
//            const char* updateBillSQL = "UPDATE visitors SET bill = ? WHERE id = ?";
//            sqlite3_stmt* stmt;
//            rc = sqlite3_prepare_v2(db, updateBillSQL, -1, &stmt, nullptr);
//            if (rc != SQLITE_OK) {
//                cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
//                sqlite3_close(db);
//                return 1;
//            }
//
//            rc = sqlite3_bind_double(stmt, 1, visitors[visitorID - 1].getBill());
//            if (rc != SQLITE_OK) {
//                cout << "ERROR:Parameters incorrectly binded" << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//            rc = sqlite3_bind_int(stmt, 2, visitorID);
//            if (rc != SQLITE_OK) {
//                cout << "ERROR:Parameters incorrectly binded" << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//
//
//            rc = sqlite3_step(stmt);
//            if (rc != SQLITE_DONE) {
//                cout << "Error Bind" << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//            cout << "YOUR RECEIPT" << endl;
//            cout << "Total Charges for the Visitor " << visitors[visitorID - 1].getName() << " are " << visitors[visitorID - 1].getBill() << endl;
//
//
//            sqlite3_finalize(stmt);
//            rc = sqlite3_bind_double(stmt, 1, visitors[visitorID - 1].getBill());
//            if (rc != SQLITE_OK) {
//                cout << "parameters are not binded correctly..error " << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//            rc = sqlite3_bind_int(stmt, 2, visitorID);
//            if (rc != SQLITE_OK) {
//                cout << "parameters are not binded correctly..error " << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//
//
//            rc = sqlite3_step(stmt);
//            if (rc != SQLITE_DONE) {
//                cout << "bill error " << sqlite3_errmsg(db) << endl;
//                sqlite3_finalize(stmt);
//                sqlite3_close(db);
//                return 1;
//            }
//            cout << "YOUR RECEIPT\n";
//            cout << "Total Charges(bill) for the visitos named " << visitors[visitorID - 1].getName() << " is " << visitors[visitorID - 1].getBill() << endl;
//
//
//            sqlite3_finalize(stmt);
//
//            sqlite3_close(db);
//        }
//        else if (choice == 2) {
//            Admin admin("admin", "password");
//
//            // Login
//            string username, password;
//            cout << "Admin Login" << endl;
//            cout << "Username: ";
//            cin >> username;
//            cout << "Password: ";
//            cin >> password;
//
//            if (admin.login(username, password)) {
//                cout << "Login Successful!" << endl;
//
//                char choice;
//                do {
//                    // Display menu options
//                    cout << "Choose an option:" << endl;
//                    cout << "1. Faculty Management" << endl;
//                    cout << "2. Trainer Management" << endl;
//                    cout << "e. Exit" << endl;
//
//                    cin >> choice;
//
//                    switch (choice) {
//                    case '1': {
//
//                        admin.readFacultyArray();
//
//                        cout << "Faculty Management Menu:" << endl;
//                        cout << "1. Add Faculty" << endl;
//                        cout << "2. Update Faculty" << endl;
//                        cout << "3. Remove Faculty" << endl;
//                        cout << "4. Display Faculty" << endl;
//                        cout << "5. Display Faculty Salaries" << endl;
//                        cout << "e. Exit" << endl;
//
//                        char option;
//                        cin >> option;
//
//                        switch (option) {
//                        case '1': {
//                            // Add Faculty
//                            string name, phoneNumber;
//                            int age, hours, days, id;
//                            char gender;
//
//                            cout << "Enter name: ";
//                            cin >> name;
//                            cout << "Enter ID: ";
//                            cin >> id;
//                            cout << "Enter age: ";
//                            cin >> age;
//                            cout << "Enter gender: ";
//                            cin >> gender;
//                            cout << "Enter phone number: ";
//                            cin >> phoneNumber;
//                            cout << "Enter working hours: ";
//                            cin >> hours;
//                            cout << "Enter working days: ";
//                            cin >> days;
//
//                            admin.addFaculty(name, id, age, gender, phoneNumber, hours, days);
//                            break;
//                        }
//                        case '2': {
//
//                            string name;
//                            int id;
//                            int age;
//                            char gender;
//
//                            cout << "Enter name of faculty to update: ";
//                            cin >> name;
//                            cout << "Enter new ID: ";
//                            cin >> id;
//                            cout << "Enter new age: ";
//                            cin >> age;
//                            cout << "Enter new gender: ";
//                            cin >> gender;
//
//                            admin.updateFaculty(name, id, age, gender);
//                            break;
//                        }
//                        case '3': {
//                            // Remove Faculty
//                            string name;
//                            cout << "Enter name of faculty to remove: ";
//                            cin >> name;
//                            admin.removeFaculty(name);
//                            break;
//                        }
//                        case '4': {
//                            // Display Faculty
//                            admin.displayFaculty();
//                            break;
//                        }
//                        case '5': {
//                            // Display Faculty Salaries
//                            admin.displayFacultySalaries();
//                            break;
//                        }
//                        case 'e':
//                            cout << "Exiting faculty management..." << endl;
//                            break;
//                        default:
//                            cout << "Invalid choice" << endl;
//                        }
//
//                        break;
//                    }
//                    case '2': {
//                        // Trainer Management
//                        // Load trainer data from file
//                        admin.readTrainerArray();
//
//                        // Display trainer management menu
//                        cout << "Trainer Management Menu:" << endl;
//                        cout << "1. Add Trainer" << endl;
//                        cout << "2. Update Trainer" << endl;
//                        cout << "3. Remove Trainer" << endl;
//                        cout << "4. Display Trainers" << endl;
//                        cout << "5. Display Trainer Salaries" << endl;
//                        cout << "e. Exit" << endl;
//
//                        char option;
//                        cin >> option;
//
//                        switch (option) {
//                        case '1': {
//                            // Add Trainer
//                            string name;
//                            int id;
//                            string phoneNumber;
//                            int age, hours, days;
//                            char gender;
//
//                            cout << "Enter name: ";
//                            cin >> name;
//                            cout << "Enter ID: ";
//                            cin >> id;
//                            cout << "Enter age: ";
//                            cin >> age;
//                            cout << "Enter gender: ";
//                            cin >> gender;
//                            cout << "Enter phone number: ";
//                            cin >> phoneNumber;
//                            cout << "Enter working hours: ";
//                            cin >> hours;
//                            cout << "Enter working days: ";
//                            cin >> days;
//
//                            admin.addTrainer(name, id, age, gender, phoneNumber, hours, days);
//                            break;
//                        }
//                        case '2': {
//                            // Update Trainer
//                            string name;
//                            int id;
//                            int age;
//                            char gender;
//
//                            cout << "Enter name of trainer to update: ";
//                            cin >> name;
//                            cout << "Enter new ID: ";
//                            cin >> id;
//                            cout << "Enter new age: ";
//                            cin >> age;
//                            cout << "Enter new gender: ";
//                            cin >> gender;
//
//                            admin.updateTrainer(name, id, age, gender);
//                            break;
//                        }
//                        case '3': {
//                            // Remove Trainer
//                            string name;
//                            cout << "Enter name of trainer to remove: ";
//                            cin >> name;
//                            admin.removeTrainer(name);
//                            break;
//                        }
//                        case '4': {
//                            // Display Trainers
//                            admin.displayTrainers();
//                            break;
//                        }
//                        case '5': {
//                            // Display Trainer Salaries
//                            admin.displayTrainerSalaries();
//                            break;
//                        }
//                        case 'e':
//                            cout << "Exiting trainer management..." << endl;
//                            break;
//                        default:
//                            cout << "Invalid choice" << endl;
//                        }
//
//                        break;
//                    }
//                    case 'e':
//                        cout << "Exiting..." << endl;
//                        break;
//                    default:
//                        cout << "Invalid choice" << endl;
//                    }
//
//                } while (choice != 'e');
//            }
//            else {
//                cout << "Login Failed!" << endl;
//            }
//        }
//    }
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//}