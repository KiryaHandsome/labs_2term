using Microsoft.VisualStudio.TestTools.UnitTesting;
using Buildings;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buildings.Tests
{
    [TestClass()]
    public class FactoryTests
    {
        [TestMethod()]
        public void EmployesAmountProperty1000Test()
        {
            Factory factory = new Factory("Pizza", 1000, 40, "Rectangle");
            int expected = 1000;
            Assert.AreEqual(expected, factory.EmployesAmount);
        }

        [TestMethod()]
        public void EmployesAmountProperty1Test()
        {
            Factory factory = new Factory("Pizza", 1, 40, "Rectangle");
            int expected = 1;
            Assert.AreEqual(expected, factory.EmployesAmount);
        }

        [TestMethod()]
        public void EmployesAmountProperty99Test()
        {
            Factory factory = new Factory("Pizza", 99, 40, "Rectangle");
            int expected = 99;
            Assert.AreEqual(expected, factory.EmployesAmount);
        }

        [TestMethod()]
        public void GetMaterialTest()
        {
            Factory factory = new Factory("Pizza", 99, 40, "Rectangle");
            string expected = "Brick";
            Assert.AreEqual(expected, factory.GetMaterial());
        }

        [TestMethod()]
        public void ShapeRectangleTest()
        {
            Factory factory = new Factory("Pizza", 99, 40, "Rectangle");
            string expected = "Rectangle";
            Assert.AreEqual(expected, factory.Shape);
        }

        [TestMethod()]
        public void ShapeCircleTest()
        {
            Factory factory = new Factory("Pizza", 99, 40, "Circle");
            string expected = "Circle";
            Assert.AreEqual(expected, factory.Shape);
        }

        [TestMethod()]
        public void ShapeRhombTest()
        {
            Factory factory = new Factory("Pizza", 99, 40, "Rhomb");
            string expected = "Rhomb";
            Assert.AreEqual(expected, factory.Shape);
        }
    }
}