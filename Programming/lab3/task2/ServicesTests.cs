using Microsoft.VisualStudio.TestTools.UnitTesting;
using task2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task2.Tests
{
    [TestClass()]
    public class ServicesTests
    {
        [TestMethod()]
        public void CalcYTest1()
        {
            double a = 123.123;
            double b = 11.11;
            double z = 1111;
            
            double expected = 48049.84372;
            Assert.AreEqual<double>(expected, Services.CalcY(a, b, z));
        }
        [TestMethod()]
        public void CalcYTest2()
        {
            double a = 1231;
            double b = 5555;
            double z = 1.123211;

            double expected = 7403972.04974;
            Assert.AreEqual<double>(expected, Services.CalcY(a, b, z));
        }
        [TestMethod()]
        public void CalcYTest3()
        {
            double a = 0;
            double b = 111;
            double z = 5775.12;

            double expected = 79.99123;
            Assert.AreEqual<double>(expected, Services.CalcY(a, b, z));
        }
    }
}