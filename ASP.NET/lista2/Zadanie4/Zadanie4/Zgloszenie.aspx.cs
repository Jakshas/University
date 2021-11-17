using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Zadanie4
{
    public partial class Zgloszenie : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            buton.Click += new EventHandler(GreetingBtn_Click);
        }
        void GreetingBtn_Click1(Object sender,EventArgs e)
        {
            if (TextBox1.Text == "")
                TextBox1.Text = "0";
            if (TextBox2.Text == "")
                TextBox2.Text = "0";
            if (TextBox3.Text == "")
                TextBox3.Text = "0";
            if (TextBox4.Text == "")
                TextBox4.Text = "0";
            if (TextBox5.Text == "")
                TextBox5.Text = "0";
            if (TextBox6.Text == "")
                TextBox6.Text = "0";
            if (TextBox7.Text == "")
                TextBox7.Text = "0";
            if (TextBox8.Text == "")
                TextBox8.Text = "0";
            if (TextBox9.Text == "")
                TextBox9.Text = "0";
            if (TextBox10.Text == "")
                TextBox10.Text = "0";

            this.Response.Redirect("/Wydruk.aspx?"+"imie="+Imie.Text +  "&nazwisko=" + Nazwisko.Text + "&data=" + Data.Text + "&zestaw=" + Zestaw.Text + "&zajecia=" + Zajecia.Text + "&TextBox1=" + TextBox1.Text + "&TextBox2=" + TextBox2.Text + "&TextBox3=" + TextBox3.Text + "&TextBox4=" + TextBox4.Text + "&TextBox5=" + TextBox5.Text + "&TextBox6=" + TextBox6.Text + "&TextBox7=" + TextBox7.Text + "&TextBox8=" + TextBox8.Text + "&TextBox9=" + TextBox9.Text + "&TextBox10=" + TextBox10.Text);
        }
        void GreetingBtn_Click(Object sender, EventArgs e)
        {
            if (TextBox1.Text == "")
                TextBox1.Text = "0";
            if (TextBox2.Text == "")
                TextBox2.Text = "0";
            if (TextBox3.Text == "")
                TextBox3.Text = "0";
            if (TextBox4.Text == "")
                TextBox4.Text = "0";
            if (TextBox5.Text == "")
                TextBox5.Text = "0";
            if (TextBox6.Text == "")
                TextBox6.Text = "0";
            if (TextBox7.Text == "")
                TextBox7.Text = "0";
            if (TextBox8.Text == "")
                TextBox8.Text = "0";
            if (TextBox9.Text == "")
                TextBox9.Text = "0";
            if (TextBox10.Text == "")
                TextBox10.Text = "0";

            TextBox1.Text = "0";
            Session.Add("imie" ,Imie.Text);
            Session.Add("nazwisko", Nazwisko.Text);
            Session.Add("data", Data.Text);
            Session.Add("zajecia", Zajecia.Text);
            Session.Add("zestaw", Zestaw.Text);
            Session.Add("TextBox1", TextBox1.Text);
            Session.Add("TextBox2", TextBox2.Text);
            Session.Add("TextBox3", TextBox3.Text);
            Session.Add("TextBox4", TextBox4.Text);
            Session.Add("TextBox5", TextBox5.Text);
            Session.Add("TextBox6", TextBox6.Text);
            Session.Add("TextBox7", TextBox7.Text);
            Session.Add("TextBox8", TextBox8.Text);
            Session.Add("TextBox9", TextBox9.Text);
            Session.Add("TextBox10", TextBox10.Text);
            Response.Redirect("/Wydruk.aspx?");
        }
    }
}