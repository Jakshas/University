using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie4
{
    public partial class Wydruk : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            var qs = this.Request.QueryString;
            label.Text = "Imie:"+qs[0]+ "<br/>Nazwisko:" + qs[1] + "<br/>Data:" + qs[2] + "<br/>Przedmiot:" + qs[4] + "<br/>Zestaw:" + qs[3] + "<br/>Zadajnie1:" + qs[5] + "<br/>Zadajnie2:" + qs[6] + "<br/>Zadajnie3:" + qs[7] + "<br/>Zadajnie4:" + qs[8] + "<br/>Zadajnie5:" + qs[9] + "<br/>Zadajnie6:" + qs[10] + "<br/>Zadajnie7:" + qs[11] + "<br/>Zadajnie8:" + qs[12] + "<br/>Zadajnie9:" + qs[13] + "<br/>Zadajnie10:" + qs[14];
        }
    }
}