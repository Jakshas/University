using System;
using System.Collections.Generic;
using System.IdentityModel.Services;
using System.IdentityModel.Tokens;
using System.Linq;
using System.Security.Claims;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace OAuth2Demo
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            // sprawdzenie czy 18 lat
            ClaimsPrincipal foundCp = null;
            SessionSecurityToken outResultSessionSecurityToken = null;
            SessionAuthenticationModule sam = FederatedAuthentication.SessionAuthenticationModule;
            if( sam.TryReadSessionTokenFromCookie(out outResultSessionSecurityToken)){
                foundCp = outResultSessionSecurityToken.ClaimsPrincipal;
                foreach(var v in foundCp.Claims)
                {
                    if(v.Type == "DateOfBirth")
                    {
                        DateTime t = DateTime.Now;
                        ;
                        if (DateTime.TryParse(v.Value, out t) && TimeSpan.Parse("18y") > DateTime.Now - t)
                        {
                            Response.Redirect("LoginPage.aspx");
                        }
                    }
                }
            }
        }
    }
}