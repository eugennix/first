#include <stdio.h>
#include <stdlib.h>           // ��� ��������� ������
          
// #define DEBUG                 // �������
#define DST_BUFFER_SIZE 5     // ������ ���������� ������

unsigned int STR_Lenght(char const* str) {  // ����� ������ �� '\0'
  int len = 0;
  if (NULL != str)
    while (*str++) len++;
  return len;
}

int STR_IsEmpty(char const* str)
{ // 1 - ���� ������ ������, ����� 0
  return ((NULL != str) && *str) ? 0 : 1;
}

int IsAlNum(char c) {
  // ����������, ��� �������� ���������� ������ � ������ ������
  // 1 - ���� [A�Z] ��� [a�z] ��� [0�9], ����� - 0
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

char* STR_FindNextWord(char const* str) {
  // ���������� ��������� �� ��������� ����� � str ��� �� ����� ������
  while (*str && !IsAlNum(*str)) str++;
  return (char*)str;
}

char* STR_FindNextSeparator(char const* str) {
  // ���������� ��������� �� ��������� ������� � str ��� �� ����� ������
  while (*str && IsAlNum(*str)) str++;
  return (char*)str;
}

int STR_Compare_FixLen(char const* str1, char const* str2, unsigned int distance)
{ // ���������� ������ �� ����� distance, ������� 1 ���� �����, 0 �����
  while (distance--)
    if (*(str1++) != *(str2++)) // �� ������� ������������
      return 0;
  return 1;
}

void STR_TransliterateSym(char* str)
{  // �������������� 1 �������� �������, � ������ ������ ���� ������� 5 ����� �����
   // �� �������� - ������ ��� �� �� 29 ����� 2016 �. N 4271
  switch (*str)
  {
  case '�': str[0] = 'a'; str[1] = '\0'; break;
  case '�': str[0] = 'A'; str[1] = '\0'; break;
  case '�': str[0] = 'b'; str[1] = '\0'; break;
  case '�': str[0] = 'B'; str[1] = '\0'; break;
  case '�': str[0] = 'v'; str[1] = '\0'; break;
  case '�': str[0] = 'V'; str[1] = '\0'; break;
  case '�': str[0] = 'g'; str[1] = '\0'; break;
  case '�': str[0] = 'G'; str[1] = '\0'; break;
  case '�': str[0] = 'd'; str[1] = '\0'; break;
  case '�': str[0] = 'D'; str[1] = '\0'; break;
  case '�':
  case '�': str[0] = 'e'; str[1] = '\0'; break;
  case '�': 
  case '�': str[0] = 'E'; str[1] = '\0'; break;
  case '�': str[0] = 'z'; str[1] = 'h'; break; str[2] = '\0'; break;
  case '�': str[0] = 'Z'; str[1] = 'h'; break; str[2] = '\0'; break;
  case '�': str[0] = 'z'; str[1] = '\0'; break;
  case '�': str[0] = 'Z'; str[1] = '\0'; break;
  case '�':
  case '�': str[0] = 'i'; str[1] = '\0'; break;
  case '�':
  case '�': str[0] = 'I'; str[1] = '\0'; break;
  case '�': str[0] = 'k'; str[1] = '\0'; break;
  case '�': str[0] = 'K'; str[1] = '\0'; break;
  case '�': str[0] = 'l'; str[1] = '\0'; break;
  case '�': str[0] = 'L'; str[1] = '\0'; break;
  case '�': str[0] = 'm'; str[1] = '\0'; break;
  case '�': str[0] = 'M'; str[1] = '\0'; break;
  case '�': str[0] = 'n'; str[1] = '\0'; break;
  case '�': str[0] = 'N'; str[1] = '\0'; break;
  case '�': str[0] = 'o'; str[1] = '\0'; break;
  case '�': str[0] = 'O'; str[1] = '\0'; break;
  case '�': str[0] = 'p'; str[1] = '\0'; break;
  case '�': str[0] = 'P'; str[1] = '\0'; break;
  case '�': str[0] = 'r'; str[1] = '\0'; break;
  case '�': str[0] = 'R'; str[1] = '\0'; break;
  case '�': str[0] = 's'; str[1] = '\0'; break;
  case '�': str[0] = 'S'; str[1] = '\0'; break;
  case '�': str[0] = 't'; str[1] = '\0'; break;
  case '�': str[0] = 'T'; str[1] = '\0'; break;
  case '�': str[0] = 'u'; str[1] = '\0'; break;
  case '�': str[0] = 'U'; str[1] = '\0'; break;
  case '�': str[0] = 'f'; str[1] = '\0'; break;
  case '�': str[0] = 'F'; str[1] = '\0'; break;
  case '�': str[0] = 'k'; str[1] = 'h'; str[2] = '\0'; break;
  case '�': str[0] = 'K'; str[1] = 'h'; str[2] = '\0'; break;
  case '�': str[0] = 't'; str[1] = 's'; str[2] = '\0'; break;
  case '�': str[0] = 'T'; str[1] = 's'; str[2] = '\0'; break;
  case '�': str[0] = 'c'; str[1] = 'h'; str[2] = '\0'; break;
  case '�': str[0] = 'C'; str[1] = 'h'; str[2] = '\0'; break;
  case '�': str[0] = 's'; str[1] = 'h'; str[2] = '\0'; break;
  case '�': str[0] = 'S'; str[1] = 'h'; str[2] = '\0'; break;
  case '�': str[0] = 's'; str[1] = 'h'; str[2] = 'c'; str[3] = 'h'; str[4] = '\0'; break;
  case '�': str[0] = 'S'; str[1] = 'h'; str[2] = 'c'; str[3] = 'h'; str[4] = '\0'; break;
  case '�': str[0] = 'y'; str[1] = '\0'; break;
  case '�': str[0] = 'Y'; str[1] = '\0'; break;
  case '�': str[0] = 'i'; str[1] = 'e'; str[2] = '\0'; break;
  case '�': str[0] = 'I'; str[1] = 'e'; str[2] = '\0'; break;
  case '�': str[0] = '\''; str[1] = '\0'; break; // � ������� �� �� ����������
  case '�': str[0] = '\''; str[1] = '\0'; break; // ���������� '
  case '�': str[0] = 'e'; str[1] = '\0'; break;
  case '�': str[0] = 'E'; str[1] = '\0'; break;
  case '�': str[0] = 'i'; str[1] = 'u'; str[2] = '\0'; break;
  case '�': str[0] = 'I'; str[1] = 'u'; str[2] = '\0'; break;
  case '�': str[0] = 'i'; str[1] = 'a'; str[2] = '\0'; break;
  case '�': str[0] = 'I'; str[1] = 'a'; str[2] = '\0'; break;
  default:
    break;
  }
}

int STR_CompareByMask(char const* str, char const* mask)
{ // ���������� ������ � ������, ������� 1 ���� ��������, 0 �����
  // ������ �������� ? - ����� ������, * - ����� ������ �������� ��� ������
  if (*str == 0 && *mask == 0)
    return 1;                 // ������������ ����� �� ����� ����� �����
  if (*str == 0)
  {                           // ������ �����������, ���� ���� ������ ��� '*'
    if (*mask == '*')
      return STR_CompareByMask(str, mask+1);  // ����������� ����� �� *
    else return 0;
  }
  else if (*mask == '?' || *mask == *str)     // ������� ������� ��� ������ '?'
    return STR_CompareByMask(str+1, mask+1);  // ����������� ��� ������
  else if (*mask == '*')
  { // ��� ������ ������� '*' ��������� ��������, ���� �����������, �� ����� �������
    
    // ������� 1 - ���������� ������ ������, ������ ������� �� '*'
    if (STR_CompareByMask(str+1, mask)) return 1;
      
    // ������� 2 - ���������� ��� ������
    if (STR_CompareByMask(str+1, mask+1)) return 1;
    
    // ������� 3 - ���������� �����, ����� ���������� ���������
    return STR_CompareByMask(str, mask+1);
  }
  else return 0; // �� ������� �������, ��� ����������� �����, � ������ ���
}

int STR_FindWord(char const* str, char* word, unsigned int pos)
{ // ���� � ������ str � ������� pos ����� word
  // return - ������� (�� ������ ������) ��� -1 == �� �������
  char const* str_ptr = str + pos;
  int word_len = STR_Lenght(word);
  int str_len = STR_Lenght(str);
  if (word_len && str_len)
  {  
    char const* limit = str + str_len - word_len;  // �� ���� ������
    while (str_ptr <= limit)
    {
      str_ptr = STR_FindNextWord(str_ptr);
      if (!(*str_ptr))  // ����������� ����� � ������
        break;
      if (STR_Compare_FixLen(str_ptr, word, word_len)) // ������� ������
        // �� �������� ��� �����������, ����� �� ������������
        if (! IsAlNum(*(str_ptr + word_len))) 
          return (str_ptr - str); // ����� �������
      str_ptr = STR_FindNextSeparator(str_ptr);
    }
  }
  return -1;
}

int STR_FindSubStr(char const* str, char* subStr, unsigned int pos)
{ // ���� � ������ str � ������� pos ��������� subStr 
  // return - ������� (�� ������ ������) ��� -1 == �� �������
  char const* str_ptr = str + pos;
  int subStr_len = STR_Lenght(subStr);
  int str_len = STR_Lenght(str);
  if (subStr_len && str_len)
  {
    char const* limit = str + str_len - subStr_len;  // �� ���� ������
    while (str_ptr <= limit)                         // �����
    { 
      if(STR_Compare_FixLen(str_ptr, subStr, subStr_len))
          return (str_ptr - str);                    // �����
      str_ptr++;
    }
  }
  return -1;                                        // �� �����
}

unsigned int WordLen(char const* str) {
  // ���������� ����� ����� �� ������ str
  return STR_FindNextSeparator(str) - str; 
}

unsigned int CountWords(char const* str) {
  // ���������� ���������� ���� � str
  unsigned int counter = 0;
  while(*(str = STR_FindNextWord(str))) // ���� �� ������ ����� ������ \0
  { 
    counter++;
    str = STR_FindNextSeparator(str);
  }
  return counter;
}

unsigned int CountSymbols(char const* str) {
  // ���������� ���������� ���� � str
  unsigned int counter = 0;
  while (*str)
    counter += IsAlNum(*str++);
  return counter;
}

unsigned int CountChar(char const* str, char x) {
  // ������� ��������� � ������ ������� X
  unsigned int counter = 0;
  while (*str)
    if(x == (*str++)) counter++;
  return counter;
}

char* FindChar(char const* str, char x, int start) {
  // ������� ��������� � ������ ������� X, ��� ����� ������ '\0'
  str += start;     // �� ������ ������
  while (*str)
    if (x == (*str)) return (char*)str;  // ����� ����� ������� ���������� �
    else str++;
  return (char*)str;  // ��� ����� ����� ����� ������ '\0'
}

unsigned int CountSeparators(char const* str) {
  // ���������� ���������� ������ � str
  unsigned int counter = 0;
  while (*str)
    counter += IsAlNum(*str++) ? 0 : 1;
  return counter;
}

char* AllocateString(unsigned int size)
{ // �������� ����� ��� ������ �������� (size + 1)
  char* new_str = (char*)malloc(size + 1);
  if(NULL != new_str)
    *new_str = '\0';   // �� ������ ������ � ������ ������ ����� ������
  return new_str;
}

char* CopyString(char const* str)
{ // ������ ����� ������ == str
  unsigned int str_size = STR_Lenght(str);
  char* new_str = (char*)malloc(str_size + 1);
  if (NULL != new_str)
  {
    char const* pOrigin = str;
    char* pNew = new_str;
    // ��������, ��������� ������������� ����� ����� ������ '\0'
    while (*(pNew++) = *(pOrigin++)) {};  
  }
  return new_str;
}

char* STR_GetChars(char const* str, int start, int end)
{ // ������ ����� ������ == str[start...end]
  if (start > end) return NULL;
  unsigned int str_size = end - start;
  char* new_str = (char*)malloc(str_size + 1);
  if (NULL != new_str)
  {
    char const* pOrigin = str + start;
    char const* pEnd = str + end;
    char* pNew = new_str;
    // ��������, ��������� ������������� ����� ����� ������ '\0'
    while (pOrigin <= pEnd && *pOrigin)  // �������� ����� [start..end] ��� �� ����� '\0'
      { *(pNew++) = *(pOrigin++); }
    pNew = '\0';   // ����� ������
  }
  return new_str;
}

char* OnlyOneSpace(char const* str)
{ // ������ ����� ������ == str, ��������� �������� ������ ���������� �� ����
  // � ������ ������ ������� ���������
  unsigned int str_size = STR_Lenght(str);
  // ������� ����� �� ������ ���������
  char* new_str = (char*)malloc(str_size + 1);
  if (NULL != new_str)
  {
    char const* pOrigin = str;
    char* pNew = new_str;
    int isPredSpase = 1;    // ������, ��� ������� � ������ ������ �� �����
    do
    {
      if (*pOrigin == ' ')  // ������ ������
      {
        if (!isPredSpase)   // ������ �������� ������ ���� ����� ��� ��� ��������
          { *(pNew++) = *(pOrigin++); }
        else
          { pOrigin++; }    // ��� ������ => �� ��������, ������ �������� ���������
        isPredSpase = 1;    // ���������, ��� ��� ������
      }
      else
      {
        *(pNew++) = *(pOrigin++);  // �������� �� ������
        isPredSpase = 0;  // ���������, ��� ��� �� ������
      }
    } while (*pOrigin);   // ��������, ���� �� ����� ������
    *pNew = '\0';         // ����� ������
  }
  // ������ �������� �����������, ���������������� ������ ? ��� �� ���� ?? �� ����
  // new_str = (char*)realloc(new_str, STR_Lenght(new_str) + 1);
  return new_str;
}

void CopySymbols(char const* strFrom, char* strTo, unsigned int number)
{ // �������� ������� � ������� strFrom -> strTo, � ���������� number
  while (number--)
    *(strTo++) = *(strFrom++);
}

unsigned int DST_InputStr(char** str, char const* text)
// ������ ������ ������������ �����, �������������� �������� ������
// � *str ���������� ��������� �� ������, return ���������� ����� ������
{
  printf("%s", text);
  char* result_str = NULL;  // ��� ��������� �� �������� ������, ��� ����������� ����
  unsigned int str_len = 0; // ����������� ����� ������, � ����� - ����������
  char buffer[DST_BUFFER_SIZE + 1] = { 0 }; // ��� ������ �����
  
  while (1)  // ��������� ������ �������� ������� DST_BUFFER_SIZE
  {
    // fgets ������ �� 1 ������ ������, ��� ��� � ����� ������ ��������� '\0'
    unsigned int input_len = STR_Lenght(fgets(buffer, DST_BUFFER_SIZE + 1, stdin));

#ifdef DEBUG    
    printf("\n��������� %u �������� ", input_len);
#endif

    if (buffer[input_len - 1] == '\n')
    {
      buffer[--input_len] = '\0';  // �������� '\n' -> '\0', ��������� �����
#ifdef DEBUG
      printf(" {CR ������ [%u], �����} ", input_len);
#endif
    }

#ifdef DEBUG
    printf("\"%s\"\n", buffer); 
#endif
    // ������ ����� ����� ������
    char * new_str = (char*)realloc(result_str, str_len + input_len + 1);
    
    if (NULL == new_str)  // ��������� ������ �� �������, ���������� ��� ����
    { printf("No more memory\n");
      break;
    }
    else 
    {
      result_str = new_str;                   //  ��������� �������� ��� � ������ �����
      // ������ ������ ��� ���������, ���������� �� ����� ��������� ������ 
      char* res_pointer = result_str + str_len;  
      char* in_pointer = buffer;                  // ��������� ��������� ������ �� buffer
      while (*res_pointer++ = *in_pointer++) {};  // �������� ���� �� '\0' � ����� buffer

      str_len += input_len;  // ����� ����� ������
#ifdef DEBUG
      printf("���� ������� %u ��������, \"%s\"\n", str_len, result_str);
#endif
      // ����������� �� ���� ������� ����� => ���� ��������
      if (input_len < DST_BUFFER_SIZE)
        break;
    }
  }
  *str = result_str;
  return str_len;
}

int STR_Joint_Separ_Str(char** str, char const* separator, char const* appendStr)
{ // ��������� ������ str, �������� � ��� + separator + appendStr
  // separator ����������� ������ ���� str �� ������
  // ���������� ����� ������������

  unsigned int origin_len = STR_Lenght(*str);
  unsigned int separator_len = STR_Lenght(separator);
  unsigned int append_len = STR_Lenght(appendStr);
  unsigned int new_len = 
     (origin_len ? origin_len + separator_len : 0) + append_len + 1;
  char* new_memory = (char*)realloc(*str, new_len);
  if (NULL == new_memory)
    return 0;
  *str = new_memory;   // �������� ��������� ���������
  char* str_ptr = new_memory + origin_len;  // ��������� �� ����� ����������

  if (origin_len)      //  ��� �������� ������ ��������� �����������
    while (*separator)
      *str_ptr++ = *separator++;

  while (*appendStr)   // �������� 2� ������
    *str_ptr++ = *appendStr++;
  *str_ptr = '\0';     // ����� ������

  return (origin_len ? separator_len : 0) + append_len;
}

char* STR_GetFirstWord(char const* str)
{ // �� str ����� ������ ����� � ����� ��������� ������, ��� NULL
  char* word_ptr = STR_FindNextWord(str);
  if (! *word_ptr)                 // ���� �� �������
    return NULL;
  char* word_end = STR_FindNextSeparator(word_ptr);
  unsigned int word_len = word_end - word_ptr;

  char* new_string = (char*)malloc(word_len + 1);   // �������� ������
  if (NULL == new_string)         // ��������� ������ �� �������
    return NULL;

  char* new_str_ptr = new_string; // �����������
  while (word_len--)
    *(new_str_ptr++) = *(word_ptr++);
  *new_str_ptr = '\0';            //  ����� ������
  return new_string;
}

char* STR_GetOnlyLetters(char const* str)
{ // �� str ����� ������ ����� � ����� ��������� ������
  unsigned int letters = CountSymbols(str);

  char* new_string = (char*)malloc(letters + 1);
  if (NULL == new_string)         // ��������� ������ �� �������
    return NULL;

  char* new_str_ptr = new_string; // �����������
  char const* old_str_ptr = str;
  while (*old_str_ptr)            // ���� �� ����� ������
    if (IsAlNum(*old_str_ptr))    //   �������� ������ �����
      *(new_str_ptr++) = *(old_str_ptr++);
    else
      old_str_ptr++;              // ������� - ����������
  
  *new_str_ptr = '\0';            //  ����� ������
  return new_string;
}

char* STR_ReverseInStr(char *str, int start, int end)
{ // str[start...end] <- str[end...start] , �.�. � �������� �������
  char* p1 = str + start;
  char* p2 = str + end;
  while (p1 < p2) 
  {
    char temp = *p1;
    *(p1++) = *p2;
    *(p2--) = temp;
  }
  return str;  // ������� ������ �� ������ ������
}

char* STR_ReverseAllStr(char* str)
{ // ������ ������
  char* p1 = str;
  char* p2 = str + STR_Lenght(str) - 1;
  while (p1 < p2)
  {
    char temp = *p1;
    *(p1++) = *p2;
    *(p2--) = temp;
  }
  return str;  // ������� ������ �� ������ ������
}

// XXXXXXXXXXXXXXXXX   �������     XXXXXXXXXXXXXXXXXXXXXXXX

char* ExtractLetters(char const* str, char const* newSeparator)
{ // ����� ������, ����� �� str ��������� ����� ������������
  unsigned int sepLenght = STR_Lenght(newSeparator);
  int symbols = CountSymbols(str);
  unsigned int new_string_size = symbols ? (symbols + (symbols - 1) * sepLenght) : 0;
  char* result = AllocateString(new_string_size);
  if (NULL == result)  // ��������� ������ �� �������
    return result;
  char* result_p = result;
  int wasFirstWord = 0;

  while (*str)
  {
    if (IsAlNum(*str))
    {
      if (wasFirstWord++)  // ����������� �� ����� ������ ����� ������ ������
      {   
        CopySymbols(newSeparator, result_p, sepLenght);
        result_p += sepLenght;
      }
      *result_p++ = *str; // ��� �������� ������ � ����� ������
    }
    str++;                // ��������� ������
  }
  *result_p = '\0';       // ����� ������
  return result;
}

char* ExtractWords(char const* str, char const* newSeparator)
{ // ����� ������, ����� �� str ��������� ����� ������������
  char const* str_ptr = str;
  char* next_word = NULL; // ��������� ����� (�������� ��������)
  char* result = AllocateString(0);    // ��� ����������� ���������
 
  while (next_word = STR_GetFirstWord(str_ptr))
  {
    unsigned int next_word_len = STR_Lenght(next_word);
    int added = STR_Joint_Separ_Str(&result, newSeparator, next_word);

    free(next_word);      // ������� �����, ��� ��� �� �����
    if (!added)  // ���������� �� �������, ���������� �� ��� ����
      break;
    // ������� ��������� - ������� ������ �����, �� ���� - ����� �����
    str_ptr = STR_FindNextWord(str_ptr) + next_word_len;
  }
  return result;
}

char* ExtractUniqueWords(char const* str, char const* newSeparator)
{ // ����� ������, ���������� ����� �� str ��������� ����� ������������
  char const* str_ptr = str;
  char* next_word = NULL; // ��������� ����� (�������� ��������)
  char* result = AllocateString(0);    // ��� ����������� ���������

  while (next_word = STR_GetFirstWord(str_ptr))
  {
    unsigned int next_word_len = STR_Lenght(next_word);

    if (STR_FindWord(result, next_word, 0) == -1) 
    { // ����� ��� �� ���� � ������
      int added = STR_Joint_Separ_Str(&result, newSeparator, next_word);
      if (!added)  // ���������� �� �������, ���������� �� ��� ����
      {
        free(next_word);      // ������� �����, ��� ��� �� �����
        break;
      }
    }
    free(next_word);      // ������� �����, ��� ��� �� �����
    // ������� ��������� - ������� ������ �����, �� ���� - ����� �����
    str_ptr = STR_FindNextWord(str_ptr) + next_word_len; 
  }
  return result;
}

char* ExtractUniqueLetters(char const* str, char const* newSeparator)
{ // ����� ������, ���������� ����� �� str ��������� ����� ������������
  char const* str_ptr = str;
  char* result = AllocateString(0);    // ��� ����������� ���������
  char letter[] = "x";    // �� ������ ������ ��� ������, ���������� ���

  while (*(str_ptr = STR_FindNextWord(str_ptr)))
  {
    letter[0] = *str_ptr; // ������ �� ����� �����
    if (STR_FindWord(result, letter, 0) == -1)
    { // ����� ��� �� ���� � ������
      int added = STR_Joint_Separ_Str(&result, newSeparator, letter);
      if (!added)  // ���������� �� �������, ���������� �� ��� ����
        break;
    }
    str_ptr++;    // ������� ��������� - �� ��������� �����
  }
  return result;
}

char* FindMirrors(char const* str, char const* newSeparator)
{ // ����� ������, �� str ������� ����������� � ������� 
  // ��� ��������� ������� 1, ������� ���� � ���������� ����,
  // ��� ��������� ����� ������������
  
  char* result = AllocateString(0);          // ��� ����������� ���������
  char* str_syms = STR_GetOnlyLetters(str);  // ��� ������ �����
  if (NULL == str_syms)                      // ���� ���
    return result;
  unsigned int syms_len = STR_Lenght(str_syms);
  // �� ���� ��������� ������ ��� ����� ������ � �����
  char* buff = AllocateString(syms_len);

  char* str_ptr = str_syms; // ����� � ������� �������
  
  while (syms_len) // ����� ��������� ���������� �����
  { // ������ ��������� ������� �� str_ptr � �� ����� ������ ������ > 1
    for (unsigned int i = 2; i <= syms_len; i++)
    {
      CopySymbols(str_ptr, buff, i);                // ����������� � buff
      STR_ReverseInStr(buff, 0, i - 1);             // �����������
      *(buff + i) = '\0';                           // ����� ������

      if (STR_FindSubStr(str_syms, buff, 0) != -1)  // ���� �� ���� ������ ��������
      { // �����, ��������, ����� ����� ��� ���� � ������ ����������
        STR_ReverseInStr(buff, 0, i - 1);           // ����������� �������
        if (STR_FindWord(result, buff, 0) == -1)    // ��� ����� �����
          if (!STR_Joint_Separ_Str(&result, newSeparator, buff))
          { // ���� ������������ ����������, ������� ��� ����
            free(buff);
            free(str_syms);
            return result;
          }
      }
    }
    str_ptr++;                   // ������������� �� ���������� �������
    syms_len--;                             // �������� �� ����� ������
  }
  free(str_syms);   // ������ ���� ������ �� �����
  free(buff);
  return result;
}

char* FindMaskWords(char const* str, char const* mask, char const* newSeparator)
{ // ����� ������, ��� ��������� �� str �� ����� ������, ��������� ����� ������������
  char const* str_ptr = str;
  char* next_word = NULL; // ��������� ����� (�������� ��������)
  char* result = AllocateString(0);    // ��� ����������� ���������

  while (next_word = STR_GetFirstWord(str_ptr))
  {
    unsigned int next_word_len = STR_Lenght(next_word);
    if (STR_CompareByMask(next_word, mask))    // �������� �� ����� ?
      if (! STR_Joint_Separ_Str(&result, newSeparator, next_word))  
      { // ���������� �� �������, ���������� �� ��� ����
        free(next_word);      // ������� �����, ��� ��� �� �����
        break;
      }
    free(next_word);      // ������� �����, ��� ��� �� �����
    // ������� ��������� - ������� ������ �����, �� ���� - ����� �����
    str_ptr = STR_FindNextWord(str_ptr) + next_word_len;
  }
  return result;
}

char* ConvertRussian(char const* str)
{ // ����� ������, �������������� ������� ��������, 
  // �� �������� - ������ ��� �� �� 29 ����� 2016 �. N 4271

  char const* str_ptr = str;
  char* result = AllocateString(0);    // ��� ����������� ���������
  char letter[5] = { 0 };    // �� ������ ������ ��� ������, ���������� ���

  while (*str_ptr)
  {
    letter[0] = *str_ptr; // ������ �� ����� �����
    letter[1] = '\0';
    STR_TransliterateSym(letter);
    int added = STR_Joint_Separ_Str(&result, "", letter);
    if (!added)  // ���������� �� �������, ���������� �� ��� ����
      break;
    str_ptr++;    // ������� ��������� - �� ��������� �����
  }
  return result;
}

// tele logo gole elemengo gote noga gano ngotole
char* STR_MakeChain(char * first_word, char * second_word)
{ // �������� ����������� ����� ��� FindChains, ����� NULL
  char* result = NULL;
  unsigned int f_len = STR_Lenght(first_word);
  unsigned int s_len = STR_Lenght(second_word);
   
  // ����� ��������� ����� �� ����������, ���������� ������� ������ ����� ������
  // ��������, ���� ������ 2 ������� ������������� - ����������� (f_len - 2)
  // ������ ����� ������ ����� �� �����, � ������ - �� ���������� ������ �������
  // 
  for (unsigned second_shift = 0; second_shift <= (f_len - 2); second_shift++)
  {
    char* f_ptr = first_word + second_shift;  // ����� ������� ����� ���������� �� ������ :-)
    char* s_ptr = second_word;

    // ���� �� ��������� ������ ����� � ��� ����������
    while (*f_ptr && (*(f_ptr) == *(s_ptr))) { 
      f_ptr++; 
      s_ptr++;
    }

    if ((*f_ptr) == 0) // ��������� ����� ������� �����, � �� ������� ��������
    { // ������ ����� ���������, ������ - ������ ������� �������, �.�. �� second_shift
#ifdef DEBUG
      printf(" == shift >> [%d] ", second_shift);
#endif // DEBUG
      result = AllocateString(s_len + second_shift);
      // ������ ����� - �������� ��, ��� �� ������ �� ������
      if (second_shift) CopySymbols(first_word, result, second_shift);
      CopySymbols(second_word, result + second_shift, s_len + 1); // � ������ ������ 0
      break; // ������ �� ������, ������ ����� ������� ����� ������� ����������
    }
  }
  return result;
}

char* FindChains(char const* str, char const* newSeparator)
{ // ����� ������, ������� ����� ������� - ��������� �����
  // ���� 2 ����� ��������� ����� ������ � ������ ������� (����� 1 �������)

  char* first_word = NULL;   // ��������� ����� (�������� ��������)
  char* second_word = NULL;  // ��������� ����� (�������� ��������)
  char* next_word = NULL;    // ����� ��������� ����� (�������� ��������)
  char* result = AllocateString(0);    // ��� ����������� ���������

  // ��� ����� ����� �� ������
  char* words = ExtractWords(str, newSeparator);

  // ������ ������� ������ � ������ :-)
  char* first_p = words;
  unsigned first_num = 0; // ����� ������� �����, ����� �� ��������� ����� ���� � �����
  while (first_word = STR_GetFirstWord(first_p))
  {
    first_num++; // ����� ������ �����
    unsigned int first_word_len = STR_Lenght(first_word);
    if (first_word_len > 1)
    {
      // ��� ���� �������� ��������� �� ����� ����������
      char* second_p = words;
      unsigned second_num = 0;
      while (second_word = STR_GetFirstWord(second_p))
      {
        second_num++;
        unsigned int second_word_len = STR_Lenght(second_word);
        if (second_word_len > 1)
        {
          if (first_num != second_num) // �� ��������� ����� ���� � �����
          { 
#ifdef DEBUG
            printf("\n[%s] + [%s]", first_word, second_word);
#endif // DEBUG

            if (NULL != (next_word = STR_MakeChain(first_word, second_word)))
            { // ������� ������� �������
#ifdef DEBUG
              printf(" == FOUND [%s] ", next_word);
#endif // DEBUG
              if (STR_FindWord(result, next_word, 0) == -1)
              { // ����� ��� �� ���� � ������
                int added = STR_Joint_Separ_Str(&result, newSeparator, next_word);
                if (!added)  // ���������� �� �������, ���������� �� ��� ����
                {
                  free(first_word);
                  free(second_word);
                  free(next_word);      // ������� �����, ��� ��� �� �����
                  break;
                }
              }
              free(next_word);
            }
          }
        }
        free(second_word);
        second_p = STR_FindNextWord(second_p) + second_word_len;
      }
    }
    free(first_word);      // ������� �����, ��� ��� �� �����
    // ������� ��������� - ������� ������ �����, �� ���� - ����� �����
    first_p = STR_FindNextWord(first_p) + first_word_len;
  }
  return result;
}

char* STR_JustifyLeft(char* str, unsigned width)
{ // ������� - ����� ������, ��� str ������� �� ������ ������� width
  // ��������� �������� ������ ���������� �� ���� ������, ������������ - �����
  // ����� �������� - \n, ���� ����� > width, ��� ����������� �� �����

  char* cropSP = OnlyOneSpace(str); // �������� ������ ������ �������

#ifdef DEBUG
  printf("\n Source string\n%s\n", cropSP);
  char* ruller = "0123456789";
  for (unsigned i = 0; i < width; i++)
    printf("%c", *(ruller + i % 10));     // �������� �������
  printf("\n");
#endif // DEBUG


  char* result = NULL;
  char* result_ptr = result;
  unsigned result_len = 0;
  char* ptr = cropSP;
  unsigned count_in_line = 0;
 
  while (*ptr) // �� ����� ������
  {
    char* nextWord = STR_FindNextWord(ptr);   // ��������� �����
    unsigned sepWidth = nextWord - ptr;       // �������� �� �����
    if (sepWidth) // ���� �����������
    {
      // ���� �������� ��� + �������� ��������� '\n'
      unsigned add_length = sepWidth + (count_in_line + sepWidth) / width;
      unsigned count_added = 0;
      char* new_result = (char*)realloc(result, result_len + add_length + 1);
      if (NULL == new_result) break;
      
      result = new_result;
      result_ptr = result + result_len;

      for (int i = sepWidth; i; i--) // �������� �����������
      {
        if (count_in_line == 0 && *ptr == ' ') // ���� ������ ����� � ������ ������ �� ��������� ���
          ptr++;
        else
        {
          *result_ptr++ = *ptr++;       // ��� ����������� �������
          count_added++;
          if (++count_in_line >= width) // ����������� ������� �������� � ������
          {
            // ���� � ����� ������� ��� ������ ������� ���
            if (*(result_ptr - 1) == ' ')
              *(result_ptr - 1) = '\n';
            else
            {
              *result_ptr++ = '\n';       // ������ ����� ������
              count_added++;
            }
            count_in_line = 0;
          }
        }
      }
      result_len += count_added;
    }

    if (*ptr) // ��� ��� �����, � �� ����� ������
    { // 3 ��������
      char* next_separ = STR_FindNextSeparator(ptr);
      unsigned word_len = next_separ - ptr;
      
      // ����� �� ���������� � ������ 
      if (count_in_line + word_len > width)
        if (word_len < width)     //����� ������ ������ ������, 
          // ������ ������� �������� � ������ �� ����� ������,
          count_in_line = width;
      // �����, ���� ����� ����������, ����� ������
      // ���� ����� ���� ������, ����� ��� ���������

      unsigned add_length = word_len + (count_in_line + word_len) / width;
      char* new_result = (char*)realloc(result, result_len + add_length + 1);
      if (NULL == new_result)  break;
      result = new_result;
      result_ptr = result + result_len;
      unsigned count_added = 0;
      
      for (int i = word_len; i; i--) // �������� 
      {
        if (count_in_line == width)  // ����� ������
        {
          // ���� � ����� ������� ��� ������ ������� ���
          if (*(result_ptr - 1) == ' ')
            *(result_ptr - 1) = '\n';
          else
          {
            *result_ptr++ = '\n';       // ������ ����� ������
            count_added++;
          }
          count_in_line = 0;
        }
        count_in_line++;
        *result_ptr++ = *ptr++;       // ��� ����������� �������
        count_added++;
      }
      result_len += count_added;
    }
  }

  free(cropSP);
  *result_ptr = '\0';
  return result;
}

char* STR_JustifyWidth(char* str, unsigned width)
{ // ������� - ����� ������, ��� str ������� �� ������ ������� width
  // ������������- �� ������, ������� ���������� ��������
  // ����� �������� - \n, ���� ����� > width, ��� ����������� �� �����
  
  char* cropSP = OnlyOneSpace(str);   // ������� �������, ���� �� ��������
  if (NULL == cropSP) return NULL;

  char* buffer = (char*)malloc(width + 2);   // ��� ���� ����������� ��������� �������
  if (NULL == buffer) return NULL;    // +1 ��� '\n'   �   +1 ��� '\0'

  // ������� ������� �� ������� � ������������� �����, 
  // ����� �������� �� ������ ������ �������
  char* str_j_left = STR_JustifyLeft(cropSP, width);
  free(cropSP);                       // ��� ��� �� �����
  if (NULL == str_j_left) return NULL;
  
  // ���������� �������, ������ � ������� +1 ���� ��������� ������� �� ������
  int num_lines = CountChar(str_j_left, '\n') + 1;
  // ������� ���� �����, ���� ��� ������� ����� ������ width + '\n'
  int result_len = num_lines * (width + 1) + 1;   // + ����� ������ '\0'

  char* result = (char*)malloc(result_len);
  if (NULL == result) { free(str_j_left); return NULL; }
  
  char* ptr = str_j_left;
  char* result_ptr = result;
 
  while (*ptr) //�� ����� ������
  {
    char* nextCR = FindChar(ptr, '\n', 0);  // ��������� '\n' ��� ����� ������ '\0'
    if (*nextCR == '\0')
    { // ��������� ������� �� �����������, ������ ��������
      while (*ptr) *(result_ptr++) = *(ptr++); // ��� �����������
      break;
    }
      
    unsigned int line_len = nextCR - ptr;
    CopySymbols(ptr, buffer, line_len);     // �������� � ����� ��������� ������(��� \n)
    *(buffer + line_len) = '\0';            // ������� ��������� ����� ������

#ifdef DEBUG
      printf("\nBUFFER [%s] ����� %d", buffer, line_len);
#endif // DEBUG

    if (line_len < width)                   // ������ ���� ���������
    {
      unsigned int countSpace = CountChar(buffer, ' '); // ������� ������� � ���� ������
      unsigned delta = width - line_len;                // ������� ����� �������� ��������
      if (countSpace) // � ������ ���� �������, ����� �� �����������
      {
        unsigned plusSP = delta / countSpace;      // ������� �������� � ������� ���������� �������
        unsigned plusSP_special = delta - plusSP * countSpace; // ��� �������, ��������� �� � �������
        int count_in_line = 0;
        for (unsigned i = 0; i < line_len; i++)
        {
          if (buffer[i] != ' ')
          { *(result_ptr++) = buffer[i];
#ifdef DEBUG
              printf("%c", buffer[i]);
#endif // DEBUG
            
          }
          else
          { 
            count_in_line++;                    // ������� ����������
            for (unsigned j = 0; j <= plusSP; j++)   // � ���� ���������� ������ ���� ������
            { *(result_ptr++) = ' ';
#ifdef DEBUG
                printf("#"); // �������� ������ �� ����� "��� � ���� �����������"
#endif // DEBUG                
               
            }
            // ��� ��� ������������� ������� ������������, �� � ������ ����������
            if (plusSP_special && count_in_line * plusSP_special % countSpace == 0)
            {
#ifdef DEBUG
                printf("*");   // ���� ������ "���������, �� ��� ���"
#endif // DEBUG                         
              *(result_ptr++) = ' '; // �������������� ������
            }
          }
        }
      }
      else  // � ������ 1 ����� � ��� ��������, ������� �� � �����
      {     // ��� �� ��������� �������� ?? �������
        unsigned int delta = width - line_len;
        while (delta--)
          *(buffer + line_len + delta) = ' ';
        // � ������ ������, �� ��� \n \0
        CopySymbols(buffer, result_ptr, width); // � ������ �
        result_ptr += width;                    // ������ ��������� � ������
#ifdef DEBUG
          printf("\nBUFFER [%s] just add %d SP", buffer, width-line_len);
#endif // DEBUG

      }
    }
    else
    { // � ������ ������ ������ �����, �� ��� \n \0
      CopySymbols(buffer, result_ptr, width); // � ������ �
      result_ptr += width;                    // ������ ��������� � ������

#ifdef DEBUG
        printf("\nBUFFER [%s] do nothing", buffer);
#endif // DEBUG
    }        
    *(result_ptr++) = '\n';                 // �������� ������� ������
    ptr += line_len;      // �������� ��������� � �������� ������
    if (*ptr == '\n')     // �������� ���, ���� ��� \n
      ptr++;
  }
 
  free(str_j_left);
  *result_ptr = '\0';  // �������� ����� ������
  return result;
}
