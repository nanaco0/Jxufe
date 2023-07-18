package exercise12;

import java.util.ArrayList;
import java.util.Arrays;

public class TestSortArrayList {
	
	public static void main(String[] args) {
		
		Integer[] numbers = {1,2,3,4,5};
        ArrayList<Number> list = new ArrayList<>(Arrays.asList(numbers));
        SortArrayList.sort(list);
        System.out.println(list);
		
	}
	
}
