using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;   
namespace PCL_surface
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\PLY_reader_viewer.exe");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\PLY_Statistical_Filters.exe");
        }

 

        private void button1_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\Filters_Passthrough.exe");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\Filters_voxel_grid.exe");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\Filters_radius_outlier_removal");  
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\Filters_conditional_removal");  
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\PCLtry_ICP_auto.exe");  
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\PCLtry_Statistical_Filters_batch.exe"); 
        }

        private void button6_Click_1(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\PLYtry_ICP.exe"); 
        }

        private void button8_Click_1(object sender, EventArgs e)
        {
            Process.Start(@"E:\graduating_design\PCLTest\PCL_transform_viewer"); 
        }


  
    }
}
