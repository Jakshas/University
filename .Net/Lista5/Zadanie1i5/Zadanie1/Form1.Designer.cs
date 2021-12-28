
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
            this.Uczelnia = new System.Windows.Forms.GroupBox();
            this.Adres = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.Nazwa = new System.Windows.Forms.Label();
            this.Studia = new System.Windows.Forms.GroupBox();
            this.uzupelniajace = new System.Windows.Forms.CheckBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.Cykl = new System.Windows.Forms.Label();
            this.Lata = new System.Windows.Forms.ComboBox();
            this.Akceptuj = new System.Windows.Forms.Button();
            this.Anuluj = new System.Windows.Forms.Button();
            this.helpNazwa = new System.Windows.Forms.HelpProvider();
            this.Pomoc = new System.Windows.Forms.Button();
            this.Uczelnia.SuspendLayout();
            this.Studia.SuspendLayout();
            this.SuspendLayout();
            // 
            // Uczelnia
            // 
            this.Uczelnia.Controls.Add(this.Adres);
            this.Uczelnia.Controls.Add(this.textBox2);
            this.Uczelnia.Controls.Add(this.textBox1);
            this.Uczelnia.Controls.Add(this.Nazwa);
            this.Uczelnia.Location = new System.Drawing.Point(12, 12);
            this.Uczelnia.Name = "Uczelnia";
            this.Uczelnia.Size = new System.Drawing.Size(503, 127);
            this.Uczelnia.TabIndex = 0;
            this.Uczelnia.TabStop = false;
            this.Uczelnia.Text = "Uczelnia";
            // 
            // Adres
            // 
            this.Adres.AutoSize = true;
            this.Adres.Location = new System.Drawing.Point(7, 66);
            this.Adres.Name = "Adres";
            this.Adres.Size = new System.Drawing.Size(40, 15);
            this.Adres.TabIndex = 3;
            this.Adres.Text = "Adres:";
            // 
            // textBox2
            // 
            this.helpNazwa.SetHelpKeyword(this.textBox2, "Adres");
            this.textBox2.Location = new System.Drawing.Point(55, 63);
            this.textBox2.Name = "textBox2";
            this.helpNazwa.SetShowHelp(this.textBox2, true);
            this.textBox2.Size = new System.Drawing.Size(414, 23);
            this.textBox2.TabIndex = 2;
            // 
            // textBox1
            // 
            this.helpNazwa.SetHelpKeyword(this.textBox1, "Nazwa");
            this.textBox1.Location = new System.Drawing.Point(55, 20);
            this.textBox1.Name = "textBox1";
            this.helpNazwa.SetShowHelp(this.textBox1, true);
            this.textBox1.Size = new System.Drawing.Size(414, 23);
            this.textBox1.TabIndex = 1;
            // 
            // Nazwa
            // 
            this.Nazwa.AutoSize = true;
            this.Nazwa.Location = new System.Drawing.Point(7, 23);
            this.Nazwa.Name = "Nazwa";
            this.Nazwa.Size = new System.Drawing.Size(45, 15);
            this.Nazwa.TabIndex = 0;
            this.Nazwa.Text = "Nazwa:";
            // 
            // Studia
            // 
            this.Studia.Controls.Add(this.uzupelniajace);
            this.Studia.Controls.Add(this.checkBox1);
            this.Studia.Controls.Add(this.Cykl);
            this.Studia.Controls.Add(this.Lata);
            this.Studia.Location = new System.Drawing.Point(12, 145);
            this.Studia.Name = "Studia";
            this.Studia.Size = new System.Drawing.Size(502, 126);
            this.Studia.TabIndex = 1;
            this.Studia.TabStop = false;
            this.Studia.Text = "Rodzaj studiów";
            this.Studia.Enter += new System.EventHandler(this.Studia_Enter);
            // 
            // uzupelniajace
            // 
            this.uzupelniajace.AutoSize = true;
            this.uzupelniajace.Location = new System.Drawing.Point(151, 52);
            this.uzupelniajace.Name = "uzupelniajace";
            this.uzupelniajace.Size = new System.Drawing.Size(98, 19);
            this.uzupelniajace.TabIndex = 3;
            this.uzupelniajace.Text = "uzupełniajace";
            this.uzupelniajace.UseVisualStyleBackColor = true;
            this.uzupelniajace.Click += new System.EventHandler(this.uzupelniajace_Click);
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Checked = true;
            this.checkBox1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox1.Location = new System.Drawing.Point(77, 52);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(67, 19);
            this.checkBox1.TabIndex = 2;
            this.checkBox1.Text = "dzienne";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.Click += new System.EventHandler(this.checkBox1_Click);
            // 
            // Cykl
            // 
            this.Cykl.AutoSize = true;
            this.Cykl.Location = new System.Drawing.Point(6, 25);
            this.Cykl.Name = "Cykl";
            this.Cykl.Size = new System.Drawing.Size(65, 15);
            this.Cykl.TabIndex = 1;
            this.Cykl.Text = "Cykl nauki:";
            // 
            // Lata
            // 
            this.Lata.FormattingEnabled = true;
            this.helpNazwa.SetHelpKeyword(this.Lata, "Cykl");
            this.Lata.Items.AddRange(new object[] {
            "licencjackie",
            "inzynierskie",
            "magisterskie"});
            this.Lata.Location = new System.Drawing.Point(77, 22);
            this.Lata.Name = "Lata";
            this.helpNazwa.SetShowHelp(this.Lata, true);
            this.Lata.Size = new System.Drawing.Size(392, 23);
            this.Lata.TabIndex = 0;
            // 
            // Akceptuj
            // 
            this.Akceptuj.Location = new System.Drawing.Point(12, 277);
            this.Akceptuj.Name = "Akceptuj";
            this.Akceptuj.Size = new System.Drawing.Size(75, 23);
            this.Akceptuj.TabIndex = 2;
            this.Akceptuj.Text = "Akceptuj";
            this.Akceptuj.UseVisualStyleBackColor = true;
            this.Akceptuj.Click += new System.EventHandler(this.Akceptuj_Click);
            // 
            // Anuluj
            // 
            this.Anuluj.Location = new System.Drawing.Point(439, 277);
            this.Anuluj.Name = "Anuluj";
            this.Anuluj.Size = new System.Drawing.Size(75, 23);
            this.Anuluj.TabIndex = 3;
            this.Anuluj.Text = "Anuluj";
            this.Anuluj.UseVisualStyleBackColor = true;
            this.Anuluj.Click += new System.EventHandler(this.Anuluj_Click);
            // 
            // helpNazwa
            // 
            this.helpNazwa.HelpNamespace = "C:\\Projekty\\University\\dotNet\\Lista5\\Zadanie1i5\\Pomoc.chm";
            this.helpNazwa.Tag = "";
            // 
            // Pomoc
            // 
            this.Pomoc.Location = new System.Drawing.Point(358, 276);
            this.Pomoc.Name = "Pomoc";
            this.Pomoc.Size = new System.Drawing.Size(75, 23);
            this.Pomoc.TabIndex = 4;
            this.Pomoc.Text = "Pomoc";
            this.Pomoc.UseVisualStyleBackColor = true;
            this.Pomoc.Click += new System.EventHandler(this.Pomoc_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(528, 311);
            this.Controls.Add(this.Pomoc);
            this.Controls.Add(this.Anuluj);
            this.Controls.Add(this.Akceptuj);
            this.Controls.Add(this.Studia);
            this.Controls.Add(this.Uczelnia);
            this.HelpButton = true;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.helpNazwa.SetShowHelp(this, true);
            this.Text = "Aplikacja";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Uczelnia.ResumeLayout(false);
            this.Uczelnia.PerformLayout();
            this.Studia.ResumeLayout(false);
            this.Studia.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox Uczelnia;
        private System.Windows.Forms.GroupBox Studia;
        private System.Windows.Forms.Button Akceptuj;
        private System.Windows.Forms.Button Anuluj;
        private System.Windows.Forms.ComboBox Lata;
        private System.Windows.Forms.Label Cykl;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.Label Nazwa;
        private System.Windows.Forms.Label Adres;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.CheckBox uzupelniajace;
        private System.Windows.Forms.HelpProvider helpNazwa;
        private System.Windows.Forms.Button Pomoc;
    }
}

