package exercise02;

public class Test {
    //正确代码如下，原代码缺少“static”，
    public static void main(String[] args) {
        double i = 50.0;
        double k = i + 50.0;
        double j = k + 1;
        //正确代码如下，原代码不应该在双引号内换行，可以在双引号外换行但是要用�?+”连�?
        System.out.println("j is " + j + " and k is " + k);
    }
}