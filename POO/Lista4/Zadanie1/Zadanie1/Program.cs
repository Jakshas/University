public class Singleton
{
    private static Singleton _instance;
    private static object _lock = new object();
    Singleton() { }
    public static Singleton Instance()
    {
        lock (_lock)
        {
            if (_instance == null)
            {
                _instance = new Singleton();
            }
        }
        return _instance;
    }
}

public class ThreadSingleton
{
    [ThreadStatic] 
    static ThreadSingleton _instance;
    private static object _lock = new object();
    ThreadSingleton() { }
    public static ThreadSingleton Instance()
    {
        lock (_lock)
        {
            if (_instance == null)
            {
                _instance = new ThreadSingleton();
            }
        }
        return _instance;
    }
}

public class TimeSingleton
{
    private static TimeSingleton _instance;
    private static object _lock = new object();
    static DateTime lastUpdate;
    TimeSingleton()
    {
        lastUpdate = DateTime.Now;
    }

    public static TimeSingleton Instance()
    {
        lock (_lock)
        {
            if (_instance == null || DateTime.Now >= lastUpdate.AddSeconds(5))
            {
                _instance = new TimeSingleton();
            }
        }

        return _instance;
    }
}
public class Projekt
{
    public static void Main()
    {

    }
}