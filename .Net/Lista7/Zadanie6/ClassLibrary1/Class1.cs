using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary1
{
    [Serializable()]
    public class CObiekt : ISerializable
    {
        int v;
        DateTime d;
        string s;
        public CObiekt(int v, DateTime d, string s)
        {
            this.v = v;
            this.d = d;
            this.s = s;
        }
        public CObiekt(SerializationInfo info, StreamingContext context)
        {
            v = (int)info.GetValue("v", typeof(int));
            d = (DateTime)info.GetValue("d", typeof(DateTime));
            s = (string)info.GetValue("s", typeof(string));
        }
        public void GetObjectData(SerializationInfo info, StreamingContext context)
        {
            info.AddValue("v", v);
            info.AddValue("d", d);
            info.AddValue("s", s);
        }
        public override string ToString()
        {
            return String.Format("{0}, {1:d}, {2}", v, d, s);
        }
    }
}
