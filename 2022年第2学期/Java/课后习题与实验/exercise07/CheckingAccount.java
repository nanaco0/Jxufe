package exercise07;

public class CheckingAccount extends Account {

	public final boolean Overdraft = true;
	
	public CheckingAccount() {
		// TODO 自动生成的构造函数存�?
	}
	
	public String toString(){
    	return "Class : CheckingAccount " + "\t Overdraft ? " + this.Overdraft;
    }
}
