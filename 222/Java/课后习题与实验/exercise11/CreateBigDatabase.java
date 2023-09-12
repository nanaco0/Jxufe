package exercise11;

import java.util.Random;
import java.io.File;
import java.io.PrintWriter;

public class CreateBigDatabase
{
    public static void main(String [] args) throws Exception
    {
        File file = new File("Salary.txt");
        if (file.exists())
        {
            System.out.println("Salary.txt has exist");
            System.exit(1);
        }

        String[] level = {"assistant", "associate", "full"};
        Random random = new Random(7);

        try(
            PrintWriter output = new PrintWriter(file);
        )
        {
            for (int i = 1; i < 1001; i++)
            {
                int levelRandom = random.nextInt(3);
                output.print("FirstName" + i);
                output.print(" SecondName" + i);
                output.print(" " + level[levelRandom]);
                if (levelRandom == 0)
                {
                    output.println(" " + (int)((random.nextDouble() * 30000 + 50000) * 100) / 100.0);
                }
                else if (levelRandom == 1)
                {
                    output.println(" " + (int)((random.nextDouble() * 50000 + 60000) * 100) / 100.0);
                }   
                else if (levelRandom == 2)
                {
                    output.println(" " + (int)((random.nextDouble() * 55000 + 75000) * 100) / 100.0);
                }
            }   
        }
    }
}