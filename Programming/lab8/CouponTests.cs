using Microsoft.VisualStudio.TestTools.UnitTesting;
using station;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace station.Tests
{
    [TestClass()]
    public class CouponTests
    {
        [TestMethod()]
        public void PriceTest123_10()
        {
            Coupon coupon = new(123, 10, "path");
            int expected = (123 - 123 * 10 / 100);
            Assert.AreEqual(Convert.ToInt32(coupon.GetPrice()), expected);
        }

        [TestMethod()]
        public void PriceTest11_0()
        {
            Coupon coupon = new(11, 0, "path");
            int expected = (int)(11 - 0);
            Assert.AreEqual(Convert.ToInt32(coupon.GetPrice()), expected);
        }

        [TestMethod()]
        public void PriceTest111_50()
        {
            Coupon coupon = new(111, 50, "path");
            int expected = (int)(111 - 111 * 50 / 100);
            Assert.AreEqual(Convert.ToInt32(coupon.GetPrice()), expected);
        }
    }
}