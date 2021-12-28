
namespace Zadanie2
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.ListViewGroup listViewGroup1 = new System.Windows.Forms.ListViewGroup("Imie", System.Windows.Forms.HorizontalAlignment.Left);
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Syn");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Rodzic", new System.Windows.Forms.TreeNode[] {
            treeNode1});
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Wujek");
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Dziadek", new System.Windows.Forms.TreeNode[] {
            treeNode2,
            treeNode3});
            this.Lista = new System.Windows.Forms.ListView();
            this.Imie = new System.Windows.Forms.ColumnHeader();
            this.Nazwisko = new System.Windows.Forms.ColumnHeader();
            this.Wzrost = new System.Windows.Forms.ColumnHeader();
            this.name = new System.Windows.Forms.TextBox();
            this.surname = new System.Windows.Forms.TextBox();
            this.height = new System.Windows.Forms.TextBox();
            this.button = new System.Windows.Forms.Button();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.up = new System.Windows.Forms.Button();
            this.down = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Lista
            // 
            this.Lista.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.Imie,
            this.Nazwisko,
            this.Wzrost});
            this.Lista.GridLines = true;
            listViewGroup1.Header = "Imie";
            listViewGroup1.Name = "Imie";
            this.Lista.Groups.AddRange(new System.Windows.Forms.ListViewGroup[] {
            listViewGroup1});
            this.Lista.HideSelection = false;
            this.Lista.Location = new System.Drawing.Point(12, 12);
            this.Lista.Name = "Lista";
            this.Lista.Size = new System.Drawing.Size(218, 230);
            this.Lista.TabIndex = 0;
            this.Lista.UseCompatibleStateImageBehavior = false;
            this.Lista.View = System.Windows.Forms.View.Details;
            // 
            // Imie
            // 
            this.Imie.Text = "Imie";
            // 
            // Nazwisko
            // 
            this.Nazwisko.Text = "Nazwisko";
            this.Nazwisko.Width = 100;
            // 
            // Wzrost
            // 
            this.Wzrost.Text = "Wzrost";
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(302, 13);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(120, 23);
            this.name.TabIndex = 1;
            // 
            // surname
            // 
            this.surname.Location = new System.Drawing.Point(302, 42);
            this.surname.Name = "surname";
            this.surname.Size = new System.Drawing.Size(120, 23);
            this.surname.TabIndex = 2;
            // 
            // height
            // 
            this.height.Location = new System.Drawing.Point(302, 71);
            this.height.Name = "height";
            this.height.Size = new System.Drawing.Size(120, 23);
            this.height.TabIndex = 3;
            // 
            // button
            // 
            this.button.Location = new System.Drawing.Point(448, 34);
            this.button.Name = "button";
            this.button.Size = new System.Drawing.Size(103, 36);
            this.button.TabIndex = 4;
            this.button.Text = "dodaj";
            this.button.UseVisualStyleBackColor = true;
            this.button.Click += new System.EventHandler(this.button_Click);
            // 
            // treeView1
            // 
            this.treeView1.Location = new System.Drawing.Point(13, 249);
            this.treeView1.Name = "treeView1";
            treeNode1.Name = "Node3";
            treeNode1.Text = "Syn";
            treeNode2.Name = "Node1";
            treeNode2.Text = "Rodzic";
            treeNode3.Name = "Node2";
            treeNode3.Text = "Wujek";
            treeNode4.Name = "Node0";
            treeNode4.Text = "Dziadek";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode4});
            this.treeView1.Size = new System.Drawing.Size(162, 81);
            this.treeView1.TabIndex = 5;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(448, 274);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(121, 38);
            this.button1.TabIndex = 6;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(261, 285);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(181, 23);
            this.textBox1.TabIndex = 7;
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(13, 408);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(162, 23);
            this.progressBar1.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.progressBar1.TabIndex = 8;
            this.progressBar1.UseWaitCursor = true;
            // 
            // up
            // 
            this.up.Location = new System.Drawing.Point(448, 408);
            this.up.Name = "up";
            this.up.Size = new System.Drawing.Size(75, 23);
            this.up.TabIndex = 9;
            this.up.Text = "up";
            this.up.UseVisualStyleBackColor = true;
            this.up.Click += new System.EventHandler(this.up_Click);
            // 
            // down
            // 
            this.down.Location = new System.Drawing.Point(367, 408);
            this.down.Name = "down";
            this.down.Size = new System.Drawing.Size(75, 23);
            this.down.TabIndex = 10;
            this.down.Text = "down";
            this.down.UseVisualStyleBackColor = true;
            this.down.Click += new System.EventHandler(this.down_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 704);
            this.Controls.Add(this.down);
            this.Controls.Add(this.up);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.treeView1);
            this.Controls.Add(this.button);
            this.Controls.Add(this.height);
            this.Controls.Add(this.surname);
            this.Controls.Add(this.name);
            this.Controls.Add(this.Lista);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView Lista;
        private System.Windows.Forms.ColumnHeader Imie;
        private System.Windows.Forms.ColumnHeader Nazwisko;
        private System.Windows.Forms.ColumnHeader Wzrost;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.TextBox surname;
        private System.Windows.Forms.TextBox height;
        private System.Windows.Forms.Button button;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Button up;
        private System.Windows.Forms.Button down;
    }
}

