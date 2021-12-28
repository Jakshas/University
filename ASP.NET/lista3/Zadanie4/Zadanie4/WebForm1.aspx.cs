using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie4
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            l1.Text = SessionPseudoSingleton.TheData+"<br>";
            l1.Text += Global.TheDatabase.i+ "<br>";
        }
    }
    public class SessionPseudoSingleton

    {
        const string DATAKEY = "datakey";
        public static String TheData
        {
            get
            {
                if (HttpContext.Current.Session[DATAKEY] == null)
                {
                    // create object someho
                    String f = "";
                    HttpContext.Current.Session[DATAKEY] = f;
                }
                return (String)HttpContext.Current.Session[DATAKEY];
            }

        }

    }
    public class Global
    {
        const string MODELKEY = "model";
        public static TheDatabase Model
        {
            get
            {
                if (HttpContext.Current.Items[MODELKEY] == null)
                {
                    TheDatabase db = new TheDatabase();
                    HttpContext.Current.Items[MODELKEY] = db;
                }
                return (TheDatabase)HttpContext.Current.Items[MODELKEY];
            }

        }

    public class TheDatabase 
        {
            public static int i = 1; 
        }
    }
    public class ApplicationPseudoSingleton
    {
        const string DATAKEY = "datakey";
        const object _lock = new object();
        public static String TheData
        {
            get
            {
                if (HttpContext.Current.Application[DATAKEY] == null)
                {
                    lock (_lock)
                    {
                        if (HttpContext.Current.Application[DATAKEY] == null)
                        {
                            String f = ";";
                            HttpContext.Current.Application[DATAKEY] = f;
                        }
                    }
                }
                return (String)HttpContext.Current.Application[DATAKEY];
            }
        }
    }
}