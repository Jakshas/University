using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            // Dodawanie
            HttpCookie nameCookie = new HttpCookie("kuki");
            nameCookie.Values["kuki"] = "kuki";
            nameCookie.Expires = DateTime.Now.AddDays(1);
            Response.Cookies.Add(nameCookie);

            // Czytanie
            nameCookie = Request.Cookies["kuki"];
            string name = nameCookie != null ? nameCookie.Value.Split('=')[1] : "undefined";
            L.Text = name; 

            //Usuwanie
            nameCookie = Request.Cookies["kuki"];
            nameCookie.Expires = DateTime.Now.AddDays(-1);
            Response.Cookies.Add(nameCookie);

            // Sparawdzic można ustawiuajac jakies przykłądowe ciastko a dokłądnie mozna to spradzac np w JSie sprawdzajac zmienna Cookies.enabled
        }
    }
}