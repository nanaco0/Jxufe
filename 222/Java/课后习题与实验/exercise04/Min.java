//7.9 找出�?小元�?

package exercise04;

import java.util.Scanner;

public class Min {

	public static void main(String[] args) {
		System.out.printf("Enter 10 numbers : ");
		Scanner input = new Scanner(System.in);
		double[] arr = new double[10];
		for(int i=0;i<arr.length;i++) {
			arr[i] =input.nextDouble();
		}
		input.close();
		System.out.printf("Tne Min element is %.1f " , min(arr));
	}

	public static double min(double[] array) {
		double result = array[0];
		for(double e : array) {
			if(e<result) {
				result=e;
			}
		}
		return result;
	}
}