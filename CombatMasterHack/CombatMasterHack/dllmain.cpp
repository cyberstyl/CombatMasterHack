#include "Includes.hpp"

void Main(LPVOID lpParam)
{
	if (AllocConsole()) {
		FILE* file;
		freopen_s(&file, "CONOUT$", "w", stdout);
		SetConsoleTitleA("Debug Console");
	}

	Il2CppWrapper::il2cpp_thread_attach();
	printf("Il2CppWrapper Attached\n");

	Hooks::Init();
	printf("Hooks Initialized\n");

	while (!GetAsyncKeyState(VK_END))
		Sleep(100);

	Hooks::UnInit();
	printf("Hooks Unloaded\n");

	FreeConsole();
	fclose(stdout);
	FreeLibraryAndExitThread(static_cast<HMODULE>(lpParam), EXIT_SUCCESS);
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH) {
		if (HANDLE thread = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Main), module, NULL, nullptr))
			CloseHandle(thread);
	}

   return TRUE;
}