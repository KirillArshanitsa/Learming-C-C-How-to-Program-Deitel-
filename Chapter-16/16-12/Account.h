class Account
{
public:
	Account(int money);
	void credit(int money);
	void debit(int money);
	int getBalance();
private:
	int balance;
};