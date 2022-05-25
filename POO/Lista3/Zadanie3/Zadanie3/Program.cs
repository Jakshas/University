namespace before
{
    public class TaxCalculator
    {
        public Decimal CalculateTax(Decimal Price) { return Price * new Decimal(0.22); }
    }
    public class Item
    {
        public Decimal Price { get; }
        public string Name { get; }
    }
    public class CashRegister
    {
        public TaxCalculator taxCalc = new TaxCalculator();
        public Decimal CalculatePrice(Item[] Items)
        {
            Decimal _price = 0;
            foreach (Item item in Items)
            {
                _price += item.Price + taxCalc.CalculateTax(item.Price);
            }
            return _price;
        }
        public void PrintBill(Item[] Items)
        {
            foreach (var item in Items)
                Console.WriteLine("towar {0} : cena {1} + podatek {2}",
                item.Name, item.Price, taxCalc.CalculateTax(item.Price));
        }
    }
}
    namespace after
{
    public abstract class TaxCalculator
    {
        public Func<Decimal, Decimal> calculate;
        public Decimal CalculateTax(Decimal Price) { return calculate(Price); }
    }
    public class Item
    {
        public Decimal Price { get; }
        public string Name { get; }
    }

    public class OrderModifier
    {
        public Func<Item[], Item[]> modifier;
        public Item[] ModifyOrder(Item[] list) { return modifier(list); }
    }

    public class CashRegister
    {
        TaxCalculator taxCalc { get; set; }
        OrderModifier modifier { get; set; }

        public Decimal CalculatePrice(Item[] Items)
        {
            Decimal _price = 0;
            foreach (Item item in Items)
            {
                _price += item.Price + taxCalc.CalculateTax(item.Price);
            }
            return _price;
        }
        public void PrintBill(Item[] Items)
        {
            foreach (var item in modifier.ModifyOrder(Items))
                Console.WriteLine("towar {0} : cena {1} + podatek {2}",
                item.Name, item.Price, taxCalc.CalculateTax(item.Price));
        }
    }
}