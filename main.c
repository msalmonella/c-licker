#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define KEY_F7 0x76
#define KEY_F4 0x73

int main()
{
	int number;
	number = 0;
	printf("Enter CPS value: ");
	scanf("%d", &number);
	printf("Press F6 to toggle enable or disable.");
	bool enabled = false;

	while (true)
	{
		if (GetAsyncKeyState(KEY_F7) & 0x8000)
		{
			while (GetAsyncKeyState(KEY_F7) & 0x8000)
				Sleep(10);
			enabled = !enabled;
			printf(enabled ? ":ON\n" : ":OFF\n");
		}

		if (GetAsyncKeyState(KEY_F4) & 0x8000)
		{
			printf("Enter CPS value: ");
			scanf("%d", &number);
			printf("Press F6 to toggle enable or disable.\n");
		}

		if (enabled && number > 0)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(1000 / number);
		}
		else
		{
			Sleep(15); // idle: yield the CPU instead of spinning
		}
	}
}
