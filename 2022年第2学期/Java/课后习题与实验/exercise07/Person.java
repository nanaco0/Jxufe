package exercise07;

public class Person {
	
	final public String NAME, ADDRESS, PHONE, EMAIL;
	
	public Person() {
		this.NAME=null;
		this.ADDRESS=null;
		this.PHONE=null;
		this.EMAIL=null;
	}
	public Person(String name, String address, String phoneNumber, String email) {
		this.NAME=name;
		this.ADDRESS=address;
		this.PHONE=phoneNumber;
		this.EMAIL=email;
	}
	
	@Override
    public String toString(){
        return "Class : Person " + "\t Name : " + NAME;
    }
	
}
