namespace Zadanie1
{

    public partial class Form1 : Form
    {
        List<Student> studentList = new List<Student>();
        List<Wykladowca> wykladowcaList = new List<Wykladowca>();
        public EventAggregator agregator;
        public Dictionary<string, List<WpisWKartotece>> map = new Dictionary<string, List<WpisWKartotece>>();
        public Form1()
        {
            InitializeComponent();
            studentList.Add(new Student("Jan", "Kowalski", "2000-02-21", "ul. D³uga 1, Wroc³aw"));
            studentList.Add(new Student("Jan", "Nowak", "2000-03-11", "ul. Krótka 2, Wroc³aw"));

            wykladowcaList.Add(new Wykladowca("Adam", "Kowalski",  "1970-02-21", "ul. D³uga 2, Wroc³aw"));
            wykladowcaList.Add(new Wykladowca("Adam", "Nowak",  "1970-03-11", "ul. Krótka 3, Wroc³aw"));
            map["Jan Kowalski"] = new List<WpisWKartotece>();
            map["Jan Nowak"] = new List<WpisWKartotece>();
            map["Adam Kowalski"] = new List<WpisWKartotece>();
            map["Adam Nowak"] = new List<WpisWKartotece>();
            map["Jan Kowalski"].Add(new WpisWKartotece(100, "Wp³ata za WF", true));
            map["Jan Kowalski"].Add(new WpisWKartotece(200, "Wp³ata za ", true));
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            agregator = new EventAggregator();
            ListType list = new ListType(treeView1, listView1, studentList, wykladowcaList, map);
            agregator.AddSubscriber<UserProfileSelectedNotification>(list);
            agregator.AddSubscriber<CategorySelectedNotification>(list);
            agregator.AddSubscriber<UserProfileAddedNotification>(list);
            agregator.AddSubscriber<ModifyRecordNotification>(list);
            foreach (Student student in studentList)
            {
                treeView1.Nodes[0].Nodes.Add(new TreeNode(student.imie +" "+ student.nazwisko));
            }
            foreach (Wykladowca student in wykladowcaList)
            {
                treeView1.Nodes[1].Nodes.Add(new TreeNode(student.imie + " " + student.nazwisko));
            }
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            if(e.Node.Text == "Wyk³adowcy" || e.Node.Text == "Studenci")
            {
                CategorySelectedNotification c = new CategorySelectedNotification(e.Node.Text);
                agregator.Publish(c);
            }
            else
            {
                UserProfileSelectedNotification c = new UserProfileSelectedNotification(e.Node.Text.Split(" ")[0], e.Node.Text.Split(" ")[1]);
                agregator.Publish(c);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(listView1.SelectedItems.Count != 0 && (treeView1.SelectedNode.Text != "Wyk³adowcy" && treeView1.SelectedNode.Text != "Studenci"))
            {
                Form f = new Form3(this, listView1.SelectedItems[0]);
                f.ShowDialog(this);
            }


        }

        private void dodaj_Click(object sender, EventArgs e)
        {
            Form f = new Form2(this);
            f.ShowDialog(this);
        }
    }
    public class ListType : ISubscriber<CategorySelectedNotification>, ISubscriber<UserProfileSelectedNotification>, ISubscriber<UserProfileAddedNotification>, ISubscriber<ModifyRecordNotification>
    {
        private TreeView treeView;
        private ListView listView;
        List<Student> studentList;
        List<Wykladowca> wykladowcaList;
        Dictionary<string, List<WpisWKartotece>> map;
        public ListType(TreeView treeView, ListView listView, List<Student> studentList, List<Wykladowca> wykladowcaList, Dictionary<string, List<WpisWKartotece>> map)
        {
            this.treeView = treeView;
            this.listView = listView; 
            this.wykladowcaList= wykladowcaList;
            this.studentList = studentList;
            this.map = map;
        }
        public void Handle(CategorySelectedNotification Notification)
        {
            if(Notification.TypeOfSelected == "Wyk³adowcy")
            {
                listView.Items.Clear();
                listView.Columns.Clear();
                ColumnHeader col1 = new ColumnHeader();
                col1.Width = 150;
                col1.Text = "Nazwisko";
                ColumnHeader col2 = new ColumnHeader();
                col2.Width = 150;
                col2.Text = "Imie";
                ColumnHeader col3 = new ColumnHeader();
                col3.Width = 150;
                col3.Text = "Data urodzenia";
                ColumnHeader col4 = new ColumnHeader();
                col4.Width = 150;
                col4.Text = "Adres";
                listView.Columns.Add(col1);
                listView.Columns.Add(col2);
                listView.Columns.Add(col3);
                listView.Columns.Add(col4);
                foreach ( var v in wykladowcaList){
                    string[] s = { v.imie, v.nazwisko, v.data, v.adres};
                    ListViewItem item1 = new ListViewItem(s);
                    listView.Items.Add(item1);
                }
            }
            if (Notification.TypeOfSelected == "Studenci")
            {
                listView.Items.Clear();
                listView.Columns.Clear();
                ColumnHeader col1 = new ColumnHeader();
                col1.Width = 150;
                col1.Text = "Nazwisko";
                ColumnHeader col2 = new ColumnHeader();
                col2.Width = 150;
                col2.Text = "Imie";
                ColumnHeader col3 = new ColumnHeader();
                col3.Width = 150;
                col3.Text = "Data urodzenia";
                ColumnHeader col4 = new ColumnHeader();
                col4.Width = 150;
                col4.Text = "Adres";
                listView.Columns.Add(col1);
                listView.Columns.Add(col2);
                listView.Columns.Add(col3);
                listView.Columns.Add(col4);
                foreach (var v in studentList)
                {
                    string[] s = {  v.imie, v.nazwisko, v.data, v.adres };
                    ListViewItem item1 = new ListViewItem(s);
                    listView.Items.Add(item1);
                }
            }
        }

        public void Handle(UserProfileSelectedNotification Notification)
        {
            
            listView.Items.Clear();
            listView.Columns.Clear();
            ColumnHeader col1 = new ColumnHeader();
            col1.Width = 150;
            col1.Text = "Ile zap³acono";
            ColumnHeader col2 = new ColumnHeader();
            col2.Width = 150;
            col2.Text = "Jaki cel op³aty";
            ColumnHeader col3 = new ColumnHeader();
            col3.Width = 150;
            col3.Text = "Czy zap³acone";
            listView.Columns.Add(col1);
            listView.Columns.Add(col2);
            listView.Columns.Add(col3);
            List<WpisWKartotece> lista = map[Notification.nameSelected + " " + Notification.surnameSelected];
            foreach(var w in lista)
            {
                 string[] s = { w.ile.ToString(), w.na_co, w.czy_zaplacone.ToString() };
                 ListViewItem item1 = new ListViewItem(s);
                 listView.Items.Add(item1);
            }
        }

        public void Handle(UserProfileAddedNotification Notification)
        {
            if (Notification.student)
            {
                studentList.Add(new Student(Notification.name,Notification.surname,Notification.date,Notification.adress));
                listView.Items.Clear();
                listView.Columns.Clear();
                ColumnHeader col1 = new ColumnHeader();
                col1.Width = 150;
                col1.Text = "Nazwisko";
                ColumnHeader col2 = new ColumnHeader();
                col2.Width = 150;
                col2.Text = "Imie";
                ColumnHeader col3 = new ColumnHeader();
                col3.Width = 150;
                col3.Text = "Data urodzenia";
                ColumnHeader col4 = new ColumnHeader();
                col4.Width = 150;
                col4.Text = "Adres";
                listView.Columns.Add(col1);
                listView.Columns.Add(col2);
                listView.Columns.Add(col3);
                listView.Columns.Add(col4);
                foreach (var v in studentList)
                {
                    string[] s = {  v.imie, v.nazwisko, v.data, v.adres };
                    ListViewItem item1 = new ListViewItem(s);
                    listView.Items.Add(item1);
                }
            }
            else
            {
                wykladowcaList.Add(new Wykladowca(Notification.name, Notification.surname, Notification.date, Notification.adress));
                listView.Items.Clear();
                listView.Columns.Clear();
                ColumnHeader col1 = new ColumnHeader();
                col1.Width = 150;
                col1.Text = "Nazwisko";
                ColumnHeader col2 = new ColumnHeader();
                col2.Width = 150;
                col2.Text = "Imie";
                ColumnHeader col3 = new ColumnHeader();
                col3.Width = 150;
                col3.Text = "Data urodzenia";
                ColumnHeader col4 = new ColumnHeader();
                col4.Width = 150;
                col4.Text = "Adres";
                listView.Columns.Add(col1);
                listView.Columns.Add(col2);
                listView.Columns.Add(col3);
                listView.Columns.Add(col4);
                foreach (var v in wykladowcaList)
                {
                    string[] s = {  v.imie, v.nazwisko, v.data, v.adres };
                    ListViewItem item1 = new ListViewItem(s);
                    listView.Items.Add(item1);
                }
            }
                
        }

        public void Handle(ModifyRecordNotification Notification)
        {
            if (Notification.deleting == true)
            {
                List<WpisWKartotece> listaa = map[treeView.SelectedNode.Text];
                listaa.RemoveAt(Notification.index);
            }
            else
            {
                List<WpisWKartotece> listaa = map[treeView.SelectedNode.Text];
                listaa[Notification.index].ile = Int32.Parse( Notification.ile );
                listaa[Notification.index].czy_zaplacone = Notification.czy_zap³acone;
                listaa[Notification.index].na_co = Notification.na_co;
            }
            

            listView.Items.Clear();
            listView.Columns.Clear();
            ColumnHeader col1 = new ColumnHeader();
            col1.Width = 150;
            col1.Text = "Ile zap³acono";
            ColumnHeader col2 = new ColumnHeader();
            col2.Width = 150;
            col2.Text = "Jaki cel op³aty";
            ColumnHeader col3 = new ColumnHeader();
            col3.Width = 150;
            col3.Text = "Czy zap³acone";
            listView.Columns.Add(col1);
            listView.Columns.Add(col2);
            listView.Columns.Add(col3);
            List<WpisWKartotece> lista = map[treeView.SelectedNode.Text];
            foreach (var w in lista)
            {
                string[] s = { w.ile.ToString(), w.na_co, w.czy_zaplacone.ToString() };
                ListViewItem item1 = new ListViewItem(s);
                listView.Items.Add(item1);
            }
        }
    }
}