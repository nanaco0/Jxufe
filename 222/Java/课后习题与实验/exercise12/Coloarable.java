package exercise12;

import java.util.Scanner;

public interface Coloarable
{
	void howToColor();
	
	public static void main(String [] args)
    {
        Scanner input = new Scanner(System.in);
        GeometricObject2[] squares = new Square[5];

        for (int i = 0; i < 5; i++)
        {
            System.out.println(i + " : Square ");
            System.out.print("\t输入颜色: ");
            String color = input.next();
            System.out.print("\t输入是否填充: ");
            boolean filled = input.nextBoolean();

            squares[i] = new Square(color, filled);
        }
        input.close();
    }
}


class GeometricObject2
{
	private String color;
	private boolean filled;
	public String getColor() {
		return color;
	}
	public void setColor(String color) {
		this.color = color;
	}
	public boolean isFilled() {
		return filled;
	}
	public void setFilled(boolean filled) {
		this.filled = filled;
	}
}