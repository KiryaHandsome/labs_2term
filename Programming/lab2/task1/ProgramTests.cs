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
        public void IsOdd_100_Test()
        {
            Assert.AreEqual(false, Program.IsOdd(100));
        }
        [TestMethod()]
        public void IsOdd_999_Test()
        {
            Assert.AreEqual(true, Program.IsOdd(999));
        }
        [TestMethod()]
        public void IsOdd_0_Test()
        {
            Assert.AreEqual(false, Program.IsOdd(0));
        }
        [TestMethod()]
        public void IsOdd_453_Test()
        {
            Assert.AreEqual(true, Program.IsOdd(453));
        }
    }
}