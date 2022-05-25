// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, World!");

public interface State
{
    public void Wait();
    public void GetPin(string Pin);
    public void GetAmount(int amount);
    public void GiveMoney();
}

public class StateMachine
{
    private State current;
    public int Amount { get; set; }
    public string Pin { get; set; }

    public StateMachine()
    {
        current = new WaitForCardState(this);
    }

    public void SetState(State state)
    {
        this.current = state;
    }
}
public class WaitForCardState : State
{
    public StateMachine machine;

    public WaitForCardState(StateMachine machine)
    {
        this.machine = machine;
    }

    public void GetAmount(int amount)
    {
        throw new Exception("Give pin");
    }

    public void GetPin(string Pin)
    {
        if (machine.Pin == Pin)
        {
            machine.SetState(new WaitForAmount(machine));
        }
    }

    public void GiveMoney()
    {
        throw new Exception("Give pin");
    }

    public void Wait()
    {
        
    }
}

public class WaitForAmount : State
{
    public StateMachine machine;

    public WaitForAmount(StateMachine machine)
    {
        this.machine = machine;
    }

    public void GetAmount(int amount)
    {
        machine.Amount = amount;
        machine.SetState(new WaitForAmount(machine));
    }

    public void GetPin(string Pin)
    {

    }

    public void GiveMoney()
    {
        throw new Exception("Give amount");
    }

    public void Wait()
    {
    }
}
public class GiveMoneyState : State
{
    public StateMachine machine;

    public GiveMoneyState(StateMachine machine)
    {
        this.machine = machine;
    }

    public void GetAmount(int amount)
    {
        throw new Exception("Wait for money");
    }

    public void GetPin(string Pin)
    {
        throw new Exception("Wait for money");
    }

    public void GiveMoney()
    {
        Console.WriteLine("Wydaje " + machine.Amount +" zł");
        machine.SetState(new WaitForCardState(machine));
    }

    public void Wait()
    {
    }
}