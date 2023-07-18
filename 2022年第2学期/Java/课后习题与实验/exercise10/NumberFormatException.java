//package exercise10;
//package exercise8;
//
//public class NumberFormatException
//{
//    public static void main(String[] args)
//    {
//        if (args.length != 3)
//        {
//            System.out.println("Enter x1 operation x2");
//            System.exit(1);
//        }
//
//        try
//        {
//            int x1 = parseInt(args[0]);
//            int x2 = parseInt(args[2]);
//            System.out.println(args[0] + " " + args[1] + " " + args[2] + " = " + result(x1, x2, args[1].charAt(0)));
//        }
//        catch (NumberFormatException ex)
//        {
//            System.out.println("Wrong input: " + ex.getMessage());
//        }
//    }
//
//    public static int parseInt(String str) throws NumberFormatException 
//    {
//        for (int i = 0; i <  str.length(); i++)
//        {
//            if (!Character.isDigit(str.charAt(i)))
//            {
//                throw new NumberFormatException(str);
//            }
//            //System.out.println("会执行吗");
//        }
//
//        return Integer.parseInt(str);
//    }
//
//    public static int result(int x1, int x2, char operation)
//    {
//        switch (operation)
//        {
//        case '+':
//            return (x1 + x2);
//        case '-':
//            return (x1 - x2);
//        case '.':
//            return (x1 * x2);
//        case '/':
//            return (x1 / x2);
//        default : 
//            return 0;
//        }
//    }
//
//}
//// 可以看出一旦抛出异常，在出现异常的方法中没有捕获和处理，就会直接中断