using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task
{
    public class Ticket
    {
        private int price;
        private string path;

        public int Price    
        {
            get { return price; }
            set 
            { 
                if(price > 0) price = value;
                else price = 0;
            }
        }

        public string Path
        {
            get { return path; }
            set { path = value; }
        }

        public Ticket(int price = 10, string path = "Minsk")
        {
            this.price = price;
            this.path = path;
        }
    }
}
