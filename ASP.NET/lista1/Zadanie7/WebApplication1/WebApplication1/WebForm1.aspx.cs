using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            using (StreamReader sr = new StreamReader("C:\\Projekty\\University\\ASP.NET\\lista1\\zadanie8pom.txt"))
            {
                string line, str="";
                while ((line = sr.ReadLine()) != null)
                {
                    str += line;
                }
                Label1.Text = str;
            }
        }
    }
}