using RationalClass;

Console.WriteLine("Hello, World!");
Rational num1 = new(142, 15);
Rational num2 = new(555, 18);
Rational num3;
try
{
    num3 = new(0, 0);
} catch (System.DivideByZeroException)
{
    Console.WriteLine("Catch exception divide by zero.");
}
Rational sum = num1 + num2;
Console.WriteLine("Result of sum " + num1.ToString() + " and " + num2.ToString() + " : " + sum.ToString());

Rational sum2 = num1 + 17;
Console.WriteLine("Result of sum " + num1.ToString() + " and  17 : " + sum2.ToString());

Rational multiply = num1 * num2;
Console.WriteLine("Result of multiply " + num1.ToString() + " and "  + num2.ToString() + " : " + multiply.ToString());

Rational multiply2 = num1 * 4;
Console.WriteLine("Result of multiply " + num1.ToString() + " and  4 : " + multiply2.ToString());

Rational div = num1 / num2;
Console.WriteLine("Result of division " + num1.ToString() + " by " + num2.ToString() + " :" + div.ToString());

Rational div2 = num1 / 2;
Console.WriteLine("Result of division " + num1.ToString() + " by 2 : " + div2.ToString());

Rational sub = num1 - num2;
Console.WriteLine("Result of substraction " + num1.ToString() + " and " + num2.ToString() + " : " + sub.ToString());

Rational sub2 = num1 - 17;
Console.WriteLine("Result of substraction " + num1.ToString() + " and  17 : " + sub2.ToString());

string temp = multiply.ToString();
multiply.Normalization();
Console.WriteLine("Result of normalization before : " + temp + " after: " + multiply.ToString());

Console.WriteLine("Greatest divisor between 1188 and 6142: " + Rational.GreatestDivisor(1188, 6142));

Console.WriteLine("Operator == : " + num1.ToString() + (num1 == num2 ? " == " : " != ") + num2.ToString());

Console.WriteLine("Operator > : " + num1.ToString() + (num1 > num2 ? " > " : " <= ") + num2.ToString());


int a = (int)num1;
Console.WriteLine("Explicit cast to int " + num1.ToString() + " = " +  Convert.ToString(a));

Rational q = a;
Console.WriteLine("Implicit cast to rational " + Convert.ToString(a) + " = " + q.ToString());