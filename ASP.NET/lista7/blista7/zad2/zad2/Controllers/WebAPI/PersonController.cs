using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace zad2.Controllers
{

    [Authorize]
    public class PersonController : ApiController
    {
        public IHttpActionResult Get()
        {
            List<Person> persons = new List<Person>()
            {
                new Person() { Id=1, Name="Kamil" },
                new Person() { Id=2, Name="Arek" }
            };
            return this.Ok(persons);
        }

        public IHttpActionResult Post(Person p)
        {
            if (p == null)
                return this.BadRequest();

            return this.Ok(new Person() { Id = 1, Name = p.Name + "accepted" });
        }
    }

    public class Person
    {
        public int Id { get; set; }
        public string Name { get; set; }
    }
}
