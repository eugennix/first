#pragma once
#pragma warning(disable:4996)   // for use scanf in VisualStudio
#define BIT_ZERO_SYM '.'        // ��� ������ �� �����
#define BIT_ONE_SYM '#'



// �������� ������������ ����������� ����� ------------------------------------------------
// typedef unsigned char integer_t;       // ������������� ������ ���� �� ���
// typedef unsigned short integer_t;
// typedef unsigned int integer_t;
 typedef unsigned long integer_t; 
// typedef unsigned long long integer_t;


// ��� ��� ����� / ������
typedef unsigned long long MaxInt;

// ������ --------------------------------------------------------------
integer_t BIT_Input();
  // ������ ������������� �����, ����������� ��� � ���� integer_t
unsigned int BIT_count_dec_width(integer_t x);
  // ����������, ������� ���� ����������� ��� 10�� ������������� �
unsigned int max_2u(unsigned int x1, unsigned int x2);
  // ������� ������������ �������� 2 �����
void BIT_Print(const char text[], integer_t x, unsigned int size_in_dec);
  // �������� � � ������ �������������� �� ������� ������

// ������� --------------------------------------------------------------
integer_t BIT_reverse_bit_blocks(integer_t x, unsigned int block_size);
  // ���������� ����� ������� ������ ������� block_size � ����� �, 
  // 1 - ������ �����, 2 - ������� b1b0 <-> b(n)b(n-1) ..., 4 - b3..b0 <-> 4 ������� ���� ...
  // 8 - �������� (������� ���� �� ������� � �.�.), ����� ������ ����� - �� ������ �
integer_t BIT_reverse_IN_blocks(integer_t x, unsigned int block_size);
   // ���������� ����� ����� ������ ������� ������ ������� block_size � ����� �, 
   // 1 - ������, 2 - ������ ���� �������� � ���������, 4 - ������ � ����� 4�� �����
   // 8 - ������ ����� � ������ �����, ����� ������ ����� - �� ������ �
integer_t BIT_CycleLeft(integer_t x, unsigned int shift);
  // ����������� ����� <---  ����� <--- 
integer_t BIT_CycleRight(integer_t x, unsigned  int shift);
  // ����������� ����� ---> ������ --->
integer_t BIT_CycleLeft_inBytes(integer_t x, unsigned  int shift);
  // ����������� ����� <---  ����� <--- (� ������ ����� ��������)
integer_t BIT_CycleRight_inBytes(integer_t x, unsigned int shift);
  // ����������� ����� ---> ������ ---> (� ������ ����� ��������)
