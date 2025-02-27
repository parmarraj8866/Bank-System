#include <iostream>
using namespace std;

class BankAccount
{
protected:
  string accountHolderName;
  long long accountNumber;
  double balance;

public:
  BankAccount(string n, long long acc, double bal)
  {
    accountHolderName = n;
    accountNumber = acc;
    balance = bal;
  }

  virtual ~BankAccount() {}

  void deposit(double amount)
  {
    if (amount > 0)
    {
      balance += amount;
    }
  }

  void withdraw(double amount)
  {
    if (amount <= balance)
    {
      balance -= amount;
    }
    else
    {
      cout << "Insufficient Funds\n";
    }
  }

  void getBalance()
  {
    cout << "Current Balance: ₹" << balance << endl;
  }

  void displayAccountInfo()
  {
    cout << "\nAccount Name: " << accountHolderName
         << "\nAccount Number: " << accountNumber
         << "\nBalance: ₹" << balance << endl;
  }
};

class SavingAccount : public BankAccount
{
private:
  double interestRate;

public:
  SavingAccount(string n, long long acc, double bal, double rt)
      : BankAccount(n, acc, bal), interestRate(rt) {}

  void calculateInterest()
  {
    double interest = balance * (interestRate / 100);
    balance += interest;
    cout << "Added Interest: ₹" << interest << " (Rate: " << interestRate << "%)\n";
  }
};

class CheckingAccount : public BankAccount
{
private:
  double overdraftLimit;

public:
  CheckingAccount(string n, long long acc, double bal, double overdraft)
      : BankAccount(n, acc, bal), overdraftLimit(overdraft) {}

  void checkOverdraft(double amount)
  {
    if (amount > (balance + overdraftLimit))
    {
      cout << "Transaction Denied! Exceeds Overdraft Limit of ₹" << overdraftLimit << "\n";
    }
    else
    {
      balance -= amount;
      cout << "₹" << amount << " Withdrawn Successfully.\n";
      cout << "New Balance (including overdraft if used): ₹" << balance << "\n";
    }
  }
};

class FixedDepositAccount : public BankAccount
{
private:
  int term;
  double interestRate;

public:
  FixedDepositAccount(string n, long long acc, double bal, int t, double rate)
      : BankAccount(n, acc, bal), term(t), interestRate(rate) {}

  void calculateInterest()
  {
    double interest = balance * (interestRate / 100) * term;
    balance += interest;
    cout << "Fixed Deposit Interest Earned in " << term
         << " years: ₹" << interest << " (Rate: " << interestRate << "% per year)\n";
  }
};

int main()
{
  BankAccount b1("Parmar R", 2565216226LL, 10000);
  SavingAccount s1("Vikas Yadav", 251487956324LL, 50000, 1.5);
  CheckingAccount c1("Abhishek Sharma", 8978412561LL, 400000, 54871.654);
  FixedDepositAccount f1("Lokesh Sharma", 454585632541LL, 600000, 4, 4.5);

  c1.checkOverdraft(5000);

  s1.calculateInterest();
  s1.displayAccountInfo();

  f1.calculateInterest();
  f1.displayAccountInfo();

  return 0;
}
