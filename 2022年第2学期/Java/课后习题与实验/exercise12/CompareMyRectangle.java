package exercise12;

public class CompareMyRectangle extends CompareGeometricObject
{
    private double width;
    private double height;

    public CompareMyRectangle()
    {
    }

    public CompareMyRectangle(double width, double height)
    {
        this(width, height, "white", false);
    }

    public CompareMyRectangle(double width, double height, String color, boolean filled)
    {
        super(color, filled);
        this.width = width;
        this.height = height;
    }

    public double getWidth()
    {
        return width;
    }

    public void setWidth(double width)
    {
        this.width = width;
    }

    public double getHeight()
    {
        return height;
    }

    public void setHeight(double height)
    {
        this.height = height;
    }

    @Override
    public double getArea()
    {
        return width * height;
    }

    @Override
    public double getPerimeter()
    {
        return 2 * (width + height);
    }

    @Override
    public String toString()
    {
        return super.toString() + "\nMy Rectangle Width : " + getWidth() + " Height : " + getHeight();
    }
}