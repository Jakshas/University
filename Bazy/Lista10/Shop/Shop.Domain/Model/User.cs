using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shop.Domain.Model.Repository;

public class User //entity identyfikator email cykl zycia utworzenie zalogownaie wylogowanie agregat: user root
    {
        private IUserRepository _userRepository;
        string Login;
        string Password;
        string Email;
        public User(string Login, string Password, string Email)
        {
            this.Login = Login;
            this.Email = Email;
            this.Password = Password;
        }
        public bool changePasword(string NewPassword, string OldPassword)
        {
            return true;
        }
        public bool changeEmail(string NewEmail, string OldEmail)
        {
            return true;
        }
    }

