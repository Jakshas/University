using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MVCCMSRouting.Models.Page;

namespace MVCCMSRouting.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
        public ActionResult Index()
        {
            return Content("Home/Index nadal działa");
        }
        public ActionResult Save(PageRenderModel content)
        {
            var routeData = Request.RequestContext.RouteData.Values;
            string site = routeData[CMSCustomRoute.SITENAME] as string;
            string page = routeData[CMSCustomRoute.PAGENAME] as string;

            using (var context = new StronyDataContext())
            {
                var matches = context.Strony.Where(x => x.Nazwa.Replace("\\", "/") == (site + "/" + page));
                if (matches.Count() == 0)
                {
                    return Content("dodaj strone");
                }
                matches.First().Strona = content.Content;
                var model = new PageRenderModel()
                {
                    Site = site,
                    Page = page,
                    Content = content.Content
                };
                context.SubmitChanges();
                return View(model);
            }
        }
    }
}