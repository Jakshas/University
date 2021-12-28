using MVCCMSRouting.Models.Page;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Markdig;

namespace MVCCMSRouting.Controllers
{
    public class PageController : Controller
    {        
        public ActionResult Render()
        {
            var routeData = this.Request.RequestContext.RouteData.Values;

            string site = routeData[CMSCustomRoute.SITENAME] as string;
            string page = routeData[CMSCustomRoute.PAGENAME] as string;
            string content;

            // odczyt z magazynu danych

            using (var context = new StronyDataContext())
            {
                var znalezione = context.Strony.Where(x => x.Nazwa.Replace("\\", "/") == (site + "/" + page));
                if (znalezione.Count() == 0)
                    return Content("Nie ma strony");
                else
                    content = Markdown.ToHtml(znalezione.First().Strona);
            }

            // renderowanie
            var model = new PageRenderModel()
            {
                Content = content,
                Site = site,
                Page = page
            };

            return View(model);
        }
        [HttpPost]
        public ActionResult Render(string q)
        {
            if (Request["route"] == "")
                return View();
            using (var context = new StronyDataContext())
            {
                var val = Request.RequestContext.RouteData.Values;
                string adres = val[CMSCustomRoute.SITENAME] as string;
                var znalezione = context.Strony.Where(x => x.Nazwa == Request["route"]);

                if (znalezione.Count() == 0)
                {
                    context.Strony.InsertOnSubmit(new Strony() { Nazwa = adres + "/" + Request["route"]+"/index.html", Strona = "" });
                    context.SubmitChanges();
                }
                return Redirect("/CMS/" + adres + "/" + Request["route"]);
            }
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