using Shop.Domain.Model.Repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


    public class Order // entity ID order crated order send order delivered agregat: order root
    {
        int ID;
        User Ordering;
        List<Product> Products;
        double Price;
        Delivery delivery;
        private IOrderRepository orders;
        public Order(User Ordering, List<Product> Products, double Price, Delivery delivery)
        {
            this.delivery = delivery;
            this.Products = Products;
            this.Ordering = Ordering;
            this.Price = Price;
        }
    }

    public class Delivery // value object agregat: order
    {
        string Type;
        double Price;
        public Delivery(string Type, double Price)
        {
            this.Type = Type;
            this.Price = Price;
        }
    }

