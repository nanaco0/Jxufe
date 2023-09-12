package exercise07;

public class Staff extends Employee{

	private String title;
	
	@Override
    public String toString(){
    	return "Class : Staff " + "\t Name : " + super.NAME;
    }

}
