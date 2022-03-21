using task1;

class Program
{
    public static int Main()
    {
        Console.WriteLine("This program calculate next formule : z = max(x, 2y + x) - max(7x + 2y, y)\n");
        bool isExit = false;
        double x, y, result;
        do
        {
            Console.WriteLine("Enter 1 - for input data, 0 - for exit;");
            int choice = Convert.ToInt32(Console.ReadLine());
            if(choice == 1)
            {
                Console.Write("Enter x = ");
                x = Convert.ToDouble(Console.ReadLine());
                Console.Write("Enter y = ");
                y = Convert.ToDouble(Console.ReadLine());
                result = MyCalc.Max(x, 2 * y + x) - MyCalc.Max(7 * x + 2 * y, y);
                Console.WriteLine($"z = { result }");
            }
            if(choice == 0)
            {
                isExit = true;
            }

        } while (!isExit);
        
        return 0;
    }

    
}