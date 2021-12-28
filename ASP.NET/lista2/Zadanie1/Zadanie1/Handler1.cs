using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;

namespace Zadanie1
{
    public class Handler1 : IHttpHandler
    {
        public bool IsReusable => true;

        public void ProcessRequest(HttpContext context)
        {
            context.Response.AppendHeader("Context-type", "text/html");
            context.Response.Write(context.Request.Url+ "<br>");
            context.Response.Write(context.Request.Headers + "<br>");
            context.Response.Write(context.Request.RequestType + "<br>");
            if (context.Request.RequestType == "POST" )
            {
                var bodyStream = new StreamReader(HttpContext.Current.Request.InputStream);
                bodyStream.BaseStream.Seek(0, SeekOrigin.Begin);
                var bodyText = bodyStream.ReadToEnd();
                context.Response.Write(bodyText + "<br>");
            }
            // POST wszytskie 
            context.Response.End();
            string[] keys = context.Request.Form.AllKeys;
            for (int i = 0; i < keys.Length; i++)
            {
                context.Response.Write(keys[i] + ": " + context.Request.Form[keys[i]] + "<br>");
            }
            // Get wszystkie
            foreach(var s in context.Request.QueryString){
                context.Response.Write(s + "<br>");
            }
        }
    }
}