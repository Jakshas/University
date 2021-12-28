using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie4.Controllers
{
    public class DefaultController : Controller
    {
        [Authorize]
        public ActionResult Index()
        {
            return Content("Jesteś zalogowany");
        }
    }
}