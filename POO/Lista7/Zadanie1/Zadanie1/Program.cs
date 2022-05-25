namespace Zadanie1
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());
        }
    }
        public class Student
        {
            public string imie;
            public string nazwisko;
            public string data;
            public string adres;
            public Student(string imie, string nazwisko, string data, string adres)
            {
                this.imie = imie;
                this.nazwisko = nazwisko;
                this.data = data;
                this.adres = adres;
            }
        }
        public class Wykladowca
        {
            public string imie;
            public string nazwisko;
            public string data;
            public string adres;
            public Wykladowca(string imie, string nazwisko, string data, string adres)
            {
                this.imie = imie;
                this.nazwisko = nazwisko;
                this.data = data;
                this.adres = adres;
            }
        }
    public class CategorySelectedNotification
    {
        public string TypeOfSelected;
        public CategorySelectedNotification(string TypeOfSelected)
        {
            this.TypeOfSelected = TypeOfSelected;
        }
    }
    public class UserProfileSelectedNotification
    {
        public string nameSelected;
        public string surnameSelected;
        public UserProfileSelectedNotification(string nameSelected , string surnameSelected)
        {
            this.nameSelected = nameSelected;
            this.surnameSelected = surnameSelected;
        }
    }
    public class ModifyRecordNotification
    {
        public bool deleting;
        public string ile;
        public string na_co;
        public bool czy_zap³acone;
        public int index;
        public ModifyRecordNotification(bool deleting, string ile, string na_co, bool czy_zap³acone, int index)
        {
            this.deleting = deleting;
            this.ile = ile;
            this.czy_zap³acone = czy_zap³acone;
            this.na_co = na_co;
            this.index = index;
        }
    }
    public class UserProfileAddedNotification
    {
        public string name;
        public string surname;
        public string date;
        public string adress;
        public bool student;
        public UserProfileAddedNotification(string name, string surname, string date, string adress, bool student)
        {
            this.name = name;
            this.surname = surname;
            this.date = date;
            this.adress = adress;
            this.student = student;
        }
    }
    public interface ISubscriber<T>
        {
            public void Handle(T Notification);
        }
        public interface IEventAggregator
        {
            void AddSubscriber<T>(ISubscriber<T> Subscriber);
            void RemoveSubscriber<T>(ISubscriber<T> Subscriber);
            void Publish<T>(T Event);
        }
        public class EventAggregator : IEventAggregator
        {
            Dictionary<Type, List<object>> _subscribers = new Dictionary<Type, List<object>>();
            public void AddSubscriber<T>(ISubscriber<T> Subscriber)
            {
                if (!_subscribers.ContainsKey(typeof(T)))
                    _subscribers.Add(typeof(T), new List<object>());
                _subscribers[typeof(T)].Add(Subscriber);
            }
            public void RemoveSubscriber<T>(ISubscriber<T> Subscriber)
            {
                if (_subscribers.ContainsKey(typeof(T)))
                    _subscribers[typeof(T)].Remove(Subscriber);
            }
            public void Publish<T>(T Event)
            {
                if (_subscribers.ContainsKey(typeof(T)))
                    foreach (ISubscriber<T> subscriber in
                    _subscribers[typeof(T)].OfType<ISubscriber<T>>())
                        subscriber.Handle(Event);

            }
        }
    }
public class WpisWKartotece
{
    public int ile;
    public string na_co;
    public bool czy_zaplacone;
    public WpisWKartotece(int ile, string na_co, bool czy_zaplacone)
    {
        this.ile = ile;
        this.na_co = na_co;
        this.czy_zaplacone = czy_zaplacone;
    }
}