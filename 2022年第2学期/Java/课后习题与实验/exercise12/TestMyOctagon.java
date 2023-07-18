package exercise12;

public class TestMyOctagon
{
    public static void main(String [] args)
    {
        MyOctagon octagon1 = new MyOctagon(5);
        System.out.println(octagon1.getArea());
        MyOctagon octagon2 = (MyOctagon)octagon1.clone();
        System.out.println(octagon1.compareTo(octagon2));
    }
}