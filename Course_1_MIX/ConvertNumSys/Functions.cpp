#include <stdio.h>

int StrLenght(char str[]) {  // ����� ������ �� '\0'
  int len = 0;
  while (str[len]) len++;
  return len;
}

char convert_36_10(char sym)
{   // ���������� ������ char '0'-'9A'-'Z'  ->  � ����� char 0-35
  static char convertTable[] =  // static - �� ��������� ������ ���
  { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    // 0-15
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    // 16-31
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,    // 32-47
     0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,    // 48-63  ��� ����� 
    -1,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,    // 64-79  A-Z
    25,26,27,28,29,30,31,32,33,34,35,-1,-1,-1,-1,-1,    // 80-95
    -1,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,    // 96-111 a-z
    25,26,27,28,29,30,31,32,33,34,35,-1,-1,-1,-1,-1     // 112-127
  }; // -1 ������� ���������� �����, ���� ����� �� �������������� ;-)
  return convertTable[sym]; // ������ 0-127
}

void convertToBig(char array[], int len)
{   // � ������� array ������� ����� ���������� ��������� 0..9A..Z
    // ����������� ������� � ����� 0--35 � ��������� ������� ���� 
    // �� ������� �������� � �������
  int start = 0;
  int end = len - 1;
  while (start <= end)    // ��� � ����� ���� ������� �� ��������
  {                       // �������� ���� ������, ��� �����������
    char temp = convert_36_10(array[start]);
    array[start++] = convert_36_10(array[end]);
    array[end--] = temp;
  }
}

void printBig(char array[], int len)
{   // � ������� array ������� ����� �� ������� �������� � �������
    // ����������� ����� 0--35 � ������� 0..9A..Z � ��������� ������� ���� 
  char digits36[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int pos = len - 1;

  while (pos > 0 && !array[pos])
    pos--; // ��������� �� ������� �����, ����� ���������� (���� == 0)

  for (; pos >= 0; pos--) // �������� �����
    printf("%c", digits36[array[pos]]);
}


int isBigNum_lessThan(char array[], int len, int NS, int x)
{ // ���� ������� ����� � ������� ������ X => �� ���������� ��� �������� [0...X)
  // ����� -1
  int bigValue = 0;
  for (int i = len - 1; i >= 0; i--)      // ������� �������
  {
    bigValue = bigValue * NS + array[i];
    if (bigValue >= x) return -1;
  }
  return bigValue;
}


int BigDivide(char a[], int a_len, int NS, int divisor)
{ // � ������� A ������� ����� � �� NS (������ a_len ��������� � �������� �������)
  // ����� ��� �� divisor ��������� ����� ��� �� (�������� ��������� 0..0 � �������)
  // ���������� ������� �� �������
  int rest = 0;
  for (int i = a_len - 1; i >= 0; i--) // �������� �������, �� ������� ��������
  {
    int cur = rest * NS + a[i];
    a[i] = cur / divisor;
    rest = cur % divisor;
  }
  return rest;
}
