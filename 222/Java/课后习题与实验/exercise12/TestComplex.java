package exercise12;

import java.util.Scanner;

public class TestComplex
{
    public static void main(String [] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the first complex number : ");
        double r1 = input.nextDouble();
        double i1 = input.nextDouble();
        Complex complex1 = new Complex(r1, i1);

        System.out.print("Enter the second complex number : ");
        double r2 = input.nextDouble();
        double i2 = input.nextDouble();
        Complex complex2 = new Complex(r2, i2);

        input.close();
        
        String c1 = "(" + r1 + " + " + i1 + "i)";
        String c2 = "(" + r2 + " + " + i2 + "i)";
        System.out.println( c1 + " + " + c2 + " = " + complex1.add(complex2).toString());
        System.out.println( c1 + " - " + c2 + " = " + complex1.subtract(complex2).toString());
        System.out.println( c1 + " * " + c2 + " = " + complex1.multiply(complex2).toString());
        System.out.println( c1 + " / " + c2 + " = " + complex1.divide(complex2).toString());
        System.out.println( "|" + c1 + " + " + c2 + "| = " + complex1.abs());

    }
}