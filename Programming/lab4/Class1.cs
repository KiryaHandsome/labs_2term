using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    public class Ticket
    {
        private int cost;
        private string path;


        public Ticket(string Path = "Волковыск")
        {
            cost = 100;
            path = Path;
        }

        public int Cost
        {
            get { return cost; }
            set { cost = value; }
        }

        public string Path
        {
            get { return path; }
            set { path = value; }
        }
    }

    public class Station
    {
        private static Ticket ticket;
        private string nameStation;
        private int saledTicketsCount;
        private int seatsCount;
        private static Station StationInstance;

        private Station()
        {
            nameStation = "Минск";
            saledTicketsCount = 5;
            seatsCount = 10;
        }

        public Ticket Ticket
        {
            get { return ticket; }  

            set { ticket = value; }
        }

        public int SaledTicketsCount
        {
            get { return saledTicketsCount; }

            set {  saledTicketsCount = value; }
        }

        public int SeatsCount
        {
            get { return seatsCount; }

            set { seatsCount = value; }
        }

        public string NameStation
        {
            get { return nameStation; } 

            set { nameStation = value; }    
        }

        public static Station GetInstanceStation()
        {
            if(StationInstance == null)
            {
                StationInstance = new Station();
                ticket = new Ticket();
            }  
            return StationInstance;
        }

        public int CalcCostNotSaledTickets()
        {
            return (seatsCount - saledTicketsCount) * ticket.Cost;
        }



    }
}
