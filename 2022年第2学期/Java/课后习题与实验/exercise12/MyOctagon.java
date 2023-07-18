package exercise12;

public class MyOctagon extends GeometricObject implements Comparable<MyOctagon>, Cloneable
{
private double side;

public MyOctagon()
{
}

public MyOctagon(double side)
{
    this(side, "White", false);
}

public MyOctagon(double side, String color, boolean filled)
{
    super(color, filled);
    this.side = side;
}

public double getSide()
{
    return side;
}

public void setSide(double side)
{
    this.side = side;
}

@Override
public double getArea()
{
    return (2 + 4 * Math.sqrt(2)) * side * side;
}

@Override
public double getPerimeter()
{
    return 8 * side;
}

@Override
public int compareTo(MyOctagon octagon)
{
    if (getArea() > octagon.getArea())
    {
        return 1;
    }
    else if (getArea() < octagon.getArea())
    {
        return -1;
    }
    else
        return 0;
}

@Override
public String toString()
{
    return super.toString()  + "\nside : "  + side;
}

@Override
public Object clone() 
{
    try
    {
        MyOctagon octagon = (MyOctagon)super.clone();
        return octagon;
    }
    catch (CloneNotSupportedException ex)
    {
        return null;
    }
}
}