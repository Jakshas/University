public class User //entity identyfikator email cykl zycia utworzenie zalogownaie wylogowanie agregat: user root
{
    string Login;
    string Password;
    string Email;
    public User(string Login, string Password, string Email) {
        this.Login = Login;
        this.Email = Email;
        this.Password = Password;
    }
    public bool changePasword(string NewPassword, string OldPassword)
    {
        return true;
    }
    public bool changeEmail(string NewEmail, string OldEmail)
    {
        return true;
    }
}
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
public class Order // entity ID order crated order send order delivered agregat: order root
{
    int ID;
    User Ordering;
    List<Product> Products;
    double Price;
    Delivery delivery;
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
public class MainViewService
{
    public void returnToMain() { }
    public void goToCategory(string category) { }
    public User login(string username, string password) { return null; }
    public void logout() { }
    public void addToCart(Product p) { }
    public void goToProfile(User u) { }
    public void goToCart() { }
}

public class CategoryViewService
{
    public void returnToMain() { }
    public void goToCategory(string category) { }
    public User login(string username, string password) { return null; }
    public void logout() { }
    public void addToCart(Product p) { }
    public void selectSorting(Sorting s) { }
    public void selectFilters(Filters f) { }
    public void goToProfile(User u) { }
    public void goToCart() { }
}

public class CartViewService
{
    public void returnToMain() { }
    public void goToCategory(string category) { }
    public User login(string username, string password) { return null; }
    public void logout() { }
    public void deleteFromCart(Product p) { }
    public Order purchase(Product[] p) { return null; }
    public void goToProfile(User u) { }
    public void goToCart() { }
}

public class ProfileViewService
{
    public void returnToMain() { }
    public void goToCategory(string category) { }
    public User login(string username, string password) { return null; }
    public void logout() { }
    public void selectDelivery(Order o) { }
    public void displayOrders(User u) { }
    public void goToProfile(User u) { }
    public void goToCart() { }
}