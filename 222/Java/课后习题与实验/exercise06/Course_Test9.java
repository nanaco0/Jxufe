package exercise06;

public class Course_Test9 {

    private String courseName;
    private String[] students = new String[100];
    private int numberOfStudents;

    public Course_Test9(String courseName){
        this.courseName = courseName;
    }

    // 任务�?2：改写addStudent方法
    public void addStudent(String student){
        if (numberOfStudents >= student.length()){
            String[] temp = new String[numberOfStudents + 50];
            for (int i = 0 ; i < numberOfStudents ; i++){
                temp[i] = students[i];
            }
            students = temp;
        }
        students[numberOfStudents] = student;
        numberOfStudents++;
    }

    // 任务�?1：改写getStudent方法
    public String[] getStudents(){
        String[] feedback = new String[numberOfStudents];
        for (int i = 0 ; i < numberOfStudents ; i++){
            feedback[i] = students[i];
        }
        return feedback;
    }

    public int getNumberOfStudents(){
        return numberOfStudents;
    }

    public String getCourseName(){
        return courseName;
    }

    // 任务�?3：完善dropStudent方法
    public void dropStudent(String student){
        for (int i = 0 ; i < numberOfStudents ; i++){
            if (students[i].equals(student)){
                for (; i < numberOfStudents ; i++){
                    students[i] = students[i+1];
                }
                numberOfStudents--;
                return;
            }
        }
    }

    // 任务�?4：添加clear方法
    public void clear(){
        String[] temp = new String[100];
        students = temp;
    }
}
