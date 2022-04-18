using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buildings
{
    public abstract class Building
    {
        private int countOfFloors;
        private string shape;

        public int CountOfFloors
        {
            get { return countOfFloors; }
            set { countOfFloors = value; }
        }

        public string Shape { get => shape; set => shape = value; }

        public Building(int floors = 1, string shape = "Rectangle")
        {
            countOfFloors = floors;
            this.shape = shape;
        }

        public abstract string GetMaterial();

        public virtual void GetInfoAboutBuilding()
        {
            Console.WriteLine("Is not a real building");
        }

        public void PrintAllInfo()
        {
            Console.WriteLine($"countOfFloors = {countOfFloors};\nshape = {shape};");
        }

    }
}
