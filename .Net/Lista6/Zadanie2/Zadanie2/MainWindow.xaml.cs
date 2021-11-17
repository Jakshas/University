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

namespace Zadanie2
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

        private void button_Click(object sender, RoutedEventArgs e)
        {
            if (pr.Value < 100)
            {
                pr.Value++;
            }
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            if (pr.Value > 0)
            {
                pr.Value--;
            }
        }

        private void button_Click_1(object sender, RoutedEventArgs e)
        {
            if (pr.Value < 100)
            {
                pr.Value++;
            }
        }

        private void button1_Click_1(object sender, RoutedEventArgs e)
        {
            if (pr.Value > 0)
            {
                pr.Value--;
            }
        }

        public class MyItem
        {
            public string Imie { get; set; }

            public string Nazwisko { get; set; }

            public int Wzrost { get; set; }
        }
        private void textBox_SelectionChanged(object sender, RoutedEventArgs e)
        {
            textBlock.Text = "Linia " + (textBox.GetLineIndexFromCharacterIndex(textBox.CaretIndex) + 1) + " Znak " + (textBox.CaretIndex - textBox.GetCharacterIndexFromLineIndex(textBox.GetLineIndexFromCharacterIndex(textBox.CaretIndex)));
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            listView.Items.Add(new MyItem { Imie = textBox1.Text, Nazwisko = textBox2.Text,Wzrost = Int32.Parse(textBox3.Text) });
        }
    }
}
