package exercise12;

import java.util.ArrayList;

public class SortArrayList {
	
    public static void sort(ArrayList<Number> list)
    {
        if (list.size() == 0 || list == null)
        {
            return ;
        }

        for (int i = 0; i < list.size() - 1; i++)
        {
            Number number = list.get(i);
            int minIndex = i;
            for (int j = i + 1; j < list.size(); j++)
            {
                if (list.get(j).doubleValue() < number.doubleValue())
                {
                    minIndex = j;
                    number = list.get(j);
                }
            }

            if (minIndex != i)
            {
                list.set(minIndex, list.get(i));
                list.set(i, number);
            }
        }
    }

}
