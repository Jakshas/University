using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace Zadanie1.Controllers.WebAPI
{
    public class DefaultController : ApiController
    {
        public IHttpActionResult Get()
        {
            List<Student> students = new List<Student>()
            {
                new Student() { ID=1, Imie="Jakub", Nazwisko="Kowalski" },
                new Student() { ID=2, Imie="Kacper", Nazwisko="Kowalski" },
                new Student() { ID=3, Imie="Cezary", Nazwisko="Kowalski" }
            };
            return this.Ok(students);
        }

        public IHttpActionResult Post(Student p)
        {
            if (p == null)
                return this.BadRequest();

            return this.Ok(new Student() { ID = 1, Imie = p.Imie , Nazwisko = p.Nazwisko });
        }
    }
}
