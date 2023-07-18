package exercise10;

public class TriangleUseIllegalTrianglException
{
    private double side1;
    private double side2;
    private double side3;

    public TriangleUseIllegalTrianglException()
        throws IllegalTriangleException
    {
        this(1.0, 1.0, 1.0);
    }

    public TriangleUseIllegalTrianglException(double side1, double side2, double side3)
        throws IllegalTriangleException
    {
        setSides(side1, side2, side3);
    }

    public void setSides(double side1, double side2, double side3)
        throws IllegalTriangleException
    {
        if ((side1 + side2 <= side3) || (side1 - side2 >= side3))
        {
            throw new IllegalTriangleException(side1, side2, side3);
        }
        else
        {
            this.side1 = side1;
            this.side2 = side2;
            this.side3 = side3;
        }   
    }

    public void setSide1(double side1) throws IllegalTriangleException
    {
        setSides(side1, this.side2, this.side3);
    }

    public void setSide2(double side2) throws IllegalTriangleException
    {
        setSides(this.side1, side2, this.side3);
    }

    public void setSide3(double side3) throws IllegalTriangleException
    {
        setSides(this.side1, this.side2, side3);
    }

    public double getSide1()
    {
        return side1;
    }

    public double getSide2()
    {
        return side2;
    }

    public double getSide3()
    {
        return side3;
    }

    public double getArea()
    {
        double s = (side1 + side2 + side3) / 2;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    public double getPerimeter()
    {
        return (side1 + side2 + side3);
    }
}