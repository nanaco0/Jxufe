package exercise05;

public class AccountTest {

	public static void main(String[] args) {
		Account account = new Account(1122, 20000);
		account.setAnnualInterestRate(4.5);
		account.withDraw(2500);
		account.deposit(3000);
		System.out.println("余额: "+account.getBalance()+"\n"+"月利�?: "+account.getMonthlyInterest()+"\n"+"�?户日�?: "+account.getDateCreated());
	}

}
