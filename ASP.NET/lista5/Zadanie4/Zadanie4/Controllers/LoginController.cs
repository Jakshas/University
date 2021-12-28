using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace Zadanie4.Controllers
{
    public class LoginController : Controller
    {
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Index(Models.User model)
        {
            if (model.login != "" && new MyMembershipProvider().ValidateUser(model.login, model.haslo))
            {
                if (Membership.ValidateUser(model.login, model.haslo))
                {
                    string[] roles = Roles.GetRolesForUser(model.login);
                    string proles = string.Join("|", roles);
                    FormsAuthenticationTicket ticket = new FormsAuthenticationTicket(1, model.login, DateTime.Now, DateTime.Now.AddMinutes(60), false, proles);
                    HttpCookie cookie = new HttpCookie(FormsAuthentication.FormsCookieName, FormsAuthentication.Encrypt(ticket));
                    Response.AppendCookie(cookie);
                    return RedirectToAction("Index", "Admin");
                }
                else
                {
                    FormsAuthenticationTicket ticket = new FormsAuthenticationTicket(1, model.login, DateTime.Now, DateTime.Now.AddMinutes(10), false, "");
                    HttpCookie cookie = new HttpCookie(FormsAuthentication.FormsCookieName, FormsAuthentication.Encrypt(ticket));
                    Response.AppendCookie(cookie);
                    return RedirectToAction("Index", "Default");
                }

            }
            return View();
        }
    }
}