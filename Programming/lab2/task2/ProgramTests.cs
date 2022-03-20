using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tests
{
    [TestClass()]
    public class ProgramTests
    {
        [TestMethod()]
        public void LocationOfPoint_12_5_Test()
        {
            int expected = -1;

            Assert.AreEqual(expected, Program.LocationOfPoint(12, 5));
        }
        [TestMethod()]
        public void LocationOfPoint_0_0_Test()
        {
            int expected = 0;

            Assert.AreEqual(expected, Program.LocationOfPoint(0, 0));
        }
        [TestMethod()]
        public void LocationOfPoint_3_0_Test()
        {
            int expected = 0;

            Assert.AreEqual(expected, Program.LocationOfPoint(3, 0));
        }
        [TestMethod()]
        public void LocationOfPoint_0_1_Test()
        {
            int expected = 1;

            Assert.AreEqual(expected, Program.LocationOfPoint(0, 1));
        }
        [TestMethod()]
        public void LocationOfPoint__1_2_Test()
        {
            int expected = 1;

            Assert.AreEqual(expected, Program.LocationOfPoint(-1, 2));
        }
        [TestMethod()]
        public void LocationOfPoint__12__3_Test()
        {
            int expected = -1;

            Assert.AreEqual(expected, Program.LocationOfPoint(-12, -3));
        }
    }
}