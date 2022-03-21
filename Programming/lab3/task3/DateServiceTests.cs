using Microsoft.VisualStudio.TestTools.UnitTesting;
using task3;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task3.Tests
{
    [TestClass()]
    public class DateServiceTests
    {
        [TestMethod()]
        public void GetDayOfWeekTest1()
        {
            string date = "22/03/2022";
            int expected = 2;

            Assert.AreEqual(expected, DateService.GetDayOfWeek(date));
        }
        [TestMethod()]
        public void GetDayOfWeekTest2()
        {
            string date = "11/11/1929";
            int expected = 1;

            Assert.AreEqual(expected, DateService.GetDayOfWeek(date));
        }
        [TestMethod()]
        public void GetDayOfWeekTest3()
        {
            string date = "10/2/2011";
            int expected = 4;

            Assert.AreEqual(expected, DateService.GetDayOfWeek(date));
        }

        [TestMethod()]
        public void GetDaysSpanTest1()
        {
            int day = 21;
            int month = 3;
            int year = 2022;

            int expected = (int)(DateTime.Now - new DateTime(year, month, day)).TotalDays;
            Assert.AreEqual(expected, DateService.GetDaysSpan(day, month, year));
        }
        [TestMethod()]
        public void GetDaysSpanTest2()
        {
            int day = 11;
            int month = 8;
            int year = 2222;

            int expected = (int)(new DateTime(year, month, day) - DateTime.Now).TotalDays;
            Assert.AreEqual(expected, DateService.GetDaysSpan(day, month, year));
        }
        [TestMethod()]
        public void GetDaysSpanTest3()
        {
            int day = 22;
            int month = 3;
            int year = 2011;

            int expected = (int)(DateTime.Now - new DateTime(year, month, day)).TotalDays;
            Assert.AreEqual(expected, DateService.GetDaysSpan(day, month, year));
        }
    }
}