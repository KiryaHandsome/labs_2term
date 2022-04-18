using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task
{
    public class Passenger
    {
        private string surname;
        private string passport;
        private List<Ticket> tickets;

        public List<Ticket> Tickets
        {
            get { return tickets; }
            set { tickets = value; }
        }

        public string Surname 
        { 
            get { return surname; }
            set { surname = value; }
        }

        public string PassportInfo
        {
            get { return passport; }
            set { passport = value; }
        }


        public Passenger(string surname = "Ivanov", string passport = "KH123456789")
        {
            if(tickets == null) tickets = new List<Ticket>();
            this.surname = surname;
            this.passport = passport;    
        }

        public void BuyTicket(Ticket ticket)
        {
            tickets.Add(ticket);
        }


    }

}
