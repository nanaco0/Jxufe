package exercise10;

import java.util.Scanner;

public class TestTriangleUseIllegalTrianglException
{
    public static void main(String [] args)
    {
        Scanner input = new Scanner(System.in);
        while (true)
        {
            System.out.println("Enter three sides for a triangle: ");
            try
            {
                double side1 = input.nextDouble();
                double side2 = input.nextDouble();
                double side3 = input.nextDouble();
                TriangleUseIllegalTrianglException triangle = 
                    new TriangleUseIllegalTrianglException(side1, side2, side3);
                System.out.println("The area is " + triangle.getArea());
                System.out.println("The perimeter is " + triangle.getPerimeter());
            }
            catch (IllegalTriangleException ex)
            {
                System.out.println(ex.getMessage());
                System.out.println("Try again.");
            }
            input.nextLine();
        }

    }
}