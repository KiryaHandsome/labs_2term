using task;

bool isExit = false;

Console.WriteLine("Program for work with Station system");
//create base of station
Station station = new Station();
string[] StartTariffs = { "Grodno", "Vitebsk", "Minsk", "Gomel", "Brest" };
int[] StartPrices = { 10, 20, 30, 40, 50 };
for(int i = 0; i < 5; ++i)
{
    station.AddTariff(new Ticket(StartPrices[i], StartTariffs[i]));
}

int choice = 0;
while(!isExit)
{
    Console.WriteLine("***************************************************************************");
    Console.WriteLine("Press ... to ");
    Console.WriteLine("1 - add passenger;\n2 - buy ticket for passenger;\n3 - show passengers by path;" +
        "\n4 - add tariff;\n5 - cost of passenger's tickets;\n6 - show all tariffs;\n0 - exit from program");
    choice = Convert.ToInt32(Console.ReadLine());
    switch (choice)
    {
        case 1:
            Console.Write("Enter passenger's surname: ");
            string surname = Console.ReadLine();
            Console.Write("Enter passenger's passport: ");
            string passport = Console.ReadLine();
            station.AddPassenger(surname, passport);
            Console.WriteLine("Passenger was added successfully.");
            break;
        case 2:
            station.ShowAllTariffs();
            Console.WriteLine("Enter number of tariff:");
            int num = Convert.ToInt32(Console.ReadLine());
            if(num < 0 || num > station.GetTariffsCount())
            {
                Console.WriteLine("Incorrect num");
                break;
            }
            else
            {
                Console.WriteLine("Enter passport of passenger:");
                string passpInfo = Console.ReadLine();
                bool pasExist = false;
                int i = 0;
                for (; i < station.GetPassengersCount(); ++i)
                {
                    if(station.PassengersInfo[i].PassportInfo == passpInfo)
                    {
                        pasExist = true;
                        break;
                    }
                }

                if (pasExist)
                {
                    station.BuyTicket(passpInfo, station.Tariffs[num - 1]);
                    Console.WriteLine("Ticket was acquired successfully!");
                }
                else
                {
                    Console.WriteLine("No such passenger.");
                }
            }
            break;
        case 3:
            Console.WriteLine("Enter path:");
            string path = Console.ReadLine();
            station.ShowPassengersByPath(path);
            break;
        case 4:
            Console.Write("Enter price of tariff:");
            int priceOfTicket = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter path of tariff: ");
            string pathOfTicket = Console.ReadLine();
            station.AddTariff(new Ticket(priceOfTicket, pathOfTicket));
            Console.WriteLine("Tariff was added succesfully!");
            break;
        case 5:
            Console.Write("Enter passport of passenger: ");
            string PassportInfo = Console.ReadLine();
            int cost = station.CostOfPassengersTickets(PassportInfo);
            if(cost == -1)
            {
                Console.WriteLine("No such passenger");
            }
            else
            {
                Console.WriteLine($"This guy bought tickets on {cost}$!");
            }
            break;
        case 6:
            station.ShowAllTariffs();
            break;
        case 0: 
            isExit = true;
            break;
            
    }
    Console.WriteLine("***************************************************************************");
}
