#include <iostream>
#include <iomanip>
#include "Account.h" // Account class definition
#include "SavingsAccount.h" // SavingsAccount class definition
#include "CheckingAccount.h" // CheckingAccount class definition
using namespace std;
 class AccountHolder 
{ 
    // Access specifier 
    private:
      // Data Members 
      string name,phone,address; 
    public: 
     AccountHolder(string n,string p,string a){
         name=n;
         phone=p;
         address=a;
     }
   
  
    // Member Functions() 
    void details() 
    { 
       cout << "Name: " << name<<endl; 
       cout << "Phone: " << phone<<endl;
       cout << "Address: " <<address<<endl;
    } 
}; 

int main()
{
   cout<<"Wlcome TO ABC Banking System "<<endl;
   string name,phone,address; 
   cout<<"Enter Name:";
  getline(cin, name);
   cout<<"Enter Phone:";
   getline(cin, phone);
   cout<<"Enter Address:";
   getline(cin, address);
   AccountHolder ach(name,phone,address);
   
   Account account1( 50.0 ); // create Account object
   SavingsAccount account2( 25.0, .03 ); // create SavingsAccount object
   CheckingAccount account3( 80.0, 1.0 ); // create CheckingAccount object
 
   cout << fixed << setprecision( 2 );
    
   //Creating Menu
		while(true){
			cout <<"------------------------------------------------------------------"<<endl;
			cout<<"View Account Details [1]"<<endl;
			cout<<"Deposit To Saving Account [2]"<<endl;
			cout<<"Withdraw From Saving Account [3]"<<endl;
			cout<<"Deposit To Checking Account [4]"<<endl;
			cout<<"Withdraw From Checking Account [5]"<<endl;
			cout<<"Check balance after calculating Interest of  Saving Account [6]"<<endl;
			cout<<"To Exit [0]"<<endl;
			cout <<"------------------------------------------------------------------"<<endl;

			cout<<"Enter your choice:";
			int choice;
			cin>>choice;

			switch(choice){
			case 1: 
			    ach.details(); 
                cout << "Saving Account balance: RM " << account2.getBalance() << endl;
                cout << "Check Account  balance: RM " << account3.getBalance() << endl;
			    break;
			case 2: 
			    cout << "Enter the Deposit amount: RM " << endl;
			    double saving_d;
			    cin>>saving_d;
                account2.credit(saving_d); 
			    cout<<"The Balance after Deposit: "<<account2.getBalance() << endl;
			    break;
			case 3: 
			    cout << "Enter the Withdraw amount: RM " << endl;
                double saving_w;
			    cin>>saving_w;
                account2.debit(saving_w); 
			    cout<<"The Balance after Withdraw: "<<account2.getBalance() << endl;
			    break;
			case 4: 
			    cout << "Enter the Deposit amount: RM " << endl;
			    double checking_d;
			    cin>>checking_d;
                account3.credit(checking_d); 
			    cout<<"The Balance after Deposit: "<<account3.getBalance() << endl;
			    break;
			case 5: 
			    cout << "Enter the Withdraw amount: RM " << endl;
			    double checking_w;
			    cin>>checking_w;
                account3.debit(checking_w); 
			    cout<<"The Balance after Withdraw: "<<account3.getBalance() << endl;
			    break;
			case 6: 
                double interestEarned;
                interestEarned= account2.calculateInterest();
                cout << "Adding RM " << interestEarned << " interest to Saving Account."<< endl;
                account2.credit( interestEarned );
                cout << "New Saving Account balance: RM " << account2.getBalance() << endl;
			    break;
			case 0: 
			   exit(0);
			   break;
			default:
			  cout<<"Incorrect input!!! Please re-enter choice from our menu"<<endl;
			}
		}
} 