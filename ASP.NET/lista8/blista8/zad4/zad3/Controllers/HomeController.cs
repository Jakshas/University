using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.Security.Claims;
using zad3.Models;

namespace zad3.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Index(string q)
        {
            var Claims = new List<Claim>()
            {
                new Claim(ClaimTypes.Name, Request.Form["login"])
            };

            SignIn(new ClaimsIdentity(Claims, CookieAuthenticationDefaults.AuthenticationScheme));
            
            return View();
        }

        public async void SignIn(ClaimsIdentity claimsId)
        {
            var authProperties = new AuthenticationOptions
            {
                RequireAuthenticatedSignIn = false
            };
            await HttpContext.SignInAsync(new ClaimsPrincipal(claimsId));
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