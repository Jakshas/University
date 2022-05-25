using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shop.Domain.Model.Repository
{
    public interface IOrderRepository
    {
        void Insert(Order post);

        void Delete(int id);

        Order Find(int id);
    }
}
