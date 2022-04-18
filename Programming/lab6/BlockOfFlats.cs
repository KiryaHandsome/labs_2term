using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buildings
{
    public class BlockOfFlats : Building
    {
        private int numberOfFlats;
        private double debtForElectricity;
        private string material;

        public int NumberOfFlats
        {
            get => numberOfFlats;
            set => numberOfFlats = value;
        }

        public BlockOfFlats(int numOfFlats, int floors, string shape) : base(floors, shape)
        {
            this.material = "Foam Block";
            debtForElectricity = 100;
            this.numberOfFlats = numOfFlats;
        }

        public override string GetMaterial()
        {
            return material;
        }


        public double GetDebtForElectricity()
        {
            return debtForElectricity;
        }
        public void PayForElectricity(double sum)
        {
            if(debtForElectricity == 0)
            {
                Console.WriteLine("You have no debt for electricity");
            }
            else
            {
                debtForElectricity -= sum;
                if(debtForElectricity <= 0)
                {
                    Console.WriteLine("You pay for electricity. Thank you.");
                }
                else
                {
                    Console.WriteLine($"You has to pay for electricity another {debtForElectricity}.");
                }
            }
        }

        public override void GetInfoAboutBuilding()
        {
            Console.WriteLine($"Is a block of flats with {CountOfFloors} floors and {numberOfFlats} flats.");
        }
    }
}
