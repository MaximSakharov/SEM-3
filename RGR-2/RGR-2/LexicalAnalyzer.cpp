#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

// Перечисление содержит константы для обозначения классов символьных лексем: БУКВА, ЦИФРА, АРИФМЕТИЧЕСКАЯ ОПЕРАЦИЯ, ОТНОШЕНИЕ, ПРОБЕЛ, КОНЕЦ СТРОКИ (LF), КОММЕНТАРИЙ (;), ОШИБКА, КОНЕЦ.
enum SymbolicTokenClass { Letter, Digit, ArithOp, Ratio, Space, LF, Comment, Error, EndOfFile };

/*
A1. Ожидается команда в начале строки. Это первая команда программы.
A2. Ожидается очередная (не первая) команда в начале строки.
B1. Считывается продолжение ключевого слова.
C1. Ожидается конец строки после правильной команды.
D1. Был прочитан первый символ отношения. Нужно завершить
обработку отношения.
E1. Только что прочитано слово push, нужно дождаться пробела.
E2. Только что прочитано слово jmp или ji, нужно дождаться пробела.
E3. Только что прочитано слово pop, нужно дождаться пробела.
F1. Ожидается первый символ переменной или константы (после
push).
F2. Ожидается начало константы (после jmp или ji).
F3. Ожидается начало переменной (после pop).
G1. Считывается константа.
H1. Считывается переменная
I1. Считывается комментарий, перед которым не было команд.
I2. Считывается комментарий, перед которым были команды.
J1. Считывается остаток строки после ошибки до перехода на новую
строку.
*/
enum States { s_A1, s_A2, s_B1, s_C1, s_D1, s_E1, s_E2, s_E3, s_F1, s_F2, s_F3, s_G1, s_H1, s_I1, s_I2, s_J1, s_M1, s_Stop };

/*
PUSH - указатель на таблицу имён
POP - указатель на таблицу умён
ARITHMETIC_OPERATION - код операции
RATIO - код отношения
JMP - номер строки
JI - номер строки
READ
WRITE
END
COMMENT
ERROR
END_OF_FILE
*/
enum ListTokenClass { PUSH, POP, ARITHMETIC_OPERATION, RATIO, JMP, JI, READ, WRITE, END, COMMENT, ERROR, END_OF_FILE};

//enum Ratio {None, Equal, Not_Equale,  };

// Структура для представления символьной лексемы.
struct SymbolicToken
{
   SymbolicTokenClass token_class; // Класс лексемы.
   int value;                      // Значение лексемы.
};

/*
struct ListToken
{
   ListTokenClass token_class; // Класс лексемы.
   int value;                      // Значение лексемы.
};
*/

struct Variable;

// Глобальные переменные, используемые процедурами автомата.
SymbolicToken s;    // Символьная лексема.
ListTokenClass class_regist;
void* pointer_regist;
int number_regist;         // Регистр числа.
int ratio_regist;          // Регистр отношения (??)
int value_regist;          // Регистр значения  (??)
string variable_register;     // Регистр переменной (??)
int detection_register;    // Регистр обнаружения для таблицы обнаружения
int line_number;           // Номер строки
int constant_flag;         // Флаг константы

int A1(), A1_a(), A1_b(), A2_a(), A2_b(), A2_c(), A2_d(), A2_e(), A2_f(), B1_a(), B1_b(), C1(), C1_a(), C1_b(), C1_c(), C1_d(), C1_e(), C1_f(), C1_g(), C1_h(), D1_a(), E1_a(), E2_a(), E2_b(), E3_a(), F1(), F2(), F3(), G1_a(), G1_b(), H1_a(), H1_b(), I1(), I2(), I1_a(), I2_a(), I2_b(), I2_c(), I2_d(), J1(), M1(), Exit1(), Exit2(), Exit3(), Exit4();

vector<int> constant_table;

struct Variable
{
   string name;
   int type;
   int integer_value;

   //void* ptr;
};

vector<Variable> variable_table;

struct InitialVector
{
   char ch;
   int LineNumber;
};

vector <InitialVector> initial_vector =
{
    {'a', 0},
    {'b', 0},
    {'c', 0},
    {'d', 0},
    {'e', 1},
    {'f', 0},
    {'g', 0},
    {'h', 0},
    {'i', 0},
    {'j', 3},
    {'k', 0},
    {'l', 0},
    {'m', 0},
    {'n', 0},
    {'o', 0},
    {'p', 6},
    {'q', 0},
    {'r', 11},
    {'s', 0},
    {'t', 0},
    {'u', 0},
    {'v', 0},
    {'w', 14},
    {'x', 0},
    {'y', 0},
    {'z', 0}
};

struct DetectionTable
{
   //int LineNumber;
   char ch;
   int alternative;
   int transition;

   //DetectionTable(): ch('a'), alternative(0), transition(A1()) {};
};

vector <DetectionTable> detection_table = {
    {'n', 0, B1_a()},
    {'d', 0, C1_b()},
    {'i', 4, E2_a()},
    {'m', 0, B1_b()},
    {'p', 0, E2_b()},
    {'o', 8, B1_b()},
    {'p', 0, E3_a()},
    {'u', 0, B1_b()},
    {'s', 0, B1_b()},
    {'h', 0, E1_a()},
    {'e', 0, B1_a()},
    {'a', 0, B1_a()},
    {'d', 0, C1_c()},
    {'r', 0, B1_b()},
    {'i', 0, B1_b()},
    {'t', 0, B1_b()},
    {'e', 0, C1_d()}
};

struct LexemeList
{
   ListTokenClass class_token;
   int value;
   int number_lexeme_line;
};

vector<LexemeList> lexeme_list;

void ErrorHandlingProcess()
{
   return ;
}

void AddConstantProcess()
{
   /*
* Если ФЛАГ_КОНСТАНТЫ = 0, то выйти из процедуры.
Добавить в таблицу констант РЕГИСТР_ЧИСЛА, если такой
константы там ещё нет.
   */

   if (constant_flag == 0)
      return;

   if (constant_table.size() == 0)
   {
      constant_table.push_back(number_regist);
      return;
   }

   //bool flag = false;

   int i = 0;

   for (; i < constant_table.size(); ++i)
   {
      if (constant_table[i] == number_regist)
      {
         return;
      }
   }

   constant_table.push_back(number_regist);

   // РЕГИСТР_УКАЗАТЕЛЯ = указатель на соответствующий элемент таблицы констант
   pointer_regist = &constant_table[constant_table.size()-1];
}

void AddVariableProcess()
{
   if (variable_table.size() == 0)
   {
      variable_table.push_back(Variable{ variable_register, 0, 0 });
      return;
   }

   //bool flag = false;

   int i = 0;

   for (; i < constant_table.size(); ++i)
   {
      if (variable_table[i].name == variable_register)
      {
         ErrorHandlingProcess();
      }
   }

   variable_table.push_back(Variable{ variable_register, 0, 0 });

   // РЕГИСТР_УКАЗАТЕЛЯ = указатель на соответствующий элемент таблицы переменных
   pointer_regist = &variable_table[variable_table.size()-1];
}

void AddLexemeProcess()
{
   lexeme_list.push_back({class_regist, value_regist, line_number});

   return;
}

/* Функция транслитерации.
 * ch - символ
 * Возвращаемое значение - результат транслитерации символа ch
 */
SymbolicToken transliterator(int ch)
{
   SymbolicToken s;
   s.value = 0;
   if (isalpha(ch))
   {
      s.token_class = Letter;
      s.value = ch;
   }
   else if (isdigit(ch))
   {
      s.token_class = Digit;
      s.value = ch - '0';
   }
   else if (ch == '+' || ch == '-' || ch == '*' || ch == '%')
   {
      s.token_class = ArithOp;
      s.value = ch; // ?! нужно?
   }
   else if (ch == '=' || ch == '!' || ch == '<' || ch == '>')
   {
      s.token_class = Ratio;
      s.value = ch;// ?! нужно?
   }
   else if (ch == ' ')
   {
      s.token_class = Space;
   }
   else if (ch == '\t')
   {
      s.token_class = LF;
   }
   else if (ch == ';')
   {
      s.token_class = Comment;
   }
   else if (ch == EOF)
   {
      s.token_class = EndOfFile;
   }
   else
   {
      s.token_class = Error;
   }
   return s;
}

// Процедуры автомата (от A1 до Exit1).
int A1()
{
   return s_A1;
}
int A1_a()
{
   //СОздать лексему ??
   AddLexemeProcess();
   ++line_number;
   return s_A1;
}
int A1_b()
{
   ++line_number;
   return s_A1;
}
int A2_a()
{
   ++line_number;
   return s_A1;
}
int A2_b()
{
   //Создать лексему ??
   AddLexemeProcess();
   ++line_number;
   return s_A1;
}
int A2_c()
{
   // Добавить константу
   AddConstantProcess();
   //Создать лексему ??
   AddLexemeProcess();
   ++line_number;
   return s_A1;
}
int A2_d()
{
   // Добавить переменную
   AddVariableProcess();
   //Создать лексему ??
   AddLexemeProcess();
   ++line_number;
   return s_A1;
}
int A2_e()
{

   if (ratio_regist == '!')
      ErrorHandlingProcess();

   //Создать лексему ??
   AddLexemeProcess();
   ++line_number;
   return s_A1;
}
int A2_f()
{
   ++line_number;
   AddLexemeProcess();
   return s_A1;
}
int B1_a()
{

   detection_register = s.value - 'a' + 1;
   if (detection_register == 0)
      ErrorHandlingProcess();
   return s_B1;
}
int B1_b()
{
   ++detection_register;
   return s_B1;
}
int C1()
{
   return s_C1;
}
int C1_a()
{
   class_regist = ARITHMETIC_OPERATION;
   if (s.value == '+')
      value_regist = '+';
   else if (s.value == '-')
      value_regist = '-';
   else if (s.value == '/')
      value_regist = '/';
   else if (s.value == '%')
      value_regist = '%';
   // Создать лексему
   AddLexemeProcess();
   return s_C1;
}
int C1_b()
{
   class_regist = END;
   // Создать лексему
   AddLexemeProcess();
   return s_C1;
}
int C1_c()
{
   class_regist = READ;
   // Создать лексему
   AddLexemeProcess();
   return s_C1;
}
int C1_d()
{
   class_regist = WRITE;
   // Создать лексему
   AddLexemeProcess();
   return s_C1;
}
int C1_e()
{
   // Добавить константу
   AddConstantProcess();
   // Создать лексему
   AddLexemeProcess();
   return s_C1;
}
int C1_f()
{
   // Добавить переменную
   AddVariableProcess();
   // Создать лексему
   AddLexemeProcess();
   return s_C1;
}
int C1_g()
{
   if (ratio_regist == '!')
      ErrorHandlingProcess();

   // Создать лексему
   AddLexemeProcess();
   return s_C1;
}
int C1_h()
{
   // Используя РЕГИСТР_ОТНОШЕНИЯ и значение текущего символа, вычислить значение отношения и поместить его в РЕГИСТР_ОТНОШЕНИЯ
   
   if (ratio_regist == '!' && s.value == '=')
      ratio_regist = 2;
   else if (ratio_regist == '<' && s.value == '=')
      ratio_regist = 5;
   else if (ratio_regist == '>' && s.value == '=')
      ratio_regist = 6;
   else
      ratio_regist = 0;

   if (ratio_regist == 0)
      ErrorHandlingProcess();
   
   // Создать лексему
   return s_C1;
}
int D1_a()
{
   class_regist = RATIO;

   if (s.value == '=')
      ratio_regist = '=';
   else if (s.value == '!')
      ratio_regist = '!';
   else if (s.value == '<')
      ratio_regist = '<';
   else if (s.value == '>')
      ratio_regist = '>';

   return s_D1;
}
int E1_a()
{
   class_regist = PUSH;
   constant_flag = 1;
   return s_E1;
}
int E2_a()
{
   class_regist = JI;
   constant_flag = 0;
   return s_E2;
}
int E2_b()
{
   class_regist = JMP;
   constant_flag = 0;
   return s_E2;
}
int E3_a()
{
   class_regist = POP;
   return s_E3;
}
int F1()
{
   return s_F1;
}
int F2()
{
   return s_F2;
}
int F3()
{
   return s_F3;
}
int G1_a()
{
   number_regist = s.value;
   return s_G1;
}
int G1_b()
{
   number_regist = 10 * number_regist + s.value;
   return s_G1;
}
int H1_a()
{
   //variable_register = '\0';
   variable_register = (char)s.value;
   return s_H1;
}
int H1_b()
{
   // Добавить текущий входной символ в конец строки РЕГИСТР_ПЕРЕМЕННОЙ
   variable_register += (char)s.value;
   return s_H1;
}
int I1()
{
   return s_I1;
}
int I2()
{
   return s_I2;
}
int I1_a()
{
   class_regist = COMMENT;
   return s_I1;
}
int I2_a()
{
   class_regist = COMMENT;
   return s_I2;
}
int I2_b()
{
   // Добавить константу
   // Создать лексему
   class_regist = COMMENT;
   return s_I2;
}
int I2_c()
{
   // Добавить константу
   AddConstantProcess();
   // Создать лексему
   AddLexemeProcess();
   class_regist = COMMENT;
   return s_I2;
}
int I2_d()
{
   // Если РЕГИСТР_ОТНОШЕНИЯ = "!", то перейти на прцедуру, обрабатывающую ошибку
   if (ratio_regist == '!')
      ErrorHandlingProcess();

   // Создать лексему
   AddLexemeProcess();
   class_regist = COMMENT;
   return s_I2;
}
int J1()
{
   return s_J1;
}
int M1()
{
   // Сравнение значения символа с текущим входным символом
   if (detection_table[detection_register - 1].ch == s.value)
   {
      // Переходим к процедуре, на которую указывает регистр обнаружения
      detection_table[detection_register - 1].transition;
      //return s_B1; // ?????
   }
   else
   {
      // Устанавливаем альтернативное значение из таблицы обнаружения
      detection_register = detection_table[detection_register - 1].alternative;
      // Если ошибка, то обработка ошибки
      if (detection_register == 0)
      {
         ErrorHandlingProcess();
      }
   }
   return M1();
}

   /*
int M1()
{
   * Сравнить значение символа, на который указывает РЕГИСТР_-
ОБНАРУЖЕНИЯ, со значением текущего входного символа.
Если значения равны, то перейти к процедуре, на которую
указывает РЕГИСТР_ОБНАРУЖЕНИЯ.
В противном случае поместить в РЕГИСТР_ОБНАРУЖЕНИЯ
альтернативное значение из таблицы обнаружения.
Если РЕГИСТР_ОБНАРУЖЕНИЯ = 0, то перейти на процедуру,
обрабатывающую ошибку.
В противном случае перейти на M1.

   return s_M1;
}
   */

int Exit1()
{
   class_regist = END_OF_FILE;
   // Создать лексему
   AddLexemeProcess();
   return s_Stop;
}
int Exit2()
{
   if (ratio_regist == '!')
      class_regist = ERROR;
   // Создать лексему
   AddLexemeProcess();
   class_regist = END_OF_FILE;
   AddLexemeProcess();
   // Создать лексему
   return s_Stop;
}
int Exit3()
{
   // Добавить константу
   AddConstantProcess();
   // Создать лексему
   AddLexemeProcess();
   class_regist = END_OF_FILE;
   // Создать лексему
   AddLexemeProcess();
   return s_Stop;
}
int Exit4()
{
   // Добавить переменную
   AddVariableProcess();
   // Создать лексему
   AddLexemeProcess();
   class_regist = END_OF_FILE;
   // Создать лексему
   AddLexemeProcess();
   return s_Stop;
}
int Error1()
{
   cout << "Обнаружена ошибка" << endl;
   return s_Stop;
}

// Размеры таблицы автомата.
const int state_number = 16; // Число состояний (без s_Stop).
const int class_number = 9; // Число символов входного алфавита.

// Таблица указателей на процедуры автомата.
typedef int (*function_pointer)();
function_pointer table[state_number][class_number];

// Функция инициализации таблицы указателей на процедуры автомата.
void initialize_table()
{
   // Сначала во все ячейки заносится указатель на процедуру обработки ошибок.
   for (int i = 0; i < state_number; i++)
   {
      for (int j = 0; j < class_number; j++)
      {
         table[i][j] = Error1;
      }
   }
   // Далее заполняются ячейки для остальных процедур.
   table[s_A1][Letter] = B1_a; table[s_A1][ArithOp] = C1_a; table[s_A1][Ratio] = D1_a; table[s_A1][Space] = A1; table[s_A1][LF] = A1_b; table[s_A1][Comment] = I1_a; table[s_A1][EndOfFile] = Exit1;
   table[s_A2][Letter] = B1_a; table[s_A2][ArithOp] = C1_a; table[s_A2][Ratio] = D1_a; table[s_A2][Space] = A1; table[s_A2][LF] = A1_b; table[s_A2][Comment] = I1_a; table[s_A2][EndOfFile] = Exit1;
   
   table[s_B1][Letter] = M1; table[s_B1][LF] = A2_f; 
   
   table[s_C1][Space] = C1; table[s_C1][LF] = A2_a; table[s_C1][Comment] = I2_a; table[s_C1][EndOfFile] = Exit1;

   table[s_D1][Ratio] = C1_h; table[s_D1][Space] = C1_g; table[s_D1][LF] = A2_e; table[s_D1][Comment] = I2_d; table[s_D1][EndOfFile] = Exit2;
   
   table[s_E1][Space] = F1; table[s_E1][LF] = A2_f;
   table[s_E2][Space] = F2; table[s_E2][LF] = A2_f;
   table[s_E3][Space] = F2; table[s_E3][LF] = A2_f;
   
   table[s_F1][Letter] = H1_a; table[s_F1][Digit] = G1_a; table[s_F1][Space] = F1; table[s_F1][LF] = A2_f;
   table[s_F2][Digit] = G1_a; table[s_F2][Space] = F2; table[s_F2][LF] = A2_f;
   table[s_F3][Letter] = H1_a; table[s_F3][Space] = F3; table[s_F3][LF] = A2_f;
   
   table[s_G1][Digit] = G1_b; table[s_G1][Space] = C1_e; table[s_G1][LF] = A2_c; table[s_G1][Comment] = I2_b; table[s_G1][EndOfFile] = Exit3;
   
   table[s_H1][Letter] = H1_b; table[s_H1][Digit] = H1_b; table[s_H1][Space] = C1_f; table[s_H1][LF] = A2_d; table[s_H1][Comment] = I2_c; table[s_H1][EndOfFile] = Exit4;
   
   table[s_I1][Letter] = I1; table[s_I1][Digit] = I1; table[s_I1][ArithOp] = I1; table[s_I1][Ratio] = I1; table[s_I1][Space] = I1; table[s_I1][LF] = A1_a; table[s_I1][Comment] = I1; table[s_I1][Error] = I1;
   table[s_I2][Letter] = I2; table[s_I2][Digit] = I2; table[s_I2][ArithOp] = I2; table[s_I2][Ratio] = I2; table[s_I2][Space] = I2; table[s_I2][LF] = A2_b; table[s_I2][Comment] = I2; table[s_I2][Error] = I2; table[s_I2][EndOfFile] = Exit1;
   
   table[s_J1][Letter] = J1; table[s_J1][Digit] = J1; table[s_J1][ArithOp] = J1; table[s_J1][Ratio] = J1; table[s_J1][Space] = J1; table[s_J1][LF] = A2_a; table[s_J1][Comment] = J1; table[s_J1][Error] = J1; table[s_J1][EndOfFile] = Exit1;
}

// Основная функция анализа. Функция запускает конечный автомат на тексте из файла filename.
void parse(const char* filename)
{
   ifstream in(filename);
   if (!in)
   {
      cout << "Не удалось открыть файл " << filename << endl;
      return;
   }

   int ch;             // Входной символ.
   int state = s_A1;   // Текущее состояние автомата.
   while (state != s_Stop)
   {
      // s_Stop - техническое состояние. Когда автомат попадает в s_Stop, цикл останавливается.
      ch = in.get();
      s = transliterator(ch);
      state = (*table[state][s.token_class])();
   }

   in.close();
}


// Вызов программы имеет вид ./имя-исполняемого-файла имя-входного-файла.
int main(int argc, char *argv[])
{
   setlocale(LC_ALL,"RUSSION");
    if (argc != 2)
    {
        cout << "Формат: ./имя-исполняемого-файла имя-входного-файла" << endl;
        return 1;
    }

    // Поскольку автомат не меняется, то таблица инициализируется один раз.
    initialize_table();
    parse(argv[1]);

    return 0;
}
