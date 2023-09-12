package exercise12;

import java.util.Scanner;

public class TestCompareRectangle
{
    public static void main(String [] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Create the first Rectangle (enter width, height): ");
        double firstWidth = input.nextDouble();
        double firstHeight = input.nextDouble();

        System.out.print("Crate the second Rectangle (enter width, height): ");
        double secondWidth = input.nextDouble();
        double secondHeight = input.nextDouble();
        
        input.close();

        CompareMyRectangle rectangle1 = new CompareMyRectangle(firstWidth, firstHeight);
        CompareMyRectangle rectangle2 = new CompareMyRectangle(secondWidth, secondHeight);

        System.out.println(CompareGeometricObject.max(rectangle1, rectangle2).toString());
        // 可以看出此处的 max 返回的是 CompareMyRectangle 的一个实例
    }
}