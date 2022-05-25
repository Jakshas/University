using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using Zadanie1.Controllers.WebAPI;

class Program
{
    static HttpClient client = new HttpClient();
    static Program()
    {
        client.DefaultRequestHeaders.Accept.Add(new System.Net.Http.Headers.MediaTypeWithQualityHeaderValue("application/json"));
    }
    static void Main(string[] args)
    {
        Get();
        Post();
        Console.ReadLine();
    }
    async static Task Get()
    {
        using (var requestMessage = new HttpRequestMessage(HttpMethod.Get, "https://localhost:44357/api/Student"))
        {
            await client.SendAsync(requestMessage);
        }

        var responseString = await client.GetStringAsync("https://localhost:44357/api/Default");
        var response = JsonConvert.DeserializeObject<IEnumerable<Student>>(responseString);
        foreach (var student in response)
        {
            Console.WriteLine(string.Format("{0} {1}", student.ID, student.Imie));
        }
        Console.WriteLine();
    }
    async static Task Post()
    {
        var student = new Student() { ID = 2, Imie = "Jakub", Nazwisko = "Szajner" };
        var request = JsonConvert.SerializeObject(student);
        StringContent content = new StringContent(request, Encoding.UTF8, "application/json");
        var response = await client.PostAsync("https://localhost:44357/api/Default", content);
        var responseString = await response.Content.ReadAsStringAsync();
        var studentResp = JsonConvert.DeserializeObject<Student>(responseString);
        Console.WriteLine(string.Format("{0} {1} {2}", studentResp.ID, studentResp.Imie, studentResp.Nazwisko));
        Console.WriteLine();
    }
}