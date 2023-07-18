package exercise12;

import java.util.*;
public class ComparableCircle extends Circle implements Comparable<ComparableCircle>
{
 
	public ComparableCircle(double r) {
		super(r);
		// TODO �Զ����ɵĹ��캯�����
	}
	 public ComparableCircle max(ComparableCircle o1, ComparableCircle o2)
	    {
	        if (o1.compareTo(o2) > 0)
	        {
	            return o1;
	        }
	        else
	            return o2;
	    }
 
 
	@Override
	public int compareTo(ComparableCircle o) {
		// TODO �Զ����ɵķ������
		if (super.getArea() > o.getArea())
        {
            return 1;
        }
        else if (super.getArea() < o.getArea())
        {
            return -1;
        }
        else
            return 0;
 
	}
	
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		System.out.println("�����������뾶��");
		double r1 = input.nextDouble();
		ComparableCircle o1 = new ComparableCircle(r1);
		double r2 = input.nextDouble();
		ComparableCircle o2 = new ComparableCircle(r2);
		System.out.println(o1.compareTo(o2));
		input.close();
	}
}