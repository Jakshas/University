using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shop.Domain.Model.Repository
{
    public interface IUserRepository
    {
        void Insert(Product post);

        void Delete(int id);

        Product Find(int id);
    }
}
