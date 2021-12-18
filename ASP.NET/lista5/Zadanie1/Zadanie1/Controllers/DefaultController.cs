using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie1.Controllers
{
    public class DefaultController : Controller
    {
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }
        [HttpPost]
        public ActionResult Index(string q)
        {
            var qs = this.Request.Form;
            string s = "Imie:" + qs[0] + "<br/>Nazwisko:" + qs[1] + "<br/>Data:" + qs[2] + "<br/>Przedmiot:" + qs[3] + "<br/>Zestaw:" + qs[4] + "<br/>Zadajnie1:" + (qs[5] == "" ? "0" : qs[5]) + "<br/>Zadajnie2:" + (qs[6] == "" ? "0" : qs[6]) + "<br/>Zadajnie3:" + (qs[7] == "" ? "0" : qs[7]) + "<br/>Zadajnie4:" + (qs[8] == "" ? "0" : qs[8]) + "<br/>Zadajnie5:" + (qs[9] == "" ? "0" : qs[9]) + "<br/>Zadajnie6:" + (qs[10] == "" ? "0" : qs[10]) + "<br/>Zadajnie7:" + (qs[11] == "" ? "0" : qs[11]) + "<br/>Zadajnie8:" + (qs[12] == "" ? "0" : qs[12]) + "<br/>Zadajnie9:" + (qs[13] == "" ? "0" : qs[13]) + "<br/>Zadajnie10:" + (qs[14] == "" ? "0" : qs[14]);

            return Content(s);
        }
    }
}