//7.2 倒置输入�?10个数�?

package exercise04;

import java.util.Scanner;

public class Reverse {

	public static void main(String[] args) {
		System.out.println("Enter 10 numbers : ");
		Scanner input = new Scanner(System.in);
		input.close();
		int[] arr = new int[10];
		for(int i=0;i<10;i++) {
			arr[i]=input.nextInt();
		}
		System.out.println("The inverted number : ");
		for(int i=9;i>=0;i--) {
			System.out.printf("%d ",arr[i]);
		}
	}

}