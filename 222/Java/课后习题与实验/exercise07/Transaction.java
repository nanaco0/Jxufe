package exercise07;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Transaction {

	private Date date;
	private char type;
	private double amount;
	private double balance;
	private String description = "Transaction: " + date + ", type: " + type + ", amount: " + amount + ", balance: " + balance;
	
	public Transaction(char type, double amount, double balance, String description) {
		this.date=new Date();
		this.type=type;
		this.amount=amount;
		this.balance=balance;
		this.description=description;
	}
	
	public Date getDate() {
		return date;
	}
	public void setDate(Date date) {
		this.date = date;
	}
	
	public char getType() {
		return type;
	}
	public void setType(char type) {
		this.type = type;
	}
	
	public double getAmount() {
		return amount;
	}
	public void setAmount(double amount) {
		this.amount = amount;
	}
	
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
	
    @Override
    public String toString(){
        return "\n" + "交易记录�?" + new SimpleDateFormat("yyyy-MM-dd").format(date) + " " + type + " " + amount + " " + balance + " 美元 " + description;
    }

}
