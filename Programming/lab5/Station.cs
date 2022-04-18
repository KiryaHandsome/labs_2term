using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task
{
    public class Station
    {
        //list of passengers which bought ticket
        private List<Passenger> passengersInfo;
        //list of avaible tickets
        private List<Ticket> tariffs;

        public List<Ticket> Tariffs
        {
            get { return tariffs; }
        }

        public List<Passenger> PassengersInfo
        {
            get { return passengersInfo; }
        }

        public void AddTariff(Ticket tariff)
        {
            tariffs.Add(tariff);
        }

        public void AddPassenger(string surname, string passport)
        {
            passengersInfo.Add(new Passenger(surname, passport));
        }

        public void BuyTicket(string passport, Ticket ticket)
        {
            for(int i = 0; i < passengersInfo.Count; ++i)
            {
                if (passengersInfo[i].PassportInfo == passport)
                {
                    passengersInfo[i].BuyTicket(ticket);
                    break;
                }
            }
        }

        public void ShowAllTariffs()
        {
            for(int i = 1; i <= tariffs.Count; ++i)
            {
                Console.WriteLine($"#{i} Price: {tariffs[i - 1].Price}$; Path: {tariffs[i - 1].Path};");
            }
        }

        public int CostOfPassengersTickets(string passport)
        {
            for(int i = 0; i < passengersInfo.Count; i++)
            {
                if (passengersInfo[i].PassportInfo == passport)
                {
                    int cost = 0;
                    foreach(var curr in passengersInfo[i].Tickets)
                    {
                        cost += curr.Price;
                    }
                    return cost;
                }
            }
            return -1;
        }
        public void ShowPassengersByPath(string path)
        {
            bool isExist = false;
            foreach (var curr in tariffs)
            {
                if(curr.Path == path)
                {
                    isExist = true;
                }
            }

            if (isExist)
            {
                bool PassengerExist = false;
                bool isFirst = true;
                for(int i = 0; i < passengersInfo.Count; ++i)
                {
                    foreach(var curr in passengersInfo[i].Tickets)
                    {
                        if(curr.Path == path)
                        {
                            if (isFirst)
                            {
                                Console.WriteLine($"Next guys go to {path}");
                                isFirst = false;
                            }
                            Console.WriteLine(passengersInfo[i].Surname);
                            PassengerExist = true;
                            break;
                        }
                    }
                }
                if (!PassengerExist)
                {
                    Console.WriteLine($"Nobody go to {path}.");
                }
            }
            else
            {
                Console.WriteLine("No such path.");
            }
        }

        public int GetTariffsCount() {  return tariffs.Count; } 

        public int GetPassengersCount() { return passengersInfo.Count; }

        public Station() 
        {
            passengersInfo = new List<Passenger>();
            tariffs = new List<Ticket>();
        }



    }
}
