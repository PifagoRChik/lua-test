// Библиотеки для работы с lua функциями
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"


// Вычисляет формулу d = (a + b) / c используя lua stack
int calc(lua_State *L) {
   // Step 1: достаём аргументы a, b, c из стека
   // Нумерация начинается с единицы
    double a = luaL_checknumber(L, 1);
    double b = luaL_checknumber(L, 2);
    double c = luaL_checknumber(L, 3);

   //  Step 2: вычисляем d, d = (a + b) / c
    double d = (a + b) / c;

   // Step 3:  пушим результат вычисления в стек
    lua_pushnumber(L, d);

   // Возвращаем значение d из функции
   // Для этого возвращаем верхнее значение из стека по индексу
   // Индекс последнего добавленного значения –– 1
    return 1;
};

// Регистрируем функцию calc как lua модуль
const struct luaL_Reg libcalc [] = {
    {"calc", calc},
    {NULL, NULL}
};

// libcalc как lua модуль
int luaopen_libcalc(lua_State *L) {
    luaL_newlib(L, libcalc);
    return 1;
};