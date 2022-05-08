using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace station
{
    public class Ticket : IPrice
    {
        private double price;
        private string path;
       
        public double Price { get { return price; } set { price = value; } }  

        public string Path { get { return path; } set { path = value; } }   

        public double GetPrice()
        {
            return price;
        }

        public Ticket(double price, string path)
        {
            this.price = price;
            this.path = path;
        }

    }
}
