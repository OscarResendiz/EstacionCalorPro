using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CalculadorColores
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            Color myRgbColor = new Color();
            myRgbColor = Color.FromArgb(trackBarBrillo.Value, trackBarRojo.Value, trackBarVerde.Value, trackBarAzul.Value);
            panel5.BackColor = myRgbColor;
            int r = calcula(trackBarRojo.Value);
            int g = calcula(trackBarVerde.Value);
            int b = calcula(trackBarAzul.Value);
            int a = calcula(trackBarBrillo.Value);
            string hexValue = r.ToString("X") + g.ToString("X") + b.ToString("X") + a.ToString("X") ;
            textBox1.Text ="0X"+ hexValue;
            //            panel5.Refresh();
            //          pictureBox1.BackColor = Color.FromArgb(trackBarBrillo.Value, trackBarRojo.Value, trackBarVerde.Value, trackBarAzul.Value); 
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Color myRgbColor = new Color();
            myRgbColor = Color.FromArgb(0, 255, 0);
            panel5.BackColor= myRgbColor;
            trackBar1_Scroll(null, null);
        }
        int calcula(int v)
        {
            return v * 16 / 256;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string r,g,b;
            r = textBox2.Text.Substring(0, 2);
            g = textBox2.Text.Substring(2, 2);
            b = textBox2.Text.Substring(4, 2);
            int vr = Convert.ToInt32(r, 16);
            int vg = Convert.ToInt32(g, 16);
            int vb = Convert.ToInt32(b, 16);
            trackBarRojo.Value = vr;
            trackBarVerde.Value = vg;
            trackBarAzul.Value = vb;
            trackBar1_Scroll(null, null);
        }
    }
}
