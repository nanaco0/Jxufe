package exercise11;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class isSorted {

	public static void main(String[] args) throws IOException {
		File myText = new File("SortedStrings.txt");
		
		if(!myText.exists()) {
			PrintWriter output = new PrintWriter(myText);
		}
		
		Scanner input = new Scanner(myText);
		
		ArrayList<String> list = new ArrayList<>();
		
        while (input.hasNext())
        {
            String[] divide = input.nextLine().split("[,. ]");
            for (String words : divide)
            {
                list.add(words);
            }
        }

        judgeSorted(list);
    }

    public static void judgeSorted(ArrayList<String> list)
    {
        for (int i = 0; i < list.size() - 1; i++)
        {
            if (list.get(i).compareTo(list.get(i + 1)) > 0)
            {
                System.out.println(list.get(i) + " " +
                    list.get(i + 1));
                break;
            }

        }
	
	}
	
}
