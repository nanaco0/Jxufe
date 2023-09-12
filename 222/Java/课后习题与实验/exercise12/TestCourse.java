package exercise12;

public class TestCourse
{
    public static void main(String [] args)
    {
        Course course1 = new Course("English");
        course1.addStudents("wang");
        course1.addStudents("chun");
        course1.addStudents("lei");
        System.out.println(course1.getNumberOfStudents());

        Course course2 = (Course)(course1.clone()); 
        System.out.println(course2.getNumberOfStudents());
        System.out.println(course1.equals(course2));
        for (String name : course2.getStudents())
        {
            System.out.print(name + " ");
        }
        System.out.println();
    }
}