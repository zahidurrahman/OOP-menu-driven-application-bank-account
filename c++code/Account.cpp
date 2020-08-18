#include <stdexcept>
#include <iostream>
#include "Account.h"
using namespace std;
 
// Account constructor initializes data member balance
Account::Account( double initialBalance )
{
   // if initialBalance is greater than or equal to 0.0, set this value 
   // as the balance of the Account
   if ( initialBalance >= 0.0 )
      balance = initialBalance;
   else
      throw invalid_argument( "Initial balance cannot be negative" );
}
 
// credit (add) an amount to the account balance
void Account::credit( double amount )
{
   balance = balance + amount; 
} 
 
// debit (subtract) an amount from the account balance
// return bool indicating whether money was debited
bool Account::debit( double amount )
{
   if ( amount > balance ) 
   {
      cout << "Debit amount exceeded account balance." << endl;
      return false;
   } // end if
   else // debit amount does not exceed balance
   {
      balance = balance - amount;
      return true;
   } // end else
} // end function debit
 
// set the account balance
void Account::setBalance( double newBalance )
{
   balance = newBalance;
} // end function setBalance
 
// return the account balance
double Account::getBalance()
{
   return balance;
} // end function getBalance