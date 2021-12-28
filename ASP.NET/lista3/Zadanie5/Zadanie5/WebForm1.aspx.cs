using System;
using System.Collections.Generic;
using System.Data.Linq;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie5
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            DataContext dc = Global.Model;
            l1.Text = dc.ToString();
        }
    }
    public class Global
    {
        const string MODELKEY = "model";
        public static DataContext Model
        {
            get
            {
                if (HttpContext.Current.Items[MODELKEY] == null)
                {
                    DataContext db = new DataContext("WebForm1.aspx");
                    HttpContext.Current.Items[MODELKEY] = db;
                }
                return (DataContext)HttpContext.Current.Items[MODELKEY];
            }

        }
    }
}