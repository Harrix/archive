HarrixQtLibraryForQWebView
==========================

1.13
----
 * Функция HQt_ReadHdataToHtmlChart удалена из библиотеки, так как ее функцию выполняет теперь класс HarrixClass_HarrixData.

1.12
----
 * В функции HQt_ReadHdataToHtmlChart включена возможность загрузки данных Harrix Data 1.1, но без выдачи данных новых видов графиков - это будет реализована в библиотеке для Latex.

1.11
----
 * Исправление опечаток.

1.10
----
 * Изменение функций HQt_BeginHtml и HQt_AddHtml ввиду изменений в файле index.html.

1.9
---
 * Переименование библиотеки в HarrixQtLibraryForQWebView.

1.8
---
 * Дополнения в функциях вывода QStringList.

1.7
---
 * Добавлены функции QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix), QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix), QString THQt_ShowMatrix (QStringList *VMHL_Matrix, int VMHL_N).

1.6
---
 * Добавлены функции QString THQt_ShowVector (QStringList VMHL_Vector, QString TitleVector, QString NameVector), QString THQt_ShowVector (QStringList VMHL_Vector, QString NameVector), QString THQt_ShowVector (QStringList VMHL_Vector).

1.5
---
 * Добавлены функции template <class T> QString THQt_ShowNumber (T VMHL_X, QString NameX), template <class T> QString THQt_ShowVector (T *VMHL_Vector, int VMHL_N), template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N, QString NameVector), template <class T> QString THQt_ShowVectorT (T *VMHL_Vector, int VMHL_N), template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix), 
template <class T> QString THQt_ShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M).

1.4
---
 * Исправлены ошибки с отображением векторов.

1.3
---
 * Оптимизирована работа некоторых функций.
 * Иногда прокрутка не докручивалась. Вставлен костыль.
 * Добавлена функция QString HQt_ShowH1 (QString String).
 * Добавлена функция QString HQt_ShowHr ().
 * Почти все стили вынесены в style.css.
1.2
---
 * Добавлена автоматическая прокрутка отображения в QWebView при добавлении новых данных.

1.1
---
 * Добавлены функции void HQt_BeginHtml(QString Path) и void HQt_AddHtml(QString Html).
 * Изменение работы ajax скрипта. Теперь обновление происходит только когда появилась новая информация.

1.0
---
 * Библиотека есть следствие выделения функций для отображения в QWebView данных из библиотеки HarrixQtLibrary.
 * Отображение данных перешло на ajax технологию с применением JQuery библиотеки.