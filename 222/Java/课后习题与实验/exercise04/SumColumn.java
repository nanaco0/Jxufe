//8.1 分列求和

package exercise04;

import java.util.Scanner;

public class SumColumn {

	public static void main(String[] args) {
		System.out.println("Enter a 3-by-4 matrix row by row :");
		Scanner input = new Scanner(System.in);
		double[][] arr = new double[3][4];
		for(int i=0; i<arr.length; i++) {
			for(int j=0; j<arr[i].length; j++) {
				arr[i][j]=input.nextDouble();
			}
		}
		input.close();
		for(int i=0; i<arr[0].length; i++) {
			System.out.printf("Sum of the elements at column %d is %.1f\n", i, sumColumn(arr, i));
		}
	}
	
	public static double sumColumn(double[][] m, int columnIndex) {
		double sum = 0;
		for(int i=0; i<m.length; i++) {
			sum += m[i][columnIndex];
		}
		return sum;
	}
}
