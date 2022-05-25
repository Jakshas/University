using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using zad2.Models;

namespace zad2.Controllers
{
    public class HomeController : Controller
    {
        private readonly IConfiguration Configuration;

        public HomeController(IConfiguration configuration)
        {
            Configuration = configuration;
        }

        public IActionResult Index()
        {
            if (Request.Cookies["myCookie"] == null)
            {
                Response.Cookies.Append("myCookie", "a");
            }
            else
            {
                Response.Cookies.Append("myCookie", Request.Cookies["myCookie"] + "a");
            }

            if (HttpContext.Session.GetInt32("_random") != null)
                Console.WriteLine(HttpContext.Session.GetInt32("_random"));
            else
                HttpContext.Session.SetInt32("_random", new Random().Next());
            Console.WriteLine(HttpContext.Session.GetInt32("_random"));

            Console.WriteLine(Configuration["AppSettings:foo"]);
            return View();
        }

        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}