package exercise07;

public class NewAccountTest {

    public static void main(String[] args) {
        NewAccount account = new NewAccount("George",1122,1000.0);
        account.setAnnualInterestRate(1.5/100);
        account.deposit(30.0);
        account.deposit(40.0);
        account.deposit(50.0);
        account.withDraw(5.0);
        account.withDraw(4.0);
        account.withDraw(2.0);
        System.out.println("客户名：" + account.getName() + " 年利率：" + account.getAnnualInterestRate() + " 当前余额�?" + account.getBalance() + "美元");
        System.out.print(account.getTransactions().toString());
    }

}
