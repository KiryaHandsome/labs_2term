using Microsoft.VisualStudio.TestTools.UnitTesting;
using task1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task1.Tests
{
    [TestClass()]
    public class MyCalcTests
    {
        [TestMethod()]
        public void Max_1231_19999()
        {
            double x = 1231, y = 19999;
            double expected = y;
            Assert.AreEqual(expected, MyCalc.Max(x, y));
        }
        [TestMethod()]
        public void Max_01123_0()
        {
            double x = 0.1123, y = 0;
            double expected = x;
            Assert.AreEqual(expected, MyCalc.Max(x, y));
        }
        [TestMethod()]
        public void Max_1111_1111()
        {
            double x = 1111, y = 1111;
            double expected = y;
            Assert.AreEqual(expected, MyCalc.Max(x, y));
        }
        [TestMethod()]
        public void Max_12345678__12412312()
        {
            double x = 12345678, y = -12412312;
            double expected = x;
            Assert.AreEqual(expected, MyCalc.Max(x, y));
        }
        [TestMethod()]
        public void Max_10_11()
        {
            int x = 10, y = 11;
            int expected = y;
            Assert.AreEqual(expected, MyCalc.Max(x, y));
        }
        [TestMethod()]
        public void Max_777_111()
        {
            int x = 777, y = 111;
            int expected = x;
            Assert.AreEqual(expected, MyCalc.Max(x, y));
        }
    }
}