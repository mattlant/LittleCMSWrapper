using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;
using LittleCMSWrapper;
using mattlant.Imaging;
using System.Drawing.Drawing2D;
//using PDFLibNet;

namespace TEST
{
	public partial class Form1 : Form
	{
		private lcmsCIELab currentLAB;
		private lcmsProfile pRGB;
		private lcmsProfile pLab;
		private lcmsTransform tRGBtoLab;
		private lcmsTransform tRGBtoLabDBL;
		private lcmsFlags	_flag;
		private lcmsIntents _intent;
		private double _AdaptationState;
		private String _FileName;

		private readonly String ICCProfilePath = Application.StartupPath + @"\ICCProfiles\";
		private readonly String SystemICCProfilePath = Environment.SystemDirectory + @"\spool\drivers\color\";
		private List<String> ProfileFilesIn = new List<string>();
		private List<String> ProfileFilesOut = new List<string>();
		private int picX = 0;
		private int picY = 0;
		private int picZT = 0;
		private int picZL = 0;
		private Bitmap picBmp = null;

		private lcmsRGBColor rgbColor = new lcmsRGBColor();

		private bool IsPointSetIn = false;
		private bool IsPointSetOut = false;
		private bool DontDoTestLab = false;

		private void CreateRGBtoLABTransforms()
		{
			if(tRGBtoLab != null) tRGBtoLab.Close(false);
			if (tRGBtoLabDBL != null) tRGBtoLabDBL.Close(false);

			tRGBtoLab = lcmsTransform.CreateTransform(pRGB, lcmsDefs.TYPE_RGB_8, pLab, lcmsDefs.TYPE_Lab_DBL, _intent, _flag,
														new lcmsTransformExtraArgs(_AdaptationState));
			tRGBtoLabDBL = lcmsTransform.CreateTransform(pRGB, lcmsDefs.TYPE_RGB_DBL, pLab, lcmsDefs.TYPE_Lab_DBL, _intent, _flag,
														new lcmsTransformExtraArgs(_AdaptationState));
		}

		public Form1()
		{
			InitializeComponent();


			//var wPo = new lcmsCIEXYZ(0.3127, 0.3290, 0.3583); //WhitePoint using XYZ
			//var wP = new lcmsCIExyY();
			//lcmsWrapper.XYZ2xyY(wPo, wP); //Converts whitepoint from XYZ to xyY

			_flag = lcmsFlags.EMPTY;

			//ProfileFiles.Add(ICCProfilePath + "Kodak.icm");
			//ProfileFiles.Add(ICCProfilePath + "sRGB.icm");
			//pRGB = lcmsWrapper.OpenProfileFromFile(ICCProfilePath + "Kodak.icm", "r");
			//pRGB = lcmsWrapper.OpenProfileFromFile(ICCProfilePath + "sRGB.icm", "r");

			_intent = lcmsIntents.PERCEPTUAL;
			_AdaptationState = 1d;
			_FileName = "";
			
			pRGB = lcmsProfile.Create_sRGBProfile();
			pLab = lcmsProfile.CreateLab4Profile(lcmsWhitePoint.ICC_D50());  //D50

			CreateRGBtoLABTransforms();
		}

		private void TestWhitePoint()
		{
			//var myWhitePoint = new lcmsCIExyY();

			//var myCIElab = new lcmsCIELab(0.1, 0.2, 0.44);

			//var isOk = lcmsWrapper.WhitePointFromTemp(5000, myWhitePoint);

			//if (isOk)
			//{
			//    MessageBox.Show(myWhitePoint.x + " " + myWhitePoint.y + " " + myWhitePoint.Y);
			//}
		}

		private void TestLab()
		{
			if (DontDoTestLab) return;
			pnlColor.BackColor = Color.FromArgb(tbRed.Value, tbGreen.Value, tbBlue.Value);

			double[] myLab = new double[3];
			byte[] rgb = new byte[3];

			//double

			rgb[0] = (Byte)tbRed.Value; //Red
			rgb[1] = (Byte)tbGreen.Value; //Green
			rgb[2] = (Byte)tbBlue.Value; //Blue

			IntPtr ptrIn = Marshal.AllocCoTaskMem(sizeof(byte) * rgb.Length);
			Marshal.Copy(rgb, 0, ptrIn, rgb.Length);

			IntPtr ptrOut = Marshal.AllocCoTaskMem(sizeof(double) * myLab.Length);

			tRGBtoLab.DoTransform(ptrIn, ptrOut, 1);

			Marshal.Copy(ptrOut, myLab, 0, myLab.Length);

			Marshal.FreeCoTaskMem(ptrIn);
			Marshal.FreeCoTaskMem(ptrOut);

			var labValues = new lcmsCIELab(myLab[0], myLab[1], myLab[2]);

			SetLabLChValues(labValues);
			gbxConversion.Text = " RGB - LAB (byte -> double)";
		}

		private void TestTransform()
		{
			var pIn = lcmsProfile.OpenProfileFromFile(ProfileFilesIn[cbxInput.SelectedIndex]);
			var pOut = lcmsProfile.OpenProfileFromFile(ProfileFilesOut[cbxOutput.SelectedIndex]);
			//var pOut = lcmsProfile.Create_sRGBProfile();

			var t = lcmsTransform.CreateTransform(pIn, lcmsDefs.TYPE_BGR_8, pOut, lcmsDefs.TYPE_BGR_8,
												_intent, _flag,new lcmsTransformExtraArgs(_AdaptationState));

			var bmpIn = (Bitmap)pbxInput.Image;

			for (int y = 0; y < bmpIn.Height; y++)
			{
				Rectangle rect = new Rectangle(0, y, bmpIn.Width, 1);
				BitmapData bmpData = bmpIn.LockBits(rect, ImageLockMode.ReadWrite, bmpIn.PixelFormat);

				IntPtr ptrBmp = bmpData.Scan0;

				t.DoTransform(ptrBmp, ptrBmp, (UInt32)bmpIn.Width);

				bmpIn.UnlockBits(bmpData);
			}

			pbxInput.Refresh();
			t.Close();
		}


		private void button1_Click(object sender, EventArgs e)
		{
			if (pbxInput.Image == null)
			{
				MessageBox.Show("You have to load an image first.");
				btnOpen.Focus();
				return;
			}

			if (cbxInput.SelectedIndex == -1)
			{
				MessageBox.Show("You have to select an input profile.");
				cbxInput.Focus();
				return;
			}

			if (cbxOutput.SelectedIndex == -1)
			{
				MessageBox.Show("You have to select an input profile.");
				cbxOutput.Focus();
				return;
			}

			var start = DateTime.Now;

			TestTransform();

			TimeSpan time = DateTime.Now.Subtract(start);
			String timeString = String.Format("Profile applien in {0}:{1}:{2}", time.Hours.ToString().PadLeft(2, '0'),
											  time.Minutes.ToString().PadLeft(2, '0'), time.Seconds.ToString().PadLeft(2, '0'));

			MessageBox.Show(timeString);
		}

		private void OpenFileName()
		{
			if (String.IsNullOrEmpty(_FileName)) return;

			pbxInput.Load(_FileName);

			var bmp = pbxInput.Image as Bitmap;
			var w = bmp.Width;
			var h = bmp.Height;
			Width = (Int32)((Height - 41) * ((double)w / h)) + 327;
			pbxInput.Refresh();
			this.Text += String.Format(" ({0})", _FileName);
		}

		private void btnOpen_Click(object sender, EventArgs e)
		{
			var dlg = new OpenFileDialog();

			if (dlg.ShowDialog() == DialogResult.OK)
			{
				_FileName = dlg.FileName;
				OpenFileName();
			}
		}


		private void Form1_FormClosing(object sender, FormClosingEventArgs e)
		{
			tRGBtoLab.Close(false);
			tRGBtoLabDBL.Close();
		}

		private void AddProfile(String fileName)
		{
			var tempP = lcmsProfile.OpenProfileFromFile(fileName);
			if (tempP != null)
			{
				if (tempP.ColorSpace == lcmsICColorSpaceSignature.SigRgbData)
				{
					//TODO: Check the Device class for input colorspace display
					var signature = tempP.DeviceClass;

					if (signature == lcmsICProfileClassSignature.SigInputClass ||
						signature == lcmsICProfileClassSignature.SigDisplayClass ||
						signature == lcmsICProfileClassSignature.SigColorSpaceClass)
					{
						ProfileFilesIn.Add(fileName);
						cbxInput.Items.Add(tempP.ProductDescription);
					}

					if (signature == lcmsICProfileClassSignature.SigDisplayClass ||
						signature == lcmsICProfileClassSignature.SigOutputClass)
					{
						ProfileFilesOut.Add(fileName);
						cbxOutput.Items.Add(tempP.ProductDescription);
					}
				}
			}
			tempP.Close();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			TestLab();
			SetRange();
			//Set Defaults
			//AddProfile(ICCProfilePath + "Kodak.icm");
			//AddProfile(ICCProfilePath + "sRGB.icm");

			//var files = System.IO.Directory.GetFiles(SystemICCProfilePath);
			//foreach (var file in files)
			//    AddProfile(file);

			var files2 = System.IO.Directory.GetFiles(ICCProfilePath);
			foreach (var file in files2)
				AddProfile(file);

			cbxInput.SelectedIndex = 0;
			cbxOutput.SelectedIndex = 1;

			cbxIntent.Items.Add(lcmsIntents.PERCEPTUAL);
			cbxIntent.Items.Add(lcmsIntents.RELATIVE_COLORIMETRIC);
			cbxIntent.Items.Add(lcmsIntents.SATURATION);
			cbxIntent.Items.Add(lcmsIntents.ABSOLUTE_COLORIMETRIC);
			cbxIntent.SelectedIndex = 3;

			cbxAdaptationState.SelectedIndex = 1;
		}

		private string ExtractName(string file)
		{
			return file.Substring(file.LastIndexOf(@"\") + 1);
		}

		private int CorrectRangeValue(int value, int minimunValue, int maximunValue)
		{
			if (value < minimunValue) value = minimunValue;
			if (value > maximunValue) value = maximunValue;
			return value;
		}

		private lcmsRGBColor GetAvgRGBFromBitmap(Bitmap picture, int xC, int yC, int rangeInit)
		{
			if (picture == null) return null;

			// 1 inch = 25.4 mm
			double verticalResolution = picture.VerticalResolution / 25.4; //Pixel per mm
			double horizontalResolution = picture.HorizontalResolution / 25.4; //Pixel per mm

			int rangeX = Convert.ToInt32(rangeInit * horizontalResolution);
			int rangeY = Convert.ToInt32(rangeInit * verticalResolution);

			if (chkMM.Checked)
			{
				rangeX = rangeInit;
				rangeY = rangeInit;
			}

			var avgColor = new lcmsRGBColor();

			int r = 0;
			int g = 0;
			int b = 0;

			int x1 = CorrectRangeValue(xC - rangeX, 0, picture.Width - 1);
			int y1 = CorrectRangeValue(yC - rangeY, 0, picture.Height - 1);
			int x2 = CorrectRangeValue(xC + rangeX, 0, picture.Width - 1);
			int y2 = CorrectRangeValue(yC - rangeY, 0, picture.Height - 1);

			int pixelCount = 0;
			for (int y = y1; y <= y2; y++)
				for (int x = x1; x <= x2; x++)
				{
					var pixel = picture.GetPixel(x, y);
					r += pixel.R;
					g += pixel.G;
					b += pixel.B;
					pixelCount++;
				}

			avgColor.R = (double)r / pixelCount;
			avgColor.G = (double)g / pixelCount;
			avgColor.B = (double)b / pixelCount;

			return avgColor;
		}

		private void DoTestLabMouse()
		{
			if (picBmp == null) return;

			DontDoTestLab = true;

			//This code get the RGB value from a point or a region from the picture(picBmp is a Bitmap)

			lcmsRGBColor pixel = (chkRange.Checked)
									? GetAvgRGBFromBitmap(picBmp, picX, picY, (int)nupRange.Value)
									: new lcmsRGBColor(picBmp.GetPixel(picX, picY));

			rgbColor.FromColor(pixel);



			tbRed.Value = Convert.ToInt32(pixel.R);
			tbGreen.Value = Convert.ToInt32(pixel.G);
			tbBlue.Value = Convert.ToInt32(pixel.B);



			TestLabDBL();

			DontDoTestLab = false;
		}

		private void SetLabLChValues(lcmsCIELab tLab)
		{
			lblMyR.Text = "R: " + rgbColor.R.ToString("F2") + "(" + (rgbColor.R / 255).ToString("F2") + ")";
			lblMyG.Text = "G: " + rgbColor.G.ToString("F2") + "(" + (rgbColor.G / 255).ToString("F2") + ")";
			lblMyB.Text = "B: " + rgbColor.B.ToString("F2") + "(" + (rgbColor.B / 255).ToString("F2") + ")";

			lblL.Text = "L*: " + tLab.L.ToString("F2");
			lbla.Text = "a*: " + tLab.a.ToString("F2");
			lblb.Text = "b*: " + tLab.b.ToString("F2");

			var tLCh = tLab.ToLCh();
			var tXYZ = tLab.ToXYZ(pLab.WhitePoint);
			
			lbL.Text = "L: " + tLCh.L.ToString("F2");
			lbC.Text = "C: " + tLCh.C.ToString("F2");
			lbh.Text = "h: " + tLCh.h.ToString("F2");

			lX.Text = "X: " + tXYZ.X.ToString("F2");
			lY.Text = "Y: " + tXYZ.Y.ToString("F2");
			lZ.Text = "Z: " + tXYZ.Z.ToString("F2");

			if (currentLAB == null) currentLAB = new lcmsCIELab();

			currentLAB.L = tLab.L;
			currentLAB.a = tLab.a;
			currentLAB.b = tLab.b;
		}

		private void TestLabDBL()
		{
			pnlColor.BackColor = Color.FromArgb(tbRed.Value, tbGreen.Value, tbBlue.Value);

			lcmsCIELab labValues;

			double[] buffer = new double[3];

			buffer[0] = rgbColor.R / 255; //In - Red   Out - L			(In  - as input buffer)
			buffer[1] = rgbColor.G / 255; //In - Green Out - a			(Out - as output buffer)
			buffer[2] = rgbColor.B / 255; //In - Blue  Out - b

			var size = sizeof(double) * buffer.Length;

			IntPtr ptr = Marshal.AllocCoTaskMem(size);
			Marshal.Copy(buffer, 0, ptr, buffer.Length); //Copy the buffer to the pointer

			tRGBtoLabDBL.DoTransform(ptr, ptr, 1);

			Marshal.Copy(ptr, buffer, 0, buffer.Length); //Copy the transformed values in the pointer back to the buffer
			Marshal.FreeCoTaskMem(ptr);

			labValues = new lcmsCIELab(buffer[0], buffer[1], buffer[2]);

			SetLabLChValues(labValues);
			gbxConversion.Text = " RGB - LAB (double -> double)";
		}

		private void SetZoom()
		{
			int w = pbxOutput.Width;
			int h = pbxOutput.Height;
			picZL = CorrectRangeValue(picX - (w / 2), 0, picBmp.Width - 1);
			picZT = CorrectRangeValue(picY - (h / 2), 0, picBmp.Height - 1);

			if (picZT + h > picBmp.Height) picZT = picBmp.Height - h;
			if (picZL + w > picBmp.Width) picZL = picBmp.Width - w;

			Bitmap bmp2 = ImageUtil.Crop(picBmp, picZT, picZL, w, h, InterpolationMode.HighQualityBicubic);

			pbxOutput.SizeMode = PictureBoxSizeMode.Normal;

			pbxOutput.Image = bmp2;
			pbxOutput.Refresh();
		}

		private void pbx_MouseMove(object sender, MouseEventArgs e)
		{
			var pbx = (PictureBox)sender;
			var isIn = pbx.Equals(pbxInput);

			if (pbx.Image == null) return;
			if (isIn && IsPointSetIn) return;
			if (!isIn && IsPointSetOut) return;

			var bmp = pbx.Image as Bitmap;

			if (isIn)
			{
				picBmp = bmp;

				double factorH = (double)bmp.Height / pbx.Height;
				double factorW = (double)bmp.Width / pbx.Width;

				picX = CorrectRangeValue(Convert.ToInt32(e.X * factorW), 0, bmp.Width - 1);
				picY = CorrectRangeValue(Convert.ToInt32(e.Y * factorH), 0, bmp.Height - 1);

				lblX.Text = "X: " + e.X + " (" + picX + ")";
				lblY.Text = "Y: " + e.Y + " (" + picY + ")";

				SetZoom();
			}
			else
			{
				picBmp = pbxInput.Image as Bitmap;
				picX = CorrectRangeValue(picZL + e.X, 0, picBmp.Width - 1);
				picY = CorrectRangeValue(picZT + e.Y, 0, picBmp.Height - 1);
				lblX.Text = "X: " + picX;
				lblY.Text = "Y: " + picY;
			}

			DoTestLabMouse();
		}


		private void SetRange()
		{
			nupRange.Enabled = chkRange.Checked;
		}

		private void chkRange_CheckedChanged(object sender, EventArgs e)
		{
			SetRange();
			DoTestLabMouse();
		}



		private void pbxInput_Click(object sender, EventArgs e)
		{
			if (pbxInput.Image == null) return;
			IsPointSetIn = !IsPointSetIn;
		}

		private void nupRange_ValueChanged(object sender, EventArgs e)
		{
			DoTestLabMouse();
		}

		private void button1_Click_2(object sender, EventArgs e)
		{
			if (pbxInput.SizeMode == PictureBoxSizeMode.StretchImage)
			{
				pbxInput.SizeMode = PictureBoxSizeMode.AutoSize;
			}
			else
			{
				pbxInput.SizeMode = PictureBoxSizeMode.StretchImage;
			}
		}

		private void pbxOutput_Click(object sender, EventArgs e)
		{
			if (pbxOutput.Image == null) return;
			IsPointSetOut = !IsPointSetOut;
		}

		private void Form1_SizeChanged(object sender, EventArgs e)
		{
			pbxInput.Refresh();
		}

		private void tbRed_ValueChanged(object sender, EventArgs e)
		{
			lblRed.Text = tbRed.Value.ToString();
			TestLab();
		}

		private void tbGreen_ValueChanged(object sender, EventArgs e)
		{
			lblGreen.Text = tbGreen.Value.ToString();
			TestLab();
		}

		private void tbBlue_ValueChanged(object sender, EventArgs e)
		{
			lblBlue.Text = tbBlue.Value.ToString();
			TestLab();
		}

		private void chkMM_CheckedChanged(object sender, EventArgs e)
		{
			DoTestLabMouse();
		}

		private void btnProfiling_Click(object sender, EventArgs e)
		{
			var profilingForm = new Form2();
			profilingForm.ShowDialog();
		}

		private void cbxIntent_SelectedIndexChanged(object sender, EventArgs e)
		{
			var intent = (lcmsIntents)cbxIntent.SelectedItem;

			if (intent != _intent)
			{
				_intent = intent;

				CreateRGBtoLABTransforms();

				DoTestLabMouse();
				if (_intent == lcmsIntents.ABSOLUTE_COLORIMETRIC && cbxAdaptationState.SelectedIndex == 0)
					cbxAdaptationState.SelectedIndex = 1;
			}

			
		}

		private static List<double> listLAB = new List<double>();
		private static List<double> listLCH = new List<double>();
		private static List<double> listXYZ = new List<double>();
		private static List<double> listDE2K = new List<double>();

		private String ListDoubleToString(List<double> list)
		{
			String r = "";
			for (int i = 0; i < list.Count; i += 3)
				r += list[i] + "\t" + list[i + 1] + "\t" + list[i + 2] + "\t" + "\r\n";

			Clipboard.SetText(r);
			return r;
		}

		private void btnXYZ_Click(object sender, EventArgs e)
		{
			txtLAB.Text = ListDoubleToString(listXYZ);
		}

		private void btnDeltaE2K_Click(object sender, EventArgs e)
		{
			var sLAB = txtLAB.Text.Split();

			listLAB.Clear();
			listLCH.Clear();
			listXYZ.Clear();
			listDE2K.Clear();

			foreach (var item in sLAB)
				if (!String.IsNullOrEmpty(item)) listLAB.Add(Double.Parse(item));

			var A = new lcmsCIELab();
			var B = new lcmsCIELab();

			if (listLAB.Count % 2 != 0) 
			{
				txtLAB.Text = "Error!!! you  have to enter an even number of LAB values.";
				return;
			}

			int half = listLAB.Count / 2;

			for (int i = 0; i < half; i += 3)
			{
				A.L = listLAB[i];
				A.a = listLAB[i + 1];
				A.b = listLAB[i + 2];

				B.L = listLAB[half + i];
				B.a = listLAB[half + i + 1];
				B.b = listLAB[half + i + 2];

				listDE2K.Add(A.DeltaECIE2000(B,1,1,1));
			}

			String sDE2K = "";

			foreach (double item in listDE2K)
				sDE2K += item + "\r\n";
                               
			Clipboard.SetText(sDE2K);

			txtLAB.Text = sDE2K;
		}

		private void btnTEST_Click(object sender, EventArgs e)
		{
			//var sLAB = txtLAB.Text.Split();

			//listLAB.Clear();
			//listLCH.Clear();
			//listXYZ.Clear();
			//listDE2K.Clear();

			//foreach (var item in sLAB)
			//    if (!String.IsNullOrEmpty(item)) listXYZ.Add(Double.Parse(item));

			//var A = new lcmsCIEXYZ();
			//var B = new lcmsCIELab();

			//for (int i = 0; i < listXYZ.Count; i += 3)
			//{
			//    A.X = listXYZ[i];
			//    A.Y = listXYZ[i + 1];
			//    A.Z = listXYZ[i + 2];

			//    B.FromXYZ(A);

			//    listLAB.Add(B.L);
			//    listLAB.Add(B.a);
			//    listLAB.Add(B.b);
			//}

			listLAB.Add(currentLAB.L);
			listLAB.Add(currentLAB.a);
			listLAB.Add(currentLAB.b);

			txtLAB.Text = ListDoubleToString(listLAB);
		}

		private void btnLab_Click(object sender, EventArgs e)
		{
			var sLAB = txtLAB.Text.Split();

			listLAB.Clear();
			listLCH.Clear();
			listXYZ.Clear();

			foreach (var item in sLAB)
				if (!String.IsNullOrEmpty(item)) listLAB.Add(Double.Parse(item));

			var A = new lcmsCIELab();
			var B = new lcmsCIELCh();
			var C = new lcmsCIEXYZ();

			for (int i = 0; i < listLAB.Count; i+=3)
			{
				A.L = listLAB[i];
				A.a = listLAB[i + 1];
				A.b = listLAB[i + 2];

				B.FromLab(A);
				C.FromLab(pLab.WhitePoint, A);

				listLCH.Add(B.L);
				listLCH.Add(B.C);
				listLCH.Add(B.h);

				listXYZ.Add(C.X);
				listXYZ.Add(C.Y);
				listXYZ.Add(C.Z);
			}
			listLAB.Clear();
		}

		private void btnLCH_Click(object sender, EventArgs e)
		{
			txtLAB.Text = ListDoubleToString(listLCH);
		}

		private void cbxAdaptationState_SelectedIndexChanged(object sender, EventArgs e)
		{
			double dV = Convert.ToDouble(cbxAdaptationState.SelectedIndex);

			if (_AdaptationState != dV)
			{
				_AdaptationState = dV;

				CreateRGBtoLABTransforms();

				DoTestLabMouse();
			}
		}

		private void btnRestore_Click(object sender, EventArgs e)
		{
			OpenFileName();
		}

		private void cbxUseInput_CheckedChanged(object sender, EventArgs e)
		{
			if (pRGB != null) pRGB.Close();
			if (pLab != null) pLab.Close();

			pRGB = (cbxUseInput.Checked) ? lcmsProfile.OpenProfileFromFile(ProfileFilesIn[cbxInput.SelectedIndex]) : lcmsProfile.Create_sRGBProfile();
			pLab = (cbxTest.Checked) ? lcmsProfile.CreateLab4Profile(pRGB.WhitePoint) : lcmsProfile.CreateLab4Profile(lcmsWhitePoint.ICC_D50());
			

			CreateRGBtoLABTransforms();

			DoTestLabMouse();
		}

		private void cbxInput_SelectedIndexChanged(object sender, EventArgs e)
		{
			if(cbxUseInput.Checked) cbxUseInput_CheckedChanged(sender,e);
		}

		private void cbxTest_CheckedChanged(object sender, EventArgs e)
		{
			if (cbxUseInput.Checked) cbxUseInput_CheckedChanged(sender, e);
		}

	}
}



