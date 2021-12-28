using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie2
{
    public partial class LoginPage : CustomBasePage
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Customembership.ex = this.DataContext;
        }

        protected void bt_Click(object sender, EventArgs e)
        {
            if (Membership.ValidateUser(login.Text,haslo.Text))
            {
                string[] roles = Roles.GetRolesForUser(login.Text);
                string proles = string.Join("|", roles);
                FormsAuthenticationTicket ticket = new FormsAuthenticationTicket(1, login.Text, DateTime.Now, DateTime.Now.AddMinutes(60), false, proles);
                HttpCookie cookie = new HttpCookie(FormsAuthentication.FormsCookieName, FormsAuthentication.Encrypt(ticket));
                Response.AppendCookie(cookie);
                Response.Redirect("WebForm1.aspx");
            }
        }

        protected void regbt_Click(object sender, EventArgs e)
        {
            string source;
            using (var md5Hash = MD5.Create())
            {
                source = haslo.Text+1;
                for (int i = 0; i < 2; i++)
                {
                    var sourceBytes = Encoding.UTF8.GetBytes(source);
                    var hashBytes = md5Hash.ComputeHash(sourceBytes);
                    source = BitConverter.ToString(hashBytes).Replace("-", string.Empty) + "1";
                }
            }
            PASSWORD p = new PASSWORD { liczba = 2, skrot = source, sol = 1 };
            DataContext.USER.InsertOnSubmit(new USER { email = "", Name= source, PASSWORD=p});
            DataContext.PASSWORD.InsertOnSubmit(p);
            DataContext.SubmitChanges();
            if (Membership.ValidateUser(login.Text, haslo.Text))
            {
                string[] roles = Roles.GetRolesForUser(login.Text);
                string proles = string.Join("|", roles);
                FormsAuthenticationTicket ticket = new FormsAuthenticationTicket(1, login.Text, DateTime.Now, DateTime.Now.AddMinutes(60), false, proles);
                HttpCookie cookie = new HttpCookie(FormsAuthentication.FormsCookieName, FormsAuthentication.Encrypt(ticket));
                Response.AppendCookie(cookie);
                Response.Redirect("WebForm1.aspx");
            }
        }
    }
}