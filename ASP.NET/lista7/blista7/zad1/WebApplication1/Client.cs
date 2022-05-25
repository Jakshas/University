using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Web;

class Program
{
    static HttpClient client = new HttpClient();
    static Program()
    {
        client.DefaultRequestHeaders.Accept.Add(new System.Net.Http.Headers.MediaTypeWithQualityHeaderValue("application/json"));
    }
    static void Main(string[] args)
    {
        _ = Get();
        _ = Post();
        Console.ReadLine();
    }
    async static Task Get()
    {
        var responseString = await client.GetStringAsync("http://localhost:44357/api/Home");
        var response = JsonConvert.DeserializeObject<IEnumerable<Person>>(responseString);
        foreach (var person in response)
        {
            Console.WriteLine(string.Format("{0} {1}", person.ID, person.Name));
        }
    }
    async static Task Post()
    {
        var person = new Person() { ID = 188, Name = "ghj" };
        var request = JsonConvert.SerializeObject(person);
        StringContent content = new StringContent(request, Encoding.UTF8, "application/json");
        var response = await client.PostAsync("http://localhost:44357/api/Home", content);
        var responseString = await response.Content.ReadAsStringAsync();
        var personResp = JsonConvert.DeserializeObject<Person>(responseString);
        Console.WriteLine(string.Format("{0} {1}", personResp.ID, personResp.Name));
    }
}
public class Person
{
    public int ID { get; set; }
    public string Name { get; set; }
}