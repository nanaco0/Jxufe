//4.18 判定学生专业年级�?138页）

package exercise03;

import java.util.Scanner;

public class Speciality {

	public static void main(String[] args) {
		System.out.printf("Enter two characters : ");
		Scanner input = new Scanner (System.in);
		String str = input.nextLine();
		char c = str.charAt(0);
		char num = str.charAt(1);
		if((c=='M'|c=='C'|c=='I')&(num=='1'|num=='2'|num=='3'|num=='4')) {
			switch (c) {
				case 'M' : System.out.printf("Mathematics ");break;
				case 'C' : System.out.printf("Computer Science ");break;
				case 'I' : System.out.printf("Information Technology ");
			}
			switch (num) {
				case '1' : System.out.printf("Freshman ");break;
				case '2' : System.out.printf("Sophomor ");break;
				case '3' : System.out.printf("Junior ");break;
				case '4' : System.out.printf("Senior ");
			}
		}
		else System.out.println("Invalid input");
		input.close();
	}
}