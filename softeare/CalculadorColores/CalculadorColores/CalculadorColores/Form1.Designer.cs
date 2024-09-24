namespace CalculadorColores
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.panel4 = new System.Windows.Forms.Panel();
            this.trackBarRojo = new System.Windows.Forms.TrackBar();
            this.trackBarVerde = new System.Windows.Forms.TrackBar();
            this.trackBarAzul = new System.Windows.Forms.TrackBar();
            this.panel5 = new System.Windows.Forms.Panel();
            this.trackBarBrillo = new System.Windows.Forms.TrackBar();
            this.panel6 = new System.Windows.Forms.Panel();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarRojo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarVerde)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarAzul)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarBrillo)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.textBox2);
            this.panel1.Controls.Add(this.textBox1);
            this.panel1.Controls.Add(this.panel6);
            this.panel1.Controls.Add(this.trackBarBrillo);
            this.panel1.Controls.Add(this.panel5);
            this.panel1.Controls.Add(this.trackBarAzul);
            this.panel1.Controls.Add(this.trackBarVerde);
            this.panel1.Controls.Add(this.trackBarRojo);
            this.panel1.Controls.Add(this.panel4);
            this.panel1.Controls.Add(this.panel3);
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(892, 339);
            this.panel1.TabIndex = 0;
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.Red;
            this.panel2.Location = new System.Drawing.Point(12, 12);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(22, 22);
            this.panel2.TabIndex = 0;
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.Lime;
            this.panel3.Location = new System.Drawing.Point(12, 51);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(22, 22);
            this.panel3.TabIndex = 1;
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.Blue;
            this.panel4.Location = new System.Drawing.Point(12, 89);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(22, 22);
            this.panel4.TabIndex = 2;
            // 
            // trackBarRojo
            // 
            this.trackBarRojo.Location = new System.Drawing.Point(40, 12);
            this.trackBarRojo.Maximum = 255;
            this.trackBarRojo.Name = "trackBarRojo";
            this.trackBarRojo.Size = new System.Drawing.Size(610, 45);
            this.trackBarRojo.TabIndex = 3;
            this.trackBarRojo.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // trackBarVerde
            // 
            this.trackBarVerde.Location = new System.Drawing.Point(40, 51);
            this.trackBarVerde.Maximum = 255;
            this.trackBarVerde.Name = "trackBarVerde";
            this.trackBarVerde.Size = new System.Drawing.Size(610, 45);
            this.trackBarVerde.TabIndex = 4;
            this.trackBarVerde.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // trackBarAzul
            // 
            this.trackBarAzul.Location = new System.Drawing.Point(40, 89);
            this.trackBarAzul.Maximum = 255;
            this.trackBarAzul.Name = "trackBarAzul";
            this.trackBarAzul.Size = new System.Drawing.Size(610, 45);
            this.trackBarAzul.TabIndex = 5;
            this.trackBarAzul.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // panel5
            // 
            this.panel5.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel5.Location = new System.Drawing.Point(686, 20);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(86, 37);
            this.panel5.TabIndex = 6;
            // 
            // trackBarBrillo
            // 
            this.trackBarBrillo.Location = new System.Drawing.Point(40, 140);
            this.trackBarBrillo.Maximum = 255;
            this.trackBarBrillo.Name = "trackBarBrillo";
            this.trackBarBrillo.Size = new System.Drawing.Size(610, 45);
            this.trackBarBrillo.TabIndex = 7;
            this.trackBarBrillo.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // panel6
            // 
            this.panel6.BackColor = System.Drawing.Color.White;
            this.panel6.Location = new System.Drawing.Point(12, 140);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(22, 22);
            this.panel6.TabIndex = 8;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(672, 76);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 10;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(12, 191);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 11;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(142, 191);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 12;
            this.button1.Text = "Convertir";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(892, 450);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarRojo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarVerde)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarAzul)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarBrillo)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TrackBar trackBarAzul;
        private System.Windows.Forms.TrackBar trackBarVerde;
        private System.Windows.Forms.TrackBar trackBarRojo;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.TrackBar trackBarBrillo;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox2;
    }
}

