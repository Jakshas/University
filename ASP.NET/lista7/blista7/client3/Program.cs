using System.Text;
using System.Security.Claims;
using System.IdentityModel.Tokens.Jwt;
using Newtonsoft.Json;
using System.Net.Http;

class Program
{
    static HttpClient client = new HttpClient();
    static Program()
    {
        client.DefaultRequestHeaders.Accept.Add(new System.Net.Http.Headers.MediaTypeWithQualityHeaderValue("application/json"));
    }
    static void Main(string[] args)
    {
        var plainTextSecurityKey = "This is my shared, not so secret, secret!";
        var signingKey = new Microsoft.IdentityModel.Tokens.SymmetricSecurityKey(Encoding.UTF8.GetBytes(plainTextSecurityKey));
        var signingCredentials = new Microsoft.IdentityModel.Tokens.SigningCredentials(signingKey, Microsoft.IdentityModel.Tokens.SecurityAlgorithms.HmacSha256Signature);
        // -------------------------
        var claimsIdentity = new ClaimsIdentity(new List<Claim>()
            {
            new Claim(ClaimTypes.Name, "asdaasdaASPzad3"),
            new Claim(ClaimTypes.Role, "Administrator"),
            }, "Custom");
        var securityTokenDescriptor = new Microsoft.IdentityModel.Tokens.SecurityTokenDescriptor()
        {
            Audience = "http://my.website.com",
            Issuer = "http://my.tokenissuer.com",
            Subject = claimsIdentity,
            SigningCredentials = signingCredentials
        };
        var tokenHandler = new JwtSecurityTokenHandler();
        var plainToken = tokenHandler.CreateToken(securityTokenDescriptor);
        var signedAndEncodedToken = tokenHandler.WriteToken(plainToken);
        // Console.WriteLine(plainToken);
        // Console.WriteLine(signedAndEncodedToken);
        HttpRequestMessage request = new HttpRequestMessage()
        {
            Method = HttpMethod.Get,
            RequestUri = new Uri("http://localhost:59300/api/Person")
        };
        request.Headers.Add("token", signedAndEncodedToken);
       
        HttpResponseMessage response = client.SendAsync( request ).Result;
        var users = response.Content.ReadFromJsonAsync<IEnumerable<Person>>().Result;
        foreach ( var person in users)
        {
            Console.WriteLine(string.Format("{0} {1}", person.ID, person.Name));
        }
        Console.ReadLine();
    }

    public class Person
    {
        public int ID { get; set; }
        public string? Name { get; set; }
    }
}