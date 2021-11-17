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

namespace Zadanie1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void checkBox_Click(object sender, RoutedEventArgs e)
        {
            if (checkBox1.IsChecked == true)
            {
                checkBox1.IsChecked = false;
            }
            checkBox.IsChecked = true;
        }

        private void checkBox1_Click(object sender, RoutedEventArgs e)
        {
            if(checkBox.IsChecked == true)
            {
                checkBox.IsChecked = false;
            }
            checkBox1.IsChecked = true;
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            Environment.Exit(0);
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            string s;
            if (checkBox.IsChecked == true)
            {
                s = "dzienne";
            }
            else
            {
                s = "uzupełniajace";
            }
            MessageBox.Show(textBox.Text+"\n"+ textBox1.Text + "\n"+ comboBox.Text + "\n"+ s);
        }
    }
}
