package exercise07;

public class Employee extends Person{
    private String office;
    private double salary;
    private MyDate Date = new MyDate();

    public Employee() {
	}
    public Employee(String office, double salary, MyDate Date) {
    	this.office=office;
    	this.salary=salary;
    	this.Date=Date;
	}
    
    @Override
    public String toString(){
    	return "Class : Employee " + "\t Name : " + super.NAME;
    }
}
