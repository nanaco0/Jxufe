package exercise12;

public class Square extends GeometricObject2 implements Coloarable
{
	private double side;
	
	public Square(String color,boolean filled) 
	{
		
	}

	public void  howToColor() 
	{
		 System.out.println("Color all four");
	}
	public double getSide() {
		return side;
	}
	public void setSide(double side) {
		this.side = side;
	}
}