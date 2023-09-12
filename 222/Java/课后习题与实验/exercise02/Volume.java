package exercise02;

import java.util.Scanner;

public class Volume {
    public static void main(String[] args) {
        System.out.print("Enter the radius and ength of a cylinder : ");
        Scanner input = new Scanner (System.in);
        double radius = input.nextDouble();
        double length = input.nextDouble();
        double pi = 3.141526535;
        System.out.printf("The area is %6.4f \n" , Math.pow(radius, 2) * pi);
        System.out.printf("The volume is %5.1f\n" , Math.pow(radius, 2) * pi * length);
        input.close();
    }
}