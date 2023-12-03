# Black_and_Scholes_AOS_OMP_parallel_version

Проект для IT LAB бенчмарк формулы Блэка Шоулза, реализованный с помощью масисива из элементов класса option. На вход приходит размер кол-ва акций, как параметр командоной строки, далее с помощью формулы Блэка Шоулза (https://ru.wikipedia.org/wiki/Модель_Блэка_—_Шоулза) высчитвается размер справедливого опциона за все акции.
Результатом работы программы является цена опциона за все акции и время работы получения справедливой цены опциона в миллисекундах.

Для улучшения работы алгоритма используются:

1.Векторизация.

2.Распараллеливание циклов.

3.Использование одного типа данных ( избегаем смешивания типов).

Для вычисления времени работы алгоритма используется библиотека chrono. Элементы массивов в классе опцион заполняются с помощью генератора случайных чисел и дистрибьютеров из библиотеки random. Переменные обозначены как в формуле Блэка Шоулза, за исключением волотильности и процентной ставки. Значение переменных из формулы подписаны комментариями.