using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace station
{
    public class Coupon : IPrice
    {
        private double price;
        private string path;
        private int discount_percent;

        public double Price()
        {
            return price;
        }

        public int DiscountPercent()
        {
            return discount_percent;
        }

        public double GetPrice()
        {
            return price - price * discount_percent / 100;
        }

        public Coupon(double price, int percent, string path)
        {
            this.path = path;
            this.price = price;  
            this.discount_percent = percent;
        }
    }
}
