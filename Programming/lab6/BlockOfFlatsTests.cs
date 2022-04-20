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
    public class BlockOfFlatsTests
    {
        [TestMethod()]
        public void GetMaterialTest()
        {
            BlockOfFlats block = new BlockOfFlats(1, 1, "rect");
            string expected = "Foam Block";
            Assert.AreEqual(expected, block.GetMaterial());
        }

        [TestMethod()]
        public void NumOfFlatsProperty_100_Test()
        {
            BlockOfFlats block = new BlockOfFlats(100, 9, "shape");
            int expected = 100;
            Assert.AreEqual(expected, block.NumberOfFlats);
        }

        [TestMethod()]
        public void GetDebtForElectricityStartTest()
        {
            BlockOfFlats block = new BlockOfFlats(0, 0, "shape");
            int expected = 100;
            Assert.AreEqual(expected, block.GetDebtForElectricity());
        }

        [TestMethod()]
        public void GetDebtForElectricityPay50Test()
        {
            BlockOfFlats block = new BlockOfFlats(0, 0, "shape");
            int expected = 50;
            block.PayForElectricity(50);
            Assert.AreEqual(expected, block.GetDebtForElectricity());
        }

        public void GetDebtForElectricityPay150Test()
        {
            BlockOfFlats block = new BlockOfFlats(0, 0, "shape");
            int expected = -50;
            block.PayForElectricity(150);
            Assert.AreEqual(expected, block.GetDebtForElectricity());
        }

        [TestMethod()]
        public void PayForElectricity30Test()
        {
            BlockOfFlats block = new BlockOfFlats(0, 0, "shape");
            int expected = 70;
            block.PayForElectricity(30);
            Assert.AreEqual(expected, block.GetDebtForElectricity());
        }

        [TestMethod()]
        public void ShapeRectangleTest()
        {
            BlockOfFlats block = new BlockOfFlats(0, 0, "Rectangle");
            string expected = "Rectangle";
            Assert.AreEqual(expected, block.Shape);
        }

        [TestMethod()]
        public void ShapeCircleTest()
        {
            BlockOfFlats block = new BlockOfFlats(0, 0, "Circle");
            string expected = "Circle";
            Assert.AreEqual(expected, block.Shape);
        }

        [TestMethod()]
        public void ShapeRhombTest()
        {
            BlockOfFlats block = new BlockOfFlats(0, 0, "Rhomb");
            string expected = "Rhomb";
            Assert.AreEqual(expected, block.Shape);
        }
    }
}