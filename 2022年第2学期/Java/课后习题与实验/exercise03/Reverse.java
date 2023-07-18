//5.46 逆序显示字符串（179页）

package exercise03;

import java.util.Scanner;

public class Reverse {

	public static void main(String[] args) {
		System.out.printf("Enter a string : ");
		Scanner input = new Scanner (System.in);
		String str1 = input.nextLine();
		input.close();
		String str2 = "";
		char ch[] = str1.toCharArray();
		int i , j = str1.length();
		for (i = j-1 ; i >= 0 ; i--) str2 = str2 + ch[i];
		System.out.println(str2);
	}
}