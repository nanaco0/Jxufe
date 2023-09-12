package exercise12;

import java.util.Scanner;

public class TestTriangle {

	public static void main(String[] args) {
			
		Scanner input = new Scanner(System.in);
		
		System.out.println("请输入三角形的三条边：");
		double side1 = input.nextDouble(); 
		double side2 = input.nextDouble();
		double side3 = input.nextDouble();
		
		System.out.println("请输入三角形的颜色：");
		String color = input.next();
		
		System.out.println("请输入三角形是否填充（是/否）：");
		Boolean filled = input.nextBoolean();
		
		input.close();
				
		Triangle triangle1 = new Triangle(side1, side2, side3);
		triangle1.setColor(color);
		triangle1.setFilled(filled);
		System.out.println(triangle1.toString());
		System.out.println("Area: "+triangle1.getArea());
		System.out.println("Perimter: "+triangle1.getPerimeter());
	}

}
