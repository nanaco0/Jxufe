package exercise06;

public class MyIntegerTest{
    public static void main(String[] args) {
        char[] a = {'1', '2', '3'};
        String b = "123";
        MyInteger myInteger=new MyInteger(6);
        MyInteger myInteger1=new MyInteger(7);
        //以下验证值分别为偶数、奇数或素数，那么isEvenO、isOdd()和isPrime 方法都会返回 true
        System.out.println("The "+myInteger.get()+" is odd : "+myInteger.isOdd());
        System.out.println("The "+myInteger.get()+" is even : "+myInteger.isEven());
        System.out.println("The "+myInteger.get()+" is prime : "+myInteger.isPrime());
        //以下验证 如果指定值分别为偶数、奇数或素数，那么相应的静�?�方�? isEven(int)、isOdd(int)�? isPrime(int)会返�? true
        System.out.println("The int is odd : "+MyInteger.isOdd(5));
        System.out.println("The int is even : "+MyInteger.isEven(5));
        System.out.println("The int is prime : "+MyInteger.isPrime(5));
        //以下验证 如果指定值分别为偶数�? 奇数或素数，那么相应的静态方�? isEven(MyInteger)�? isOdd(MyInteger)�? isPrime(MyInteger)会返�? true
        System.out.println("The MyInteger is odd : "+MyInteger.isOdd(myInteger));
        System.out.println("The MyInteger is even: "+MyInteger.isEven(myInteger));
        System.out.println("The MyInteger is prime : "+MyInteger.isPrime(myInteger));
        //以下验证如果该对象的值与指定的�?�相等，那么equals(int)�? equals(MyInteger)方法返回 true
        System.out.println("The int is equal to MyInteger: "+myInteger.equals(myInteger1.get()));
        System.out.println("The int is equal to MyInteger: "+myInteger.equals(myInteger1));
        //以下验证 静�?�方�? parseInt(char[])将数字字符构成的数组转换为一个int �?
        System.out.println(MyInteger.parseInt(a));
        //以下验证 静�?�方�? parseInt(String)将一个字符串转换为一个int 值�??
        System.out.println(MyInteger.parseInt(b));
    }
}
