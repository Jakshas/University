using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.Security.Claims;
using Zadanie4.Models;

namespace Zadanie4.Controllers
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

            _ = SignInAsync(new ClaimsIdentity(Claims, CookieAuthenticationDefaults.AuthenticationScheme));

            return View();
        }

        private async Task SignInAsync(ClaimsIdentity claimsIdentity)
        {
            var authProperties = new AuthenticationOptions
            {
                RequireAuthenticatedSignIn = false
            };
            await HttpContext.SignInAsync(new ClaimsPrincipal(claimsIdentity));
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