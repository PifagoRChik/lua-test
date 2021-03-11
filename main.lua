-- Читаем числа a, b, c из потока ввода
-- *n – читаем числа
a, b, c = io.read("*n", "*n", "*n")

-- Загружаем функцию calc из libcalc
libcalc = require 'libcalc'

-- Отдаем в поток вывода результат работы calc
io.write(
    '(', a, ' + ', b, ') / ', c,
    ' = ', libcalc.calc(a, b, c),
    '\n'
)