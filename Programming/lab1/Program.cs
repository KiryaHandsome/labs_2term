using System;

namespace _153501_Pryhozhy
{
    class Program
    {
        static void Main()
        {
            Console.Write("Enter first number: ");
            int first = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter second number: ");
            int second = Convert.ToInt32(Console.ReadLine());
            int result = first / second;
            Console.WriteLine($"{first} / {second} = {result}");
        }
    }
}
