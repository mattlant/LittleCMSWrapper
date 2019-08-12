using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using LittleCMSWrapper;

namespace TEST
{
	public partial class Form2 : Form
	{
		lcmsJPEGProfiling jpegProfiling;

		public Form2()
		{
			InitializeComponent();

			jpegProfiling = new lcmsJPEGProfiling();
		}

		private void chkDefaultOutput_CheckedChanged(object sender, EventArgs e)
		{
			bool visible = !((CheckBox)sender).Checked;
			//visible = false; //Later comment this
			lblOuput.Visible = visible;
			tbxOutput.Visible = visible;
			btnOutput.Visible = visible;
		}

		private void Form2_Load(object sender, EventArgs e)
		{
			chkDefaultOutput_CheckedChanged(chkDefaultOutput,e);
			chkInputProfile_CheckedChanged(chkInputProfile,e);
			chkOutputProfile_CheckedChanged(chkOutputProfile, e);
			chkProofProfile_CheckedChanged(chkProofProfile, e);
			chkSaveEmbeded_CheckedChanged(chkSaveEmbeded, e);

			cbxIntent.Items.Add(lcmsIntents.PERCEPTUAL);
			cbxIntent.Items.Add(lcmsIntents.RELATIVE_COLORIMETRIC);
			cbxIntent.Items.Add(lcmsIntents.SATURATION);
			cbxIntent.Items.Add(lcmsIntents.ABSOLUTE_COLORIMETRIC);
			cbxIntent.SelectedIndex = 0;

			cbxSoftProofIntent.Items.Add(lcmsIntents.PERCEPTUAL);
			cbxSoftProofIntent.Items.Add(lcmsIntents.RELATIVE_COLORIMETRIC);
			cbxSoftProofIntent.Items.Add(lcmsIntents.SATURATION);
			cbxSoftProofIntent.Items.Add(lcmsIntents.ABSOLUTE_COLORIMETRIC);
			cbxSoftProofIntent.SelectedIndex = 0;

			cbxBlackPreserve.Items.Add(lcmsBlackPreservation.Off);
			cbxBlackPreserve.Items.Add(lcmsBlackPreservation.BlackInkOnly);
			cbxBlackPreserve.Items.Add(lcmsBlackPreservation.FullKPlane);
			cbxBlackPreserve.SelectedIndex = 0;

			cbxPrecalcMode.Items.Add(lcmsPrecalculationMode.Off);
			cbxPrecalcMode.Items.Add(lcmsPrecalculationMode.Low_Res);
			cbxPrecalcMode.Items.Add(lcmsPrecalculationMode.Normal);
			cbxPrecalcMode.Items.Add(lcmsPrecalculationMode.Hi_Res);
			cbxPrecalcMode.SelectedIndex = 2;
		}

		private string FileWithoutExtension(string file)
		{
			return file.Substring(file.LastIndexOf(@".") + 1);
		}

		private void btnInput_Click(object sender, EventArgs e)
		{
			var dlg = new OpenFileDialog();
			dlg.Filter = "Jpeg files (*.jpg) | *.jpg";
			if (dlg.ShowDialog() == DialogResult.OK)
			{
				tbxInput.Text = dlg.FileName;	
				if(chkDefaultOutput.Checked || true)
				{
					tbxOutput.Text = dlg.FileName + "_OUT.jpg";
				}
				else
				{
					//Enable this later
					//here goes code to take the output file from the textbox
				}
			}
		}

		private void chkInputProfile_CheckedChanged(object sender, EventArgs e)
		{
			bool visible = ((CheckBox)sender).Checked;
			chkDeviceLink.Visible = visible;
			tbxInputProfile.Visible = visible;
			btnInputProfile.Visible = visible;
		}

		private void chkOutputProfile_CheckedChanged(object sender, EventArgs e)
		{
			bool visible = ((CheckBox)sender).Checked;
			tbxOutputProfile.Visible = visible;
			btnOutputProfile.Visible = visible;
		}

		private void chkProofProfile_CheckedChanged(object sender, EventArgs e)
		{
			bool visible = ((CheckBox)sender).Checked;
			tbxProofProfile.Visible = visible;
			btnProofProfile.Visible = visible;
		}

		private void chkSaveEmbeded_CheckedChanged(object sender, EventArgs e)
		{
			bool visible = ((CheckBox)sender).Checked;
			tbxSaveEmbedded.Visible = visible;
			btnSaveEmbedded.Visible = visible;
			if (visible) tbxSaveEmbedded.Text = tbxInput.Text + "_SAVED_EMBEDDED_PROFILE.ICM";
		}

		String GetProfileFileName()
		{
			var dlg = new OpenFileDialog();
			dlg.Filter = "ICC Profiles | *.icm;*.icc";
			if(dlg.ShowDialog() == DialogResult.OK)
			{
				bool validProfile = false;
				string fileName = dlg.FileName;

				try
				{
					var tempProfile = lcmsProfile.OpenProfileFromFile(fileName);

					validProfile = tempProfile.HasValue;

					//TODO:Perform more checks for a valid profile

					//txtInputProfile.Text = String.Format("{0} ({1})", tempProfile.ProductName, tempProfile.ProductDescription);
					//txtInputProfile.ToolTip = tempProfile.ProductInfo;

					tempProfile.Close();
				}
				catch (Exception ex)
				{
					MessageBox.Show("MY ERROR: "+ex.Message);
					validProfile = false;					
				}
				if(validProfile) return fileName;
			}
			return String.Empty;
		}

		private void btnInputProfile_Click(object sender, EventArgs e)
		{
			tbxInputProfile.Text = GetProfileFileName();
		}

		private void btnOutputProfile_Click(object sender, EventArgs e)
		{
			tbxOutputProfile.Text = GetProfileFileName();
		}

		private void btnProofProfile_Click(object sender, EventArgs e)
		{
			tbxProofProfile.Text = GetProfileFileName();
		}

		private void btnDoTransform_Click(object sender, EventArgs e)
		{
			if (!CheckOptionsAndSet()) return;

			MessageBox.Show((jpegProfiling.TransformImage() ? "Transformation was OK" : "ERROR!"));
		}

		private bool CheckOptionsAndSet()
		{
			if(String.IsNullOrEmpty(tbxInput.Text.Trim()))
			{
				MessageBox.Show("First you have to select an input jpeg file.");
				return false;
			}

			if (String.IsNullOrEmpty(tbxOutput.Text.Trim()))
			{
				MessageBox.Show("You have to select an output jpeg file.");
				return false;
			}

			if(chkInputProfile.Checked && String.IsNullOrEmpty(tbxInputProfile.Text.Trim()))
			{
				MessageBox.Show("If you select the input profile option you have to select a file.");
				return false;
			}

			if(chkInputProfile.Checked && chkDeviceLink.Checked && (chkOutputProfile.Checked || chkProofProfile.Checked))
			{
				MessageBox.Show("If you select the use as Device Link option then you cannot select output profile or soft proof profile options.");
				return false;
			}

			if (chkOutputProfile.Checked && String.IsNullOrEmpty(tbxOutputProfile.Text.Trim()))
			{
				MessageBox.Show("If you select the output profile option you have to select a file.");
				return false;
			}

			if (chkProofProfile.Checked && String.IsNullOrEmpty(tbxProofProfile.Text.Trim()))
			{
				MessageBox.Show("If you select the Soft Proof profile option you have to select a file.");
				return false;
			}

			if (chkSaveEmbeded.Checked && String.IsNullOrEmpty(tbxSaveEmbedded.Text.Trim()))
			{
				MessageBox.Show("If you select the Save Embedded profile option you have to select a file.");
				return false;
			}



			jpegProfiling.InputFileName = tbxInput.Text;
			jpegProfiling.OutputFileName = tbxOutput.Text;
			jpegProfiling.BlackPointCompensation = chkBlackPoint.Checked;

			jpegProfiling.InputProfileS = (chkInputProfile.Checked) ? tbxInputProfile.Text : String.Empty;
			jpegProfiling.OutputProfileS = (chkOutputProfile.Checked) ? tbxOutputProfile.Text : String.Empty;
			jpegProfiling.ProofProfileS = (chkProofProfile.Checked) ? tbxProofProfile.Text : String.Empty;
			jpegProfiling.IsDeviceLink = (chkInputProfile.Checked && chkDeviceLink.Checked);

			jpegProfiling.SaveEmbedded = (chkSaveEmbeded.Checked) ? tbxSaveEmbedded.Text : String.Empty;

			jpegProfiling.IgnoreEmbedded = chkIgnoreEmbeded.Checked;
			jpegProfiling.EmbedProfile = chkEmbedProfile.Checked;

			jpegProfiling.CheckGamut = chkGamutCheck.Checked;

			jpegProfiling.JpegQuality = (UInt32)nupJpgQuality.Value;

			//Intent, soft Intent, Preserve Black, Pre calculation Mode Transform
			jpegProfiling.Intent = (lcmsIntents)cbxIntent.SelectedItem;
			jpegProfiling.ProofingIntent = (lcmsIntents)cbxSoftProofIntent.SelectedItem;
			jpegProfiling.BlackPreservationStrategy = (lcmsBlackPreservation)cbxBlackPreserve.SelectedItem;
			jpegProfiling.PrecalculationMode = (lcmsPrecalculationMode)cbxPrecalcMode.SelectedItem;
			return true;
		}
	}
}
