using Microsoft.VisualStudio.TestTools.UnitTesting;
using Lab4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4.Tests
{
    [TestClass]
    public class StationTests
    {
        [TestMethod()]
        public void CalcCostNotSaledTicketsTest12_200_100()
        {
            int saledTickets = 12;
            int seatsCount = 200;
            int costOfTicket = 100;

            Station.GetInstanceStation().SaledTicketsCount = saledTickets;
            Station.GetInstanceStation().SeatsCount = seatsCount;
            Station.GetInstanceStation().Ticket.Cost = costOfTicket;

            int expected = (seatsCount - saledTickets) * costOfTicket;

            Assert.AreEqual(expected, Station.GetInstanceStation().CalcCostNotSaledTickets());
        }
        [TestMethod()]
        public void CalcCostNotSaledTicketsTest20_120_230()
        {
            int saledTickets = 20;
            int seatsCount = 120;
            int costOfTicket = 230;

            Station.GetInstanceStation().SaledTicketsCount = saledTickets;
            Station.GetInstanceStation().SeatsCount = seatsCount;
            Station.GetInstanceStation().Ticket.Cost = costOfTicket;

            int expected = (seatsCount - saledTickets) * costOfTicket;

            Assert.AreEqual(expected, Station.GetInstanceStation().CalcCostNotSaledTickets());
        }

        [TestMethod()]
        public void CalcCostNotSaledTicketsTest44_45_100000()
        {
            int saledTickets = 44;
            int seatsCount = 45;
            int costOfTicket = 100000;

            Station.GetInstanceStation().SaledTicketsCount = saledTickets;
            Station.GetInstanceStation().SeatsCount = seatsCount;
            Station.GetInstanceStation().Ticket.Cost = costOfTicket;

            int expected = (seatsCount - saledTickets) * costOfTicket;

            Assert.AreEqual(expected, Station.GetInstanceStation().CalcCostNotSaledTickets());
        }

        [TestMethod()]
        public void ChangeCostOfTicketTest12345()
        {
            int expected = 12345;
            Station.GetInstanceStation().Ticket.Cost = expected;

            Assert.AreEqual(expected, Station.GetInstanceStation().Ticket.Cost);
        }

        [TestMethod()]
        public void ChangeCostOfTicketTest3333()
        {
            int expected = 3333;
            Station.GetInstanceStation().Ticket.Cost = expected;

            Assert.AreEqual(expected, Station.GetInstanceStation().Ticket.Cost);
        }

        [TestMethod()]
        public void ChangeCostOfTicketTest1()
        {
            int expected = 1;
            Station.GetInstanceStation().Ticket.Cost = expected;

            Assert.AreEqual(expected, Station.GetInstanceStation().Ticket.Cost);
        }


    }
}