using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace zad2.Controllers
{
    public class AccountController : Controller
    {
        // GET: Account
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Index(string q)
        {
            if(this.Request["login"] == this.Request["password"] && this.Request["Login"] != null)
            {
                FormsAuthenticationTicket ticket = new FormsAuthenticationTicket(1, Request["login"], DateTime.Now, DateTime.Now.AddMinutes(10), false, "");
                HttpCookie cookie = new HttpCookie(FormsAuthentication.FormsCookieName, FormsAuthentication.Encrypt(ticket));
                Response.AppendCookie(cookie);
                var a = User.Identity;
                return Redirect("/Home");
            }
            return View();
        }
    }
}