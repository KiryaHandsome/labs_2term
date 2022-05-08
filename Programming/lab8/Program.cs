using station;

Station station = new Station();


station.AddTicket(123, "Minsk");
station.AddTicket(909.155, "Grodno");
station.AddTicket(167.1121, "Minsk");
station.AddTicket(1111, "Mogilev");
station.AddTicket(455.987, "Vitebsk");
station.AddTicket(909.155, "Gomel");

IPrice obj;
obj = (IPrice)station[3];
Console.WriteLine(obj.GetPrice());

string path = station.FindPathWithMinPrice();

Console.WriteLine("Path with minimal price : " + path);

