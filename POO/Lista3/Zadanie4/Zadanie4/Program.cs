int w = 4, h = 5;
Square rect = new Rectangle() { Width = w, Height = h };
AreaCalculator calc = new AreaCalculator();
Console.WriteLine("prostokąt o wymiarach {0} na {1} ma pole {2}",
w, h, calc.CalculateArea(rect));
public class Rectangle: Square
{
    public override int Width
    {
        get { return _Width; }
        set { _Width = value; }
    }
    public override int Height
    {
        get { return _Height; }
        set { _Height = value; }
    }
}
public class Square
{
    protected int _Width;
    protected int _Height;
    public virtual int Width { get { return _Width; }  set { _Width = _Height = value; } }
    public virtual int Height { get { return _Height; } set { _Width = _Height = value; } }
}
public class AreaCalculator
{
    public int CalculateArea(Square rect)
    {
        return rect.Width * rect.Height;
    }
}
