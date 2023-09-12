package exercise06;

public class MyStringBuilder1 {

	private char[] value;
	public char[] show() {
		return value;
	}
	public MyStringBuilder1(String s) {
		value = new char[s.length()];
        for(int i=0; i<s.length(); i++) {
            value[i] = s.charAt(i);
        }
	}
	public MyStringBuilder1 append(MyStringBuilder1 s) {
		String string1 = new String();
		String string2 = new String();
		string1=String.valueOf(this.value);
		string2=String.valueOf(s.show());
		MyStringBuilder1 newString = new MyStringBuilder1(string1.concat(string2));
		return newString;
	}
	public MyStringBuilder1 append(int i) {
		String string1 = new String();
		String string2 = new String();
		string1=String.valueOf(value);
		string2=String.valueOf(i);
		MyStringBuilder1 newString = new MyStringBuilder1(string1.concat(string2));
		return newString;
	}
	public int length() {
		return this.value.length;
	}
	public char charAt(int index) {
		return value[index-1];
	}
	public MyStringBuilder1 toLowerCase(){
		String string = new String();
		string=String.valueOf(value);
		MyStringBuilder1 newString=new MyStringBuilder1(string.toLowerCase());
		return newString;
	}
	public MyStringBuilder1 substring(int begin, int end) {
		String string = new String();
		string=String.valueOf(value);
		MyStringBuilder1 newString = new MyStringBuilder1(string.substring(begin, end));
		return newString;
	}
	public String toString() {
		return new String(value);
	}
}
