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
    public class StationTests
    {
        [TestMethod()]
        public void FindPathWithMinPriceTest123()
        {
            Station station = new Station();
            station.AddTicket(123, "asd");
            Assert.AreEqual("asd", station.FindPathWithMinPrice());
        }

        [TestMethod()]
        public void FindPathWithMinPriceTest999_123_5_9_32()
        {
            Station station = new Station();
            station.AddTicket(999, "a");
            station.AddTicket(123, "b");
            station.AddTicket(5, "c");
            station.AddTicket(9, "d");
            station.AddTicket(32, "e");
            Assert.AreEqual("c", station.FindPathWithMinPrice());
        }

        [TestMethod()]
        public void FindPathWithMinPriceTest111_53_91_123_11()
        {
            Station station = new Station();
            station.AddTicket(111, "a");
            station.AddTicket(53, "b");
            station.AddTicket(91, "c");
            station.AddTicket(123, "d");
            station.AddTicket(11, "e");
            Assert.AreEqual("e", station.FindPathWithMinPrice());
        }

        [TestMethod()]
        public void IndexatorTicket2()
        {
            Station station = new Station();
            station.AddTicket(111, "a");
            station.AddTicket(53, "b");
            station.AddTicket(91, "c");
            station.AddTicket(123, "d");
            station.AddTicket(11, "e");
            var t = station[2].Price;
            Assert.AreEqual(t, 91);
        }

        [TestMethod()]
        public void IndexatorTicket1()
        {
            Station station = new Station();
            station.AddTicket(111, "a");
            station.AddTicket(53, "b");
            station.AddTicket(91, "c");
            station.AddTicket(123, "d");
            station.AddTicket(11, "e");
            var t = station[1].Price;
            Assert.AreEqual(t, 53);
        }

        [TestMethod()]
        public void IndexatorTicket124124124()
        {
            Station station = new Station();
            station.AddTicket(111, "a");
            station.AddTicket(53, "b");
            station.AddTicket(91, "c");
            station.AddTicket(123, "d");
            station.AddTicket(11, "e");
            bool isCatched = false;
            try
            {
                var t = station[124124124].Price;
            } catch(Exception ex)
            {
                isCatched = true;
            }

            Assert.AreEqual(true, isCatched);
        }
    }
}