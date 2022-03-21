using task3;


Console.WriteLine("This program demonstrate work of class <DateService>");
bool isExit = false;
do
{
    Console.WriteLine("Enter 1 - for caclulate day of week of entered date, " +
        "2 - for calculate amount of days between your and current date, 0 - for exit");
    int choice = Convert.ToInt32(Console.ReadLine());  
    if(choice == 1)
    {
        Console.WriteLine("Enter date in dd/mm/yyyy");
        string date = Console.ReadLine();
        Console.WriteLine(DateService.ToString(DateService.GetDayOfWeek(date)));
    }
    if(choice == 2)
    {
        int day, month, year;
        Console.Write("Enter day = ");
        day = Convert.ToInt32(Console.ReadLine());

        Console.Write("Enter month = ");
        month = Convert.ToInt32(Console.ReadLine());

        Console.Write("Enter year = ");
        year = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine(DateService.GetDaysSpan(day, month, year));
    }
    if(choice == 0)
    {
        isExit = true;
    }
} while (!isExit);
