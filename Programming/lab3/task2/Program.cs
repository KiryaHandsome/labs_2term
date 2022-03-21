using task2;


bool isExit = false;
Console.WriteLine("This program calculate formula 2 in task 2");
double a, b, z;
do
{
    Console.WriteLine("Enter 1 - for enter data, 0 - for exit");
    int choice = Convert.ToInt32(Console.ReadLine());
    if (choice == 1)
    {
        Console.Write("Enter a = ");
        a = Convert.ToDouble(Console.ReadLine());
        Console.Write("Enter b = ");
        b = Convert.ToDouble(Console.ReadLine());
        Console.Write("Enter z = ");
        z = Convert.ToDouble(Console.ReadLine());
        Services.CalcY(a, b, z);
    }
    if (choice == 0)
    {
        isExit = true;
    }
} while (!isExit);