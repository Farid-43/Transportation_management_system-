#include <bits/stdc++.h>
using namespace std;
void mainMenu();
void mainMenu1();
void firstPage();
void displayMenu();
void foodOptions();

class management
{
public:
    void firstPage()
    {
        cout << "\n___________________________________________________________________________________" << endl;
        cout << "____________________________WELCOME TO BD AIRLINES______________________________" << endl
             << endl;
        cout << "\t\t|\t 1. Admin Mode    \t|" << endl;
        cout << "\t\t|\t 2. User Mode     \t|" << endl;
        cout << "\t\t|\t 3. Exit          \t|" << endl;
        int choice;
        string id = "admin";
        string password = "admin";
        string eid, pass;
        cout << "Select: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "____________________________________________________________" << endl;
            cout << endl
                 << "Enter Admin Username: ";
            cin >> eid;
            if (id == eid)
            {
                cout << "\nEnter Admin Password: ";
                cin >> pass;
                if (pass == password)
                    mainMenu();
                else
                    cout << "Password is wrong, Please try again!" << endl;
                firstPage();
            }
            else
            {
                cout << "Entered Admin ID is wrong, Please Try Again!" << endl;
                firstPage();
            }
            break;
        }
        case 2:
        {
            cout << "\n_______________________________________________________________________________" << endl;
            cout << "WELCOME TO USER MODE" << endl;
            cout << "\t1. Create New Account" << endl;
            cout << "\t2. Login using existing account" << endl;
            cout << "\n\tSelect: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                string uid, upass;
                cout << "______________________________CREATING NEW ACCOUNT_________________________________" << endl;
                cout << "\nEnter the New ID: ";
                cin >> uid;
                cout << "\nEnter Password: ";
                cin >> upass;
                fstream in("user.txt", ios::app); // ios::app == append mode
                in << uid << " " << upass << endl;
                in.close();
                cout << "New User ID created!";
                cout << "Your User ID is " << uid << " and password is " << upass << endl;
                cout << "Use this as Login Credentials!" << endl
                     << endl;
                firstPage();
                break;
            }
            case 2:
            {
                cout << "__________________________________LOGING IN_______________________________________" << endl;
                string uid, upass;
                string cuid, cupass;
                cout << "\nEnter ID: ";
                cin >> uid;
                cout << "\nEnter Password: ";
                cin >> upass;
                fstream f1("user.txt", ios::in); // ios::in == input mode
                while (!f1.eof())
                {
                    f1 >> cuid >> cupass;
                    cout << endl;
                    if (uid == cuid && upass == cupass)
                    {
                        cout << "\nCredentials Matched!" << endl;
                        cout << "\n_____________________________________________________________________________________" << endl;
                        mainMenu1();
                        firstPage();
                        return;
                    }
                }
                cout << "Please enter correct details" << endl;
                cout << "\n_____________________________________________________________________________________" << endl;
                firstPage();
                break;
            }
            default:
                break;
            }
            break;
        }
        case 3:
        {
            cout << "___________________Thanks for using BD AIRLINES_____________________" << endl
                 << endl;
            exit(0);
        }
        }
    }
};

class TicketDetails
{
public:
    virtual void displayTicketDetails() = 0; // Pure virtual
};
class Details : public TicketDetails
{
public:
    static string name[5], gender[5];
    int phoneNo;
    static int age[5], cId[5], pnr, n;
    char arr[100];
    void information()
    {
        srand(time(NULL)); //  This is a function that sets the seed value for the random number generator
        pnr = 100000000 + (rand() % 90000000);
        cout << "\nYour PNR number is: " << pnr << endl;
        cout << "\nEnter the number of passengers: ";
        cin >> n;
        if (n > 5)
        {
            cout << "You can book tickets for only 5 passengers in a ticket!" << endl;
            mainMenu();
        }
        for (int i = 0; i < n; i++)
        {
            cout << "\n Enter the customer ID :";
            cin >> cId[i];
            cout << "\n Enter the Name :";
            cin >> name[i];
            cout << "\n Enter the age :";
            cin >> age[i];
            cout << "\n Gender:";
            cin >> gender[i];
        }
        cout << "Yours details are saved with us.\n";
        cout << "Your PNR number is: " << pnr << endl;
        cout << "Please use this PNR number to book tickets!" << endl
             << endl;
    }
    virtual void displayInfo()
    {
        cout << "Passenger Information:\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Name: " << name[i] << ", Age: " << age[i] << ", Gender: " << gender[i] << endl;
        }
    }
    void displayTicketDetails() override
    {
        cout << "Passenger Information:\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Name: " << name[i] << ", Age: " << age[i] << ", Gender: " << gender[i] << endl;
        }
    }

    friend ostream &operator<<(ostream &os, Details &details)
    {
        details.displayTicketDetails();
        return os;
    }
};
int Details::cId[5];
string Details::name[5];
string Details::gender[5];
int Details::pnr;
int Details::age[5];
int Details::n;
class registration : public Details
{
public:
    static int choice;
    int choice1, back;
    static float charges;
    void trains()
    {
        string plainsN[] = {"Dhaka", "Chittagong", "Cumilla", "Khulna", "Rangpur"};
        for (int a = 0; a < 5; a++)
        {
            cout << (a + 1) << ".train to " << plainsN[a] << endl;
        }
        cout << "\nWELCOME TO THE AIRLINES!" << endl;
        cout << "Press the number of the city you want to book:";
        cin >> choice;
        int f;
        cout << "WELCOME TO " << plainsN[choice - 1] << endl;
        cout << " your comfort is our priority , Enjoy the journey!" << endl;
        cout << " Following are the Plains \n"
             << endl;
        cout << "1. " << plainsN[choice - 1] << " 123" << endl;
        cout << "\t30-10-2023  8:00AM  10hrs  3A-Rs.700 2A-Rs.1000 1A-Rs.1500" << endl;
        cout << "2. " << plainsN[choice - 1] << " 234" << endl;
        cout << "\t30-10-2023  10:00AM  9hrs  3A-Rs.800 2A-Rs.1050 1A-Rs.1550" << endl;
        cout << "3. " << plainsN[choice - 1] << " 007" << endl;
        cout << "\t30-10-2023  9:00pm  10hrs  3A-Rs.700 2A-Rs.1000 1A-Rs.1500" << endl;
        cin >> choice1;
        cout << "\n Enter the class in which u want to travel : ";
        cin >> f;
        if (choice1 == 1)
        {
            if (f == 3)
            {
                charges = 700;
            }
            else if (f == 2)
            {
                charges = 1000;
            }
            else if (f == 1)
            {
                charges = 1500;
            }
            cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN " << plainsN[choice - 1] << " " << 123 << endl;
            cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
        }
        else if (choice1 == 2)
        {
            if (f == 3)
            {
                charges = 800;
            }
            else if (f == 2)
            {
                charges = 1050;
            }
            else if (f == 1)
            {
                charges = 1550;
            }
            cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN " << plainsN[choice - 1] << " " << 234 << endl;
            cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
        }
        else if (choice1 == 3)
        {
            if (f == 3)
            {
                charges = 700;
            }
            else if (f == 2)
            {
                charges = 1000;
            }
            else if (f == 1)
            {
                charges = 1500;
            }
            cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN " << plainsN[choice - 1] << " 007" << endl;
            cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
        }
        else
        {
            cout << " Invalid input,shifting to previous menu" << endl;
            trains();
        }
        cout << " press any key to go back to the main menu: " << endl;
        cin >> back;
        mainMenu();
    }
    virtual void dispDatabase(){

    };
};
float registration::charges;
int registration::choice;
class ticket : public registration
{
public:
    void Bill()
    {
        string destination[5] = {};
        for (int i = 0; i < n; i++)
        {
            ofstream outf("tickets.txt", ios::app);
            ofstream oo("record.txt", ios::out); //
            {
                oo << pnr << "\t\t|";
                oo << cId[i] << "\t\t|";
                oo << name[i] << "\t|";
                oo << gender[i] << "\t|";

                outf << pnr << "\t\t|";
                outf << cId[i] << "\t\t|";
                outf << name[i] << "\t|";
                outf << gender[i] << "\t|";
                if (registration::choice == 1)
                {
                    destination[i] = "Dhaka";
                }
                else if (registration::choice == 2)
                {
                    destination[i] = "Chittagong";
                }
                else if (registration::choice == 3)
                {
                    destination[i] = "Cumilla";
                }
                else if (registration::choice == 4)
                {
                    destination[i] = "Khulna";
                }
                else if (registration::choice == 5)
                {
                    destination[i] = "Rangpur";
                }
                outf << destination[i] << "\t\t|";
                outf << registration::charges << "\t|";
                outf << endl;
            }
            outf.close();
        }
        cout << "Total Cost: " << charges * n;
    }
    void database()
    {
        string destination[5] = {};
        for (int i = 0; i < n; i++)
        {
            ofstream outf("records.txt", ios::app);
            ofstream oo("record.txt", ios::out);
            {
                oo << pnr << "\t\t|";
                oo << cId[i] << "\t\t|";
                oo << name[i] << "\t|";
                oo << gender[i] << "\t|";

                outf << pnr << " ";
                outf << cId[i] << " ";
                outf << name[i] << " ";
                outf << gender[i] << " ";
                if (registration::choice == 1)
                {
                    destination[i] = "Dhaka";
                }
                else if (registration::choice == 2)
                {
                    destination[i] = "Chittagong";
                }
                else if (registration::choice == 3)
                {
                    destination[i] = "Cumilla";
                }
                else if (registration::choice == 4)
                {
                    destination[i] = "Khulna";
                }
                else if (registration::choice == 5)
                {
                    destination[i] = "Rangpur";
                }
                outf << destination[i] << " ";
                outf << registration::charges;
                outf << endl;
            }
            outf.close();
        }
    }
    void dispBill()
    {
        cout << "____BD AIRLINES_____" << endl;
        cout << "____Tickets______" << endl;
        cout << "___________" << endl
             << endl;
        ;
        cout << "PNR Num\t\t\t|"
             << "Customer ID\t|"
             << "Name\t|"
             << "Gender\t|"
             << endl;
        ifstream ifs("record.txt");
        {
            if (!ifs)
            {
                cout << "File error!" << endl;
            }
            while (!ifs.eof())
            {
                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }
        ifs.close();
    }
    void dispDatabase()
    {
        string cpnr, cid, cname, cgen, cdest, ccharge;

        cout << "____BD AIRLINES_____" << endl;

        cout << "____Tickets______" << endl;
        cout << "___________" << endl
             << endl;
        cout << "|PNR Num\t|"
             << "Customer ID\t|"
             << "Name\t\t|"
             << "Gender\t|"
             << "Destination\t|"
             << endl;
        ifstream ifs;
        ifs.open("records.txt");
        while (ifs >> cpnr >> cid >> cname >> cgen >> cdest >> ccharge)
        {
            cout << "|" << cpnr << "\t|" << cid << "\t\t|" << cname << "\t\t|" << cgen << "\t|" << cdest << "\t\t|Rs. " << ccharge << "\t|" << endl;
        }
        ifs.close();
        cout << endl;
    }
    void deletedata()
    {
        ticket obj;
        int w;
        cout << "Enter PNR no.:" << endl;
        cin >> w;
        string line;
        int cpnr, ccharges, ccid;
        string cname, cgen, cdest;
        ifstream myfile;
        ofstream temp;
        myfile.open("records.txt");
        temp.open("temp.txt");
        while (myfile >> cpnr >> ccid >> cname >> cgen >> cdest >> ccharges)
        {
            if (cpnr != w)
                temp << cpnr << " " << ccid << " " << cname << " " << cgen << " " << cdest << " " << ccharges << endl
                     << flush;
        }
        cout << "The record with the name " << w << " has been deleted if it exsisted" << endl;
        myfile.close();
        temp.close();
        remove("records.txt");
        getchar();
        rename("temp.txt", "records.txt");
    }
};
class orderFood : public ticket
{
public:
    string fpnr, cpnr, cname, ccid, cgen, cdest, ccharges;
    int fcharges;
    void foodOptions()
    {
        cout << "\n____________________________________________________________________" << endl;
        cout << "____________________WELCOME TO CATERING SERVICE_______________________" << endl
             << endl;
        cout << "\t1. View Menu and Order Food" << endl;
        cout << "\t2. Print Receipt" << endl;
        cout << "\t3. Back" << endl;
        cin >> choice1;
        cout << endl;
        switch (choice1)
        {
        case 1:
        {
            char filename[] = "foodr.txt";
            remove(filename);
            getDetails();
            break;
        }
        case 2:
        {
            displayFoodReceipt();
            break;
        }
        case 3:
        {
            mainMenu();
            break;
        }
        default:
        {
            cout << "Invalid Option! Try Again!" << endl;
            foodOptions();
        }
        }
    }
    void getDetails()
    {
        cout << "\n____________________________________________________________________" << endl;
        cout << "Enter Details to continue" << endl;
        cout << "\tEnter Your PNR number: ";
        cin >> fpnr;
        ifstream f1;
        f1.open("records.txt");
        do
        {
            if (f1.eof())
            {
                cout << "PNR does not match with our record!\nPlease Enter a valid PNR! " << endl;
                f1.close();
                getDetails();
            }
            f1 >> cpnr >> ccid >> cname >> cgen >> cdest >> ccharges;
        } while (cpnr != fpnr);
        f1.close();
        if (cpnr == fpnr)
        {
            cout << "Welcome " << cname << "! Please find the Menu!" << endl;
            displayMenu();
        }
        else
        {
            cout << "Try Again" << endl;
            getDetails();
        }
    }
    void displayMenu()
    {
        fcharges = 0;
        cout << "\n____________________________________________________________________" << endl;
        cout << "____________________________FOOD MENU_________________________________" << endl
             << endl;
        cout << "\t|S.no."
             << "\t|Item Name"
             << "\t\t\t|Price"
             << "\t\t|" << endl;
        cout << "\t|1."
             << "\t|Burger"
             << "\t\t\t\t|Rs. 100"
             << "\t\t|" << endl;
        cout << "\t|2."
             << "\t|Burger"
             << "\t\t\t\t|Rs. 210"
             << "\t\t|" << endl;
        cout << "\t|3."
             << "\t|Grill\t"
             << "\t\t\t|Rs. 100"
             << "\t\t|" << endl;
        cout << "\t|4."
             << "\t|Sandwich"
             << "\t\t\t|Rs. 99"
             << "\t\t|" << endl;
        cout << "\t|5."
             << "\t|Coffee"
             << "\t\t\t\t|Rs. 25"
             << "\t\t|" << endl;
        cout << "\t|6."
             << "\t|Tea\t"
             << "\t\t\t|Rs. 15"
             << "\t\t|" << endl;

        int choicess[6], noOfItems;
        cout << "Enter the number of Items you want to book: " << endl;
        cin >> noOfItems;
        for (int i = 0; i < noOfItems; i++)
        {
        tryagain:
            cout << "Enter your Choice " << i + 1 << ": ";
            cin >> choicess[i];
            cout << endl;
            fstream f2;
            fstream f3;
            f2.open("foodr.txt", ios::app);
            f3.open("foodd.txt", ios::app);
            switch (choicess[i])
            {
            case 1:
            {
                cout << "\tBurger" << endl;
                fcharges += 100;
                f2 << cpnr;
                f2 << "\t|Burger"
                   << "\t\t"
                   << "Rs. 100" << endl;
                f3 << cpnr << " Burger"
                   << " 100" << endl;
                break;
            }
            case 2:
            {
                cout << "\tBurger" << endl;
                fcharges += 210;
                f2 << cpnr;
                f2 << "\t|Burger"
                   << "\t\t"
                   << "Rs. 210" << endl;
                f3 << cpnr << " Burger"
                   << " 210" << endl;
                break;
            }
            case 3:
            {
                cout << "Grill " << endl;
                fcharges += 100;
                f2 << cpnr;
                f2 << "\t|Grill"
                   << "\t\t"
                   << "Rs. 100" << endl;
                f3 << cpnr << "Grill"
                   << " 100" << endl;
                break;
            }
            case 4:
            {
                cout << "Sandwich" << endl;
                fcharges += 99;
                f2 << cpnr;
                f2 << "\t|Sandwich"
                   << "\t\t"
                   << "Rs. 99" << endl;
                f3 << cpnr << " Sandwich"
                   << " 99" << endl;
                break;
            }
            case 5:
            {
                cout << "Coffee" << endl;
                fcharges += 25;
                f2 << cpnr;
                f2 << "\t|Coffee"
                   << "\t\t"
                   << "Rs. 25" << endl;
                f3 << cpnr << " Coffee"
                   << " 25" << endl;
                break;
            }
            case 6:
            {
                cout << "Tea" << endl;
                fcharges += 15;
                f2 << cpnr;
                f2 << "\t|Tea"
                   << "\t\t"
                   << "Rs. 15" << endl;
                f3 << cpnr << " Tea"
                   << " 15" << endl;
                break;
            }
            default:
            {
                cout << "Enter Valid Input!\n";
                f2.close();
                f3.close();
                goto tryagain;
                break;
            }
            }
            f2.close();
            f3.close();
        }
        cout << "Order Placed Successfully! Please collect your Reciept by Print Reciept option!" << endl;
        system("pause");
        foodOptions();
    }
    void displayFoodReceipt()
    {
        cout << "\n________________________________________________________________________" << endl;
        cout << "____________________________ORDER RECIEPT_________________________________" << endl
             << endl;
        cout << "\tPassenger Details:\n";
        cout << "\t|PNR Num\t\t|"
             << "Name\t|"
             << "Gender\t|"
             << "Destination\t|"
             << endl;
        cout << "\t|" << cpnr << "\t\t|" << cname << "\t|" << cgen << "\t" << cdest << "\t\t|" << endl
             << endl;
        cout << "\tOrdered Food Details:\n";
        ifstream f4("foodr.txt");
        {
            if (!f4)
            {
                cout << "File error!" << endl;
            }

            while (!f4.eof())
            {
                f4.getline(arr, 100);
                cout << arr << endl;
            }
        }
        f4.close();
        system("pause");
        foodOptions();
    }
    void displayFoodDatabase()
    {

        string food1, food2, food3, price;
        cout << "\n________________________________________________________________________" << endl;
        cout << "____________________________FOOD DATABASE_________________________________" << endl
             << endl;
        cout << "\t|PNR no\t\t|Item Name\t|Price\t|" << endl;
        ;
        fstream f5("foodd.txt", ios::in);
        while (f5 >> cpnr >> food1 >> price)
        {
            cout << "\t|" << cpnr << "\t|" << food1 << "\t|Rs. \t" << price << "\t|" << endl;
            // cout << flush;
        }
        f5.close();
        system("pause");
    }
};

void mainMenu()
{
    int lchoice;
    int schoice, back;
    cout << "\t               BD AIRLINES " << endl
         << endl;
    cout << "\t_________________________Main Menu_______________________" << endl;
    cout << "\t___________________________________________________________" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t|\t Press 1 to add the Customer Details    \t|" << endl;
    cout << "\t|\t Press 2 for TIcket Booking              \t|" << endl;
    cout << "\t|\t Press 3 for Ticket and Charges         \t|" << endl;
    cout << "\t|\t Press 4 to display Database            \t|" << endl;
    cout << "\t|\t Press 5 to Cancel                      \t|" << endl;
    cout << "\t|\t Press 6 to view FOOD Database          \t|" << endl;
    cout << "\t|\t Press 7 to Order Food                  \t|" << endl;
    cout << "\t|\t Press 8 to exit                        \t|" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t___________________________________________________________" << endl;
    cout << "Enter the Choice: ";
    cin >> lchoice;
    Details d;
    registration r;
    ticket t;
    orderFood f;
    switch (lchoice)
    {
    case 1:
    {
        Details d;
        d.information();
        cout << d; // operator overloading
        mainMenu();
        break;
    }
    case 2:
    {
        cout << "___Book a ticket in this section__" << endl
             << endl;
        r.trains();
        break;
    }
    case 3:
    {
        cout << "____Getting your Ticket___" << endl
             << endl;
        t.Bill();
        cout << "Your Ticket is printed, you can collect it" << endl
             << endl;
        cout << "Press 1 to display your ticket ";
        cin >> back;
        if (back == 1)
        {
            t.dispBill();
            t.database();
            cout << "Press any key to go back" << endl;
            cin >> back;
        }
        mainMenu();
        break;
    }
    case 4:
    {
        t.dispDatabase();
        cout << "Press any key to go back" << endl;
        cin >> back;
        mainMenu();
        break;
    }
    case 5:
    {
        t.deletedata();
        cout << "Press any key to go back" << endl;
        cin >> back;
        mainMenu();
        break;
    }
    case 6:
    {
        f.displayFoodDatabase();
        mainMenu();
        break;
    }
    case 7:
    {
        f.displayMenu();
        mainMenu();
        break;
    }
    case 8:
    {
        cout << endl
             << endl;
        return;
        break;
    }
    default:
    {
        cout << "Invalid Input, Please try again!" << endl
             << endl;
        mainMenu();
        break;
    }
    }
}

void mainMenu1()
{
    int lchoice;
    int schoice, back;
    cout << "\t               BD AIRLINES " << endl
         << endl;
    cout << "\t_________________________Main Menu_______________________" << endl;
    cout << "\t___________________________________________________________" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t|\t Press 1 to add the Customer Details    \t|" << endl;
    cout << "\t|\t Press 2 for TIcket Booking              \t|" << endl;
    cout << "\t|\t Press 3 for Ticket and Charges         \t|" << endl;
    cout << "\t|\t Press 4 to Cancel                      \t|" << endl;
    cout << "\t|\t Press 5 to Order Food                  \t|" << endl;
    cout << "\t|\t Press 6 to exit                        \t|" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t___________________________________________________________" << endl;
    cout << "Enter the Choice: ";
    cin >> lchoice;
    Details d;
    registration r;
    ticket t;
    orderFood f;
    switch (lchoice)
    {
    case 1:
    {
        Details d;
        d.information();
        cout << d; // operator overloading
        mainMenu1();
        break;
    }
    case 2:
    {
        cout << "___Book a ticket in this section__" << endl
             << endl;
        r.trains();
        break;
    }
    case 3:
    {
        cout << "____Getting your Ticket___" << endl
             << endl;
        t.Bill();
        cout << "Your Ticket is printed, you can collect it" << endl
             << endl;
        cout << "Press 1 to display your ticket ";
        cin >> back;
        if (back == 1)
        {
            t.dispBill();
            t.database();
            cout << "Press any key to go back" << endl;
            cin >> back;
        }
        mainMenu1();
        break;
    }
    case 4:
    {
        t.deletedata();
        cout << "Press any key to go back" << endl;
        cin >> back;
        mainMenu1();
        break;
    }
    case 5:
    {
        f.displayMenu();
        mainMenu1();
        break;
    }
    case 6:
    {
        cout << endl
             << endl;
        return;
        break;
    }
    default:
    {
        cout << "Invalid Input, Please try again!" << endl
             << endl;
        mainMenu1();
        break;
    }
    }
}

template <typename T>
void CallFirstPage(T &obj)
{
    if (typeid(obj) == typeid(management))
    {
        obj.firstPage();
    }
}
int main()
{
    management obj;
    CallFirstPage(obj);
    return 0;
}