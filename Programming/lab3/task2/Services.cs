using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task2
{
    public class Services
    {
        public static double CalcY(double a, double b, double z)
        {
            double x;
            if(z < a * b)
            {
                x = Math.Sqrt(a * a + b * b * z);
                Console.WriteLine("Branch z < a * b");
            }
            else
            {
                x = Math.Pow(Math.Sin(z), 2) + Math.Abs(a * b * z);
                Console.WriteLine("Branch z >= a * b");
            }
            double y = Math.Round(a * x + b * x * Math.Cos(Math.Sqrt(x)) / (x + a * b), 5);
            Console.WriteLine($"y = { y }");
            return y;
        }
    }
}
