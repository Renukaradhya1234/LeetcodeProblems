using System;
using System.Runtime.InteropServices;
using System.Drawing; // add System.Drawing in references..
using System.Drawing.Imaging; // add System.Drawing in references..
using System.Diagnostics;

namespace CaptureAutomationElement
{
    class CaptureScreen
    {
        // import GetForegroundWindow() window API...
        [DllImport("user32.dll", SetLastError = true)]
        private static extern IntPtr GetForegroundWindow();

        // import GetWindowThreadProcessId() window API...
        [DllImport("user32.dll")]
        public static extern int GetWindowThreadProcessId(IntPtr hWnd, out int ProcessId);

        // import GetWindowRect() window API...
        [DllImport("user32.dll")]
        private static extern bool GetWindowRect(IntPtr hWnd, out RECTANGLE rect);

        // Defining the custom structural for storing rectBound value...
        [StructLayout(LayoutKind.Sequential)]
        private struct RECTANGLE
        {
            public int Left;
            public int Top;
            public int Right;
            public int Bottom;
        }

        // Method to capture the screenshot and Store in the file...
        public bool CaptureScreenShot(IntPtr windowId, Process filenameProcess)
        {
            RECTANGLE windowRect;

            if (GetWindowRect(windowId, out windowRect))
            {
                int width = windowRect.Right - windowRect.Left;
                int height = windowRect.Bottom - windowRect.Top;

                using (Bitmap screenshot = new Bitmap(width, height, PixelFormat.Format32bppArgb)) // creating the width and height of the image
                {
                    using (Graphics graphics = Graphics.FromImage(screenshot)) // accessing to Bitmap created image
                    {
                        graphics.CopyFromScreen(windowRect.Left, windowRect.Top, 0, 0, new Size(width, height), CopyPixelOperation.SourceCopy); //draw the image same as the screen appearing
                    }
                    screenshot.Save($@"C:\Users\Admin\Desktop\practice\company_program_dotnet\Automation_Element\CaptureAutomationElement\react\src\images\{filenameProcess.ProcessName}{filenameProcess.Handle}.jpeg", ImageFormat.Jpeg);
                    return true;
                }
            }
            return false;
        }
    }
}
