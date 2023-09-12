package exercise07;

public class Faculty extends Employee {
	
	private String officeHours;
	private String level;
	
    @Override
    public String toString(){
    	return "Class : Faculty " + "\t Name : " + super.NAME;
    }
}
