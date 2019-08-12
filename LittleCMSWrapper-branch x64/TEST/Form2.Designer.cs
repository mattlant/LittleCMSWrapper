namespace TEST
{
	partial class Form2
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
			this.lblInput = new System.Windows.Forms.Label();
			this.lblOuput = new System.Windows.Forms.Label();
			this.tbxInput = new System.Windows.Forms.TextBox();
			this.tbxOutput = new System.Windows.Forms.TextBox();
			this.btnInput = new System.Windows.Forms.Button();
			this.btnOutput = new System.Windows.Forms.Button();
			this.chkDefaultOutput = new System.Windows.Forms.CheckBox();
			this.chkInputProfile = new System.Windows.Forms.CheckBox();
			this.chkOutputProfile = new System.Windows.Forms.CheckBox();
			this.chkBlackPoint = new System.Windows.Forms.CheckBox();
			this.btnInputProfile = new System.Windows.Forms.Button();
			this.tbxInputProfile = new System.Windows.Forms.TextBox();
			this.btnOutputProfile = new System.Windows.Forms.Button();
			this.tbxOutputProfile = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.cbxIntent = new System.Windows.Forms.ComboBox();
			this.cbxBlackPreserve = new System.Windows.Forms.ComboBox();
			this.label2 = new System.Windows.Forms.Label();
			this.chkIgnoreEmbeded = new System.Windows.Forms.CheckBox();
			this.chkEmbedProfile = new System.Windows.Forms.CheckBox();
			this.chkSaveEmbeded = new System.Windows.Forms.CheckBox();
			this.btnSaveEmbedded = new System.Windows.Forms.Button();
			this.tbxSaveEmbedded = new System.Windows.Forms.TextBox();
			this.cbxPrecalcMode = new System.Windows.Forms.ComboBox();
			this.label3 = new System.Windows.Forms.Label();
			this.btnProofProfile = new System.Windows.Forms.Button();
			this.tbxProofProfile = new System.Windows.Forms.TextBox();
			this.chkProofProfile = new System.Windows.Forms.CheckBox();
			this.cbxSoftProofIntent = new System.Windows.Forms.ComboBox();
			this.label4 = new System.Windows.Forms.Label();
			this.chkGamutCheck = new System.Windows.Forms.CheckBox();
			this.nupJpgQuality = new System.Windows.Forms.NumericUpDown();
			this.label5 = new System.Windows.Forms.Label();
			this.chkDeviceLink = new System.Windows.Forms.CheckBox();
			this.btnDoTransform = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.nupJpgQuality)).BeginInit();
			this.SuspendLayout();
			// 
			// lblInput
			// 
			this.lblInput.AutoSize = true;
			this.lblInput.Location = new System.Drawing.Point(21, 22);
			this.lblInput.Name = "lblInput";
			this.lblInput.Size = new System.Drawing.Size(86, 13);
			this.lblInput.TabIndex = 0;
			this.lblInput.Text = "Select Input File:";
			// 
			// lblOuput
			// 
			this.lblOuput.AutoSize = true;
			this.lblOuput.Location = new System.Drawing.Point(13, 75);
			this.lblOuput.Name = "lblOuput";
			this.lblOuput.Size = new System.Drawing.Size(94, 13);
			this.lblOuput.TabIndex = 1;
			this.lblOuput.Text = "Select Output File:";
			// 
			// tbxInput
			// 
			this.tbxInput.Location = new System.Drawing.Point(113, 19);
			this.tbxInput.Name = "tbxInput";
			this.tbxInput.ReadOnly = true;
			this.tbxInput.Size = new System.Drawing.Size(219, 20);
			this.tbxInput.TabIndex = 2;
			// 
			// tbxOutput
			// 
			this.tbxOutput.Location = new System.Drawing.Point(113, 73);
			this.tbxOutput.Name = "tbxOutput";
			this.tbxOutput.ReadOnly = true;
			this.tbxOutput.Size = new System.Drawing.Size(219, 20);
			this.tbxOutput.TabIndex = 3;
			// 
			// btnInput
			// 
			this.btnInput.Location = new System.Drawing.Point(341, 20);
			this.btnInput.Name = "btnInput";
			this.btnInput.Size = new System.Drawing.Size(25, 20);
			this.btnInput.TabIndex = 4;
			this.btnInput.Text = "...";
			this.btnInput.UseVisualStyleBackColor = true;
			this.btnInput.Click += new System.EventHandler(this.btnInput_Click);
			// 
			// btnOutput
			// 
			this.btnOutput.Location = new System.Drawing.Point(341, 73);
			this.btnOutput.Name = "btnOutput";
			this.btnOutput.Size = new System.Drawing.Size(25, 20);
			this.btnOutput.TabIndex = 5;
			this.btnOutput.Text = "...";
			this.btnOutput.UseVisualStyleBackColor = true;
			// 
			// chkDefaultOutput
			// 
			this.chkDefaultOutput.AutoSize = true;
			this.chkDefaultOutput.Checked = true;
			this.chkDefaultOutput.CheckState = System.Windows.Forms.CheckState.Checked;
			this.chkDefaultOutput.Location = new System.Drawing.Point(27, 46);
			this.chkDefaultOutput.Name = "chkDefaultOutput";
			this.chkDefaultOutput.Size = new System.Drawing.Size(187, 17);
			this.chkDefaultOutput.TabIndex = 6;
			this.chkDefaultOutput.Text = "Default Output File (Recomended)";
			this.chkDefaultOutput.UseVisualStyleBackColor = true;
			this.chkDefaultOutput.CheckedChanged += new System.EventHandler(this.chkDefaultOutput_CheckedChanged);
			// 
			// chkInputProfile
			// 
			this.chkInputProfile.AutoSize = true;
			this.chkInputProfile.Location = new System.Drawing.Point(27, 172);
			this.chkInputProfile.Name = "chkInputProfile";
			this.chkInputProfile.Size = new System.Drawing.Size(104, 17);
			this.chkInputProfile.TabIndex = 7;
			this.chkInputProfile.Text = "Use Input Profile";
			this.chkInputProfile.UseVisualStyleBackColor = true;
			this.chkInputProfile.CheckedChanged += new System.EventHandler(this.chkInputProfile_CheckedChanged);
			// 
			// chkOutputProfile
			// 
			this.chkOutputProfile.AutoSize = true;
			this.chkOutputProfile.Location = new System.Drawing.Point(27, 223);
			this.chkOutputProfile.Name = "chkOutputProfile";
			this.chkOutputProfile.Size = new System.Drawing.Size(112, 17);
			this.chkOutputProfile.TabIndex = 8;
			this.chkOutputProfile.Text = "Use Output Profile";
			this.chkOutputProfile.UseVisualStyleBackColor = true;
			this.chkOutputProfile.CheckedChanged += new System.EventHandler(this.chkOutputProfile_CheckedChanged);
			// 
			// chkBlackPoint
			// 
			this.chkBlackPoint.AutoSize = true;
			this.chkBlackPoint.Location = new System.Drawing.Point(27, 354);
			this.chkBlackPoint.Name = "chkBlackPoint";
			this.chkBlackPoint.Size = new System.Drawing.Size(150, 17);
			this.chkBlackPoint.TabIndex = 9;
			this.chkBlackPoint.Text = "Black Point Compensation";
			this.chkBlackPoint.UseVisualStyleBackColor = true;
			// 
			// btnInputProfile
			// 
			this.btnInputProfile.Location = new System.Drawing.Point(375, 170);
			this.btnInputProfile.Name = "btnInputProfile";
			this.btnInputProfile.Size = new System.Drawing.Size(25, 20);
			this.btnInputProfile.TabIndex = 11;
			this.btnInputProfile.Text = "...";
			this.btnInputProfile.UseVisualStyleBackColor = true;
			this.btnInputProfile.Click += new System.EventHandler(this.btnInputProfile_Click);
			// 
			// tbxInputProfile
			// 
			this.tbxInputProfile.Location = new System.Drawing.Point(170, 170);
			this.tbxInputProfile.Name = "tbxInputProfile";
			this.tbxInputProfile.ReadOnly = true;
			this.tbxInputProfile.Size = new System.Drawing.Size(196, 20);
			this.tbxInputProfile.TabIndex = 10;
			// 
			// btnOutputProfile
			// 
			this.btnOutputProfile.Location = new System.Drawing.Point(375, 220);
			this.btnOutputProfile.Name = "btnOutputProfile";
			this.btnOutputProfile.Size = new System.Drawing.Size(25, 20);
			this.btnOutputProfile.TabIndex = 13;
			this.btnOutputProfile.Text = "...";
			this.btnOutputProfile.UseVisualStyleBackColor = true;
			this.btnOutputProfile.Click += new System.EventHandler(this.btnOutputProfile_Click);
			// 
			// tbxOutputProfile
			// 
			this.tbxOutputProfile.Location = new System.Drawing.Point(170, 220);
			this.tbxOutputProfile.Name = "tbxOutputProfile";
			this.tbxOutputProfile.ReadOnly = true;
			this.tbxOutputProfile.Size = new System.Drawing.Size(196, 20);
			this.tbxOutputProfile.TabIndex = 12;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(24, 286);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(34, 13);
			this.label1.TabIndex = 14;
			this.label1.Text = "Intent";
			// 
			// cbxIntent
			// 
			this.cbxIntent.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxIntent.FormattingEnabled = true;
			this.cbxIntent.Location = new System.Drawing.Point(170, 283);
			this.cbxIntent.Name = "cbxIntent";
			this.cbxIntent.Size = new System.Drawing.Size(196, 21);
			this.cbxIntent.TabIndex = 15;
			// 
			// cbxBlackPreserve
			// 
			this.cbxBlackPreserve.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxBlackPreserve.FormattingEnabled = true;
			this.cbxBlackPreserve.Location = new System.Drawing.Point(170, 388);
			this.cbxBlackPreserve.Name = "cbxBlackPreserve";
			this.cbxBlackPreserve.Size = new System.Drawing.Size(196, 21);
			this.cbxBlackPreserve.TabIndex = 17;
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(24, 391);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(140, 13);
			this.label2.TabIndex = 16;
			this.label2.Text = "Preserve Black (CMYK only)";
			// 
			// chkIgnoreEmbeded
			// 
			this.chkIgnoreEmbeded.AutoSize = true;
			this.chkIgnoreEmbeded.Location = new System.Drawing.Point(27, 426);
			this.chkIgnoreEmbeded.Name = "chkIgnoreEmbeded";
			this.chkIgnoreEmbeded.Size = new System.Drawing.Size(142, 17);
			this.chkIgnoreEmbeded.TabIndex = 18;
			this.chkIgnoreEmbeded.Text = "Ignore Embedded Profile";
			this.chkIgnoreEmbeded.UseVisualStyleBackColor = true;
			// 
			// chkEmbedProfile
			// 
			this.chkEmbedProfile.AutoSize = true;
			this.chkEmbedProfile.Location = new System.Drawing.Point(27, 464);
			this.chkEmbedProfile.Name = "chkEmbedProfile";
			this.chkEmbedProfile.Size = new System.Drawing.Size(145, 17);
			this.chkEmbedProfile.TabIndex = 19;
			this.chkEmbedProfile.Text = "Embed destination Profile";
			this.chkEmbedProfile.UseVisualStyleBackColor = true;
			// 
			// chkSaveEmbeded
			// 
			this.chkSaveEmbeded.AutoSize = true;
			this.chkSaveEmbeded.Location = new System.Drawing.Point(27, 501);
			this.chkSaveEmbeded.Name = "chkSaveEmbeded";
			this.chkSaveEmbeded.Size = new System.Drawing.Size(137, 17);
			this.chkSaveEmbeded.TabIndex = 20;
			this.chkSaveEmbeded.Text = "Save Embedded Profile";
			this.chkSaveEmbeded.UseVisualStyleBackColor = true;
			this.chkSaveEmbeded.CheckedChanged += new System.EventHandler(this.chkSaveEmbeded_CheckedChanged);
			// 
			// btnSaveEmbedded
			// 
			this.btnSaveEmbedded.Location = new System.Drawing.Point(375, 499);
			this.btnSaveEmbedded.Name = "btnSaveEmbedded";
			this.btnSaveEmbedded.Size = new System.Drawing.Size(25, 20);
			this.btnSaveEmbedded.TabIndex = 22;
			this.btnSaveEmbedded.Text = "...";
			this.btnSaveEmbedded.UseVisualStyleBackColor = true;
			// 
			// tbxSaveEmbedded
			// 
			this.tbxSaveEmbedded.Location = new System.Drawing.Point(170, 499);
			this.tbxSaveEmbedded.Name = "tbxSaveEmbedded";
			this.tbxSaveEmbedded.ReadOnly = true;
			this.tbxSaveEmbedded.Size = new System.Drawing.Size(196, 20);
			this.tbxSaveEmbedded.TabIndex = 21;
			// 
			// cbxPrecalcMode
			// 
			this.cbxPrecalcMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxPrecalcMode.FormattingEnabled = true;
			this.cbxPrecalcMode.Location = new System.Drawing.Point(170, 541);
			this.cbxPrecalcMode.Name = "cbxPrecalcMode";
			this.cbxPrecalcMode.Size = new System.Drawing.Size(196, 21);
			this.cbxPrecalcMode.TabIndex = 24;
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(24, 544);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(121, 13);
			this.label3.TabIndex = 23;
			this.label3.Text = "Precalculates Transform";
			// 
			// btnProofProfile
			// 
			this.btnProofProfile.Location = new System.Drawing.Point(375, 249);
			this.btnProofProfile.Name = "btnProofProfile";
			this.btnProofProfile.Size = new System.Drawing.Size(25, 20);
			this.btnProofProfile.TabIndex = 29;
			this.btnProofProfile.Text = "...";
			this.btnProofProfile.UseVisualStyleBackColor = true;
			this.btnProofProfile.Click += new System.EventHandler(this.btnProofProfile_Click);
			// 
			// tbxProofProfile
			// 
			this.tbxProofProfile.Location = new System.Drawing.Point(170, 249);
			this.tbxProofProfile.Name = "tbxProofProfile";
			this.tbxProofProfile.ReadOnly = true;
			this.tbxProofProfile.Size = new System.Drawing.Size(196, 20);
			this.tbxProofProfile.TabIndex = 28;
			// 
			// chkProofProfile
			// 
			this.chkProofProfile.AutoSize = true;
			this.chkProofProfile.Location = new System.Drawing.Point(27, 251);
			this.chkProofProfile.Name = "chkProofProfile";
			this.chkProofProfile.Size = new System.Drawing.Size(127, 17);
			this.chkProofProfile.TabIndex = 27;
			this.chkProofProfile.Text = "Use Soft Proof Profile";
			this.chkProofProfile.UseVisualStyleBackColor = true;
			this.chkProofProfile.CheckedChanged += new System.EventHandler(this.chkProofProfile_CheckedChanged);
			// 
			// cbxSoftProofIntent
			// 
			this.cbxSoftProofIntent.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxSoftProofIntent.FormattingEnabled = true;
			this.cbxSoftProofIntent.Location = new System.Drawing.Point(170, 312);
			this.cbxSoftProofIntent.Name = "cbxSoftProofIntent";
			this.cbxSoftProofIntent.Size = new System.Drawing.Size(196, 21);
			this.cbxSoftProofIntent.TabIndex = 31;
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(24, 315);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(84, 13);
			this.label4.TabIndex = 30;
			this.label4.Text = "Soft Proof Intent";
			// 
			// chkGamutCheck
			// 
			this.chkGamutCheck.AutoSize = true;
			this.chkGamutCheck.Location = new System.Drawing.Point(27, 585);
			this.chkGamutCheck.Name = "chkGamutCheck";
			this.chkGamutCheck.Size = new System.Drawing.Size(206, 17);
			this.chkGamutCheck.TabIndex = 32;
			this.chkGamutCheck.Text = "Marks out-of-gamut colors in soft proof";
			this.chkGamutCheck.UseVisualStyleBackColor = true;
			// 
			// nupJpgQuality
			// 
			this.nupJpgQuality.Location = new System.Drawing.Point(134, 617);
			this.nupJpgQuality.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
			this.nupJpgQuality.Name = "nupJpgQuality";
			this.nupJpgQuality.Size = new System.Drawing.Size(43, 20);
			this.nupJpgQuality.TabIndex = 33;
			this.nupJpgQuality.Value = new decimal(new int[] {
            75,
            0,
            0,
            0});
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(27, 619);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(101, 13);
			this.label5.TabIndex = 34;
			this.label5.Text = "Jpeg Saving Quality";
			// 
			// chkDeviceLink
			// 
			this.chkDeviceLink.AutoSize = true;
			this.chkDeviceLink.Location = new System.Drawing.Point(50, 195);
			this.chkDeviceLink.Name = "chkDeviceLink";
			this.chkDeviceLink.Size = new System.Drawing.Size(112, 17);
			this.chkDeviceLink.TabIndex = 35;
			this.chkDeviceLink.Text = "as a Device Link?";
			this.chkDeviceLink.UseVisualStyleBackColor = true;
			// 
			// btnDoTransform
			// 
			this.btnDoTransform.Location = new System.Drawing.Point(262, 119);
			this.btnDoTransform.Name = "btnDoTransform";
			this.btnDoTransform.Size = new System.Drawing.Size(104, 23);
			this.btnDoTransform.TabIndex = 36;
			this.btnDoTransform.Text = "Do Transform";
			this.btnDoTransform.UseVisualStyleBackColor = true;
			this.btnDoTransform.Click += new System.EventHandler(this.btnDoTransform_Click);
			// 
			// Form2
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1095, 656);
			this.Controls.Add(this.btnDoTransform);
			this.Controls.Add(this.chkDeviceLink);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.nupJpgQuality);
			this.Controls.Add(this.chkGamutCheck);
			this.Controls.Add(this.cbxSoftProofIntent);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.btnProofProfile);
			this.Controls.Add(this.tbxProofProfile);
			this.Controls.Add(this.chkProofProfile);
			this.Controls.Add(this.cbxPrecalcMode);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.btnSaveEmbedded);
			this.Controls.Add(this.tbxSaveEmbedded);
			this.Controls.Add(this.chkSaveEmbeded);
			this.Controls.Add(this.chkEmbedProfile);
			this.Controls.Add(this.chkIgnoreEmbeded);
			this.Controls.Add(this.cbxBlackPreserve);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.cbxIntent);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.btnOutputProfile);
			this.Controls.Add(this.tbxOutputProfile);
			this.Controls.Add(this.btnInputProfile);
			this.Controls.Add(this.tbxInputProfile);
			this.Controls.Add(this.chkBlackPoint);
			this.Controls.Add(this.chkOutputProfile);
			this.Controls.Add(this.chkInputProfile);
			this.Controls.Add(this.chkDefaultOutput);
			this.Controls.Add(this.btnOutput);
			this.Controls.Add(this.btnInput);
			this.Controls.Add(this.tbxOutput);
			this.Controls.Add(this.tbxInput);
			this.Controls.Add(this.lblOuput);
			this.Controls.Add(this.lblInput);
			this.Name = "Form2";
			this.Text = "Form2";
			this.Load += new System.EventHandler(this.Form2_Load);
			((System.ComponentModel.ISupportInitialize)(this.nupJpgQuality)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label lblInput;
		private System.Windows.Forms.Label lblOuput;
		private System.Windows.Forms.TextBox tbxInput;
		private System.Windows.Forms.TextBox tbxOutput;
		private System.Windows.Forms.Button btnInput;
		private System.Windows.Forms.Button btnOutput;
		private System.Windows.Forms.CheckBox chkDefaultOutput;
		private System.Windows.Forms.CheckBox chkInputProfile;
		private System.Windows.Forms.CheckBox chkOutputProfile;
		private System.Windows.Forms.CheckBox chkBlackPoint;
		private System.Windows.Forms.Button btnInputProfile;
		private System.Windows.Forms.TextBox tbxInputProfile;
		private System.Windows.Forms.Button btnOutputProfile;
		private System.Windows.Forms.TextBox tbxOutputProfile;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.ComboBox cbxIntent;
		private System.Windows.Forms.ComboBox cbxBlackPreserve;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.CheckBox chkIgnoreEmbeded;
		private System.Windows.Forms.CheckBox chkEmbedProfile;
		private System.Windows.Forms.CheckBox chkSaveEmbeded;
		private System.Windows.Forms.Button btnSaveEmbedded;
		private System.Windows.Forms.TextBox tbxSaveEmbedded;
		private System.Windows.Forms.ComboBox cbxPrecalcMode;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Button btnProofProfile;
		private System.Windows.Forms.TextBox tbxProofProfile;
		private System.Windows.Forms.CheckBox chkProofProfile;
		private System.Windows.Forms.ComboBox cbxSoftProofIntent;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.CheckBox chkGamutCheck;
		private System.Windows.Forms.NumericUpDown nupJpgQuality;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.CheckBox chkDeviceLink;
		private System.Windows.Forms.Button btnDoTransform;
	}
}