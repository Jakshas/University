using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie1.Controllers
{
    public class EditController : Controller
    {
        // GET: Edit
        [HttpGet]
        public ActionResult Index()
        {
            using (var context = new StudenciDataContext())
            {
                var tab = context.Studenci.Where(x => x.ID == int.Parse(Request.QueryString[0])).First();
                return View(new { Imie = tab.Imie, Nazwisko = tab.Nazwisko, Wiek = tab.Wiek });
            }
        }
        [HttpPost]
        public ActionResult Index(string q)
        {
            string imie = Request.Form["Imie"];
            string nazwisko = Request.Form["Nazwisko"];
            int wiek = int.Parse(Request.Form["Wiek"]);

            if (imie == "" || nazwisko == "")
            {
                return View();
            }
            using (var context = new StudenciDataContext())
            {
                var tab = context.Studenci.Where(x => x.ID == int.Parse(Request.Form["ID"])).First();
                tab.Wiek = wiek;
                tab.Imie = imie;
                tab.Nazwisko = nazwisko;
                context.SubmitChanges();
            }
            return Redirect("/Default");
        }
    }
}