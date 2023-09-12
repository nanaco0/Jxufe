package exercise11;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class File_R_W {
	
	public static void main(String[] args) throws IOException {
		
		File myText = new File("Exercise12_15.txt");
		PrintWriter output = new PrintWriter(myText);
		
		if (myText.exists()) {
			System.out.println("当前Java程序目录下存在文件“Exercise12_15.txt”");
		}
		else {
			System.out.println("当前Java程序目录下不存在文件“Exercise12_15.txt，已通过Java创建该文件。”");
		}
		
		Random random = new Random(7);
        for (int i = 0; i < 100; i++)
        {
            output.print(random.nextInt(100) + " ");
        }

        output.close();

        Scanner input = new Scanner(myText);
        int[] numbers = new int[100];
        int index = 0;
        while (input.hasNext())
        {
            numbers[index++] = input.nextInt();
            input.skip(" ");
        }
        input.close();

        Arrays.sort(numbers);

        for (int number : numbers)
        {
            System.out.println(number);
        }
	}
	

}
