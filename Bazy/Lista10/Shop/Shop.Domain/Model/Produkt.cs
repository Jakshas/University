using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shop.Domain.Model.Repository;

public enum Sorting // value object agregat: site
    {
        Popularity,
        PriceIncrising,
        PriceDecrising,
        NameIncrising,
        NameDecrising
    }
    public class Filters // value object agregat: site
    {
        public int pricelowest;
        public int pricehighest;
        public Filters(int pricelowest, int pricehighest)
        {
            this.pricelowest = pricelowest;
            this.pricehighest = pricehighest;
        }
    }
    public class Product // entity agregat: site root
    {
        private IProductRepository productRepository;
        string Name;
        string Description;
        double Price;
        public Product(string Name, string Description, double Price)
        {
            this.Description = Description;
            this.Price = Price;
            this.Name = Name;
        }
    }

