package exercise12;

public class Complex implements Cloneable
{
    private double realPart;
    private double imaginaryPart;

    public Complex()
    {
    }

    public Complex(double a)
    {
        this(a, 0);
    }

    public Complex(double a, double b)
    {
        this.realPart = a;
        this.imaginaryPart = b;
    }

    public double getRealPart()
    {
        return realPart;
    }

    public double getImaginaryPart()
    {
        return imaginaryPart;
    }

    public Complex add(Complex c)
    {
        double r = realPart + c.getRealPart();
        double i = imaginaryPart + c.getImaginaryPart();
        return new Complex(r, i);
    }

    public Complex subtract(Complex c)
    {
        double r = realPart - c.getRealPart();
        double i = imaginaryPart - c.getImaginaryPart();
        return new Complex(r, i);
    }

    public Complex multiply(Complex c)
    {
        double r = realPart * c.getRealPart() - imaginaryPart * c.getImaginaryPart();
        double i = realPart * c.getImaginaryPart() + imaginaryPart * c.getRealPart();

        return new Complex(r, i);
    }

    public Complex divide(Complex c)
    {
        double r = (realPart * c.getRealPart() + imaginaryPart * c.getImaginaryPart()) / 
            (c.getRealPart() * c.getRealPart() + c.getImaginaryPart() * c.getImaginaryPart());
        double i = (realPart * c.getImaginaryPart() - imaginaryPart * c.getRealPart()) /
            (c.getRealPart() * c.getRealPart() + c.getImaginaryPart() * c.getImaginaryPart());

        return new Complex(r, i);
    }

    public double abs()
    {
        return Math.sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
    }

    @Override
    public String toString()
    {
        if (realPart == 0)
        {
            return imaginaryPart + "i";
        }
        else if (imaginaryPart == 0)
        {
            return realPart + "";
        }
        else
            return realPart + " + " + imaginaryPart + "i";
    }

    @Override
    public Object clone()
    {
        return new Complex(realPart, imaginaryPart);
    }
}