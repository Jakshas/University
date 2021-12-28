using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Web;

namespace Zadanie2
{
    public class CustomBasePage: System.Web.UI.Page
    {
        private ExampleDataContext _dataContext;
        public static int id = 0;
        public ExampleDataContext DataContext
        {
            get
            {
                if(_dataContext == null)
                {
                    var cs = ConfigurationManager.AppSettings["cs"];
                    _dataContext= new ExampleDataContext(cs);
                }

                return _dataContext;
            }
        }
        public override void Dispose()
        {
            if(_dataContext != null)
            {
                _dataContext.Dispose();
            }
        }
    }
}