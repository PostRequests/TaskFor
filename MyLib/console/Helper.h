#pragma once
#include <iostream>

/// <summary>
/// ���������, �������� �� text ������ �������� �� content
/// </summary>
/// <param name="text">����������� �����</param>
/// <param name="content">����������� �������</param>
/// <returns>True, ���� ��� ������� �� text ������������ � content, ����� false</returns>
bool includeContainsOnly(char* text, const char* content);
/// <summary>
/// ����������� ����� � ����� (����� ��������������� �������� bool isNumber(char* text))
/// </summary>
/// <param name="num">�����</param>
/// <returns>���������� ��������������� ����� �� ������</returns>
int strToInt(char* num);
/// <summary>
///  ���������, ����� �� ����� ������������ � ������������� �����
/// </summary>
/// <param name="text">����������� �����</param>
/// <returns>���������� true ���� text �������� ������� "1234567890-"</returns>
bool isNumber(char* text);