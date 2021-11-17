// zadanie6.Pomocnicza
internal class Pomocnicza
{
    private int x = 1;

    private int y = 2;

    private int _wiek;

    private int[] tab = new int[10];

    public int Wiek
    {
        get
        {
            return _wiek;
        }
        set
        {
            _wiek = value;
        }
    }

    public int this[int index]
    {
        get
        {
            return tab[index];
        }
        set
        {
            tab[index] = value;
        }
    }

    private int add(int x, int y)
    {
        return x + y;
    }
}
