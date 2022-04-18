using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buildings
{
    sealed public class Factory : Building
    {
        private string product;
        private int employesAmount;
        //material of factory
        private string material;

        public Factory(string product, int employesAmount, int countOfFloors, string shape) : base(countOfFloors, shape)
        {
            material = "Brick";
            this.product = product;
            this.employesAmount = employesAmount;
        }

        public int EmployesAmount
        {
            get => employesAmount;
            set => employesAmount = value;
        }


        public override string GetMaterial()
        {
            return material;
        }
        
        public void ProduceProduct()
        {
            Random rand = new Random();
            int countOfTodayProduct = rand.Next(10001);
            Console.WriteLine($"Today factory produced {countOfTodayProduct} products!");
        }

        public new void PrintAllInfo()
        {
            base.PrintAllInfo();
            Console.WriteLine($"Product = {product};\nemployesAmount = {employesAmount};\nmaterial = {material};");
        }

    }
}
