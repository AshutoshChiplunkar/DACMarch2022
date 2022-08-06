package banking;

final class SavingsAccount extends Account implements Profitable {

	//field declared with final modifier cannot be reinitialized
	static final double MIN_BALANCE = 5000;

	SavingsAccount() {
		balance = MIN_BALANCE;
	}

	public void deposit(double amount) {
		balance += amount;
	}

	public void withdraw(double amount) throws InsufficientFundsException {
		if(balance - amount < MIN_BALANCE)
			throw new InsufficientFundsException();
		balance -= amount;
	}

	public double interest(int months) {
		return balance * months * MIN_RATE / 1200;
	}
}

