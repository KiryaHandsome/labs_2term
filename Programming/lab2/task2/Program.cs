//variant 2

public class Program
{
    public static int Main()
    {

        Console.WriteLine("This program checks situation of the entered point as to shaded area(inside, outside or on the boarder)\n");
        int choice = 0;
        bool exit = false;
        double x, y;
        do
        {
            Console.WriteLine("Enter 1 - for input point's coordinates, 0 - for exit\n");
            choice = Convert.ToInt32(Console.ReadLine());
            switch (choice)
            {
                case 1:
                    Console.WriteLine("Enter coordinates of point\n");
                    Console.Write("x = ");
                    x = Convert.ToDouble(Console.ReadLine());
                    Console.Write("y = ");
                    y = Convert.ToDouble(Console.ReadLine());
                    int position = LocationOfPoint(x, y);

                    switch (position)
                    {
                        case 1:
                            Console.WriteLine("Point inside the shaded area.\n"); break;
                        case -1:
                            Console.WriteLine("Point outside the shaded area.\n"); break;
                        case 0:
                            Console.WriteLine("Point on the boarder of the shaded area.\n"); break;
                    }
                    break;
                case 0:
                    exit = true;
                    break;
            }
        } while (!exit);
        return 0;
    }

    public static int LocationOfPoint(double x, double y)  //returns values: 
    {                                                      //  -1 - outside the area
        double X2 = Math.Pow(x, 2);                        //  0 - on the border
        double Y2 = Math.Pow(y, 2);                        //  1 - inside the area
        if( X2 + Y2 < 9 && y > 0)
        {
            return 1;
        } else if((X2 + Y2 == 9 && y >= 0) || (y == 0 && X2 <= 9))
        {
            return 0;
        } else
        {
            return -1;
        }
    }
}


