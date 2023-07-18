package exercise07;

import java.util.ArrayList;
import java.util.Date;

public class NewAccount{
	
	private int id = 0;
	private double balance = 0;
	private double annualInterestRate = 0;//取�?�范�?:[0,100]
	private Date dateCreated;
	private String name;
	private ArrayList<Transaction> transactions= new ArrayList<Transaction>();;
	
	public NewAccount(){
		dateCreated = new Date();
	}
	public NewAccount(int id, double balance){
		this.id = id;
		this.balance = balance;
		dateCreated = new Date();
	}
	public NewAccount(String name, int id, double balance){
		this.name=name;
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
		return annualInterestRate/12;//取�?�范�?:[0,100]/12
	}
	public double getMonthlyInterest() {
		return balance*getMonthlyInterestRate()/100;
	}
	
	public void withDraw(double money) {
		setBalance(balance-money);
		transactions.add(new Transaction('w', money, getBalance(), "取款成功"));
		
	}
	public void deposit(double money) {
		setBalance(balance+money);
		transactions.add(new Transaction('D', money, getBalance(), "存款成功"));
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public ArrayList<Transaction> getTransactions() {
		return transactions;
	}
}
