using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task3
{
    public static class DateService
    {
        public static int GetDayOfWeek(string date)
        {
            DateTime dt = DateTime.Parse(date);
            return Convert.ToInt32(dt.DayOfWeek);
        }
        public static string ToString(int day)
        {
            string[] DaysOfWeek = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
            return DaysOfWeek[day - 1];
        }
        public static int GetDaysSpan(int day, int month, int year)
        {
            DateTime currentDate = DateTime.Now;
            DateTime secondDate = new DateTime(year, month, day);
            return Math.Abs((int)(currentDate - secondDate).TotalDays);
        }
    }
}
