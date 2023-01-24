#include "MainForm.h"
#include <Windows.h>

using namespace System::Windows::Forms;
using namespace NumericalMethods;

[STAThread]
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew MainForm());
	return 0;
}
