namespace OCXTesterCS
{
    partial class OCXTester
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(OCXTester));
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.comboBox = new System.Windows.Forms.ComboBox();
            this.buttonExecuteCommand = new System.Windows.Forms.Button();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.textBoxLog = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.axDemoOCX1 = new AxDemoOCXLib.AxDemoOCX();
            this.statusStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axDemoOCX1)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileDialog
            // 
            this.openFileDialog.DefaultExt = "zlib";
            this.openFileDialog.Filter = "ZLib files|*.zlib|All files|*.*";
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.DefaultExt = "zlib";
            this.saveFileDialog.Filter = "ZLib files|*.zlib|All files|*.*";
            // 
            // comboBox
            // 
            this.comboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox.FormattingEnabled = true;
            this.comboBox.Items.AddRange(new object[] {
            "Add test images",
            "Import image list ",
            "Export image list",
            "Delete all images"});
            this.comboBox.Location = new System.Drawing.Point(15, 258);
            this.comboBox.Name = "comboBox";
            this.comboBox.Size = new System.Drawing.Size(154, 21);
            this.comboBox.TabIndex = 1;
            this.comboBox.SelectionChangeCommitted += new System.EventHandler(this.ComboBox_SelectionChangeCommitted);
            // 
            // buttonExecuteCommand
            // 
            this.buttonExecuteCommand.AutoSize = true;
            this.buttonExecuteCommand.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.buttonExecuteCommand.Location = new System.Drawing.Point(210, 258);
            this.buttonExecuteCommand.Name = "buttonExecuteCommand";
            this.buttonExecuteCommand.Size = new System.Drawing.Size(56, 23);
            this.buttonExecuteCommand.TabIndex = 5;
            this.buttonExecuteCommand.Text = "Execute";
            this.buttonExecuteCommand.UseVisualStyleBackColor = true;
            this.buttonExecuteCommand.Click += new System.EventHandler(this.ButtonExecuteCommand_Click);
            // 
            // statusStrip
            // 
            this.statusStrip.ImageScalingSize = new System.Drawing.Size(24, 24);
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel});
            this.statusStrip.Location = new System.Drawing.Point(0, 290);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(278, 22);
            this.statusStrip.SizingGrip = false;
            this.statusStrip.TabIndex = 31;
            // 
            // toolStripStatusLabel
            // 
            this.toolStripStatusLabel.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.toolStripStatusLabel.Name = "toolStripStatusLabel";
            this.toolStripStatusLabel.Size = new System.Drawing.Size(263, 17);
            this.toolStripStatusLabel.Spring = true;
            this.toolStripStatusLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // textBoxLog
            // 
            this.textBoxLog.Location = new System.Drawing.Point(15, 164);
            this.textBoxLog.Multiline = true;
            this.textBoxLog.Name = "textBoxLog";
            this.textBoxLog.ReadOnly = true;
            this.textBoxLog.Size = new System.Drawing.Size(251, 86);
            this.textBoxLog.TabIndex = 4;
            this.textBoxLog.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 148);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 30;
            this.label1.Text = "Error log:";
            // 
            // axDemoOCX1
            // 
            this.axDemoOCX1.Enabled = true;
            this.axDemoOCX1.Location = new System.Drawing.Point(12, 12);
            this.axDemoOCX1.Name = "axDemoOCX1";
            this.axDemoOCX1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axDemoOCX1.OcxState")));
            this.axDemoOCX1.Size = new System.Drawing.Size(254, 128);
            this.axDemoOCX1.TabIndex = 32;
            // 
            // OCXTester
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(278, 312);
            this.Controls.Add(this.axDemoOCX1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxLog);
            this.Controls.Add(this.statusStrip);
            this.Controls.Add(this.buttonExecuteCommand);
            this.Controls.Add(this.comboBox);
            this.Name = "OCXTester";
            this.Text = "OCX Tester";
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axDemoOCX1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.ComboBox comboBox;
        private System.Windows.Forms.Button buttonExecuteCommand;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel;
        private System.Windows.Forms.TextBox textBoxLog;
        private System.Windows.Forms.Label label1;
        private AxDemoOCXLib.AxDemoOCX axDemoOCX1;
    }
}

