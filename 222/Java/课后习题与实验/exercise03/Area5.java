//4.1 求五边形面积�?135页）

package exercise03;

import java.util.Scanner;

public class Area5 {

	public static void main(String[] args) {
		System.out.printf("Enter the length from center to a vertex : ");
		Scanner input = new Scanner (System.in);
		double pi =3.1415926535;
		double r = input.nextDouble();
		double s = 2*r*Math.sin(pi/5);
		System.out.printf("The area of the pentagon is %.2f ." , (5*Math.pow(s, 2))/(4*Math.tan(pi/5)));
		input.close();
	}
}