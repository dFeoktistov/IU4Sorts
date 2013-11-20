#include "profile.h"

#ifndef _WIN32
#error "This is not very cross-platform, I'm so sorry"
#endif

#include <Windows.h>
#pragma comment(lib, "winmm.lib") // ��� timeGetTime


double g_StartTime = -1.0f; // ��� �������� ������� �������
double g_LastElaspedTime = -1.0f;

void	PROF_StartProfile() {
	g_StartTime = timeGetTime();
	g_LastElaspedTime = -1.0f;
}

double	PROF_GetTimeElaspedMSec() {
	double locTime = timeGetTime();
	if (g_StartTime < 0) { // �� �������� ����������
		return (-1.0f); // ���� �� ��� ����� ��� �� ������ ������
	}
	else {
		g_LastElaspedTime = locTime;
		return (locTime - g_StartTime);
	}
}

double	PROF_GetDeltaTimeMSec() {
	double locTime = timeGetTime();
	if (g_LastElaspedTime < 0.0) return -1.0f;
	return (locTime - g_LastElaspedTime);
}


void	PROF_StopProfile() {
	g_StartTime = -1.0f;
	g_LastElaspedTime = 0.0f;
}

double	PROF_ProfileSort(int nElems,
	void (*sort_function)(void* array, int elem_size, int array_len, 
			int (*compare_function)(void* pA, void* pB), int ascending)
	) {
	// ������: ����������
	return 0.0;
}

void	PROF_PlotEfficiency(FILE* f,
	void (*sort_function)(void* array, int elem_size, int array_len, 
			int (*compare_function)(void* pA, void* pB), int ascending),
			int n_minElems, int n_maxElems) {

	// ������: ����������
}