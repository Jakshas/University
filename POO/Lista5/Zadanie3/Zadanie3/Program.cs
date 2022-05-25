using System;
using System.Collections.Generic;
using System.Linq;


public class Plane
{
}
public class Airport
{
    private int capacity;

    private List<Plane> ready = new List<Plane>();
    private List<Plane> flying = new List<Plane>();

    public Airport(int capacity)
    {
        if (capacity <= 0)
        {
            throw new ArgumentException();
        }

        this.capacity = capacity;
    }

    public virtual Plane AcquirePlane()
    {
        if (flying.Count == capacity)
        {
            throw new ArgumentException();
        }

        if (ready.Count() == 0)
        {
            ready.Add(new Plane());
        }

        var plane = ready[0];
        ready.Remove(plane);
        flying.Add(plane);

        return plane;
    }

    public virtual void ReleasePlane(Plane plane)
    {
        if (!flying.Contains(plane))
        {
            throw new ArgumentException();
        }

        flying.Remove(plane);
        ready.Add(plane);
    }
}

public class AirportProxy1 : Airport
{
    Airport _airport;
    public AirportProxy1(int capacity) : base(capacity)
    {
        _airport = new Airport(capacity);
    }

    public override Plane AcquirePlane()
    {
        if (!IsOpen())
        {
            throw new InvalidOperationException();
        }

        return this._airport.AcquirePlane();
    }

    public override void ReleasePlane(Plane plane)
    {
        if (!IsOpen())
        {
            throw new InvalidOperationException();
        }

        this._airport.ReleasePlane(plane);
    }
    private bool IsOpen()
    {
        var time = DateTime.Now;

        return (time.Hour >= 8 && time.Minute >= 0) &&
               (time.Hour < 22 || (time.Hour == 22 && time.Minute == 0));
    }
}
public class AirportProxy2 : Airport
{
    Airport _airport;
    public AirportProxy2(int capacity) : base(capacity)
    {
        _airport = new Airport(capacity);
    }

    public override Plane AcquirePlane()
    {
        
        LogCall("AcquirePlane", null);
        Plane plane = this._airport.AcquirePlane();
        LogReturn(plane);
        return plane;
    }

    public override void ReleasePlane(Plane plane)
    {
        LogCall("ReleasePlane", plane);
        this._airport.ReleasePlane(plane);
        LogReturn(null);
    }
    private void LogCall(string metodName, Plane parameters)
    {
        Console.WriteLine(DateTime.Now + "|" + metodName + "|" + parameters);
    }
    private void LogReturn(Plane returnval)
    {
        Console.WriteLine(DateTime.Now + "|" + returnval);
    }
}
public class Program
{
    public static void Main()
    {
        AirportProxy2 p = new AirportProxy2(10);
        Plane pl = p.AcquirePlane();
        p.ReleasePlane(pl);
    }
}