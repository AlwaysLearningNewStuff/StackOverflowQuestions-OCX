using System;
using System.Runtime.InteropServices;
using System.Security;
using System.Windows.Forms;

namespace OCXTesterCS
{
    public partial class OCXTester : Form
    {
        private enum COMMAND { ADD = 0, READ, WRITE, CLEAR }

        private COMMAND Choice { get; set; }

        public OCXTester()
        {
            InitializeComponent();
            comboBox.SelectedIndex = 0;
        }

        private void ButtonExecuteCommand_Click(object sender, EventArgs e)
        {
            textBoxLog.Text = "";
            statusStrip.Items[0].Text = "";
            //m_OCX.FileName = "";
            // var ret;
            switch (Choice)
            {
                case COMMAND.ADD:
                    axDemoOCX1.AddTestImages();
                    break;
                case COMMAND.READ:
                    {
                        if (openFileDialog.ShowDialog() == DialogResult.OK)
                        {
                            try
                            {
                                statusStrip.Items[0].Text = "File path: " + openFileDialog.FileName;
                                textBoxLog.Text = "Success";
                            }
                            catch (SecurityException ex)
                            {
                                textBoxLog.Text = ex.Message + Environment.NewLine;
                                textBoxLog.Text += "Stack trace:" + Environment.NewLine + ex.StackTrace + Environment.NewLine;
                            }

                            int ret = axDemoOCX1.ImportImageList(openFileDialog.FileName);
                            
                            if(ret < 0)
                            {
                                textBoxLog.Text = "Error = " + ret.ToString() + Environment.NewLine;
                            }
                        }
                    }
                    break;
                case COMMAND.WRITE:
                    {
                        if (saveFileDialog.ShowDialog() == DialogResult.OK)
                        {
                            try
                            {
                                statusStrip.Items[0].Text = "File path: " + saveFileDialog.FileName;
                                textBoxLog.Text = "Success";
                            }
                            catch (SecurityException ex)
                            {
                                textBoxLog.Text = ex.Message + Environment.NewLine;
                                textBoxLog.Text += "Stack trace:" + Environment.NewLine + ex.StackTrace + Environment.NewLine;
                            }

                            int ret = axDemoOCX1.ExportImageListToFile(saveFileDialog.FileName);

                            if (ret < 0)
                            {
                                textBoxLog.Text = "Error = " + ret.ToString() + Environment.NewLine;
                            }
                        }
                    }
                    break;
                case COMMAND.CLEAR:
                    axDemoOCX1.EmptyImageList();
                    break;
                default:
                    break;
            }
        }

        private void ComboBox_SelectionChangeCommitted(object sender, EventArgs e)
        {
            Choice = (COMMAND)comboBox.SelectedIndex;
        }

    }
}
