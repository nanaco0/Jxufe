package exercise12;

public abstract class CompareGeometricObject implements Comparable<CompareGeometricObject>
{
	private String color;
	private boolean filled;
	private java.util.Date dateCreated;
	
	protected CompareGeometricObject()
	{
	    dateCreated = new java.util.Date();
	}
	
	protected CompareGeometricObject(String color, boolean filled)
	{
	    this.color = color;
	    this.filled = filled;
	    dateCreated = new java.util.Date();
	}
	
	public String getColor()
	{
	    return color;
	}
	
	public void setColor(String color)
	{
	    this.color = color;
	}
	
	public boolean isFilled()
	{
	    return filled;
	}
	
	public void setFilled(boolean filled)
	{
	    this.filled = filled;
	}
	
	public java.util.Date getDateCreated()
	{
	    return dateCreated;
	}
	
	@Override
	public String toString()
	{
	    return "Created on " + dateCreated + "\nColor : " + color + "\n and Filled : " + filled;
	}
	
	@Override
	public int compareTo(CompareGeometricObject o)
	{
	    if (getArea() < o.getArea())
	    {
	        return -1;
	    }
	    else if (getArea() > o.getArea())
	    {
	        return 1;
	    }
	    else
	        return 0;
	}
	
	public static CompareGeometricObject max(CompareGeometricObject o1, CompareGeometricObject o2)
	{
	    if (o1.compareTo(o2) > 0)
	    {
	        return o1;
	    }
	    else
	        return o2;
	}
	
	public abstract double getArea();
	
	public abstract double getPerimeter();
}