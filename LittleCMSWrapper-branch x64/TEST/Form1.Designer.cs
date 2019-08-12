namespace TEST
{
    partial class Form1
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
			this.btnApplyProfile = new System.Windows.Forms.Button();
			this.btnOpen = new System.Windows.Forms.Button();
			this.pbxOutput = new System.Windows.Forms.PictureBox();
			this.pbxInput = new System.Windows.Forms.PictureBox();
			this.cbxInput = new System.Windows.Forms.ComboBox();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.cbxOutput = new System.Windows.Forms.ComboBox();
			this.nupRange = new System.Windows.Forms.NumericUpDown();
			this.chkRange = new System.Windows.Forms.CheckBox();
			this.lblY = new System.Windows.Forms.Label();
			this.lblX = new System.Windows.Forms.Label();
			this.pnlColor = new System.Windows.Forms.Panel();
			this.label1 = new System.Windows.Forms.Label();
			this.lblBlue = new System.Windows.Forms.Label();
			this.tbBlue = new System.Windows.Forms.TrackBar();
			this.lblGreen = new System.Windows.Forms.Label();
			this.tbGreen = new System.Windows.Forms.TrackBar();
			this.lblRed = new System.Windows.Forms.Label();
			this.tbRed = new System.Windows.Forms.TrackBar();
			this.lblb = new System.Windows.Forms.Label();
			this.lbla = new System.Windows.Forms.Label();
			this.lblL = new System.Windows.Forms.Label();
			this.gbxConversion = new System.Windows.Forms.Label();
			this.chkMM = new System.Windows.Forms.CheckBox();
			this.lbh = new System.Windows.Forms.Label();
			this.lbC = new System.Windows.Forms.Label();
			this.lbL = new System.Windows.Forms.Label();
			this.lblMyB = new System.Windows.Forms.Label();
			this.lblMyG = new System.Windows.Forms.Label();
			this.lblMyR = new System.Windows.Forms.Label();
			this.btnProfiling = new System.Windows.Forms.Button();
			this.lZ = new System.Windows.Forms.Label();
			this.lY = new System.Windows.Forms.Label();
			this.lX = new System.Windows.Forms.Label();
			this.cbxIntent = new System.Windows.Forms.ComboBox();
			this.label4 = new System.Windows.Forms.Label();
			this.txtLAB = new System.Windows.Forms.TextBox();
			this.btnLCH = new System.Windows.Forms.Button();
			this.btnXYZ = new System.Windows.Forms.Button();
			this.btnLab = new System.Windows.Forms.Button();
			this.cbxAdaptationState = new System.Windows.Forms.ComboBox();
			this.label5 = new System.Windows.Forms.Label();
			this.btnRestore = new System.Windows.Forms.Button();
			this.cbxUseInput = new System.Windows.Forms.CheckBox();
			this.cbxTest = new System.Windows.Forms.CheckBox();
			this.btnDeltaE2K = new System.Windows.Forms.Button();
			this.btnTEST = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.pbxOutput)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.pbxInput)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.nupRange)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.tbBlue)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.tbGreen)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.tbRed)).BeginInit();
			this.SuspendLayout();
			// 
			// btnApplyProfile
			// 
			this.btnApplyProfile.Location = new System.Drawing.Point(225, 106);
			this.btnApplyProfile.Name = "btnApplyProfile";
			this.btnApplyProfile.Size = new System.Drawing.Size(83, 23);
			this.btnApplyProfile.TabIndex = 0;
			this.btnApplyProfile.Text = "Apply Profile";
			this.btnApplyProfile.UseVisualStyleBackColor = true;
			this.btnApplyProfile.Click += new System.EventHandler(this.button1_Click);
			// 
			// btnOpen
			// 
			this.btnOpen.Location = new System.Drawing.Point(106, 106);
			this.btnOpen.Name = "btnOpen";
			this.btnOpen.Size = new System.Drawing.Size(54, 23);
			this.btnOpen.TabIndex = 3;
			this.btnOpen.Text = "Open";
			this.btnOpen.UseVisualStyleBackColor = true;
			this.btnOpen.Click += new System.EventHandler(this.btnOpen_Click);
			// 
			// pbxOutput
			// 
			this.pbxOutput.Cursor = System.Windows.Forms.Cursors.Cross;
			this.pbxOutput.Location = new System.Drawing.Point(7, 134);
			this.pbxOutput.Margin = new System.Windows.Forms.Padding(0);
			this.pbxOutput.Name = "pbxOutput";
			this.pbxOutput.Size = new System.Drawing.Size(300, 300);
			this.pbxOutput.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.pbxOutput.TabIndex = 2;
			this.pbxOutput.TabStop = false;
			this.pbxOutput.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pbx_MouseMove);
			this.pbxOutput.Click += new System.EventHandler(this.pbxOutput_Click);
			// 
			// pbxInput
			// 
			this.pbxInput.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.pbxInput.Cursor = System.Windows.Forms.Cursors.Cross;
			this.pbxInput.Location = new System.Drawing.Point(315, 4);
			this.pbxInput.Margin = new System.Windows.Forms.Padding(0);
			this.pbxInput.Name = "pbxInput";
			this.pbxInput.Size = new System.Drawing.Size(0, 729);
			this.pbxInput.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
			this.pbxInput.TabIndex = 1;
			this.pbxInput.TabStop = false;
			this.pbxInput.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pbx_MouseMove);
			this.pbxInput.Click += new System.EventHandler(this.pbxInput_Click);
			// 
			// cbxInput
			// 
			this.cbxInput.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxInput.FormattingEnabled = true;
			this.cbxInput.Location = new System.Drawing.Point(83, 4);
			this.cbxInput.Name = "cbxInput";
			this.cbxInput.Size = new System.Drawing.Size(227, 21);
			this.cbxInput.TabIndex = 20;
			this.cbxInput.SelectedIndexChanged += new System.EventHandler(this.cbxInput_SelectedIndexChanged);
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(7, 7);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(63, 13);
			this.label2.TabIndex = 21;
			this.label2.Text = "Input Profile";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(7, 31);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(71, 13);
			this.label3.TabIndex = 23;
			this.label3.Text = "Output Profile";
			// 
			// cbxOutput
			// 
			this.cbxOutput.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxOutput.FormattingEnabled = true;
			this.cbxOutput.Location = new System.Drawing.Point(83, 28);
			this.cbxOutput.Name = "cbxOutput";
			this.cbxOutput.Size = new System.Drawing.Size(227, 21);
			this.cbxOutput.TabIndex = 22;
			// 
			// nupRange
			// 
			this.nupRange.Location = new System.Drawing.Point(262, 481);
			this.nupRange.Name = "nupRange";
			this.nupRange.Size = new System.Drawing.Size(48, 20);
			this.nupRange.TabIndex = 41;
			this.nupRange.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
			this.nupRange.ValueChanged += new System.EventHandler(this.nupRange_ValueChanged);
			// 
			// chkRange
			// 
			this.chkRange.AutoSize = true;
			this.chkRange.Checked = true;
			this.chkRange.CheckState = System.Windows.Forms.CheckState.Checked;
			this.chkRange.Location = new System.Drawing.Point(162, 482);
			this.chkRange.Name = "chkRange";
			this.chkRange.Size = new System.Drawing.Size(94, 17);
			this.chkRange.TabIndex = 40;
			this.chkRange.Text = "Enable Range";
			this.chkRange.UseVisualStyleBackColor = true;
			this.chkRange.CheckedChanged += new System.EventHandler(this.chkRange_CheckedChanged);
			// 
			// lblY
			// 
			this.lblY.AutoSize = true;
			this.lblY.Location = new System.Drawing.Point(80, 459);
			this.lblY.Name = "lblY";
			this.lblY.Size = new System.Drawing.Size(17, 13);
			this.lblY.TabIndex = 56;
			this.lblY.Text = "Y:";
			// 
			// lblX
			// 
			this.lblX.AutoSize = true;
			this.lblX.Location = new System.Drawing.Point(12, 459);
			this.lblX.Name = "lblX";
			this.lblX.Size = new System.Drawing.Size(17, 13);
			this.lblX.TabIndex = 55;
			this.lblX.Text = "X:";
			// 
			// pnlColor
			// 
			this.pnlColor.Location = new System.Drawing.Point(12, 487);
			this.pnlColor.Name = "pnlColor";
			this.pnlColor.Size = new System.Drawing.Size(35, 34);
			this.pnlColor.TabIndex = 54;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(9, 546);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(107, 13);
			this.label1.TabIndex = 53;
			this.label1.Text = "Red    Green      Blue";
			// 
			// lblBlue
			// 
			this.lblBlue.AutoSize = true;
			this.lblBlue.Location = new System.Drawing.Point(93, 568);
			this.lblBlue.Name = "lblBlue";
			this.lblBlue.Size = new System.Drawing.Size(13, 13);
			this.lblBlue.TabIndex = 52;
			this.lblBlue.Text = "0";
			// 
			// tbBlue
			// 
			this.tbBlue.AutoSize = false;
			this.tbBlue.LargeChange = 1;
			this.tbBlue.Location = new System.Drawing.Point(87, 584);
			this.tbBlue.Maximum = 255;
			this.tbBlue.Name = "tbBlue";
			this.tbBlue.Orientation = System.Windows.Forms.Orientation.Vertical;
			this.tbBlue.Size = new System.Drawing.Size(23, 150);
			this.tbBlue.TabIndex = 51;
			this.tbBlue.ValueChanged += new System.EventHandler(this.tbBlue_ValueChanged);
			// 
			// lblGreen
			// 
			this.lblGreen.AutoSize = true;
			this.lblGreen.Location = new System.Drawing.Point(51, 568);
			this.lblGreen.Name = "lblGreen";
			this.lblGreen.Size = new System.Drawing.Size(13, 13);
			this.lblGreen.TabIndex = 50;
			this.lblGreen.Tag = "0";
			this.lblGreen.Text = "0";
			// 
			// tbGreen
			// 
			this.tbGreen.AutoSize = false;
			this.tbGreen.LargeChange = 1;
			this.tbGreen.Location = new System.Drawing.Point(48, 584);
			this.tbGreen.Maximum = 255;
			this.tbGreen.Name = "tbGreen";
			this.tbGreen.Orientation = System.Windows.Forms.Orientation.Vertical;
			this.tbGreen.Size = new System.Drawing.Size(23, 150);
			this.tbGreen.TabIndex = 49;
			this.tbGreen.ValueChanged += new System.EventHandler(this.tbGreen_ValueChanged);
			// 
			// lblRed
			// 
			this.lblRed.AutoSize = true;
			this.lblRed.Location = new System.Drawing.Point(13, 568);
			this.lblRed.Name = "lblRed";
			this.lblRed.Size = new System.Drawing.Size(13, 13);
			this.lblRed.TabIndex = 48;
			this.lblRed.Text = "0";
			// 
			// tbRed
			// 
			this.tbRed.AutoSize = false;
			this.tbRed.LargeChange = 1;
			this.tbRed.Location = new System.Drawing.Point(10, 584);
			this.tbRed.Maximum = 255;
			this.tbRed.Name = "tbRed";
			this.tbRed.Orientation = System.Windows.Forms.Orientation.Vertical;
			this.tbRed.Size = new System.Drawing.Size(23, 150);
			this.tbRed.TabIndex = 47;
			this.tbRed.ValueChanged += new System.EventHandler(this.tbRed_ValueChanged);
			// 
			// lblb
			// 
			this.lblb.AutoSize = true;
			this.lblb.Location = new System.Drawing.Point(116, 713);
			this.lblb.Name = "lblb";
			this.lblb.Size = new System.Drawing.Size(16, 13);
			this.lblb.TabIndex = 46;
			this.lblb.Text = "b:";
			// 
			// lbla
			// 
			this.lbla.AutoSize = true;
			this.lbla.Location = new System.Drawing.Point(116, 685);
			this.lbla.Name = "lbla";
			this.lbla.Size = new System.Drawing.Size(16, 13);
			this.lbla.TabIndex = 45;
			this.lbla.Text = "a:";
			// 
			// lblL
			// 
			this.lblL.AutoSize = true;
			this.lblL.Location = new System.Drawing.Point(116, 658);
			this.lblL.Name = "lblL";
			this.lblL.Size = new System.Drawing.Size(16, 13);
			this.lblL.TabIndex = 44;
			this.lblL.Text = "L:";
			// 
			// gbxConversion
			// 
			this.gbxConversion.AutoSize = true;
			this.gbxConversion.ForeColor = System.Drawing.Color.Blue;
			this.gbxConversion.Location = new System.Drawing.Point(152, 508);
			this.gbxConversion.Name = "gbxConversion";
			this.gbxConversion.Size = new System.Drawing.Size(60, 13);
			this.gbxConversion.TabIndex = 57;
			this.gbxConversion.Text = "Conversion";
			// 
			// chkMM
			// 
			this.chkMM.AutoSize = true;
			this.chkMM.Location = new System.Drawing.Point(162, 459);
			this.chkMM.Name = "chkMM";
			this.chkMM.Size = new System.Drawing.Size(142, 17);
			this.chkMM.TabIndex = 58;
			this.chkMM.Text = "Use pixels instead of mm";
			this.chkMM.UseVisualStyleBackColor = true;
			this.chkMM.CheckedChanged += new System.EventHandler(this.chkMM_CheckedChanged);
			// 
			// lbh
			// 
			this.lbh.AutoSize = true;
			this.lbh.Location = new System.Drawing.Point(176, 713);
			this.lbh.Name = "lbh";
			this.lbh.Size = new System.Drawing.Size(16, 13);
			this.lbh.TabIndex = 61;
			this.lbh.Text = "h:";
			// 
			// lbC
			// 
			this.lbC.AutoSize = true;
			this.lbC.Location = new System.Drawing.Point(176, 685);
			this.lbC.Name = "lbC";
			this.lbC.Size = new System.Drawing.Size(17, 13);
			this.lbC.TabIndex = 60;
			this.lbC.Text = "C:";
			// 
			// lbL
			// 
			this.lbL.AutoSize = true;
			this.lbL.Location = new System.Drawing.Point(176, 658);
			this.lbL.Name = "lbL";
			this.lbL.Size = new System.Drawing.Size(16, 13);
			this.lbL.TabIndex = 59;
			this.lbL.Text = "L:";
			// 
			// lblMyB
			// 
			this.lblMyB.AutoSize = true;
			this.lblMyB.Location = new System.Drawing.Point(60, 529);
			this.lblMyB.Name = "lblMyB";
			this.lblMyB.Size = new System.Drawing.Size(17, 13);
			this.lblMyB.TabIndex = 64;
			this.lblMyB.Text = "B:";
			// 
			// lblMyG
			// 
			this.lblMyG.AutoSize = true;
			this.lblMyG.Location = new System.Drawing.Point(59, 508);
			this.lblMyG.Name = "lblMyG";
			this.lblMyG.Size = new System.Drawing.Size(18, 13);
			this.lblMyG.TabIndex = 63;
			this.lblMyG.Text = "G:";
			// 
			// lblMyR
			// 
			this.lblMyR.AutoSize = true;
			this.lblMyR.Location = new System.Drawing.Point(59, 488);
			this.lblMyR.Name = "lblMyR";
			this.lblMyR.Size = new System.Drawing.Size(18, 13);
			this.lblMyR.TabIndex = 62;
			this.lblMyR.Text = "R:";
			// 
			// btnProfiling
			// 
			this.btnProfiling.Location = new System.Drawing.Point(10, 106);
			this.btnProfiling.Name = "btnProfiling";
			this.btnProfiling.Size = new System.Drawing.Size(90, 23);
			this.btnProfiling.TabIndex = 65;
			this.btnProfiling.Text = "Test Profiling...";
			this.btnProfiling.UseVisualStyleBackColor = true;
			this.btnProfiling.Click += new System.EventHandler(this.btnProfiling_Click);
			// 
			// lZ
			// 
			this.lZ.AutoSize = true;
			this.lZ.Location = new System.Drawing.Point(240, 713);
			this.lZ.Name = "lZ";
			this.lZ.Size = new System.Drawing.Size(17, 13);
			this.lZ.TabIndex = 68;
			this.lZ.Text = "Z:";
			// 
			// lY
			// 
			this.lY.AutoSize = true;
			this.lY.Location = new System.Drawing.Point(240, 685);
			this.lY.Name = "lY";
			this.lY.Size = new System.Drawing.Size(17, 13);
			this.lY.TabIndex = 67;
			this.lY.Text = "Y:";
			// 
			// lX
			// 
			this.lX.AutoSize = true;
			this.lX.Location = new System.Drawing.Point(240, 658);
			this.lX.Name = "lX";
			this.lX.Size = new System.Drawing.Size(17, 13);
			this.lX.TabIndex = 66;
			this.lX.Text = "X:";
			// 
			// cbxIntent
			// 
			this.cbxIntent.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxIntent.FormattingEnabled = true;
			this.cbxIntent.Location = new System.Drawing.Point(83, 52);
			this.cbxIntent.Name = "cbxIntent";
			this.cbxIntent.Size = new System.Drawing.Size(227, 21);
			this.cbxIntent.TabIndex = 70;
			this.cbxIntent.SelectedIndexChanged += new System.EventHandler(this.cbxIntent_SelectedIndexChanged);
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(43, 55);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(34, 13);
			this.label4.TabIndex = 69;
			this.label4.Text = "Intent";
			// 
			// txtLAB
			// 
			this.txtLAB.Location = new System.Drawing.Point(119, 559);
			this.txtLAB.Multiline = true;
			this.txtLAB.Name = "txtLAB";
			this.txtLAB.Size = new System.Drawing.Size(191, 84);
			this.txtLAB.TabIndex = 71;
			// 
			// btnLCH
			// 
			this.btnLCH.Location = new System.Drawing.Point(274, 530);
			this.btnLCH.Name = "btnLCH";
			this.btnLCH.Size = new System.Drawing.Size(35, 23);
			this.btnLCH.TabIndex = 72;
			this.btnLCH.Text = "LCh";
			this.btnLCH.UseVisualStyleBackColor = true;
			this.btnLCH.Click += new System.EventHandler(this.btnLCH_Click);
			// 
			// btnXYZ
			// 
			this.btnXYZ.Location = new System.Drawing.Point(227, 530);
			this.btnXYZ.Name = "btnXYZ";
			this.btnXYZ.Size = new System.Drawing.Size(43, 23);
			this.btnXYZ.TabIndex = 73;
			this.btnXYZ.Text = "XYZ";
			this.btnXYZ.UseVisualStyleBackColor = true;
			this.btnXYZ.Click += new System.EventHandler(this.btnXYZ_Click);
			// 
			// btnLab
			// 
			this.btnLab.Location = new System.Drawing.Point(119, 530);
			this.btnLab.Name = "btnLab";
			this.btnLab.Size = new System.Drawing.Size(30, 23);
			this.btnLab.TabIndex = 74;
			this.btnLab.Text = "Do";
			this.btnLab.UseVisualStyleBackColor = true;
			this.btnLab.Click += new System.EventHandler(this.btnLab_Click);
			// 
			// cbxAdaptationState
			// 
			this.cbxAdaptationState.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cbxAdaptationState.FormattingEnabled = true;
			this.cbxAdaptationState.Items.AddRange(new object[] {
            "No Adaptation",
            "Observer if Fully adapted"});
			this.cbxAdaptationState.Location = new System.Drawing.Point(99, 78);
			this.cbxAdaptationState.Name = "cbxAdaptationState";
			this.cbxAdaptationState.Size = new System.Drawing.Size(211, 21);
			this.cbxAdaptationState.TabIndex = 76;
			this.cbxAdaptationState.SelectedIndexChanged += new System.EventHandler(this.cbxAdaptationState_SelectedIndexChanged);
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(7, 81);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(86, 13);
			this.label5.TabIndex = 75;
			this.label5.Text = "Adaptation State";
			// 
			// btnRestore
			// 
			this.btnRestore.Location = new System.Drawing.Point(165, 106);
			this.btnRestore.Name = "btnRestore";
			this.btnRestore.Size = new System.Drawing.Size(54, 23);
			this.btnRestore.TabIndex = 77;
			this.btnRestore.Text = "Restore";
			this.btnRestore.UseVisualStyleBackColor = true;
			this.btnRestore.Click += new System.EventHandler(this.btnRestore_Click);
			// 
			// cbxUseInput
			// 
			this.cbxUseInput.AutoSize = true;
			this.cbxUseInput.Location = new System.Drawing.Point(162, 439);
			this.cbxUseInput.Name = "cbxUseInput";
			this.cbxUseInput.Size = new System.Drawing.Size(143, 17);
			this.cbxUseInput.TabIndex = 78;
			this.cbxUseInput.Text = "Use Input Profile for Lab ";
			this.cbxUseInput.UseVisualStyleBackColor = true;
			this.cbxUseInput.CheckedChanged += new System.EventHandler(this.cbxUseInput_CheckedChanged);
			// 
			// cbxTest
			// 
			this.cbxTest.AutoSize = true;
			this.cbxTest.Location = new System.Drawing.Point(13, 438);
			this.cbxTest.Name = "cbxTest";
			this.cbxTest.Size = new System.Drawing.Size(121, 17);
			this.cbxTest.TabIndex = 79;
			this.cbxTest.Text = "Test (Do not check)";
			this.cbxTest.UseVisualStyleBackColor = true;
			this.cbxTest.CheckedChanged += new System.EventHandler(this.cbxTest_CheckedChanged);
			// 
			// btnDeltaE2K
			// 
			this.btnDeltaE2K.Location = new System.Drawing.Point(155, 530);
			this.btnDeltaE2K.Name = "btnDeltaE2K";
			this.btnDeltaE2K.Size = new System.Drawing.Size(37, 23);
			this.btnDeltaE2K.TabIndex = 80;
			this.btnDeltaE2K.Text = "E2K";
			this.btnDeltaE2K.UseVisualStyleBackColor = true;
			this.btnDeltaE2K.Click += new System.EventHandler(this.btnDeltaE2K_Click);
			// 
			// btnTEST
			// 
			this.btnTEST.Location = new System.Drawing.Point(198, 530);
			this.btnTEST.Name = "btnTEST";
			this.btnTEST.Size = new System.Drawing.Size(24, 23);
			this.btnTEST.TabIndex = 81;
			this.btnTEST.Text = "T";
			this.btnTEST.UseVisualStyleBackColor = true;
			this.btnTEST.Click += new System.EventHandler(this.btnTEST_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(314, 736);
			this.Controls.Add(this.btnTEST);
			this.Controls.Add(this.btnDeltaE2K);
			this.Controls.Add(this.cbxTest);
			this.Controls.Add(this.cbxUseInput);
			this.Controls.Add(this.btnRestore);
			this.Controls.Add(this.cbxAdaptationState);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.btnLab);
			this.Controls.Add(this.btnXYZ);
			this.Controls.Add(this.btnLCH);
			this.Controls.Add(this.txtLAB);
			this.Controls.Add(this.cbxIntent);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.lZ);
			this.Controls.Add(this.lY);
			this.Controls.Add(this.lX);
			this.Controls.Add(this.btnProfiling);
			this.Controls.Add(this.lblMyB);
			this.Controls.Add(this.lblMyG);
			this.Controls.Add(this.lblMyR);
			this.Controls.Add(this.lbh);
			this.Controls.Add(this.lbC);
			this.Controls.Add(this.lbL);
			this.Controls.Add(this.chkMM);
			this.Controls.Add(this.gbxConversion);
			this.Controls.Add(this.lblY);
			this.Controls.Add(this.lblX);
			this.Controls.Add(this.pnlColor);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.lblBlue);
			this.Controls.Add(this.tbBlue);
			this.Controls.Add(this.lblGreen);
			this.Controls.Add(this.tbGreen);
			this.Controls.Add(this.lblRed);
			this.Controls.Add(this.tbRed);
			this.Controls.Add(this.lblb);
			this.Controls.Add(this.lbla);
			this.Controls.Add(this.lblL);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.nupRange);
			this.Controls.Add(this.cbxOutput);
			this.Controls.Add(this.chkRange);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.cbxInput);
			this.Controls.Add(this.btnOpen);
			this.Controls.Add(this.pbxOutput);
			this.Controls.Add(this.pbxInput);
			this.Controls.Add(this.btnApplyProfile);
			this.MinimumSize = new System.Drawing.Size(322, 770);
			this.Name = "Form1";
			this.Text = "Little CMS Wrapper - Testing App";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
			((System.ComponentModel.ISupportInitialize)(this.pbxOutput)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.pbxInput)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.nupRange)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.tbBlue)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.tbGreen)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.tbRed)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnApplyProfile;
        private System.Windows.Forms.PictureBox pbxInput;
        private System.Windows.Forms.PictureBox pbxOutput;
        private System.Windows.Forms.Button btnOpen;
        private System.Windows.Forms.ComboBox cbxInput;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox cbxOutput;
        private System.Windows.Forms.NumericUpDown nupRange;
        private System.Windows.Forms.CheckBox chkRange;
        private System.Windows.Forms.Label lblY;
        private System.Windows.Forms.Label lblX;
        private System.Windows.Forms.Panel pnlColor;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblBlue;
        private System.Windows.Forms.TrackBar tbBlue;
        private System.Windows.Forms.Label lblGreen;
        private System.Windows.Forms.TrackBar tbGreen;
        private System.Windows.Forms.Label lblRed;
        private System.Windows.Forms.TrackBar tbRed;
        private System.Windows.Forms.Label lblb;
        private System.Windows.Forms.Label lbla;
        private System.Windows.Forms.Label lblL;
        private System.Windows.Forms.Label gbxConversion;
		private System.Windows.Forms.CheckBox chkMM;
		private System.Windows.Forms.Label lbh;
		private System.Windows.Forms.Label lbC;
		private System.Windows.Forms.Label lbL;
		private System.Windows.Forms.Label lblMyB;
		private System.Windows.Forms.Label lblMyG;
		private System.Windows.Forms.Label lblMyR;
		private System.Windows.Forms.Button btnProfiling;
		private System.Windows.Forms.Label lZ;
		private System.Windows.Forms.Label lY;
		private System.Windows.Forms.Label lX;
		private System.Windows.Forms.ComboBox cbxIntent;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox txtLAB;
		private System.Windows.Forms.Button btnLCH;
		private System.Windows.Forms.Button btnXYZ;
		private System.Windows.Forms.Button btnLab;
		private System.Windows.Forms.Label label5;
		public System.Windows.Forms.ComboBox cbxAdaptationState;
		private System.Windows.Forms.Button btnRestore;
		private System.Windows.Forms.CheckBox cbxUseInput;
		private System.Windows.Forms.CheckBox cbxTest;
		private System.Windows.Forms.Button btnDeltaE2K;
		private System.Windows.Forms.Button btnTEST;
    }
}

