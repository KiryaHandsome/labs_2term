using Buildings;

bool isExit = false;

Factory factory = null;
BlockOfFlats block = null;

//create Block of flats
bool isFactory = false, isBlock = false;

while (!isExit)
{
    Console.WriteLine("Enter 1 for work with factory, 2 for work with block of flats, 0 for exit : ");
    int num = Convert.ToInt32(Console.ReadLine());
    switch (num)
    {
        case 1: isFactory = true; break;
        case 2: isBlock = true; break;
        case 0: isExit = true; break;
    }
    while (isFactory)
    {
        Console.WriteLine("Enter ... to \n1 - create Factory;\n2 - get material of factory;\n" +
            "3 - print all info about factory;\n4 - get produced products today;\n0 - go to main menu;");
        int choice = Convert.ToInt32(Console.ReadLine());
        switch (choice)
        {
            case 1:
                if(factory == null)
                {
                    Console.Write("Enter product of factory: ");
                    string product = Console.ReadLine();
                    Console.Write("Enter number of employes on factory: ");
                    int numberOfEmployes = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Enter number of floors: ");
                    int numberOfFloors = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Enter shape: ");
                    string shape = Console.ReadLine();
                    factory = new Factory(product, numberOfEmployes, numberOfFloors, shape);
                    Console.WriteLine("Factory was created successfully.");
                }
                else
                {
                    Console.WriteLine("Factory already exist.");
                }
                break;
            case 2:
                if(factory != null)
                {
                    Console.WriteLine($"Material of factory - {factory.GetMaterial()}.");
                }
                else
                {
                    Console.WriteLine("Factory not created yet.");
                }
                break;
            case 3:
                if (factory != null)
                {
                    factory.PrintAllInfo();
                }
                else
                {
                    Console.WriteLine("Factory not created yet.");
                }
                break;
            case 4:
                if (factory != null)
                {
                    factory.ProduceProduct();
                }
                else
                {
                    Console.WriteLine("Factory not created yet.");
                }
                break;
            case 0:
                isFactory = false;
                break;
        }
    }

    while (isBlock)
    {
        Console.WriteLine("Enter ... to \n1 - create Block of flats;\n2 - get debt for electricity;\n" +
           "3 - get inforemation about block of flats;\n4 - get material of building;\n5 - pay for electricity;\n0 - go to main menu;");
        int choice = Convert.ToInt32(Console.ReadLine());
        switch (choice)
        {
            case 1:
                if (block == null)
                {
                    Console.Write("Enter number of flats: ");
                    int numOfFlats = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Enter number of floors: ");
                    int numberOfFloors = Convert.ToInt32(Console.ReadLine());
                    Console.Write("Enter shape: ");
                    string shape = Console.ReadLine();
                    block = new BlockOfFlats(numOfFlats, numberOfFloors, shape);
                    Console.WriteLine("Block of flats was created successfully.");
                }
                else
                {
                    Console.WriteLine("Block of flats already exist.");
                }
                break;
            case 2:
                if (block != null)
                {
                    Console.WriteLine($"Debt for electricity = {block.GetDebtForElectricity()}.");
                }
                else
                {
                    Console.WriteLine("Block of flats not created yet.");
                }
                break;
            case 3:
                if (block != null)
                {
                    block.GetInfoAboutBuilding();
                }
                else
                {
                    Console.WriteLine("Block of flats not created yet.");
                }
                break;
            case 4:
                if (block != null)
                {
                    Console.WriteLine(block.GetMaterial());
                }
                else
                {
                    Console.WriteLine("Block of flats not created yet.");
                }
                break;
            case 5:
                if(block != null)
                {
                    Console.Write("Enter sum for pay for electricity: ");
                    double sum = Convert.ToDouble(Console.ReadLine());
                    block.PayForElectricity(sum);
                }
                else
                {
                    Console.WriteLine("Block of flats not created yet.");
                }
                break;
            case 0:
                isBlock = false;
                break;
        }
    }
   
}
