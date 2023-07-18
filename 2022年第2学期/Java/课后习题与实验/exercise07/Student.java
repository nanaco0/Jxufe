package exercise07;

public class Student extends Person {
	
	final public String GRADE;
	
	public Student() {
		GRADE = null;
	}
	public Student(String GRADE) {
		this.GRADE = GRADE;
	}

	@Override
    public String toString(){
        return "Class : Student " + "\t Name : " + super.NAME;
    }
	
}
