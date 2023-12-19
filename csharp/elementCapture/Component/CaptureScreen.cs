using System.Drawing;
using System.Runtime.InteropServices;
using System.Drawing.Imaging;

namespace CaptureScreenNamespace
{
    public class CaptureScreenClass
    {
           // Defining the custom structural for storing rectBound value...
        [StructLayout(LayoutKind.Sequential)] // this is from System.Runtime.InteropServices package
        private struct RECTANGLE
        {
            public int Left;
            public int Top;
            public int Right;
            public int Bottom;
        }

        // import GetWindowRect() window API...
        [DllImport("user32.dll")]

        private static extern bool GetWindowRect(IntPtr hWnd, out RECTANGLE rect);
        public bool CaputureScreen(IntPtr WindowHandle, string fileName)
        {
            try
            {
                RECTANGLE windowRect;

                if (GetWindowRect(WindowHandle, out windowRect)) // this function return true or false
                {
                    int width = windowRect.Right - windowRect.Left;
                    int height = windowRect.Bottom - windowRect.Top;

                    using (Bitmap screenshot = new Bitmap(width, height, PixelFormat.Format32bppArgb)) // creating the width and height of the image
                    {
                        using (Graphics graphics = Graphics.FromImage(screenshot)) // accessing to Bitmap created image
                        {
                            graphics.CopyFromScreen(windowRect.Left, windowRect.Top, 0, 0, new Size(width, height), CopyPixelOperation.SourceCopy); //draw the image same as the screen appearing
                        }
                        screenshot.Save(fileName, ImageFormat.Jpeg);
                    }
                    return true;
                }
                return false;
            }
            catch (Exception error)
            {
                Console.WriteLine($"Some error while Screenshot: {error}");
                return false;
            }
        }
    }
}