using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie1.Controllers
{
    public class AddController : Controller
    {
        // GET: Add
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }
        [HttpPost]
        public ActionResult Index(string q)
        {
            string imie = Request.Form["Imie"];
            string nazwisko = Request.Form["Nazwisko"];
            int wiek = int.Parse(Request.Form["Wiek"]);

            if (imie == "" || nazwisko == "" || wiek == 0)
            {
                return View();
            }
            using (var context = new StudenciDataContext())
            {
                var tab = context.Studenci;
                tab.InsertOnSubmit(new Studenci { Imie = imie, Nazwisko = nazwisko, Wiek = wiek });
                context.SubmitChanges();
            }
            return Redirect("/Default");
        }
    }
}