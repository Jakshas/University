using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml;

namespace Zadanie7
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void UploadButton_Click(object sender, EventArgs e)
        {
            if (FileUpload1.HasFile)
            {
                String fileName = FileUpload1.FileName;
                int size = FileUpload1.PostedFile.ContentLength;
                var tab = FileUpload1.FileBytes;
                int suma = 0;
                foreach( int t in tab)
                {
                    suma += t;
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
            }
        }
    }
}