package exercise06;

public class MyStringBuilder1Test {

	public static void main(String[] args) {
		String s1 = new String();
		s1="Java Test ";
		String s2 = new String();
		s2="String Demo ";
		MyStringBuilder1 string1 = new MyStringBuilder1(s1);
		MyStringBuilder1 string2 = new MyStringBuilder1(s2);
		System.out.println(string1.append(string2).show());
		System.out.println(string2.append(1234).show());
		System.out.println(string1.length());
		System.out.println(string2.charAt(3));
		System.out.println(string1.toLowerCase().show());
		System.out.println(string2.substring(0, 3).show());
		System.out.println(string1.toString());
	}
}