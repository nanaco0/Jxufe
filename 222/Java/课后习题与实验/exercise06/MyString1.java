package exercise06;

public class MyString1 {//MyString类的实现
	private final char[] chars;
	public char[] show() {
		return chars;
	}
	public MyString1(char[] chars) {
		this.chars=chars;
	}
	public char charAt(int index) {
		return this.chars[index-1];
	}
	public int length() {
		return chars.length;
	}
	public MyString1 substring(int begin, int end) {
		char[] string=new char[end-begin+1];
		int i=0;
		int n=0; 
		for(i=begin;i<end;i++){
			string[n]=chars[i];
			n++;
		}
		MyString1 newString=new MyString1(string);
		return newString;
	}
	public MyString1 toLowerCase() {
		char[] string = new char[chars.length];
		for(int i=0; i<chars.length; i++) {
			string[i]=chars[i];
		}
		for(int i=0; i<chars.length; i++) {
			if(string[i]>='A'&&string[i]<='Z') {
				string[i]=(char) (string[i]+32);
			}
		}
		MyString1 newString=new MyString1(string);
		return newString;
	}
	public boolean equals(MyString1 s) {
		int flag=0;
		if(this.chars.length==s.chars.length) {
			for(int i=0; i<=chars.length-1; i++) {
				if(s.chars[i]!=this.chars[i]) {
					flag=1;
					break;
				}
			}
			if(flag==0)
				return true;
			else
				return false;
		}
		return false;
	}
	public static MyString1 valueOf(int i) {
		char[] string=new char[10];
		int flag=0;
		for(int n=0; i*10/10!=0; n++) {
			string[n]=(char)(i%10+(int)'0');
			i=i/10;
			flag++;
		}
		int top=0,end=flag-1;	
		while(top<end){
			char temp=string[top];
			string[top]=string[end];
			string[end]=temp;
			top++;
			end--;
		}
		MyString1 newString=new MyString1(string);
		return newString;
	}
}
