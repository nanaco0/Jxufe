package exercise12;

import java.util.ArrayList;

public class Course
{
    private String courseName;
    private ArrayList<String> students = new ArrayList<>();

    public Course()
    {
    }

    public Course(String courseName)
    {
        this.courseName = courseName;
    }

    public void addStudents(String student)
    {
        if (students.size() >= 100)
        {
            System.out.println("It is full.");
            return;
        }
        else
            students.add(student);
    }

    public ArrayList<String> getStudents()
    {
        return students;
    }

    public int getNumberOfStudents()
    {
        return students.size();
    }

    public String getCourseName()
    {
        return courseName;
    }

    public void dropStudents(String student)
    {
        students.remove(students.get(students.indexOf(student)));
    }

    public void setStudents(ArrayList<String> students)
    {
        this.students = students;
    }

    @Override
    public Object clone()
    {
        Course newCourse = new Course(getCourseName());
        newCourse.setStudents(getStudents());
        return newCourse;

    }
}