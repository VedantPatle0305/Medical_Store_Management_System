#include <iostream>
#include <fstream>
using namespace std;
class Customer_input
{
private:
    string name;
    string medicine;
    string address;
    int n;
    int amt[100];

public:
    void enterdetails(void)
    {
        /// using file handling here to write the data taken from customer into the file named customer.txt
        ofstream fout("customer.txt", ios::out | ios::app);
        cout << "\n\nEnter Customer Name: ";
        cin >> name;
        fout << name << endl;
        cout << "Enter address of Customer: ";
        cin >> address;
        fout << address << endl;
        cout << "Enter number of medicine: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Medicine Name: ";
            cin >> medicine;
            cout << "Enter amount: ";
            cin >> amt[i];
        }
        fout.close();
    }
    void flread()
    {
        // reading all the data from the file named customer.txt to print
        ifstream fin("customer.txt", ios::in);
        string a, b;
        fin >> a;
        fin >> b;
        while (!fin.eof())
        {
            cout << "Name: " << a << endl;
            cout << "Address: " << b << endl;
            fin >> a;
            fin >> b;
        }
        fin.close();
    }
    // created the virtual function named display to implement the concept of functionoverriding
    virtual void display()
    {
        cout << endl;
        int sum = 0;
        for (int i = 0; i < Customer_input::n; i++)
        {
            sum += amt[i];
        }
        cout << "CUSTOMER NAME: " << Customer_input::name << "\nCUSTOMER ADDRESS: " << Customer_input::address << "\nNUMBER OF MEDICINE: " << Customer_input::n << "\n\n\tTOTAL AMOUNT TO BE PAID: " << sum << endl;
    }
};
// Deriving Payment class from Customer_input class
class Payment : public Customer_input
{
    char option;
    string pin[4];
    string id;

public:
    Customer_input *ptr;
    void display()
    {
        cout << "\n\n---------------------------Welcome to the payment section-- -- -- -- -- -- -- -- -- -- -- -- -- -\n "
             << endl;
        cout << "Mode of payment\n1. Cash\n2. Card\n3. UPI\n"
             << endl;
        cout << "Enter the option: ";
        cin >> option;
        switch (option)
        {
        case '1':
        {
            cout << "Payment Successfully Done.";
            break;
        }
        case '2':
        {
            cout << "Enter PIN: ";
            cin >> pin[4];
            cout << "Payment Successfully Done.";
            break;
        }
        case '3':
        {
            cout << "Enter Transaction ID: ";
            cin >> id;
            cout << "Payment Successfully Done.";
            break;
        }
        default:
            cout << "INVALID CHOICE........";
            break;
        }
        cout << "\n\n\t\t\t------------Thank you--------------" << endl;
    }
    void pay()
    {
        // calling the function of
        Payment obj;
        ptr = &obj;
        ptr->display();
    }
};
struct med
{
    string meds;
    int mrp;
    string info;
};
template <typename T>
class stocks
{
    string medname;
    int n;
    string med;
    int quan;
    T amt[100];
    struct med medicine[10];

public:
    string temp;
    stocks()
    {
        medicine[0].meds = "Paracetamol";
        medicine[0].mrp = 12;
        medicine[0].info = "Paracetamol is a medicine used to relieve pain and to reduce fever.It is used to treat many conditions such as headaches, body aches, toothaches, and the common cold.It works by inhibiting the release of certain chemicals that cause pain and fever.";
        medicine[1].meds = "Combiflam";
        medicine[1].mrp = 10;
        medicine[1].info = "Combiflam Tablet combines two medicines that work as painkillers.They're working together to reduce pain,  fever, and inflammation.It is used to treat many conditions such as headache, muscle pain, period pain, toothache, and joint pain.";
        medicine[2].meds = "Crocin";
        medicine[2].mrp = 15;
        medicine[2].info = "Crocin Pain Relief provides targeted pain relief.It provides symptomatic relief from mild to moderate pain e.g     from headache, migraine, toothache and musculoskeletal pain.Its formula contains clinically proven ingredients paracetamol and caffeine.It acts at the center of pain..";
        medicine[3].meds = "Erythromycin";
        medicine[3].mrp = 35;
        medicine[3].info = "Erythromycin is known as a macrolide antibiotic. It works by stopping the growth of bacteria. This antibiotic treats or prevents only bacterial infections. It will not work for viral infections (such as common cold, flu)..";
        medicine[4].meds = "Soframycin";
        medicine[4].mrp = 32;
        medicine[4].info = "Soframycin is used to treat bacterial infection of the eye or ear. Soframycin is an antibiotic of the aminoglycoside class. It works by killing bacteria. Your doctor may have prescribed Soframycin for another reason.";
        medicine[5].meds = "Dolo650";
        medicine[5].mrp = 73;
        medicine[5].info = "Dolo 650 Tablet is a common painkiller used to treat aches and pains.It works by blocking chemical messengers in the brain that tell us we have pain.It is effective in relieving pain caused by headache, migraine, nerve pain, toothache, sore throat, period menstrual) pains, arthritis, and muscle aches.";
        medicine[6].meds = "Metformin";
        medicine[6].mrp = 49;
        medicine[6].info = "Metformin is an oral diabetes medicine that helps control blood sugar levels. Metformin is used together with diet and exercise to improve blood sugar control in adults with type 2 diabetes mellitus. Metformin is sometimes used together with insulin or other medications, but it is not for treating type 1 diabetes.";
        medicine[7].meds = "sorafenib";
        medicine[7].mrp = 44;
        medicine[7].info = "Sorafenib is also used to treat hepatocellular carcinoma(a type of liver cancer) that cannot be treated with surgery and   a certain type of thyroid cancer that has spread to other parts of the body and cannot be treated with radioactive iodine.Sorafenib is in a class of medications called kinase inhibitors.";
        medicine[8].meds = "Warfarin";
        medicine[8].mrp = 37;
        medicine[8].info = "Warfarin is used to prevent blood clots from forming or growing larger in your blood and blood vessels. It is prescribed for people with certain types of irregular heartbeat, people with prosthetic (replacement or mechanical) heart valves, and people who have suffered a heart attack.";
        medicine[9].meds = "paricr";
        medicine[9].mrp = 82;
        medicine[9].info = "Pari CR 12.5 Tablet 15's is used to treat anxiety disorders such as obsessive - compulsive disorder(OCD), panic disorder, social anxiety disorder, post - traumatic stress disorder, premenstrual dysphoric disorder, and generalised anxiety isorder.";
    }
    // operator overloading, we have overloaded == operator to comapre the medicine name to find the info of that particular medicine 
    void operator==(stocks obj)
    {
        bool flag = 0;
        for (int i = 0; i < 10; i++)
        {
            if (temp == obj.medicine[i].meds)
            {
                flag = 1;
                cout << "\nDetails about the " << temp << ":\n";
                cout << "Name of medicines:" << temp << endl;
                cout << "\nInfo : " << obj.medicine[i].info << endl;
                cout << "\nMRP: " << obj.medicine[i].mrp << endl;
                return;
            }
        }
        if (flag == 1)
        {
            cout << "\nNo data found!\n";
        }
    }
    void available_stock()
    {
        cout << "------------------------MEDICINE IN STOCK-------------------------\n "
             << endl;
        cout << "MEDICINE NAME\tQUANTITY\tMRP" << endl;
        cout << "Paracetamol\t20\t\t12" << endl;
        cout << "Combiflam\t30\t\t10" << endl;
        cout << "Crocin\t\t25\t\t15" << endl;
        cout << "Erythromycin\t30\t\t35" << endl;
        cout << "Soframycin\t50\t\t32" << endl;
        cout << "Dolo650\t\t40\t\t73" << endl;
        cout << "Metformin\t25\t\t49" << endl;
        cout << "sorafenib\t30\t\t44" << endl;
        cout << "Warfarin\t40\t\t37" << endl;
        cout << "paricr\t\t20\t\t82" << endl;
    }
};
// class template is implemented here
template <typename T>
class buy
{
    string medname;
    int n;
    string med;
    int quan;
    T amt[100];

public:
    void required_stock()
    {
        cout << "Enter the number of medicine you want to order: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Medicine name: ";
            cin >> med;
            cout << "Quantity of box: ";
            cin >> quan;
            cout << "Enter amount of medicine: ";
            cin >> amt[i];
            amt[i] = quan * amt[i];
        }
    }
    // Exception handling is introduced in this function
    void display()
    {
        cout << endl;
        int sum = 0;
        try
        {
            for (int i = 0; i < n; i++)
            {
                sum += amt[i];
            }
            if (sum == 0)
            {
                throw sum;
            }
        }
        catch (int ex)
        {
            cout << "No Amount to be paid\n"
                 << endl;
            cout << "DO ZERO TRANSACTION\n"
                 << endl;
        }
        cout << "TOTAL AMOUNT TO BE PAID: " << sum << endl;
    }
};
// Admin
class Admin : public Customer_input
{
    string username, uname;
    string password, upwd;
    char pass1[10], ch;
    int i;

public:
    void store()
    {
        username = "Admin";
        password = "Admin@123";
    }
    void retrieve()
    {
        cout << "Enter userName: ";
        cin >> uname;
        cout << "Enter passWord: ";
        cin >> upwd;
    }
    int check()
    {
        if (uname == username)
        {
            if (upwd == password)
            {
                cout << "\nPassword matched\n";
                return 1;
            }
            else
            {
                cout << "\nInvalid Password\n";
                return 0;
            }
        }
        else
        {
            cout << "\nInvalid Username\n";
            return 0;
        }
    }
};
int main()
{
    system("CLS"); // to clear the screen
    stocks<int> objtemp;
    Admin A;
    Customer_input in;
    Payment p;
    stocks<int> s;
    buy<int> b;
    int n;
    char want;
    char want2;
    string temp;
    int help;
    int price;
    int choice;
    do
    {
        cout << "\n\n\t#################### WELCOME TO MEDICAL STORE MANAGEMENT SYSTEM####################\n\n " << endl;
        cout << "\nEnter who you are?\n1)Admin\n2)Customer\n\nEnter: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        up:
            A.store();
            A.retrieve();
            if (A.check())
            {
                cout << "\nNames and the addresses of the customer till date :\n\n ";
                A.flread();
            }
            else
            {
                goto up;
            }
            break;
        case 2:
            do
            {
                cout << "\t\t\t\t--------MAIN MENU---------\n"
                     << endl;
                cout << "1:: Customer Login\n2:: Medicine info\n3:: Buy Stocks\n4::Quit\n\n "
                     << endl;
                cout << "Enter Choice: ";
                cin >> n;
                cout << endl;
                switch (n)
                {
                case 1:
                {
                    cout << "\n\n\t\t\t---------WELCOME TO THE CUSTOMER INPUT SECTION-- -- -- -- -" << endl;
                    // inheritance
                    in.enterdetails();
                    in.flread();
                    in.display();
                    cout << "\n\n\t\t\t\tPROCEED TO PAY THE AMOUNT ";
                    p.pay();
                    break;
                }
                case 2:
                {
                    s.available_stock();
                    cout << "\nEnter midicine name to be searched: ";
                    cin >> objtemp.temp;
                    // implementation of function overriding
                    objtemp == s;
                    cout << "\n\t\t----------THANK YOU----------\n" << endl;
                    break;
                }
                case 3:
                {
                    cout << "\n\n\t\t------ENTER DETAILS TO BUY STOCK-- -- -\n ";
                            b.required_stock();
                    b.display();
                    cout << "\n\n\t\t\t\tPROCEED TO PAY THE AMOUNT\n ";
                            p.pay();
                    break;
                }
                case 4:
                {
                    return 0;
                }
                default:
                {
                    cout << "INVALID CHOICE........." << endl;
                }
                }
                cout << "\n\nDo you want to continue as a customer(y/n): ";
                cin >>
                    want;
                cout << endl;
            } while (want != 'n');
            cout << "\n\n";
            break;
        default:
            cout << "\nEnter a valid choice!";
            break;
        }
        cout << "\nEnter (y/n) if you want continue using the system :";
        cin >> want2;
    } while (want2 != 'n');
    return 0;
}