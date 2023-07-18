package exercise10;

import java.util.Scanner;

public class TestArrayIndexOutBoundsException {
	
	public static void main(String[] args) {
		
		int[] array = new int[100];
		for (int i = 0; i < array.length; i++) {
			array[i]=(int) (Math.random()*100);
		}
		
		System.out.println("Please enter the index :");
		
		Scanner input = new Scanner(System.in);
		int index = input.nextInt();
		
		try {
			if(index >= array.length) {
				throw new ArrayIndexOutOfBoundsException();
			}
			else {
				System.out.println(array[index]);
			}
		}
		catch (Exception e) {
			System.out.println("Out of Bounds");
		}
	}
}
