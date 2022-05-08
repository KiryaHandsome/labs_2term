using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RationalClass
{
    public class Rational
    {
        private int numerator;
        private int denominator;

        public int Numerator
        {
            get { return numerator; }
            set
            {
                numerator = value;
            }
        }
        public int Denominator
        {
            get { return denominator; }
            set
            {
                if (denominator == 0)
                {
                    throw new System.DivideByZeroException();
                }
                denominator = value;
            }
        }

        public Rational(int numerator, int denominator)
        {
            this.numerator = numerator;
            if (denominator == 0)
            {
                throw new System.DivideByZeroException();
            }
            this.denominator = denominator;
            CheckSign();
        }

        public Rational()
        {
            this.numerator = 0;
            this.denominator = 1;
        }

        public override string ToString()  
        {
            return Convert.ToString(numerator) + " / " + Convert.ToString(denominator);
        }

        public static string ToString(Rational num)
        {
            return Convert.ToString(num.numerator) + " / " + Convert.ToString(num.denominator);
        }

        public void Normalization()
        {
            int divisor = GreatestDivisor(numerator, denominator);
            numerator /= divisor;
            denominator /= divisor;
        }

        public static Rational Normalization(Rational num)
        {
            int divisor = GreatestDivisor(num.numerator, num.denominator);
            num.numerator /= divisor;
            num.denominator /= divisor;
            return num;
        }

        public static int GreatestDivisor(int a, int b)
        {
            int max = Math.Abs(a > b ? a : b), min = Math.Abs(a > b ? b : a);
            if(min == 0)
            {
                return max;
            }
            else
            {
                return GreatestDivisor(min, max % min);
            }
        }

        public static int LeastCommonMultiple(int a, int b)
        {
            return Math.Abs(a * b) / GreatestDivisor(a, b);
        }

        public static Rational operator + (Rational left, Rational right)
        {
            int new_denominator = LeastCommonMultiple(left.denominator, right.denominator);
            int new_numerator = left.numerator * (new_denominator / left.denominator) + right.numerator * (new_denominator / right.denominator);
            return new(new_numerator, new_denominator);
        }

        public static Rational operator + (Rational left, int right)
        {
            int new_numerator = left.numerator + right * left.denominator;
            Rational rational = new(new_numerator, left.denominator);
            rational.CheckSign();
            return rational;
        }

        public static Rational operator - (Rational left, Rational right)
        {
            int new_denominator = LeastCommonMultiple(left.denominator, right.denominator);
            int new_numerator = left.numerator * (new_denominator / left.denominator)  - right.numerator * (new_denominator / right.denominator);
            return new(new_numerator, new_denominator);
        }

        public static Rational operator - (Rational left, int right)
        {
            int new_numerator = left.numerator - right * left.denominator;
            Rational rational = new(new_numerator, left.denominator);
            rational.CheckSign();
            return rational;
        }

        public static Rational operator * (Rational left, Rational right)
        {
            int new_numerator = left.numerator * right.numerator;
            int new_denominator = left.denominator * right.denominator;
            return new(new_numerator, new_denominator);
        }

        public static Rational operator * (Rational left, int right)
        {
            return new(left.numerator * right, left.denominator);
        }


        public static Rational operator / (Rational left, Rational right)
        {
            Rational flip_right = new (right.denominator, right.numerator);
            return left * flip_right;
        }

        public static Rational operator / (Rational left, int right)
        {
            Rational flip_right = new(1, right);
            return left * flip_right;
        }

        public static bool operator !=(Rational left, Rational right)
        {
            if (left == right)
            {
                return false;
            }
            return true;
        }

        public static bool operator ==(Rational left, Rational right)
        {
            left.Normalization();
            right.Normalization();
            if(left.numerator == right.numerator && left.denominator == right.denominator)
            {
                return true;
            }
            return false;
        }

        private void CheckSign()
        {
            if (numerator < 0 && denominator < 0 || denominator < 0 && numerator > 0)
            {
                numerator = -numerator;
                denominator = -denominator;
            }
        }

        public static bool operator > (Rational l, Rational r)
        {
            l *= r.Denominator;
            r *= l.Denominator;
            if (l.numerator > r.numerator) return true;
            return false;
        }

        public static bool operator <(Rational l, Rational r)
        {
            if(l > r) return false;
            return true;
        }

        public static explicit operator int(Rational num)
        {
            return num.numerator / num.Denominator;
        }

        public static implicit operator Rational(int num)
        {
            return new Rational(num, 1);
        }

        public static implicit operator bool(Rational num)
        {
            return num.numerator == 0;
        }

    }


}
