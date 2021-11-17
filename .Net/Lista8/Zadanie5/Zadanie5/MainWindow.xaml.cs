using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Zadanie5
{
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            using (DataClasses1DataContext context = new DataClasses1DataContext(@"server=.\sqlexpress;database=zadanie2;integrated security=true"))
            {
                foreach (Student s in context.Student){
                    string str = s.Imie + " " + s.Nazwisko + " " + s.DataUrodzenia.ToString() + " " + s.Miejscowosc;
                    listBox.Items.Add(str);
                }
                
            }
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            using (DataClasses1DataContext context = new DataClasses1DataContext(@"server=.\sqlexpress;database=zadanie2;integrated security=true"))
            {
                Student s = new Student();
                s.Imie = textBox.Text;
                s.Nazwisko = textBox1.Text;
                s.DataUrodzenia = dp.SelectedDate.Value;
                s.Miejscowosc = textBox3.Text;
                string str = s.Imie + " " + s.Nazwisko + " " + s.DataUrodzenia.ToString() + " " + s.Miejscowosc;
                Miejscowosc m = new Miejscowosc();
                foreach(var mi in context.Miejscowosc)
                {
                    if(mi.Nazwa == textBox3.Text)
                    {
                        listBox.Items.Add(str);
                        context.Student.InsertOnSubmit(s);
                        context.SubmitChanges();
                        return;
                    }
                }
                m.Nazwa = textBox3.Text;
                listBox.Items.Add(str);
                context.Miejscowosc.InsertOnSubmit(m);
                context.Student.InsertOnSubmit(s);
                context.SubmitChanges();
            }
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            using (DataClasses1DataContext context = new DataClasses1DataContext(@"server=.\sqlexpress;database=zadanie2;integrated security=true"))
            {
                Student s = new Student();
                var l = listBox.SelectedItem;
                if(l == null)
                {
                    return;
                }
                string[] st = l.ToString().Split(' ');
                s.Imie = st[0];
                s.Nazwisko = st[1];
                s.DataUrodzenia = DateTime.Parse(st[2]);
                s.Miejscowosc = st[4];
                Student del = null;
                foreach(var v in context.Student)
                {
                    if(v.DataUrodzenia==s.DataUrodzenia && s.Imie == v.Imie && s.Nazwisko == v.Nazwisko && s.Miejscowosc == v.Miejscowosc)
                    {
                        del = v;
                        break;
                    }
                }
                if (del == null)
                    return;
                context.Student.DeleteOnSubmit(del);
                context.SubmitChanges();
                listBox.Items.Clear();
                foreach (Student ss in context.Student)
                {
                    string str = ss.Imie + " " + ss.Nazwisko + " " + ss.DataUrodzenia.ToString() + " " + ss.Miejscowosc;
                    listBox.Items.Add(str);
                }
            }
        }

        private void listBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {            
            

        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            using (DataClasses1DataContext context = new DataClasses1DataContext(@"server=.\sqlexpress;database=zadanie2;integrated security=true"))
            {
                Student s1 = new Student();
                s1.Imie = textBox.Text;
                s1.Nazwisko = textBox1.Text;
                s1.DataUrodzenia = dp.SelectedDate.Value;
                s1.Miejscowosc = textBox3.Text;
                Miejscowosc m = new Miejscowosc();
                Student s = new Student();
                var l = listBox.SelectedItem;
                if (l == null)
                {
                    return;
                }
                string[] st = l.ToString().Split(' ');
                s.Imie = st[0];
                s.Nazwisko = st[1];
                s.DataUrodzenia = DateTime.Parse(st[2]);
                s.Miejscowosc = st[4];
                Student del = null;
                foreach (var v in context.Student)
                {
                    if (v.DataUrodzenia == s.DataUrodzenia && s.Imie == v.Imie && s.Nazwisko == v.Nazwisko && s.Miejscowosc == v.Miejscowosc)
                    {
                        del = v;
                        break;
                    }
                }
                if (del == null)
                    return;
                foreach (var mi in context.Miejscowosc)
                {
                    if (mi.Nazwa == textBox3.Text)
                    {
                        context.Student.DeleteOnSubmit(del);
                        context.Student.InsertOnSubmit(s1);
                        context.SubmitChanges();
                        return;
                    }
                }
                context.Student.DeleteOnSubmit(del);
                context.Student.InsertOnSubmit(s1);
                m.Nazwa = textBox3.Text;
                context.Miejscowosc.InsertOnSubmit(m);
                context.SubmitChanges();
                listBox.Items.Clear();
                foreach (Student ss in context.Student)
                {
                    string str = ss.Imie + " " + ss.Nazwisko + " " + ss.DataUrodzenia.ToString() + " " + ss.Miejscowosc;
                    listBox.Items.Add(str);
                }
            }
        }
    }
}
