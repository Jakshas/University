namespace Notify
{
    public abstract class PersonNotify
    {
        public abstract void NotifyPersons(List<Person> l);
    }
    public class SMSPersonNotify: PersonNotify
    {
        public override void NotifyPersons(List<Person> l)
        {
            foreach (Person person in l)
                Console.WriteLine("SMS "+person);
        }
    }
    public class MailPersonNotify : PersonNotify
    {
        public override void NotifyPersons(List<Person> l)
        {
            foreach (Person person in l)
                Console.WriteLine("Mail " + person);
        }
    }
    public abstract class PersonRegistry
    {
        PersonNotify noti;
        public PersonRegistry(PersonNotify notify)
        {
            noti = notify;
        }
        
        public abstract List<Person> GetPersons();
        public void NotifyPersons(List<Person> l)
        {
            noti.NotifyPersons(l);
        }
    }
    public abstract class XMLPersonRegistry:PersonRegistry
    {
        public List<Person> _persons = new List<Person>();
        public XMLPersonRegistry(PersonNotify notify):base(notify)
        {

        }
        public override List<Person> GetPersons()
        {
            return _persons;
        }
    }
    public abstract class DBPersonRegistry : PersonRegistry
    {
        public List<Person> _persons = new List<Person>();
        public DBPersonRegistry(PersonNotify notify) : base(notify)
        {

        }
        public override List<Person> GetPersons()
        {
            return _persons;
        }
    }
    public class Person { }
}
namespace Registry
{
    public abstract class PersonRegistry
    {
        public abstract List<Person> GetPersons();

    }
    public abstract class XMLPersonRegistry : PersonRegistry
    {
        public List<Person> _persons = new List<Person>();
        public override List<Person> GetPersons()
        {
            return _persons;
        }
    }
    public abstract class DBPersonRegistry : PersonRegistry
    {
        public List<Person> _persons = new List<Person>();
        public override List<Person> GetPersons()
        {
            return _persons;
        }
    }
    public abstract class PersonNotify
    {
        PersonRegistry _personRegistry;
        public abstract void NotifyPersons(List<Person> l);
        public PersonNotify(PersonRegistry registry)
        {
            this._personRegistry = registry;
        }
        public List<Person> GetPersons() 
        { 
            return this._personRegistry.GetPersons(); 
        }
    }
    public class SMSPersonNotify : PersonNotify
    {
        public SMSPersonNotify(PersonRegistry registry) : base(registry)
        {
        }

        public override void NotifyPersons(List<Person> l)
        {
            foreach (Person person in l)
                Console.WriteLine("SMS " + person);
        }
    }
    public class MailPersonNotify : PersonNotify
    {
        public MailPersonNotify(PersonRegistry registry) : base(registry)
        {
        }

        public override void NotifyPersons(List<Person> l)
        {
            foreach (Person person in l)
                Console.WriteLine("Mail " + person);
        }
    }
    public class Person { }
}