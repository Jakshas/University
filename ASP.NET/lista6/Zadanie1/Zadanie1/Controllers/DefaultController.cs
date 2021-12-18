using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Zadanie1.Models;

namespace Zadanie1.Controllers
{
    public class DefaultController : Controller
    {
        // GET: Default
        [HttpGet]
        public ActionResult Index(int page = 0, string sort = "Imie", string sortdir = "ASC")
        {
            var model = new GridMOdel();
            var dataLayer = new DataLayer();

            model.Students = new PagedEnumerable<Student>()
            {
                Items = dataLayer.GetStudents(string.Format("{0} {1}", sort, sortdir), (page - 1) * 10, 10),
                TotalCount = dataLayer.TotalStudents()
            };

            return View(model);
        }
        [HttpGet]
        public ActionResult Add()
        {
            return Redirect("/Add");
        }
    }
}