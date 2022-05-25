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

     public Plane AcquirePlane()
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

     public void ReleasePlane(Plane plane)
     {
         if (!flying.Contains(plane))
         {
             throw new ArgumentException();
         }

         flying.Remove(plane);
         ready.Add(plane);
     }
}
public class Program
    {
    public static void Main()
    {

    }
}