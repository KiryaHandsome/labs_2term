using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace station
{
    public class Station
    {
        private Ticket[]? tickets;
        private Coupon[]? coupons;

        // indexator
        public Ticket this[int index]
        {
            get
            {
                if (index < 0 || index >= tickets!.Length)
                {
                    throw new IndexOutOfRangeException();
                }
                return tickets[index];
            }
        }


        public Station() {  }


        public void AddTicket(double price, string path)
        {
            if (tickets == null)
            {
                tickets = new Ticket[1];
                tickets[0] = new Ticket(price, path);
            }
            else
            {
                Array.Resize(ref tickets, tickets.Length + 1);
                tickets[^1] = new Ticket(price, path);
            }
        }

        public string? FindPathWithMinPrice()
        {
            if(tickets == null)
            {
                return null;
            }
            string path = string.Empty;
            double price = double.MaxValue;
            foreach(var i in tickets)
            {
                if(i.Price < price)
                {
                    price = i.Price;
                    path = i.Path;
                }
            }
            return path;
        }

    }
}
