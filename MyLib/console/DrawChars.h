#pragma once
#include "ANSI.h"
#include <iostream>
/// <summary>
/// �������� �����
/// </summary>
/// <param name="s">������ �����</param>
/// <param name="symbol">������� ����������</param>
/// <param name="color1">���� ������� ANSI</param>
/// <param name="color2">���� ������� ANSI</param>
void printRowChars(int s, char symbol, int color1 = 0, int color2 = 0);
/// <summary>
/// �������� �����
/// </summary>
/// <param name="s">������ �����</param>
/// <param name="l">������ ������ � �����</param>
/// <param name="c">������ ������� ����� ��������� ����� �����</param>
/// <param name="r">��������� ������ �����</param>
/// <param name="color1">���� ������� ANSI (�� ������������ ��������)</param>
/// <param name="color2">���� ������� ANSI (�� ������������ ��������)</param>
void printRowChars(int s, char l, char c, char r, int color1 = 0, int color2 = 0);
/// <summary>
/// �����������/������� ������� ������������� 
/// </summary>
/// <param name="posX">������� ������</param>
/// <param name="posY">������� �������</param>
/// <param name="rows">���������� ������������� �����</param>
/// <param name="cols">���������� ������������� �������</param>
/// <param name="color">�������� ����� (��������� ������ ������ ���)</param>
void drawFillRectangle(int posX, int posY, int rows, int cols, int color = 0);
/// <summary>
/// ������ ������� � �������� �������
/// </summary>
/// <param name="sX">� - ����� ������� ����������</param>
/// <param name="sY">� - ����� ������� ����������</param>
/// <param name="eX">� - ������ ������ ����������</param>
/// <param name="eY">� - ������ ������ ����������</param>
/// <param name="color">���� �����</param>
void drawEmptyRectangle2(int sX, int sY, int eX, int eY, int color = 0);
/// <summary>
/// �������� ����� �� ��������
/// </summary>
/// <param name="text">�����</param>
/// <param name="totalLen">������ ������</param>
void centerWord(const char* text, int totalLen);
