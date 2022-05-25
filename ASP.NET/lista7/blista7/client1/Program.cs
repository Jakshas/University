using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

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
        Console.WriteLine("Wszedlem w geta");

        using (var requestMessage = new HttpRequestMessage(HttpMethod.Get, "https://localhost:44357/api/Person"))
        {
            requestMessage.Headers.Authorization =
                new AuthenticationHeaderValue("Bearer", your_token);
            
            await httpClient.SendAsync(requestMessage);
        }

        var responseString = await client.GetStringAsync("https://localhost:44357/api/Home");
        var response = JsonConvert.DeserializeObject<IEnumerable<Person>>(responseString);
        foreach (var person in response)
        {
            Console.WriteLine(string.Format("{0} {1}", person.ID, person.Name));
        }
        Console.WriteLine();
    }
    async static Task Post()
    {
        Console.WriteLine("Wszedlem w posta");
        var person = new Person() { ID = 188, Name = "ghj" };
        var request = JsonConvert.SerializeObject(person);
        StringContent content = new StringContent(request, Encoding.UTF8, "application/json");
        var response = await client.PostAsync("https://localhost:44357/api/Home", content);
        var responseString = await response.Content.ReadAsStringAsync();
        var personResp = JsonConvert.DeserializeObject<Person>(responseString);
        Console.WriteLine(string.Format("{0} {1}", personResp.ID, personResp.Name));
        Console.WriteLine();
    }
}
public class Person
{
    public int ID { get; set; }
    public string Name { get; set; }
}