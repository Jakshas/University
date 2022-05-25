public interface IShapeFactoryWorker
{
    bool AcceptsParameters(string name, object[] parameters);

    IShape Create(object[] parameters);
}

public interface IShape
{
    double GetArea();
}

public class Square : IShape
{
    public double Side { get; set; }
    public double GetArea()
    {
        return Side * Side;
    }

}

public class CircleFactoryWorker : IShapeFactoryWorker
{
    public bool AcceptsParameters(string name, object[] parameters)
    {
        return name == "Square"
            && parameters.Length == 1;
    }

    public IShape Create(object[] parameters)
    {
        return new Square { Side = (double)parameters[0] };
    }

}

public class Rectangle : IShape
{
    public double Width { get; set; }
    public double Height { get; set; }

    public double GetArea()
    {
        return Width * Height;
    }
}

public class RectangleFactoryWorker : IShapeFactoryWorker
{
    public bool AcceptsParameters(string name, object[] parameters)
    {
        return name == "Rectangle"
            && parameters.Length == 2
            && parameters[0] is double
            && parameters[1] is double;
    }

    public IShape Create(object[] parameters)
    {
        return new Rectangle
        {
            Width = (double)parameters[0],
            Height = (double)parameters[1]
        };
    }
}

public class ShapeFactory
{
    List<IShapeFactoryWorker> workers = new List<IShapeFactoryWorker>();

    public ShapeFactory()
    {
        this.RegisterWorker(new CircleFactoryWorker());
        this.RegisterWorker(new RectangleFactoryWorker());
    }

    public void RegisterWorker(IShapeFactoryWorker worker)
    {
        this.workers.Add(worker);
    }

    public IShape CreateShape(string name, params object[] parameters)
    {
        foreach (var worker in workers)
        {
            if (worker.AcceptsParameters(name, parameters))
            {
                return worker.Create(parameters);
            }
        }

        throw new ArgumentException("Unrecognized shape name " + name);
    }
}

