public class User{

}
public class Sorting
{

}
public class Filters
{

}
public class Product
{

}
public class Order
{

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