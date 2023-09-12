package exercise06;

public class Course {
	
    public static void main(String[] args) {
    	Course_Test9 tc = new Course_Test9("mycourse");
        tc.addStudent("zhang");
        tc.addStudent("wang");
        tc.addStudent("li");

        tc.dropStudent("wang");

        System.out.println(tc.getNumberOfStudents());       // 2
    }
}
