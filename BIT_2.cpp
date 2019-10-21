// BIT_2.c

#include <stdio.h>
#include <locale.h>
#include "MyBITfuncs.h"


int main()
{
  integer_t x;
  setlocale(LC_ALL, "Russian");
  do
  {
    // ����
    x = BIT_Input();
    unsigned dec_width = BIT_count_dec_width(x);  // ������ � ���������� ����
    unsigned operand2;
    printf(" ������� ������� : ");
    scanf("%d", &operand2);

    // �������
    integer_t x_1reverse = BIT_reverse_bit_blocks(x, 1);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_1reverse));
    integer_t x_2reverse = BIT_reverse_bit_blocks(x, 2);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_2reverse));
    integer_t x_4reverse = BIT_reverse_bit_blocks(x, 4);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_4reverse));
    integer_t x_8reverse = BIT_reverse_bit_blocks(x, 8);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_8reverse));
    integer_t x_swap2 = BIT_reverse_IN_blocks(x, 2);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_swap2));
    integer_t x_swap4 = BIT_reverse_IN_blocks(x, 4);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_swap4));
    integer_t x_swap8 = BIT_reverse_IN_blocks(x, 8);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_swap8));
    integer_t x_cycleL = BIT_CycleLeft(x, operand2);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_cycleL));
    integer_t x_cycleR = BIT_CycleRight(x, operand2);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_cycleR));
    integer_t x_cycleL_b = BIT_CycleLeft_inBytes(x, operand2);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_cycleL_b));
    integer_t x_cycleR_b = BIT_CycleRight_inBytes(x, operand2);
    dec_width = max_2u(dec_width, BIT_count_dec_width(x_cycleR_b));

    // ����������
    BIT_Print("        �� �����+:", x, dec_width);
    BIT_Print(" ������ �� �����+:", x_1reverse, dec_width);
    BIT_Print(" ������ �� 2 ���+:", x_2reverse, dec_width);
    BIT_Print(" ������ �� 4 ��� :", x_4reverse, dec_width);
    BIT_Print(" ������ �������� :", x_8reverse, dec_width);
    BIT_Print(" ����� ��� � 2��+:", x_swap2, dec_width);
    BIT_Print(" ����� ��� � 4��+:", x_swap4, dec_width);
    BIT_Print(" ����� ��� � 8��+:", x_swap8, dec_width);
    BIT_Print("   ���� << �����+:", x_cycleL, dec_width);
    BIT_Print("   ���� >> �����+:", x_cycleR, dec_width);
    BIT_Print("���� << � ������+:", x_cycleL_b, dec_width);
    BIT_Print("���� >> � ������ :", x_cycleR_b, dec_width);

    printf("\n");

  } while (x); // ������� ������ �� ����� -> ����� == 0

  return 0;
}
