using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.Mvc;
using System.Xml;

namespace Zadanie2.Controllers
{
    public class DefaultController : Controller
    {
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }
        [HttpPost]
        public ActionResult Index(HttpPostedFileBase file)
        {
            if (file.ContentLength > 0)
            {
                String fileName = file.FileName;
                int size = file.ContentLength;
                var tab = file.InputStream;
                int suma = 0;
                for (int i = 0; i < size;  i++)
                {
                    suma += tab.ReadByte();
                }
                suma &= 0xFFFF;
                XmlDocument docConfig = new XmlDocument();
                XmlNode xmlNode = docConfig.CreateNode(XmlNodeType.XmlDeclaration, "", "");
                XmlElement rootElement = docConfig.CreateElement("opis");
                docConfig.AppendChild(rootElement);
                XmlElement installationElement = docConfig.CreateElement("nazwa");
                XmlText installationIdText = docConfig.CreateTextNode(fileName);
                installationElement.AppendChild(installationIdText);
                docConfig.ChildNodes.Item(0).AppendChild(installationElement);
                installationElement = docConfig.CreateElement("rozmiar");
                installationIdText = docConfig.CreateTextNode(Convert.ToString(size));
                installationElement.AppendChild(installationIdText);
                docConfig.ChildNodes.Item(0).AppendChild(installationElement);
                installationElement = docConfig.CreateElement("sygnatura");
                installationIdText = docConfig.CreateTextNode(Convert.ToString(suma));
                installationElement.AppendChild(installationIdText);
                docConfig.ChildNodes.Item(0).AppendChild(installationElement);

                Response.Clear();
                Response.ClearHeaders();
                Response.ContentType = "file/xml";
                Response.Headers.Add("Content-Disposition", "attachment; filename=plik.xml");
                Response.ContentEncoding = System.Text.Encoding.UTF8;
                docConfig.Save(Response.Output);
                Response.End();
                return File(Encoding.Default.GetBytes(docConfig.OuterXml), "file/xml");
            }
            return View();
        }
    }
}