package exercise10;

import java.util.Scanner;

public class TestLoan {

	public static void main(String[] args) {
		
		Loan l1 = new Loan();
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("ÇëÊäÈë´û¿î×Ü¶î£º");
		double loanAmount = input.nextDouble();
		
		l1.setLoanAmount(loanAmount);
		l1.judge();
		
		input.close();
		
	}

}
