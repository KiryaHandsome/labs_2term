//variant 2

public class Program
{
    public static int Main()
    {
        Console.WriteLine("This program checks whether a given number is odd\n");
        bool exit = false;
        do
        {
            Console.WriteLine("Enter: 1 - for entering number; 0 - for exit\n");
            int choice = Convert.ToInt32(Console.ReadLine());
            int number;
            switch (choice)
            {
                case 1:
                    Console.WriteLine("Enter number: ");
                    number = Convert.ToInt32(Console.ReadLine());
                    if (IsOdd(number))
                    {
                        Console.WriteLine("This number is odd\n");
                    }
                    else
                    {
                        Console.WriteLine("This number isn't odd(even)\n");
                    }
                    break;
                case 0:
                    exit = true;
                    break;
            }
        } while (!exit);
        return 0;
    }

    public static bool IsOdd(int a)
    {
        return a % 2 == 1;
    }
} 
