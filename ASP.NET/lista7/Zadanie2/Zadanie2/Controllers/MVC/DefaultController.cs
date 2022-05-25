using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie2.Controllers.MVC
{
    public class DefaultController : Controller
    {
        // GET: Default
        [Authorize]
        public ActionResult Index()
        {
            return View();
        }
    }
}