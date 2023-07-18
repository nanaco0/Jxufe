package exercise06;

public class MyString1Test {//测试程序
	public static void main(String[] args) {
		char[] s1 = new char[]{'J','a','v','a',' ','T','e','s','t'};
		char[] s2 = new char[]{'S','t','r','i','n','g'};
		MyString1 string1 = new MyString1(s1);
		MyString1 string2 = new MyString1(s2);
		System.out.println(string1.show());
		System.out.println(string1.charAt(2));
		System.out.println(string1.length());
		System.out.println((string1.substring(0, 3)).show());
		System.out.println(string1.toLowerCase().show());
		System.out.println(string1.equals(string2));
		System.out.println(MyString1.valueOf(1234567).show());
	}
}

