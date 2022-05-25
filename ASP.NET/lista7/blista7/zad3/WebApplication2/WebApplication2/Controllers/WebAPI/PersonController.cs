using Microsoft.IdentityModel.Tokens;
using System;
using System.Collections.Generic;
using System.IdentityModel.Tokens.Jwt;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Security.Principal;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Web.Http;
using System.Web.Http.Filters;
using System.Web.Http.Results;


namespace WebApplication2.Controllers.WebAPI
{
    [CustomAuthenticationFilter]
    public class PersonController : ApiController
    {
        public IHttpActionResult Get()
        {
            var list = new List<Person>()
            {
                new WebAPI.Person() { ID = 1, Name = "jan" },
                new WebAPI.Person() { ID = 100, Name = "tomasz" },
            };

            return this.Ok(list);
        }

        public IHttpActionResult Post(Person person)
        {
            return this.Ok(person);
        }
    }

    public class Person
    {
        public int ID { get; set; }
        public string Name { get; set; }
    }

    public class CustomAuthenticationFilter : Attribute, IAuthenticationFilter
    {
        const string header_name = "token";

        public bool AllowMultiple
        {
            get
            {
                return true;
            }
        }

        public Task AuthenticateAsync(
            HttpAuthenticationContext context,
            CancellationToken cancellationToken)
        {
            var plainTextSecurityKey = "This is my shared, not so secret, secret!";
            var signingKey = new Microsoft.IdentityModel.Tokens.SymmetricSecurityKey(Encoding.UTF8.GetBytes(plainTextSecurityKey));
            var request = context.Request;
            IEnumerable<string> headers;

            if (request.Headers.TryGetValues(header_name, out headers))
            {
                var value = headers.FirstOrDefault();
                var tokenHandler = new JwtSecurityTokenHandler();

                var tokenValidationParameters = new TokenValidationParameters()
                {
                    ValidAudiences = new string[]
                    {
                    "http://my.website.com",
                    },
                    ValidIssuers = new string[]
                    {
                    "http://my.tokenissuer.com",
                    },
                    IssuerSigningKey = signingKey
                };
                SecurityToken validatedToken;
                var validatedPrincipal = tokenHandler.ValidateToken(value,
                tokenValidationParameters, out validatedToken);

                if (validatedPrincipal.Identity.Name == "asdaasdaASPzad3")
                {
                    context.Principal =
                        new GenericPrincipal(
                            new GenericIdentity("user", "authenticated"),
                            new string[0]);

                    return Task.FromResult(0);
                }
            }

            // fallback - brak nagłówka lub niepoprawny nagłówek
            context.ErrorResult =
                new ResponseMessageResult(
                    request.CreateErrorResponse(HttpStatusCode.Unauthorized, "unauthorized"));

            return Task.FromResult(0);
        }

        public Task ChallengeAsync(
            HttpAuthenticationChallengeContext context,
            CancellationToken cancellationToken)
        {
            return Task.FromResult(0);
        }
    }

}
