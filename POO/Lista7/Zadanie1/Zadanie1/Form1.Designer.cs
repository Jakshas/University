namespace Zadanie1
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
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Studenci");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Wykładowcy");
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.listView1 = new System.Windows.Forms.ListView();
            this.zmien = new System.Windows.Forms.Button();
            this.dodaj = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // treeView1
            // 
            this.treeView1.Location = new System.Drawing.Point(0, -2);
            this.treeView1.Name = "treeView1";
            treeNode1.Name = "Studenci";
            treeNode1.Tag = "Studenci";
            treeNode1.Text = "Studenci";
            treeNode2.Name = "Wykładowcy";
            treeNode2.Text = "Wykładowcy";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2});
            this.treeView1.Size = new System.Drawing.Size(179, 413);
            this.treeView1.TabIndex = 0;
            this.treeView1.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterSelect);
            // 
            // listView1
            // 
            this.listView1.Location = new System.Drawing.Point(185, -2);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(615, 413);
            this.listView1.TabIndex = 1;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            // 
            // zmien
            // 
            this.zmien.Location = new System.Drawing.Point(185, 417);
            this.zmien.Name = "zmien";
            this.zmien.Size = new System.Drawing.Size(75, 23);
            this.zmien.TabIndex = 2;
            this.zmien.Text = "Zmień";
            this.zmien.UseVisualStyleBackColor = true;
            this.zmien.Click += new System.EventHandler(this.button1_Click);
            // 
            // dodaj
            // 
            this.dodaj.Location = new System.Drawing.Point(6, 417);
            this.dodaj.Name = "dodaj";
            this.dodaj.Size = new System.Drawing.Size(75, 23);
            this.dodaj.TabIndex = 3;
            this.dodaj.Text = "Dodaj";
            this.dodaj.UseVisualStyleBackColor = true;
            this.dodaj.Click += new System.EventHandler(this.dodaj_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.dodaj);
            this.Controls.Add(this.zmien);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.treeView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        public TreeView treeView1;
        public ListView listView1;
        private Button zmien;
        private Button dodaj;
    }
}