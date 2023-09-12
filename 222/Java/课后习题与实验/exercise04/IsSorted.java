//7.19 是否排序�?

package exercise04;

import java.util.Arrays;
import java.util.Scanner;

public class IsSorted {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		//输入size
		System.out.printf("Enter the size of the list : ");
		int size = input.nextInt();

		//输入list
		System.out.print("Enter the contents of the list: ");
		int[] list = new int[size];
		for (int i = 0 ; i < size ; i++){
			list[i] = input.nextInt();
		}
		input.close();

		//输出该数�?
		System.out.printf("This list has %d integers : ", list.length);
		for (int i = 0 ; i < size ; i++){
			System.out.print(list[i] + " ");
		}
		System.out.println();

		//判断该数组是否排�?
		if(isSorted(list))
			System.out.println("This list is already sorted.");
		else
			System.out.println("This list is not sorted.");
	}

	public static boolean isSorted(int[] list) {
		int[] list0 = Arrays.copyOf(list, list.length);
		Arrays.sort(list);
		return Arrays.equals(list, list0);
	}
}

