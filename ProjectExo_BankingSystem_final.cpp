#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
#include <stdlib.h>
#include <limits>
using namespace std;
class Bank
{
    string bank_name = "India Bank Limited";
    string bank_IFSC = "IBL005710";
    string bank_address = "Board Office, MP Nagar, Bhopal-462011";

public:
    void welcomeMessage();
    string getbname();
    string getaddress();
    string getIFSc();
};
void Bank::welcomeMessage()
{
    system("Color 0A");

    cout << "\nWelcome to " << bank_name << endl;
    cout << "Address: " << bank_address << endl;
    cout << "IFSC:" << bank_IFSC << endl;
    cout << "\nHello Sir/Madam... \n\n Please select the option from the following menu to proceed: " << endl;
}
string Bank::getaddress()
{
    return bank_address;
}
string Bank::getbname()
{
    return bank_name;
}
string Bank::getIFSc()
{
    return bank_IFSC;
}
class NewUser : public Bank
{
private:
    string cname;
    int cage;
    string cmob;
    string cdob;
    string cpinCode;
    string caddress;
    string accType;
    string cID;
    static string accNum;
    string userId;
    int loginPassword;
    string transactionPIN;
    string acc1;

    string acc;

public:
    void getPersonalDetails();
    string getcname();
    void modifycname(string);
    int getcage();
    void modifycage(int);
    string getcDob();
    void modifycDob(string);
    string getcpincode();
    void modifycpinCode(string);
    string getcmob();
    void modifycmob(string);
    string getcaddress();
    void modifyaccType(string);
    string getaccType();
    string getcID();
    void modifycaddress(string);
    string getUserId();
    int getloginPassword();
    string putdata();
    void createTransactionPin();
    string getTransactionPin();
    string getacc();
    void generateAccountNum(const string &dob, const string &mobile, const string &cpinCode, const string &cID);
    void getLogindetail();
    void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

private:
    void shuffleAccNum(string);
    static string getcDobPart(const string &cdob)
    {
        string dobPart;

        for (char ch : cdob)
        {
            if (ch != '-' && ch != '/')
            {
                dobPart += ch;
            }
            dobPart = dobPart.substr(0, 4);
        }
        return dobPart;
    }
    static string getcmobPart(const string &cmob)
    {
        string mobilePart = cmob.substr(10 - 3);
        return mobilePart;
    }
    static string getcpincodePart(const string &cpinCode)
    {
        string cpinCodePart = cpinCode.substr(cpinCode.length() - 2);
        return cpinCodePart;
    }
    static string getcIDPart(const string &cID)
    {
        string cIDPart = cID.substr(cID.length() - 4);
        return cIDPart;
    }
};
void NewUser::getLogindetail()
{
    cout << "Create Your User Name: \n";
    cin >> userId;
    cout << "Create Your Login Password(Numbers only-4to8 Digits): \n";
    cin >> loginPassword;
}
void NewUser::createTransactionPin()
{
    cout << "Create Your 6-digit Transaction PIN: \n";
    cin >> transactionPIN;
}

string NewUser::putdata()
{
    cout << cname << "\n Age : " << cage << "\n Your Mobile number : " << cmob;
}
int NewUser::getcage()
{
    return cage;
}
string NewUser::getcDob()
{
    return cdob;
}
string NewUser::getcmob()
{
    return cmob;
}
string NewUser::getcname()
{
    return cname;
}
string NewUser::getcpincode()
{
    return cpinCode;
}
string NewUser::getcaddress()
{
    return caddress;
}
string NewUser::getUserId()
{
    return userId;
}
string NewUser::getaccType()
{
    return accType;
}
string NewUser::getcID()
{
    return cID;
}
void NewUser::modifyaccType(string acctype)
{
    if (acctype == "s" || accType == "S")
        accType = "Saving";
    else if (acctype == "c" || accType == "C")
        accType = "Current";

    // return accType;
}
int NewUser::getloginPassword()
{
    return loginPassword;
}
string NewUser::getTransactionPin()
{
    return transactionPIN;
}
string NewUser::getacc()
{
    return acc;
}
void NewUser::modifycname(string cname2)
{
    cname = cname2;
}
void NewUser::modifycage(int cage2)
{
    cage = cage2;
}
void NewUser::modifycDob(string cDob2)
{
    cdob = cDob2;
}
void NewUser::modifycmob(string cmob2)
{
    cmob = cmob2;
}
void NewUser::modifycpinCode(string cpinCode2)
{
    cpinCode = cpinCode2;
}
void NewUser::modifycaddress(string caddress2)
{
    caddress = caddress2;
}

void NewUser ::getPersonalDetails()
{
    system("Color 0B");
    cout << "Thankyou for choosing our bank\nFill thr form to open new account:";
    cout << "\nAccount Holder Name : ";
    cin.ignore();
    getline(cin, cname);
    cout << "Account Holder age: ";
    while (!(cin >> cage) || cage <= 0 || cage > 150)
    {
        cout << "Please enter a valid age: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    cout << "Account Holder date of birth (DD-MM-YYYY): ";
    cin>>cdob;
    cout << "Account Holder mobile number (10digit): ";
    while (!(cin >> cmob) || cmob.length() != 10 || !all_of(cmob.begin(), cmob.end(), ::isdigit))
    {
        cout << "Please enter a valid 10-digit mobile number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    cout << "Account Holder Address : ";
    cin.ignore();
    getline(cin, caddress);
    cout << "Enter your 6 digit PIN code(Postal): ";
    while (!(cin >> cpinCode) || cpinCode.length() != 6 || !all_of(cpinCode.begin(), cpinCode.end(), ::isdigit))
    {
        cout << "Please enter a valid 6-digit PIN code: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    cout << "Enter your aadhar number(12digits-no space): ";
    while (!(cin >> cID) || cID.length() != 12 || !all_of(cID.begin(), cID.end(), ::isdigit))
    {
        cout << "Please enter a valid 12-digit Aadhar number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    cout << "------------------------------" << endl;
    cout << "Your account is successfully created please create your user id and login password to complete the account generation process" << endl;
    generateAccountNum(cdob, cmob, cpinCode, cID);
    cout << "Select Account type(Saving-S/Current-C): ";
    cin >> accType;
    modifyaccType(accType);
    getLogindetail();
    cout << "Thank you for regestering, here is your regestered details: " << endl;
    cout << "Account Holder Name: " << cname << endl;
    cout << "Account Holder Age: " << cage << endl;
    cout << "Account Holder Date of Birth: " << cdob << endl;
    cout << "Account Holder Mobile No.: " << cmob << endl;
    cout << "PIN Code: " << cpinCode << endl;
    cout << " Account Number is: " << acc << endl;
    cout << " Account Type : " << accType << endl;

    cout << "Create a transaction PIN for transactions" << endl;
    createTransactionPin();
    cout << "Deposit a minimum amount of Rs 1000 at the cash counter to initiate the transactions in your account\n Press Enter to continue: " << endl;
    return;
}
void NewUser::generateAccountNum(const string &dob, const string &mobile, const string &pinCode, const string &cID)
{
    string accNum = "";
    string accPart1 = getcDobPart(dob);
    string accPart2 = getcmobPart(mobile);
    string accPart3 = getcpincodePart(pinCode);
    string accPart4 = getcIDPart(cID);
    vector<string> initAcc = {accPart1, accPart2, accPart3, accPart4};
    random_device rd;
    mt19937 gen(rd());
    shuffle(initAcc.begin(), initAcc.end(), gen);
    string mainAcc;
    for (const auto &part : initAcc)
    {
        mainAcc += part;
    }
    acc = mainAcc;
    acc.insert(0,"57");
    //acc += acc1;
    // shuffleAccNum(accNum);
}
// void NewUser::shuffleAccNum(string accToShuffle)
// {
//     string inputString = accToShuffle;

//     vector<char> charVector(inputString.begin(), inputString.end());
//     random_device rd;
//     mt19937 gen(rd());
//     shuffle(charVector.begin(), charVector.end(), gen);
//     string shuffledString(charVector.begin(), charVector.end());
//     acc1 = shuffledString;
//     acc += acc1;
//}
class ExistingUser : public Bank
{
    string regdUserName;
    string regdPswd;

public:
    void getRegdAccDetails();
    string getRegdUserName();
    string getRegdPswd();
    void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
};
void ExistingUser ::getRegdAccDetails()
{

    cout << "Enter your UserName : ";
    cin >> regdUserName;
    cin.ignore();
    cout << "Enter your Login Passsword(Numbers Only - 4to8 digits) : ";
    cin>>regdPswd;
    cin.ignore();

}
string ExistingUser::getRegdUserName()
{
    return regdUserName;
}
string ExistingUser::getRegdPswd()
{
    return regdPswd;
}
class Employe : public NewUser, public ExistingUser
{
private:
    string AllempId[4] = {"vishwas7782", "sunil9131", "vivek8871", "vinay7903"};
    string AllempPswd[4] = {"843125", "465687", "465693", "843333"};
    string empId;
    string empPswd;
    string acctoCheck;


public:
    bool validId = false;
    bool validPswd = false;
    bool validAcc= false;
    void getEmpDetail();
    void EmpCheck();
    void modifyname();
    void modifyage();
    void modifyDob();
    void modifymob();
    void modifypinCode();
    void modifyaddress();
    void modifyAccountMenu();
    void AccCheck();
    void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
};

void Employe::getEmpDetail()
{
    system("Color 0D");
    cout << "Enter Your Employe ID :\n";
    cin >> empId;
    cin.ignore();
    cout << "Enter Your Login Password :\n";
    cin >> empPswd;
    cin.ignore();
}
void Employe::AccCheck(){
    do{
    cout << "Enter Account No. :\n";
    cin >> acctoCheck;
    if(acctoCheck==getacc()){
        validAcc=true;
    }
    else{
        cout<<"Invalid Account No\n Try again...";
    }
    }while(!validAcc);
}
void Employe::EmpCheck()
{
    system("Color 06");

    do
    {

        cout << "Enter Your Employee ID:\n";
        cin >> empId;
        cin.ignore();
        for (int i = 0; i < 4; i++)
        {
            if (empId == AllempId[i])
            {
                validId = true;
                cout << "Enter Your Login Password:\n";
                cin >> empPswd;
                cin.ignore();

                if (empPswd == AllempPswd[i])
                {
                    validPswd = true;
                    cout << "Login Successful!\n";
                }
                else
                {
                    cout << "Incorrect Password!\n";
                    break;
                }
            }
        }

        if (!validId)
        {
            cout << "Invalid Employee ID!\n";
        }
    } while (!validId || !validPswd);
}
void Employe::modifyname()
{
    string namecheck;
    string cname2;
   AccCheck();
    do
    {

        cout << "Enter the old name to verify: ";
        
        cin.ignore();
        getline(cin, namecheck);
        if (getcname() == namecheck)
        {
            cout << "Enter Modified Name: ";
            cin >> cname2;
            modifycname(cname2);
            cout << "Name modification successfull \n";
            break;
        }
        else
        {
            cout << "Customer name not found, please try again with correct detail\n";
        }
    } while (namecheck != getcname());
}
void Employe::modifyage()
{
    int agecheck;
    int cage2;
    AccCheck();
    do
    {

        cout << "Enter the old age to verify: ";
        while (!(cin >> agecheck) || agecheck <= 0 || agecheck > 150)
        {
            cout << "Please enter a valid age: ";
            clearInputBuffer();
        }
        clearInputBuffer();
        if (getcage() == agecheck)
        {
            cout << "Enter Modified Age: ";
            cin >> cage2;
            modifycage(cage2);
            cout << "Age modification successfull \n";
            break;
        }
        else
        {
            cout << "Wrong age entered, please try again with correct detail\n";
        }
    } while (agecheck != getcage());
}

void Employe::modifyDob()
{
    string dobcheck;
    string cDob2;
    AccCheck();
    do
    {

        cout << "Enter the old Dob to verify: ";
        cin.ignore();
        getline(cin, dobcheck);
        if (getcDob() == dobcheck)
        {
            cout << "Enter Modified Dob: ";
            cin >> cDob2;
            modifycDob(cDob2);
            cout << "DOB modification successfull \n";
            break;
        }
        else
        {
            cout << "Wrong Dob entered, please try again with correct detail\n";
        }
    } while (dobcheck != getcDob());
}
void Employe::modifymob()
{
    string mobcheck;
    string cmob2;
    AccCheck();
    do
    {

        cout << "Enter the old mobile number to verify: ";
        cin.ignore();
        getline(cin, mobcheck);
        if (getcmob() == mobcheck)
        {
            cout << "Enter Modified Mobile no: ";
            cin >> cmob2;
            modifycmob(cmob2);
            cout << "Mobile no. modification successfull \n";
            break;
        }
        else
        {
            cout << "Wrong mobile no entered, please try again with correct detail\n";
        }
    } while (mobcheck != getcmob());
}
void Employe::modifypinCode()
{
    string pinCodecheck;
    string cpinCode2;
    AccCheck();
    do
    {

        cout << "Enter the old PIN Code to verify: ";
        cin.ignore();
        getline(cin, pinCodecheck);
        if (getcpincode() == pinCodecheck)
        {
            cout << "Enter Modified Pin Code: ";
            cin >> cpinCode2;
            modifycpinCode(cpinCode2);
            cout << "Pin Code modification successfull \n";
            break;
        }
        else
        {
            cout << "Wrong Pin Code entered, please try again with correct detail\n";
        }
    } while (pinCodecheck != getcpincode());
}
void Employe::modifyaddress()
{
    string addresscheck;
    string caddress2;
    AccCheck();
    do
    {

        cout << "Enter the old address to verify: ";
        cin.ignore();
        getline(cin, addresscheck);
        if (getcaddress() == addresscheck)
        {
            cout << "Enter Modified Address: ";
            cin >> caddress2;
            modifycaddress(caddress2);
            cout << "Address modification successfull \n";
            break;
        }
        else
        {
            cout << "Wrong address entered, please try again with correct detail\n";
        }
    } while (addresscheck != getcaddress());
}
void Employe::modifyAccountMenu()
{
    char ch2;
    do
    {
        // system("cls");
        cout << "-----------------------------------------" << endl;
        cout << "||\t" << setw(23) << left << "Modify Account MENU"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. Modify Name :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "2. Modify Age :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "3. Modify DOB :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "4. Modify Mob No. :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "5. Modify Pin Code :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "6. Modify Address :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "7. EXIT :"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "\t" << setw(31) << left << "Select option from the given menu ...: ";
        cin >> ch2;
        // system("cls");
        switch (ch2)
        {
        case '1':
            modifyname();
            break;
        case '2':
            modifyage();
            break;
        case '3':
            modifyDob();
            break;
        case '4':
            modifymob();
            break;
        case '5':
            modifypinCode();
            break;
        case '6':
            modifyaddress();
            break;
        case '7':
            cout << "Press enter to go back";
            break;
        default:
            cout << "\a Wrong Choice...Try Again...\n";
            break;
        }
        cin.ignore();
        cin.get();

    } while (ch2 != '7');
}

class Authentication : public Employe
{
private:
    string check_usrname;
    string regdPINCheck;
    int check_loginPass;
    // int transferAccountCheck[20];

public:
    void getAuthenticationDetails();
    // void getTransferAccDetails();
    void doAuthentication();
    void getPINAuthenticationDetails();
    void doPINAuthentication();
    string num;
    bool logincheck = false;
    bool PINcheck = false;

    // void write_account()
    // {
    //     ofstream outfile;
    //     outfile.open("Account3.dat", ios::binary | ios::app);
    //     outfile.write(reinterpret_cast<char *>(&ac), sizeof(Bank));
    //     outfile.close();

    //     std::ofstream outFile("function_data.dat", std::ios::binary); // Open file in binary mode
    //     if (outFile.is_open())
    //     {
    //         outFile.write(data.c_str(), data.size()); // Writing data to the file in binary mode
    //         outFile.close();                          // Closing the file
    //         std::cout << "Data written to .dat file successfully." << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "Unable to open .dat file." << std::endl;
    //     }
    // }
};

void Authentication::getAuthenticationDetails()
{

    cout << "Welcome Back...\n Login to proceede : " << endl;
    cout << "Enter your Username : ";
    cin >> check_usrname;
    cin.ignore();
    cout << "Enter your Login Password : ";
    cin >> check_loginPass;
    cin.ignore();
}
void Authentication::doAuthentication()
{ // getRegdUserName()=check_usrname;
  // getRegdPswd()=check_loginPass;

    do
    {
        getAuthenticationDetails();
        if (getUserId() == check_usrname && getloginPassword() == check_loginPass)
        {
            logincheck = true;
            cout << "Log in successfull " << endl;
            cout << "Your can access all Bank Services :  " << endl;
            // bankingMenu();
        }
        else
        {

            cout << "Sorry.... Bad credentials, please try again..." << endl;
        }
    } while (!logincheck);
}
void Authentication::getPINAuthenticationDetails()
{
    cout << "Enter your Transaction PIN to procede:";

    cin >> regdPINCheck;
    cin.ignore();
}
void Authentication::doPINAuthentication()
{

    do
    {
        getPINAuthenticationDetails();
        if (getTransactionPin() == regdPINCheck)
        {
            PINcheck = true;
            cout << "Verification Successfull successfull " << endl;
            cout << "Your can procede with your transacction:  " << endl;
            // bankingMenu();
        }
        else
        {

            cout << "Sorry.... Bad credentials, please try again..." << endl;
        }
    } while (!PINcheck);
}
static int transactionCount = 0;
class Transactions : public Authentication
{
private:
string transacc1,transacc2;
    float bal = 1000;

    // float amount, calCharge;
public:
    // int choice;
    string pass = getRegdPswd();

    void cashdeposit(int amt);
    void cashwithdraw(int amt);
    int calcharge(int amt);
    void CheckBalance();
    void trans(int amt);
    void trans(int amt, int charge);
    void showUserData();
    float getbal();
    void showAllUserData();
};
void Transactions::showUserData()
{
    cout << "Name: " << getcname() << endl;
    cout << "Age: " << getcage() << endl;
    cout << "Date of Birth: " << getcDob() << endl;
    cout << "Mobile No.: " << getcmob() << endl;
    cout << "PIN Code: " << getcpincode() << endl;
    cout << "Your Account Number is: " << getacc() << endl;
    cout << "Account Type : " << getaccType() << endl;
}
void Transactions ::cashdeposit(int amt)
{
    cout << "Enter Amount to Deposit: ";
    cin >> amt;
    bal += amt;
    cout << "Amount Deposited succesfully." << endl;
    cout << "New Balance : " << bal << endl;
}
void Transactions ::cashwithdraw(int amt)
{
    cout << "Enter Amount to Withdraw: ";
    cin >> amt;
    if (bal > amt && (bal - amt) >= 1000)
    {
        bal -= amt;
        cout << "Amount Withdrawl succesfully." << endl;
        cout << "New Balance : " << bal << endl;
    }
    else
    {
        cout << "Insufficient Balance" << endl;
    }
}
int Transactions::calcharge(int amt)
{

    if (amt <= 10000)
    {
        return 5;
    }
    else if (amt > 10000 && amt <= 100000)
    {
        return 10;
    }
    else if (amt > 100000 && amt <= 200000)
    {
        return 15;
    }
    else
    {
        return 25;
    }
}
void Transactions ::CheckBalance()
{
    cout << "Your Account Balance : " << bal << endl;
}
void Transactions ::trans(int amt)
{
     cout << " Transfer To Account Number : ";
    cin >> transacc2;
    cout << "Enter Transfer amount: ";
    cin >> amt;
    if (bal > amt && (bal - amt) >= 1000)
    {
        bal -= amt;
        cout << "Balance after transaction : " << bal << endl;
    }
    else
    {
        cout << "Insufficient Balance, minimum balance of 1000 sould be maintained" << endl;
    }
}
void Transactions ::trans(int amt, int charge)
{ 
    cout << "Additional Charges apply" << endl;
     cout << " Transfer To Account Number : ";
    cin >> transacc1;
    cout << "Enter transaction amount: ";
    cin >> amt;
    if (bal > amt && (bal - amt - charge) >= 1000)
    {
        bal = bal - amt - charge;
        cout << "Your transaction charge : " << charge << endl;
        cout << "Balance after transaction : " << bal << endl;
    }
    else
    {
        cout << "Insufficient Balance, minimum balance of 1000 sould be maintained" << endl;
    }
}
float Transactions::getbal()
{
    return bal;
}
void Transactions::showAllUserData()
{
    system("Color FB");
    cout << "\tUser\t" << setw(30) << left << "Name" << setw(25) << "A/c No" << setw(15) << "A/c Type" << setw(15) << "Balance" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "|\t"
         << "1"
         << "\t" << setw(30) << left << getcname() << setw(25) << getacc() << setw(15) << getaccType() << setw(15) << getbal() << "\t|" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
}

class BankDatabase : public Transactions
{
public:
    void BankMenu();
    void empMenu();
    void mainMenu();
} stud1;
void BankDatabase::BankMenu()
{
    system("\nColor 03");
    char c;
    double amt, charge = calcharge(amt);
    do
    {
        cout << "------------------------------\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer to same Bank\n";
        cout << "5. Transfer to other Bank\n";
        cout << "6. Show Your Acc Details \n";
        cout << "7. Modify Account \n";
        cout << "8. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice: ";
        cin >> c;
        cout << "------------------------------\n";

        if (c == '1')

        {
            doPINAuthentication();
            if (PINcheck)

                CheckBalance();
            transactionCount;
            PINcheck = false;

            // break;
        }
        else if (c == '2')
        {
            doPINAuthentication();
            if (PINcheck)
            {
                cashdeposit(amt);
                transactionCount;
                PINcheck = false;
            }
            // break;
        }
        else if (c == '3')
        {
            doPINAuthentication();
            if (PINcheck)
            {
                cashwithdraw(amt);
                transactionCount;
                PINcheck = false;
            }
            // break;
        }
        else if (c == '4')
        {
            doPINAuthentication();
            if (PINcheck)
            {
                trans(amt);
                transactionCount;
                PINcheck = false;
            }
            // break;
        }
        else if (c == '5')
        {
            doPINAuthentication();
            if (PINcheck)
            {
                trans(amt, charge);
                transactionCount;
                PINcheck = false;
            }
            // break;
        }
        else if (c == '6')
        {
            doPINAuthentication();
            if (PINcheck)
            {
                showUserData();
                PINcheck = false;
            }
            // break;
        }
        else if (c == '7')
        {
            doPINAuthentication();
            if (PINcheck)
            {
                modifyAccountMenu();
                PINcheck = false;
            }
            // break;
        }
        else if (c == '8')
        {
            break;
        }
        else
        {
            cout << "Wrong choice...try again...\n";
        }

    } while (c != 8);
}

void BankDatabase::empMenu()
{
    char ch1;
    do
    {
        // system("cls");
        cout << "-----------------------------------------" << endl;
        cout << "||\t\t" << setw(23) << left << "Employe MENU"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. Modify Account :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "2. Show Total Balance of Bank:"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "3. Show All Accounts :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "4. EXIT :"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "\t" << setw(31) << left << "Select option from the given menu ...: ";
        cin >> ch1;
        // system("cls");
        switch (ch1)
        {
        case '1':
            modifyAccountMenu();
            break;
        case '2':
            cout << "Under Maintenance...Sorry..." << endl;
            break;
        case '3':
            showAllUserData();
            cout << "\nUnder Maintenance...Sorry..." << endl;
            break;
        case '4':
            mainMenu();
            break;
        default:
            cout << "\a Wrong Choice...Try Again...\n";
            break;
        }
        cin.ignore();
        cin.get();

    } while (ch1 != '4');
}
void BankDatabase::mainMenu()
{
    char ch;
    do
    {
        // system("cls");
        cout << "-----------------------------------------" << endl;
        cout << "||\t\t" << setw(23) << left << "LOGIN INTERFACE"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. NEW USER :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "2. EXISTING USER :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "3. EMPLOYEE(offline Process) :"
             << "||" << endl;
        // cout << "||\t" << setw(31) << left << "4. EXIT :"
        //      << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "\t" << setw(31) << left << "Select User Type from the given menu ...: ";
        cin >> ch;
        // system("cls");
        switch (ch)
        {
        case '1':
            getPersonalDetails();
            break;
        case '2':
            doAuthentication();
            if (logincheck == true)
            {
                BankMenu();
            }
            break;
        case '3':
            EmpCheck();
            if (validId == true && validPswd == true)
            {
                empMenu();
            }
            break;
        case '4':
            cout << "\n\n\tThankyou for Visiting India Bank Limited\nClosing System...";
            exit(0);
            break;

        default:
            cout << "\a Wrong Choice...Try Again...\nPress Enter to ";
        }
        cin.ignore();
        cin.get();

    } while (ch != '4');
}
void intro();
void introto();
void Message();

int main()
{
    int Loginpin;
    string user;
    char found = 'f';
    char cr;
    intro();
    do
    {   cout << "-----------------------------------------" << endl;
        cout << "||\t\t" << setw(23) << left << "LOGIN INTERFACE"
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "1. NEW USER :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "2. EXISTING USER :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "3. EMPLOYEE(Offline Process) :"
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "4. EXIT : "
             << "||" << endl;
        cout << "||-------------------------------------||" << endl;
        cout << "\t" << setw(31) << left << "Select option from the given menu ...: ";
        cin >> cr;
        // system("cls");
        switch (cr)
        {

        case '1':
        {
            ofstream fout("BankDataFinal.dat", ios::out | ios::app);

            stud1.getPersonalDetails();
            fout.write((char *)&stud1, sizeof(stud1));
            break;
            fout.close();
        }
        case '2':
        {
            ifstream fin("BankDataFinal.dat", ios::in | ios::app);
            do
            {
                cout << "Enter Your User Name : ";
                cin >> user;
                cout << "Enter the login Password : ";
                cin >> Loginpin;

                while (!fin.eof())
                {
                    fin.read((char *)&stud1, sizeof(stud1));
                    if (stud1.getloginPassword() == Loginpin)
                    {
                        stud1.BankMenu();
                        found = 'n';
                        break;
                    }
                }
                if (found == 'f')
                {
                    cout << "Sorry Invalid Usernme And Password : " << endl;
                }

                fin.close();
                break;
            } while (found == 'f');
            break;
        }
        case '3':
            stud1.EmpCheck();

            stud1.empMenu();

        case '4':
        
            break;
        }

    } while (cr != '4');
    introto();
    Message();
    return 0;
}
void intro()
{
    stud1.ExistingUser::welcomeMessage();
}
void introto()
{
    cout << "THANK YOU FOR USING OUR BANKING SERVICES !..........\n.....VISIT AGAIN.....!!!!!!!  ";
}
void Message(){
   cout << "-----------------------------------------" << endl;
        cout << "||\t\t" << setw(23) << left << "BANK"
             << "||" << endl;
      //  cout << "||-------------------------------------||" << endl;
        cout << "||\t" << setw(31) << left << "MANAGMENT SYSTEM..."
             << "||" << endl;
        cout << "||\t" << setw(31) << left << "MADE BY HELLO WORLD SQUAD..."
             << "||" << endl;
        cout << "\t" << setw(31) << left << "TEAM MEMBERS ARE..."<<endl
        <<"\t\t" << setw(31) << left <<"1.Vishwasjeet Gupta"<<endl
        <<"\t\t\t" << setw(31) << left <<"2.Sunil Rathore"<<endl
        <<"\t\t\t\t" << setw(31) << left<<"3.Vivek Agrawal"<<endl
        <<"\t\t\t\t\t" << setw(31) << left<<"4.Ramvinay Kumar\n\n"<< endl;
}