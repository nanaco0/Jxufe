package exercise07;

import java.util.Date;

public class Account {
	
	private int id = 0;
	private double balance = 0;
	private double annualInterestRate = 0;//å–å?¼èŒƒå›?:[0,100]
	private Date dateCreated;
	
	public Account(){
		dateCreated = new Date();
	}
	public Account(int id, double balance){
		this.id = id;
		this.balance = balance;
		dateCreated = new Date();
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	
	public double getAnnualInterestRate() {
		return annualInterestRate;
	}
	public void setAnnualInterestRate(double annualInterestRate) {
		this.annualInterestRate = annualInterestRate;
	}
	
	public Date getDateCreated() {
		return dateCreated;
	}
	
	public double getMonthlyInterestRate() {
		return annualInterestRate/12;//å–å?¼èŒƒå›?:[0,100]/12
	}
	public double getMonthlyInterest() {
		return balance*getMonthlyInterestRate()/100;
	}
	
	public void withDraw(double money) {
		setBalance(balance-money);
	}
	public void deposit(double money) {
		setBalance(balance+money);
	}
}
