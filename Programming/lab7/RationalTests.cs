using Microsoft.VisualStudio.TestTools.UnitTesting;
using RationalClass;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RationalClass.Tests
{
    [TestClass()]
    public class RationalTests
    {
        [TestMethod()]
        public void RationalDenominator123123Test()
        {
            Rational rational = new Rational(0, 123123);
            int expected = 123123;
            Assert.AreEqual(expected, rational.Denominator);
        }

        [TestMethod()]
        public void RationalDenominator_99999Test()
        {
            Rational rational = new Rational(0, -99999);
            int expected = -99999;
            Assert.AreEqual(expected, rational.Denominator);
        }

        [TestMethod()]
        public void RationalDenominator0Test()
        {
            bool was_catched = false;
            bool expected = true;
            try
            {
                Rational rational = new Rational(0, 0);
            }
            catch (System.DivideByZeroException ex)
            {
                was_catched = true;
            }
            Assert.AreEqual(expected, was_catched);
        }

        [TestMethod()]
        public void ToString145_16Test()
        {
            Rational rational = new Rational(145, 16);
            string expected = "145 / 16";
            Assert.AreEqual(expected, rational.ToString());
        }

        [TestMethod()]
        public void ToStringTest999999__123123213()
        {
            Rational rational = new Rational(999999, -123123213);
            string expected = "-999999 / 123123213";
            Assert.AreEqual(expected, rational.ToString());
        }

        [TestMethod()]
        public void NormalizationTest15_15()
        {
            Rational rational = new(15, 15);
            rational.Normalization();
            bool res = rational == new Rational(1, 1);
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void NormalizationTest200_20()
        {
            Rational rational = new(200, 20);
            rational.Normalization();
            bool res = rational == new Rational(10, 1);
            Assert.AreEqual(true, res);
        }


        [TestMethod()]
        public void ToStringTest_123231__727272()
        {
            Rational rational = new Rational(-123231, -727272);
            string expected = "123231 / 727272";
            Assert.AreEqual(expected, rational.ToString());
        }


        [TestMethod()]
        public void NormalizationTest9999_2()
        {
            Rational rational = new(9999, 2);
            rational.Normalization();
            bool res = rational == new Rational(9999, 2);
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void NormalizationTest_456_456()
        {
            Rational rational = new(-456, 228);
            rational.Normalization();
            bool res = rational == new Rational(-2, 1);
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void GreatestDivisor19_7Test()
        {
            int a = 19;
            int b = 7;
            int expected = 1;
            Assert.AreEqual(expected, Rational.GreatestDivisor(a, b));
        }

        [TestMethod()]
        public void LeastCommonMultipleTest18_45()
        {
            int a = 18, b = 45;
            int expected = 90;
            Assert.AreEqual(expected, Rational.LeastCommonMultiple(a, b));
        }

        [TestMethod()]
        public void RationalNumeratorTest123_999()
        {
            Rational rational = new(123, 999);
            int expected = 123;
            Assert.AreEqual(expected, rational.Numerator);
        }

        [TestMethod()]
        public void RationalNumeratorTest0_999()
        {
            Rational rational = new(0, 999);
            int expected = 0;
            Assert.AreEqual(expected, rational.Numerator);
        }

        [TestMethod()]
        public void RationalNumeratorTest_123132_999()
        {
            Rational rational = new(-123132, 999);
            int expected = -123132;
            Assert.AreEqual(expected, rational.Numerator);
        }

        [TestMethod()]
        public void RationalNumeratorTest_123132__999()
        {
            Rational rational = new(-123132, -999);
            int expected = 123132;
            Assert.AreEqual(expected, rational.Numerator);
        }

        [TestMethod()]
        public void RationalNumeratorTestDefaultConstructor()
        {
            Rational rational = new Rational();
            int expected = 0;
            Assert.AreEqual(expected, rational.Numerator);
        }

        [TestMethod()]
        public void LeastCommonMultipleTest555_4441()
        {
            int a = 555, b = 4441;
            int expected = 2464755;
            Assert.AreEqual(expected, Rational.LeastCommonMultiple(a, b));
        }

        [TestMethod()]
        public void GreatestDivisorTest18_6()
        {
            int a = 18;
            int b = 6;
            int expected = 6;
            Assert.AreEqual(expected, Rational.GreatestDivisor(a, b));
        }

        [TestMethod()]
        public void GreatestDivisorTest_190_5()
        {
            int a = -190;
            int b = 35;
            int expected = 5;
            Assert.AreEqual(expected, Rational.GreatestDivisor(a, b));
        }

        [TestMethod()]
        public void GreatestDivisorTest7271814_5613()
        {
            int a = 7271814;
            int b = 5613;
            int expected = 3;
            Assert.AreEqual(expected, Rational.GreatestDivisor(a, b));
        }

        [TestMethod()]
        public void LeastCommonMultipleTest2_8()
        {
            int a = 2, b = 8;
            int expected = 8;
            Assert.AreEqual(expected, Rational.LeastCommonMultiple(a, b));
        }

        [TestMethod()]
        public void Operator_plus111_222_222_111Test()
        {
            Rational r = new(111, 222);
            Rational l = new(222, 111);
            Rational expected = new(555, 222);
            Rational actual = r + l;
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_plus12_15_18_15Test()
        {
            Rational r = new(12, 15);
            Rational l = new(18, 15);
            Rational expected = new(30, 15);
            Rational actual = r + l;
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_plus_1_12__566_12Test()
        {

            Rational r = new(-1, 12);
            Rational l = new(-566, 12);
            Rational expected = new(-567, 12);
            Rational actual = r + l;
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_plus_int12_15_19Test()
        {
            Rational r = new(12, 15);
            int l = 19;
            Rational expected = new(297, 15);
            Rational actual = r + l;
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_plus_int199_11_33Test()
        {
            Rational r = new(199, 11);
            int l = 33;
            Rational expected = new(562, 11);
            Rational actual = r + l;
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_plus_int123_99990_0Test()
        {
            Rational r = new(123, 99990);
            int l = 0;
            Rational expected = new(123, 99990);
            Rational actual = r + l;
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_plus0_15_15Test()
        {
            Rational r = new(0, 15);
            int l = 15;
            Rational expected = new(225, 15);
            Rational actual = r + l;
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_minus15_15_8_15Test()
        {
            Rational r = new(15, 15);
            Rational l = new(9, 15);
            Rational actual = r - l;
            Rational expected = new(6, 15);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_minus253_4_78_2Test()
        {
            Rational r = new(253, 4);
            Rational l = new(78, 2);
            Rational actual = r - l;
            Rational expected = new(97, 4);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_minus0_15_190_123Test()
        {
            Rational r = new(0, 15);
            Rational l = new(190, 123);
            Rational actual = r - l;
            Rational expected = new(-190, 123);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_minus_int_15_190_1Test()
        {
            Rational r = new(15, 190);
            int l = 1;
            Rational actual = r - l;
            Rational expected = new(-175, 190);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_minus_int_111_10_10Test()
        {
            Rational r = new(111, 10);
            int l = 10;
            Rational actual = r - l;
            Rational expected = new(11, 10);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_minus_int_155_2_2132Test()
        {
            Rational r = new(155, 2);
            int l = 2132;
            Rational actual = r - l;
            Rational expected = new(-4109, 2);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_mult_111_123_1_1Test()
        {
            Rational r = new(111, 123);
            Rational l = new(1, 1);
            Rational actual = r * l;
            Rational expected = new(111, 123);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_mult_55_123_123_2Test()
        {
            Rational r = new(55, 123);
            Rational l = new(123, 2);
            Rational actual = r * l;
            Rational expected = new(6765, 246);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_mult_4_2_5_8Test()
        {
            Rational r = new(4, 2);
            Rational l = new(5, 8);
            Rational actual = r * l;
            Rational expected = new(20, 16);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_mult_int_4_2_3Test()
        {
            Rational r = new(4, 2);
            int l = 3;
            Rational actual = r * l;
            Rational expected = new(12, 2);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_mult_int_10_17_43Test()
        {
            Rational r = new(10, 17);
            int l = 43;
            Rational actual = r * l;
            Rational expected = new(430, 17);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_div_1_2_3_4_Test()
        {
            Rational r = new(1, 2);
            Rational l = new(3, 4);
            Rational actual = r / l;
            Rational expected = new(4, 6);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_div_100_17_5534_17_Test()
        {
            Rational r = new(100, 17);
            Rational l = new(5534, 17);
            Rational actual = r / l;
            Rational expected = new(1700, 94078);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_div_int_100_17_2Test()
        {
            Rational r = new(100, 17);
            int l = 2;
            Rational actual = r / l;
            Rational expected = new(100, 34);
            bool res = actual == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_explicit_conv_to_int_15_4()
        {
            Rational r = new(15, 4);
            int expected = 3;
            int res = (int)r;
            Assert.AreEqual(res, expected);
        }

        [TestMethod()]
        public void Operator_explicit_conv_to_int_180_90()
        {
            Rational r = new(180, 90);
            int expected = 2;
            int res = (int)r;
            Assert.AreEqual(res, expected);
        }

        [TestMethod()]
        public void Operator_explicit_conv_to_int_56_3()
        {
            Rational r = new(56, 3);
            int expected = 18;
            int res = (int)r;
            Assert.AreEqual(res, expected);
        }

        [TestMethod()]
        public void Operator_implicit_conv_to_rational_18()
        {
            int r = 18;
            Rational expected = new(18, 1);
            Rational tmp = r;
            bool res = tmp == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_implicit_conv_to_rational_19123()
        {
            int r = 19123;
            Rational expected = new(19123, 1);
            Rational tmp = r;
            bool res = tmp == expected;
            Assert.AreEqual(true, res);
        }

        [TestMethod()]
        public void Operator_15_5_greater_16_1()
        {
            Rational l = new(15, 5);
            Rational r = new(16, 1);
            bool expected = false;
            Assert.AreEqual(expected, l > r);
        }

        [TestMethod()]
        public void Operator_15_1_less_16_1()
        {
            Rational l = new(15, 1);
            Rational r = new(16, 1);
            bool expected = true;
            Assert.AreEqual(expected, l < r);
        }
    }

    
    
}