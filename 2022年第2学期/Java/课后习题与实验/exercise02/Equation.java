package exercise02;

import java.util.Scanner;

public class Equation {

    public static void main(String[] args) {
        System.out.print("Enter a b c : ");
        Scanner input = new Scanner (System.in);
        double a = input.nextDouble();
        double b = input.nextDouble();
        double c = input.nextDouble();
        input.close();
        double delta = Math.pow(b, 2) - 4 * a * c;
        double r1 = (-b + Math.pow (delta , 0.5))/(2 * a);
        double r2 = (-b - Math.pow (delta , 0.5))/(2 * a);
        if (delta > 0)
            System.out.printf("The equation has two roots %.6f %.5f" , r1 , r2);
        else if (delta == 0)
            System.out.printf("The equation has one root %.1f" , r1);
        else
            System.out.printf("The equation has no real roots ");
    }
}